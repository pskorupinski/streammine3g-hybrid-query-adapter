/*
 * Accessop.cpp
 *
 *  Created on: Oct 25, 2012
 *      Author: ubuntu
 */

#include "Accessop.h"

/**
 * @param param - pointer to an object of SearchRequest class
 */
void Accessop::init(int sliceId, int sliceUId, int bucketCount, char* param, int size)
{
    logger  = log4cxx::Logger::getLogger("sm.accessop");

    LOG4CXX_INFO(logger, "Accessop initiated.");

	/* Initialize searchRequest class field */
	m_searchRequest = new SearchRequest();

    LOG4CXX_INFO(logger, "Accessop init param: " << param);

	std::string str(param, param+size);

	google::protobuf::TextFormat::ParseFromString(str,m_searchRequest);

	/* Initialize dataSourceAdapter depending on dataSourceImplType field value */
	switch (m_searchRequest->datasourceimpltype()) {
	case SearchRequest_DataSourceImplType_REAL_TIME:
		if(m_searchRequest->has_timelimitmin())
			m_dataSourceAdapter = new RealTimeDataSourceAdapter(m_searchRequest->timelimitmin());
		else
			m_dataSourceAdapter = new RealTimeDataSourceAdapter();
	    LOG4CXX_INFO(logger, "REAL TIME SOURCE ADAPTER LAUNCHED");
		break;
	case SearchRequest_DataSourceImplType_MONGO_GRIDFS:
		//m_dataSourceAdapter = new MongoDbDataSourceAdapter();
	    LOG4CXX_INFO(logger, "MONGO DB GRIDFS SOURCE ADAPTER LAUNCHED");
		break;
	default:
		m_dataSourceAdapter = NULL;
		break;
	}

	/* Connect to DataSource */
	std::string host = m_searchRequest->host();
	int port = m_searchRequest->port();
	std::string sourceName = "";
	if (m_searchRequest->has_sourcename())
		sourceName = m_searchRequest->sourcename();

	bool bConnected = m_dataSourceAdapter->connect(host, port, sourceName);

	if (bConnected) {
		/* Define what should be read */
		SearchRequest_ReadPreferenceType readPreferenceType =
				m_searchRequest->readpreferencetype();
		std::list<GeneralKey> * key = new std::list<GeneralKey>();
		int keysNum = m_searchRequest->generalkeys_size();
		for (int i = 0; i < keysNum; i++) {
			key->push_back(m_searchRequest->generalkeys(i));
		}
		m_lAdapterPortionSize = PROCESS_PORTION_SIZE;

		bool bReadDefined = m_dataSourceAdapter->readDefine(readPreferenceType,
				key, m_lAdapterPortionSize);
	}
}

void Accessop::onConnectAdapter(int portId, int sourceId, Collector* collector) {
}

void Accessop::onReadAdapter(void* buf, int size, int sourceId,
		Collector* collector) {
}

bool Accessop::generate(Collector* collector) {
	bool bRet = true;

    LOG4CXX_INFO(logger, "Accessop GENERATE");

    LOG4CXX_INFO(logger, "m_lAdapterPortionSize = " << m_lAdapterPortionSize);

	char * chBuff = new char[m_lAdapterPortionSize];

	int lPortionSize = m_lAdapterPortionSize;

	bool bReadSuccess = m_dataSourceAdapter->readNext(chBuff, lPortionSize);

	if (bReadSuccess) {
		/* emit an event with data! */
		collector->emitEvent(0, timestampCounterGenerator++, chBuff,
				lPortionSize);
	} else {
		/* no more to read - stop calling generate method */
		if (lPortionSize == -1) {
			bRet = false;

			LOG4CXX_INFO(logger, "   --- ACCESSOP GENERATE: no more to read, emitting [EOS] event");
		    /* emit event [EOS] */
			EndOfStreamHandler::sendEndOfStream(collector, timestampCounterGenerator++, 0);
		}
		/* if buffer was actually to small - next generate will read the same data */
		else
			m_lAdapterPortionSize = max(lPortionSize,m_lAdapterPortionSize);

		//delete [] chBuff;
	}

	return bRet;
}

void Accessop::process(int routingKey, void* eventIn, int size, void* state, Collector* collector) {
	char * chBuff = (char*) eventIn;
	char * chArrayOut;
	int lArrayOutSize;

    LOG4CXX_INFO(logger, "Accessop PROCESS");

	if(EndOfStreamHandler::checkEndOfStream(chBuff, size)) {
	    LOG4CXX_INFO(logger, "   --- ACCESSOP PROCESS: EndOfStream");
		EndOfStreamHandler::handleEndOfStream(collector);
		EndOfStreamHandler::sendEndOfStream(collector, timestampCounterProcessor++);
	}
	else {

		int headerSize = (int)chBuff[0];

		/* 1. Read protobuf header */
		ByteArrayHeader byteArrayHeader;
		byteArrayHeader.ParseFromArray((void*)(chBuff+1), headerSize);

		LOG4CXX_INFO(logger, "   --- ACCESSOP PROCESS: " << "Processing data about "
				<< byteArrayHeader.filename() << ", offset: " << byteArrayHeader.offset());

		const int lEventInDataOffset = 0 + byteArrayHeader.ByteSize();

	    LOG4CXX_INFO(logger, "   --- ACCESSOP PROCESS: " << byteArrayHeader.size() << " + " << byteArrayHeader.ByteSize() <<
				" + 1 = " << size);

		if (byteArrayHeader.size() + byteArrayHeader.ByteSize() + 1 != size) {
		    LOG4CXX_INFO(logger, "Incorrect data given in ByteArrayHeader object. "
					"Skipping further processing");
		} else {
			/* 2. If data size is greater than g_lDataChunkProcessingSize, split array and generate protobuf header for every part */
			if (byteArrayHeader.size() > g_lDataChunkProcessingSize) {
				int lEventsToGenerate = ceil(
						(double) byteArrayHeader.size()
								/ (double) g_lDataChunkProcessingSize);
				/* Which byte will be the first byte of a current event byte array */
				int lLocalOffset = 0;
				/* Pointer to the event byte array (header + byte array) */
				void * eventPtr;
				/* Memory size in bytes that is needed for an event */
				int eventSize;

			    LOG4CXX_INFO(logger, "   --- ACCESSOP PROCESS: " << "Data size is too big - cutting to " << lEventsToGenerate << " parts.");

				for (int i = 0; i < lEventsToGenerate; i++) {
					ByteArrayHeader newByteArrayHeader;
					newByteArrayHeader.set_datasource( byteArrayHeader.datasource() );
					newByteArrayHeader.set_filename( byteArrayHeader.filename() );

					newByteArrayHeader.set_offset( byteArrayHeader.offset() + lLocalOffset );

					if ( byteArrayHeader.size() - lLocalOffset >= g_lDataChunkProcessingSize )
						newByteArrayHeader.set_size( g_lDataChunkProcessingSize );
					else
						newByteArrayHeader.set_size( byteArrayHeader.size() - lLocalOffset );


					//lInitByteNumber = 0 + newByteArrayHeader.ByteSize();
					int lHeaderSize = newByteArrayHeader.ByteSize();
					char * newHeaderByteArray = new char[lHeaderSize];
					newByteArrayHeader.SerializeToArray(newHeaderByteArray,lHeaderSize);

					eventSize = lHeaderSize + newByteArrayHeader.size();
					void* eventPtr = collector->allocEvent(
							m_searchRequest->has_partitionkey() ? m_searchRequest->partitionkey() : -1,
							timestampCounterProcessor++, eventSize);

				    LOG4CXX_INFO(logger, "   --- ACCESSOP PROCESS: " << "File fragment: offset - " << newByteArrayHeader.offset() <<
							", size - " << newByteArrayHeader.size());

					memcpy((char*)eventPtr + 0,
							newHeaderByteArray,
							lHeaderSize);
					memcpy((char*)eventPtr + lHeaderSize,
							(char*)eventIn + lEventInDataOffset + lLocalOffset,
							newByteArrayHeader.size());

				    LOG4CXX_INFO(logger, "   --- ACCESSOP PROCESS: " << "lLocalOffset = " << lLocalOffset << " -> " << lLocalOffset+newByteArrayHeader.size());
					lLocalOffset += newByteArrayHeader.size();

					collector->commit();

					LOG4CXX_INFO(logger, "   --- ACCESSOP PROCESS: " << "EVENT COMMITTED!");

					delete [] newHeaderByteArray;
				}
			} else {
				collector->emitEvent(-1, timestampCounterProcessor++, eventIn,
						size);
			}
		}
	}
}

void Accessop::onReleaseBuffer(void* buf, BufferReleaseType bufferReleaseType) {
	if (bufferReleaseType == streammine3G::EventBuffer)
		delete (int*) buf;
}

extern "C" {
Operator *operatorInstance() {
	return new Accessop();
}
}

/*
 * Mapper.cpp
 *
 *  Created on: Apr 10, 2013
 *      Author: ubuntu
 */

#include "Mapper.h"

void Mapper::init(int sliceId, int sliceUId, int bucketCount, char* param, int size)
{
    logger  = log4cxx::Logger::getLogger("sm.mapper");

    LOG4CXX_INFO(logger, "Mapper initiated.");

    timestampCounterProcessor = 0;
}

void Mapper::onConnectAdapter(int portId, int sourceId, Collector* collector) {

}

void Mapper::onReadAdapter(void* buf, int size, int sourceId, Collector* collector) {

}

void Mapper::onReleaseBuffer(void* buf, BufferReleaseType bufferReleaseType) {

}

void Mapper::process(int routingKey, void* eventIn, int size, void* state, Collector* collector) {

	if(EndOfStreamHandler::checkEndOfStream((char*)eventIn, size)) {
	    LOG4CXX_INFO(logger, "   --- MAPPER: EndOfStream");
		EndOfStreamHandler::handleEndOfStream(collector);
		EndOfStreamHandler::sendEndOfStream(collector, timestampCounterProcessor++);
	}
	else {
		/* 1. Read protobuf header */
		ByteArrayHeader byteArrayHeader;
		byteArrayHeader.ParseFromArray(eventIn, size);

	    LOG4CXX_INFO(logger, "   --- MAPPER: " << "Processing data about "
				<< byteArrayHeader.filename() << "offset: " << byteArrayHeader.offset());

		const int lEventInDataOffset = 0 + byteArrayHeader.ByteSize();
		char * dataInArray = (char*)eventIn + lEventInDataOffset;

		char* word = new char[g_lDataChunkProcessingSize];
		strcpy(word, dataInArray);
		word = strtok(word, " .,\r\n\t:;-()");
		while (word != NULL) {
		    LOG4CXX_INFO(logger, "   --- MAPPER: Word " << word[0] << "..");
			char* eventOut = (char*)collector->allocEvent(0, timestampCounterProcessor++, strlen(word)+1);
			memcpy(eventOut, word, strlen(word));
			eventOut[strlen(word)] = '\0';
		    LOG4CXX_INFO(logger, "   --- MAPPER: " << "EVENT ALLOCATED!");
			collector->commit();
		    LOG4CXX_INFO(logger, "   --- MAPPER: " << "EVENT COMMITTED!" );
			word = strtok(NULL, " .,\r\n\t:;-()");
		}
	}
}

Mapper::~Mapper()
{
}

extern "C"
{
    Operator *operatorInstance()
    {
        return new Mapper();
    }
}

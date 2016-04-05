#include "MongoDbDataSourceAdapter.h"

MongoDbDataSourceAdapter::MongoDbDataSourceAdapter() : m_currentFile()
{
    logger  = log4cxx::Logger::getLogger("sm.accessop");
}


MongoDbDataSourceAdapter::~MongoDbDataSourceAdapter()
{
}

bool MongoDbDataSourceAdapter::connect(::std::string host, int port, ::std::string sourceName)
{
	bool bRet = false;

	if(host.empty())
	{
		host = "localhost";
	}

	mongo::HostAndPort hostAndPort(host, port);
	::std::string errmsg("Wrong connection data to mongo instance");

	try
	{
		m_mongoConn.connect(hostAndPort, errmsg);
	    LOG4CXX_INFO(logger, "Connected to mongoDB");

	    // TODO analyze sourceName var. if it contains a dot, divide into dbName.prefix

	    m_strSourceName = sourceName;
	    m_gridFs = new mongo::MyGridFS(m_mongoConn, m_strSourceName);

	    bRet = true;
	} catch( const mongo::DBException &e ) {
	    LOG4CXX_INFO(logger, "caught " << e.what() );
	}

	return bRet;
}

bool MongoDbDataSourceAdapter::readDefine(SearchRequest_ReadPreferenceType readPreferenceType, void * key, int& portionLength)
{
	bool bRet = false;
	bool bEnumOk = false;

    LOG4CXX_INFO(logger, "method: readDefine");

	m_readPreferenceType = readPreferenceType;

	if(m_readPreferenceType == SearchRequest_ReadPreferenceType_READ_ALL)
	{
		// TODO read-all option for mongodb
		//
		bEnumOk = true;
	}
	else if(m_readPreferenceType == SearchRequest_ReadPreferenceType_LIST_OF_KEYS)
	{
		bEnumOk = true;

		m_ptrMongoKeyList = (std::list<GeneralKey> *) key;
		m_mongoKeyListIter = m_ptrMongoKeyList->begin();

	}

	if(bEnumOk)
	{
		m_lLastChunkRead = -1;
		// TODO get a chunk size and store in portion var

		bRet = true;
	}

	return bRet;
}

bool MongoDbDataSourceAdapter::readNext(const char * dataPortion, int& portionLength)
{
	bool bRet = false;
	bool bTudoBem = false;

    LOG4CXX_INFO(logger, "method: readNext");

	int lChunkToBeRead;

	if(m_lLastChunkRead == -1)
	/* will read a new file */
	{
		if(m_readPreferenceType == SearchRequest_ReadPreferenceType_LIST_OF_KEYS)
		{
			if(m_mongoKeyListIter != m_ptrMongoKeyList->end())
			{
				// get data about what file to read and how
				const std::string strFileKey = m_mongoKeyListIter->name();
				if(m_mongoKeyListIter->has_first())
					lChunkToBeRead = m_mongoKeyListIter->first();
				else
					lChunkToBeRead = 0;

				// TODO some correctness check
				/* set new file */
			    LOG4CXX_INFO(logger, "Opening a file of key: '" << strFileKey);
				m_currentFile = new mongo::MyGridFile( m_gridFs->findFile(strFileKey) );
				LOG4CXX_INFO(logger, m_currentFile->exists() << "! name: " << m_currentFile->getFilename() << " with chunks: " << m_currentFile->getNumChunks());
				bTudoBem = true;
			}
			else
			{
				// that means - no more files
				portionLength = -1;
			}
		}
		else if(m_readPreferenceType == SearchRequest_ReadPreferenceType_READ_ALL)
		{
			// TODO read all files from server
		}
	}
	else
	{
		lChunkToBeRead = m_lLastChunkRead + 1;

		bTudoBem = true;
	}

	if(bTudoBem == true)
	{
		/* the core of the method */
		mongo::MyGridFSChunk gridFsChunk = m_currentFile->getChunk(lChunkToBeRead);

		LOG4CXX_INFO(logger, "Read chunk no. " << lChunkToBeRead );

		int lCurrChunkLen = gridFsChunk.len();

		ByteArrayHeader dataHeader;
		dataHeader.set_datasource( m_strSourceName );
		dataHeader.set_filename( m_currentFile->getFilename() );
		dataHeader.set_offset( lChunkToBeRead * m_currentFile->getChunkSize() );
		dataHeader.set_size( lCurrChunkLen );

		int lDataHeaderByteSize = dataHeader.ByteSize();

		if(portionLength >= lCurrChunkLen + lDataHeaderByteSize + 1)
		{
			LOG4CXX_INFO(logger, "Given buffer is of enough size: "
					<< portionLength << " >= " << lCurrChunkLen << " + " << lDataHeaderByteSize );

			const char * dataBuffer = gridFsChunk.data(lCurrChunkLen);

			char * lDataHeaderArray = new char[lDataHeaderByteSize];
			dataHeader.SerializeToArray(lDataHeaderArray,lDataHeaderByteSize);

			char headerSize[1];
			headerSize[0] = (char)lDataHeaderByteSize;

			memcpy(const_cast<char*>(dataPortion),
					headerSize,
					1);

			memcpy(const_cast<char*>(dataPortion + 1),
					lDataHeaderArray,
					lDataHeaderByteSize);
			memcpy(const_cast<char*>(dataPortion + 1 + lDataHeaderByteSize),
					dataBuffer,
					lCurrChunkLen);

			LOG4CXX_INFO(logger, dataHeader.filename() << ": " << dataPortion[0+lDataHeaderByteSize] << dataPortion[1+lDataHeaderByteSize] << dataPortion[2+lDataHeaderByteSize] << "..." );

			/* final inside-object changes */
			if(m_mongoKeyListIter->has_last() && lChunkToBeRead == m_mongoKeyListIter->last())
				m_lLastChunkRead = -1;
			else if(lChunkToBeRead == m_currentFile->getNumChunks()-1)
				m_lLastChunkRead = -1;
			else
				m_lLastChunkRead++;

			if(m_lLastChunkRead == -1)
				m_mongoKeyListIter++;

			bRet = true;

			// TODO ???? Why delete causes problems?
//			delete [] dataBuffer;
//			delete [] lDataHeaderArray;
		}
		else
		{
			LOG4CXX_INFO(logger, "Given buffer is of NOT enough size" );
		}

		// if portionLength is too small (array is too small), return false and needed size
		portionLength = lCurrChunkLen + lDataHeaderByteSize + 1;
	}

	return bRet;
}

bool MongoDbDataSourceAdapter::write(void * key, char * dataPortion, int& portionLength)
{
	bool bRet = false;

	const char * data = dataPortion;
	const std::string remoteName((char*)key);
	size_t length = portionLength;

	// TODO probably add MD5 metadata

	m_gridFs->storeFile(data, length, remoteName);

	bRet = true;

	return bRet;
}

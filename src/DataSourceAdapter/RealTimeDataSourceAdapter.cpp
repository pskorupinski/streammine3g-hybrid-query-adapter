/*
 * RealTimeDataSourceAdapter.cpp
 *
 *  Created on: Oct 9, 2012
 *      Author: ubuntu
 */

#include "RealTimeDataSourceAdapter.h"


RealTimeDataSourceAdapter::RealTimeDataSourceAdapter()
{
    logger  = log4cxx::Logger::getLogger("sm.accessop");
}

RealTimeDataSourceAdapter::RealTimeDataSourceAdapter(int timeLimitMin)
{
    logger  = log4cxx::Logger::getLogger("sm.accessop");
	time_t now;
	time(&now);
	endTime = now + 60*timeLimitMin;
	m_pEmergencyBuffer = new char[READLENGTH];
	m_bEmergencyBufferActive = false;
	m_nEmergencyBufferSize = 0;
}

RealTimeDataSourceAdapter::~RealTimeDataSourceAdapter() {
	endTime = LONG_MAX;
}

bool RealTimeDataSourceAdapter::connect(::std::string host, int port, ::std::string sourceName)
{
	bool bRet = false;

	try
	{
        LOG4CXX_INFO(logger, "new ClientSocket(" << host << ", " << port << ");");
		client_socket = new ClientSocket( host, port );
		client_socket->setMaxLength(1024);	// should it really be here?
	    //this->readPreferenceType = readPreferenceType; - it has no meaning to real time data
	    bRet = true;
	}
	catch ( std::exception& e )
	{
        LOG4CXX_INFO(logger, "Exception on a socket" << e.what() );
	}

	return bRet;
}

bool RealTimeDataSourceAdapter::readNext(const char * dataPortion, int& portionLength)
{
	bool bRet = false;

    try
	{
    	if(time(0) < endTime) {
    		const char * dataBuffer = new char[READLENGTH];
    		int lLength;

			if(m_bEmergencyBufferActive)
			{
				lLength = m_nEmergencyBufferSize;
				memcpy(const_cast<char*>(dataBuffer), m_pEmergencyBuffer, lLength);
				m_bEmergencyBufferActive = false;
			}
			else
			{
    			lLength = client_socket->getData((char*)dataBuffer , READLENGTH);
			}

			if(lLength == -1)
			{
				LOG4CXX_INFO(logger, "Client socket returned -1.");
			}
			else
			{
				ByteArrayHeader dataHeader;
				dataHeader.set_datasource( m_strSourceName );
				dataHeader.set_filename( m_strSourceName );
				dataHeader.set_offset( 0 );
				dataHeader.set_size( lLength );

				int lDataHeaderByteSize = dataHeader.ByteSize();

				if(portionLength >= lLength + lDataHeaderByteSize + 1)
				{
					LOG4CXX_INFO(logger, "Given buffer is of enough size (" << portionLength << ">=" << lLength << "+" << lDataHeaderByteSize << ")");

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
							lLength);

			        LOG4CXX_INFO(logger, dataHeader.filename() << ": " << dataPortion[0+lDataHeaderByteSize] << dataPortion[1+lDataHeaderByteSize] << dataPortion[2+lDataHeaderByteSize] << "...");

					bRet = true;
				}
				else {
			        LOG4CXX_INFO(logger, "Given buffer is of NOT enough size");

					memcpy(const_cast<char*>(m_pEmergencyBuffer),dataBuffer,lLength);
					m_nEmergencyBufferSize = lLength;
					m_bEmergencyBufferActive = true;
				}

				// if portionLength is too small (array is too small), return false and needed size
				portionLength = lLength + lDataHeaderByteSize + 1;
			}
    	}
    	else {
			// that means - no more files
			portionLength = -1;
			delete client_socket;
			LOG4CXX_INFO(logger, "RealTimeDataSourceAdapter : Reading time finished!");
    	}
	}
    catch ( std::exception& e )
    {
        LOG4CXX_INFO( logger, "Exception on a socket" << e.what() );
    }

	return bRet;
}

/*
 * EndOfStreamHandler.cpp
 *
 *  Created on: Apr 27, 2013
 *      Author: ubuntu
 */

#include "EndOfStreamHandler.h"

#include <iostream>


void EndOfStreamHandler::sendEndOfStream(Collector* collector, int64_t timestamp, int key)
{
	log4cxx::LoggerPtr logger = log4cxx::Logger::getLogger("sm.accessop");

	char eos[] = ENDOFSTREAM;

	void* eventPtr = collector->allocEvent(
								-1,
								timestamp,
								ENDOFSTREAM_L);

	memcpy(eventPtr, (const void*)eos, ENDOFSTREAM_L);

    LOG4CXX_INFO(logger, "method: sendEndOfStream. eventPtr: " << (char*)eventPtr);

	collector->commit();

}

bool EndOfStreamHandler::checkEndOfStream(char* chBuff, int size)
{
	log4cxx::LoggerPtr logger = log4cxx::Logger::getLogger("sm.accessop");

	char eos[] = ENDOFSTREAM;

    LOG4CXX_INFO(logger, "...... check end of stream ...... "
			<< "size: " << size);
	if(size < 10) LOG4CXX_INFO(logger, " (" << chBuff << ")");

	if(size == ENDOFSTREAM_L && strcmp(chBuff, eos)==0)
		return true;
	else
		return false;

}

void EndOfStreamHandler::handleEndOfStream(Collector* collector)
{
	log4cxx::LoggerPtr logger = log4cxx::Logger::getLogger("sm.accessop");

	char eos[] = ENDOFSTREAM;
	void * buf = new char[ENDOFSTREAM_L];
	memcpy(buf, eos, ENDOFSTREAM_L);

    LOG4CXX_INFO(logger, "sendCustomProbe");

	collector->sendCustomProbe(buf, ENDOFSTREAM_L);

}

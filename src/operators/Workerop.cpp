/*
 * Workerop.cpp
 *
 *  Created on: Oct 25, 2012
 *      Author: ubuntu
 */

#include "Workerop.h"

#include <boost/serialization/map.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>

#include <sstream>
#include <string.h>

void Workerop::init(int sliceId, int sliceUId, int bucketCount, char* param, int size)
{
    logger  = log4cxx::Logger::getLogger("sm.workerop");

    LOG4CXX_INFO(logger, "Worker initiated.");

    timestampCounterProcessor = 0;
}

void Workerop::process(int routingKey, void* eventIn, int size, void* state, Collector* collector)
{
    LOG4CXX_INFO(logger, "Worker PROCESS" );

	if(EndOfStreamHandler::checkEndOfStream((char*)eventIn, size)) {
	    LOG4CXX_INFO(logger, "   --- WORKER: EndOfStream");
		EndOfStreamHandler::handleEndOfStream(collector);
	}
	else {
	    LOG4CXX_INFO(logger, "   --- WORKER: event - " << (char*)eventIn);

		typedef std::map<std::string, int> MAP;
		MAP* wordCountMap = (MAP*)state;
		(*wordCountMap)[(char*)eventIn]++;
	}
}

void Workerop::onReleaseBuffer(void* buf, BufferReleaseType bufferReleaseType)
{
    if (bufferReleaseType == streammine3G::StateBuffer && ((char*)buf)[0] == 'H') delete [](char*)buf;
    if (bufferReleaseType == streammine3G::EventBuffer)
		delete (int*) buf;
}


int Workerop::getStateSize(void* state)
{
    return sizeof(int);
}

void* Workerop::stateInit()
{
    return new std::map<std::string, int>();
}

void Workerop::freeState(void* state)
{
    LOG4CXX_INFO(logger, "STATE AFTER ALL THE DATA RECEIVED:");

    std::ostringstream oss;

    typedef std::map<std::string, int> MAP;
	MAP* wordCountMap = (MAP*)state;

    typedef std::map<std::string, int>::const_iterator MapIterator;
    for (MapIterator iter = wordCountMap->begin(); iter != wordCountMap->end(); iter++)
    {
         oss << iter->first;
         oss << ": ";
         oss << iter->second;
         oss << "\n";
    }

    LOG4CXX_INFO(logger, oss.str().c_str());

    delete wordCountMap;
}

void Workerop::serializeState(void* state, std::list<Buffer*>* buffers)
{
    std::map<std::string, int>* hashMap = static_cast<std::map<std::string, int>*>(state);

    std::stringstream outstream(std::stringstream::out | std::stringstream::binary);
    boost::archive::binary_oarchive oa(outstream);
    oa << hashMap;
    std::string mapAsString = outstream.str();
    size_t size = mapAsString.size() + 1;
    char* buf = new char[size];
    memcpy(buf, mapAsString.c_str(), size);

    buffers->push_back(new Buffer(buf, size));
}

void* Workerop::deserializeState(std::list<Buffer*>* buffers)
{
    char* buf = (char*) buffers->front()->getData();
    int size = buffers->front()->getSize();

    std::stringstream instream(std::string(buf, size), std::stringstream::in | std::stringstream::binary);
    boost::archive::binary_iarchive ia(instream);
    std::map<std::string, int>* hashMap = new std::map<std::string, int>();

    ia >> hashMap;
}

void Workerop::stateAccess(int routingKey, void* eventIn, int size, StateAccess* stateAccess)
{
    stateAccess->setKey(0);
}


Workerop::~Workerop()
{
}

extern "C"
{
    Operator *operatorInstance()
    {
        return new Workerop();
    }
}

/*
 * Workerop.h
 *
 *  Created on: Oct 25, 2012
 *      Author: ubuntu
 */

#ifndef WORKEROP_H_
#define WORKEROP_H_

#include <log4cxx/logger.h>
#include "OperatorImpl.hpp"
#include "../proto/SMByteArrayHeader.pb.h"

#include "Constants.h"

#include "../operations/EndOfStreamHandler.h"

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <sstream>

class Workerop : public OperatorImpl
{
    log4cxx::LoggerPtr logger;
    int64_t timestampCounterProcessor;
public:
	~Workerop();

	void init(int sliceId, int sliceUId, int bucketCount, char* param, int size);
    void process(int routingKey, void* eventIn, int size, void* state, Collector* collector);
    void onReleaseBuffer(void* buf, BufferReleaseType bufferReleaseType);

    void* stateInit();
    int getStateSize(void* state);
    void freeState(void* state);
    void serializeState(void* state, std::list<Buffer*>* buffers);
    void* deserializeState(std::list<Buffer*>* buffers);
    void stateAccess(int routingKey, void* eventIn, int size, StateAccess* stateAccess);

};

#endif /* WORKEROP_H_ */

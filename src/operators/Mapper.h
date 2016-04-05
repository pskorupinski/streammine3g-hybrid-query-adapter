/*
 * Mapper.h
 *
 *  Created on: Apr 10, 2013
 *      Author: ubuntu
 */

#ifndef MAPPER_H_
#define MAPPER_H_

#include <log4cxx/logger.h>
#include "OperatorImpl.hpp"
#include "../proto/SMOperatorInitParam.pb.h"
#include "../proto/SMByteArrayHeader.pb.h"
#include "../DataSourceAdapter/AbstractDataSourceAdapter.h"
#include "../DataSourceAdapter/MongoDbDataSourceAdapter.h"
#include "../DataSourceAdapter/RealTimeDataSourceAdapter.h"

#include "Constants.h"

#include "../operations/EndOfStreamHandler.h"

class Mapper : public OperatorImpl
{
    log4cxx::LoggerPtr logger;
    int64_t timestampCounterProcessor;
public:
	~Mapper();

    void init(int sliceId, int sliceUId, int bucketCount, char* param, int size);
    void onConnectAdapter(int portId, int sourceId, Collector* collector);
    void onReadAdapter(void* buf, int size, int sourceId, Collector* collector);
    void onReleaseBuffer(void* buf, BufferReleaseType bufferReleaseType);
    void process(int routingKey, void* eventIn, int size, void* state, Collector* collector);
};

#endif /* MAPPER_H_ */

/*
 * Accessop.h
 *
 *  Created on: Oct 25, 2012
 *      Author: ubuntu
 */

#ifndef ACCESSOP_H_
#define ACCESSOP_H_

#define PROCESS_PORTION_SIZE 1024

#include "OperatorImpl.hpp"
#include <google/protobuf/text_format.h>
#include "../proto/SMOperatorInitParam.pb.h"
#include "../proto/SMByteArrayHeader.pb.h"
#include "../DataSourceAdapter/AbstractDataSourceAdapter.h"
//#include "../DataSourceAdapter/MongoDbDataSourceAdapter.h"
#include "../DataSourceAdapter/RealTimeDataSourceAdapter.h"

#include "Constants.h"

#include "../operations/EndOfStreamHandler.h"

#include <string.h>
#include <iostream>
#include <log4cxx/logger.h>
#include <algorithm>

class Accessop : public OperatorImpl
{
private:
    log4cxx::LoggerPtr logger;
	SearchRequest * m_searchRequest;
	AbstractDataSourceAdapter * m_dataSourceAdapter;
	int m_lAdapterPortionSize;

    int64_t timestampCounterGenerator;
    int64_t timestampCounterProcessor;
public:
    void init(int sliceId, int sliceUId, int bucketCount, char* param, int size);
    void onConnectAdapter(int portId, int sourceId, Collector* collector);
    void onReadAdapter(void* buf, int size, int sourceId, Collector* collector);
    void onReleaseBuffer(void* buf, BufferReleaseType bufferReleaseType);
    bool generate(Collector* collector);
    void process(int routingKey, void* eventIn, int size, void* state, Collector* collector);
};

#endif /* ACCESSOP_H_ */

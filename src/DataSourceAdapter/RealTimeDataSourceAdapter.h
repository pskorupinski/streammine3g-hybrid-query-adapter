/*
 * RealTimeDataSourceAdapter.h
 *
 *  Created on: Oct 9, 2012
 *      Author: ubuntu
 */

#ifndef REALTIMEDATASOURCEADAPTER_H_
#define REALTIMEDATASOURCEADAPTER_H_

#include <log4cxx/logger.h>
#include "AbstractDataSourceAdapter.h"
#include "../socket/ClientSocket.h"
#include "../socket/SocketException.h"
#include <iostream>
#include <time.h>
#include <limits.h>
#define READLENGTH 1024

class RealTimeDataSourceAdapter : public AbstractDataSourceAdapter {
private:
    log4cxx::LoggerPtr logger;
	ClientSocket * client_socket;
	time_t endTime;
	const char * m_pEmergencyBuffer;
	int m_nEmergencyBufferSize;
	bool m_bEmergencyBufferActive;
public:
	RealTimeDataSourceAdapter();
	RealTimeDataSourceAdapter(int timeLimitMin);
	virtual ~RealTimeDataSourceAdapter();

	bool connect(::std::string host, int port, ::std::string sourceName = "");

	bool readDefine(SearchRequest_ReadPreferenceType readPreferenceType, void * key, int& portionLength) { return false; }
	bool readNext(const char * dataPortion, int& portionLength);

	bool write(void * key, char * dataPortion, int& portionLength) { return false; }

};

#endif /* REALTIMEDATASOURCEADAPTER_H_ */

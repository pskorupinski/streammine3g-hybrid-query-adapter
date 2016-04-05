/*
 * MongoDbDataSourceAdapter.h
 *
 *  Created on: Oct 10, 2012
 *      Author: ubuntu
 */

#ifndef MONGODBDATASOURCEADAPTER_H_
#define MONGODBDATASOURCEADAPTER_H_

#include "AbstractDataSourceAdapter.h"
#include <list>

#include <iostream>
#include <memory>
#include <mongo/client/dbclient.h>
#include "../gridfs/MyGridFS.h"
#include <mongo/bson/bson.h>
#include <log4cxx/logger.h>

class MongoDbDataSourceAdapter: public AbstractDataSourceAdapter {
private:
    log4cxx::LoggerPtr logger;

	mongo::DBClientConnection m_mongoConn;
	mongo::MyGridFS * m_gridFs;
	mongo::MyGridFile * m_currentFile;

	// files to be read
	std::list<GeneralKey> * m_ptrMongoKeyList;
	std::list<GeneralKey>::iterator m_mongoKeyListIter;

	int m_lLastChunkRead;
	int m_lCurrentFirstByteCounter;


public:
	MongoDbDataSourceAdapter();
	~MongoDbDataSourceAdapter();

	/**
	 * @param host - address of mongod (or mongos) server to connect. if host empty, connects to localhost
	 * @param port - port on which process is listening
	 * @param sourceName - dbName
	 */
	bool connect(::std::string host, int port, ::std::string sourceName = "");

	/**
	 * @param key - pointer to an array with keys
	 * @param portion length - will be always overridden to a chunk size in mongodb
	 */
	bool readDefine(SearchRequest_ReadPreferenceType readPreferenceType, void * key, int& portionLength);
	bool readNext(const char * dataPortion, int& portionLength);

	bool write(void * key, char * dataPortion, int& portionLength);
};

#endif /* MONGODBDATASOURCEADAPTER_H_ */

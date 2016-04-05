/*
 * AbstractDataSourceAdapter.h
 *
 *  Created on: Oct 9, 2012
 *      Author: ubuntu
 */

#ifndef ABSTRACTDATASOURCEADAPTER_H_
#define ABSTRACTDATASOURCEADAPTER_H_

#include "../proto/SMOperatorInitParam.pb.h"

#include "../proto/SMByteArrayHeader.pb.h"

class AbstractDataSourceAdapter {
protected:
	SearchRequest_ReadPreferenceType m_readPreferenceType;
	std::string m_strSourceName;
public:
	AbstractDataSourceAdapter() {};
	virtual ~AbstractDataSourceAdapter() {};

	virtual bool connect(::std::string host, int port, ::std::string sourceName = "") = 0;

	virtual bool readDefine(SearchRequest_ReadPreferenceType readPreferenceType, void * key, int& portionLength) = 0;
	virtual bool readNext(const char * dataPortion, int& portionLength) = 0;

	virtual bool write(void * key, char * dataPortion, int& portionLength) = 0;

};

#endif /* ABSTRACTDATASOURCEADAPTER_H_ */

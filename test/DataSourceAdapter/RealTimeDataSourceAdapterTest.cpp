/*
 * MongoDbDataSourceAdapterTest.cpp
 *
 *  Created on: Oct 19, 2012
 *      Author: ubuntu
 */


#include "../../src/DataSourceAdapter/RealTimeDataSourceAdapter.h"
//#define BOOST_TEST_MODULE MongoDbDataSourceAdapterTest
#include <boost/test/unit_test.hpp>
#include <iostream>
#include <fstream>

BOOST_AUTO_TEST_CASE( mongo_read_test )
{
	std::cout << "starting!" << std::endl;

    RealTimeDataSourceAdapter realtimeDSA;

    BOOST_CHECK(
    		realtimeDSA.connect("localhost", 6666, "")
    		);

    std::list<GeneralKey> * keyList = new std::list<GeneralKey>();

//    int portionLength = 0;
//
//    BOOST_CHECK(
//    		realtimeDSA.readDefine(
//    				SearchRequest_ReadPreferenceType_LIST_OF_KEYS, (void*) keyList, portionLength )
//    		);

    const char * chBuff;
    int portion = 1024;

    std::ofstream file;
    file.open("/local/mt1/workspace/example/test/DataSourceAdapter/output.txt");

    BOOST_CHECK(
    		file.is_open()
    		);

    do
    {
    	chBuff = new char[1024];

		bool bReadSuccess = realtimeDSA.readNext(chBuff, portion);

		if(bReadSuccess)
		{
			std::cout << portion << ": " << chBuff[0] << chBuff[1] << chBuff[2] << "...\n";
			file.write(chBuff, portion);
		}
		else
		{
			std::cout << portion << ", finished!\n";
			// no more to read
			if(portion == -1)
				break;
		}

    } while(true);

    file.close();

}



/*
 * MongoDbDataSourceAdapterTest.cpp
 *
 *  Created on: Oct 19, 2012
 *      Author: ubuntu
 */


#include "../../src/DataSourceAdapter/MongoDbDataSourceAdapter.h"
//#define BOOST_TEST_MODULE MongoDbDataSourceAdapterTest
#include <boost/test/unit_test.hpp>
#include <iostream>
#include <fstream>

BOOST_AUTO_TEST_CASE( mongo_read_test )
{
	std::cout << "starting!" << std::endl;

    MongoDbDataSourceAdapter mongodbDSA;

    BOOST_CHECK(
    		mongodbDSA.connect("localhost", 10004, "filesystem")
    		);

    std::list<GeneralKey> * keyList = new std::list<GeneralKey>();

    GeneralKey generalKey1;
    const char name1[] = "72425f1c3df63e7bbc3a802458aeaf8a";
    generalKey1.set_name(name1);
    generalKey1.set_first(0);
    generalKey1.set_last(2);
    keyList->push_back(generalKey1);

//    GeneralKey generalKey2;
//    const char name2[] = "file2.txt";
//    generalKey2.set_name(name2);
//    keyList->push_back(generalKey2);
//
//    GeneralKey generalKey3;
//    const char name3[] = "file3.txt";
//    generalKey3.set_name(name3);
//    keyList->push_back(generalKey3);

    int portionLength = 0;

    BOOST_CHECK(
    		mongodbDSA.readDefine(
    				SearchRequest_ReadPreferenceType_LIST_OF_KEYS, (void*) keyList, portionLength )
    		);

    const char * chBuff;
    int portion = 1024*256;

    do
    {
    	chBuff = new char[portion];

		bool bReadSuccess = mongodbDSA.readNext(chBuff, portion);

		if(bReadSuccess)
		{
			std::cout << portion << ": " << chBuff[0] << chBuff[1] << chBuff[2] << "...\n";
			//file.write(chBuff, portion);
		}
		else
		{
			std::cout << portion << ", finished!\n";
			// no more to read
			if(portion == -1)
				break;
		}

    } while(true);

}



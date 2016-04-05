#include "../../src/DataSourceAdapter/MongoDbDataSourceAdapter.h"
#include <boost/test/unit_test.hpp>

#define CHARDIGIT(i) (char)i+48

void gen_random(char *s, const int len) {
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz .,";

    for (int i = 0; i < len; ++i) {
        s[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
    }

    s[len] = 0;
}

BOOST_AUTO_TEST_CASE( mongo_read_test )
{
	int size = 1024*1024;
	char * exemplarFile = new char[size];

    MongoDbDataSourceAdapter mongodbDSA;

    BOOST_CHECK(
    		mongodbDSA.connect("localhost", 27017, "filesystem")
	);

	std::cout << "Connected." << std::endl;

	char key[] = "filex.txt";

	std::cout << "Array ok." << std::endl;

	for( int i=0; i<3; i++)
	{
		gen_random(exemplarFile, size);
		key[4] = CHARDIGIT(i+1);

		mongodbDSA.write(key, exemplarFile, size);

		std::cout << "Written to " << key << std::endl;
	}
}

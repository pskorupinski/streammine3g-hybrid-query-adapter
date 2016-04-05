#include <iostream>

#include "SamplePartitioner.hpp"

SamplePartitioner::SamplePartitioner()
{
}

char* SamplePartitioner::version()
{
    return (char*)"1.4.11";
}

void SamplePartitioner::init(int slicesCount, char* param, int size)
{
    logger  = log4cxx::Logger::getLogger("sm.partitioner");

    this->slicesCount = slicesCount;
    LOG4CXX_INFO(logger, "Initializing custom partitioner");

    /* Precompute a hash table */
}

int SamplePartitioner::getPartition(int key, void* event, int size)
{
	int sliceNumber;

    LOG4CXX_INFO(logger, "   --- PARTITIONER: Calling get partition");

    if(key == -1) {
    	sliceNumber = key;
    }
    else {
		/* Count a hash of a word */
		const char * word = (const char *) event;
		uint32_t hash = SuperFastHash(word, size);

		sliceNumber = floor( (double)hash / double(0xffffffff) * double(slicesCount) );

	    LOG4CXX_INFO(logger, "   --- PARTITIONER: hash - " << hash << ", slice - " << sliceNumber);
    }
    return sliceNumber;
}

SamplePartitioner::~SamplePartitioner()
{
}


extern "C"
{
    Partitioner *partitionerInstance()
    {
        return new SamplePartitioner();
    }
}


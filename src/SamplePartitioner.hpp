#ifndef SAMPLEPARTITIONER_HPP_
#define SAMPLEPARTITIONER_HPP_

#include <log4cxx/logger.h>
#include <streammine3G/Partitioner.hpp>
#include "operations/operations.h"
#include <math.h>

using streammine3G::Partitioner;

class SamplePartitioner : public Partitioner
{
private:
    log4cxx::LoggerPtr logger;
    int slicesCount;

public:
    SamplePartitioner();
    char* version();
    void init(int slicesCount, char* param, int size);
    int getPartition(int key, void* event, int size);
    virtual ~SamplePartitioner();
};

#endif

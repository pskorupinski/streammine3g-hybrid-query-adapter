#include <cstddef>

#include "OperatorImpl.hpp"

OperatorImpl::OperatorImpl()
{
}

void OperatorImpl::init(int sliceId, int sliceUId, int bucketCount, char* param, int size)
{
}

char* OperatorImpl::version()
{
    return (char*)"1.4.11";
}

void* OperatorImpl::stateInit()
{
    return NULL;
}

int OperatorImpl::getStateSize(void* state)
{
    return 0;
}

void OperatorImpl::freeState(void* state)
{
}

void OperatorImpl::onReleaseBuffer(void* buf, BufferReleaseType bufferReleaseType)
{
}

void OperatorImpl::serializeState(void* state, std::list<Buffer*>* buffers)
{
}

void* OperatorImpl::deserializeState(std::list<Buffer*>* buffers)
{
    return NULL;
}

void OperatorImpl::onConnectAdapter(int portId, int sourceId, Collector* collector)
{
}

void OperatorImpl::onDisconnectAdapter(int sourceId, Collector* collector)
{
}

void OperatorImpl::onReadAdapter(void* buf, int size, int sourceId, Collector* collector)
{
}

void OperatorImpl::onReplayAdapter(int64_t timestamp, Collector* collector)
{
}

void OperatorImpl::onPruneAdapter(int64_t timestamp, Collector* collector)
{
}

bool OperatorImpl::generate(Collector* collector)
{
    return false;
}

void OperatorImpl::stateAccess(int routingKey, void* eventIn, int size, StateAccess* stateAccess)
{
    stateAccess->setKey(-1);
}

void OperatorImpl::process(int routingKey, void* eventIn, int size, void* state, Collector* collector)
{
}

OperatorImpl::~OperatorImpl()
{
}

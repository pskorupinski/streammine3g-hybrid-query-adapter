#include <cstddef>

#include "DefaultOperator.hpp"

DefaultOperator::DefaultOperator()
{
}

void DefaultOperator::init(int sliceId, int sliceUId, char* param, int size)
{
}

char* DefaultOperator::version()
{
    return (char*)"1.1.9";
}

void* DefaultOperator::stateInit()
{
    return NULL;
}

int DefaultOperator::getStateSize(void* state)
{
    return 0;
}

void DefaultOperator::freeState(void* state)
{
}

void DefaultOperator::onReleaseBuffer(void* buf, BufferReleaseType bufferReleaseType)
{
}

void DefaultOperator::serializeState(void* state, std::list<Buffer*>* buffers)
{
}

void* DefaultOperator::deserializeState(std::list<Buffer*>* buffers)
{
    return NULL;
}

void DefaultOperator::onConnectAdapter(int sourceId, Collector* collector)
{
}

void DefaultOperator::onDisconnectAdapter(int sourceId, Collector* collector)
{
}

void DefaultOperator::onReadAdapter(void* buf, int size, int sourceId, Collector* collector)
{
}

void DefaultOperator::onReplayAdapter(int64_t timestamp, Collector* collector)
{
}

void DefaultOperator::onPruneAdapter(int64_t timestamp, Collector* collector)
{
}

bool DefaultOperator::generate(Collector* collector)
{
    return false;
}

void DefaultOperator::stateAccess(int routingKey, void* eventIn, int size, StateAccess* stateAccess)
{
    stateAccess->setKey(-1);
}

void DefaultOperator::process(int routingKey, void* eventIn, int size, void* state, Collector* collector)
{
}

DefaultOperator::~DefaultOperator()
{
}

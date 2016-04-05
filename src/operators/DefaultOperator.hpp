#ifndef DEFAULTOPERATOR_HPP_
#define DEFAULTOPERATOR_HPP_

#include <streammine3G/Operator.hpp>

using streammine3G::Operator;
using streammine3G::Collector;
using streammine3G::Buffer;
using streammine3G::StateAccess;
using streammine3G::BufferReleaseType;

class DefaultOperator : public Operator
{
public:
    DefaultOperator();
    virtual void init(int sliceId, int sliceUId, char* param, int size);
    virtual char* version();
    virtual void* stateInit();
    virtual int getStateSize(void* state);
    virtual void freeState(void* state);
    virtual void onReleaseBuffer(void* buf, BufferReleaseType bufferReleaseType);
    virtual void serializeState(void* state, std::list<Buffer*>* buffers);
    virtual void* deserializeState(std::list<Buffer*>* buffers);
    virtual void onConnectAdapter(int sourceId, Collector* collector);
    virtual void onDisconnectAdapter(int sourceId, Collector* collector);
    virtual void onReadAdapter(void* buf, int size, int sourceId, Collector* collector);
    virtual void onReplayAdapter(int64_t timestamp, Collector* collector);
    virtual void onPruneAdapter(int64_t timestamp, Collector* collector);
    virtual bool generate(Collector* collector);
    virtual void stateAccess(int routingKey, void* eventIn, int size, StateAccess* stateAccess);
    virtual void process(int routingKey, void* eventIn, int size, void* state, Collector* collector);
    virtual ~DefaultOperator();
};

#endif

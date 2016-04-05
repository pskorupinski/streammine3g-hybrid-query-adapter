#ifndef JBOSSNETTYADAPTER_HPP_
#define JBOSSNETTYADAPTER_HPP_

#include <streammine3G/Collector.hpp>

#include "GPBMessageListener.hpp"

using streammine3G::Collector;

class JBossNettyAdapter
{
private:
    GPBMessageListener* gpbFrameListener;
    bool header;
    int pos;
    int result;

    int readVarInt32(char byte);

public:
    JBossNettyAdapter(GPBMessageListener* gpbFrameListener);
    int onRead(void* buf, int size, int sliceId, Collector* collector);
    static void writeVarInt32(int value, Collector* collector, int sourceId);
    virtual ~JBossNettyAdapter();
};

#endif

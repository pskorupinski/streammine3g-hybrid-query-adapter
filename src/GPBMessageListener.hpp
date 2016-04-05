#ifndef GPBFRAMELISTENER_HPP_
#define GPBFRAMELISTENER_HPP_

#include <streammine3G/Collector.hpp>

using streammine3G::Collector;

class GPBMessageListener
{
public:
    GPBMessageListener() {};
    virtual void onMessage(void* buf, int size, int sliceId, Collector* collector) = 0;
    virtual ~GPBMessageListener() {};
};

#endif

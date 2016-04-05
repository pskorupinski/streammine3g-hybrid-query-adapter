#ifndef TESTMANAGER_HPP_
#define TESTMANAGER_HPP_

#include <streammine3G/Manager.hpp>
#include <streammine3G/CloudControl.hpp>

#include "proto/SMOperatorInitParam.pb.h"

using streammine3G::Manager;
using streammine3G::CloudControl;
using streammine3G::PerformanceProbe;
using streammine3G::Action;

class SampleManager : public Manager
{
private:
    int nodeCounter;
    int timeCounter;
    char* libraryPath;
    CloudControl* cloudControl;

public:
    SampleManager();
    void init(CloudControl* cloudControl, char* nodeName, int nodeId);
    char* version();
    void serializeState(std::list<Buffer*>* buffers);
    void deserializeState(std::list<Buffer*>* buffers);
    void onReleaseBuffer(void* buf);
    void onNodeJoin(char* nodeName, int nodeId);
    void onNodeLeave(char* nodeName, int nodeId);
    void onPerformanceProbe(PerformanceProbe* PerformanceProbe);
    void onCustomProbe(int sliceUId, void* buf, int size);
    void onActionCompleted(Action action, char* payload1, int payload2, char* payload3);
    void onTimer();
    void onConnectAdapter(int portId, int sourceId);
    void onDisconnectAdapter(int sourceId);
    void onReadAdapter(void* buf, int size, int sourceId);
    virtual ~SampleManager();
};

#endif

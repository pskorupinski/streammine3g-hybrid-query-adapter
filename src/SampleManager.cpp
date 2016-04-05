#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

#include "SampleManager.hpp"

using streammine3G::OperatorConfig;
using streammine3G::CreateOperator_SUCCESS;
using streammine3G::CreateOperator_FAILED;
using streammine3G::DeployOperator_SUCCESS;
using streammine3G::DeployOperator_FAILED;
using streammine3G::RemoveOperator_SUCCESS;
using streammine3G::RemoveOperator_FAILED;
using streammine3G::WireOperator_SUCCESS;
using streammine3G::WireOperator_FAILED;
using streammine3G::UnwireOperator_SUCCESS;
using streammine3G::UnwireOperator_FAILED;
using streammine3G::DeployOperatorSlice_SUCCESS;
using streammine3G::DeployOperatorSlice_FAILED;
using streammine3G::RemoveOperatorSlice_SUCCESS;
using streammine3G::RemoveOperatorSlice_FAILED;
using streammine3G::SyncOperatorSlice_SUCCESS;
using streammine3G::SyncOperatorSlice_FAILED;

SampleManager::SampleManager()
{
    nodeCounter = 0;
    timeCounter = 0;
}

void SampleManager::init(CloudControl* cloudControl, char* nodeName, int nodeId)
{
    this->cloudControl = cloudControl;

    libraryPath = new char[1024];
    char* path = getenv("LIBRARYPATH");
    if (path == NULL) sprintf(libraryPath, ".");
    else sprintf(libraryPath, "%s", path);
}

char* SampleManager::version()
{
    return (char*)"1.1.15";
}

void SampleManager::serializeState(std::list<Buffer*>* buffers)
{
    buffers->push_back(new Buffer(&nodeCounter, sizeof(int)));
    buffers->push_back(new Buffer(&timeCounter, sizeof(int)));
}

void SampleManager::deserializeState(std::list<Buffer*>* buffers)
{
    if (buffers->size() != 2) return;

    std::list<Buffer*>::iterator iterator = --buffers->end();

    Buffer* buffer1 = buffers->front();
    Buffer* buffer2 = *iterator;

    //memcpy(&nodeCounter, buffer1->getData(), sizeof(int));
    //memcpy(&timeCounter, buffer2->getData(), sizeof(int));
}

void SampleManager::onReleaseBuffer(void* buf)
{
}

void SampleManager::onNodeJoin(char* nodeName, int nodeId)
{
    nodeCounter++;
    std::cout << "Node joined: " << nodeName << "\n";

    cloudControl->checkpointManagerState();
}

void SampleManager::onNodeLeave(char* nodeName, int nodeId)
{
    nodeCounter--;
    std::cout << "Node left: " << nodeName << "\n";

    if (nodeCounter == 0) cloudControl->shutDown();

    cloudControl->checkpointManagerState();
}

void SampleManager::onPerformanceProbe(PerformanceProbe* performanceProbe)
{
    printf("Received probe: %jd, %s, %2d\n", performanceProbe->getTimestamp(), performanceProbe->getNodeName(), performanceProbe->getNodeId());
    for (int i=0; i<performanceProbe->getSliceProbes()->size(); i++)
    {
	    printf("Received probe: %s, %2d, %2d, %2d = IN: %10jd, %3jd OUT: %jd, %3jd, PROC: %3jd, state size: %3jd, %3jd, %3d, %3jd, %3jd\n",
			performanceProbe->getSliceProbes()->at(i)->getOperatorName(), performanceProbe->getSliceProbes()->at(i)->getOperatorId(),
			performanceProbe->getSliceProbes()->at(i)->getSliceId(), performanceProbe->getSliceProbes()->at(i)->getSliceUId(),
			performanceProbe->getSliceProbes()->at(i)->getDataVolumeIn(), performanceProbe->getSliceProbes()->at(i)->getEventCountIn(),
			performanceProbe->getSliceProbes()->at(i)->getDataVolumeOut(), performanceProbe->getSliceProbes()->at(i)->getEventCountOut(),
			performanceProbe->getSliceProbes()->at(i)->getEventCountProcessing(), performanceProbe->getSliceProbes()->at(i)->getStateSize(),
			performanceProbe->getSliceProbes()->at(i)->getProcessingTime(), performanceProbe->getSliceProbes()->at(i)->getQueueItemCount(),
			performanceProbe->getSliceProbes()->at(i)->getQueueSize(), performanceProbe->getSliceProbes()->at(i)->getQueueTimestamp());
    }

    for (int i=0; i<performanceProbe->getNetworkProbes()->size(); i++)
    printf("Received network probe from NIC: %s\n", performanceProbe->getNetworkProbes()->at(i)->getNICName());
}

void SampleManager::onCustomProbe(int sliceUId, void* buf, int size)
{
    std::cout << "onCustomProbe: "<< (char*)buf << " from slice w/ sliceUId: " << sliceUId << "\n";
}

void SampleManager::onActionCompleted(Action action, char* payload1, int payload2, char* payload3)
{
    if (action == CreateOperator_SUCCESS)      std::cout << "CreateOperator_SUCCESS " << payload1 << "\n";
    if (action == CreateOperator_FAILED)       std::cout << "CreateOperator_FAILED " << payload1 << "\n";

    if (action == DeployOperator_SUCCESS)      std::cout << "DeployOperator_SUCCESS " << payload1 << "\n";
    if (action == DeployOperator_FAILED)       std::cout << "DeployOperator_FAILED " << payload1 << "\n";

    if (action == RemoveOperator_SUCCESS)      std::cout << "RemoveOperator_SUCCESS " << payload1 << "\n";
    if (action == RemoveOperator_FAILED)       std::cout << "RemoveOperator_FAILED " << payload1 << "\n";

    if (action == WireOperator_SUCCESS)        std::cout << "WireOperator_SUCCESS " << payload1 << "\n";
    if (action == WireOperator_FAILED)         std::cout << "WireOperator_FAILED " << payload1 << "\n";

    if (action == UnwireOperator_SUCCESS)      std::cout << "UnwireOperator_SUCCESS " << payload1 << "\n";
    if (action == UnwireOperator_FAILED)       std::cout << "UnwireOperator_FAILED " << payload1 << "\n";

    if (action == DeployOperatorSlice_SUCCESS) std::cout << "DeployOperatorSlice_SUCCESS " << payload2 << "\n";
    if (action == DeployOperatorSlice_FAILED)  std::cout << "DeployOperatorSlice_FAILED " << payload2 << "\n";

    if (action == RemoveOperatorSlice_SUCCESS) std::cout << "RemoveOperatorSlice_SUCCESS " << payload2 << "\n";
    if (action == RemoveOperatorSlice_FAILED)  std::cout << "RemoveOperatorSlice_FAILED " << payload2 << "\n";

    if (action == SyncOperatorSlice_SUCCESS)   std::cout << "SyncOperatorSlice_SUCCESS " << payload2 << "\n";
    if (action == SyncOperatorSlice_FAILED)    std::cout << "SyncOperatorSlice_FAILED " << payload2 << "\n";
}

void SampleManager::onTimer()
{
    OperatorConfig* operatorConfig = NULL;

    std::cout << "onTimer "<< timeCounter + 1 << "...\n";
    std::cout << "nodeCounter "<< nodeCounter << "...\n";

    if (nodeCounter != 2 && timeCounter == 0) return;
    timeCounter++;

    /////////////////////////////////////////////////////////////////////////////////
     /////////////////////////////////////////////////////////////////////////////////
 	/* Mongo DB Reading operator */
 	SearchRequest searchRequest1;

    GeneralKey * generalKey1 = searchRequest1.add_generalkeys();
    const char name1[] = "file1.txt";
    generalKey1->set_name(name1);

    GeneralKey * generalKey2 = searchRequest1.add_generalkeys();
    const char name2[] = "file2.txt";
    generalKey2->set_name(name2);

    GeneralKey * generalKey3 = searchRequest1.add_generalkeys();
    const char name3[] = "file3.txt";
    generalKey3->set_name(name3);

    searchRequest1.set_host("localhost");
 	searchRequest1.set_port(10001);
 	searchRequest1.set_datasourceimpltype(SearchRequest_DataSourceImplType_MONGO_GRIDFS);
 	searchRequest1.set_readpreferencetype(SearchRequest_ReadPreferenceType_LIST_OF_KEYS);
 	searchRequest1.set_sourcename("filesystem");

   	const int lSearchRequestByteSize = searchRequest1.ByteSize();
    char * ptrByteSearchRequest = new char[lSearchRequestByteSize];
    searchRequest1.SerializeToArray(ptrByteSearchRequest,lSearchRequestByteSize);
    /////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////


    switch(timeCounter)
    {
        case 3:
            char sourceLib[255];
            char workerLib[255];
            char partitionerLib[255];

            sprintf(sourceLib, "%s/libAccessop.so", libraryPath);
            sprintf(workerLib, "%s/libWorkerop.so", libraryPath);

            sprintf(partitionerLib,   "%s/libSamplePartitioner.so", libraryPath);

            // configure source operator
            operatorConfig = cloudControl->createOperator((char*)"source", 0 /* operatorId */);
            operatorConfig->setParameter((char*)LIBRARYPATH, (char*)&sourceLib);
			operatorConfig->setParameter((char*)PARAMETERS, ptrByteSearchRequest, lSearchRequestByteSize);
            operatorConfig->setParameter((char*)TIMERINTERVAL, (char*)"1000000");
            operatorConfig->setParameter((char*)CHECKPOINTEPOCHLEN, (char*)"10");
            //operatorConfig->setParameter((char*)LAYERTYPE, (char*)"noorderdelegate");

            // configure worker
            operatorConfig = cloudControl->createOperator((char*)"worker", 1 /* operatorId */);
            operatorConfig->setParameter((char*)LIBRARYPATH, (char*)&workerLib);
            operatorConfig->setParameter((char*)PARAMETERS, (char*)"testParameter1");
            operatorConfig->setParameter((char*)SLICES, (char*)"2");
            operatorConfig->setParameter((char*)CHECKPOINTEPOCHLEN, (char*)"10");
            //operatorConfig->setParameter((char*)LAYERTYPE, (char*)"noorderdelegate");

            // deploy previously configured operators - deployment means registering the nodes in the ZK config
            cloudControl->deployOperator((char*)"source");
            cloudControl->deployOperator((char*)"worker");

            // connect operators
            cloudControl->wireOperator((char*)"source", (char*)"worker");
            break;

        case 5:
            // sliceId in this case (see config above) we have 2 slices per op
            // sliceUId unique number (has to be different for each slice)
            cloudControl->deployOperatorSlice((char*)"node1.mycloud.com", (char*)"source", 0 /* sliceId */, 0 /* sliceUId */);
            cloudControl->deployOperatorSlice((char*)"node2.mycloud.com", (char*)"worker", 0 /* sliceId */, 1 /* sliceUId */);
            cloudControl->deployOperatorSlice((char*)"node2.mycloud.com", (char*)"worker", 1 /* sliceId */, 2 /* sliceUId */);
            break;

        case 7:
            cloudControl->launchOperatorSlice(0);
            cloudControl->launchOperatorSlice(1);
            cloudControl->launchOperatorSlice(2);
            break;

        case 24:
            cloudControl->tearDownOperatorSlice(0);
            cloudControl->tearDownOperatorSlice(1);
            cloudControl->tearDownOperatorSlice(2);
            break;

        case 26:
            cloudControl->removeOperatorSlice(0);
            cloudControl->removeOperatorSlice(1);
            cloudControl->removeOperatorSlice(2);
            break;

        case 27:
            cloudControl->unwireOperator((char*)"source", (char*)"worker");
            break;

        case 28:
            cloudControl->removeOperator((char*)"source");
            cloudControl->removeOperator((char*)"worker");

            cloudControl->shutDownNode((char*)"node1.mycloud.com");
            cloudControl->shutDownNode((char*)"node2.mycloud.com");
            break;

        case 29:
            cloudControl->shutDownNode((char*)"node0.mycloud.com");
            break;
    }

    cloudControl->checkpointManagerState();
}

void SampleManager::onConnectAdapter(int portId, int sourceId)
{
    std::cout << "On connect from source " << sourceId << "\n";

    char* buf = new char[1];
    cloudControl->readAdapter(buf, 1, sourceId);
}

void SampleManager::onDisconnectAdapter(int sourceId)
{
    std::cout << "On dicconnect from source " << sourceId << "\n";
}

void SampleManager::onReadAdapter(void* buf, int size, int sourceId)
{
    cloudControl->writeAdapter(buf, size, sourceId); // echo server
    delete [](char*)buf;

    buf = new char[1];
    cloudControl->readAdapter(buf, 1, sourceId);
}

SampleManager::~SampleManager()
{
    delete[] libraryPath;
}

extern "C"
{
    Manager *managerInstance()
    {
        return new SampleManager();
    }
}


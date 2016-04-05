/*
  Google Protocol Buffers Patch for preventing segfault when tearing down the system
  as the code for releasing buffers of operators/managers does not exist anymore during shutdown of StreamMine3G
*/
#include <vector>
#include <cstddef>
#include <pthread.h>

#include "GPBPatch.hpp"

namespace GPBPatch
{

std::vector<void (*)()>* shutdown_functions = NULL;
pthread_mutex_t* shutdown_functions_mutex = NULL;

void InitShutdownFunctions()
{
    GPBPatch::shutdown_functions = new std::vector<void (*)()>;
    GPBPatch::shutdown_functions_mutex = new pthread_mutex_t;
    pthread_mutex_init(GPBPatch::shutdown_functions_mutex, NULL);
}

void OnShutdown(void (*func)())
{
    pthread_mutex_lock(GPBPatch::shutdown_functions_mutex);
    GPBPatch:: shutdown_functions->push_back(func);
    pthread_mutex_unlock(GPBPatch::shutdown_functions_mutex);
}

void ShutdownProtobufLibrary()
{
    if (GPBPatch::shutdown_functions == NULL) return;

    pthread_mutex_lock(GPBPatch::shutdown_functions_mutex);
    for (int i = 0; i < (int)GPBPatch::shutdown_functions->size(); i++) GPBPatch::shutdown_functions->at(i)();

    delete GPBPatch::shutdown_functions;
    GPBPatch::shutdown_functions = NULL;
    pthread_mutex_unlock(GPBPatch::shutdown_functions_mutex);
    delete GPBPatch::shutdown_functions_mutex;
    GPBPatch::shutdown_functions_mutex = NULL;
}

}

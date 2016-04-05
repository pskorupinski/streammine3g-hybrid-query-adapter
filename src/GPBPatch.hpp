#ifndef GPBPATCH_HPP_
#define GPBPATCH_HPP_

namespace GPBPatch
{

void InitShutdownFunctions();
void OnShutdown(void (*func)());
void ShutdownProtobufLibrary();
}

#endif

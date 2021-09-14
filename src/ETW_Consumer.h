/*
* Desc: consume the ETW event trace in different ways(realtime and file-based), need to register to a specific session 
*   and can set filter condition and processing callbacks when registering
* APIs:
*/

#pragma once
#include "ETW_Utils.h"

//event callback
void WINAPI ProcessEvent(PEVENT_RECORD pEvent);

//event real-time processing thread
DWORD WINAPI ConsumerThread(LPVOID param);

struct ETWTraceConsumer {

};
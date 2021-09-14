/*
* Desc: receive, store, process and dispatch event, one session can have multiple providers, session
*   can store event in a log file or dispatch to consumer in real-time
* APIs:
*/

#pragma once
#include "ETW_Utils.h"

struct ETWTraceConsumer;

struct ETWTraceSession {
    LARGE_INTEGER mStartQpc = {};
    LARGE_INTEGER mQpcFrequency = {};
    ETWTraceConsumer* mETWTraceConsumer = nullptr;
    TRACEHANDLE mETWSessionHandle = 0; //invalid session handle are 0
    TRACEHANDLE mETWTraceHandle = INVALID_PROCESSTRACE_HANDLE; //invalid trace handles are INVALID_PROCESSTRACE_HANDLE

    ULONG Start(
        ETWTraceConsumer* pTraceConsumer, //Required ETWTraceConsumer instance
        char const* etlPath, //If nullptr, live/realtime tracing session
        char const* sessionName //Required session naem
    );
    void Stop();

    static ULONG StopNamedSession(char const* sessionName);
};
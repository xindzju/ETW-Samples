/*
* Desc: receive, store, process and dispatch event, one session can have multiple providers, session
*   can store event in a log file or dispatch to consumer in real-time
* APIs:
*/
#pragma once
#include "ETW_Utils.h"

/*
//kernel session
NT Kernel Logger                        Trace                         Running
Circular Kernel Context Logger          Trace                         Running

//user session
Eventlog-Security                       Trace                         Running
AppModel                                Trace                         Running
DiagLog                                 Trace                         Running
Diagtrack-Listener                      Trace                         Running
EventLog-Application                    Trace                         Running
EventLog-System                         Trace                         Running
LwtNetLog                               Trace                         Running
Microsoft-Windows-Rdp-Graphics-RdpIdd-Trace Trace                         Running
NetCore                                 Trace                         Running
NtfsLog                                 Trace                         Running
RadioMgr                                Trace                         Running
ReFSLog                                 Trace                         Running
UBPM                                    Trace                         Running
WdiContextLog                           Trace                         Running
WiFiSession                             Trace                         Running
WPR_initiated_DiagTrackMiniLogger_OneTrace_User_Logger_20210730_1 EC_0 Trace                         Running
WPR_initiated_DiagTrackMiniLogger_WPR System Collector Trace                         Running
SgrmEtwSession                          Trace                         Running
CldFltLog                               Trace                         Running
SleepStudyTraceSession                  Trace                         Running
Microsoft-VisualStudio-Telemetry-PerfWatson2-9360 Trace                         Running
NOCAT                                   Trace                         Running
MpWppTracing-20210914-091728-00000003-ffffffff Trace                         Running
Admin_PS_Provider                       Trace                         Running
ScreenOnPowerStudyTraceSession          Trace                         Running
Microsoft-VisualStudio-Telemetry-PerfWatson2-19324 Trace                         Running
SHS-09142021-091747-7-1ff               Trace                         Running
Microsoft-VisualStudio-Telemetry-PerfWatson2-19928 Trace                         Running
8696EAC4-1288-4288-A4EE-49EE431B0AD9    Trace                         Running
*/

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
#include "ETW_Consumer.h"

//event callback
void WINAPI ProcessEvent(PEVENT_RECORD pEvent) {
}

//event real-time processing thread
DWORD WINAPI ConsumerThread(LPVOID param) {
    EVENT_TRACE_LOGFILE trace;
    memset(&trace, 0, sizeof(trace));
    //trace.LoggerName = const_cast<wchar_t*>(KERNEL_LOGGER_NAME);
    trace.LoggerName = KERNEL_LOGGER_NAME;
    trace.LogFileName = NULL;
    //specify how to process the event
    trace.ProcessTraceMode = PROCESS_TRACE_MODE_REAL_TIME | PROCESS_TRACE_MODE_EVENT_RECORD;
    trace.Context = NULL;
    //specify event processing function
    trace.EventRecordCallback = ProcessEvent;

    //open session
    TRACEHANDLE handle = OpenTrace(&trace);
    if (handle == (TRACEHANDLE)INVALID_HANDLE_VALUE)
    {
        printf("handle is invalid value.\n");
        return -1;
    }

    //Start to process event
    ProcessTrace(&handle, 1, 0, 0);

    CloseTrace(handle);
    return 0;
}

/*
struct _EVENT_TRACE_LOGFILEA {
    LPSTR                   LogFileName;      // Logfile Name
    LPSTR                   LoggerName;       // LoggerName
    LONGLONG                CurrentTime;      // timestamp of last event
    ULONG                   BuffersRead;      // buffers read to date
    union {
        ULONG               LogFileMode;      // Mode of the logfile
        ULONG               ProcessTraceMode; // Processing flags
    } DUMMYUNIONNAME;
    EVENT_TRACE             CurrentEvent;     // Current Event from this stream
    TRACE_LOGFILE_HEADER    LogfileHeader;    // logfile header structure
    PEVENT_TRACE_BUFFER_CALLBACKA             // callback before each buffer
                            BufferCallback;   // is read

    //
    // following variables are filled for BufferCallback.
    //
    ULONG                   BufferSize;
    ULONG                   Filled;
    ULONG                   EventsLost;
    //
    // following needs to be propagated to each buffer
    //
    union {
        PEVENT_CALLBACK         EventCallback;  // callback for every event
        PEVENT_RECORD_CALLBACK  EventRecordCallback;
    } DUMMYUNIONNAME2;


    ULONG                   IsKernelTrace;  // TRUE for kernel logfile

    PVOID                   Context;        // reserved for internal use
};*/
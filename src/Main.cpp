#include "ETW_Consumer.h"
#include "ETW_Controller.h"
#include "ETW_Provider.h"

int main() {
    uint32_t buff_size = sizeof(EVENT_TRACE_PROPERTIES) + sizeof(KERNEL_LOGGER_NAME);
    EVENT_TRACE_PROPERTIES* trace_config = reinterpret_cast<EVENT_TRACE_PROPERTIES*>(new char[buff_size]);

    memset(trace_config, 0, buff_size);
    trace_config->Wnode.BufferSize = buff_size;
    trace_config->Wnode.Flags = WNODE_FLAG_TRACED_GUID;
    trace_config->Wnode.ClientContext = 1;
    trace_config->Wnode.Guid = SystemTraceControlGuid;          //NT Kernel Logger session GUID
    trace_config->EnableFlags = EVENT_TRACE_FLAG_FILE_IO_INIT;    //disk IO event
    trace_config->LogFileMode = EVENT_TRACE_REAL_TIME_MODE;     //real-time mode
    trace_config->LoggerNameOffset = sizeof(EVENT_TRACE_PROPERTIES);

    EVENT_TRACE_PROPERTIES* temp_config = reinterpret_cast<EVENT_TRACE_PROPERTIES*>(new char[buff_size]);
    memcpy(temp_config, trace_config, buff_size);

    TRACEHANDLE session_handle = NULL;
    uint32_t status = 0;

    //open session: NT Kernel Logger
    status = StartTrace(&session_handle, KERNEL_LOGGER_NAME, temp_config);
    if (ERROR_SUCCESS != status)
    {
        if (ERROR_ALREADY_EXISTS == status)
        {
            printf("The NT Kernel Logger session is already in use.\n");
            //NT Kernel Logger session already existing, close and then reopen
            status = ControlTrace(NULL, KERNEL_LOGGER_NAME, temp_config, EVENT_TRACE_CONTROL_STOP);
            if (SUCCEEDED(status))
            {
                status = StartTrace(&session_handle, KERNEL_LOGGER_NAME, trace_config);
                if (ERROR_SUCCESS != status)
                {
                    printf("err %d\n", GetLastError());
                }
            }
        }
        else
        {
            printf("EnableTrace() failed with %lu\n", status);
        }
    }

    //create event processing thread for real-time processing
    CreateThread(NULL, 0, ConsumerThread, NULL, 0, 0);

    //block here to wait for event processing thread executing
    printf("Press any key to end trace session.\n");
    getchar();

    //Close NT Kernel Logger session
    status = ControlTrace(session_handle, KERNEL_LOGGER_NAME, trace_config, EVENT_TRACE_CONTROL_STOP);

    if (trace_config != NULL)
    {
        delete[]trace_config;
    }
    return 0;
}
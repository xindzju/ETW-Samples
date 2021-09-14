# ETW-Samples


### Controller
Manage Session and Provider
* Enable/Disable provider

### Session
* Public
Public session is global session, can receive related event globally

* Private(uncommon)
Private session can only receive the event in the process it belongs to

### Logging mode
https://docs.microsoft.com/en-us/windows/win32/etw/logging-mode-constants?redirectedfrom=MSDN
* EVENT_TRACE_FILE_MODE_NONE: will generate huge log file
* EVENT_TRACE_FILE_MODE_SEQUENTIAL: need config MaximumFilesSize
* EVENT_TRACE_REAL_TIME_MODE: one provider and one consumer, and only for public session
  
### ETW Provider
System Widgets, Driver, Applications
First register an event trace to system
EnableTraceEx2: connect provider and session, automated registeration
TraceHandle

### ETW Consumer
* OpenTrace: 
* Event trace callback: general callback can be specified in the OpenTrace call, and spepcific callback can be register in the SetTrackCallback call
* ProcessTrace: using callback to process trace, using an thread
* CloseTrace: called by Consumer or Controller close session


### Calling Stack
1. Create Session
   1. StartTrace: Property is very important
2. Init Provider
   1. trace handle and provider id
   2. controlcode
   3. enableparameters


### Relationship of Provider, Consumer and Session
* one Provider: multi Session
* one Consumer: one Session
  

### Useful APIs
StartTrace: create event trace session, use the Properties to correlate provider
EnableTrace: enable provider
ControlTrace: disable provider
OpenTrace: build relationship between consumer and event trace session, can specify generic event trace handle callback
SetTraceCallback: specific event trace handle callback 
ProcessTrace: process trace in block way
CloseTrace: stop process
### Terms
* TDH: Trace Data Helper

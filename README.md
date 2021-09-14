# ETW-Samples
Samples written in the process of studying Event Tracing for Windows(ETW).

### Event Tracing Session
https://docs.microsoft.com/en-us/windows/win32/etw/event-tracing-sessions
* Public
Public session is global session, can receive related event globally
* Private(uncommon)
Private session can only receive the event in the process it belongs to

### ETW Controller
https://docs.microsoft.com/en-us/windows/win32/etw/controlling-event-tracing-sessions
* Manage Session and Provider
* Enable/Disable provider
  
### ETW Provider
https://docs.microsoft.com/en-us/windows/win32/etw/providing-events
* EnableTraceEx2: connect provider and session, automated registeration

### ETW Consumer
https://docs.microsoft.com/en-us/windows/win32/etw/consuming-events
* OpenTrace: 
* Event trace callback: general callback can be specified in the OpenTrace call, and spepcific callback can be register in the SetTrackCallback call
* ProcessTrace: using callback to process trace, using an thread
* CloseTrace: called by Consumer or Controller close session

### Useful APIs
* StartTrace: create event trace session, use the Properties to correlate provider
* EnableTrace: enable provider
* ControlTrace: disable provider
* OpenTrace: build relationship between consumer and event trace session, can specify generic event trace handle callback
* SetTraceCallback: specific event trace handle callback 
* ProcessTrace: process trace in block way
* CloseTrace: stop process

### Logman
Logman.exe is a native Windows command-line utility, which is considered to be a Controller. 
* List all running event tracing sessions, must excuted from an elevated context
  ```
  logman query -ets
  ```
* List all providers that a trace session is subscribed to
  ```
  logman query "EventLog-Application" -ets 
  ```
* List all registered ETW providers, supplying their name and GUID
  ```
  logman query providers
  ```
* View an individual provider
  ```
  logman query providers Microsoft-Windows-PowerShell
  ```
* View all providers that a specific process is sending event to
  ```
  logman query providers -pid <pid_number>
  ```
* Create a tracing session
  ```
  logman create trace <session_name> -ets
  ```

### Reference
 * https://renyili.org/post/etw_study/
 * https://blog.palantir.com/tampering-with-windows-event-tracing-background-offense-and-defense-4be7ac62ac63
 * https://randomascii.wordpress.com/2015/09/24/etw-central/ 
 * https://www.ired.team/miscellaneous-reversing-forensics/windows-kernel-internals/etw-event-tracing-for-windows-101

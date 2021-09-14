/*
* Desc: every provider has a GUID, there are 4 types of provider, MOF Providers, WPP Providers, manifest-based Providers(recommended) and TraceLogging Providers(recommended)
* APIs:
* Built-in: 
* List all the providers: logman query providers
*/

#pragma once
#include "ETW_Utils.h"

#include "ETW/Microsoft_Windows_D3D9.h"
#include "ETW/Microsoft_Windows_Dwm_Core.h"
#include "ETW/Microsoft_Windows_DXGI.h"
#include "ETW/Microsoft_Windows_DxgKrnl.h"
#include "ETW/Microsoft_Windows_EventMetadata.h"
#include "ETW/Microsoft_Windows_Win32k.h"
#include "ETW/NT_Process.h"

/*
* EventRegister: https://docs.microsoft.com/en-us/windows/win32/api/evntprov/nf-evntprov-eventregister
* EventWrite: https://docs.microsoft.com/en-us/windows/win32/api/evntprov/nf-evntprov-eventwrite
*/

/*
//system(kernel) provider: events can only be traced by Kernel Session("NT Kernel Logger" and "Circular Kernel Context Logger")
Windows Kernel Trace                     {9E814AAD-3204-11D2-9A82-006008A86939}

C:\WINDOWS\system32>logman query providers "Windows Kernel Trace"

Provider                                 GUID
-------------------------------------------------------------------------------
Windows Kernel Trace                     {9E814AAD-3204-11D2-9A82-006008A86939}

Value               Keyword              Description
-------------------------------------------------------------------------------
0x0000000000000001  process              Process creations/deletions
0x0000000000000002  thread               Thread creations/deletions
0x0000000000000004  img                  Image load
0x0000000000000008  proccntr             Process counters
0x0000000000000010  cswitch              Context switches
0x0000000000000020  dpc                  Deferred procedure calls
0x0000000000000040  isr                  Interrupts
0x0000000000000080  syscall              System calls
0x0000000000000100  disk                 Disk IO
0x0000000000000200  file                 File details
0x0000000000000400  diskinit             Disk IO entry
0x0000000000000800  dispatcher           Dispatcher operations
0x0000000000001000  pf                   Page faults
0x0000000000002000  hf                   Hard page faults
0x0000000000004000  virtalloc            Virtual memory allocations
0x0000000000010000  net                  Network TCP/IP
0x0000000000020000  registry             Registry details
0x0000000000100000  alpc                 ALPC
0x0000000000200000  splitio              Split IO
0x0000000000800000  driver               Driver delays
0x0000000001000000  profile              Sample based profiling
0x0000000002000000  fileiocompletion     File IO completion
0x0000000004000000  fileio               File IO

//user provider
Microsoft-Windows-Kernel-IO              {ABF1F586-2E50-4BA8-928D-49044E6F0DB7}
Microsoft-Windows-Kernel-Memory          {D1D93EF7-E1F2-4F45-9943-03D245FE6C00}
Microsoft-Windows-Kernel-Network         {7DD42A49-5329-4832-8DFD-43D979153A88}
Microsoft-Windows-Kernel-Power           {331C3B3A-2005-44C2-AC5E-77220C37D6B4}
Microsoft-Windows-Kernel-Process         {22FB2CD6-0E7B-422B-A0C7-2FAD1FD0E716}
*/

//system memory
struct ETWTraceProvider {
    ULONG Register(
};
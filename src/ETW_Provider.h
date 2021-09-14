/*
* Desc: every provider has a GUID, there are 4 types of provider, MOF Providers, WPP Providers, manifest-based Providers(recommended) and TraceLogging Providers(recommended)
* APIs:
*/

#pragma once
#include "ETW_Utils.h"

//built-in provider 
#include "ETW/Microsoft_Windows_D3D9.h"
#include "ETW/Microsoft_Windows_Dwm_Core.h"
#include "ETW/Microsoft_Windows_DXGI.h"
#include "ETW/Microsoft_Windows_DxgKrnl.h"
#include "ETW/Microsoft_Windows_EventMetadata.h"
#include "ETW/Microsoft_Windows_Win32k.h"
#include "ETW/NT_Process.h"

//custom provider

struct ETWTraceProvider {
};
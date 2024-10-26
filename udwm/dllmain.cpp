// Copyright (c) 1985 - 2012 Microsoft Corporation. All rights reserved

#include "precomp.h"





// PURPOSE: Dll main entry point.
BOOL APIENTRY DllMain(HINSTANCE hInstance, DWORD fdwReason, LPVOID lpReserved){

    return 0;
}


// PURPOSE: DWM Client Startup
DWORD WINAPI DwmClientStartup(){
    HRESULT hResult1;
    CDesktopManager m_desktopManager;
    unsigned int m_Uint;
    HRESULT hResult2;

CDesktopManagerCriticalSection s_csDwmInstance;

EnterCriticalSection(s_csDwmInstance.m_cs);

m_Uint = hResult1;

}
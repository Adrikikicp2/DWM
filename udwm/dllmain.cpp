// Copyright (c) 1985 - 2012 Microsoft Corporation. All rights reserved

#include "precomp.h"


#define $S1 256



DWORD WINAPI DwmClientStartup();
// FUNCTION: DllMain
// PURPOSE: Dll main entry point.
BOOL WINAPI DllMain(HINSTANCE hinstDll, DWORD fdwReason, LPVOID lpvReserved){


DwmClientStartup();
    return TRUE;
}




// FUNCTION: DWMClientStartup
// PURPOSE: DWM Client Startup

DWORD WINAPI DwmClientStartup(){
      int dwmVersion;
    CDesktopManager *m_desktopManager;
    DWORD result;


  



if (($S1 - 1) == 0) {


       MILINSTRUMENTATIONHRESULTLIST[0] = 0x80070032; 
    MILINSTRUMENTATIONHRESULTLIST[1] = 0x88980701;
}

dwmVersion = DwmVersionCheck(0x88bde5e5);

if(-1 < dwmVersion){
    result = CDesktopManager::Create();
    if (-1 < (int)result){
    
        return result;
    }
}





return result;

}
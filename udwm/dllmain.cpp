// Copyright (c) 1985 - 2012 Microsoft Corporation. All rights reserved

#include "precomp.h"



int* m_pStack;

HRESULT* HRESULTERRORLIST;
DWORD* dwInstrument;


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
      HRESULT hResult1 = 0;
    CDesktopManager *m_desktopManager;
    unsigned int result;
    HRESULT hResult2;


  



if ((m_pStack - 1) == 0) {
       HRESULTERRORLIST[0] = -2147024846; 
        dwInstrument = (DWORD *) -2003302655; 
        m_pStack = (int *) 1u;
}





result = hResult1;

if(hResult1 < 0)
{
    
}else{
    hResult2 = CDesktopManager::Create();
}

return result;

}
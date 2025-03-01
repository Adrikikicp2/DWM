#include "DesktopManager.h"
#include "BaseObject.h"
#include "HeapBase.h"
#include "precomp.h"


HRESULT __fastcall CDesktopManager::Initialize(CDesktopManager *desktopManager, const STARTUPINFO *pStartupInfo){

return 0;
}



DWORD __fastcall CDesktopManager::Create(const StartupInfo* pStartupInfo, CompositionInfo*  pCompositionInfo){

char *allocChar = NULL;

HRESULT hResult = 0;
DWORD dwResult;
CDesktopManager * pdm;




s_pDesktopManagerInstance = (CDesktopManager *)allocChar;

EnterCriticalSection(&CDesktopManager::s_csDwmInstance.m_cs); // Critical section.
allocChar = (char *)WPF::g_pProcessHeap->AllocClear(WPF::g_pProcessHeap, 0x3D0);
if(allocChar){
    *((DWORD *)allocChar + 2) = 1;
    *((DWORD *)allocChar + 193) = -12542210;
    SystemParametersInfoW(0x1024u, 0, allocChar + 17, 0);
    dwResult = hResult;
    CDesktopManager::s_pDesktopManagerInstance = (CDesktopManager *)allocChar;
    if(hResult < 0){
  
    } else{
        MilInstrumentationChechHR(0x15u, MILINSTRUMENTATIONHRESULTLIST[0], 1u,hResult,0x3A3u);
        CBaseObject::Release(pdm);
    }
} else{
    dwResult = -2147024882;
    g_pdmInstance = pdm;
}

return dwResult;
}
#include "DesktopManager.h"
#include "BaseObject.h"
#include "precomp.h"


HRESULT __fastcall CDesktopManager::Initialize(CDesktopManager *desktopManager, const STARTUPINFO *pStartupInfo){

return 0;
}



DWORD __fastcall CDesktopManager::Create(){

char *allocChar = NULL;
CDesktopManager *desktopManager;
HRESULT hResult = 0;
DWORD dwResult;

const STARTUPINFO *pStartupInfo = NULL;


desktopManager = (CDesktopManager *)allocChar;
if(allocChar){
    *((DWORD *)allocChar + 2) = 1;
    *((DWORD *)allocChar + 193) = -12542210;
    SystemParametersInfoW(0x1024u, 0, allocChar + 17, 0);
    dwResult = hResult;
    if(hResult < 0){
  
    } else{

    }
} else{
    dwResult = -2147024882;
}

return dwResult;
}
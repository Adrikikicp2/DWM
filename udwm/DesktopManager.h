#ifndef C_DESKTOP_MANAGER
#define C_DESKTOP_MANAGER

#include "precomp.h"



class CDesktopManager
{

public:

static DWORD __fastcall Create();
HRESULT __fastcall Initialize(CDesktopManager *desktopManager, const STARTUPINFO *pStartupInfo);
};

#endif // C_DESKTOP_MANAGER

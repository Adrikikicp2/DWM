#ifndef C_DESKTOP_MANAGER
#define C_DESKTOP_MANAGER

#include "BaseObject.h"
#include "precomp.h"

class CDesktopManager : public CBaseObject  
{
public:
    static DWORD __fastcall Create();
    HRESULT __fastcall Initialize(CDesktopManager *desktopManager, const STARTUPINFO *pStartupInfo);
};

#endif // C_DESKTOP_MANAGER

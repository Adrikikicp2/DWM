#ifndef C_DESKTOP_MANAGER
#define C_DESKTOP_MANAGER

#include "BaseObject.h"
#include "precomp.h"

struct CDwmCS{
RTL_CRITICAL_SECTION m_cs;
};


class CDesktopManager : public CBaseObject  
{
public:
    static DWORD __fastcall Create(const StartupInfo* pStartupInfo, CompositionInfo*  pCompositionInfo);
    HRESULT __fastcall Initialize(CDesktopManager *desktopManager, const STARTUPINFO *pStartupInfo);
static CDwmCS s_csDwmInstance;
static CDesktopManager* s_pDesktopManagerInstance;

};

#endif // C_DESKTOP_MANAGER

#ifndef C_DESKTOP_MANAGER
#define C_DESKTOP_MANAGER

#include "precomp.h"

class CDesktopManagerCriticalSection{

    public:
    LPCRITICAL_SECTION m_cs;
};

class CDesktopManager
{

public:
CDesktopManagerCriticalSection s_csDwmInstance;
DWORD __fastcall CDesktopManager::Create();

};

#endif // C_DESKTOP_MANAGER

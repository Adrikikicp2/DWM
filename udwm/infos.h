#include "precomp.h"


struct StartupInfo{
    bool fIsRemoting;
    bool fIsBitmapRemoting;
    DWORD dwConnectionGeneration;
    DWORD dwMaxTextureWidth;
    DWORD dwMaxTextureHeight;
    bool fPowerStateReccommendsOpaqueBlend;
    HRESULT (__fastcall *pfnTriggeredInfoNotifier)(const MIL_MESSAGE*);
    IDwmSettingsManager *pSettingsManager;
};

struct CompositionInfo{
    HMIL_CONNECTIONMANAGER__ *hConnectionManager;
    HMILL_CONNECTION__ *hConnection;
    MIL_CHANNEL__ *hRedirectionStateChannel;
    bool fDesktopComposition;
};
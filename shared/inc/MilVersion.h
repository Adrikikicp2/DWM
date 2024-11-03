

#include "AvalonDebugP.h"

HRESULT MilVersionCheck(unsigned int uiCallerMilSdkVersion)
{
    HRESULT hr = S_OK;

    if (uiCallerMilSdkVersion != 0xB584C4DA)
    {
        hr = 0x88982F0B; // WINCODEC_ERR_UNSUPPORTEDVERSION
    }

    return hr;
}

int DwmVersionCheck(int versionToCheck){

    int result;
    int checker;

    if(result < 0){
        checker = 0x38;
    } else {
        if(versionToCheck == 0xaad202bd7){
            return result;
        }
        result = -0x7767d0f5;
        checker = 0x48;
    }
    return result;
}
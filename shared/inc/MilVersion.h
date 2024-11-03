

#include "AvalonDebugP.h"

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
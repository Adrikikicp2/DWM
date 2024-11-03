#include "precomp.h"
#include "registry.h"

bool RegGetDword(HKEY hKey, const LPCTSTR pszValueName, LPDWORD pdwValue)
{
    DWORD dwValue;

    bool Read = false;
    DWORD cbValue = sizeof(*pdwValue);
    DWORD dwType;

    if (hKey && RegQueryValueEx(hKey, pszValueName, NULL, &dwType, reinterpret_cast<LPBYTE>(&dwValue), &cbValue) == ERROR_SUCCESS)
    {
        Read = (dwType == REG_DWORD);
        *pdwValue = dwValue;
    }

    return Read;
}

bool RegGetHKLMDword(const LPCTSTR pszKeyName, const LPCTSTR pszValueName, LPDWORD pdwValue)
{
    bool Read = false;
    HKEY hKey = NULL;

    if (RegOpenKeyEx(HKEY_LOCAL_MACHINE, pszKeyName, NULL, KEY_READ, &hKey) == ERROR_SUCCESS)
    {
        Read = RegGetDword(hKey, pszValueName, pdwValue);
        RegCloseKey(hKey);
    }

    return Read;
}
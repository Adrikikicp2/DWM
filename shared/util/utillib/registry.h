#ifndef C_UTILLIB_REGISTRY
#define C_UTILLIB_REGISTRY

#include "precomp.h"

bool RegGetDword(const HKEY hKey, const LPCTSTR pszValueName, LPDWORD pdwValue);
bool RegGetHKLMDword(const LPCTSTR pszKeyName, const LPCTSTR pszValueName, LPDWORD pdwValue);

#endif
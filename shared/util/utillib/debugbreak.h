#ifndef C_UTILLIB_DEBUGBREAK
#define C_UTILLIB_DEBUGBREAK

#include "precomp.h"

void MilUnexpectedError(HRESULT hr, LPCTSTR pszContext);
void MilInstrumentationBreak(DWORD dwFlags, bool fDebugBreak);
void MilDisableInstrumentationBreaks();

#endif
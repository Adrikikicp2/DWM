#include "precomp.h"
#include "debugbreak.h"
#include "registry.h"

BOOL g_fDisableInstrumentationBreaks = false;

static bool BreakForInstrumentation()
{
    bool Result = false;

    if (g_fDisableInstrumentationBreaks)
    {
        return false;
    }

    DWORD dwOverride = 0;

    if (RegGetHKLMDword(TEXT("Software\\Microsoft\\Avalon.Graphics"), TEXT("DisableInstrumentationBreaking"), &dwOverride))
    {
        Result = (dwOverride == 0);
    }

    return Result;
}

static bool BreakOnUnexpectedErrors()
{
    bool Result = false;
    DWORD dwOverride = 0;

    if (RegGetHKLMDword(TEXT("Software\\Microsoft\\Avalon.Graphics"), TEXT("BreakOnUnexpectedErrors"), &dwOverride))
    {
        Result = (dwOverride != 0);
    }

    return Result;
}

void MilUnexpectedError(HRESULT hr, LPCTSTR pszContext)
{
    TCHAR szMessage[256];

    StringCchPrintf(szMessage, 256, TEXT("MIL FAILURE: Unexpected HRESULT 0x%08x in caller: %s"), hr, pszContext);

    DbgPrintEx(
        g_uDPFltrID,
        DPFLTR_ERROR_LEVEL,
        "%S\n",
        szMessage);

    if (BreakOnUnexpectedErrors())
    {
        Assert(L"This break is due to an unexpected HRESULT in the caller, not this method.\n"
            L"***   Investigate the stack capture to determine the source of the HRESULT.\n");
    }
}

void MilInstrumentationBreak(DWORD dwFlags, bool fDebugBreak)
{
    if (BreakForInstrumentation() && ((dwFlags & 8) == 0 || IsKernelDebuggerPresent() || !IsDebuggerPresent() && IsKernelDebuggerEnabled()))
    {
        if (fDebugBreak)
        {
            DebugBreak();
        }
        else
        {
            Assert(L"Unexpected HRESULT in MilInstrumentation* caller");
        }
    }
}

void MilDisableInstrumentationBreaks()
{
    g_fDisableInstrumentationBreaks = true;
}
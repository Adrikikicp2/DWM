#ifndef C_INC_AVALONDEBUGP
#define C_INC_AVALONDEBUGP

extern ULONG g_uDPFltrID;

BOOL IsKernelDebuggerEnabled();
BOOL IsKernelDebuggerPresent();

NTSYSAPI
ULONG
__cdecl
DbgPrintEx (
    __in ULONG ComponentId,
    __in ULONG Level,
    __in_z __drv_formatString(printf) PCSTR Format,
    ...
    );

VOID
AssertA(
    __in_opt PCSTR Message,
    __in_opt PCWSTR FailedAssertion,
    __in PCWSTR Function,
    __in PCWSTR FileName,
    ULONG LineNumber
    );

VOID
AssertW(
    __in_opt PCWSTR Message,
    __in_opt PCWSTR FailedAssertion,
    __in PCWSTR Function,
    __in PCWSTR FileName,
    ULONG LineNumber
    );

// Macros to widen a string macro
#define __WIDEN2(x) L ## x
#define __WIDEN(x)  __WIDEN2(x)

#define __WFILE__ __WIDEN(__FILE__)
#define __WFUNCTION__ __WIDEN(__FUNCTION__)

#define Assert(msg) (AssertW(msg, NULL, __WFUNCTION__, __WFILE__, __LINE__))

#endif
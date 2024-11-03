#include "precomp.h"

typedef struct _SYSTEM_KERNEL_DEBUGGER_INFORMATION {
    BOOLEAN KernelDebuggerEnabled;
    BOOLEAN KernelDebuggerNotPresent;
} SYSTEM_KERNEL_DEBUGGER_INFORMATION, *PSYSTEM_KERNEL_DEBUGGER_INFORMATION;

typedef enum _SYSTEM_INFORMATION_CLASS {
    SystemBasicInformation,
    SystemProcessorInformation,
    SystemPerformanceInformation,
    SystemTimeOfDayInformation,
    SystemPathInformation,
    SystemProcessInformation,
    SystemCallCountInformation,
    SystemDeviceInformation,
    SystemProcessorPerformanceInformation,
    SystemFlagsInformation,
    SystemCallTimeInformation,
    SystemModuleInformation,
    SystemLocksInformation,
    SystemStackTraceInformation,
    SystemPagedPoolInformation,
    SystemNonPagedPoolInformation,
    SystemHandleInformation,
    SystemObjectInformation,
    SystemPageFileInformation,
    SystemVdmInstemulInformation,
    SystemVdmBopInformation,
    SystemFileCacheInformation,
    SystemPoolTagInformation,
    SystemInterruptInformation,
    SystemDpcBehaviorInformation,
    SystemFullMemoryInformation,
    SystemLoadGdiDriverInformation,
    SystemUnloadGdiDriverInformation,
    SystemTimeAdjustmentInformation,
    SystemSummaryMemoryInformation,
    SystemMirrorMemoryInformation,
    SystemPerformanceTraceInformation,
    SystemObsolete0,
    SystemExceptionInformation,
    SystemCrashDumpStateInformation,
    SystemKernelDebuggerInformation,
    SystemContextSwitchInformation,
    SystemRegistryQuotaInformation,
    SystemExtendServiceTableInformation,
    SystemPrioritySeperation,
    SystemVerifierAddDriverInformation,
    SystemVerifierRemoveDriverInformation,
    SystemProcessorIdleInformation,
    SystemLegacyDriverInformation,
    SystemCurrentTimeZoneInformation,
    SystemLookasideInformation,
    SystemTimeSlipNotification,
    SystemSessionCreate,
    SystemSessionDetach,
    SystemSessionInformation,
    SystemRangeStartInformation,
    SystemVerifierInformation,
    SystemVerifierThunkExtend,
    SystemSessionProcessInformation,
    SystemLoadGdiDriverInSystemSpace,
    SystemNumaProcessorMap,
    SystemPrefetcherInformation,
    SystemExtendedProcessInformation,
    SystemRecommendedSharedDataAlignment,
    SystemComPlusPackage,
    SystemNumaAvailableMemory,
    SystemProcessorPowerInformation,
    SystemEmulationBasicInformation,
    SystemEmulationProcessorInformation,
    SystemExtendedHandleInformation,
    SystemLostDelayedWriteInformation,
    SystemBigPoolInformation,
    SystemSessionPoolTagInformation,
    SystemSessionMappedViewInformation,
    SystemHotpatchInformation,
    SystemObjectSecurityMode,
    SystemWatchdogTimerHandler,
    SystemWatchdogTimerInformation,
    SystemLogicalProcessorInformation,
    SystemWow64SharedInformationObsolete,
    SystemRegisterFirmwareTableInformationHandler,
    SystemFirmwareTableInformation,
    SystemModuleInformationEx,
    SystemVerifierTriageInformation,
    SystemSuperfetchInformation,
    SystemMemoryListInformation,
    SystemFileCacheInformationEx,
    SystemThreadPriorityClientIdInformation,
    SystemProcessorIdleCycleTimeInformation,
    SystemVerifierCancellationInformation,
    SystemProcessorPowerInformationEx,
    SystemRefTraceInformation,
    SystemSpecialPoolInformation,
    SystemProcessIdInformation,
    SystemErrorPortInformation,
    SystemBootEnvironmentInformation,
    SystemHypervisorInformation,
    SystemVerifierInformationEx,
    SystemTimeZoneInformation,
    SystemImageFileExecutionOptionsInformation,
    SystemCoverageInformation,
    SystemPrefetchPatchInformation,
    SystemVerifierFaultsInformation,
    SystemSystemPartitionInformation,
    SystemSystemDiskInformation,
    SystemProcessorPerformanceDistribution,
    SystemNumaProximityNodeInformation,
    SystemDynamicTimeZoneInformation,
    SystemCodeIntegrityInformation,
    SystemProcessorMicrocodeUpdateInformation,
    SystemProcessorBrandString,
    SystemVirtualAddressInformation,
    SystemLogicalProcessorAndGroupInformation,
    SystemProcessorCycleTimeInformation,
    SystemStoreInformation,
    SystemRegistryAppendString,
    SystemAitSamplingValue,
    SystemVhdBootInformation,
    SystemCpuQuotaInformation,
    SystemSpare0,
    SystemSpare1,
    SystemLowPriorityIoInformation,
    SystemTpmBootEntropyInformation,
    SystemVerifierCountersInformation,
    SystemPagedPoolInformationEx,
    SystemSystemPtesInformationEx,
    SystemNodeDistanceInformation,
    SystemAcpiAuditInformation,
    SystemBasicPerformanceInformation,
    SystemSessionBigPoolInformation,
    SystemBootGraphicsInformation,
    SystemScrubPhysicalMemoryInformation,
    SystemBadPageInformation,
    MaxSystemInfoClass,
} SYSTEM_INFORMATION_CLASS;

#define NTSTATUS LONG

#ifdef __cplusplus
extern "C" {
#endif

__kernel_entry
NTSYSCALLAPI
NTSTATUS
NTAPI
NtQuerySystemInformation (
    __in SYSTEM_INFORMATION_CLASS SystemInformationClass,
    __out_bcount_part_opt(SystemInformationLength, *ReturnLength) PVOID SystemInformation,
    __in ULONG SystemInformationLength,
    __out_opt PULONG ReturnLength
    );

// copied from ntstatus.h

#define NT_SUCCESS(Status) ((NTSTATUS)(Status) >= 0)

#define STATUS_UNSUCCESSFUL              ((NTSTATUS)0xC0000001L)

// copied from wdm.h

__analysis_noreturn
VOID
NTAPI
DbgBreakPoint(
    VOID
    );
    
// copied from ntddk.h

NTSYSAPI
ULONG
NTAPI
DbgPrompt (
    __in_z PCCH Prompt,
    __out_bcount(Length) PCH Response,
    __in ULONG Length
    );

#ifdef __cplusplus
}
#endif

ULONG g_uDPFltrID = DPFLTR_DEFAULT_ID;

BOOL IsKernelDebuggerEnabled()
{
    static bool fSuccessfullyQueried = false;
    static SYSTEM_KERNEL_DEBUGGER_INFORMATION kdInfo = {FALSE};

    if (!fSuccessfullyQueried)
    {
        if (NT_SUCCESS(NtQuerySystemInformation(SystemKernelDebuggerInformation, &kdInfo, sizeof(kdInfo), NULL)))
        {
            fSuccessfullyQueried = true;
        }
    }

    return kdInfo.KernelDebuggerEnabled;
}

BOOL IsKernelDebuggerPresent()
{
    static bool fSuccessfullyQueried = false;
    static SYSTEM_KERNEL_DEBUGGER_INFORMATION kdInfo = {TRUE, TRUE};

    if (kdInfo.KernelDebuggerEnabled && kdInfo.KernelDebuggerNotPresent)
    {
        if (!NT_SUCCESS(NtQuerySystemInformation(SystemKernelDebuggerInformation, &kdInfo, sizeof(kdInfo), NULL)))
        {
            kdInfo.KernelDebuggerEnabled = TRUE;
            kdInfo.KernelDebuggerNotPresent = TRUE;
        }
    }

    return kdInfo.KernelDebuggerEnabled && !kdInfo.KernelDebuggerNotPresent;
}

// TODO: add support for ignoring asserts
VOID AssertW(PCWSTR Message, PCWSTR FailedAssertion, PCWSTR Function, PCWSTR FileName, ULONG LineNumber)
{
    PSTR DebuggerPrompt = "Break, Go (continue), terminate Process, or terminate Thread (bgpt)? ";

Prompt:
    const BOOL KernelDebuggerPresent = IsKernelDebuggerPresent();

    char Response[2] = {'?', 0};

    if (!KernelDebuggerPresent && IsDebuggerPresent())
    {
        Response[0] = 'g';
    }

    DbgPrintEx(
        g_uDPFltrID,
        DPFLTR_ERROR_LEVEL,
        "\n*** Assertion failed: %ls%ls%ls\n***   %s%ls%sSource: `%ls:%ld`\n\n",
        Message ? Message : L"",
        (Message && FailedAssertion) ? L"\n***  " : L"",
        FailedAssertion ? FailedAssertion : L"",
        Function ? "Function: " : "",
        Function ?  Function    : L"",
        Function ? ", "         : "",
        FileName,
        LineNumber);

    if (KernelDebuggerPresent)
    {
        DbgPrompt(DebuggerPrompt, Response, sizeof(Response));
    }
    else
    {
        DbgPrintEx(
            g_uDPFltrID,
            DPFLTR_ERROR_LEVEL,
            "(No kernel debugger is present.) Respond with:\n"
            "  g                    -- Go (continue)\n"
            "  eb 0x%p 'p';g  -- terminate Process\n"
            "  eb 0x%p 't';g  -- terminate Thread\n"
            " or regular debugging.\n",
            &Response[0],
            &Response[0]
            );

        DbgBreakPoint();
    }

    switch (Response[0])
    {
    case 'B':
    case 'b':
        DbgBreakPoint();
        return;
    case 'G':
    case 'g':
        return;
    case 'P':
    case 'p':
        TerminateProcess(GetCurrentProcess(), (DWORD)STATUS_UNSUCCESSFUL);
        break;
    case 'T':
    case 't':
        TerminateThread(GetCurrentThread(), (DWORD)STATUS_UNSUCCESSFUL);
        break;
    }

    DbgPrintEx(g_uDPFltrID, DPFLTR_ERROR_LEVEL, "Unrecognized response.\n");

    goto Prompt;
}
#ifndef C_PROCESS_HEAP
#define C_PROCESS_HEAP

#include "HeapBase.h"
#include "precomp.h"

extern HANDLE g_hProcessHeap;

namespace WPF
{
    class ProcessHeapImpl : public HeapBase
    {
    public:
        void* Alloc(size_t cbSize);
        void* AllocClear(size_t cbSize);
        HRESULT Realloc(void** ppv, size_t cbSize);
        void Free(void* pv);
    };
}

#endif
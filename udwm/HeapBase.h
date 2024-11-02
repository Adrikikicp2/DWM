#ifndef C_HEAP_BASE
#define C_HEAP_BASE

#include "precomp.h"

namespace WPF
{
    class ProcessHeapImpl;
    extern ProcessHeapImpl * g_pProcessHeap;

    class HeapBase
    {
    public:
        virtual ~HeapBase() {};
        
        virtual void* Alloc(size_t cbSize) = 0;
        virtual void* AllocClear(size_t cbSize) = 0;
        virtual HRESULT Realloc(void** ppv, size_t cbSize) = 0;
        virtual void Free(void* pv) = 0;
    };

    void Alloc(size_t cbSize);
}

#endif
#ifndef C_HEAP_BASE
#define C_HEAP_BASE

#include "precomp.h"

namespace WPF
{
    class HeapBase
    {
        virtual ~HeapBase() = default;
        virtual void* Alloc(size_t cbSize) = 0;
        virtual void* AllocClear(size_t cbSize) = 0;
        virtual HRESULT Realloc(void** ppv, size_t cbSize) = 0;
        virtual void Free(void* pv) = 0;
    };
}

#endif
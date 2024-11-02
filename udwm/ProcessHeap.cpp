#include "precomp.h"
#include "ProcessHeap.h"

HANDLE g_hProcessHeap = GetProcessHeap();

namespace WPF
{
    ProcessHeapImpl* g_pProcessHeap = new ProcessHeapImpl();

    void* ProcessHeapImpl::Alloc(size_t cbSize)
    {
        // Minimum we can allocate is 1 byte.
        if (cbSize == 0)
            cbSize = 1;
        
        return HeapAlloc(g_hProcessHeap, 0, cbSize);
    }

    void* ProcessHeapImpl::AllocClear(size_t cbSize)
    {
        // Minimum we can allocate is 1 byte.
        if (cbSize == 0)
            cbSize = 1;

        void* result = HeapAlloc(g_hProcessHeap, 0, cbSize);
        if (result)
        {
            memset(result, 0, cbSize);
            return result;
        }

        return NULL;
    }

    HRESULT ProcessHeapImpl::Realloc(void** ppv, size_t cbSize)
    {
        void* ptr = NULL;

        if (*ppv)
        {
            ptr = HeapReAlloc(g_hProcessHeap, 0, *ppv, cbSize);
            if (ptr)
            {
                *ppv = ptr;
                return S_OK;
            }
        }
        else
        {
            // Minimum we can allocate is 1 byte.
            if (cbSize == 0)
                cbSize = 1;

            ptr = HeapAlloc(g_hProcessHeap, 0, cbSize);
            *ppv = ptr;
            if (ptr)
                return S_OK;
        }
        return E_OUTOFMEMORY;
    }

    void ProcessHeapImpl::Free(void* pv)
    {
        if (pv)
            HeapFree(g_hProcessHeap, 0, pv);
    }
}
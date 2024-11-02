#include "precomp.h"
#include "HeapBase.h"
#include "ProcessHeap.h"

void* WPF::Alloc(size_t cbSize)
{
    return WPF::g_pProcessHeap->Alloc(cbSize);
}

void* WPF::AllocClear(size_t cbSize)
{
    return WPF::g_pProcessHeap->AllocClear(cbSize);
}
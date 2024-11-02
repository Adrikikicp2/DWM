#include "precomp.h"
#include "BaseObject.h"
#include "ProcessHeap.h"

void* CBaseObject::operator new(size_t cbSize)
{
    return WPF::Alloc(cbSize);
}

void CBaseObject::operator delete(void* ptr)
{
    return WPF::g_pProcessHeap->Free(ptr);
}

size_t CBaseObject::AddRef() {
    return InterlockedIncrement((DWORD*)&m_cRef);
}

size_t CBaseObject::Release() {
    InterlockedDecrement((DWORD*)&m_cRef);
    if (m_cRef < 1)
        delete this;
    return m_cRef;
}
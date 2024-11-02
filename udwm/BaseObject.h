#ifndef C_BASE_OBJECT
#define C_BASE_OBJECT

#include "precomp.h"

class CBaseObject  
{
public:
    virtual ~CBaseObject();

    void* operator new(size_t size);
    void operator delete(void* ptr);
    
    size_t __fastcall AddRef();
    size_t __fastcall Release();
private:
    int m_cRef;
};

#endif // C_BASE_OBJECT

//*-----------------------------------------------
//
//  FILE: DynCast.h
//  
//  PURPOSE: Dynamic casts
//
//  CREATED: Nov-2-24
//
//  AUTHORS: adrikikicp, brwinner
//
//*----------------------------------------------

// Originally licensed to the .NET Foundation for Avalon (Windows Presentation Foundation)


#pragma once

#if !defined(_PREFAST_) && (!DBG || defined(NO_RTTI))

#define DYNCAST(Dest_type, Source_Value) (static_cast<Dest_type*>(Source_Value))

#else // PREfast || DBG

#if defined(_PREFAST_) || defined(NO_RTTI)

template <class TS, class TD>
__success(source != NULL) __out_ecount(1) TD * DYNCAST_IMPL(__in_ecount_opt(1) TS * source, __in_opt TD &, __in PCSTR pszType)
{
    return static_cast <TD *> (source);
}

#else // !PREfast && RTTI

//*---------------------------------------------------
//
//  The DYNCAST MACRO
//
//  It is used to cast objects from a cast type to another. 
//  Example:
//
//  CBodyElement *pBody = DYNCAST(CBodyElement, _pElement);
//
//*---------------------------------------------------

#define ARRAY_COMMA_ELEM_COUNT(A) ((A)), ARRAYSIZE((A))
#define ARRAY_COMMA_BYTE_COUNT(A) ((A)), sizeof((A))

// ARRAY_COMMA_ECOUNT


#pragma warning(push)
#include <typeinfo>
#pragma warning(pop)


// Include strsafe.h as it provides various print functions.

#include <strsafe.h>

template <class TS, class TD>
__success(source != NULL) __out_ecount(1) TD * DYNCAST_IMPL(__in_ecount_opt(1) TS * source, __in_opt TD &, __in PCSTR pszType)
{
    if (!source) return NULL;

    char achDynCastMsg[256];

    TD * dest  = dynamic_cast <TD *> (source);
    TD * dest2 = static_cast <TD *> (source);
    if (!dest)
    {
        StringCchPrintfA(ARRAY_COMMA_ELEM_COUNT(achDynCastMsg),
                         "Invalid Static Cast -- Attempt to cast object "
                         "of type %s to type %s.",
                         typeid(*source).name(), pszType);
        AssertMsgA(FALSE, achDynCastMsg);
    }
    else if (dest != dest2)
    {
        StringCchPrintfA(ARRAY_COMMA_ELEM_COUNT(achDynCastMsg),
                         "Dynamic Cast Attempted ---  "
                         "Attempt to cast between two base classes of %s. "
                         "The cast was to class %s from some other base class "
                         "pointer. This cast will not succeed in a retail build.",
                         typeid(*source).name(), pszType);
        AssertMsgA(FALSE, achDynCastMsg);
    }

    return dest2;
}

#endif // PREfast || NO_RTTI

#define DYNCAST(Dest_type, Source_value) \
    DYNCAST_IMPL(Source_value,(Dest_type &)*(Dest_type*)NULL, #Dest_type)

#endif // PREfast || DBG
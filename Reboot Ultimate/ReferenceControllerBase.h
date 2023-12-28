#pragma once

#include "inc.h"

class FReferenceControllerBase
{
public:
    FORCEINLINE explicit FReferenceControllerBase()
        : SharedReferenceCount(1)
        , WeakReferenceCount(1)
    {
    }

    int32 SharedReferenceCount;
    int32 WeakReferenceCount;
};
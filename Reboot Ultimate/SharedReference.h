#pragma once

#include "SharedPointerInternals.h"

template< class ObjectType, ESPMode Mode >
class TSharedRef
{
public:
    ObjectType* Object;
    FSharedReferencer<Mode> SharedReferenceCount;
};

template< ESPMode Mode >
class FSharedReferencer
{
public:
    FReferenceControllerBase* ReferenceController;
};
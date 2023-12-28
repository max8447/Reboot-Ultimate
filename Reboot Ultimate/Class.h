#pragma once

#include "Object.h"

#include "addresses.h"
#include "String.h"
#include "Map.h"
#include "Name.h"
#include "Field.h"
#include "Struct.h"

template <typename PropertyType = void>
static inline PropertyType* GetNext(void* Field)
{
	return Fortnite_Version >= 12.10 ? *(PropertyType**)(__int64(Field) + 0x20) : ((UField*)Field)->Next;
}

static inline FName* GetFNameOfProp(void* Property)
{
	FName* NamePrivate = nullptr;

	if (Fortnite_Version >= 12.10)
		NamePrivate = (FName*)(__int64(Property) + 0x28);
	else
		NamePrivate = &((UField*)Property)->NamePrivate;

	return NamePrivate;
}

class UClass : public UStruct
{
public:
	UObject* CreateDefaultObject();
};
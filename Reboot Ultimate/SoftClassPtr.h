#pragma once

#include "SoftObjectPtr.h"

template<typename UEType>
class TSoftClassPtr : public FSoftObjectPtr
{
public:

	UEType* Get()
	{
		return FindObject<UEType>(ObjectID.AssetPathName.ToString());
	}

	UEType* operator->() const
	{
		return static_cast<UEType*>(TPersistentObjectPtr::Get());
	}
};
#pragma once

#include "Object.h"
#include "WeakObjectPtrTemplates.h"

struct FNetGUIDCache
{
	bool SupportsObject(const UObject* Object, const TWeakObjectPtr<UObject>* WeakObjectPtr = nullptr) const
	{
		// 1.11
		bool (*SupportsObjectOriginal)(__int64, const UObject*, const TWeakObjectPtr<UObject>*) = decltype(SupportsObjectOriginal)(__int64(GetModuleHandleW(0)) + 0x1AF01E0);
		return SupportsObjectOriginal(__int64(this), Object, WeakObjectPtr);
	}
};
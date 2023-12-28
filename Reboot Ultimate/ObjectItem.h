#pragma once

#include "inc.h"

#include "Object.h"
#include "ObjectMacros.h"
#include "FixedObjectArray.h"
#include "ChunkedFixedObjectArray.h"

struct FUObjectItem
{
	UObject* Object;
	int32 Flags;
	int32 ClusterRootIndex;
	int32 SerialNumber;

	FORCEINLINE bool IsPendingKill() const
	{
		return !!(Flags & int32(EInternalObjectFlags::PendingKill));
	}

	FORCEINLINE void SetFlag(EInternalObjectFlags FlagToSet)
	{
		// static_assert(sizeof(int32) == sizeof(Flags), "Flags must be 32-bit for atomics.");
		int32 StartValue = int32(Flags);

		if ((StartValue & int32(FlagToSet)) == int32(FlagToSet))
		{
			return;
		}

		int32 NewValue = StartValue | int32(FlagToSet);
	}

	FORCEINLINE void SetRootSet()
	{
		SetFlag(EInternalObjectFlags::RootSet);
	}
};

extern inline int NumElementsPerChunk = 0x10000;

extern inline FChunkedFixedUObjectArray* ChunkedObjects = 0;
extern inline FFixedUObjectArray* UnchunkedObjects = 0;

FORCEINLINE UObject* GetObjectByIndex(int32 Index)
{
	return ChunkedObjects ? ChunkedObjects->GetObjectByIndex(Index) : UnchunkedObjects ? UnchunkedObjects->GetObjectByIndex(Index) : nullptr;
}

FORCEINLINE FUObjectItem* GetItemByIndex(int32 Index)
{
	return ChunkedObjects ? ChunkedObjects->GetItemByIndex(Index) : UnchunkedObjects ? UnchunkedObjects->GetItemByIndex(Index) : nullptr;
}
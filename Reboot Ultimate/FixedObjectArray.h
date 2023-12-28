#pragma once

class FFixedUObjectArray
{
	FUObjectItem* Objects;
	int32 MaxElements;
	int32 NumElements;
public:
	FORCEINLINE int32 Num() const { return NumElements; }
	FORCEINLINE int32 Capacity() const { return MaxElements; }
	FORCEINLINE bool IsValidIndex(int32 Index) const { return Index < Num() && Index >= 0; }

	FORCEINLINE FUObjectItem* GetItemByIndex(int32 Index)
	{
		if (!IsValidIndex(Index)) return nullptr;
		return &Objects[Index];
	}

	bool IsValid(UObject* Object)
	{
		int32 Index = Object->InternalIndex;
		if (Index == -1)
		{
			// UE_LOG(LogUObjectArray, Warning, TEXT("Object is not in global object array"));
			return false;
		}
		if (!IsValidIndex(Index))
		{
			// UE_LOG(LogUObjectArray, Warning, TEXT("Invalid object index %i"), Index);
			return false;
		}

		FUObjectItem* Slot = GetItemByIndex(Index);
		if (!Slot || Slot->Object == nullptr)
		{
			// UE_LOG(LogUObjectArray, Warning, TEXT("Empty slot"));
			return false;
		}
		if (Slot->Object != Object)
		{
			// UE_LOG(LogUObjectArray, Warning, TEXT("Other object in slot"));
			return false;
		}
		return true;
	}

	FORCEINLINE UObject* GetObjectByIndex(int32 Index)
	{
		if (auto Item = GetItemByIndex(Index))
			return Item->Object;

		return nullptr;
	}
};
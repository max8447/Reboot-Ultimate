#pragma once

#include "FortItem.h"
#include "Object.h"
#include "Class.h"
#include "Text.h"

#include "reboot.h"

class UFortItemDefinition : public UObject
{
public:
	UFortItem* CreateTemporaryItemInstanceBP(int Count, int Level = 1); // Should Level be 20?
	float GetMaxStackSize();

	bool DoesAllowMultipleStacks()
	{
		static auto bAllowMultipleStacksOffset = GetOffset("bAllowMultipleStacks");
		static auto bAllowMultipleStacksFieldMask = GetFieldMask(GetProperty("bAllowMultipleStacks"));
		return ReadBitfieldValue(bAllowMultipleStacksOffset, bAllowMultipleStacksFieldMask);
	}

	FText GetSingleLineDescription()
	{
		static auto fn = FindObject<UFunction>("/Script/FortniteGame.FortItemDefinition.GetSingleLineDescription");

		FText ReturnValue;
		
		this->ProcessEvent(fn, &ReturnValue);

		return ReturnValue;
	}

	FText GetShortDescription()
	{
		static auto fn = FindObject<UFunction>("/Script/FortniteGame.FortItemDefinition.GetShortDescription");

		FText ReturnValue;

		this->ProcessEvent(fn, &ReturnValue);

		return ReturnValue;
	}

	static UClass* StaticClass()
	{
		static auto Class = FindObject<UClass>(L"/Script/FortniteGame.FortItemDefinition");
		return Class;
	}
};

struct FItemAndCount
{
private:
	int                                                Count;                                                    // 0x0000(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	unsigned char                                      UnknownData00[0x4];                                       // 0x0004(0x0004) MISSED OFFSET
	UFortItemDefinition* Item;                                                     // 0x0008(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
public:
	int& GetCount()
	{
		return Count;
	}

	UFortItemDefinition*& GetItem()
	{
		return Item;
	}
};
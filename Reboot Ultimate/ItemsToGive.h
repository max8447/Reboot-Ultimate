#pragma once

#include "Struct.h"
#include "reboot.h"
#include "FortWorldItemDefinition.h"
#include "ScalableFloat.h"

struct FItemsToGive
{
	static UStruct* GetStruct()
	{
		static auto Struct = FindObject<UStruct>("/Script/FortniteGame.ItemsToGive");
		return Struct;
	}

	static int GetStructSize() { return GetStruct()->GetPropertiesSize(); }

	UFortWorldItemDefinition*& GetItemToDrop()
	{
		static auto ItemToDropOffset = FindOffsetStruct("/Script/FortniteGame.ItemsToGive", "ItemToDrop");
		return *(UFortWorldItemDefinition**)(__int64(this) + ItemToDropOffset);
	}

	FScalableFloat& GetNumberToGive()
	{
		static auto NumberToGiveOffset = FindOffsetStruct("/Script/FortniteGame.ItemsToGive", "NumberToGive");
		return *(FScalableFloat*)(__int64(this) + NumberToGiveOffset);
	}
};
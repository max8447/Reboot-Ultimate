#pragma once

#include "Struct.h"
#include "FortWorldItemDefinition.h"
#include "reboot.h"
#include "ScalableFloat.h"

struct FActiveItemGrantInfo
{
	static UStruct* GetStruct()
	{
		static auto Struct = FindObject<UStruct>("/Script/FortniteGame.ActiveItemGrantInfo");
		return Struct;
	}

	static int GetStructSize() { return GetStruct()->GetPropertiesSize(); }

	UFortWorldItemDefinition*& GetItem()
	{
		static auto ItemOffset = FindOffsetStruct("/Script/FortniteGame.ActiveItemGrantInfo", "Item");
		return *(UFortWorldItemDefinition**)(__int64(this) + ItemOffset);
	}

	FScalableFloat& GetAmountToGive()
	{
		static auto AmountToGiveOffset = FindOffsetStruct("/Script/FortniteGame.ActiveItemGrantInfo", "AmountToGive");
		return *(FScalableFloat*)(__int64(this) + AmountToGiveOffset);
	}

	FScalableFloat& GetMaxAmount()
	{
		static auto MaxAmountOffset = FindOffsetStruct("/Script/FortniteGame.ActiveItemGrantInfo", "MaxAmount");
		return *(FScalableFloat*)(__int64(this) + MaxAmountOffset);
	}
};
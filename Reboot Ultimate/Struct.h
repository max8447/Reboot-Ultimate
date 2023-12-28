#pragma once

#include "Field.h"
#include "addresses.h"
#include "Array.h"

class UStruct : public UField
{
public:
	int GetPropertiesSize();

	UStruct* GetSuperStruct() { return *(UStruct**)(__int64(this) + Offsets::SuperStruct); } // idk if this is in UStruct

	TArray<uint8_t> GetScript() { return *(TArray<uint8_t>*)(__int64(this) + Offsets::Script); }
};
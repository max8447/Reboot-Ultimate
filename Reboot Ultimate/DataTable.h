#pragma once

#include "Object.h"
#include "reboot.h"

#include "Map.h"

class UDataTable : public UObject
{
public:
	template <typename RowDataType = uint8_t>
	TMap<FName, RowDataType*>& GetRowMap()
	{
		static auto RowStructOffset = FindOffsetStruct("/Script/Engine.DataTable", "RowStruct");

		return *(TMap<FName, RowDataType*>*)(__int64(this) + (RowStructOffset + sizeof(UObject*))); // because after rowstruct is rowmap
	}

	static UClass* StaticClass()
	{
		static auto Class = FindObject<UClass>(L"/Script/Engine.DataTable");
		return Class;
	}
};

template <typename StructType = uint8>
struct RowNameAndRowData
{
	FName RowName;
	StructType* RowData;
};
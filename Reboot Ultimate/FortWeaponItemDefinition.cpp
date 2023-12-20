#include "FortWeaponItemDefinition.h"

#include "DataTable.h"
#include "SoftObjectPtr.h"

int& UFortWeaponItemDefinition::GetClipSize()
{
	static int INVALID_RET = 0;

	static auto WeaponStatHandleOffset = GetOffset("WeaponStatHandle");
	auto& WeaponStatHandle = Get<FDataTableRowHandle>(WeaponStatHandleOffset);

	auto Table = WeaponStatHandle.DataTable;

	if (!Table)
		return INVALID_RET;

	auto& RowMap = Table->GetRowMap();

	void* Row = nullptr;

	for (int i = 0; i < RowMap.Pairs.Elements.Data.Num(); ++i)
	{
		auto& Pair = RowMap.Pairs.Elements.Data.at(i).ElementData.Value;

		if (Pair.Key() == WeaponStatHandle.RowName)
		{
			Row = Pair.Value();
			break;
		}
	}

	if (!Row)
		return INVALID_RET;

	static auto ClipSizeOffset = FindOffsetStruct("/Script/FortniteGame.FortBaseWeaponStats", "ClipSize");
	return *(int*)(__int64(Row) + ClipSizeOffset);
}

float& UFortWeaponItemDefinition::GetSpread()
{
	static float INVALID_RET = 0.f;

	static auto WeaponStatHandleOffset = GetOffset("WeaponStatHandle");
	auto& WeaponStatHandle = Get<FDataTableRowHandle>(WeaponStatHandleOffset);

	auto Table = WeaponStatHandle.DataTable;

	if (!Table)
		return INVALID_RET;

	auto& RowMap = Table->GetRowMap();

	void* Row = nullptr;

	for (int i = 0; i < RowMap.Pairs.Elements.Data.Num(); ++i)
	{
		auto& Pair = RowMap.Pairs.Elements.Data.at(i).ElementData.Value;

		if (Pair.Key() == WeaponStatHandle.RowName)
		{
			Row = Pair.Value();
			break;
		}
	}

	if (!Row)
		return INVALID_RET;

	static auto SpreadOffset = FindOffsetStruct("/Script/FortniteGame.FortRangedWeaponStats", "Spread");
	return *(float*)(__int64(Row) + SpreadOffset);
}

TArray<int>& UFortWeaponItemDefinition::GetDamage()
{
	static TArray<int> INVALID_RET;

	static auto WeaponStatHandleOffset = GetOffset("WeaponStatHandle");
	auto& WeaponStatHandle = Get<FDataTableRowHandle>(WeaponStatHandleOffset);

	auto Table = WeaponStatHandle.DataTable;

	if (!Table)
		return INVALID_RET;

	auto& RowMap = Table->GetRowMap();

	void* Row = nullptr;

	for (int i = 0; i < RowMap.Pairs.Elements.Data.Num(); ++i)
	{
		auto& Pair = RowMap.Pairs.Elements.Data.at(i).ElementData.Value;

		if (Pair.Key() == WeaponStatHandle.RowName)
		{
			Row = Pair.Value();
			break;
		}
	}

	if (!Row)
		return INVALID_RET;

	TArray<int> DamageArray;

	static auto DmgMaxRangeOffset = FindOffsetStruct("/Script/FortniteGame.FortBaseWeaponStats", "DmgMaxRange");
	static auto DmgLongOffset = FindOffsetStruct("/Script/FortniteGame.FortBaseWeaponStats", "DmgLong");
	static auto DmgMidOffset = FindOffsetStruct("/Script/FortniteGame.FortBaseWeaponStats", "DmgMid");
	static auto DmgPBOffset = FindOffsetStruct("/Script/FortniteGame.FortBaseWeaponStats", "DmgPB");

	int DmgPB = *(int*)(__int64(Row) + DmgPBOffset);
	int DmgMid = *(int*)(__int64(Row) + DmgMidOffset);
	int DmgLong = *(int*)(__int64(Row) + DmgLongOffset);
	int DmgMaxRange = *(int*)(__int64(Row) + DmgMaxRangeOffset);

	DamageArray.Add(DmgPB);
	DamageArray.Add(DmgMid);
	DamageArray.Add(DmgLong);
	DamageArray.Add(DmgMaxRange);

	return DamageArray;
}

EFortRarity& UFortWeaponItemDefinition::GetRarity()
{
	static auto RarityOffset = FindOffsetStruct("/Script/FortniteGame.FortItemDefinition", "Rarity");
	return *(EFortRarity*)(__int64(this) + RarityOffset);
}

EFortItemTier& UFortWeaponItemDefinition::GetTier()
{
	static auto RarityOffset = FindOffsetStruct("/Script/FortniteGame.FortItemDefinition", "Tier");
	return *(EFortItemTier*)(__int64(this) + RarityOffset);
}

UFortWorldItemDefinition* UFortWeaponItemDefinition::GetAmmoData()
{
	static auto AmmoDataOffset = GetOffset("AmmoData");
	auto AmmoData = GetPtr<TSoftObjectPtr<UFortWorldItemDefinition>>(AmmoDataOffset);
	return AmmoData->Get();
}

UClass* UFortWeaponItemDefinition::StaticClass()
{
	static auto Class = FindObject<UClass>(L"/Script/FortniteGame.FortWeaponItemDefinition");
	return Class;
}
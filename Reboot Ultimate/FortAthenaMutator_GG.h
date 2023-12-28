// Gun Game

#pragma once

#include "Actor.h"
#include "CurveTable.h"
#include "FortWeaponItemDefinition.h"
#include "FortPlayerStateAthena.h"
#include "FortAthenaMutator.h"
#include "GunGameEntry.h"

class AFortAthenaMutator_GG : public AFortAthenaMutator
{
public:
	int32 GetScoreToWin()
	{
		static auto ScoreToWinOffset = GetOffset("ScoreToWin");
		return Get<int32>(ScoreToWinOffset);
	}

	TArray<FGunGameGunEntry>& GetWeaponEntries()
	{
		static auto WeaponEntriesOffset = GetOffset("WeaponEntries");
		return Get<TArray<FGunGameGunEntry>>(WeaponEntriesOffset);
	}

	TMap<int, FGunGameGunEntries>& GetAwardEntriesAtElimMap()
	{
		static auto AwardEntriesAtElimMapOffset = GetOffset("AwardEntriesAtElimMap");
		return Get<TMap<int, FGunGameGunEntries>>(AwardEntriesAtElimMapOffset);
	}

	TMap<AFortPlayerStateAthena*, FGunGamePlayerData>& GetPlayerData()
	{
		static auto PlayerDataOffset = GetOffset("PlayerData");
		return Get<TMap<AFortPlayerStateAthena*, FGunGamePlayerData>>(PlayerDataOffset);
	}

	FGunGameGunEntries GetEntriesFromAward(const FScalableFloat& AwardAtElim)
	{
		auto& AwardEntriesAtElimMap = GetAwardEntriesAtElimMap();

		float Value = 0; // TODO Get from AwardAtElim

		for (auto& AwardEntry : AwardEntriesAtElimMap)
		{
			if (AwardEntry.First == Value)
			{
				return AwardEntry.Second;
			}
		}
	}

	static UClass* StaticClass()
	{
		static auto Class = FindObject<UClass>("/Script/FortniteGame.FortAthenaMutator_GG");
		return Class;
	}
};
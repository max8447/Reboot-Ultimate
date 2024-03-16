#pragma once

#include "reboot.h"
#include "FortAthenaAIBotCharacterCustomization.h"
#include "TSubClassOf.h"
#include "bots.h"
#include "BehaviorTree.h"
#include "FortBotNameSettings.h"
#include "FortAthenaAIBotInventoryItems.h"

class UFortAthenaAIBotCustomizationData : public UObject // UPrimaryDataAsset
{
public:
	UFortAthenaAIBotCharacterCustomization*& GetCharacterCustomization()
	{
		static auto CharacterCustomizationOffset = GetOffset("CharacterCustomization");
		return Get<UFortAthenaAIBotCharacterCustomization*>(CharacterCustomizationOffset);
	}

	TSubclassOf<AFortPlayerPawnAthena> GetPawnClass()
	{
		static auto PawnClassOffset = GetOffset("PawnClass");
		return Get<TSubclassOf<AFortPlayerPawnAthena>>(PawnClassOffset);
	}

	UBehaviorTree* GetBehaviorTree()
	{
		static auto BehaviorTreeOffset = GetOffset("BehaviorTree");
		return Get<UBehaviorTree*>(BehaviorTreeOffset);
	}

	UFortBotNameSettings* GetBotNameSettings()
	{
		static auto BotNameSettingsOffset = GetOffset("BotNameSettings");
		return Get<UFortBotNameSettings*>(BotNameSettingsOffset);
	}

	UFortAthenaAIBotInventoryItems* GetStartupInventory()
	{
		static auto StartupInventoryOffset = GetOffset("StartupInventory");
		return Get<UFortAthenaAIBotInventoryItems*>(StartupInventoryOffset);
	}

	static void ApplyOverrideCharacterCustomizationHook(UFortAthenaAIBotCustomizationData* InBotData, AFortPlayerPawn* NewBot, __int64 idk)
	{
		LOG_INFO(LogDev, "ApplyOverrideCharacterCustomizationHook!");

		Bosses::SpawnBoss(NewBot, NewBot->GetTransform(), InBotData);
		NewBot->K2_DestroyActor();
	}

	static UClass* StaticClass()
	{
		static auto Class = FindObject<UClass>(L"/Script/FortniteGame.FortAthenaAIBotCustomizationData");
		return Class;
	}
};
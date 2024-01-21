#pragma once

#include "reboot.h"
#include "FortAthenaAIBotCharacterCustomization.h"
#include "BehaviorTree.h"
#include "FortBotNameSettings.h"
#include "FortPlayerControllerAthena.h"

struct FFortAthenaAIBotRunTimeCustomizationData
{
public:
	FGameplayTag								 PredefinedCosmeticSetTag;                          // 0x0(0x8)(Edit, BlueprintVisible, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                        CullDistanceSquared;                               // 0x8(0x4)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                         bCheckForOverlaps;                                 // 0xC(0x1)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                        bHasCustomSquadId : 1;                             // Mask: 0x1, PropSize: 0x10xD(0x1)(Edit, BlueprintVisible, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                        BitPad_2D1 : 7;                                    // Fixing Bit-Field Size  [ Dumper-7 ]
	uint8                                        CustomSquadId;                                     // 0xE(0x1)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                        Pad_4865[0x1];                                     // Fixing Size Of Struct [ Dumper-7 ]
};

class UFortAthenaAIBotInventoryItems : public UObject
{
public:
	TArray<UFortItemDefinition*> GetItems()
	{
		static auto ItemsOffset = GetOffset("Items");
		return Get<TArray<UFortItemDefinition*>>(ItemsOffset);
	}
};

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

	UFortAthenaAIBotInventoryItems* GetStartupInventory()
	{
		static auto StartupInventoryOffset = GetOffset("StartupInventory");
		return Get<UFortAthenaAIBotInventoryItems*>(StartupInventoryOffset);
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

	static void ApplyOverrideCharacterCustomizationHook(UFortAthenaAIBotCustomizationData* InBotData, AFortPlayerPawn* NewBot, __int64 idk)
	{
		LOG_INFO(LogDev, "ApplyOverrideCharacterCustomizationHook!");

		auto CharacterCustomization = InBotData->GetCharacterCustomization();

		auto Controller = NewBot->GetController();

		LOG_INFO(LogDev, "Controller: {}", Controller->IsValidLowLevel() ? Controller->GetPathName() : "BadRead");
		
		/*

		static auto CosmeticLoadoutBCOffset = Controller->GetOffset("CosmeticLoadoutBC");
		Controller->GetPtr<FFortAthenaLoadout>(CosmeticLoadoutBCOffset)->GetCharacter() = CharacterCustomization->GetCustomizationLoadout()->GetCharacter();

		*/

		ApplyHID(NewBot, CharacterCustomization->GetCustomizationLoadout()->GetCharacter()->GetHeroDefinition());

		/*

		auto PlayerStateAsFort = Cast<AFortPlayerState>(Controller->GetPlayerState());

		static auto UpdatePlayerCustomCharacterPartsVisualizationFn = FindObject<UFunction>(L"/Script/FortniteGame.FortKismetLibrary.UpdatePlayerCustomCharacterPartsVisualization");
		PlayerStateAsFort->ProcessEvent(UpdatePlayerCustomCharacterPartsVisualizationFn, &PlayerStateAsFort);

		PlayerStateAsFort->ForceNetUpdate();
		NewBot->ForceNetUpdate();
		Controller->ForceNetUpdate();

		*/

		// NewBot->GetCosmeticLoadout()->GetCharacter() = CharacterCustomization->GetCustomizationLoadout()->GetCharacter();
	}

	static UClass* StaticClass()
	{
		static auto Class = FindObject<UClass>(L"/Script/FortniteGame.FortAthenaAIBotCustomizationData");
		return Class;
	}
};
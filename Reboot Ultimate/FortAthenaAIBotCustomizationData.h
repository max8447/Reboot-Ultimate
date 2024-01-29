#pragma once

#include "reboot.h"
#include "FortAthenaAIBotCharacterCustomization.h"
#include "BehaviorTree.h"
#include "FortBotNameSettings.h"
#include "FortPlayerControllerAthena.h"
#include "bots.h"
#include "FortPlayerPawn.h"
#include "DataTable.h"
#include "FortBotNameSettings.h"
#include "KismetTextLibrary.h"

struct FFortAthenaAIBotRunTimeCustomizationData
{
public:
	FGameplayTag								 PredefinedCosmeticSetTag;                          // 0x0(0x8)(Edit, BlueprintVisible, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                        CullDistanceSquared;                               // 0x8(0x4)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                         bCheckForOverlaps;                                 // 0xC(0x1)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                        bHasCustomSquadId : 1;                             // Mask: 0x1, PropSize: 0x10xD(0x1)(Edit, BlueprintVisible, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                        BitPad_2D1 : 7;                                    // Fixing Bit-Field Size  [ Dumper-7 ]
	uint8                                        CustomSquadId;                                     // 0xE(0x1)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                        Pad_4996[0x1];                                     // Fixing Size Of Struct [ Dumper-7 ]
};

class UFortAthenaAIBotInventoryItems : public UObject
{
public:
	TArray<FItemAndCount> GetItems()
	{
		static auto ItemsOffset = GetOffset("Items");
		return Get<TArray<FItemAndCount>>(ItemsOffset);
	}
};

class UFortAthenaAIBotCosmeticLibraryData : public UObject // UDataAsset
{
public:
	TSoftObjectPtr<UDataTable> GetPredefineSetsDataTable()
	{
		static auto PredefineSetsDataTableOffset = GetOffset("PredefineSetsDataTable");
		return Get<TSoftObjectPtr<UDataTable>>(PredefineSetsDataTableOffset);
	}
};

struct PhoebeHenchman;

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

	TSoftObjectPtr<UFortAthenaAIBotCosmeticLibraryData> GetCosmeticCustomizationLibrary()
	{
		static auto CosmeticCustomizationLibraryOffset = GetOffset("CosmeticCustomizationLibrary");
		return Get<TSoftObjectPtr<UFortAthenaAIBotCosmeticLibraryData>>(CosmeticCustomizationLibraryOffset);
	}

	static void ApplyOverrideCharacterCustomizationHook(UFortAthenaAIBotCustomizationData* InBotData, AFortPlayerPawn* NewBot, __int64 idk)
	{
		LOG_INFO(LogDev, "ApplyOverrideCharacterCustomizationHook!");

		UAthenaCharacterItemDefinition* CharacterToApply = nullptr;

		if (!CharacterToApply)
		{
			auto DefaultCharacterName = InBotData->GetCharacterCustomization()->GetCustomizationLoadout()->GetCharacter()->GetName();

			if (DefaultCharacterName != "CID_556_Athena_Commando_F_RebirthDefaultA")
			{
				CharacterToApply = InBotData->GetCharacterCustomization()->GetCustomizationLoadout()->GetCharacter();
			}
			else
			{
				if (InBotData->GetFullName().contains("Alter"))
				{
					CharacterToApply = FindObject<UAthenaCharacterItemDefinition>("CID_780_Athena_Commando_M_HenchmanBadShorts", nullptr, ANY_PACKAGE);
				}
				else if (InBotData->GetFullName().contains("Ego"))
				{
					CharacterToApply = FindObject<UAthenaCharacterItemDefinition>("CID_779_Athena_Commando_M_HenchmanGoodShorts", nullptr, ANY_PACKAGE);
				}
				else
				{
					CharacterToApply = FindObject<UAthenaCharacterItemDefinition>("CID_NPC_Athena_Commando_M_HenchmanGood", nullptr, ANY_PACKAGE);
				}
			}
		}

		auto PawnClass = InBotData->GetPawnClass();

		PhoebeHenchman* Henchman = new PhoebeHenchman(Cast<AFortPlayerPawnAthena>(NewBot), PawnClass);

		if (CharacterToApply)
		{
			auto HeroDefinition = CharacterToApply->Get<UFortHeroType*>(CharacterToApply->GetOffset("HeroDefinition"));

			ApplyHID(Henchman->Pawn, HeroDefinition, true);

			LOG_INFO(LogBots, "Applied Skin.");
		}
		else
		{
			LOG_WARN(LogBots, "Failed to find Character for Henchman!");
		}

		LOG_INFO(LogBots, "BotData: {}, Coordinates: {}", InBotData->GetFullName(), Henchman->Pawn->GetActorLocation().ToString().ToString());

		struct FItemAndCount
		{
			int                                                Count;                                                    // 0x0000(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
			unsigned char                                      UnknownData00[0x4];                                       // 0x0004(0x0004) MISSED OFFSET
			UFortItemDefinition* Item;                                                     // 0x0008(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
		};

		static auto StartupInventoryOffset = InBotData->GetOffset("StartupInventory");
		auto StartupInventory = InBotData->Get(StartupInventoryOffset);
		static auto StartupInventoryItemsOffset = StartupInventory->GetOffset("Items");

		std::vector<std::pair<UFortItemDefinition*, int>> ItemsToGrant;

		if (Fortnite_Version < 13)
		{
			auto& StartupInventoryItems = StartupInventory->Get<TArray<UFortItemDefinition*>>(StartupInventoryItemsOffset);

			for (int i = 0; i < StartupInventoryItems.Num(); ++i)
			{
				ItemsToGrant.push_back({ StartupInventoryItems.at(i), 1 });
			}
		}
		else
		{
			auto& StartupInventoryItems = StartupInventory->Get<TArray<FItemAndCount>>(StartupInventoryItemsOffset);

			for (int i = 0; i < StartupInventoryItems.Num(); ++i)
			{
				ItemsToGrant.push_back({ StartupInventoryItems.at(i).Item, StartupInventoryItems.at(i).Count });
			}
		}

		static auto InventoryOffset = Henchman->PlayerController->GetOffset("Inventory");
		auto Inventory = Henchman->PlayerController->Get<AFortInventory*>(InventoryOffset);

		if (Inventory)
		{
			for (int i = 0; i < ItemsToGrant.size(); ++i)
			{
				auto pair = Inventory->AddItem(ItemsToGrant.at(i).first, nullptr, ItemsToGrant.at(i).second);

				LOG_INFO(LogDev, "pair.first.size(): {}", pair.first.size());

				if (pair.first.size() > 0)
				{
					if (auto weaponDef = Cast<UFortWeaponItemDefinition>(ItemsToGrant.at(i).first))
						Henchman->Pawn->EquipWeaponDefinition(weaponDef, pair.first.at(0)->GetItemEntry()->GetItemGuid());
				}
			}

			Inventory->Update();
		}

		auto BotNameSettings = InBotData->GetBotNameSettings();
		auto OverrideName = BotNameSettings->GetOverrideName();
		auto OverrideNameStr = UKismetTextLibrary::Conv_TextToString(OverrideName);

		auto GameMode = Cast<AFortGameModeAthena>(GetWorld()->GetGameMode());

		GameMode->ChangeName(Henchman->PlayerController, OverrideNameStr, false);
	}

	static UClass* StaticClass()
	{
		static auto Class = FindObject<UClass>(L"/Script/FortniteGame.FortAthenaAIBotCustomizationData");
		return Class;
	}
};
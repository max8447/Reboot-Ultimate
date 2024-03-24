#include "BuildingContainer.h"
#include "FortPickup.h"
#include "FortLootPackage.h"
#include "FortGameModeAthena.h"
#include "gui.h"

template<typename T>
static inline bool VectorContains(T Item, std::vector<T>& Vector)
{
	for (auto& Def : Vector)
	{
		if (Def == Item)
			return true;
	}

	return false;
}

static inline ItemRow* GetRandomItemForCustomLootpool(std::string LootTier, EFortItemType ItemType = EFortItemType::EFortItemType_MAX, bool bEnableDefs = false, bool bTypeMatters = true)
{
	static std::vector<UFortItemDefinition*> LastDefs{};

	if (!CustomLootpoolMap.contains(LootTier))
		return nullptr;

	auto AllItemsRowsOfTier = CustomLootpoolMap[LootTier];

	if (AllItemsRowsOfTier.size() <= 0)
		return nullptr;

	// std::shuffle(AllItemsRowsOfTier.at(0), AllItemsRowsOfTier.at(AllItemsRowsOfTier.Num()), std::default_random_engine((unsigned int)time(0)));

	ItemRow ItemRow = AllItemsRowsOfTier[std::rand() % AllItemsRowsOfTier.size()];

	if (bEnableDefs)
	{
		bool ItemIsContainedInLastDefs = VectorContains<UFortItemDefinition*>(ItemRow.Definition, LastDefs);

		if (ItemIsContainedInLastDefs)
			return GetRandomItemForCustomLootpool(LootTier, ItemType);
	}

	if (!bTypeMatters && ItemType != EFortItemType::EFortItemType_MAX && ItemRow.Definition->GetItemType() != ItemType)
	{
		LOG_INFO(LogDev, "Regenerating, ItemType was incorrect.");
		return GetRandomItemForCustomLootpool(LootTier, ItemType, false, false);
	}

	if (!UKismetMathLibrary::RandomBoolWithWeight(ItemRow.Weight))
	{
		LOG_INFO(LogDev, "Regenerating, didn't hit Weight.");
		return GetRandomItemForCustomLootpool(LootTier, ItemType);
	}

	if (!ItemRow.Definition->ClassPrivate)
	{
		LOG_INFO(LogDev, "Regenerating, no ClassPrivate");
		return GetRandomItemForCustomLootpool(LootTier, ItemType);
	}

	if (bEnableDefs)
	{
		LastDefs.push_back(ItemRow.Definition);

		if (LastDefs.size() > 3)
			LastDefs.erase(LastDefs.begin());
	}

	if (ItemType == EFortItemType::WeaponRanged)
	{
		ItemRow.DropCount = Cast<UFortWeaponItemDefinition>(ItemRow.Definition)->GetClipSize();
	}
	else
	{
		ItemRow.DropCount = ItemRow.Definition->GetMaxStackSize();
	}

	LOG_INFO(LogDev, "Random Item: {}", ItemRow.Definition->GetFullName());

	return &ItemRow;
}

void ABuildingContainer::OnLootHook(ABuildingContainer* BuildingContainer)
{
	BuildingContainer->ForceNetUpdate();

	auto GameMode = Cast<AFortGameModeAthena>(GetWorld()->GetGameMode());

	FVector LocationToSpawnLoot = BuildingContainer->GetActorLocation() + BuildingContainer->GetActorForwardVector() * BuildingContainer->GetLootSpawnLocation_Athena().X + BuildingContainer->GetActorRightVector() * BuildingContainer->GetLootSpawnLocation_Athena().Y + BuildingContainer->GetActorUpVector() * BuildingContainer->GetLootSpawnLocation_Athena().Z;

	auto RedirectedLootTier = GameMode->RedirectLootTier(BuildingContainer->GetSearchLootTierGroup());

	static auto Loot_TreasureFName = UKismetStringLibrary::Conv_StringToName(L"Loot_Treasure");
	static auto Loot_AmmoFName = UKismetStringLibrary::Conv_StringToName(L"Loot_Ammo");

	if (RedirectedLootTier == Loot_TreasureFName)
		RedirectedLootTier = UKismetStringLibrary::Conv_StringToName(L"Loot_AthenaTreasure");

	if (RedirectedLootTier == Loot_AmmoFName)
		RedirectedLootTier = UKismetStringLibrary::Conv_StringToName(L"Loot_AthenaAmmoLarge");

	LOG_INFO(LogInteraction, "RedirectedLootTier: {}", RedirectedLootTier.ToString());

	auto GameState = Cast<AFortGameStateAthena>(GetWorld()->GetGameState());

	std::vector<LootDrop> LootDrops;

	if (Globals::bCustomLootpool)
	{
		std::string LootTierStr = RedirectedLootTier.ToString();
		EFortItemType ItemType = EFortItemType::EFortItemType_MAX;
		int RepeatNum = 1;
		ItemRow* RandomItem = nullptr;

		if (LootTierStr == "Loot_AthenaTreasure")
		{
			ItemType = EFortItemType::WeaponRanged;
		}
		else if (LootTierStr == "Loot_AthenaIceBox")
		{
			RepeatNum = 2;
		}
		else if (LootTierStr == "Loot_AthenaTreasure_Blue" || LootTierStr == "Loot_AthenaTreasure_Red")
		{
			ItemType = EFortItemType::WeaponRanged;
			RepeatNum = 3;
		}

		for (int i = 0; i < RepeatNum; i++)
		{
			RandomItem = GetRandomItemForCustomLootpool(LootTierStr, ItemType);

			if (RandomItem && RandomItem->Definition)
			{
				try
				{
					auto Entry = FFortItemEntry::MakeItemEntry(LoadObject<UFortItemDefinition>(RandomItem->Definition->GetFullName(), UFortItemDefinition::StaticClass()), 1, Cast<UFortWeaponItemDefinition>(RandomItem->Definition)->GetClipSize());
					LootDrops.push_back(LootDrop(Entry));
					LOG_INFO(LogDev, "Entry->ItemDefinition: {}", Entry->GetItemDefinition()->GetFullName());
				}
				catch (...)
				{
					LOG_ERROR(LogGame, "Failed to generate loot!");
				}
			}
			else
			{
				LOG_WARN(LogDev, "RandomItem or RandomItem->Definition is nullptr!");
			}
		}

		if (ItemType == EFortItemType::WeaponRanged)
		{
			static auto Wood = FindObject<UFortItemDefinition>("/Game/Items/ResourcePickups/WoodItemData.WoodItemData");
			static auto Metal = FindObject<UFortItemDefinition>("/Game/Items/ResourcePickups/MetalItemData.MetalItemData");
			static auto Stone = FindObject<UFortItemDefinition>("/Game/Items/ResourcePickups/StoneItemData.StoneItemData");

			UFortItemDefinition* ResourceDefinition = nullptr;

			if (std::rand() % 40 > 20)
			{
				ResourceDefinition = std::rand() % 20 > 10 ? Wood : Stone;
			}
			else
			{
				ResourceDefinition = Metal;
			}

			LootDrops.push_back(LootDrop(FFortItemEntry::MakeItemEntry(ResourceDefinition, 30)));

			ItemRow* RandomConsumableItem = GetRandomItemForCustomLootpool(LootTierStr, EFortItemType::Consumable);

			if (RandomConsumableItem && RandomConsumableItem->Definition)
			{
				LootDrops.push_back(LootDrop(FFortItemEntry::MakeItemEntry(RandomConsumableItem->Definition)));
			}

			if (RandomItem && RandomItem->Definition)
			{
				try
				{
					UFortWorldItemDefinition* AmmoItem = Cast<UFortWeaponItemDefinition>(RandomItem->Definition)->GetAmmoData();

					if (AmmoItem && RandomItem->Definition != AmmoItem && AmmoItem->GetDropCount() > 0)
					{
						LootDrops.push_back(LootDrop(FFortItemEntry::MakeItemEntry(AmmoItem, AmmoItem->GetDropCount())));
					}
				}
				catch (...)
				{
					LOG_ERROR(LogGame, "Failed to generate ammo!");
				}
			}
		}
	}
	else
	{
		LootDrops = PickLootDrops(RedirectedLootTier, GameState->GetWorldLevel(), -1, bDebugPrintLooting);
	}

	// LOG_INFO(LogInteraction, "LootDrops.size(): {}", LootDrops.size());

	for (auto& LootDrop : LootDrops)
	{
		PickupCreateData CreateData;
		CreateData.bToss = true;
		CreateData.ItemEntry = LootDrop.ItemEntry;
		CreateData.SpawnLocation = LocationToSpawnLoot;
		CreateData.SourceType = EFortPickupSourceTypeFlag::GetContainerValue();
		CreateData.bRandomRotation = true;
		CreateData.bShouldFreeItemEntryWhenDeconstructed = true;

		auto NewPickup = AFortPickup::SpawnPickup(CreateData);
	}

	if (!BuildingContainer->IsDestroyed())
	{
		BuildingContainer->ForceNetUpdate();
		// a buncha other stuff
	}
}

UClass* ABuildingContainer::StaticClass()
{
	static auto Class = FindObject<UClass>("/Script/FortniteGame.BuildingContainer");
	return Class;
}
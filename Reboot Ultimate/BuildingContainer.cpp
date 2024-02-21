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

static inline ItemRow* GetRandomItemForCustomLootpool(std::string LootTier, EFortItemType ItemType = EFortItemType::EFortItemType_MAX, bool EnableDefs = false)
{
	static std::vector<UFortItemDefinition*> LastDefs{};

	if (!CustomLootpoolMap.contains(LootTier))
		return nullptr;

	auto& Vector = CustomLootpoolMap[LootTier];

	if (Vector.size() <= 0)
		return nullptr;
	static auto rng = std::default_random_engine((unsigned int)time(0));
	std::shuffle(Vector.begin(), Vector.end(), rng);

	ItemRow* Ret = &Vector[UKismetMathLibrary::RandomIntegerInRange(0, Vector.size() - 1)];

	if (EnableDefs)
	{
		bool contains = VectorContains<UFortItemDefinition*>(Ret->Definition, LastDefs);

		if (contains)
			return GetRandomItemForCustomLootpool(LootTier, ItemType);
	}

	if (ItemType != EFortItemType::EFortItemType_MAX && Ret->Definition->GetItemType() != ItemType)
		return GetRandomItemForCustomLootpool(LootTier, ItemType);

	if (!UKismetMathLibrary::RandomBoolWithWeight(Ret->Weight))
		return GetRandomItemForCustomLootpool(LootTier, ItemType);

	if (EnableDefs)
	{
		LastDefs.push_back(Ret->Definition);

		if (LastDefs.size() > 3)
			LastDefs.erase(LastDefs.begin());
	}

	return Ret;
}

bool ABuildingContainer::SpawnLoot(AFortPawn* Pawn)
{
	if (!Pawn)
		return false;

	this->ForceNetUpdate();

	auto GameMode = Cast<AFortGameModeAthena>(GetWorld()->GetGameMode());
	// idk
   /* this->GetActorForwardVector() * this->GetLootSpawnLocation_Athena().X + this->GetActorRightVector() * this->GetLootSpawnLocation_Athena().Y + this->GetActorUpVector() * this->GetLootSpawnLocation_Athena().Z*/

	FVector LocationToSpawnLoot = this->GetActorLocation() + this->GetActorForwardVector() * this->GetLootSpawnLocation_Athena().X + this->GetActorRightVector() * this->GetLootSpawnLocation_Athena().Y + this->GetActorUpVector() * this->GetLootSpawnLocation_Athena().Z;

	auto RedirectedLootTier = GameMode->RedirectLootTier(GetSearchLootTierGroup());

	LOG_INFO(LogInteraction, "RedirectedLootTier: {}", RedirectedLootTier.ToString());

	auto GameState = Cast<AFortGameStateAthena>(GetWorld()->GetGameState());

	std::vector<LootDrop> LootDrops;

	if (Globals::bCustomLootpool)
	{
		std::string LootTierStr = RedirectedLootTier.ToString();
		bool bIsChest = LootTierStr == "Loot_AthenaTreasure" ? true : false;
		bool bIsFactionChest = LootTierStr == "Loot_AthenaTreasure_Blue" || LootTierStr == "Loot_AthenaTreasure_Red";

		ItemRow* RandomWeaponItem = GetRandomItemForCustomLootpool(LootTierStr, (bIsChest ? EFortItemType::WeaponRanged : EFortItemType::EFortItemType_MAX));

		if (RandomWeaponItem && RandomWeaponItem->Definition)
		{
			LootDrop WeaponDrop;
			WeaponDrop.ItemEntry = ((UFortItem*)RandomWeaponItem->Definition)->GetItemEntry();

			LootDrops.push_back(WeaponDrop);
		}

		if (LootTierStr == "Loot_AthenaIceBox")
		{
			for (int i = 0; i < 2; i++)
			{
				ItemRow* RandomIceBoxItem = GetRandomItemForCustomLootpool(LootTierStr, EFortItemType::EFortItemType_MAX);

				if (RandomIceBoxItem && RandomIceBoxItem->Definition)
				{
					LootDrop IceBoxDrop;
					IceBoxDrop.ItemEntry = ((UFortItem*)RandomIceBoxItem->Definition)->GetItemEntry();

					LootDrops.push_back(IceBoxDrop);
				}
			}
		}

		UFortWorldItemDefinition* AmmoItem = Cast<UFortWorldItemDefinition>(Cast<UFortWeaponItemDefinition>(RandomWeaponItem->Definition))->GetAmmoWorldItemDefinition_BP();

		if (AmmoItem && RandomWeaponItem->Definition != AmmoItem && AmmoItem->GetDropCount() > 0)
		{
			LootDrop AmmoDrop;
			AmmoDrop.ItemEntry = ((UFortItem*)AmmoItem)->GetItemEntry();

			LootDrops.push_back(AmmoDrop);
		}

		if (bIsChest || bIsFactionChest)
		{
			ItemRow* RandomConsumableItem = GetRandomItemForCustomLootpool(LootTierStr, EFortItemType::Consumable);

			if (RandomConsumableItem)
			{
				LootDrop ConsumableDrop;
				ConsumableDrop.ItemEntry = ((UFortItem*)RandomConsumableItem)->GetItemEntry();

				LootDrops.push_back(ConsumableDrop);
			}

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

			LootDrop ResourceDrop;
			ResourceDrop.ItemEntry = ((UFortItem*)ResourceDefinition)->GetItemEntry();

			LootDrops.push_back(ResourceDrop);
		}

		if (bIsFactionChest)
		{
			for (int i = 0; i < 3; i++)
			{
				ItemRow* RandomFactionItem = GetRandomItemForCustomLootpool(LootTierStr, (bIsChest ? EFortItemType::WeaponRanged : EFortItemType::EFortItemType_MAX));

				if (RandomFactionItem && RandomFactionItem->Definition)
				{
					LootDrop FactionDrop;
					FactionDrop.ItemEntry = ((UFortItem*)RandomFactionItem->Definition)->GetItemEntry();

					LootDrops.push_back(FactionDrop);
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
		// CreateData.PawnOwner = Pawn;
		CreateData.ItemEntry = LootDrop.ItemEntry;
		CreateData.SpawnLocation = LocationToSpawnLoot;
		CreateData.SourceType = EFortPickupSourceTypeFlag::GetContainerValue();
		CreateData.bRandomRotation = true;
		CreateData.bShouldFreeItemEntryWhenDeconstructed = true;

		auto NewPickup = AFortPickup::SpawnPickup(CreateData);
	}

	if (!this->IsDestroyed())
	{
		this->ForceNetUpdate();
		// a buncha other stuff
	}

	return true;
}
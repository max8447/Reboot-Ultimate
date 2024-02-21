#pragma once

#include "BuildingSMActor.h"
#include "FortPawn.h"

enum class EFortItemType : uint8
{
	WorldItem = 0,
	Ammo = 1,
	Badge = 2,
	BackpackPickup = 3,
	BuildingPiece = 4,
	CharacterPart = 5,
	Consumable = 6,
	Deco = 7,
	EditTool = 8,
	Ingredient = 9,
	ItemCache = 10,
	Food = 11,
	Gadget = 12,
	AthenaGadget = 13,
	HomebaseGadget = 14,
	BattleLabDevice = 15,
	SpyTechPerk = 16,
	HeroAbility = 17,
	MissionItem = 18,
	Trap = 19,
	Weapon = 20,
	WeaponMelee = 21,
	WeaponRanged = 22,
	WeaponHarvest = 23,
	WeaponCreativePhone = 24,
	WorldResource = 25,
	CreativeUserPrefab = 26,
	CreativePlayset = 27,
	Vehicle = 28,
	AccountItem = 29,
	AccountResource = 30,
	CollectedResource = 31,
	Alteration = 32,
	CardPack = 33,
	Currency = 34,
	Hero = 35,
	Schematic = 36,
	Worker = 37,
	TeamPerk = 38,
	PlayerTech = 39,
	Token = 40,
	DailyRewardScheduleToken = 41,
	CodeToken = 42,
	Stat = 43,
	Buff = 44,
	BuffCredit = 45,
	Quest = 46,
	Accolades = 47,
	MedalsPunchCard = 48,
	ChallengeBundle = 49,
	ChallengeBundleSchedule = 50,
	ChallengeBundleCompletionToken = 51,
	GameplayModifier = 52,
	Outpost = 53,
	HomebaseNode = 54,
	Defender = 55,
	ConversionControl = 56,
	DeployableBaseCloudSave = 57,
	ConsumableAccountItem = 58,
	Quota = 59,
	Expedition = 60,
	HomebaseBannerIcon = 61,
	HomebaseBannerColor = 62,
	AthenaSkyDiveContrail = 63,
	PersonalVehicle = 64,
	AthenaGlider = 65,
	AthenaPickaxe = 66,
	AthenaHat = 67,
	AthenaBackpack = 68,
	AthenaCharacter = 69,
	AthenaDance = 70,
	AthenaConsumableEmote = 71,
	AthenaLoadingScreen = 72,
	AthenaBattleBus = 73,
	AthenaVehicleCosmetic = 74,
	AthenaItemWrap = 75,
	AthenaCallingCard = 76,
	AthenaMapMarker = 77,
	AthenaMusicPack = 78,
	AthenaPetCosmetic = 79,
	AthenaCharmCosmetic = 80,
	AthenaVictoryPose = 81,
	AthenaSeasonTreasure = 82,
	AthenaSeason = 83,
	AthenaRewardGraph = 84,
	EventDescription = 85,
	BattleLabDeviceAccount = 86,
	MatchAward = 87,
	AthenaEventToken = 88,
	EventPurchaseTracker = 89,
	CosmeticVariantToken = 90,
	CampaignHeroLoadout = 91,
	Playset = 92,
	PrerollData = 93,
	CreativePlot = 94,
	PlayerSurveyToken = 95,
	CosmeticLocker = 96,
	BannerToken = 97,
	RestedXpBoosterToken = 98,
	RewardEventGraphPurchaseToken = 99,
	HardcoreModifier = 100,
	EventDependentItem = 101,
	SpecialItem = 102,
	Emote = 103,
	Stack = 104,
	CollectionBookPage = 105,
	BGAConsumableWrapper = 106,
	GiftBox = 107,
	GiftBoxUnlock = 108,
	PlaysetProp = 109,
	RegCosmeticDef = 110,
	Profile = 111,
	Max_None = 112,
	EFortItemType_MAX = 113,
};


class ABuildingContainer : public ABuildingSMActor
{
public:
	bool ShouldDestroyOnSearch()
	{
		static auto bDestroyContainerOnSearchOffset = GetOffset("bDestroyContainerOnSearch");
		static auto bDestroyContainerOnSearchFieldMask = GetFieldMask(GetProperty("bDestroyContainerOnSearch"));
		return this->ReadBitfieldValue(bDestroyContainerOnSearchOffset, bDestroyContainerOnSearchFieldMask);
	}

	FName& GetSearchLootTierGroup()
	{
		static auto SearchLootTierGroupOffset = this->GetOffset("SearchLootTierGroup");
		return Get<FName>(SearchLootTierGroupOffset);
	}

	bool IsAlreadySearched()
	{
		static auto bAlreadySearchedOffset = this->GetOffset("bAlreadySearched");
		static auto bAlreadySearchedFieldMask = GetFieldMask(this->GetProperty("bAlreadySearched"));
		return this->ReadBitfieldValue(bAlreadySearchedOffset, bAlreadySearchedFieldMask);
	}

	FVector& GetLootSpawnLocation_Athena()
	{
		static auto LootSpawnLocation_AthenaOffset = this->GetOffset("LootSpawnLocation_Athena");
		return this->Get<FVector>(LootSpawnLocation_AthenaOffset);
	}

	void SetAlreadySearched(bool bNewValue, bool bOnRep = true)
	{
		static auto bAlreadySearchedOffset = this->GetOffset("bAlreadySearched");
		static auto bAlreadySearchedFieldMask = GetFieldMask(this->GetProperty("bAlreadySearched"));
		this->SetBitfieldValue(bAlreadySearchedOffset, bAlreadySearchedFieldMask, bNewValue);

		if (bOnRep)
		{
			static auto OnRep_bAlreadySearchedFn = FindObject<UFunction>(L"/Script/FortniteGame.BuildingContainer.OnRep_bAlreadySearched");
			this->ProcessEvent(OnRep_bAlreadySearchedFn);
		}
	}

	FVector& GetLootSpawnLocation()
	{
		static auto LootSpawnLocationOffset = GetOffset("LootSpawnLocation");
		return Get<FVector>(LootSpawnLocationOffset);
	}

	float& GetLootNoiseRange()
	{
		static auto LootNoiseRangeOffset = GetOffset("LootNoiseRange");
		return Get<float>(LootNoiseRangeOffset);
	}

	void BounceContainer()
	{
		static auto BounceContainerFn = FindObject<UFunction>("/Script/FortniteGame.BuildingContainer.BounceContainer");
		this->ProcessEvent(BounceContainerFn);
	}

	bool SpawnLoot(AFortPawn* Pawn);

	static UClass* StaticClass()
	{
		static auto Class = FindObject<UClass>("/Script/FortniteGame.BuildingContainer");
		return Class;
	}
};
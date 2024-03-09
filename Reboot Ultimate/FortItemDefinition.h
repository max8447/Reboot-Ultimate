#pragma once

#include "FortItem.h"
#include "Object.h"
#include "Class.h"

#include "reboot.h"
#include "GameplayTagContainer.h"

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

enum class EFortInventoryFilter : uint8
{
	WeaponMelee = 0,
	WeaponRanged = 1,
	Ammo = 2,
	Traps = 3,
	Consumables = 4,
	Ingredients = 5,
	Gadget = 6,
	Decorations = 7,
	Badges = 8,
	Heroes = 9,
	LeadSurvivors = 10,
	Survivors = 11,
	Defenders = 12,
	Resources = 13,
	ConversionControl = 14,
	AthenaCosmetics = 15,
	Playset = 16,
	CreativePlot = 17,
	TeamPerk = 18,
	Workers = 19,
	Invisible = 20,
	Max_None = 21,
	EFortInventoryFilter_MAX = 22,
};

class UFortItemDefinition : public UObject
{
public:
	UFortItem* CreateTemporaryItemInstanceBP(int Count, int Level = 1); // Should Level be 20?
	float GetMaxStackSize();
	EFortItemType GetItemType();

	bool DoesAllowMultipleStacks()
	{
		static auto bAllowMultipleStacksOffset = GetOffset("bAllowMultipleStacks");
		static auto bAllowMultipleStacksFieldMask = GetFieldMask(GetProperty("bAllowMultipleStacks"));
		return ReadBitfieldValue(bAllowMultipleStacksOffset, bAllowMultipleStacksFieldMask);
	}

	EFortInventoryFilter GetFilterOverride()
	{
		static auto FilterOverrideOffset = GetOffset("FilterOverride");
		return Get<EFortInventoryFilter>(FilterOverrideOffset);
	}

	FGameplayTagContainer GetGameplayTags()
	{
		return Get<FGameplayTagContainer>("GameplayTags");
	}

	static UClass* StaticClass()
	{
		static auto Class = FindObject<UClass>(L"/Script/FortniteGame.FortItemDefinition");
		return Class;
	}
};

struct FItemAndCount
{
private:
	int                                                Count;                                                    // 0x0000(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	unsigned char                                      UnknownData00[0x4];                                       // 0x0004(0x0004) MISSED OFFSET
	UFortItemDefinition* Item;                                                     // 0x0008(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
public:
	int& GetCount()
	{
		return Count;
	}

	UFortItemDefinition*& GetItem()
	{
		return Item;
	}
};
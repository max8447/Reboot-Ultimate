#pragma once

#include "PlayerController.h"
#include "FortInventory.h"
#include "FortPawn.h"

#include "Rotator.h"
#include "BuildingSMActor.h"
#include "Stack.h"
#include "ActorComponent.h"
#include "SoftObjectPtr.h"
#include "FortWeaponMeleeItemDefinition.h"

class UProperty : public UField
{
public:
	uint8                                        Pad_14[0x4];                                       // Fixing Size After Last (Predefined) Property  [ Dumper-7 ]
	int32                                        ElementSize;                                       // (0x34[0x04]) NOT AUTO-GENERATED PROPERTY
	uint64                                       PropertyFlags;                                     // (0x38[0x08]) NOT AUTO-GENERATED PROPERTY
	uint8                                        Pad_15[0x4];                                       // Fixing Size After Last (Predefined) Property  [ Dumper-7 ]
	int32                                        Offset;                                            // (0x44[0x04]) NOT AUTO-GENERATED PROPERTY
	uint8                                        Pad_16[0x28];                                      // Fixing Size Of Struct [ Dumper-7 ]
};

struct FPrimaryAssetType
{
public:
	FName                                  Name;                                              // 0x0(0x8)(Edit, BlueprintVisible, ZeroConstructor, SaveGame, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

struct FPrimaryAssetId
{
public:
	FPrimaryAssetType                     PrimaryAssetType;                                  // 0x0(0x8)(Edit, BlueprintVisible, ZeroConstructor, SaveGame, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	FName                                  PrimaryAssetName;                                  // 0x8(0x8)(Edit, BlueprintVisible, ZeroConstructor, SaveGame, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

enum class EXPEventPriorityType : uint8
{
	EXPEventPriorityType__NearReticle = 0,
	EXPEventPriorityType__XPBarOnly = 1,
	EXPEventPriorityType__TopCenter = 2,
	EXPEventPriorityType__Feed = 3,
	EXPEventPriorityType__EXPEventPriorityType_MAX = 4,
};

enum class EFortSimulatedXPSize : uint8
{
	EFortSimulatedXPSize__None = 0,
	EFortSimulatedXPSize__VerySmall = 1,
	EFortSimulatedXPSize__Small = 2,
	EFortSimulatedXPSize__Medium = 3,
	EFortSimulatedXPSize__Large = 4,
	EFortSimulatedXPSize__VeryLarge = 5,
	EFortSimulatedXPSize__EFortSimulatedXPSize_MAX = 6,
};

struct FXPEventEntry : public FFastArraySerializerItem
{
public:
	uint8                                        Pad_4665[0x4];                                     // Fixing Size After Last Property  [ Dumper-7 ]
	class FText                                  SimulatedXpEvent;                                  // 0x10(0x18)(NativeAccessSpecifierPublic)
	class UFortQuestItemDefinition* QuestDef;                                          // 0x28(0x8)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FPrimaryAssetId                       Accolade;                                          // 0x30(0x10)(ZeroConstructor, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                        Time;                                              // 0x40(0x4)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	int32                                        EventXpValue;                                      // 0x44(0x4)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	int32                                        TotalXpEarnedInMatch;                              // 0x48(0x4)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                        Pad_4666[0x4];                                     // Fixing Size Of Struct [ Dumper-7 ]
};

struct FXPEventInfo
{
public:
	class FName                                  EventName;                                         // 0x0(0x4)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                        Pad_68D4[0x4];                                     // Fixing Size After Last Property  [ Dumper-7 ]
	class FText                                  SimulatedText;                                     // 0x8(0x18)(Edit, BlueprintVisible, BlueprintReadOnly, NativeAccessSpecifierPublic)
	class FText                                  SimulatedName;                                     // 0x20(0x18)(Edit, BlueprintVisible, BlueprintReadOnly, NativeAccessSpecifierPublic)
	class UFortQuestItemDefinition* QuestDef;                                          // 0x38(0x8)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	enum class EXPEventPriorityType              Priority;                                          // 0x40(0x1)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                        Pad_68D5[0x3];                                     // Fixing Size After Last Property  [ Dumper-7 ]
	int32                                        EventXpValue;                                      // 0x44(0x4)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	int32                                        TotalXpEarnedInMatch;                              // 0x48(0x4)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FPrimaryAssetId                       Accolade;                                          // 0x4C(0x8)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	int32                                        RestedValuePortion;                                // 0x54(0x4)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	int32                                        SeasonBoostValuePortion;                           // 0x58(0x4)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	int32                                        RestedXPRemaining;                                 // 0x5C(0x4)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class AFortPlayerController* PlayerController;                                  // 0x60(0x8)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct TSoftObjectPtr<class UTexture2D>             AccoladeLargePreviewImageOverride;                 // 0x68(0x28)(Edit, BlueprintVisible, BlueprintReadOnly, UObjectWrapper, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	enum class EFortSimulatedXPSize              SimulatedXpSize;                                   // 0x90(0x1)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                        Pad_68D6[0x7];                                     // Fixing Size Of Struct [ Dumper-7 ]
};

static UClass* LettersClass = nullptr;
static UProperty* LetterQuestItem = nullptr;
static UProperty* BackendNameProp = nullptr;

class UAthenaCosmeticItemDefinition : public UFortItemDefinition // UFortAccountItemDefinition
{
public:
};

class UAthenaBattleBusItemDefinition : public UAthenaCosmeticItemDefinition
{
public:
};

class UFortHeroType : public UFortItemDefinition // UFortWorkerType
{
public:
};

class UAthenaCharacterItemDefinition : public UAthenaCosmeticItemDefinition
{
public:
	UFortHeroType* GetHeroDefinition()
	{
		static auto HeroDefinitonOffset = FindOffsetStruct("/Script/FortniteGame.AthenaCharacterItemDefinition", "HeroDefinition");
		return *(UFortHeroType**)(__int64(this) + HeroDefinitonOffset);
	}

	static UClass* StaticClass()
	{
		static auto Class = FindObject<UClass>(L"/Script/FortniteGame.AthenaCharacterItemDefinition");
		return Class;
	}
};

class UAthenaPickaxeItemDefinition : public UAthenaCosmeticItemDefinition
{
public:
	UFortWeaponMeleeItemDefinition* GetWeaponDefinition()
	{
		static auto WeaponDefinitionOffset = FindOffsetStruct("/Script/FortniteGame.AthenaPickaxeItemDefinition", "WeaponDefinition");
		return *(UFortWeaponMeleeItemDefinition**)(__int64(this) + WeaponDefinitionOffset);
	}

	static UClass* StaticClass()
	{
		static auto Class = FindObject<UClass>(L"/Script/FortniteGame.AthenaPickaxeItemDefinition");
		return Class;
	}
};

class UAthenaBackpackItemDefinition : public UAthenaCosmeticItemDefinition // UAthenaCharacterPartItemDefinition
{
public:
	static UClass* StaticClass()
	{
		static auto Class = FindObject<UClass>(L"/Script/FortniteGame.AthenaBackpackItemDefinition");
		return Class;
	}
};

class UAthenaGliderItemDefinition : public UAthenaCosmeticItemDefinition
{
public:
	static UClass* StaticClass()
	{
		static auto Class = FindObject<UClass>(L"/Script/FortniteGame.AthenaGliderItemDefinition");
		return Class;
	}
};

class UAthenaSkyDiveContrailItemDefinition : public UAthenaCosmeticItemDefinition
{
public:
	static UClass* StaticClass()
	{
		static auto Class = FindObject<UClass>(L"/Script/FortniteGame.AthenaSkyDiveContrailItemDefinition");
		return Class;
	}
};

class UAthenaDanceItemDefinition : public UAthenaCosmeticItemDefinition // UFortMontageItemDefinitionBase
{
public:
	static UClass* StaticClass()
	{
		static auto Class = FindObject<UClass>(L"/Script/FortniteGame.AthenaDanceItemDefinition");
		return Class;
	}
};

struct FFortAthenaLoadout
{
	static UStruct* GetStruct()
	{
		static auto Struct = FindObject<UStruct>("/Script/FortniteGame.FortAthenaLoadout");
		return Struct;
	}

	static int GetStructSize()
	{
		return GetStruct()->GetPropertiesSize();
	}

	UAthenaCharacterItemDefinition*& GetCharacter()
	{
		static auto CharacterOffset = FindOffsetStruct("/Script/FortniteGame.FortAthenaLoadout", "Character");
		return *(UAthenaCharacterItemDefinition**)(__int64(this) + CharacterOffset);
	}

	UAthenaBackpackItemDefinition*& GetBackpack()
	{
		static auto BackpackOffset = FindOffsetStruct("/Script/FortniteGame.FortAthenaLoadout", "Backpack");
		return *(UAthenaBackpackItemDefinition**)(__int64(this) + BackpackOffset);
	}

	UAthenaPickaxeItemDefinition*& GetPickaxe()
	{
		static auto PickaxeOffset = FindOffsetStruct("/Script/FortniteGame.FortAthenaLoadout", "Pickaxe");
		return *(UAthenaPickaxeItemDefinition**)(__int64(this) + PickaxeOffset);
	}

	UAthenaGliderItemDefinition*& GetGlider()
	{
		static auto GliderOffset = FindOffsetStruct("/Script/FortniteGame.FortAthenaLoadout", "Glider");
		return *(UAthenaGliderItemDefinition**)(__int64(this) + GliderOffset);
	}

	UAthenaSkyDiveContrailItemDefinition*& GetSkyDiveContrail()
	{
		static auto SkyDiveContrailOffset = FindOffsetStruct("/Script/FortniteGame.FortAthenaLoadout", "SkyDiveContrail");
		return *(UAthenaSkyDiveContrailItemDefinition**)(__int64(this) + SkyDiveContrailOffset);
	}
};

struct FAthenaLevelInfo
{
public:
	int32& GetLevelXp()
	{
		static auto LevelXpOffset = FindOffsetStruct("/Script/FortniteGame.AthenaLevelInfo", "LevelXp");
		return *(int32*)(__int64(this) + LevelXpOffset);
	}

	int32& GetBookLevelXp()
	{
		static auto BookLevelXpOffset = FindOffsetStruct("/Script/FortniteGame.AthenaLevelInfo", "BookLevelXp");
		return *(int32*)(__int64(this) + BookLevelXpOffset);
	}
};

struct FAthenaAccolades
{
public:
	class UFortAccoladeItemDefinition*& GetAccoladeDef()
	{
		static auto AccoladeDefOffset = FindOffsetStruct("/Script/FortniteGame.AthenaAccolades", "AccoladeDef");
		return *(class UFortAccoladeItemDefinition**)(__int64(this) + AccoladeDefOffset);
	}

	FString& GetTemplateId()
	{
		static auto TemplateIdOffset = FindOffsetStruct("/Script/FortniteGame.AthenaAccolades", "TemplateId");
		return *(FString*)(__int64(this) + TemplateIdOffset);
	}

	int32& GetCount()
	{
		static auto CountOffset = FindOffsetStruct("/Script/FortniteGame.AthenaAccolades", "Count");
		return *(int32*)(__int64(this) + CountOffset);
	}
};

struct FCardSlotMedalData
{
public:
	int32& GetSlotIndex()
	{
		static auto SlotIndexOffset = FindOffsetStruct("/Script/FortniteGame.CardSlotMedalData", "SlotIndex");
		return *(int32*)(__int64(this) + SlotIndexOffset);
	}

	class UFortAccoladeItemDefinition*& GetAccoladeForSlot()
	{
		static auto AccoladeForSlotOffset = FindOffsetStruct("/Script/FortniteGame.CardSlotMedalData", "AccoladeForSlot");
		return *(class UFortAccoladeItemDefinition**)(__int64(this) + AccoladeForSlotOffset);
	}

	bool& IsLoadedFromMcp()
	{
		static auto bLoadedFromMcpOffset = FindOffsetStruct("/Script/FortniteGame.CardSlotMedalData", "bLoadedFromMcp");
		return *(bool*)(__int64(this) + bLoadedFromMcpOffset);
	}

	bool& IsPunched()
	{
		static auto bPunchedOffset = FindOffsetStruct("/Script/FortniteGame.CardSlotMedalData", "bPunched");
		return *(bool*)(__int64(this) + bPunchedOffset);
	}
};

struct FXPEventArray : public FFastArraySerializer
{
public:
	TArray<FXPEventEntry>                 Entries;                                           // 0x108(0x10)(ZeroConstructor, NativeAccessSpecifierPublic)
	class UFortPlayerControllerAthenaXPComponent* ParentComp;                                        // 0x118(0x8)(ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

class UFortPlayerControllerAthenaXPComponent : public UActorComponent //UFortControllerComponent
{
public:
	int32 GetCurrentLevel()
	{
		static auto CurrentLevelOffset = FindOffsetStruct("/Script/FortniteGame.FortPlayerControllerAthenaXPComponent", "CurrentLevel");
		return *(int32*)(__int64(this) + CurrentLevelOffset);
	}

	bool& IsRegisteredWithQuestManager()
	{
		static auto IsRegisteredWithQuestManagerOffset = FindOffsetStruct("/Script/FortniteGame.FortPlayerControllerAthenaXPComponent", "bRegisteredWithQuestManager");
		return *(bool*)(__int64(this) + IsRegisteredWithQuestManagerOffset);
	}

	int32& GetCombatXp()
	{
		static auto CombatXpOffset = FindOffsetStruct("/Script/FortniteGame.FortPlayerControllerAthenaXPComponent", "CombatXp");
		return *(int32*)(__int64(this) + CombatXpOffset);
	}

	int32& GetSurvivalXp()
	{
		static auto SurvivalXpOffset = FindOffsetStruct("/Script/FortniteGame.FortPlayerControllerAthenaXPComponent", "SurvivalXp");
		return *(int32*)(__int64(this) + SurvivalXpOffset);
	}

	int32& GetMedalBonusXP()
	{
		static auto MedalBonusXPOffset = FindOffsetStruct("/Script/FortniteGame.FortPlayerControllerAthenaXPComponent", "MedalBonusXP");
		return *(int32*)(__int64(this) + MedalBonusXPOffset);
	}

	int32& GetChallengeXp()
	{
		static auto ChallengeXpOffset = FindOffsetStruct("/Script/FortniteGame.FortPlayerControllerAthenaXPComponent", "ChallengeXp");
		return *(int32*)(__int64(this) + ChallengeXpOffset);
	}

	int32& GetMatchXp()
	{
		static auto MatchXpOffset = FindOffsetStruct("/Script/FortniteGame.FortPlayerControllerAthenaXPComponent", "MatchXp");
		return *(int32*)(__int64(this) + MatchXpOffset);
	}

	int32& GetTotalXpEarned()
	{
		static auto TotalXpEarnedOffset = FindOffsetStruct("/Script/FortniteGame.FortPlayerControllerAthenaXPComponent", "TotalXpEarned");
		return *(int32*)(__int64(this) + TotalXpEarnedOffset);
	}

	int32& GetRestXP()
	{
		static auto RestXPOffset = FindOffsetStruct("/Script/FortniteGame.FortPlayerControllerAthenaXPComponent", "RestXP");
		return *(int32*)(__int64(this) + RestXPOffset);
	}

	int64& GetInMatchProfileVer()
	{
		static auto InMatchProfileVerOffset = FindOffsetStruct("/Script/FortniteGame.FortPlayerControllerAthenaXPComponent", "InMatchProfileVer");
		return *(int64*)(__int64(this) + InMatchProfileVerOffset);
	}

	TArray<FXPEventEntry>& GetWaitingQuestXp()
	{
		static auto WaitingQuestXpOffset = FindOffsetStruct("/Script/FortniteGame.FortPlayerControllerAthenaXPComponent", "WaitingQuestXp");
		return *(TArray<FXPEventEntry>*)(__int64(this) + WaitingQuestXpOffset);
	}

	TArray<FAthenaAccolades>& GetPlayerAccolades()
	{
		static auto PlayerAccoladesOffset = FindOffsetStruct("/Script/FortniteGame.FortPlayerControllerAthenaXPComponent", "PlayerAccolades");
		return *(TArray<FAthenaAccolades>*)(__int64(this) + PlayerAccoladesOffset);
	}

	TArray<UFortAccoladeItemDefinition*>& GetMedalsEarned()
	{
		static auto MedalsEarnedOffset = FindOffsetStruct("/Script/FortniteGame.FortPlayerControllerAthenaXPComponent", "MedalsEarned");
		return *(TArray<UFortAccoladeItemDefinition*>*)(__int64(this) + MedalsEarnedOffset);
	}

	TArray<FCardSlotMedalData>& GetLocalPunchCardMedals()
	{
		static auto LocalPunchCardMedalsOffset = FindOffsetStruct("/Script/FortniteGame.FortPlayerControllerAthenaXPComponent", "LocalPunchCardMedals");
		return *(TArray<FCardSlotMedalData>*)(__int64(this) + LocalPunchCardMedalsOffset);
	}

	FXPEventArray& GetEventArray()
	{
		static auto EventArrayOffset = FindOffsetStruct("/Script/FortniteGame.FortPlayerControllerAthenaXPComponent", "EventArray");
		return *(FXPEventArray*)(__int64(this) + EventArrayOffset);
	}

	FAthenaLevelInfo& GetCachedLevelInfo()
	{
		static auto CachedLevelInfoOffset = FindOffsetStruct("/Script/FortniteGame.FortPlayerControllerAthenaXPComponent", "CachedLevelInfo");
		return *(FAthenaLevelInfo*)(__int64(this) + CachedLevelInfoOffset);
	}

	void OnProfileUpdated()
	{
		static auto fn = FindObject<UFunction>("/Script/FortniteGame.FortPlayerControllerAthenaXPComponent.OnProfileUpdated");
		this->ProcessEvent(fn, nullptr);
	}

	void HighPrioXPEvent(const FXPEventEntry& HighPrioXPEvent)
	{
		static auto fn = FindObject<UFunction>("/Script/FortniteGame.FortPlayerControllerAthenaXPComponent.HighPrioXPEvent");

		struct
		{
			struct FXPEventEntry               HighPrioXPEvent;
		}params{ HighPrioXPEvent };

		this->ProcessEvent(fn, &params);
	}

	void OnXpEvent(FXPEventInfo& XPEvent)
	{
		static auto fn = FindObject<UFunction>("/Script/FortniteGame.FortPlayerControllerAthenaXPComponent.OnXpEvent");
		this->ProcessEvent(fn, &XPEvent);
	}

	void OnXPEvent(FXPEventInfo& XPEvent)
	{
		static auto fn = FindObject<UFunction>("/Script/FortniteGame.FortPlayerControllerAthenaXPComponent.OnXPEvent");
		this->ProcessEvent(fn, &XPEvent);
	}

	void OnXpUpdated(int32 InCombatXp, int32 InServivalXp, int32 InBonusMedalXp, int32 InChallengeXp, int32 InMatchXp, int32 InTotalXp)
	{
		static auto fn = FindObject<UFunction>("/Script/FortniteGame.FortPlayerControllerAthenaXPComponent.OnXpUpdated");

		struct
		{
			int32                              InCombatXp;                                                      // (Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
			int32                              InServivalXp;                                                    // (Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
			int32                              InBonusMedalXp;                                                  // (Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
			int32                              InChallengeXp;                                                   // (Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
			int32                              InMatchXp;                                                       // (Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
			int32                              InTotalXp;                                                       // (Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

		}params{ InCombatXp , InServivalXp , InBonusMedalXp , InChallengeXp , InMatchXp , InTotalXp };

		this->ProcessEvent(fn, &params);
	}

	void OnInMatchProfileUpdate(int64 ProfileRevision)
	{
		static auto fn = FindObject<UFunction>("/Script/FortniteGame.FortPlayerControllerAthenaXPComponent.OnInMatchProfileUpdate");

		struct
		{
			int64                              ProfileRevision;
		}params{ ProfileRevision };

		this->ProcessEvent(fn, &params);
	}

	void OnRep_bRegisteredWithQuestManager()
	{
		static auto fn = FindObject<UFunction>("/Script/FortniteGame.FortPlayerControllerAthenaXPComponent.OnRep_bRegisteredWithQuestManager");
		this->ProcessEvent(fn, nullptr);
	}

	void ClientMedalsRecived(TArray<FAthenaAccolades>& Medals)
	{
		static auto fn = FindObject<UFunction>("/Script/FortniteGame.FortPlayerControllerAthenaXPComponent.ClientMedalsRecived");

		struct
		{
			TArray<FAthenaAccolades>    Medals;
		}params{ Medals };

		this->ProcessEvent(fn, &params);
	}
};

enum class EFortWeaponUpgradeCosts : uint8_t
{
	NotSet = 0,
	WoodUncommon = 1,
	WoodRare = 2,
	WoodVeryRare = 3,
	WoodSuperRare = 4,
	MetalUncommon = 5,
	MetalRare = 6,
	MetalVeryRare = 7,
	MetalSuperRare = 8,
	BrickUncommon = 9,
	BrickRare = 10,
	BrickVeryRare = 11,
	BrickSuperRare = 12,
	HorizontalWoodCommon = 13,
	HorizontalWoodUncommon = 14,
	HorizontalWoodRare = 15,
	HorizontalWoodVeryRare = 16,
	HorizontalWoodSuperRare = 17,
	HorizontalMetalCommon = 18,
	HorizontalMetalUncommon = 19,
	HorizontalMetalRare = 20,
	HorizontalMetalVeryRare = 21,
	HorizontalMetalSuperRare = 22,
	HorizontalBrickCommon = 23,
	HorizontalBrickUncommon = 24,
	HorizontalBrickRare = 25,
	HorizontalBrickVeryRare = 26,
	HorizontalBrickSuperRare = 27,
	EFortWeaponUpgradeCosts_MAX = 28,
};

enum class EFortWeaponUpgradeDirection : uint8
{
	NotSet = 0,
	Vertical = 1,
	Horizontal = 2,
	EFortWeaponUpgradeDirection_MAX = 3,
};

enum class EInteractionBeingAttempted : uint8
{
	FirstInteraction = 0,
	SecondInteraction = 1,
	AllInteraction = 2,
	EInteractionBeingAttempted_MAX = 3,
};

class AFortPlayerController : public APlayerController
{
public:
	static inline void (*ClientOnPawnDiedOriginal)(AFortPlayerController* PlayerController, void* DeathReport);
	static inline void (*ServerCreateBuildingActorOriginal)(UObject* Context, FFrame* Stack, void* Ret);
	static inline void (*ServerAttemptInteractOriginal)(UObject* Context, FFrame* Stack, void* Ret);
	static inline void (*ServerEditBuildingActorOriginal)(UObject* Context, FFrame& Stack, void* Ret);
	static inline void (*DropSpecificItemOriginal)(UObject* Context, FFrame& Stack, void* Ret);
	static inline AActor* (*SpawnToyInstanceOriginal)(UObject* Context, FFrame* Stack, AActor** Ret);
	static inline void (*ServerLoadingScreenDroppedOriginal)(UObject* Context, FFrame* Stack, void* Ret);
	static inline void (*ServerAttemptAircraftJumpOriginal)(AFortPlayerController* PC, FRotator ClientRotation);

	void ClientReportDamagedResourceBuilding(ABuildingSMActor* BuildingSMActor, EFortResourceType PotentialResourceType, int PotentialResourceCount, bool bDestroyed, bool bJustHitWeakspot);

	void ClientEquipItem(FGuid& ItemGuid, bool bForceExecution)
	{
		static auto ClientEquipItemFn = FindObject<UFunction>("/Script/FortniteGame.FortPlayerController.ClientEquipItem");

		struct
		{
			FGuid							   ItemGuid;
			bool                               bForceExecution;
		}params{ ItemGuid , bForceExecution };

		this->ProcessEvent(ClientEquipItemFn, &params);
	}

	UFortPlayerControllerAthenaXPComponent* GetXPComponent()
	{
		static auto XPComponentOffset = FindOffsetStruct("/Script/FortniteGame.FortPlayerControllerAthena", "XPComponent");
		return *(UFortPlayerControllerAthenaXPComponent**)(__int64(this) + XPComponentOffset);
	}

	AFortInventory*& GetWorldInventory()
	{
		static auto WorldInventoryOffset = GetOffset("WorldInventory");
		return Get<AFortInventory*>(WorldInventoryOffset);
	}

	AFortPawn*& GetMyFortPawn() // AFortPlayerPawn
	{
		static auto MyFortPawnOffset = GetOffset("MyFortPawn");
		return Get<AFortPawn*>(MyFortPawnOffset);
	}

	int GetCosmeticLoadoutOffset()
	{
		static auto CosmeticLoadoutPCOffset = this->GetOffset("CosmeticLoadoutPC", false);

		if (CosmeticLoadoutPCOffset == -1)
			CosmeticLoadoutPCOffset = this->GetOffset("CustomizationLoadout", false);

		if (CosmeticLoadoutPCOffset == -1)
			return -1;

		return CosmeticLoadoutPCOffset;
	}

	FFortAthenaLoadout* GetCosmeticLoadout()
	{
		static auto CosmeticLoadoutPCOffset = GetCosmeticLoadoutOffset();
		auto CosmeticLoadout = this->GetPtr<FFortAthenaLoadout>(CosmeticLoadoutPCOffset);

		return CosmeticLoadout;
	}

	UFortItem* AddPickaxeToInventory()
	{
		auto CosmeticLoadout = GetCosmeticLoadout();
		auto CosmeticLoadoutPickaxe = CosmeticLoadout ? CosmeticLoadout->GetPickaxe() : nullptr;
	
		static auto WeaponDefinitionOffset = FindOffsetStruct("/Script/FortniteGame.AthenaPickaxeItemDefinition", "WeaponDefinition");

		auto PickaxeDefinition = CosmeticLoadoutPickaxe ? CosmeticLoadoutPickaxe->Get<UFortItemDefinition*>(WeaponDefinitionOffset)
			: FindObject<UFortItemDefinition>(L"/Game/Athena/Items/Weapons/WID_Harvest_Pickaxe_Athena_C_T01.WID_Harvest_Pickaxe_Athena_C_T01");

		auto WorldInventory = GetWorldInventory();

		if (!WorldInventory || WorldInventory->GetPickaxeInstance())
			return nullptr;

		auto NewAndModifiedInstances = WorldInventory->AddItem(PickaxeDefinition, nullptr);
		WorldInventory->Update();

		return NewAndModifiedInstances.first.size() > 0 ? NewAndModifiedInstances.first[0] : nullptr;
	}

	TSet<FGuid>& GetGadgetTrackedAttributeItemInstanceIds() // actually in zone
	{
		static auto GadgetTrackedAttributeItemInstanceIdsOffset = GetOffset("GadgetTrackedAttributeItemInstanceIds");
		return Get<TSet<FGuid>>(GadgetTrackedAttributeItemInstanceIdsOffset);
	}

	bool IsPlayingEmote()
	{
		static auto IsPlayingEmoteFn = FindObject<UFunction>("/Script/FortniteGame.FortPlayerController.IsPlayingEmote");
		bool Ret;
		this->ProcessEvent(IsPlayingEmoteFn, &Ret);
		return Ret;
	}

	bool& ShouldTryPickupSwap()
	{
		static auto bTryPickupSwapOffset = GetOffset("bTryPickupSwap");
		return Get<bool>(bTryPickupSwapOffset);
	}
	
	bool HasTryPickupSwap()
	{
		static auto bTryPickupSwapOffset = GetOffset("bTryPickupSwap", false);
		return bTryPickupSwapOffset != -1;
	}

	void ClientEquipItem(const FGuid& ItemGuid, bool bForceExecution);

	bool DoesBuildFree();
	void DropAllItems(const std::vector<UFortItemDefinition*>& IgnoreItemDefs, bool bIgnoreSecondaryQuickbar = false, bool bRemoveIfNotDroppable = false, bool RemovePickaxe = false);
	void ApplyCosmeticLoadout();

	static void ServerSuicideHook(AFortPlayerController* PlayerController);

	static void ServerLoadingScreenDroppedHook(UObject* Context, FFrame* Stack, void* Ret);
	static void ServerRepairBuildingActorHook(AFortPlayerController* PlayerController, ABuildingSMActor* BuildingActorToRepair);
	static void ServerExecuteInventoryItemHook(AFortPlayerController* PlayerController, FGuid ItemGuid);
	static void ServerAttemptInteractHook(UObject* Context, FFrame* Stack, void* Ret);

	static void ServerAttemptAircraftJumpHook(AFortPlayerController* PC, FRotator ClientRotation);
	// static void ServerCreateBuildingActorHook(AFortPlayerController* PlayerController, FCreateBuildingActorData CreateBuildingData);
	static void ServerCreateBuildingActorHook(UObject* Context, FFrame* Stack, void* Ret);
	static AActor* SpawnToyInstanceHook(UObject* Context, FFrame* Stack, AActor** Ret);
	static void DropSpecificItemHook(UObject* Context, FFrame& Stack, void* Ret);

	static void ServerDropAllItemsHook(AFortPlayerController* PlayerController, UFortItemDefinition* IgnoreItemDef);

	static void ServerAttemptInventoryDropHook(AFortPlayerController* PlayerController, FGuid ItemGuid, int Count);
	static void ServerPlayEmoteItemHook(AFortPlayerController* PlayerController, UObject* EmoteAsset);
	static void ClientOnPawnDiedHook(AFortPlayerController* PlayerController, void* DeathReport);

	static void ServerBeginEditingBuildingActorHook(AFortPlayerController* PlayerController, ABuildingSMActor* BuildingActorToEdit);
	// static void ServerEditBuildingActorHook(AFortPlayerController* PlayerController, ABuildingSMActor* BuildingActorToEdit, UClass* NewBuildingClass, int RotationIterations, char bMirrored);
	static void ServerEditBuildingActorHook(UObject* Context, FFrame& Stack, void* Ret);
	static void ServerEndEditingBuildingActorHook(AFortPlayerController* PlayerController, ABuildingSMActor* BuildingActorToStopEditing);

	static UClass* StaticClass()
	{
		static auto Class = FindObject<UClass>("/Script/FortniteGame.FortPlayerController");
		return Class;
	}
};
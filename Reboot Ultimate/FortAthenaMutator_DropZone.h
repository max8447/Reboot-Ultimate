#pragma once

#include "FortAthenaMutator.h"

#include "FortAthenaMutator_TDM.h"
#include "ActorComponent.h"

struct FPerkMutatorData
{
public:
	struct FGameplayTag                          PerkTag;                                           // 0x0(0x8)(Edit, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	struct FGameplayTag                          ShowPerkSelectTag;                                 // 0x8(0x8)(Edit, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	struct FGameplayTag                          PassivePerkTag;                                    // 0x10(0x8)(Edit, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	struct FGameplayTag                          ItemPerkTag;                                       // 0x18(0x8)(Edit, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	struct FGameplayTag                          FirstRollTag;                                      // 0x20(0x8)(Edit, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	struct FGameplayTag                          BlockRespawnTag;                                   // 0x28(0x8)(Edit, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	TSubclassOf<class UGameplayEffect>           PerkUnlockedGameplayEffectClass;                   // 0x30(0x8)(Edit, ZeroConstructor, IsPlainOldData, NoDestructor, Protected, UObjectWrapper, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	TSubclassOf<class UGameplayEffect>           ShowPerkSelectGameplayEffectClass;                 // 0x38(0x8)(Edit, ZeroConstructor, IsPlainOldData, NoDestructor, Protected, UObjectWrapper, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	TSubclassOf<class UGameplayEffect>           BlockRespawnGameplayEffectClass;                   // 0x40(0x8)(Edit, ZeroConstructor, IsPlainOldData, NoDestructor, Protected, UObjectWrapper, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	TSubclassOf<class UUserWidget>               PerkScreenIntroWidgetClass;                        // 0x48(0x8)(Edit, ZeroConstructor, IsPlainOldData, NoDestructor, Protected, UObjectWrapper, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	struct FScalableFloat                        StartingRerollCount;                               // 0x50(0x20)(Edit, Protected, NativeAccessSpecifierProtected)
	struct FScalableFloat                        RerollsToGivePerPerkUnlock;                        // 0x70(0x20)(Edit, Protected, NativeAccessSpecifierProtected)
	TMap<class FName, struct FGameplayTag>       FactionItemMapping;                                // 0x90(0x50)(Edit, ZeroConstructor, Protected, NativeAccessSpecifierProtected)
	bool                                         bShouldShowBackgroundImage;                        // 0xE0(0x1)(Edit, ZeroConstructor, IsPlainOldData, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	uint8                                        Pad_48C4[0x7];                                     // Fixing Size Of Struct [ Dumper-7 ]
};

struct FPerkItemSet
{
public:
	TArray<class UFortSpyTechItemDefinition*>    Items;                                             // 0x0(0x10)(ZeroConstructor, NativeAccessSpecifierPublic)
	float                                        Time;                                              // 0x10(0x4)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                        Pad_4C89[0x4];                                     // Fixing Size Of Struct [ Dumper-7 ]
};

struct FRoundTechDataCache
{
public:
	TArray<struct FFutureTechData>               FuturePerks;                                       // 0x0(0x10)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, NativeAccessSpecifierPublic)
	int32                                        LevelAtRoundStart;                                 // 0x10(0x4)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	int32                                        FactionXPAtRoundStart;                             // 0x14(0x4)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                         bDataReady;                                        // 0x18(0x1)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                        Pad_4C82[0x3];                                     // Fixing Size After Last Property  [ Dumper-7 ]
	int32                                        MaxCalandarLevel;                                  // 0x1C(0x4)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	int32                                        MaxLevel;                                          // 0x20(0x4)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                        Pad_4C83[0x4];                                     // Fixing Size Of Struct [ Dumper-7 ]
};

class AFortAthenaMutator_SpyRumble : public AFortAthenaMutator_TDM
{
public:
	static UClass* StaticClass()
	{
		static auto Class = FindObject<UClass>("/Script/FortniteGame.AFortAthenaMutator_SpyRumble");
		return Class;
	}
};

class AFortAthenaMutator_PerkSystemMutator : public AFortAthenaMutator
{
public:
	FPerkMutatorData& GetMutatorData()
	{
		static auto MutatorDataOffset = FindOffsetStruct("/Script/FortniteGame.FortAthenaMutator_PerkSystemMutator", "MutatorData");
		return *(FPerkMutatorData*)(__int64(this) + MutatorDataOffset);
	}

	static UClass* StaticClass()
	{
		static auto Class = FindObject<UClass>("/Script/FortniteGame.AFortAthenaMutator_SpyRumble");
		return Class;
	}
};

class UFortControllerComponent_PerkSystem : public UActorComponent // UFortControllerComponent
{
public:
	float& GetServerTimeToRelease()
	{
		static auto ServerTimeToReleaseOffset = FindOffsetStruct("/Script/FortniteGame.FortControllerComponent_PerkSystem", "ServerTimeToRelease");
		return *(float*)(__int64(this) + ServerTimeToReleaseOffset);
	}

	FPerkMutatorData& GetMutatorData()
	{
		static auto MutatorDataOffset = FindOffsetStruct("/Script/FortniteGame.FortControllerComponent_PerkSystem", "MutatorData");
		return *(FPerkMutatorData*)(__int64(this) + MutatorDataOffset);
	}


	FGameplayTag GetCachedFactionTag()
	{
		static auto CachedFactionTagOffset = FindOffsetStruct("/Script/FortniteGame.FortAthenaMutator_PerkSystemMutator", "CachedFactionTag");
		return *(FGameplayTag*)(__int64(this) + CachedFactionTagOffset);
	}

	TArray<FPerkItemSet> GetPerkSelection()
	{
		static auto PerkSelectionOffset = FindOffsetStruct("/Script/FortniteGame.FortAthenaMutator_PerkSystemMutator", "PerkSelection");
		return *(TArray<FPerkItemSet>*)(__int64(this) + PerkSelectionOffset);
	}

	int32& GetRerollCount()
	{
		static auto RerollCountOffset = FindOffsetStruct("/Script/FortniteGame.FortAthenaMutator_PerkSystemMutator", "RerollCount");
		return *(int32*)(__int64(this) + RerollCountOffset);
	}

	TArray<UFortSpyTechItemDefinition*> GetSpyTechArray()
	{
		static auto SpyTechArrayOffset = FindOffsetStruct("/Script/FortniteGame.FortAthenaMutator_PerkSystemMutator", "SpyTechArray");
		return *(TArray<UFortSpyTechItemDefinition*>*)(__int64(this) + SpyTechArrayOffset);
	}

	TArray<UFortSpyTechItemDefinition*> GetDefaultPerks()
	{
		static auto DefaultPerksOffset = FindOffsetStruct("/Script/FortniteGame.FortAthenaMutator_PerkSystemMutator", "DefaultPerks");
		return *(TArray<UFortSpyTechItemDefinition*>*)(__int64(this) + DefaultPerksOffset);
	}

	TArray<UFortSpyTechItemDefinition*> GetAllSelectedPerks()
	{
		static auto AllSelectedPerksOffset = FindOffsetStruct("/Script/FortniteGame.FortAthenaMutator_PerkSystemMutator", "AllSelectedPerks");
		return *(TArray<UFortSpyTechItemDefinition*>*)(__int64(this) + AllSelectedPerksOffset);
	}

	FRoundTechDataCache& GetRoundStartCache()
	{
		static auto RoundStartCacheOffset = FindOffsetStruct("/Script/FortniteGame.FortAthenaMutator_PerkSystemMutator", "RoundStartCache");
		return *(FRoundTechDataCache*)(__int64(this) + RoundStartCacheOffset);
	}

	void OnRep_PerkSelection()
	{
		static auto fn = FindObject<UFunction>("/Script/FortniteGame.FortControllerComponent_PerkSystem.OnRep_PerkSelection");
		this->ProcessEvent(fn);
	}

	void OnRep_SpyTechArray()
	{
		static auto fn = FindObject<UFunction>("/Script/FortniteGame.FortControllerComponent_PerkSystem.OnRep_SpyTechArray");
		this->ProcessEvent(fn);
	}

	void OnRep_RerollCount()
	{
		static auto fn = FindObject<UFunction>("/Script/FortniteGame.FortControllerComponent_PerkSystem.OnRep_RerollCount");
		this->ProcessEvent(fn);
	}

	void OnRep_ServerTimeToRelease()
	{
		static auto fn = FindObject<UFunction>("/Script/FortniteGame.FortControllerComponent_PerkSystem.OnRep_ServerTimeToRelease");
		this->ProcessEvent(fn);
	}

	void OnRep_AllSelectedPerks()
	{
		static auto fn = FindObject<UFunction>("/Script/FortniteGame.FortControllerComponent_PerkSystem.OnRep_AllSelectedPerks");
		this->ProcessEvent(fn);
	}

	static UClass* StaticClass()
	{
		static auto Class = FindObject<UClass>("/Script/FortniteGame.FortControllerComponent_PerkSystem");
		return Class;
	}
};
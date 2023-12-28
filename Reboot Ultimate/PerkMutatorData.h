#pragma once

#include "GameplayTag.h"
#include "TSubclassOf.h"
#include "Name.h"
#include "GameplayEffect.h"
#include "UserWidget.h"

struct FPerkMutatorData
{
public:
	FGameplayTag                          PerkTag;                                           // 0x0(0x8)(Edit, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	FGameplayTag                          ShowPerkSelectTag;                                 // 0x8(0x8)(Edit, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	FGameplayTag                          PassivePerkTag;                                    // 0x10(0x8)(Edit, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	FGameplayTag                          ItemPerkTag;                                       // 0x18(0x8)(Edit, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	FGameplayTag                          FirstRollTag;                                      // 0x20(0x8)(Edit, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	FGameplayTag                          BlockRespawnTag;                                   // 0x28(0x8)(Edit, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	TSubclassOf<UGameplayEffect>           PerkUnlockedGameplayEffectClass;                   // 0x30(0x8)(Edit, ZeroConstructor, IsPlainOldData, NoDestructor, Protected, UObjectWrapper, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	TSubclassOf<UGameplayEffect>           ShowPerkSelectGameplayEffectClass;                 // 0x38(0x8)(Edit, ZeroConstructor, IsPlainOldData, NoDestructor, Protected, UObjectWrapper, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	TSubclassOf<UGameplayEffect>           BlockRespawnGameplayEffectClass;                   // 0x40(0x8)(Edit, ZeroConstructor, IsPlainOldData, NoDestructor, Protected, UObjectWrapper, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	TSubclassOf<UUserWidget>               PerkScreenIntroWidgetClass;                        // 0x48(0x8)(Edit, ZeroConstructor, IsPlainOldData, NoDestructor, Protected, UObjectWrapper, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	FScalableFloat                        StartingRerollCount;                               // 0x50(0x20)(Edit, Protected, NativeAccessSpecifierProtected)
	FScalableFloat                        RerollsToGivePerPerkUnlock;                        // 0x70(0x20)(Edit, Protected, NativeAccessSpecifierProtected)
	TMap<FName, FGameplayTag>       FactionItemMapping;                                // 0x90(0x50)(Edit, ZeroConstructor, Protected, NativeAccessSpecifierProtected)
	bool                                         bShouldShowBackgroundImage;                        // 0xE0(0x1)(Edit, ZeroConstructor, IsPlainOldData, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	uint8                                        Pad_48C4[0x7];                                     // Fixing Size Of Struct [ Dumper-7 ]
};
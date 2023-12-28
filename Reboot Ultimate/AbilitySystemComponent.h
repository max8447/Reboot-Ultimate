#pragma once

#include "Object.h"
#include "GameplayAbilitySpec.h"
#include "AttributeSet.h"
#include "PredictionKey.h"
#include "GameplayEffectContextHandle.h"
#include "ActiveGameplayEffectHandle.h"
#include "GameplayAbilitySpecContainer.h"

struct PadHex10 { char Pad[0x10]; };
struct PadHex18 { char Pad[0x18]; };
struct PadHexA8 { char Pad[0xA8]; };
struct PadHexB0 { char Pad[0xB0]; };

// using FPredictionKey = PadHex18;
// using FGameplayEventData = PadHexA8;

// using FPredictionKey = PadHex10; 
using FGameplayEventData = PadHexB0;

// using FGameplayEventData = __int64;

class UAbilitySystemComponent : public UObject
{
public:
	static inline FGameplayAbilitySpecHandle* (*GiveAbilityOriginal)(UAbilitySystemComponent*, FGameplayAbilitySpecHandle*, __int64 inSpec);
	static inline bool (*InternalTryActivateAbilityOriginal)(UAbilitySystemComponent*, FGameplayAbilitySpecHandle Handle, PadHex10 InPredictionKey, UObject** OutInstancedAbility, void* OnGameplayAbilityEndedDelegate, const FGameplayEventData* TriggerEventData);
	static inline bool (*InternalTryActivateAbilityOriginal2)(UAbilitySystemComponent*, FGameplayAbilitySpecHandle Handle, PadHex18 InPredictionKey, UObject** OutInstancedAbility, void* OnGameplayAbilityEndedDelegate, const FGameplayEventData* TriggerEventData);

	void ClientActivateAbilityFailed(FGameplayAbilitySpecHandle AbilityToActivate, int16_t PredictionKey)
	{
		struct { FGameplayAbilitySpecHandle AbilityToActivate; int16_t PredictionKey; } UAbilitySystemComponent_ClientActivateAbilityFailed_Params{ AbilityToActivate, PredictionKey };
		static auto fn = FindObject<UFunction>(L"/Script/GameplayAbilities.AbilitySystemComponent.ClientActivateAbilityFailed");

		this->ProcessEvent(fn, &UAbilitySystemComponent_ClientActivateAbilityFailed_Params);
	}

	TArray<UAttributeSet*>& GetSpawnedAttributes()
	{
		static auto SpawnedAttributesOffset = GetOffset("SpawnedAttributes");
		return Get<TArray<UAttributeSet*>>(SpawnedAttributesOffset);
	}

	FGameplayAbilitySpecContainer* GetActivatableAbilities()
	{
		static auto ActivatableAbilitiesOffset = this->GetOffset("ActivatableAbilities");
		return GetPtr<FGameplayAbilitySpecContainer>(ActivatableAbilitiesOffset);
	}

	UAttributeSet* AddDefaultSubobjectSet(UAttributeSet* Subobject)
	{
		GetSpawnedAttributes().Add(Subobject);
		return Subobject;
	}

	void ServerEndAbility(FGameplayAbilitySpecHandle AbilityToEnd, FGameplayAbilityActivationInfo* ActivationInfo, FPredictionKey* PredictionKey);
	void ClientEndAbility(FGameplayAbilitySpecHandle AbilityToEnd, FGameplayAbilityActivationInfo* ActivationInfo);
	void ClientCancelAbility(FGameplayAbilitySpecHandle AbilityToCancel, FGameplayAbilityActivationInfo* ActivationInfo);
	bool HasAbility(UObject* DefaultAbility);
	FActiveGameplayEffectHandle ApplyGameplayEffectToSelf(UClass* GameplayEffectClass, float Level, const FGameplayEffectContextHandle& EffectContext = FGameplayEffectContextHandle());
	// FGameplayEffectContextHandle MakeEffectContext();
	void RemoveActiveGameplayEffectBySourceEffect(UClass* GEClass, int StacksToRemove, UAbilitySystemComponent* Instigator);
	void ConsumeAllReplicatedData(FGameplayAbilitySpecHandle AbilityHandle, FPredictionKey* AbilityOriginalPredictionKey);
	FGameplayAbilitySpecHandle GiveAbilityEasy(UClass* AbilityClass, UObject* SourceObject = nullptr, bool bDoNotRegive = true);
	FGameplayAbilitySpec* FindAbilitySpecFromHandle(FGameplayAbilitySpecHandle Handle);
	void RemoveActiveGameplayEffectBySourceEffect(UClass* GameplayEffect, UAbilitySystemComponent* InstigatorAbilitySystemComponent, int StacksToRemove);
	void ClearAbility(const FGameplayAbilitySpecHandle& Handle);

	static void InternalServerTryActivateAbilityHook(UAbilitySystemComponent* AbilitySystemComponent, FGameplayAbilitySpecHandle Handle, bool InputPressed, const FPredictionKey* PredictionKey, const FGameplayEventData* TriggerEventData);
};

void LoopSpecs(UAbilitySystemComponent* AbilitySystemComponent, std::function<void(FGameplayAbilitySpec*)> func);
#include "FortWeaponItemDefinition.h"

#include "DataTable.h"
#include "SoftObjectPtr.h"
#include "FortPlayerControllerAthena.h"

int UFortWeaponItemDefinition::GetClipSize()
{
	static auto WeaponStatHandleOffset = GetOffset("WeaponStatHandle");
	auto& WeaponStatHandle = Get<FDataTableRowHandle>(WeaponStatHandleOffset);

	auto Table = WeaponStatHandle.DataTable;

	if (!Table)
		return 0;

	auto& RowMap = Table->GetRowMap();

	void* Row = nullptr;

	for (int i = 0; i < RowMap.Pairs.Elements.Data.Num(); ++i)
	{
		auto& Pair = RowMap.Pairs.Elements.Data.at(i).ElementData.Value;

		if (Pair.Key() == WeaponStatHandle.RowName)
		{
			Row = Pair.Value();
			break;
		}
	}

	if (!Row)
		return 0;

	static auto ClipSizeOffset = FindOffsetStruct("/Script/FortniteGame.FortBaseWeaponStats", "ClipSize");
	return *(int*)(__int64(Row) + ClipSizeOffset);
}

UFortWorldItemDefinition* UFortWeaponItemDefinition::GetAmmoData()
{
	static auto AmmoDataOffset = GetOffset("AmmoData");
	auto AmmoData = GetPtr<TSoftObjectPtr<UFortWorldItemDefinition>>(AmmoDataOffset);
	return AmmoData->Get();
}

void UFortWeaponItemDefinition::RemoveGrantedWeaponAbilities(AFortPlayerControllerAthena* PlayerController)
{
	if (Fortnite_Version < 14)
		return;

	auto EquippedAbilitySet = this->GetEquippedAbilitySet();
	auto EquippedAbilities = this->GetEquippedAbilities();

	auto PlayerState = PlayerController->GetPlayerStateAthena();
	auto AbilitySystemComponent = PlayerState->GetAbilitySystemComponent();

	if (EquippedAbilitySet.Get())
	{
		auto GrantedGameplayEffects = EquippedAbilitySet.Get()->GetGrantedGameplayEffects();
		auto GameplayAbilities = EquippedAbilitySet.Get()->GetGameplayAbilities();

		for (int i = 0; i < GrantedGameplayEffects->Num(); i++)
		{
			auto& EffectToGrant = GrantedGameplayEffects->at(i, FGameplayEffectApplicationInfoHard::GetStructSize());

			if (!EffectToGrant.GameplayEffect)
				continue;

			AbilitySystemComponent->RemoveActiveGameplayEffectBySourceEffect(EffectToGrant.GameplayEffect, 1, AbilitySystemComponent);
		}

		for (int i = 0; i < GameplayAbilities->Num(); i++)
		{
			auto Ability = GameplayAbilities->at(i);
			FGameplayAbilitySpec* AbilitySpec = nullptr;

			auto CompareAbilities = [&AbilitySpec, &Ability](FGameplayAbilitySpec* Spec)
				{
					auto CurrentAbility = Spec->GetAbility();

					// LOG_INFO(LogDev, "CurrentAbility->ClassPrivate->GetName(): {}, Ability->GetName(): {}", CurrentAbility->ClassPrivate->GetName(), Ability->GetName());

					if (CurrentAbility->ClassPrivate->GetName() == Ability->GetName())
					{
						AbilitySpec = Spec;
					}
				};

			LoopSpecs(AbilitySystemComponent, CompareAbilities);

			if (!AbilitySpec)
				continue;

			LOG_INFO(LogDev, "Removing Ability {}", Ability->GetName());

			AbilitySystemComponent->ClientCancelAbility(AbilitySpec->GetHandle(), AbilitySpec->GetActivationInfo());
			AbilitySystemComponent->ClientEndAbility(AbilitySpec->GetHandle(), AbilitySpec->GetActivationInfo());
			AbilitySystemComponent->ServerEndAbility(AbilitySpec->GetHandle(), AbilitySpec->GetActivationInfo(), nullptr);
			AbilitySystemComponent->ClearAbility(AbilitySpec->GetHandle());
		}
	}

	for (int i = 0; i < EquippedAbilities.Num(); i++)
	{
		auto Ability = EquippedAbilities.at(i).Get();
		FGameplayAbilitySpec* AbilitySpec = nullptr;

		auto CompareAbilities = [&AbilitySpec, &Ability](FGameplayAbilitySpec* Spec)
		{
			auto CurrentAbility = Spec->GetAbility();

			// LOG_INFO(LogDev, "CurrentAbility->ClassPrivate->GetName(): {}, Ability->GetName(): {}", CurrentAbility->ClassPrivate->GetName(), Ability->GetName());

			if (CurrentAbility->ClassPrivate->GetName() == Ability->GetName())
			{
				AbilitySpec = Spec;
			}
		};

		LoopSpecs(AbilitySystemComponent, CompareAbilities);

		if (!AbilitySpec)
			continue;

		LOG_INFO(LogDev, "Removing Ability {}", Ability->GetName());

		AbilitySystemComponent->ClientCancelAbility(AbilitySpec->GetHandle(), AbilitySpec->GetActivationInfo());
		AbilitySystemComponent->ClientEndAbility(AbilitySpec->GetHandle(), AbilitySpec->GetActivationInfo());
		AbilitySystemComponent->ServerEndAbility(AbilitySpec->GetHandle(), AbilitySpec->GetActivationInfo(), nullptr);
		AbilitySystemComponent->ClearAbility(AbilitySpec->GetHandle());
	}
}

void UFortWeaponItemDefinition::GiveGrantedWeaponAbilities(AFortPlayerControllerAthena* PlayerController)
{
	if (Fortnite_Version < 14)
		return;

	auto EquippedAbilitySet = this->GetEquippedAbilitySet();
	auto EquippedAbilities = this->GetEquippedAbilities();

	auto PlayerState = PlayerController->GetPlayerStateAthena();
	auto AbilitySystemComponent = PlayerState->GetAbilitySystemComponent();
	
	if (EquippedAbilitySet.Get())
	{
		auto GrantedGameplayEffects = EquippedAbilitySet.Get()->GetGrantedGameplayEffects();
		auto GameplayAbilities = EquippedAbilitySet.Get()->GetGameplayAbilities();

		for (int i = 0; i < GrantedGameplayEffects->Num(); i++)
		{
			auto& EffectToGrant = GrantedGameplayEffects->at(i, FGameplayEffectApplicationInfoHard::GetStructSize());

			if (!EffectToGrant.GameplayEffect)
				continue;

			FGameplayEffectContextHandle EffectContext{};
			AbilitySystemComponent->ApplyGameplayEffectToSelf(EffectToGrant.GameplayEffect, EffectToGrant.Level, EffectContext);
		}

		for (int i = 0; i < GameplayAbilities->Num(); i++)
		{
			UClass* AbilityClass = (UClass*)GameplayAbilities->At(i);

			if (!AbilityClass)
				continue;

			LOG_INFO(LogDev, "Giving AbilityClass {}", AbilityClass->GetName());

			AbilitySystemComponent->GiveAbilityEasy(AbilityClass);
		}
	}

	for (int i = 0; i < EquippedAbilities.Num(); i++)
	{
		UClass* AbilityClass = (UClass*)EquippedAbilities.At(i).Get();

		if (!AbilityClass)
			continue;

		LOG_INFO(LogDev, "Giving AbilityClass {}", AbilityClass->GetName());

		AbilitySystemComponent->GiveAbilityEasy(AbilityClass);
	}
}

UClass* UFortWeaponItemDefinition::StaticClass()
{
	static auto Class = FindObject<UClass>(L"/Script/FortniteGame.FortWeaponItemDefinition");
	return Class;
}
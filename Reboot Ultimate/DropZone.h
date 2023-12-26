#pragma once

#include "FortAthenaMutator_DropZone.h"
#include "FortPlayerControllerAthena.h"
#include "AbilitySystemComponent.h"

enum EPerkSystemSelections : unsigned int
{
	First = 0,
	Second = 1,
	Third = 2,
	CloseError = 500u,
	TimeoutError = 501u,
	ReRoll = 11u,
	StartSafetyTimer = 502u,
};

static bool (*ShowPerkSelect)(AFortAthenaMutator_PerkSystemMutator* Mutator, void* a2) = decltype(ShowPerkSelect)(__int64(GetModuleHandleW(0)) + 0x1A934C0);
LPVOID UnlockPerkForPlayerAddr = (LPVOID)(__int64(GetModuleHandleW(0)) + 0x1A962E0);
LPVOID OnMutatorItemSelectedAddr = (LPVOID)(__int64(GetModuleHandleW(0)) + 0x1A8CAD0);

void (*UnlockPerkForPlayerOG)(AFortAthenaMutator_PerkSystemMutator* PerkSystemMutator, AFortPlayerControllerAthena* a2, int a3, char a4);
void UnlockPerkForPlayer(AFortAthenaMutator_PerkSystemMutator* PerkSystemMutator, AFortPlayerControllerAthena* PC, int PerkAmount, char a4)
{
	// Log("UnlockPerkForPlayer called!");
	// cout << __int64(_ReturnAddress()) - __int64(GetModuleHandleW(0)) << endl;

	UAbilitySystemComponent* AbilitySystemComponent = Cast<AFortPlayerStateAthena>(PC->GetPlayerState())->GetAbilitySystemComponent();
	UFortControllerComponent_PerkSystem* Comp = (UFortControllerComponent_PerkSystem*)PC->GetComponentByClass(UFortControllerComponent_PerkSystem::StaticClass());

	UnlockPerkForPlayerOG(PerkSystemMutator, PC, PerkAmount, a4);

	for (size_t i = 0; i < Comp->GetPerkSelection().Num(); i++)
	{
		Comp->GetPerkSelection()[i].Items.Free();
		Comp->GetPerkSelection()[i].Items.Add(Comp->GetSpyTechArray()[i]);
		Comp->GetPerkSelection()[i].Items.Add(Comp->GetSpyTechArray()[i]);
	}
	Comp->GetRoundStartCache().bDataReady = true;
	Comp->OnRep_PerkSelection();

	if (Cast<AFortPlayerStateAthena>(PC->GetPlayerState())->IsInAircraft())
	{
		Comp->GetServerTimeToRelease() = UGameplayStatics::GetTimeSeconds(GetWorld()) + 30;
		Comp->OnRep_ServerTimeToRelease();
	}

	AbilitySystemComponent->ApplyGameplayEffectToSelf(PerkSystemMutator->GetMutatorData().PerkUnlockedGameplayEffectClass, 1, FGameplayEffectContextHandle());

	if (Cast<AFortPlayerStateAthena>(PC->GetPlayerState())->IsInAircraft())
		ShowPerkSelect(PerkSystemMutator, PC);
}

void (*OnMutatorItemSelectedOG)(AFortAthenaMutator_PerkSystemMutator* Mutator, AFortPlayerControllerAthena* PC, EPerkSystemSelections EnumIdk);
void OnMutatorItemSelected(AFortAthenaMutator_PerkSystemMutator* Mutator, AFortPlayerControllerAthena* PC, EPerkSystemSelections EnumIdk)
{
	// cout << "OnMutatorItemSelected called " << (uintptr_t)EnumIdk << endl;
	// cout << __int64(_ReturnAddress()) - __int64(GetModuleHandleW(0)) << endl;

	EnumIdk = EPerkSystemSelections::First;

	UFortControllerComponent_PerkSystem* Comp = (UFortControllerComponent_PerkSystem*)PC->GetComponentByClass(UFortControllerComponent_PerkSystem::StaticClass());
	UAbilitySystemComponent* AbilitySystemComponent = Cast<AFortPlayerStateAthena>(PC->GetPlayerState())->GetAbilitySystemComponent();

	switch (EnumIdk)
	{
	case EPerkSystemSelections::CloseError:
	case EPerkSystemSelections::TimeoutError:
		OnMutatorItemSelectedOG(Mutator, PC, EnumIdk);
		AbilitySystemComponent->RemoveActiveGameplayEffectBySourceEffect(Mutator->GetMutatorData().PerkUnlockedGameplayEffectClass, AbilitySystemComponent, 1);
		AbilitySystemComponent->RemoveActiveGameplayEffectBySourceEffect(Mutator->GetMutatorData().ShowPerkSelectGameplayEffectClass, AbilitySystemComponent, 1);

		Comp->GetAllSelectedPerks().Add(Comp->GetPerkSelection()[1].Items[0]);
		Comp->OnRep_AllSelectedPerks();
		break;
	case EPerkSystemSelections::ReRoll:
		for (size_t i = 0; i < Comp->GetPerkSelection().Num(); i++)
		{
			Comp->GetPerkSelection()[i].Items.Free();
			Comp->GetPerkSelection()[i].Items.Add(Comp->GetSpyTechArray()[0]);
			Comp->GetPerkSelection()[i].Items.Add(Comp->GetSpyTechArray()[i]);
		}
		Comp->GetRoundStartCache().bDataReady = true;
		Comp->OnRep_PerkSelection();
		OnMutatorItemSelectedOG(Mutator, PC, EnumIdk);
		break;
	case EPerkSystemSelections::StartSafetyTimer:
		OnMutatorItemSelectedOG(Mutator, PC, EnumIdk);
		// Log("idek");
		break;
	case EPerkSystemSelections::First:
	case EPerkSystemSelections::Second:
	case EPerkSystemSelections::Third:
		OnMutatorItemSelectedOG(Mutator, PC, EnumIdk);
		AbilitySystemComponent->RemoveActiveGameplayEffectBySourceEffect(Mutator->GetMutatorData().PerkUnlockedGameplayEffectClass, AbilitySystemComponent, 1);
		AbilitySystemComponent->RemoveActiveGameplayEffectBySourceEffect(Mutator->GetMutatorData().ShowPerkSelectGameplayEffectClass, AbilitySystemComponent, 1);

		Comp->GetAllSelectedPerks().Add(Comp->GetPerkSelection()[(uintptr_t)EnumIdk].Items[0]);
		Comp->OnRep_AllSelectedPerks();
		// Log("Selected perk " + to_string((uintptr_t)EnumIdk));
		break;
	default:
		OnMutatorItemSelectedOG(Mutator, PC, EnumIdk);
		// Log("default called");
		break;
	}
}
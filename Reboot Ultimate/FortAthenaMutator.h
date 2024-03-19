#pragma once

#include <functional>

#include "Actor.h"

#include "Stack.h"

#include "ScriptInterface.h"
#include "FortGameStateAthena.h"
#include "FortPlayerControllerAthena.h"
#include "GameplayStatics.h"

class AFortAthenaMutator : public AActor // AFortGameplayMutator
{
public:
	static UClass* StaticClass()
	{
		static auto Class = FindObject<UClass>(L"/Script/FortniteGame.FortAthenaMutator");
		return Class;
	}
};

static inline void LoopMutators(std::function<void(AFortAthenaMutator*)> Callback)
{
	auto AllMutators = UGameplayStatics::GetAllActorsOfClass(GetWorld(), AFortAthenaMutator::StaticClass());

	// LOG_INFO(LogDev, "AllMutators.Num(): {}", AllMutators.Num());

	for (int i = 0; i < AllMutators.Num(); i++)
	{
		Callback((AFortAthenaMutator*)AllMutators.at(i));
	}

	// LOG_INFO(LogGame, "Looped Mutators");

	AllMutators.Free();
}

template <typename MutatorType = AFortAthenaMutator>
static inline MutatorType* FindFirstMutator(UClass* MutatorClass = MutatorType::StaticClass())
{
	auto AllMutators = UGameplayStatics::GetAllActorsOfClass(GetWorld(), MutatorClass);
	auto FirstMutator = AllMutators.Num() >= 1 ? AllMutators.at(0) : nullptr;

	AllMutators.Free();

	return (MutatorType*)FirstMutator;
}
#pragma once

#include "FortAthenaMutator.h"
#include "FortWorldItemDefinition.h"
#include "GameplayTagContainer.h"

enum class EAshtonStoneType : uint8
{
	Purple = 0,
	Blue = 1,
	Red = 2,
	Orange = 3,
	Green = 4,
	Yellow = 5,
	MAX = 6,
};

enum class EAshtonStoneStateType : uint8
{
	NotSpawned = 0,
	Spawned = 1,
	Captured = 2,
	MAX = 3,
};

struct FAshtonStoneData
{
public:
	std::string GetStructName() { return "/Script/FortniteGame.AshtonStoneData"; }

	EAshtonStoneType GetStoneType()
	{
		return *GetStructOffset<EAshtonStoneType>(this, "StoneType");
	}

	UFortWorldItemDefinition* GetStoneItemDefinition()
	{
		return GetStructOffset<UFortWorldItemDefinition>(this, "StoneItemDefinition");
	}

	FGameplayTag& GetGameplayTag()
	{
		return *GetStructOffset<FGameplayTag>(this, "GameplayTag");
	}

	FGameplayTag& GetPickupTag()
	{
		return *GetStructOffset<FGameplayTag>(this, "PickupTag");
	}

	EAshtonStoneStateType& GetInitialStoneState()
	{
		return *GetStructOffset<EAshtonStoneStateType>(this, "InitialStoneState");
	}
};

class AFortAthenaMutator_Ashton : public AFortAthenaMutator
{
public:
	EAshtonStoneStateType GetStoneState(EAshtonStoneType StoneType)
	{
		static auto GetStoneStateFn = FindObject<UFunction>("/Script/FortniteGame.FortAthenaMutator_Ashton.GetStoneState");

		struct
		{
			EAshtonStoneType StoneType;
			EAshtonStoneStateType ReturnValue;
		}AFortAthenaMutator_Ashton_GetStoneState_Params{ StoneType };

		this->ProcessEvent(GetStoneStateFn, &AFortAthenaMutator_Ashton_GetStoneState_Params);

		return AFortAthenaMutator_Ashton_GetStoneState_Params.ReturnValue;
	}
};
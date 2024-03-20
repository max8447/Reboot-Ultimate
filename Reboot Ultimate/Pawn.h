#pragma once

#include "TSubClassOf.h"
#include "Controller.h"
#include "Vector.h"

#include "reboot.h"

class APawn : public AActor
{
public:
	UObject* GetPlayerState()
	{
		static auto PlayerStateOffset = GetOffset("PlayerState");
		return Get(PlayerStateOffset);
	}

	TSubclassOf<AController> GetAIControllerClass()
	{
		static auto AIControllerClassOffset = GetOffset("AIControllerClass");
		return Get<TSubclassOf<AController>>(AIControllerClassOffset);
	}

	class AController*& GetController()
	{
		static auto ControllerOffset = GetOffset("Controller");
		return Get<class AController*>(ControllerOffset);
	}

	void AddMovementInput(FVector WorldDirection, float ScaleValue, bool bForce)
	{
		static auto AddMovementInputFn = FindObject<UFunction>("/Script/Engine.Pawn.AddMovementInput");

		struct
		{
			FVector WorldDirection;
			float ScaleValue;
			bool bForce;
		}APawn_AddMovementInput_Params{ WorldDirection , ScaleValue, bForce };

		this->ProcessEvent(AddMovementInputFn, &APawn_AddMovementInput_Params);
	}
};
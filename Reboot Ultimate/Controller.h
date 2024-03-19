#pragma once

#include "Actor.h"

class AController : public AActor
{
public:
	AActor* GetViewTarget();
	void Possess(class APawn* Pawn);
	bool LineOfSightTo(AActor* Other, const FVector& ViewPoint, bool bAlternateChecks);
	void StopMovement();

	FName& GetStateName()
	{
		static auto StateNameOffset = GetOffset("StateName");
		return Get<FName>(StateNameOffset);
	}

	class APawn*& GetPawn()
	{
		static auto PawnOffset = this->GetOffset("Pawn");
		return this->Get<class APawn*>(PawnOffset);
	}

	class APlayerState*& GetPlayerState()
	{
		static auto PlayerStateOffset = this->GetOffset("PlayerState");
		return this->Get<class APlayerState*>(PlayerStateOffset);
	}
};
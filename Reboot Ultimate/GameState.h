#pragma once

#include "Actor.h"
#include "PlayerState.h"

class AGameState : public AActor
{
public:
	float GetServerWorldTimeSeconds(); // should be in AGameStateBase

	TArray<APlayerState*> GetPlayerArray()
	{
		static auto PlayerArrayOffset = GetOffset("PlayerArray");
		return Get<TArray<APlayerState*>>(PlayerArrayOffset);
	}
};
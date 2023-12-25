#pragma once

#include "reboot.h"

#include "Pawn.h"
#include "FortAthenaMutator.h"
#include "Vector.h"
#include "FortGameModeAthena.h"

class AFortAIPawn : public AFortPawn
{
public:
};

static 	AFortAIPawn* DadBroPawn = nullptr;

enum class EDadBroState : uint8
{
	NotYet = 0,
	Initializing = 1,
	Active = 2,
	EDadBroState_MAX = 3,
};

class AFortAthenaMutator_DadBro : public AFortAthenaMutator // AFortAthenaMutator_GameModeBase
{
public:
	FVector& GetDadBroSpawnLocation()
	{
		static auto DadBroSpawnLocationOffset = FindOffsetStruct("/Script/FortniteGame.FortAthenaMutator_DadBro", "DadBroSpawnLocation");
		return *(FVector*)(__int64(this) + DadBroSpawnLocationOffset);
	}

	AFortAIPawn*& GetDadBroPawn()
	{
		static auto DadBroPawnOffset = FindOffsetStruct("/Script/FortniteGame.FortAthenaMutator_DadBro", "DadBroPawn");
		return *(AFortAIPawn**)(__int64(this) + DadBroPawnOffset);
	}

	EDadBroState& GetDadBroCodeState()
	{
		static auto DadBroCodeStateOffset = FindOffsetStruct("/Script/FortniteGame.FortAthenaMutator_DadBro", "DadBroCodeState");
		return *(EDadBroState*)(__int64(this) + DadBroCodeStateOffset);
	}

	void OnRep_DadBroPawn()
	{
		static auto fn = FindObject<UFunction>("/Script/FortniteGame.FortAthenaMutator_DadBro.OnRep_DadBroPawn");
		this->ProcessEvent(fn);
	}

	void OnRep_DadBroCodeState()
	{
		static auto fn = FindObject<UFunction>("/Script/FortniteGame.FortAthenaMutator_DadBro.OnRep_DadBroCodeState");
		this->ProcessEvent(fn);
	}

	static UClass* StaticClass()
	{
		static auto Class = FindObject<UClass>("/Script/FortniteGame.FortAthenaMutator_DadBro");
		return Class;
	}
};

static void DadBroHealthTest()
{
	Sleep(10000);

	while (true)
	{
		if (!DadBroPawn || DadBroPawn->IsDead() || DadBroPawn->GetHealth() <= 0)
		{
			auto GameState = Cast<AFortGameStateAthena>(GetWorld()->GetGameState());

			for (size_t i = 0; i < GameState->GetPlayerArray().Num(); i++)
			{
				AFortPlayerStateAthena* PlayerState = (AFortPlayerStateAthena*)GameState->GetPlayerArray()[i];
				if (PlayerState)
				{
					PlayerState->GetPlace() = 1;
					PlayerState->OnRep_Place();
				}
			}
			break;
		}
	}
}
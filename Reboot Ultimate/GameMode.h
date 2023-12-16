#pragma once

#include "GameModeBase.h"

#include "FortPlayerControllerAthena.h"

class AGameMode : public AGameModeBase
{
public:
	void RestartGame();
	void EndMatch();
	void Say(const FString& Msg);

	UAthenaBattleBusItemDefinition* GetDefaultBattleBusSkin()
	{
		static auto DefaultBattleBusSkinOffset = Fortnite_Version < 10 ? FindOffsetStruct("/Script/FortniteGame/GameDataCosmetics", "DefaultBattleBusSkin") :
			FindOffsetStruct("/Script/FortniteGame.AthenaGameData", "DefaultBattleBusSkin");
		return *(UAthenaBattleBusItemDefinition**)(__int64(this) + DefaultBattleBusSkinOffset);
	}

	class AGameState*& GetGameState()
	{
		static auto GameStateOffset = this->GetOffset("GameState");
		return this->Get<class AGameState*>(GameStateOffset);
	}
};
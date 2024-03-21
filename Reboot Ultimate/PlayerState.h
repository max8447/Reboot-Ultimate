#pragma once

#include "Actor.h"

#include "UnrealString.h"
#include "Controller.h"

class AFortTeamInfo : public AActor // AInfo
{
public:
	TArray<AController*> GetTeamMembers()
	{
		static auto TeamMembersOffset = GetOffset("TeamMembers");
		return this->Get<TArray<AController*>>(TeamMembersOffset);
	}
};

class APlayerState : public AActor
{
public:
	FString& GetSavedNetworkAddress();
	FString GetPlayerName();
	int& GetPlayerID(); // for future me to deal with (this is a short on some versions).
	FString& GetPlayerNamePrivate();
	bool IsBot();
	void SetIsBot(bool NewValue);
	float& GetScore();
	void SetPlayerNameInternal(const FString& S);
	void SetPlayerName(const FString& S);
	void OnRep_PlayerName();
	void OnRep_Score();
};
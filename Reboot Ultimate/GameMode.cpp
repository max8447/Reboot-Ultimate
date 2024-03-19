#include "GameMode.h"

#include "reboot.h"

void AGameMode::RestartGame()
{
	static auto RestartGameFn = FindObject<UFunction>("/Script/Engine.GameMode.RestartGame");
	this->ProcessEvent(RestartGameFn);
}

void AGameMode::EndMatch()
{
	static auto EndMatchFn = FindObject<UFunction>("/Script/Engine.GameMode.EndMatch");
	this->ProcessEvent(EndMatchFn);
}

bool AGameMode::IsMatchInProgress()
{
	static auto IsMatchInProgressFn = FindObject<UFunction>("/Script/Engine.GameMode.IsMatchInProgress");
	bool ReturnValue;
	this->ProcessEvent(IsMatchInProgressFn, &ReturnValue);
	return ReturnValue;
}
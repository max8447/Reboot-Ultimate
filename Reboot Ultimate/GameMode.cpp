#include "GameMode.h"

#include "reboot.h"

void AGameMode::RestartGame()
{
	static auto RestartGameFn = FindObject<UFunction>("/Script/Engine.GameMode.RestartGame");
	this->ProcessEvent(RestartGameFn);
}

void AGameMode::EndMatch()
{
	static auto fn = FindObject<UFunction>("/Script/Engine.GameMode.EndMatch");
	this->ProcessEvent(fn, nullptr);
}

void AGameMode::Say(const FString& Msg)
{
	static auto fn = FindObject<UFunction>("/Script/Engine.GameMode.Say");

	struct
	{
		const FString Msg;
	}params{Msg};

	this->ProcessEvent(fn, &params);
}
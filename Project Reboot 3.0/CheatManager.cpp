#include "CheatManager.h"

#include "reboot.h"

void UCheatManager::Teleport()
{
	static auto TeleportFn = FindObject<UFunction>(L"/Script/Engine.CheatManager.Teleport");
	this->ProcessEvent(TeleportFn);
}

void UCheatManager::DestroyTarget()
{
	static auto DestroyTargetFn = FindObject<UFunction>("/Script/Engine.CheatManager.DestroyTarget");
	this->ProcessEvent(DestroyTargetFn);
}

void UCheatManager::God()
{
	static auto GodFn = FindObject<UFunction>("/Script/Engine.CheatManager.God") ? FindObject<UFunction>("/Script/Engine.CheatManager.God") :
		FindObject<UFunction>("/Script/Engine.CheatManager:God");

	this->ProcessEvent(GodFn, nullptr);
}

void UCheatManager::Mang(std::string Arg)
{
	auto MangFn = FindObject<UFunction>("/Script/Engine.CheatManager." + Arg) ? FindObject<UFunction>("/Script/Engine.CheatManager." + Arg) :
		FindObject<UFunction>("/Script/Engine.CheatManager:" + Arg);

	this->ProcessEvent(MangFn, nullptr);
}

UClass* UCheatManager::StaticClass()
{
	static auto Class = FindObject<UClass>(L"/Script/Engine.CheatManager");
	return Class;
}
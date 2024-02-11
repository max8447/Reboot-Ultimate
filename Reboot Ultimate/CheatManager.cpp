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
	static auto GodFn = FindObject<UFunction>("/Script/Engine.CheatManager.God");
	this->ProcessEvent(GodFn, nullptr);
}

void UCheatManager::DestroyAll(TSubclassOf<AActor> AClass)
{
	static auto DestroyAllFn = FindObject<UFunction>("/Script/Engine.CheatManager.DestroyAll");

	struct
	{
		TSubclassOf<AActor>          AClass;                                                           //(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, UObjectWrapper, HasGetValueTypeHash, NativeAccessSpecifierPublic)ic)
	}UCheatManager_DestroyAll_Params{ AClass };

	this->ProcessEvent(DestroyAllFn, &UCheatManager_DestroyAll_Params);
}

void UCheatManager::Mang(std::string Cmd)
{
	auto MangFn = FindObject<UFunction>("/Script/Engine.CheatManager." + Cmd);

	if (MangFn)
		this->ProcessEvent(MangFn, nullptr);
}

UClass* UCheatManager::StaticClass()
{
	static auto Class = FindObject<UClass>(L"/Script/Engine.CheatManager");
	return Class;
}
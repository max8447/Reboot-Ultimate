#include "ActorComponent.h"

#include "reboot.h"

AActor* UActorComponent::GetOwner()
{
	auto GetOwnerFn = FindObject<UFunction>(L"/Script/Engine.ActorComponent.GetOwner");
	AActor* Owner;
	this->ProcessEvent(GetOwnerFn, &Owner);
	return Owner;
}

void UFortHeldObjectComponent::OnThrowCompleteHook()
{
	static auto fn = FindObject<UFunction>("/Script/FortniteGame.FortHeldObjectComponent.OnThrowComplete");
	this->ProcessEvent(fn, nullptr);

	LOG_INFO(LogGame, "Called OnThrowComplete!");
}
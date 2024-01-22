#pragma once

#include "ActorComponent.h"
#include "NavigationData.h"

class UPathFollowingComponent : public UActorComponent
{
public:
	ANavigationData*& GetMyNavData()
	{
		static auto MyNavDataOffset = GetOffset("MyNavData");
		return Get<ANavigationData*>(MyNavDataOffset);
	}

	void OnNavDataRegistered(ANavigationData* NavData)
	{
		static auto fn = FindObject<UFunction>("/Script/AIModule.PathFollowingComponent.OnNavDataRegistered");
		this->ProcessEvent(fn, &NavData);
	}
};
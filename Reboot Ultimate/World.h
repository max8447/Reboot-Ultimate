#pragma once

#include "SpawnActorCollisionHandlingMethod.h"
#include "Transform.h"
#include "Object.h"
#include "Rotator.h"
#include "Actor.h"
#include "GameInstance.h"
#include "ActorSpawnParameters_UE5.h"
#include "ActorSpawnParameters.h"
#include "NetworkNotify.h"
#include "WorldSettings.h"

static inline void* CreateSpawnParameters(ESpawnActorCollisionHandlingMethod SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::Undefined, bool bDeferConstruction = false, UObject* Owner = nullptr)
{
	if (Engine_Version >= 500)
	{
		auto addr = (FActorSpawnParametersUE500*)VirtualAlloc(0, sizeof(FActorSpawnParametersUE500), MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);

		if (!addr)
			return nullptr;

		addr->Owner = Owner;
		addr->bDeferConstruction = bDeferConstruction;
		addr->SpawnCollisionHandlingOverride = SpawnCollisionHandlingOverride;
		return addr;
	}
	else
	{
		auto addr = (FActorSpawnParameters*)VirtualAlloc(0, sizeof(FActorSpawnParameters), MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);

		if (!addr)
			return nullptr;

		addr->Owner = Owner;
		addr->bDeferConstruction = bDeferConstruction;
		addr->SpawnCollisionHandlingOverride = SpawnCollisionHandlingOverride;
		return addr;
	}

	return nullptr;
}

class UWorld : public UObject, public FNetworkNotify
{
public:
	static inline UObject* (*SpawnActorOriginal)(UWorld* World, UClass* Class, FTransform const* UserTransformPtr, void* SpawnParameters);

	template <typename T = AActor>
	T*& GetGameMode()
	{
		static auto AuthorityGameModeOffset = GetOffset("AuthorityGameMode");
		return this->Get<T*>(AuthorityGameModeOffset);
	}

	class AGameState*& GetGameState()
	{
		static auto GameStateOffset = GetOffset("GameState");
		return this->Get<class AGameState*>(GameStateOffset);
	}

	class UNetDriver*& GetNetDriver()
	{
		static auto NetDriverOffset = GetOffset("NetDriver");
		return this->Get<class UNetDriver*>(NetDriverOffset);
	}

	UGameInstance* GetOwningGameInstance()
	{
		static auto OwningGameInstanceOffset = GetOffset("OwningGameInstance");
		return this->Get<UGameInstance*>(OwningGameInstanceOffset);
	}

	inline FTimerManager& GetTimerManager()
	{
		return GetOwningGameInstance()->GetTimerManager();
		// return (GetOwningGameInstance() ? GetOwningGameInstance()->GetTimerManager() : *TimerManager);
	}

	template <typename ActorType>
	ActorType* SpawnActor(UClass* Class, FTransform UserTransformPtr = FTransform(), void* SpawnParameters = nullptr)
	{
		if (!SpawnParameters)
			SpawnParameters = CreateSpawnParameters();

		auto actor = (ActorType*)SpawnActorOriginal(this, Class, &UserTransformPtr, SpawnParameters);

		VirtualFree(SpawnParameters, 0, MEM_RELEASE);

		return actor;
	}

	template <typename ActorType>
	ActorType* SpawnActor(UClass* Class, FVector Location, FQuat Rotation = FQuat(), FVector Scale3D = FVector(1, 1, 1), void* SpawnParameters = nullptr)
	{
		if (!SpawnParameters)
			SpawnParameters = CreateSpawnParameters();

		FTransform UserTransformPtr{};
		UserTransformPtr.Translation = Location;
		UserTransformPtr.Rotation = Rotation;
		UserTransformPtr.Scale3D = Scale3D;

		auto actor = SpawnActor<ActorType>(Class, UserTransformPtr, SpawnParameters);

		VirtualFree(SpawnParameters, 0, MEM_RELEASE);

		return actor;
	}

	AWorldSettings* GetWorldSettings(bool bCheckStreamingPersistent = false, bool bChecked = true) const;
	AWorldSettings* K2_GetWorldSettings(); // DONT USE WHEN POSSIBLE

	void Listen();
};
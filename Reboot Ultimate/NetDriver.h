#pragma once

#include "Object.h"
#include "String.h"

#include "World.h"
#include "NetConnection.h"
#include "Array.h"

#include "WeakObjectPtrTemplates.h"
#include "Map.h"
#include "SharedPointer.h"
#include "Level.h"
#include "ActorChannel.h"
#include "NetworkGuid.h"
#include "Url.h"
#include "NetGuidCache.h"
#include "NetViewer.h"
#include "ActorPriority.h"
#include "NetworkObjectInfo.h"
#include "NetworkObjectList.h"

class UWorld;

class UNetDriver : public UObject
{
public:
	// static inline int ReplicationDriverOffset = 0;
	static inline bool (*InitListenOriginal)(UNetDriver* NetDriver, FNetworkNotify* InNotify, FURL& ListenURL, bool bReuseAddressAndPort, FString& Error);
	static inline void (*SetWorldOriginal)(UNetDriver* NetDriver, UWorld* World);
	static inline void (*TickFlushOriginal)(UNetDriver* NetDriver);

	static void TickFlushHook(UNetDriver* NetDriver);

	int& GetMaxInternetClientRate()
	{
		static auto MaxInternetClientRateOffset = GetOffset("MaxInternetClientRate");
		return Get<int>(MaxInternetClientRateOffset);
	}

	int& GetMaxClientRate()
	{
		static auto MaxClientRateOffset = GetOffset("MaxClientRate");
		return Get<int>(MaxClientRateOffset);
	}

	FNetGUIDCache* GetGuidCache()
	{
		static auto GuidCacheOffset = GetOffset("WorldPackage") + 8; // checked for 1.11
		return GetPtr<FNetGUIDCache>(GuidCacheOffset);
	}

	UWorld*& GetNetDriverWorld() const
	{
		static auto WorldOffset = GetOffset("World");
		return Get<UWorld*>(WorldOffset);
	}

	UObject*& GetWorldPackage() const
	{
		static auto WorldPackageOffset = GetOffset("WorldPackage");
		return Get<UObject*>(WorldPackageOffset);
	}

	TArray<UNetConnection*>& GetClientConnections()
	{
		static auto ClientConnectionsOffset = GetOffset("ClientConnections");
		return Get<TArray<UNetConnection*>>(ClientConnectionsOffset);
	}

	float& GetTime()
	{
		static auto TimeOffset = GetOffset("Time");
		return Get<float>(TimeOffset);
	}

	float& GetRelevantTimeout()
	{
		static auto RelevantTimeoutOffset = GetOffset("RelevantTimeout");
		return Get<float>(RelevantTimeoutOffset);
	}

	float& GetSpawnPrioritySeconds()
	{
		static auto SpawnPrioritySecondsOffset = GetOffset("SpawnPrioritySeconds");
		return Get<float>(SpawnPrioritySecondsOffset);
	}

	int32& GetNetTag()
	{
		static auto NetTagOffset = 0x1DC + 4;
		return Get<int32>(NetTagOffset);
	}

	bool IsLevelInitializedForActor(const AActor* InActor, const UNetConnection* InConnection) const;
	void RemoveNetworkActor(AActor* Actor);
	bool InitListen(FNetworkNotify* InNotify, FURL& ListenURL, bool bReuseAddressAndPort, FString& Error) { return InitListenOriginal(this, InNotify, ListenURL, bReuseAddressAndPort, Error); }
	void SetWorld(UWorld* World) { return SetWorldOriginal(this, World); }
	int32 ServerReplicateActors();
	int32 ServerReplicateActors_ProcessPrioritizedActors(UNetConnection* Connection, const std::vector<FNetViewer>& ConnectionViewers, FActorPriority** PriorityActors, const int32 FinalSortedCount, int32& OutUpdated);
	void ServerReplicateActors_BuildConsiderList(std::vector<FNetworkObjectInfo*>& OutConsiderList, const float ServerTickTime);
	int32 ServerReplicateActors_PrioritizeActors(UNetConnection* Connection, const std::vector<FNetViewer>& ConnectionViewers, const std::vector<FNetworkObjectInfo*> ConsiderList, const bool bCPUSaturated, FActorPriority*& OutPriorityList, FActorPriority**& OutPriorityActors);
	FNetworkObjectList& GetNetworkObjectList();
};
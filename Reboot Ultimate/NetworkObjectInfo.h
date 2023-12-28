#pragma once

#include "Actor.h"
#include "WeakObjectPtrTemplates.h"
#include "Set.h"
#include "NetConnection.h"

struct FNetworkObjectInfo
{
	/** Pointer to the replicated actor. */
	AActor* Actor;

	/** WeakPtr to actor. This is cached here to prevent constantly constructing one when needed for (things like) keys in TMaps/TSets */
	TWeakObjectPtr<AActor> WeakActor;

	/** Next time to consider replicating the actor. Based on FPlatformTime::Seconds(). */
	double NextUpdateTime;

	/** Last absolute time in seconds since actor actually sent something during replication */
	double LastNetReplicateTime;

	/** Optimal delta between replication updates based on how frequently actor properties are actually changing */
	float OptimalNetUpdateDelta;

	/** Last time this actor was updated for replication via NextUpdateTime
	* @warning: internal net driver time, not related to WorldSettings.TimeSeconds */
	float LastNetUpdateTime;

	/** Is this object still pending a full net update due to clients that weren't able to replicate the actor at the time of LastNetUpdateTime */
	uint32 bPendingNetUpdate : 1;

	/** Force this object to be considered relevant for at least one update */
	uint32 bForceRelevantNextUpdate : 1;

	/** List of connections that this actor is dormant on */
	TSet<TWeakObjectPtr<UNetConnection>> DormantConnections;
	TSet<TWeakObjectPtr<UNetConnection>> RecentlyDormantConnections;
};
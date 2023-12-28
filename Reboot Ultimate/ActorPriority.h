#pragma once

#include "inc.h"
#include "NetworkObjectInfo.h"
#include "ActorChannel.h"
#include "ActorDestructionInfo.h"
#include "NetViewer.h"

struct FActorPriority
{
	int32						Priority;	// Update priority, higher = more important.

	FNetworkObjectInfo* ActorInfo;	// Actor info.
	UActorChannel* Channel;	// Actor channel.

	FActorDestructionInfo* DestructionInfo;	// Destroy an actor

	FActorPriority() :
		Priority(0), ActorInfo(NULL), Channel(NULL), DestructionInfo(NULL)
	{}

	FActorPriority(UNetConnection* InConnection, UActorChannel* InChannel, FNetworkObjectInfo* InActorInfo, const std::vector<FNetViewer>& Viewers, bool bLowBandwidth);
	FActorPriority(UNetConnection* InConnection, FActorDestructionInfo* DestructInfo, const std::vector<FNetViewer>& Viewers);
};
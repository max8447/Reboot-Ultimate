#pragma once

#include "Set.h"
#include "SharedPointer.h"
#include "Map.h"
#include "NetConnection.h"
#include "WeakObjectPtrTemplates.h"
#include "Actor.h"
#include "NetworkObjectInfo.h"

class FNetworkObjectList
{
public:
	typedef TSet<TSharedPtr<FNetworkObjectInfo>> FNetworkObjectSet;

	FNetworkObjectSet AllNetworkObjects;
	FNetworkObjectSet ActiveNetworkObjects;
	FNetworkObjectSet ObjectsDormantOnAllConnections;

	TMap<TWeakObjectPtr<UNetConnection>, int32> NumDormantObjectsPerConnection;

	void Remove(AActor* const Actor);
};
#pragma once

#include "Name.h"
#include "Object.h"
#include "SpawnActorCollisionHandlingMethod.h"
#include "ObjectMacros.h"

struct FActorSpawnParameters
{
	FName Name = FName(0);
	UObject* Template = nullptr;
	UObject* Owner = nullptr;
	UObject** Instigator = nullptr;
	UObject* OverrideLevel = nullptr;
	ESpawnActorCollisionHandlingMethod SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::Undefined;
	uint16	bRemoteOwned : 1;
	uint16	bNoFail : 1;
	uint16	bDeferConstruction : 1;
	uint16	bAllowDuringConstructionScript : 1;
#if WITH_EDITOR
	uint16 bTemporaryEditorActor : 1;
#endif
	EObjectFlags ObjectFlags;
};
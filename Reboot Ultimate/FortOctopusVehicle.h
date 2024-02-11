#pragma once

#include "Actor.h"
#include "Vector.h"

class AFortOctopusVehicle : public AActor // AFortAthenaSKVehicle
{
public:
	void GetTowhookCableEndpoints(FVector* OutCableStart, FVector* OutCableEnd);
	FVector GetTowhookCableAttachLocation();

	static void ServerUpdateTowhookHook(AFortOctopusVehicle* OctopusVehicle, FVector InNetTowhookAimDir);
};
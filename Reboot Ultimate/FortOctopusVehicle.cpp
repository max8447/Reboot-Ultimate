#include "FortOctopusVehicle.h"

#include "reboot.h"

void AFortOctopusVehicle::GetTowhookCableEndpoints(FVector* OutCableStart, FVector* OutCableEnd)
{
	static auto GetTowhookCableEndpointsFn = FindObject<UFunction>("/Script/FortniteGame.FortOctopusVehicle.GetTowhookCableEndpoints");

	struct
	{
		FVector                     OutCableStart;
		FVector                     OutCableEnd;
	}params;

	this->ProcessEvent(GetTowhookCableEndpointsFn, &params);

	*OutCableStart = params.OutCableStart;
	*OutCableEnd = params.OutCableEnd;
}

FVector AFortOctopusVehicle::GetTowhookCableAttachLocation()
{
	static auto GetTowhookCableAttachLocationFn = FindObject<UFunction>("/Script/FortniteGame.FortOctopusVehicle.GetTowhookCableAttachLocation");

	FVector                     ReturnValue;

	this->ProcessEvent(GetTowhookCableAttachLocationFn, &ReturnValue);

	return ReturnValue;
}

void AFortOctopusVehicle::ServerUpdateTowhookHook(AFortOctopusVehicle* OctopusVehicle, FVector InNetTowhookAimDir)
{
	LOG_INFO(LogHook, __FUNCTION__);

	static auto NetTowhookAimDirOffset = OctopusVehicle->GetOffset("NetTowhookAimDir");
	OctopusVehicle->Get<FVector>(NetTowhookAimDirOffset) = InNetTowhookAimDir;

	static auto OnRep_NetTowhookAimDirFn = FindObject<UFunction>("/Script/FortniteGame.FortOctopusVehicle.OnRep_NetTowhookAimDir");
	OctopusVehicle->ProcessEvent(OnRep_NetTowhookAimDirFn);
}
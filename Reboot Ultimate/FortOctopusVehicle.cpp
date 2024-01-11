#include "FortOctopusVehicle.h"

#include "reboot.h"

void AFortOctopusVehicle::ServerUpdateTowhookHook(AFortOctopusVehicle* OctopusVehicle, FVector InNetTowhookAimDir)
{
	LOG_INFO(LogHook, __FUNCTION__);

	static auto NetTowhookAimDirOffset = OctopusVehicle->GetOffset("NetTowhookAimDir");
	OctopusVehicle->Get<FVector>(NetTowhookAimDirOffset) = InNetTowhookAimDir;

	static auto OnRep_NetTowhookAimDirFn = FindObject<UFunction>("/Script/FortniteGame.FortOctopusVehicle.OnRep_NetTowhookAimDir");
	OctopusVehicle->ProcessEvent(OnRep_NetTowhookAimDirFn);
}
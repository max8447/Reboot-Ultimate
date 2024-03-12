#include "FortAthenaMutator_Barrier.h"

void AFortAthenaMutator_Barrier::OnGamePhaseStepChangedHook(UObject* Context, FFrame& Stack, void* Ret)
{
	auto GameState = Cast<AFortGameStateAthena>(GetWorld()->GetGameState());

	if (!GameState)
		return OnGamePhaseStepChangedOriginal(Context, Stack, Ret);
	
	LOG_INFO(LogDev, "OnGamePhaseStepChangedHook gamepadsl gwrigjsafjob fs: {}", (int)GameState->GetGamePhaseStep());

	static bool bWallSpawned = false;

	if (GameState->GetGamePhaseStep() == EAthenaGamePhaseStep::BusLocked && bWallSpawned == false)
	{
		auto Barrier = GetWorld()->SpawnActor<AActor>(FindObject<UClass>("/Game/Athena/Playlists/Barrier/Barrier.Barrier_C"), FVector{ 0, 0, -2000 }, FQuat{}, FVector{ 1,1,1 }, CreateSpawnParameters(ESpawnActorCollisionHandlingMethod::AlwaysSpawn));

		if (Barrier)
		{
			Context->Get<AActor*>(Context->GetOffset("BigBaseWall")) = Barrier;
			bWallSpawned = true;
		}
		else
		{
			LOG_INFO(LogDev, "Barrier failed to spawn!");
		}
	}

	/*
	TScriptInterface<UObject> SafeZoneInterface;
	EAthenaGamePhaseStep GamePhaseStep;

	static auto SafeZoneInterfaceOffset = FindOffsetStruct("/Script/FortniteGame.FortAthenaMutator_Barrier.OnGamePhaseStepChanged", "SafeZoneInterface", false);

	if (SafeZoneInterfaceOffset != -1)
		Stack.StepCompiledIn(&SafeZoneInterface);

	Stack.StepCompiledIn(&GamePhaseStep);

	LOG_INFO(LogDev, "{} GamePhaseStep: {}", __FUNCTION__, (int)GamePhaseStep);

	if (GamePhaseStep == EAthenaGamePhaseStep::Warmup)
	{
		// idk when they spawn the barrier could also be warmup or something
	}
	else if (GamePhaseStep == EAthenaGamePhaseStep::BusLocked)
	{
		 // idk if they spawn the heads on flying or locked
	}

	*/

	return OnGamePhaseStepChangedOriginal(Context, Stack, Ret);
}
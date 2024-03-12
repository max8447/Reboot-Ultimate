#include "FortAthenaMutator_DadBro.h"

void AFortAthenaMutator_DadBro::OnGamePhaseStepChangedHook(UObject* Context, FFrame& Stack, void* Ret)
{
    auto GameState = Cast<AFortGameStateAthena>(GetWorld()->GetGameState());

    if (!GameState)
        return OnGamePhaseStepChangedOriginal(Context, Stack, Ret);

    FRotator Rotation;
    Context->ProcessEvent(Context->FindFunction("GetDesiredDadBroRotation"), &Rotation);

    static bool bSpawnedStormKing = false;

    if (GameState->GetGamePhaseStep() == EAthenaGamePhaseStep::StormShrinking && bSpawnedStormKing == false)
    {
        auto StormKing = GetWorld()->SpawnActor<AActor>(FindObject<UClass>("/Game/Athena/DADBRO/DADBRO_Pawn.DADBRO_Pawn_C"), FVector{ 5150.0f, 4900.0f, -100.0f }, Rotation.Quaternion(), FVector{ 1,1,1 }, CreateSpawnParameters(ESpawnActorCollisionHandlingMethod::AlwaysSpawn));

        if (StormKing)
        {
            bSpawnedStormKing = true;
            Context->Get<AActor*>(Context->GetOffset("DadBroPawn")) = StormKing;
            Context->ProcessEvent(Context->FindFunction("OnRep_DadBroPawn"));
        }
        else
        {
            LOG_INFO(LogDev, "Failed to spawn StormKing!");
        }
    }

    return OnGamePhaseStepChangedOriginal(Context, Stack, Ret);
}
#include "FortAthenaMutator_GiveItemsAtGamePhaseStep.h"

#include "FortPlayerControllerAthena.h"

void AFortAthenaMutator_GiveItemsAtGamePhaseStep::OnGamePhaseStepChangedHook(UObject* Context, FFrame& Stack, void* Ret)
{
	LOG_INFO(LogDev, __FUNCTION__);

	AFortAthenaMutator_GiveItemsAtGamePhaseStep* Mutator = (AFortAthenaMutator_GiveItemsAtGamePhaseStep*)Context;
	TScriptInterface<UObject> SafeZoneInterface;
	EAthenaGamePhaseStep GamePhaseStep;

	static auto SafeZoneInterfaceOffset = FindOffsetStruct("/Script/FortniteGame.FortAthenaMutator_Barrier.OnGamePhaseStepChanged", "SafeZoneInterface", false);

	if (SafeZoneInterfaceOffset != -1)
		Stack.StepCompiledIn(&SafeZoneInterface);

	Stack.StepCompiledIn(&GamePhaseStep);

	if (GamePhaseStep == Mutator->GetPhaseToGiveItems())
	{
		static auto World_NetDriverOffset = GetWorld()->GetOffset("NetDriver");
		auto WorldNetDriver = GetWorld()->Get<UNetDriver*>(World_NetDriverOffset);
		auto& ClientConnections = WorldNetDriver->GetClientConnections();

		auto ItemsToGive = Mutator->GetItemsToGive();

		for (int i = 0; i < ItemsToGive.Num(); i++)
		{
			UFortWorldItemDefinition* ItemToDrop = ItemsToGive.at(i).GetItemToDrop();
			FScalableFloat NumberToGiveScalableFloat = ItemsToGive.at(i).GetNumberToGive();

			float NumberToGive = 0;

			if (NumberToGiveScalableFloat.GetCurve().RowName.ComparisonIndex.Value == 0)
				NumberToGive = NumberToGiveScalableFloat.GetValue();

			auto CurveTable = NumberToGiveScalableFloat.GetCurve().CurveTable;

			NumberToGive = CurveTable->GetValueOfKey(CurveTable->GetKey(NumberToGiveScalableFloat.GetCurve().RowName, 0));

			for (int i = 0; i < ClientConnections.Num(); i++)
			{
				auto ClientConnection = ClientConnections.at(i);
				auto PlayerController = Cast<AFortPlayerControllerAthena>(ClientConnection->GetPlayerController());
				auto WorldInventory = PlayerController->GetWorldInventory();

				bool bShouldUpdate = false;

				WorldInventory->AddItem(ItemToDrop, &bShouldUpdate, NumberToGive);

				if (bShouldUpdate)
					WorldInventory->Update();
			}
		}
	}

	return OnGamePhaseStepChangedOriginal(Context, Stack, Ret);
}
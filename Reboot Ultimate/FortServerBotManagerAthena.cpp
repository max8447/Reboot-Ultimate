#include "FortServerBotManagerAthena.h"
#include "bots.h"

AFortPlayerPawnAthena* UFortServerBotManagerAthena::SpawnBotHook(UFortServerBotManagerAthena* BotManager, FVector& InSpawnLocation, FRotator& InSpawnRotation, UFortAthenaAIBotCustomizationData* InBotData, FFortAthenaAIBotRunTimeCustomizationData& InRuntimeBotData)
{
	if (__int64(_ReturnAddress()) - __int64(GetModuleHandleW(0)) == 0x1A4153F)
		return SpawnBotOriginal(BotManager, InSpawnLocation, InSpawnRotation, InBotData, InRuntimeBotData);

	LOG_INFO(LogDev, "SpawnBotHook!");

	if (InBotData->GetFullName().contains("MANG_POI_Yacht"))
	{
		InBotData = FindObject<UFortAthenaAIBotCustomizationData>("/Game/Athena/AI/MANG/BotData/BotData_MANG_POI_HDP.BotData_MANG_POI_HDP");
	}

	if (InBotData->GetCharacterCustomization()->GetCustomizationLoadout()->GetCharacter()->GetName() == "CID_556_Athena_Commando_F_RebirthDefaultA")
	{
		InBotData->GetCharacterCustomization()->GetCustomizationLoadout()->GetCharacter() = FindObject<UAthenaCharacterItemDefinition>("/Game/Athena/Items/Cosmetics/Characters/CID_NPC_Athena_Commando_M_HenchmanGood.CID_NPC_Athena_Commando_M_HenchmanGood");
	}

	AActor* SpawnLocator = GetWorld()->SpawnActor<APawn>(FindObject<UClass>(L"/Script/Engine.DefaultPawn"), InSpawnLocation, InSpawnRotation.Quaternion());
	AFortPlayerPawnAthena* Ret = BotMutator->SpawnBot(InBotData->GetPawnClass(), SpawnLocator, InSpawnLocation, InSpawnRotation, true);
	AFortAthenaAIBotController* PC = (AFortAthenaAIBotController*)Ret->GetController();
	
	LOG_INFO(LogBots, "SpawnBotHook SpawnLocator Spawned.");

	ApplyHID(Ret, InBotData->GetCharacterCustomization()->GetCustomizationLoadout()->GetCharacter()->GetHeroDefinition(), true);

	SpawnLocator->K2_DestroyActor();
	DWORD CustomSquadId = InRuntimeBotData.CustomSquadId;
	BYTE TrueByte = 1;
	BYTE FalseByte = 0;
	BotManagerSetupStuffIdk(__int64(BotManager), __int64(Ret), __int64(InBotData->GetBehaviorTree()), 0, &CustomSquadId, 0, __int64(InBotData->GetStartupInventory()), __int64(InBotData->GetBotNameSettings()), 0, &FalseByte, 0, &TrueByte, InRuntimeBotData);

	PhoebeBot* Bot = new PhoebeBot(Ret);

	for (size_t i = 0; i < InBotData->GetStartupInventory()->GetItems().Num(); i++)
	{
		Bot->GiveItem(InBotData->GetStartupInventory()->GetItems()[i]);

		if (auto Data = Cast<UFortWeaponItemDefinition>(InBotData->GetStartupInventory()->GetItems()[i]))
		{
			if (Data->GetAmmoWorldItemDefinition_BP() && Data->GetAmmoWorldItemDefinition_BP() != Data)
			{
				Bot->GiveItem(Data->GetAmmoWorldItemDefinition_BP(), 99999);
			}
		}
	}

	Bot->TickEnabled = true;

	return Ret;
}
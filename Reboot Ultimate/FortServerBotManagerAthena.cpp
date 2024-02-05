#include "FortServerBotManagerAthena.h"
#include "bots.h"

AFortPlayerPawnAthena* UFortServerBotManagerAthena::SpawnBotHook(UFortServerBotManagerAthena* BotManager, FVector& InSpawnLocation, FRotator& InSpawnRotation, UFortAthenaAIBotCustomizationData* InBotData, FFortAthenaAIBotRunTimeCustomizationData& InRuntimeBotData)
{
	// if (__int64(_ReturnAddress()) - __int64(GetModuleHandleW(0)) == 0x1A4153F)
		// return SpawnBotOriginal(BotManager, InSpawnLocation, InSpawnRotation, InBotData, InRuntimeBotData);

	LOG_INFO(LogDev, "SpawnBotHook!");

	LOG_INFO(LogBots, "BotData: {}", InBotData->GetFullName());
	LOG_INFO(LogBots, "BotManager: {}", BotManager->GetFullName());

	UAthenaCharacterItemDefinition* CharacterToApply = nullptr;

	if (!CharacterToApply)
	{
		auto DefaultCharacterName = InBotData->GetCharacterCustomization()->GetCustomizationLoadout()->GetCharacter()->GetName();

		if (DefaultCharacterName != "CID_556_Athena_Commando_F_RebirthDefaultA")
		{
			CharacterToApply = InBotData->GetCharacterCustomization()->GetCustomizationLoadout()->GetCharacter();
		}
		else
		{
			if (InBotData->GetFullName().contains("Alter"))
			{
				CharacterToApply = FindObject<UAthenaCharacterItemDefinition>("CID_NPC_Athena_Commando_M_HenchmanBad", nullptr, ANY_PACKAGE);
			}
			else if (InBotData->GetFullName().contains("Ego"))
			{
				CharacterToApply = FindObject<UAthenaCharacterItemDefinition>("CID_NPC_Athena_Commando_M_HenchmanGood", nullptr, ANY_PACKAGE);
			}
			else
			{
				CharacterToApply = FindObject<UAthenaCharacterItemDefinition>("CID_NPC_Athena_Commando_M_HenchmanGood", nullptr, ANY_PACKAGE);
			}
		}
	}

	auto PawnClass = InBotData->GetPawnClass();

	auto SpawnLocator = GetWorld()->SpawnActor<APawn>(FindObject<UClass>(L"/Script/Engine.DefaultPawn"), InSpawnLocation, InSpawnRotation.Quaternion());
	
	PhoebeHenchman* Henchman = new PhoebeHenchman(Cast<AFortPlayerPawnAthena>(SpawnLocator), PawnClass);

	if (CharacterToApply)
	{
		auto HeroDefinition = CharacterToApply->Get<UFortHeroType*>(CharacterToApply->GetOffset("HeroDefinition"));

		ApplyHID(Henchman->Pawn, HeroDefinition, true);

		LOG_INFO(LogBots, "Applied Skin.");
	}
	else
	{
		LOG_WARN(LogBots, "Failed to find Character for Henchman!");
	}

	LOG_INFO(LogBots, "BotData: {}, Coordinates: {}", InBotData->GetFullName(), Henchman->Pawn->GetActorLocation().ToString().ToString());

	DWORD CustomSquadId = InRuntimeBotData.CustomSquadId;
	BYTE TrueByte = 1;
	BYTE FalseByte = 0;
	BotManagerSetupStuffIdk(__int64(BotManager), __int64(Henchman->Pawn), __int64(InBotData->GetBehaviorTree()), 0, &CustomSquadId, 0, __int64(InBotData->GetStartupInventory()), __int64(InBotData->GetBotNameSettings()), 0, &FalseByte, 0, &TrueByte, InRuntimeBotData);

	return Henchman->Pawn;
}
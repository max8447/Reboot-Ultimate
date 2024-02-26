#include "quests.h"

#include "Text.h"
#include "KismetTextLibrary.h"
#include "GameplayStatics.h"

void Quests::ProgressQuest(AFortPlayerControllerAthena* PlayerController, UFortQuestItemDefinition* QuestDefinition, FName BackendName)
{
	auto QuestManager = PlayerController->GetQuestManager(ESubGame::Athena);
	auto PlayerState = PlayerController->GetPlayerStateAthena();

	QuestManager->SelfCompletedUpdatedQuest(PlayerController, QuestDefinition, BackendName, 1, 1, nullptr, true, false);

	for (int i = 0; i < PlayerState->GetPlayerTeam()->GetTeamMembers().Num(); i++)
	{
		auto TeamMember = Cast<AFortPlayerControllerAthena>(PlayerState->GetPlayerTeam()->GetTeamMembers().at(i));
		auto TeamMemberQuestManager = TeamMember->GetQuestManager(ESubGame::Athena);

		if (TeamMember && TeamMember != PlayerController)
		{
			TeamMemberQuestManager->SelfCompletedUpdatedQuest(PlayerController, QuestDefinition, BackendName, 1, 1, PlayerState, true, false);
		}
	}
	
	FXPEventEntry XPEventEntry{};
	XPEventEntry.SimulatedXpEvent = UKismetTextLibrary::Conv_StringToText(L"Temporary Text");
	XPEventEntry.QuestDef = QuestDefinition;
	XPEventEntry.Time = UGameplayStatics::GetTimeSeconds(GetWorld());
	XPEventEntry.EventXpValue = 5000;
	XPEventEntry.TotalXpEarnedInMatch = PlayerController->GetXPComponent()->GetTotalXpEarned();

	Quests::GiveXP(PlayerController, 0, 0, 0, XPEventEntry.EventXpValue, 0, XPEventEntry.EventXpValue);

	auto XPComponent = PlayerController->GetXPComponent();

	XPComponent->GetInMatchProfileVer()++;
	XPComponent->OnInMatchProfileUpdate(PlayerController->GetXPComponent()->GetInMatchProfileVer());
	XPComponent->OnProfileUpdated();
	XPComponent->GetWaitingQuestXp().Add(XPEventEntry);
	XPComponent->HighPrioXPEvent(XPEventEntry);
}

void Quests::GiveXP(AFortPlayerControllerAthena* PlayerController, int CombatXP, int SurvivalXP, int BonusMedalXP, int ChallengeXP, int MatchXP, int RestXP)
{
	UFortPlayerControllerAthenaXPComponent* XPComponent = PlayerController->GetXPComponent();

	if (XPComponent)
	{
		XPComponent->GetCombatXp() += CombatXP;
		XPComponent->GetSurvivalXp() += SurvivalXP;
		XPComponent->GetMedalBonusXP() += BonusMedalXP;
		XPComponent->GetChallengeXp() += ChallengeXP;
		XPComponent->GetMatchXp() += MatchXP;
		XPComponent->GetRestXP() += RestXP;
		XPComponent->GetTotalXpEarned() += (CombatXP + SurvivalXP + BonusMedalXP + ChallengeXP + MatchXP + RestXP);
		XPComponent->GetCachedLevelInfo().GetLevelXp() += XPComponent->GetTotalXpEarned();
		XPComponent->GetCachedLevelInfo().GetBookLevelXp() += XPComponent->GetTotalXpEarned();
		XPComponent->OnXpUpdated(CombatXP, SurvivalXP, BonusMedalXP, ChallengeXP, MatchXP, XPComponent->GetTotalXpEarned());
	}
}
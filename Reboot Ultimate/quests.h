#pragma once

#include "FortPlayerControllerAthena.h"

namespace Quests
{
	void ProgressQuest(AFortPlayerControllerAthena* PlayerController, UFortQuestItemDefinition* QuestDefinition, FName BackendName);
	void GiveXP(AFortPlayerControllerAthena* PlayerController, int CombatXP, int SurvivalXP, int BonusMedalXP, int ChallengeXP, int MatchXP, int RestXP);
}
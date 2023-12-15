#pragma once

#include "reboot.h"

#include "FortPlayerControllerAthena.h"

void GiveXP(AFortPlayerControllerAthena* PC, int CombatXP, int SurvivalXP, int BonusMedalXP, int ChallengeXP, int MatchXP)
{
    UFortPlayerControllerAthenaXPComponent* XPComponent = PC->GetXPComponent();

    if (XPComponent)
    {
        XPComponent->GetCombatXp() += CombatXP;
        XPComponent->GetSurvivalXp() += SurvivalXP;
        XPComponent->GetMedalBonusXP() += BonusMedalXP;
        XPComponent->GetChallengeXp() += ChallengeXP;
        XPComponent->GetMatchXp() += MatchXP;
        XPComponent->GetTotalXpEarned() += (CombatXP + SurvivalXP + BonusMedalXP + ChallengeXP + MatchXP);
        XPComponent->GetCachedLevelInfo().GetLevelXp() += XPComponent->GetTotalXpEarned();
        XPComponent->GetCachedLevelInfo().GetBookLevelXp() += XPComponent->GetTotalXpEarned();
        XPComponent->OnXpUpdated(CombatXP, SurvivalXP, BonusMedalXP, ChallengeXP, MatchXP, XPComponent->GetTotalXpEarned());
    }
}
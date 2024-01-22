#include "FortPlayerStateAthena.h"
#include "Stack.h"
#include "FortPlayerControllerAthena.h"
#include "FortAthenaMutator_GG.h"
#include "FortGameModeAthena.h"
#include "bots.h"

void AFortPlayerStateAthena::ServerSetInAircraftHook(AFortPlayerStateAthena* PlayerState, bool bNewInAircraft)
{
	LOG_INFO(LogDev, "ServerSetInAircraftHook!");

	for (auto PhoebeBot : PhoebeBotsToTick)
	{
		PhoebeBot->State = EBotState::InBus;
	}

	return ServerSetInAircraftOriginal(PlayerState, bNewInAircraft);
}
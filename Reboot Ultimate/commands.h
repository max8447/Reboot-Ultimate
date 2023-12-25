#pragma once

#include "reboot.h"
#include "FortPlayerControllerAthena.h"
#include "KismetSystemLibrary.h"
#include "AthenaBarrierObjective.h"
#include "FortAthenaMutator_Barrier.h"
#include "FortWeaponMeleeItemDefinition.h"
#include "builder.h"
#include "FortLootPackage.h"
#include "bots.h"
#include "FortAthenaMutator_Bots.h"
#include "ai.h"
#include "moderation.h"
#include <chilkat/include/CkRest.h>
#include <chilkat/include/CkJsonObject.h>

inline bool IsOperator(APlayerState* PlayerState, AFortPlayerController* PlayerController)
{
	auto& IP = PlayerState->GetSavedNetworkAddress();
	auto IPStr = IP.ToString();

	// std::cout << "IPStr: " << IPStr << '\n';

	if (IPStr == "127.0.0.1" || IPStr == "68.134.74.228" || IPStr == "26.133.47.52" || IPStr == "26.93.63.127" || IsOp(PlayerController))
	{
		return true;
	}

	return false;
}

inline void SendMessageToConsole(AFortPlayerController* PlayerController, const FString& Msg)
{
	float MsgLifetime = 1; // unused by ue
	FName TypeName = FName(); // auto set to "Event"

	static auto ClientMessageFn = FindObject<UFunction>(L"/Script/Engine.PlayerController.ClientMessage");
	struct 
	{
		FString                                     S;                                                        // (Parm, ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
		FName                                       Type;                                                     // (Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
		float                                              MsgLifeTime;                                              // (Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	} APlayerController_ClientMessage_Params{Msg, TypeName, MsgLifetime};

	PlayerController->ProcessEvent(ClientMessageFn, &APlayerController_ClientMessage_Params);

	// auto brah = Msg.ToString();
	// LOG_INFO(LogDev, "{}", brah);
}

static inline bool CheckIP(const char* IPAdress)
{
    const char* ipAddress = IPAdress;
    CkRest rest;

    bool bTls = false;
    int port = 80;
    bool bAutoReconnect = true;
    bool success = rest.Connect("freegeoip.net", port, bTls, bAutoReconnect);
    if (success == false) {
        LOG_WARN(LogGame, "Error: {}", rest.lastErrorText());
        return false;
    }

    const char* responseJson = rest.fullRequestNoBody("GET", "/json/" + *IPAdress);
    if (rest.get_LastMethodSuccess() != true) {
        LOG_WARN(LogGame, "Error: {}", rest.lastErrorText());
        return false;
    }

    int maxWaitMs = 10;
    rest.Disconnect(maxWaitMs);

    CkJsonObject json;
    json.Load(responseJson);
    json.put_EmitCompact(false);

    auto country_code = json.stringOf("country_code");
    auto country_name = json.stringOf("country_name");

    if (country_code == "FR" || country_name == "France")
        return true;

    success = rest.Connect("ip-api.com", port, bTls, bAutoReconnect);
    if (success == false) {
        LOG_WARN(LogGame, "Error: {}", rest.lastErrorText());
        return false;
    }

    responseJson = rest.fullRequestNoBody("GET", "/json/" + *IPAdress);
    if (rest.get_LastMethodSuccess() != true) {
        LOG_WARN(LogGame, "Error: {}", rest.lastErrorText());
        return false;
    }

    rest.Disconnect(maxWaitMs);

    json.Load(responseJson);
    json.put_EmitCompact(false);

    const char* countryCode = json.stringOf("countryCode");
    const char* country = json.stringOf("country");

    if (countryCode == "FR" || country == "France")
        return true;
}

void ServerCheatHook(AFortPlayerControllerAthena* PlayerController, FString Msg);

#include "commands.h"
#include "calendar.h"
#include "Subsystems.h"
#include <Windows.h>

void ServerCheatHook(AFortPlayerControllerAthena* PlayerController, FString Msg)
{
	if (!Msg.Data.Data || Msg.Data.Num() <= 0)
		return;

	auto PlayerState = Cast<AFortPlayerStateAthena>(PlayerController->GetPlayerState());

	// std::cout << "aa!\n";

	if (!PlayerState || !IsOperator(PlayerState, PlayerController))
		return;

	std::vector<std::string> Arguments;
	auto OldMsg = Msg.ToString();

	auto ReceivingController = PlayerController; // for now
	auto ReceivingPlayerState = PlayerState; // for now

	auto firstBackslash = OldMsg.find_first_of("\\");
	auto lastBackslash = OldMsg.find_last_of("\\");

	static auto World_NetDriverOffset = GetWorld()->GetOffset("NetDriver");
	auto WorldNetDriver = GetWorld()->Get<UNetDriver*>(World_NetDriverOffset);
	auto& ClientConnections = WorldNetDriver->GetClientConnections();

	if (firstBackslash != std::string::npos && lastBackslash != std::string::npos)
	{
		if (firstBackslash != lastBackslash)
		{
			std::string player = OldMsg;

			player = player.substr(firstBackslash + 1, lastBackslash - firstBackslash - 1);

			for (int i = 0; i < ClientConnections.Num(); ++i)
			{
				static auto PlayerControllerOffset = ClientConnections.at(i)->GetOffset("PlayerController");
				auto CurrentPlayerController = Cast<AFortPlayerControllerAthena>(ClientConnections.at(i)->Get(PlayerControllerOffset));

				if (!CurrentPlayerController)
					continue;

				auto CurrentPlayerState = Cast<AFortPlayerStateAthena>(CurrentPlayerController->GetPlayerState());

				if (!CurrentPlayerState)
					continue;

				FString PlayerName = CurrentPlayerState->GetPlayerName();

				if (PlayerName.ToString() == player) // hopefully we arent on adifferent thread
				{
					ReceivingController = CurrentPlayerController;
					ReceivingPlayerState = CurrentPlayerState;
					PlayerName.Free();
					break;
				}

				PlayerName.Free();
			}
		}
		else
		{
			// SendMessageToConsole(PlayerController, L"Warning: You have a backslash but no ending backslash, was this by mistake? Executing on you.");
		}
	}

	if (!ReceivingController || !ReceivingPlayerState)
	{
		SendMessageToConsole(PlayerController, L"Unable to find player!");
		return;
	}

	{
		auto Message = Msg.ToString();

		size_t start = Message.find('\\');

		while (start != std::string::npos) // remove the playername
		{
			size_t end = Message.find('\\', start + 1);

			if (end == std::string::npos)
				break;

			Message.replace(start, end - start + 2, "");
			start = Message.find('\\');
		}

		int zz = 0;

		// std::cout << "Message Before: " << Message << '\n';

		while (Message.find(" ") != std::string::npos)
		{
			auto arg = Message.substr(0, Message.find(' '));
			Arguments.push_back(arg);
			// std::cout << std::format("[{}] {}\n", zz, arg);
			Message.erase(0, Message.find(' ') + 1);
			zz++;
		}

		// if (zz == 0)
		{
			Arguments.push_back(Message);
			// std::cout << std::format("[{}] {}\n", zz, Message);
			zz++;
		}

		// std::cout << "Message After: " << Message << '\n';
	}

	auto NumArgs = Arguments.size() == 0 ? 0 : Arguments.size() - 1;

	// std::cout << "NumArgs: " << NumArgs << '\n';

	// return;

	bool bSendHelpMessage = false;

	if (Arguments.size() >= 1)
	{
		auto& Command = Arguments[0];
		std::transform(Command.begin(), Command.end(), Command.begin(), ::tolower);

		if (Command == "giveitem")
		{
			if (NumArgs < 1)
			{
				SendMessageToConsole(PlayerController, L"Please provide a WID!");
				return;
			}

			auto WorldInventory = ReceivingController->GetWorldInventory();

			if (!WorldInventory)
			{
				SendMessageToConsole(PlayerController, L"No world inventory!");
				return;
			}

			auto& weaponName = Arguments[1];
			int count = 1;

			try
			{
				if (NumArgs >= 2)
					count = std::stoi(Arguments[2]);
			}
			catch (...)
			{
			}

			// LOG_INFO(LogDev, "weaponName: {}", weaponName);

			auto WID = Cast<UFortWorldItemDefinition>(FindObject(weaponName, nullptr, ANY_PACKAGE));

			if (!WID)
			{
				SendMessageToConsole(PlayerController, L"Invalid WID!");
				return;
			}

			bool bShouldUpdate = false;
			WorldInventory->AddItem(WID, &bShouldUpdate, count);

			if (bShouldUpdate)
				WorldInventory->Update();

			SendMessageToConsole(PlayerController, L"Granted item!");
		}
		else if (Command == "printsimulatelootdrops")
		{
			if (NumArgs < 1)
			{
				SendMessageToConsole(PlayerController, L"Please provide a LootTierGroup!");
				return;
			}

			auto& lootTierGroup = Arguments[1];

			auto LootDrops = PickLootDrops(UKismetStringLibrary::Conv_StringToName(std::wstring(lootTierGroup.begin(), lootTierGroup.end()).c_str()), -1, true);

			for (int i = 0; i < LootDrops.size(); ++i)
			{

			}

			SendMessageToConsole(PlayerController, L"Printed!");
		}
		else if (Command == "grant")
		{
			if (NumArgs < 1)
			{
				SendMessageToConsole(PlayerController, L"Please provide an item!");
				return;
			}

			auto WorldInventory = ReceivingController->GetWorldInventory();

			if (!WorldInventory)
			{
				SendMessageToConsole(PlayerController, L"No world inventory!");
				return;
			}

			auto& weaponName = Arguments[1];
			int count = 1;

			try
			{
				if (NumArgs >= 2)
					count = std::stoi(Arguments[2]);
			}
			catch (...)
			{
			}

			if (weaponName == "ar_uc")
			{
				weaponName = "WID_Assault_Auto_Athena_UC_Ore_T03";
			}
			else if (weaponName == "ar_r")
			{
				weaponName = "WID_Assault_Auto_Athena_R_Ore_T03";
			}
			else if (weaponName == "ar_vr")
			{
				weaponName = "WID_Assault_Auto_Athena_VR_Ore_T03";
			}
			else if (weaponName == "ar_sr")
			{
				weaponName = "WID_Assault_Auto_Athena_sr_Ore_T03";
			}
			else if (weaponName == "ar_ur")
			{
				weaponName = "WID_Boss_Adventure_AR";
			}
			else if (weaponName == "godgun")
			{
				weaponName = "TestGod";
			}
			else if (weaponName == "pump_uc")
			{
				weaponName = "WID_Shotgun_Standard_Athena_C_Ore_T03";
			}
			else if (weaponName == "pump_r")
			{
				weaponName = "WID_Shotgun_Standard_Athena_UC_Ore_T03";
			}
			else if (weaponName == "pump_vr")
			{
				weaponName = "WID_Shotgun_Standard_Athena_VR_Ore_T03";
			}
			else if (weaponName == "pump_sr")
			{
				weaponName = "WID_Shotgun_Standard_Athena_SR_Ore_T03";
			}
			else if (weaponName == "flint_c")
			{
				weaponName = "WID_Pistol_Flintlock_Athena_C";
			}
			else if (weaponName == "flint_uc")
			{
				weaponName = "WID_Pistol_Flintlock_Athena_UC";
			}
			else if (weaponName == "flight")
			{
				weaponName = "Builder_WID_YEETknock_UR";
			}
			else if (weaponName == "deagle_vr")
			{
				weaponName = "WID_Pistol_HandCannon_Athena_VR_Ore_T03";
			}
			else if (weaponName == "deagle_sr")
			{
				weaponName = "WID_Pistol_HandCannon_Athena_SR_Ore_T03";
			}
			else if (weaponName == "heavy_vr")
			{
				weaponName = "WID_Sniper_Heavy_Athena_VR_Ore_T03";
			}
			else if (weaponName == "heavy_sr")
			{
				weaponName = "WID_Sniper_Heavy_Athena_SR_Ore_T03";
			}
			else if (weaponName == "hunting_uc")
			{
				weaponName = "WID_Sniper_NoScope_Athena_UC_Ore_T03";
			}
			else if (weaponName == "hunting_r")
			{
				weaponName = "WID_Sniper_NoScope_Athena_R_Ore_T03";
			}
			else if (weaponName == "hunting_vr")
			{
				weaponName = "WID_Sniper_NoScope_Athena_VR_Ore_T03";
			}
			else if (weaponName == "hunting_sr")
			{
				weaponName = "WID_Sniper_NoScope_Athena_SR_Ore_T03";
			}
			else if (weaponName == "bolt_uc")
			{
				weaponName = "WID_Sniper_BoltAction_Scope_Athena_UC_Ore_T03";
			}
			else if (weaponName == "bolt_r")
			{
				weaponName = "WID_Sniper_BoltAction_Scope_Athena_R_Ore_T03";
			}
			else if (weaponName == "bolt_vr")
			{
				weaponName = "WID_Sniper_BoltAction_Scope_Athena_VR_Ore_T03";
			}
			else if (weaponName == "bolt_sr")
			{
				weaponName = "WID_Sniper_BoltAction_Scope_Athena_UC_Ore_T03";
			}
			else if (weaponName == "suppressed_vr")
			{
				weaponName = "WID_Sniper_Suppressed_Scope_Athena_VR_Ore_T03";
			}
			else if (weaponName == "suppressed_sr")
			{
				weaponName = "WID_Sniper_Suppressed_Scope_Athena_SR_Ore_T03";
			}
			else if (weaponName == "semi_uc")
			{
				weaponName = "WID_Sniper_Standard_Scope_Athena_VR_Ore_T03";
			}
			else if (weaponName == "semi_r")
			{
				weaponName = "WID_Sniper_Standard_Scope_Athena_SR_Ore_T03";
			}
			else if (weaponName == "stormscout_vr")
			{
				weaponName = "WID_Sniper_Weather_Athena_VR";
			}
			else if (weaponName == "stormscout_sr")
			{
				weaponName = "WID_Sniper_Weather_Athena_SR";
			}
			else if (weaponName == "lever_uc")
			{
				weaponName = "WID_Sniper_Cowboy_Athena_UC";
			}
			else if (weaponName == "lever_r")
			{
				weaponName = "WID_Sniper_Cowboy_Athena_R";
			}
			else if (weaponName == "lever_vr")
			{
				weaponName = "WID_Sniper_Cowboy_Athena_VR";
			}
			else if (weaponName == "lever_sr")
			{
				weaponName = "WID_Sniper_Cowboy_Athena_SR";
			}
			else if (weaponName == "hunterbolt_uc")
			{
				weaponName = "WID_Sniper_CoreSniper_Athena_UC";
			}
			else if (weaponName == "hunterbolt_r")
			{
				weaponName = "WID_Sniper_CoreSniper_Athena_R";
			}
			else if (weaponName == "hunterbolt_vr")
			{
				weaponName = "WID_Sniper_CoreSniper_Athena_VR";
			}
			else if (weaponName == "hunterbolt_sr")
			{
				weaponName = "WID_Sniper_CoreSniper_Athena_SR";
			}
			else if (weaponName == "rocket_r")
			{
				weaponName = "WID_Launcher_Rocket_Athena_R_Ore_T03";
			}
			else if (weaponName == "rocket_vr")
			{
				weaponName = "WID_Launcher_Rocket_Athena_VR_Ore_T03";
			}
			else if (weaponName == "rocket_sr")
			{
				weaponName = "WID_Launcher_Rocket_Athena_SR_Ore_T03";
			}
			else if (weaponName == "pumpkin_uc")
			{
				weaponName = "WID_Launcher_Pumpkin_Athena_UC_Ore_T03";
			}
			else if (weaponName == "pumpkin_r")
			{
				weaponName = "WID_Launcher_Pumpkin_Athena_R_Ore_T03";
			}
			else if (weaponName == "pumpkin_vr")
			{
				weaponName = "WID_Launcher_Pumpkin_Athena_VR_Ore_T03";
			}
			else if (weaponName == "pumpkin_sr")
			{
				weaponName = "WID_Launcher_Pumpkin_Athena_SR_Ore_T03";
			}
			else if (weaponName == "gl_r")
			{
				weaponName = "WID_Launcher_Grenade_Athena_R_Ore_T03";
			}
			else if (weaponName == "gl_vr")
			{
				weaponName = "WID_Launcher_Grenade_Athena_VR_Ore_T03";
			}
			else if (weaponName == "gl_sr")
			{
				weaponName = "WID_Launcher_Grenade_Athena_SR_Ore_T03";
			}
			else if (weaponName == "quad_vr")
			{
				weaponName = "WID_Launcher_Military_Athena_VR_Ore_T03";
			}
			else if (weaponName == "quad_sr")
			{
				weaponName = "WID_Launcher_Military_Athena_SR_Ore_T03";
			}
			else if (weaponName == "proxy_vr")
			{
				weaponName = "WID_GrenadeLauncher_Prox_Athena_VR";
			}
			else if (weaponName == "proxy_sr")
			{
				weaponName = "WID_GrenadeLauncher_Prox_Athena_SR";
			}
			else if (weaponName == "proxy_sr")
			{
				weaponName = "WID_GrenadeLauncher_Prox_Athena_SR";
			}
			else if (weaponName == "xenonbow")
			{
				weaponName = "WID_Sniper_Neon_Bow_SR_Crystal_T04";
			}
			else if (weaponName == "kits" || weaponName == "kitslauncher")
			{
				weaponName = "WID_Launcher_Shockwave_Athena_UR_Ore_T03";
			}
			else if (weaponName == "rift")
			{
				weaponName = "Athena_Rift_Item";
			}
			else if (weaponName == "snowman" || weaponName == "snowmen")
			{
				weaponName = "AGID_SneakySnowmanV2";
			}
			else if (weaponName == "crashpad")
			{
				weaponName = "WID_Athena_AppleSun";
			}
			else if (weaponName == "chillers" || weaponName == "chiller" || weaponName == "chillergrenade")
			{
				weaponName = "Athena_IceGrenade";
			}
			else if (weaponName == "can" || weaponName == "rustycan")
			{
				weaponName = "WID_Athena_Bucket_Old";
			}
			else if (weaponName == "coal")
			{
				weaponName = "WID_Athena_Bucket_Coal";
			}
			else if (weaponName == "stink" || weaponName == "stinkbomb")
			{
				weaponName = "Athena_GasGrenade";
			}
			else if (weaponName == "fishingrod")
			{
				weaponName = "WID_Athena_FloppingRabbit";
			}
			else if (weaponName == "shieldbubble")
			{
				weaponName = "Athena_SilverBlazer_V2";
			}
			else if (weaponName == "zaptrap")
			{
				weaponName = "Athena_ZippyTrout";
			}
			else if (weaponName == "balloons")
			{
				weaponName = "Athena_Balloons_Consumable" || weaponName == "Athena_Balloons";
			}
			else if (weaponName == "shockwave" || weaponName == "shock" || weaponName == "shockwavegrenade")
			{
				weaponName = "Athena_ShockGrenade";
			}
			else if (weaponName == "impulse" || weaponName == "impulsegrenade")
			{
				weaponName = "Athena_KnockGrenade";
			}
			else if (weaponName == "portafortress")
			{
				weaponName = "Athena_SuperTowerGrenade_A";
			}
			else if (weaponName == "presents" || weaponName == "present")
			{
				weaponName = "Athena_BirthdayGiftBox";
			}
			else if (weaponName == "hopflop" || weaponName == "hopflopper")
			{
				weaponName = "WID_Athena_Flopper_HopFlopper";
			}
			else if (weaponName == "zeropoint" || weaponName == "zeropointfish")
			{
				weaponName = "WID_Athena_Flopper_Zero";
			}
			else if (weaponName == "hopdrops" || weaponName == "hopdrop")
			{
				weaponName = "WID_Athena_HopDrop";
			}
			else if (weaponName == "chugsplash" || weaponName == "chug" || weaponName == "chugs")
			{
				weaponName = "Athena_ChillBronco";
			}
			else if (weaponName == "minis" || weaponName == "mini")
			{
				weaponName = "Athena_ShieldSmall";
			}
			else if (weaponName == "bandage")
			{
				weaponName = "Athena_Bandage";
			}
			else if (weaponName == "portafort")
			{
				weaponName = "Athena_TowerGrenade";
			}
			else if (weaponName == "c4")
			{
				weaponName = "Athena_C4";
			}
			else if (weaponName == "stormflip")
			{
				weaponName = "Athena_DogSweater";
			}
			else if (weaponName == "firefly")
			{
				weaponName = "WID_Athena_Grenade_Molotov";
			}
			else if (weaponName == "tire")
			{
				weaponName = "ID_ValetMod_Tires_OffRoad_Thrown";
			}
			else if (weaponName == "spiderman" || weaponName == "spider-man")
			{
				weaponName = "WID_WestSausage_Parallel";
			}
			else if (weaponName == "doomgauntlets")
			{
				weaponName = "WID_HighTower_Date_ChainLightning_CoreBR";
			}
			else if (weaponName == "ironman" || weaponName == "iron-man")
			{
				weaponName = "AGID_AshtonPack_Indigo";
			}
			else if (weaponName == "dub")
			{
				weaponName = "WID_WaffleTruck_Dub";
			}
			else if (weaponName == "hoprockdualies" || weaponName == "dualies")
			{
				weaponName = "WID_WaffleTruck_HopRockDualies";
			}
			else if (weaponName == "bigchill")
			{
				weaponName = "WID_WaffleTruck_ChillerLauncher";
			}
			else if (weaponName == "firesniper")
			{
				weaponName = "WID_WaffleTruck_Sniper_DragonBreath";
			}
			else if (weaponName == "recon")
			{
				weaponName = "AGID_Athena_Scooter";
			}
			else if (weaponName == "harpoon")
			{
				weaponName = "WID_Athena_HappyGhost_Infinite";
			}
			else if (weaponName == "grappler" || weaponName == "grap" || weaponName == "grapple")
			{
				weaponName = "WID_Hook_Gun_Slide";
			}
			else if (weaponName == "jules" || weaponName == "julesgrappler" || weaponName == "julesgrap")
			{
				weaponName = "WID_Boss_GrapplingHoot";
			}
			else if (weaponName == "skyesgrappler" || weaponName == "skye" || weaponName == "skyegrap")
			{
				weaponName = "WID_Boss_Adventure_GH";
			}
			else if (weaponName == "captainamerica" || weaponName == "shield")
			{
				weaponName = "AGID_AshtonPack_Chicago";
			}
			else if (weaponName == "thorshammer" || weaponName == "thor")
			{
				weaponName = "AGID_AshtonPack_Turbo";
			}
			else if (weaponName == "broom")
			{
				weaponName = "WID_Athena_WitchBroom";
			}
			else if (weaponName == "grapplerbow" || weaponName == "grapplebow")
			{
				weaponName = "WID_Athena_Bow_Grappler";
			}
			else if (weaponName == "shockwavebow" || weaponName == "shockbow")
			{
				weaponName = "WID_Bow_Shockwave_Athena_SR";
			}
			else if (weaponName == "icygrap" || weaponName == "icygrappler")
			{
				weaponName = "WID_Athena_IcyGrapple";
			}
			else if (weaponName == "stwpumpkin" || weaponName == "stwrocket")
			{
				weaponName = "WID_Launcher_Pumpkin_RPG_SR_Ore_T01";
			}
			else if (weaponName == "stwtrash" || weaponName == "stwtrashcannon")
			{
				weaponName = "WID_Launcher_Scavenger_SR_Ore_T05";
			}
			else if (weaponName == "grabitron")
			{
				weaponName = "WID_GravyGoblinV2_Athena";
			}

			auto WID = Cast<UFortWorldItemDefinition>(FindObject(weaponName, nullptr, ANY_PACKAGE));

			if (!WID)
			{
				SendMessageToConsole(PlayerController, L"Invalid WID! This might mean the item you're looking for may not exist in the current version!");
				return;
			}

			bool bShouldUpdate = false;
			WorldInventory->AddItem(WID, &bShouldUpdate, count);

			if (bShouldUpdate)
				WorldInventory->Update();

			SendMessageToConsole(PlayerController, L"Granted item!");
		}
		else if (Command == "togglesnowmap")
		{
			if (Calendar::HasSnowModification())
			{
				static bool bFirst = false;

				static float FullSnowValue = Calendar::GetFullSnowMapValue();
				static float NoSnowValue = 0.0f;

				bFirst ? Calendar::SetSnow(NoSnowValue) : Calendar::SetSnow(FullSnowValue);

				bFirst = !bFirst;

				SendMessageToConsole(PlayerController, L"Set full snow map!");
			}
			else
			{
				SendMessageToConsole(PlayerController, L"Version doesn't have any snow modification!");
			}
		}
		/* else if (Command == "debugattributes")
		{
			auto AbilitySystemComponent = ReceivingPlayerState->GetAbilitySystemComponent();

			if (!AbilitySystemComponent)
			{
				SendMessageToConsole(PlayerController, L"No AbilitySystemComponent!");
				return;
			}

			SendMessageToConsole(PlayerController, (L"AbilitySystemComponent->GetSpawnedAttributes().Num(): " + std::to_wstring(AbilitySystemComponent->GetSpawnedAttributes().Num())).c_str());

			for (int i = 0; i < AbilitySystemComponent->GetSpawnedAttributes().Num(); ++i)
			{
				auto CurrentAttributePathName = AbilitySystemComponent->GetSpawnedAttributes().at(i)->GetPathName();
				SendMessageToConsole(PlayerController, (L"SpawnedAttribute Name: " + std::wstring(CurrentAttributePathName.begin(), CurrentAttributePathName.end())).c_str());
			}
		}
		else if (Command == "debugcurrentitem")
		{
			auto Pawn = ReceivingController->GetMyFortPawn();

			if (!Pawn)
			{
				SendMessageToConsole(PlayerController, L"No pawn!");
				return;
			}

			auto CurrentWeapon = Pawn->GetCurrentWeapon();

			if (!CurrentWeapon)
			{
				SendMessageToConsole(PlayerController, L"No CurrentWeapon!");
				return;
			}

			auto WorldInventory = ReceivingController->GetWorldInventory();

			if (!CurrentWeapon)
			{
				SendMessageToConsole(PlayerController, L"No WorldInventory!");
				return;
			}

			auto ItemInstance = WorldInventory->FindItemInstance(CurrentWeapon->GetItemEntryGuid());
			auto ReplicatedEntry = WorldInventory->FindReplicatedEntry(CurrentWeapon->GetItemEntryGuid());

			if (!ItemInstance)
			{
				SendMessageToConsole(PlayerController, L"Failed to find ItemInstance!");
				return;
			}

			if (!ReplicatedEntry)
			{
				SendMessageToConsole(PlayerController, L"Failed to find ReplicatedEntry!");
				return;
			}

			SendMessageToConsole(PlayerController, (L"ReplicatedEntry->GetGenericAttributeValues().Num(): " + std::to_wstring(ReplicatedEntry->GetGenericAttributeValues().Num())).c_str());
			SendMessageToConsole(PlayerController, (L"ReplicatedEntry->GetStateValues().Num(): " + std::to_wstring(ReplicatedEntry->GetStateValues().Num())).c_str());

			for (int i = 0; i < ReplicatedEntry->GetStateValues().Num(); ++i)
			{
				SendMessageToConsole(PlayerController, (L"[{}] StateValue Type: "
					+ std::to_wstring((int)ReplicatedEntry->GetStateValues().at(i, FFortItemEntryStateValue::GetStructSize()).GetStateType())).c_str()
				);
			}
		} */
		else if (Command == "op")
		{
			if (ReceivingController == PlayerController)
			{
				SendMessageToConsole(PlayerController, L"You can't op yourself!");
				return;
			}

			if (IsOp(ReceivingController))
			{
				SendMessageToConsole(PlayerController, L"Player is already operator!");
				return;
			}

			Op(ReceivingController);
			SendMessageToConsole(PlayerController, L"Granted operator to player!");
		}
		else if (Command == "deop")
		{
			if (!IsOp(ReceivingController))
			{
				SendMessageToConsole(PlayerController, L"Player is not operator!");
				return;
			}

			Deop(ReceivingController);
			SendMessageToConsole(PlayerController, L"Removed operator from player!");
		}
		else if (Command == "setpickaxe")
		{
			if (NumArgs < 1)
			{
				SendMessageToConsole(PlayerController, L"Please provide a pickaxe!");
				return;
			}

			if (Fortnite_Version < 3) // Idk why but emptyslot kicks the player because of the validate.
			{
				SendMessageToConsole(PlayerController, L"Not supported on this version!");
				return;
			}

			auto WorldInventory = ReceivingController->GetWorldInventory();

			if (!WorldInventory)
			{
				SendMessageToConsole(PlayerController, L"No world inventory!");
				return;
			}

			auto& pickaxeName = Arguments[1];
			static auto AthenaPickaxeItemDefinitionClass = FindObject<UClass>(L"/Script/FortniteGame.AthenaPickaxeItemDefinition");

			auto Pickaxe1 = FindObject(pickaxeName + "." + pickaxeName, nullptr, ANY_PACKAGE);

			UFortWeaponMeleeItemDefinition* NewPickaxeItemDefinition = nullptr;

			if (Pickaxe1)
			{
				if (Pickaxe1->IsA(AthenaPickaxeItemDefinitionClass))
				{
					static auto WeaponDefinitionOffset = Pickaxe1->GetOffset("WeaponDefinition");
					NewPickaxeItemDefinition = Pickaxe1->Get<UFortWeaponMeleeItemDefinition*>(WeaponDefinitionOffset);
				}
				else
				{
					NewPickaxeItemDefinition = Cast<UFortWeaponMeleeItemDefinition>(Pickaxe1);
				}
			}

			if (!NewPickaxeItemDefinition)
			{
				SendMessageToConsole(PlayerController, L"Invalid pickaxe item definition!");
				return;
			}

			auto PickaxeInstance = WorldInventory->GetPickaxeInstance();

			if (PickaxeInstance)
			{
				WorldInventory->RemoveItem(PickaxeInstance->GetItemEntry()->GetItemGuid(), nullptr, PickaxeInstance->GetItemEntry()->GetCount(), true);
			}

			WorldInventory->AddItem(NewPickaxeItemDefinition, nullptr, 1);
			WorldInventory->Update();

			SendMessageToConsole(PlayerController, L"Successfully set pickaxe!");
		}
		else if (Command == "load")
		{
			if (!Globals::bCreative)
			{
				SendMessageToConsole(PlayerController, L"It is not creative!");
				return;
			}

			static auto CreativePlotLinkedVolumeOffset = ReceivingController->GetOffset("CreativePlotLinkedVolume", false);
			auto Volume = CreativePlotLinkedVolumeOffset == -1 ? nullptr : ReceivingController->GetCreativePlotLinkedVolume();

			if (Arguments.size() <= 1)
			{
				SendMessageToConsole(PlayerController, L"Please provide a filename!\n");
				return;
			}

			std::string FileName = "islandSave";

			try { FileName = Arguments[1]; }
			catch (...) {}

			float X{ -1 }, Y{ -1 }, Z{ -1 };

			if (Arguments.size() >= 4)
			{
				try { X = std::stof(Arguments[2]); }
				catch (...) {}
				try { Y = std::stof(Arguments[3]); }
				catch (...) {}
				try { Z = std::stof(Arguments[4]); }
				catch (...) {}
			}
			else
			{
				if (!Volume)
				{
					SendMessageToConsole(PlayerController, L"They do not have an island!");
					return;
				}
			}

			if (X != -1 && Y != -1 && Z != -1) // omg what if they want to spawn it at -1 -1 -1!!!
				Builder::LoadSave(FileName, FVector(X, Y, Z), FRotator());
			else
				Builder::LoadSave(FileName, Volume);

			SendMessageToConsole(PlayerController, L"Loaded!");
		}
		else if (Command == "spawnpickup")
		{
			if (NumArgs < 1)
			{
				SendMessageToConsole(PlayerController, L"Please provide a WID!");
				return;
			}

			auto Pawn = ReceivingController->GetMyFortPawn();

			if (!Pawn)
			{
				SendMessageToConsole(PlayerController, L"No pawn!");
				return;
			}

			auto& weaponName = Arguments[1];
			int count = 1;
			int amount = 1;

			try
			{
				if (NumArgs >= 2)
					count = std::stoi(Arguments[2]);
				if (NumArgs >= 3)
					amount = std::stoi(Arguments[3]);
			}
			catch (...)
			{
			}

			constexpr int Max = 100;

			if (amount > Max)
			{
				SendMessageToConsole(PlayerController, (std::wstring(L"You went over the limit! Only spawning ") + std::to_wstring(Max) + L".").c_str());
				amount = Max;
			}

			// LOG_INFO(LogDev, "weaponName: {}", weaponName);

			auto WID = Cast<UFortWorldItemDefinition>(FindObject(weaponName, nullptr, ANY_PACKAGE));

			if (!WID)
			{
				SendMessageToConsole(PlayerController, L"Invalid WID!");
				return;
			}

			auto Location = Pawn->GetActorLocation();

			auto GameState = Cast<AFortGameStateAthena>(GetWorld()->GetGameState());

			PickupCreateData CreateData;
			CreateData.ItemEntry = FFortItemEntry::MakeItemEntry(WID, count, -1, MAX_DURABILITY, WID->GetFinalLevel(GameState->GetWorldLevel()));
			CreateData.SpawnLocation = Location;
			CreateData.bShouldFreeItemEntryWhenDeconstructed = true;

			for (int i = 0; i < amount; i++)
			{
				AFortPickup::SpawnPickup(CreateData);
			}
		}
		else if (Command == "getlocation")
		{
			auto Pawn = ReceivingController->GetMyFortPawn();

			auto PawnLocation = Pawn->GetActorLocation();

			FString Loc = PawnLocation.ToString();

			SendMessageToConsole(PlayerController, Loc);

			Pawn->CopyToClipboard(Loc);
		}
		else if (Command == "listplayers")
		{
			std::string PlayerNames;

			for (int i = 0; i < ClientConnections.Num(); i++)
			{
				static auto PlayerControllerOffset = ClientConnections.at(i)->GetOffset("PlayerController");
				auto CurrentPlayerController = Cast<AFortPlayerControllerAthena>(ClientConnections.at(i)->Get(PlayerControllerOffset));

				if (!CurrentPlayerController)
					continue;

				auto CurrentPlayerState = Cast<AFortPlayerStateAthena>(CurrentPlayerController->GetPlayerState());

				if (!CurrentPlayerState->IsValidLowLevel())
					continue;

				PlayerNames += "\"" + CurrentPlayerState->GetPlayerName().ToString() + "\" ";
			}

			SendMessageToConsole(PlayerController, std::wstring(PlayerNames.begin(), PlayerNames.end()).c_str());
		}
		else if (Command == "launch")
		{
			if (Arguments.size() <= 3)
			{
				SendMessageToConsole(PlayerController, L"Please provide X, Y, and Z!\n");
				return;
			}

			float X{}, Y{}, Z{};

			try { X = std::stof(Arguments[1]); }
			catch (...) {}
			try { Y = std::stof(Arguments[2]); }
			catch (...) {}
			try { Z = std::stof(Arguments[3]); }
			catch (...) {}

			auto Pawn = ReceivingController->GetMyFortPawn();

			if (!Pawn)
			{
				SendMessageToConsole(PlayerController, L"No pawn to teleport!");
				return;
			}

			static auto LaunchCharacterFn = FindObject<UFunction>(L"/Script/Engine.Character.LaunchCharacter");

			struct
			{
				FVector                                     LaunchVelocity;                                           // (Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
				bool                                               bXYOverride;                                              // (Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
				bool                                               bZOverride;                                               // (Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
			} ACharacter_LaunchCharacter_Params{ FVector(X, Y, Z), false, false };
			Pawn->ProcessEvent(LaunchCharacterFn, &ACharacter_LaunchCharacter_Params);

			SendMessageToConsole(PlayerController, L"Launched character!");
		}
		else if (Command == "setshield")
		{
			auto Pawn = ReceivingController->GetMyFortPawn();

			if (!Pawn)
			{
				SendMessageToConsole(PlayerController, L"No pawn!");
				return;
			}

			float Shield = 0.f;

			if (NumArgs >= 1)
			{
				try { Shield = std::stof(Arguments[1]); }
				catch (...) {}
			}

			Pawn->SetShield(Shield);
			SendMessageToConsole(PlayerController, L"Set shield!\n");
		}
		else if (Command == "god")
		{
			auto Pawn = ReceivingController->GetMyFortPawn();

			if (!Pawn)
			{
				SendMessageToConsole(PlayerController, L"No pawn!");
				return;
			}

			Pawn->SetCanBeDamaged(!Pawn->CanBeDamaged());
			SendMessageToConsole(PlayerController, std::wstring(L"God set to " + std::to_wstring(!(bool)Pawn->CanBeDamaged())).c_str());
		}
		else if (Command == "applycid")
		{
			auto PlayerState = Cast<AFortPlayerState>(ReceivingController->GetPlayerState());

			if (!PlayerState) // ???
			{
				SendMessageToConsole(PlayerController, L"No playerstate!");
				return;
			}

			auto Pawn = Cast<AFortPlayerPawn>(ReceivingController->GetMyFortPawn());

			std::string CIDStr = Arguments[1];
			auto CIDDef = FindObject(CIDStr, nullptr, ANY_PACKAGE);
			// auto CIDDef = UObject::FindObject<UAthenaCharacterItemDefinition>(CIDStr);

			if (!CIDDef)
			{
				SendMessageToConsole(PlayerController, L"Invalid character item definition!");
				return;
			}

			LOG_INFO(LogDev, "Applying {}", CIDDef->GetFullName());

			if (!ApplyCID(Pawn, CIDDef))
			{
				SendMessageToConsole(PlayerController, L"Failed while applying skin! Please check the server log.");
				return;
			}

			SendMessageToConsole(PlayerController, L"Applied CID!");
		}
		else if (Command == "suicide")
		{
			static auto ServerSuicideFn = FindObject<UFunction>("/Script/FortniteGame.FortPlayerController.ServerSuicide");
			ReceivingController->ProcessEvent(ServerSuicideFn);
		}
		else if (Command == "summon")
		{
			if (Arguments.size() <= 1)
			{
				SendMessageToConsole(PlayerController, L"Please provide a class!\n");
				return;
			}

			auto& ClassName = Arguments[1];

			/* if (ClassName.contains("/Script/"))
			{
				SendMessageToConsole(PlayerController, L"For now, we don't allow non-blueprint classes.\n");
				return;
			} */

			auto Pawn = ReceivingController->GetPawn();

			if (!Pawn)
			{
				SendMessageToConsole(PlayerController, L"No pawn to spawn class at!");
				return;
			}

			int Count = 1;

			if (Arguments.size() >= 3)
			{
				try { Count = std::stod(Arguments[2]); }
				catch (...) {}
			}

			constexpr int Max = 100;

			if (Count > Max)
			{
				SendMessageToConsole(PlayerController, (std::wstring(L"You went over the limit! Only spawning ") + std::to_wstring(Max) + L".").c_str());
				Count = Max;
			}

			static auto BGAClass = FindObject<UClass>(L"/Script/Engine.BlueprintGeneratedClass");
			static auto ClassClass = FindObject<UClass>(L"/Script/CoreUObject.Class");
			auto ClassObj = ClassName.contains("/Script/") ? FindObject<UClass>(ClassName, ClassClass) : LoadObject<UClass>(ClassName, BGAClass); // scuffy

			if (ClassObj)
			{
				int AmountSpawned = 0;

				for (int i = 0; i < Count; i++)
				{
					auto Loc = Pawn->GetActorLocation();
					Loc.Z += 1000;
					auto NewActor = GetWorld()->SpawnActor<AActor>(ClassObj, Loc, FQuat(), FVector(1, 1, 1));

					if (!NewActor)
					{
						SendMessageToConsole(PlayerController, L"Failed to spawn an actor!");
					}
					else
					{
						AmountSpawned++;
					}
				}

				SendMessageToConsole(PlayerController, L"Summoned!");
			}
			else
			{
				SendMessageToConsole(PlayerController, L"Not a valid class!");
			}
		}
		else if (Command == "spawnbottest")
		{
			// /Game/Athena/AI/MANG/BotData/

			if (NumArgs < 1)
			{
				SendMessageToConsole(PlayerController, L"Please provide a customization object!");
				return;
			}

			auto Pawn = ReceivingController->GetPawn();

			if (!Pawn)
			{
				SendMessageToConsole(PlayerController, L"No pawn to spawn bot at!");
				return;
			}

			auto CustomizationData = LoadObject<UFortAthenaAIBotCustomizationData>(Arguments[1], UFortAthenaAIBotCustomizationData::StaticClass());

			if (!CustomizationData)
			{
				SendMessageToConsole(PlayerController, L"Invalid CustomizationData!");
				return;
			}

			auto NewPawn = SpawnAIFromCustomizationData(Pawn->GetActorLocation(), CustomizationData);

			if (NewPawn)
			{
				SendMessageToConsole(PlayerController, L"Spawned!");
			}
			else
			{
				SendMessageToConsole(PlayerController, L"Failed to spawn!");
			}
		}
		else if (Command == "spawnbot")
		{
			auto Pawn = ReceivingController->GetPawn();

			if (!Pawn)
			{
				SendMessageToConsole(PlayerController, L"No pawn to spawn bot at!");
				return;
			}

			int Count = 1;

			if (Arguments.size() >= 2)
			{
				try { Count = std::stod(Arguments[1]); }
				catch (...) {}
			}

			constexpr int Max = 99;

			if (Count > Max)
			{
				SendMessageToConsole(PlayerController, (std::wstring(L"You went over the limit! Only spawning ") + std::to_wstring(Max) + L".").c_str());
				Count = Max;
			}

			int AmountSpawned = 0;

			for (int i = 0; i < Count; i++)
			{
				FActorSpawnParameters SpawnParameters{};
				// SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

				auto Loc = Pawn->GetActorLocation();
				Loc.Z += 1000;

				FTransform Transform;
				Transform.Translation = Loc;
				Transform.Scale3D = FVector(1, 1, 1);

				auto NewActor = Bots::SpawnBot(Transform);

				if (!NewActor)
				{
					SendMessageToConsole(PlayerController, L"Failed to spawn an actor!");
				}
				else
				{
					AmountSpawned++;
				}
			}

			SendMessageToConsole(PlayerController, L"Summoned!");
		}
		else if (Command == "sethealth")
		{
			auto Pawn = ReceivingController->GetMyFortPawn();

			if (!Pawn)
			{
				SendMessageToConsole(PlayerController, L"No pawn!");
				return;
			}

			float Health = 100.f;

			try { Health = std::stof(Arguments[1]); }
			catch (...) {}

			Pawn->SetHealth(Health);
			SendMessageToConsole(PlayerController, L"Set health!\n");
		}
		else if (Command == "pausesafezone")
		{
			auto GameState = Cast<AFortGameStateAthena>(GetWorld()->GetGameState());
			auto GameMode = Cast<AFortGameModeAthena>(GetWorld()->GetGameMode());

			UKismetSystemLibrary::ExecuteConsoleCommand(GetWorld(), L"pausesafezone", nullptr);
			// GameMode->PauseSafeZone(GameState->IsSafeZonePaused() == 0);
		}
		else if (Command == "teleport" || Command == "tp")
		{
			auto CheatManager = ReceivingController->SpawnCheatManager(UCheatManager::StaticClass());

			if (!CheatManager)
			{
				SendMessageToConsole(PlayerController, L"Failed to spawn player's cheat manager!");
				return;
			}

			CheatManager->Teleport();
			CheatManager = nullptr;
			SendMessageToConsole(PlayerController, L"Teleported!");
		}
		else if (Command == "wipequickbar" || Command == "wipequickbars")
		{
			bool bWipePrimary = false;
			bool bWipeSecondary = false;
			bool bCheckShouldBeDropped = true;

			bool bWipeSingularQuickbar = Command != "wipequickbars";

			if (bWipeSingularQuickbar)
			{
				if (Arguments.size() <= 1)
				{
					SendMessageToConsole(PlayerController, L"Please provide \"primary\" or \"secondary\"!\n");
					return;
				}

				std::string quickbarType = Arguments[1];
				std::transform(quickbarType.begin(), quickbarType.end(), quickbarType.begin(), ::tolower);

				if (quickbarType == "primary") bWipePrimary = true;
				if (quickbarType == "secondary") bWipeSecondary = true;
			}
			else
			{
				bWipePrimary = true;
				bWipeSecondary = true;
			}

			if (!bWipePrimary && !bWipeSecondary)
			{
				SendMessageToConsole(PlayerController, L"Please provide \"primary\" or \"secondary\"!\n");
				return;
			}

			if (Arguments.size() > 1 + bWipeSingularQuickbar)
			{
				std::string bypassCanBeDropped = Arguments[1 + bWipeSingularQuickbar];
				std::transform(bypassCanBeDropped.begin(), bypassCanBeDropped.end(), bypassCanBeDropped.begin(), ::tolower);

				if (bypassCanBeDropped == "true") bCheckShouldBeDropped = true;
				else if (bypassCanBeDropped == "false") bCheckShouldBeDropped = false;
			}

			auto WorldInventory = ReceivingController->GetWorldInventory();

			if (!WorldInventory)
			{
				SendMessageToConsole(PlayerController, L"Player does not have a WorldInventory!\n");
				return;
			}

			static auto FortEditToolItemDefinitionClass = FindObject<UClass>(L"/Script/FortniteGame.FortEditToolItemDefinition");
			static auto FortBuildingItemDefinitionClass = FindObject<UClass>(L"/Script/FortniteGame.FortBuildingItemDefinition");

			std::vector<std::pair<FGuid, int>> GuidsAndCountsToRemove;
			const auto& ItemInstances = WorldInventory->GetItemList().GetItemInstances();
			auto PickaxeInstance = WorldInventory->GetPickaxeInstance();

			for (int i = 0; i < ItemInstances.Num(); ++i)
			{
				auto ItemInstance = ItemInstances.at(i);
				const auto ItemDefinition = Cast<UFortWorldItemDefinition>(ItemInstance->GetItemEntry()->GetItemDefinition());

				if (bCheckShouldBeDropped
					? ItemDefinition->CanBeDropped()
					: !ItemDefinition->IsA(FortBuildingItemDefinitionClass)
					&& !ItemDefinition->IsA(FortEditToolItemDefinitionClass)
					&& ItemInstance != PickaxeInstance
					)
				{
					bool IsPrimary = IsPrimaryQuickbar(ItemDefinition);

					if ((bWipePrimary && IsPrimary) || (bWipeSecondary && !IsPrimary))
					{
						GuidsAndCountsToRemove.push_back({ ItemInstance->GetItemEntry()->GetItemGuid(), ItemInstance->GetItemEntry()->GetCount() });
					}
				}
			}

			for (auto& [Guid, Count] : GuidsAndCountsToRemove)
			{
				WorldInventory->RemoveItem(Guid, nullptr, Count, true);
			}

			WorldInventory->Update();

			SendMessageToConsole(PlayerController, L"Cleared!\n");
		}
		else if (Command == "destroytarget")
		{
			auto CheatManager = ReceivingController->SpawnCheatManager(UCheatManager::StaticClass());

			if (!CheatManager)
			{
				SendMessageToConsole(PlayerController, L"Failed to spawn player's cheat manager!");
				return;
			}

			CheatManager->DestroyTarget();
			CheatManager = nullptr;
			SendMessageToConsole(PlayerController, L"Destroyed target!");
		}
		else if (Command == "bugitgo")
		{
			if (Arguments.size() <= 3)
			{
				SendMessageToConsole(PlayerController, L"Please provide X, Y, and Z!\n");
				return;
			}

			float X{}, Y{}, Z{};

			try { X = std::stof(Arguments[1]); }
			catch (...) {}
			try { Y = std::stof(Arguments[2]); }
			catch (...) {}
			try { Z = std::stof(Arguments[3]); }
			catch (...) {}

			auto Pawn = Cast<APawn>(ReceivingController->GetPawn());

			if (!Pawn)
			{
				SendMessageToConsole(PlayerController, L"No pawn to teleport!");
				return;
			}

			Pawn->TeleportTo(FVector(X, Y, Z), Pawn->GetActorRotation());
			SendMessageToConsole(PlayerController, L"Teleported!");
		}
		else { bSendHelpMessage = true; };
	}
	else { bSendHelpMessage = true; };

	if (bSendHelpMessage)
	{
		FString HelpMessage = LR"(
cheat giveitem <ShortWID> <Count=1> - Gives a weapon to the executing player, if inventory is full drops a pickup on the player.
cheat grant <name_rarity> (ex: rocket_sr) - Gives a weapon using a shortcut name, without ID.
cheat togglesnowmap - Toggles between full snow map and zero snow map.
cheat getlocation - Gets the location of your player and copies it to the hoster's clipboard.
cheat summon <BlueprintClassPathName> <Count=1> - Summons the specified blueprint class at the executing player's location. Note: There is a limit on the count.
cheat bugitgo <X> <Y> <Z> - Teleport to a location.
cheat launch <X> <Y> <Z> - Launches a player.
cheat listplayers - Gives you all players names.
cheat pausesafezone - Pauses the zone.
cheat sethealth <Health=100.f> - Sets executing player's health.
cheat setshield <Shield=0.f> - Sets executing player's shield.
cheat applycid <CIDShortName> - Sets a player's character.
cheat spawnpickup <ShortWID> <ItemCount=1> <PickupCount=1> - Spawns a pickup at specified player.
cheat teleport/tp - Teleports to what the player is looking at.
cheat spawnbot <Amount=1> - Spawns a bot at the player (experimental).
cheat setpickaxe <PickaxeID> - Set player's pickaxe. Can be either the PID or WID
cheat destroytarget - Destroys the actor that the player is looking at.
cheat wipequickbar <Primary|Secondary> <RemoveUndroppables=false> - Wipes the specified quickbar (parameters is not case sensitive).
cheat wipequickbars <RemoveUndroppables=false> - Wipes primary and secondary quickbar of targeted player (parameter is not case sensitive).
cheat suicide - Makes targeted player suicide. 

If you want to execute a command on a certain player, surround their name (case sensitive) with \, and put the param with their name anywhere. Example: cheat sethealth \Milxnor\ 100
)";

		SendMessageToConsole(PlayerController, HelpMessage);
	}
}
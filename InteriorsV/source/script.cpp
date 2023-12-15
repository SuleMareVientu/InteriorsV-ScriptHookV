//ScriptHook
#include <natives.h>
// #include <types.h> //Already included in globals.h
#include <main.h>
//Custom
#include "script.h"
#include "globals.h"
#include "utils\ini.h"
#include "utils\blips.h"
#include "utils\interiors.h"
#include "utils\onlineteleports.h"

Ped playerPed = NULL;
Vector3 playerLoc{NULL, NULL, NULL, NULL, NULL, NULL};
bool missionFlag = NULL;

void update()
{
	playerLoc = ENTITY::GET_ENTITY_COORDS(playerPed, false);

	//Prints current interior ID
	//Print(ToString(INTERIOR::GET_INTERIOR_AT_COORDS(playerLoc.x, playerLoc.y, playerLoc.z)), 5000);

	//Safehouses
	ClintonResidence();
	FranklinMansion();
	MichaelHouse();
	TrevorTrailer();

	//Mission Interiors
	PremiumDeluxeMotorsport();
	LesterHouse();
	LesterFactory();
	Lifeinvader();
	FloydHouse();
	Vangelico();
	MaxRenda();
	FIB();
	Chopshop();
	TequiLaLa();
	FameorShame();
	CluckingBell();
	Foundry();
	EpsilonRoom();
	JanitorHouse();
	ONeilRanch();
	Scrapyard();
	HumaneLab();
	OmegaGarage();
	BlaineCountyBank();
	DignityYacht();
	ContainerShip();
	UnionDepositoryVault();
	UnionDepositoryParking();
	Slaughterhouse();
	SolomonOffice();
	Methlab();
	Morgue();
	Motel();

	//Unused Interiors
	PaletoSheriffOffice();
	SandySheriffOffice();
	PoliceStationRooms();
	YanktonSurveillance();
	PacificBankVault();
	FleecaBanks();

	//Misc Interiors
	Misc();

	//Scenario Groups
	ScenarioGroups();

	//Map Fixes
	Fixes();
	return;
}

void ScriptMain()
{
	ReadINI();
	SYSTEM::SETTIMERA(0);
	while (true)
	{
		playerPed = PLAYER::PLAYER_PED_ID();
		missionFlag = MISC::GET_MISSION_FLAG();
		
		//Check if player exists
		if (!ENTITY::DOES_ENTITY_EXIST(playerPed))
			return;

		//Updates 1 time every 5 seconds
		if (SYSTEM::TIMERA() > 5000)
		{
			SYSTEM::SETTIMERA(0);
			update();
			AddBlips();
		}
		else
		{
			playerLoc = ENTITY::GET_ENTITY_COORDS(playerPed, false);
			UnlockDoors();	//These doors need to be unlocked every frame
		}

		//Blips toggle. Default Key: F3 (https://docs.fivem.net/docs/game-references/controls/)
		if (PAD::IS_DISABLED_CONTROL_JUST_PRESSED(2, 170))
		{
			if (iniBlips)
				RemoveBlips();
			else
			{
				iniBlips = true;
				AddBlips();
			}
		}
		Teleports();
		WAIT(0);
	}
	return;
}
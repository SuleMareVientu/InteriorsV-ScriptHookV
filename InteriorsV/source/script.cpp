//ScriptHook
#include <natives.h>
// #include <types.h> //Already included in globals.h
#include <main.h>
//Custom
#include "script.h"
#include "globals.h"
#include "utils\ini.h"
#include "utils\keyboard.h"
#include "utils\blips.h"
#include "utils\interiors.h"
#include "utils\onlineteleports.h"

Vector3 playerLoc{ NULL, NULL, NULL, NULL, NULL, NULL };
Ped playerPed = NULL;
bool missionFlag = NULL;
bool playerControl = false;

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

		if (PLAYER::IS_PLAYER_CONTROL_ON(PLAYER::PLAYER_ID()) && !CUTSCENE::IS_CUTSCENE_PLAYING())
			playerControl = true;
		else
			playerControl = false;

		//Check if player exists and scene is not loading
		while (!ENTITY::DOES_ENTITY_EXIST(playerPed))
		{
			WAIT(0);
		}

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
			UnlockDoors();	//These doors need to be unlocked every frame. Now also includes teleport markers for story interiors
		}

		//Blips toggle. Default Key: F3 (https://learn.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes)
		if (IsKeyJustUp(iniToggleBlips))
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
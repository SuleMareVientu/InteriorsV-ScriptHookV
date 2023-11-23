//ScriptHook
#include "natives.h"
#include "types.h"
#include "main.h"
//Custom
#include "script.h"
#include "globals.h"
#include "interiors.h"

Vector3 playerLoc;

static void update()
{
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
	FIBLobby();
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
	MerryweatherDock();
	StripclubBackDoor();
	Slaughterhouse();

	//Unused Interiors
	PaletoSheriffOffice();
	SandySheriffOffice();
	PoliceStationRooms();
	GarageNearUD();
	YanktonSurveillance(); 
	PacificBankVault();
	FleecaBanks();

	//Scenario Groups
	ScenarioGroups();

	//Map Fixes
	Fixes();
	return;
}

void ScriptMain()
{
	SYSTEM::SETTIMERA(0);
	while (true)
	{
		//Check if player exists
		if (ENTITY::DOES_ENTITY_EXIST(PLAYER::PLAYER_PED_ID()))
		{
			playerLoc = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), false);
			//Updates 1 time every 5 seconds
			if (SYSTEM::TIMERA() > 5000)
			{
				SYSTEM::SETTIMERA(0);
				update();
			}
			else
				UnlockDoors();	//These doors need to be unlocked every frame
		}
		WAIT(0);
	}
	return;
}
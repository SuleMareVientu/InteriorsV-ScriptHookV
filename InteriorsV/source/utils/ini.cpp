#include <SimpleIni.h>
#include "ini.h"

//General Settings
bool iniBlips = false;
bool iniSafehouses = true;
bool iniMissionInteriors = true;
bool iniUnusedInteriors = true;

//Interiors
//Safehouses
bool iniClintonResidence = false;
bool iniFranklinMansion = false;
bool iniMichaelHouse = false;
bool iniTrevorTrailer = false;
//Mission Interiors
bool iniPremiumDeluxeMotorsport = false;
bool iniLesterHouse = false;
bool iniLesterFactory = false;
bool iniLifeinvader = false;
bool iniFloydHouse = false;
bool iniVangelico = false;
bool iniMaxRenda = false;
bool iniFIBLobby = false;
bool iniChopshop = false;
bool iniTequiLaLa = false;
bool iniFameorShame = false;
bool iniCluckingBell = false;
bool iniFoundry = false;
bool iniEpsilonRoom = false;
bool iniJanitorHouse = false;
bool iniONeilRanch = false;
bool iniScrapyard = false;
bool iniHumaneLab = false;
bool iniOmegaGarage = false;
bool iniBlaineCountyBank = false;
bool iniDignityYacht = false;
bool iniContainerShip = false;
bool iniUnionDepositoryParking = false;
bool iniMerryweatherDock = false;
bool iniStripclubBackDoor = false;
bool iniSlaughterhouse = false;
//Unused Interiors
bool iniPaletoSheriffOffice = false;
bool iniSandySheriffOffice = false;
bool iniPoliceStationRooms = false;
bool iniGarageNearUD = false;
bool iniYanktonSurveillance = false;
bool iniPacificBankVault = false;
bool iniFleecaBanks = false;

//Extras
//Scenario Groups
bool iniScenarioGroups = true;
//Map Fixes
bool iniFixes = true;

void ReadINI()
{
	CSimpleIniA ini;
	SI_Error res = ini.LoadFile("InteriorsV.ini");

	if (res != SI_OK)
		return;

//////////////////////////////////////Settings//////////////////////////////////////
	iniBlips = ini.GetBoolValue("Settings", "Blips", false);
	iniSafehouses = ini.GetBoolValue("Settings", "Safehouses", true);
	iniMissionInteriors = ini.GetBoolValue("Settings", "MissionInteriors", true);
	iniUnusedInteriors = ini.GetBoolValue("Settings", "UnusedInteriors", true);

//////////////////////////////////////Interiors//////////////////////////////////////
		//Safehouses
	if (iniSafehouses)
	{
		iniClintonResidence = ini.GetBoolValue("Interiors", "ClintonResidence", true);
		iniFranklinMansion = ini.GetBoolValue("Interiors", "FranklinMansion", true);
		iniMichaelHouse = ini.GetBoolValue("Interiors", "MichaelHouse", true);
		iniTrevorTrailer = ini.GetBoolValue("Interiors", "TrevorTrailer", true);
	}

	//Mission Interiors
	if (iniMissionInteriors)
	{
		iniPremiumDeluxeMotorsport = ini.GetBoolValue("Interiors", "PremiumDeluxeMotorsport", true);
		iniLesterHouse = ini.GetBoolValue("Interiors", "LesterHouse", true);
		iniLesterFactory = ini.GetBoolValue("Interiors", "LesterFactory", true);
		iniLifeinvader = ini.GetBoolValue("Interiors", "Lifeinvader", true);
		iniFloydHouse = ini.GetBoolValue("Interiors", "FloydHouse", true);
		iniVangelico = ini.GetBoolValue("Interiors", "Vangelico", true);
		iniMaxRenda = ini.GetBoolValue("Interiors", "MaxRenda", true);
		iniFIBLobby = ini.GetBoolValue("Interiors", "FIBLobby", true);
		iniChopshop = ini.GetBoolValue("Interiors", "Chopshop", true);
		iniTequiLaLa = ini.GetBoolValue("Interiors", "TequiLaLa", true);
		iniFameorShame = ini.GetBoolValue("Interiors", "FameorShame", true);
		iniCluckingBell = ini.GetBoolValue("Interiors", "CluckingBell", true);
		iniFoundry = ini.GetBoolValue("Interiors", "Foundry", true);
		iniEpsilonRoom = ini.GetBoolValue("Interiors", "EpsilonRoom", true);
		iniJanitorHouse = ini.GetBoolValue("Interiors", "JanitorHouse", true);
		iniONeilRanch = ini.GetBoolValue("Interiors", "ONeilRanch", true);
		iniScrapyard = ini.GetBoolValue("Interiors", "Scrapyard", true);
		iniHumaneLab = ini.GetBoolValue("Interiors", "HumaneLab", true);
		iniOmegaGarage = ini.GetBoolValue("Interiors", "OmegaGarage", true);
		iniBlaineCountyBank = ini.GetBoolValue("Interiors", "BlaineCountyBank", true);
		iniDignityYacht = ini.GetBoolValue("Interiors", "DignityYacht", true);
		iniContainerShip = ini.GetBoolValue("Interiors", "ContainerShip", true);
		iniUnionDepositoryParking = ini.GetBoolValue("Interiors", "UnionDepositoryParking", true);
		iniMerryweatherDock = ini.GetBoolValue("Interiors", "MerryweatherDock", true);
		iniStripclubBackDoor = ini.GetBoolValue("Interiors", "StripclubBackDoor", true);
		iniSlaughterhouse = ini.GetBoolValue("Interiors", "Slaughterhouse", true);
	}

	//Unused Interiors
	if (iniUnusedInteriors)
	{
		iniPaletoSheriffOffice = ini.GetBoolValue("Interiors", "PaletoSheriffOffice", true);
		iniSandySheriffOffice = ini.GetBoolValue("Interiors", "SandySheriffOffice", true);
		iniPoliceStationRooms = ini.GetBoolValue("Interiors", "PoliceStationRooms", true);
		iniGarageNearUD = ini.GetBoolValue("Interiors", "GarageNearUD", true);
		iniYanktonSurveillance = ini.GetBoolValue("Interiors", "YanktonSurveillance", true);
		iniPacificBankVault = ini.GetBoolValue("Interiors", "PacificBankVault", true);
		iniFleecaBanks = ini.GetBoolValue("Interiors", "PacificBankVault", true);
	}

//////////////////////////////////////Extras//////////////////////////////////////
		//Scenario Groups
		iniScenarioGroups = ini.GetBoolValue("Extras", "ScenarioGroups", true);
		//Map Fixes
		iniFixes = ini.GetBoolValue("Extras", "Fixes", true);

		return;
}
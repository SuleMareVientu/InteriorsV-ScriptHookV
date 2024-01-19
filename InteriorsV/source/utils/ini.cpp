#include <SimpleIni.h>
#include "ini.h"
#include "../globals.h"
#include "blips.h"

//Keys
DWORD iniToggleBlips = 0x72;	//F3

//General Settings
bool iniBlips = true;
bool iniBlipsOnlineApartments = false;
bool iniStoryCompatibility = true;
bool iniSafehouses = true;
bool iniMissionInteriors = true;
bool iniUnusedInteriors = true;
bool iniOnlineInteriors = true;
bool iniMiscInteriors = true;
bool iniGates = true;

//Extras
bool iniUnlockBarriersNearPlayer = true;
bool iniScenarioGroups = true;

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
bool iniFIB = false;
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
bool iniUnionDepository = false;
bool iniSlaughterhouse = false;
bool iniSolomonOffice = false;
bool iniMethlab = false;
bool iniMorgue = false;
bool iniMotel = false;
//Unused Interiors
bool iniPaletoSheriffOffice = false;
bool iniSandySheriffOffice = false;
bool iniPoliceStationRooms = false;
bool iniYanktonSurveillance = false;
bool iniPacificBankVault = false;
bool iniFleecaBanks = false;
//Online Interiors
bool iniLowEndApartments = false;
bool iniMediumEndApartments = false;
bool iniHighEndApartments = false;

void ReadINI()
{
	CSimpleIniA ini;
	SI_Error res = ini.LoadFile("InteriorsV.ini");

	if (res != SI_OK)
		return;

//////////////////////////////////////Keys//////////////////////////////////////////
	
	iniToggleBlips = ini.GetLongValue("Keys", "ToggleBlips", 0x72);

//////////////////////////////////////Settings//////////////////////////////////////

	iniBlips = ini.GetBoolValue("Settings", "Blips", true);
	iniBlipsOnlineApartments = ini.GetBoolValue("Settings", "BlipsOnlineApartments", false);
	iniStoryCompatibility = ini.GetBoolValue("Settings", "StoryCompatibility", true);
	iniSafehouses = ini.GetBoolValue("Settings", "Safehouses", true);
	iniMissionInteriors = ini.GetBoolValue("Settings", "MissionInteriors", true);
	iniOnlineInteriors = ini.GetBoolValue("Settings", "OnlineInteriors", true);
	iniUnusedInteriors = ini.GetBoolValue("Settings", "UnusedInteriors", true);
	iniMiscInteriors = ini.GetBoolValue("Settings", "MiscInteriors", true);
	iniGates = ini.GetBoolValue("Settings", "Gates", true);

//////////////////////////////////////Extras////////////////////////////////////////

	iniUnlockBarriersNearPlayer = ini.GetBoolValue("Extras", "UnlockBarriersNearPlayer", true);
	iniScenarioGroups = ini.GetBoolValue("Extras", "ScenarioGroups", true);

//////////////////////////////////////Interiors/////////////////////////////////////
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
		iniFIB = ini.GetBoolValue("Interiors", "FIB", true);
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
		iniUnionDepository = ini.GetBoolValue("Interiors", "UnionDepository", true);
		iniSlaughterhouse = ini.GetBoolValue("Interiors", "Slaughterhouse", true);
		iniSolomonOffice = ini.GetBoolValue("Interiors", "SolomonOffice", true);
		iniMethlab = ini.GetBoolValue("Interiors", "Methlab", true);
		iniMorgue = ini.GetBoolValue("Interiors", "Morgue", true);
		iniMotel = ini.GetBoolValue("Interiors", "Motel", true);
	}

	//Unused Interiors
	if (iniUnusedInteriors)
	{
		iniPaletoSheriffOffice = ini.GetBoolValue("Interiors", "PaletoSheriffOffice", true);
		iniSandySheriffOffice = ini.GetBoolValue("Interiors", "SandySheriffOffice", true);
		iniPoliceStationRooms = ini.GetBoolValue("Interiors", "PoliceStationRooms", true);
		iniYanktonSurveillance = ini.GetBoolValue("Interiors", "YanktonSurveillance", true);
		iniPacificBankVault = ini.GetBoolValue("Interiors", "PacificBankVault", true);
		iniFleecaBanks = ini.GetBoolValue("Interiors", "FleecaBanks", true);
	}

	//Online Interiors
	if (iniOnlineInteriors)
	{
		iniLowEndApartments = ini.GetBoolValue("Interiors", "LowEndApartments", true);
		iniMediumEndApartments = ini.GetBoolValue("Interiors", "MediumEndApartments", true);
		iniHighEndApartments = ini.GetBoolValue("Interiors", "HighEndApartments", true);
	}

//////////////////////////////////////Blips//////////////////////////////////////
	BlipPremiumDeluxeMotorsport.enable = iniPremiumDeluxeMotorsport;
	BlipLesterHouse.enable = iniLesterHouse;
	BlipLesterFactory.enable = iniLesterFactory;
	BlipLifeinvader.enable = iniLifeinvader;
	BlipVangelico.enable = iniVangelico;
	BlipMaxRenda.enable = iniMaxRenda;
	BlipFIB.enable = iniFIB;
	BlipChopshop.enable = iniChopshop;
	BlipTequiLaLa.enable = iniTequiLaLa;
	BlipFameorShame.enable = iniFameorShame;
	BlipCluckingBell.enable = iniCluckingBell;
	BlipFoundry.enable = iniFoundry;
	BlipEpsilonRoom.enable = iniEpsilonRoom;
	BlipJanitorHouse.enable = iniJanitorHouse;
	BlipONeilRanch.enable = iniONeilRanch;
	BlipScrapyard.enable = iniScrapyard;
	BlipHumaneLab.enable = iniHumaneLab;
	BlipOmegaGarage.enable = iniOmegaGarage;
	BlipBlaineCountyBank.enable = iniBlaineCountyBank;
	BlipDignityYacht.enable = iniDignityYacht;
	BlipContainerShip.enable = iniContainerShip;
	BlipUnionDepositoryParking.enable = iniUnionDepository;
	BlipSlaughterhouse.enable = iniSlaughterhouse;
	BlipSolomonOffice.enable = iniSolomonOffice;
	BlipMethlab.enable = iniMethlab;
	BlipMorgue.enable = iniMorgue;
	BlipMotel.enable = iniMotel;
	BlipPaletoSheriffOffice.enable = iniPaletoSheriffOffice;
	BlipSandySheriffOffice.enable = iniSandySheriffOffice;
	BlipPacificBank.enable = iniPacificBankVault;
	//Online Apartments
	//Low-end Apartments
	BlipZancudoAvenue140.enable = iniLowEndApartments;
	BlipGrapeseedAvenue1893.enable = iniLowEndApartments;
	BlipLasLagunasBoulevard2143.enable = iniLowEndApartments;
	BlipCougarAvenue0069.enable = iniLowEndApartments;
	BlipProsperityStreet1237.enable = iniLowEndApartments;
	BlipSanVitasStreet1561.enable = iniLowEndApartments;
	BlipBoulevardDelPerro1115.enable = iniLowEndApartments;
	BlipVespucciBoulevard2057.enable = iniLowEndApartments;
	BlipSouthRockfordDrive0112.enable = iniLowEndApartments;
	//Medium Apartments
	BlipHangmanAve4.enable = iniMediumEndApartments;
	BlipProcopioDrive4401.enable = iniMediumEndApartments;
	BlipProcopioDrive4584.enable = iniMediumEndApartments;
	BlipBayCityAvenue0115.enable = iniMediumEndApartments;
	BlipMiltonRoad0184.enable = iniMediumEndApartments;
	BlipSustanciaRoad12.enable = iniMediumEndApartments;
	BlipSouthMoMiltonDrive0504.enable = iniMediumEndApartments;
	BlipSouthRockfordDrive0325.enable = iniMediumEndApartments;
	BlipDreamTower.enable = iniMediumEndApartments;
	BlipPowerStreet1162.enable = iniMediumEndApartments;
	BlipSpanishAvenue0605.enable = iniMediumEndApartments;
	BlipLasLagunasBoulevard0604.enable = iniMediumEndApartments;
	BlipTheRoyale.enable = iniMediumEndApartments;
	//High-end Apartments
	BlipEclipseTowersApartments.enable = iniHighEndApartments;
	BlipWeazelPlazaApartments.enable = iniHighEndApartments;
	BlipTinselTowersApartments.enable = iniHighEndApartments;
	BlipRichardsMajesticApartments.enable = iniHighEndApartments;
	Blip4IntegrityWayApartments.enable = iniHighEndApartments;
	Blip3AltaStreetTowerApartments.enable = iniHighEndApartments;
	BlipDelPerroHeightsApartments.enable = iniHighEndApartments;
	return;
}
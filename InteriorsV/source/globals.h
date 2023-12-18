#pragma once

#include <types.h>

extern Ped playerPed;
extern Vector3 playerLoc;
extern bool missionFlag;
extern Hash doorHash;
extern float distance;
extern bool isInsideApartment;

//////////////////////////////////////INI Settings//////////////////////////////////////

//Keys
extern DWORD iniToggleBlips;

//General Settings
extern bool iniBlips;
extern bool iniBlipsOnlineApartments;
extern bool iniStoryCompatibility;
extern bool iniSafehouses;
extern bool iniMissionInteriors;
extern bool iniUnusedInteriors;
extern bool iniOnlineInteriors;
extern bool iniMiscInteriors;

//Interiors
//Safehouses
extern bool iniClintonResidence;
extern bool iniFranklinMansion;
extern bool iniMichaelHouse;
extern bool iniTrevorTrailer;
//Mission Interiors
extern bool iniPremiumDeluxeMotorsport;
extern bool iniLesterHouse;
extern bool iniLesterFactory;
extern bool iniLifeinvader;
extern bool iniFloydHouse;
extern bool iniVangelico;
extern bool iniMaxRenda;
extern bool iniFIB;
extern bool iniChopshop;
extern bool iniTequiLaLa;
extern bool iniFameorShame;
extern bool iniCluckingBell;
extern bool iniFoundry;
extern bool iniEpsilonRoom;
extern bool iniJanitorHouse;
extern bool iniONeilRanch;
extern bool iniScrapyard;
extern bool iniHumaneLab;
extern bool iniOmegaGarage;
extern bool iniBlaineCountyBank;
extern bool iniDignityYacht;
extern bool iniContainerShip;
extern bool iniUnionDepository;
extern bool iniSlaughterhouse;
extern bool iniSolomonOffice;
extern bool iniMethlab;
extern bool iniMorgue;
extern bool iniMotel;
//Unused Interiors
extern bool iniPaletoSheriffOffice;
extern bool iniSandySheriffOffice;
extern bool iniPoliceStationRooms;
extern bool iniYanktonSurveillance;
extern bool iniPacificBankVault;
extern bool iniFleecaBanks;
//Online Interiors
extern bool iniLowEndApartments;
extern bool iniMediumEndApartments;
extern bool iniHighEndApartments;

//Extras
//Scenario Groups
extern bool iniScenarioGroups;
//Map Fixes
extern bool iniFixes;

//////////////////////////////////////Blips//////////////////////////////////////
class CustomBlip {
public:
	Blip blip = NULL;
	bool enable = false;
	void AddBlip(float x, float y, float z, float scale, char* title, int id, int colour);
	void RemoveBlip();
};

extern CustomBlip BlipPremiumDeluxeMotorsport;
extern CustomBlip BlipLesterHouse;
extern CustomBlip BlipLesterFactory;
extern CustomBlip BlipLifeinvader;
extern CustomBlip BlipVangelico;
extern CustomBlip BlipMaxRenda;
extern CustomBlip BlipFIB;
extern CustomBlip BlipChopshop;
extern CustomBlip BlipTequiLaLa;
extern CustomBlip BlipFameorShame;
extern CustomBlip BlipCluckingBell;
extern CustomBlip BlipFoundry;
extern CustomBlip BlipEpsilonRoom;
extern CustomBlip BlipJanitorHouse;
extern CustomBlip BlipONeilRanch;
extern CustomBlip BlipScrapyard;
extern CustomBlip BlipHumaneLab;
extern CustomBlip BlipOmegaGarage;
extern CustomBlip BlipBlaineCountyBank;
extern CustomBlip BlipDignityYacht;
extern CustomBlip BlipContainerShip;
extern CustomBlip BlipUnionDepositoryParking;
extern CustomBlip BlipSlaughterhouse;
extern CustomBlip BlipSolomonOffice;
extern CustomBlip BlipMethlab;
extern CustomBlip BlipMorgue;
extern CustomBlip BlipMotel;
extern CustomBlip BlipPaletoSheriffOffice;
extern CustomBlip BlipSandySheriffOffice;
extern CustomBlip BlipPacificBank;
//Online Apartments
//Low-end Apartments
extern CustomBlip BlipZancudoAvenue140;
extern CustomBlip BlipGrapeseedAvenue1893;
extern CustomBlip BlipLasLagunasBoulevard2143;
extern CustomBlip BlipCougarAvenue0069;
extern CustomBlip BlipProsperityStreet1237;
extern CustomBlip BlipSanVitasStreet1561;
extern CustomBlip BlipBoulevardDelPerro1115;
extern CustomBlip BlipVespucciBoulevard2057;
extern CustomBlip BlipSouthRockfordDrive0112;
//Medium Apartments
extern CustomBlip BlipHangmanAve4;
extern CustomBlip BlipProcopioDrive4401;
extern CustomBlip BlipProcopioDrive4584;
extern CustomBlip BlipBayCityAvenue0115;
extern CustomBlip BlipMiltonRoad0184;
extern CustomBlip BlipSustanciaRoad12;
extern CustomBlip BlipSouthMoMiltonDrive0504;
extern CustomBlip BlipSouthRockfordDrive0325;
extern CustomBlip BlipDreamTower;
extern CustomBlip BlipPowerStreet1162;
extern CustomBlip BlipSpanishAvenue0605;
extern CustomBlip BlipLasLagunasBoulevard0604;
extern CustomBlip BlipTheRoyale;
//High-end Apartments
extern CustomBlip BlipEclipseTowersApartments;
extern CustomBlip BlipWeazelPlazaApartments;
extern CustomBlip BlipTinselTowersApartments;
extern CustomBlip BlipRichardsMajesticApartments;
extern CustomBlip Blip4IntegrityWayApartments;
extern CustomBlip Blip3AltaStreetTowerApartments;
extern CustomBlip BlipDelPerroHeightsApartments;
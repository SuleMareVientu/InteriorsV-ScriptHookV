//ScriptHook
#include <natives.h>
// #include <types.h> //Already included in globals.h
//Custom
#include "blips.h"
#include "functions.h"
#include "../globals.h"

CustomBlip BlipPremiumDeluxeMotorsport;
CustomBlip BlipLesterHouse;
CustomBlip BlipLesterFactory;
CustomBlip BlipLifeinvader;
CustomBlip BlipVangelico;
CustomBlip BlipMaxRenda;
CustomBlip BlipFIB;
CustomBlip BlipChopshop;
CustomBlip BlipTequiLaLa;
CustomBlip BlipFameorShame;
CustomBlip BlipCluckingBell;
CustomBlip BlipFoundry;
CustomBlip BlipEpsilonRoom;
CustomBlip BlipJanitorHouse;
CustomBlip BlipONeilRanch;
CustomBlip BlipScrapyard;
CustomBlip BlipHumaneLab;
CustomBlip BlipOmegaGarage;
CustomBlip BlipBlaineCountyBank;
CustomBlip BlipDignityYacht;
CustomBlip BlipContainerShip;
CustomBlip BlipUnionDepositoryParking;
CustomBlip BlipSlaughterhouse;
CustomBlip BlipSolomonOffice;
CustomBlip BlipMethlab;
CustomBlip BlipMorgue;
CustomBlip BlipMotel;
CustomBlip BlipPaletoSheriffOffice;
CustomBlip BlipSandySheriffOffice;
CustomBlip BlipPacificBank;
//Online Apartments
//Low-end Apartments
CustomBlip BlipZancudoAvenue140;
CustomBlip BlipGrapeseedAvenue1893;
CustomBlip BlipLasLagunasBoulevard2143;
CustomBlip BlipCougarAvenue0069;
CustomBlip BlipProsperityStreet1237;
CustomBlip BlipSanVitasStreet1561;
CustomBlip BlipBoulevardDelPerro1115;
CustomBlip BlipVespucciBoulevard2057;
CustomBlip BlipSouthRockfordDrive0112;
//Medium Apartments
CustomBlip BlipHangmanAve4;
CustomBlip BlipProcopioDrive4401;
CustomBlip BlipProcopioDrive4584;
CustomBlip BlipBayCityAvenue0115;
CustomBlip BlipMiltonRoad0184;
CustomBlip BlipSustanciaRoad12;
CustomBlip BlipSouthMoMiltonDrive0504;
CustomBlip BlipSouthRockfordDrive0325;
CustomBlip BlipDreamTower;
CustomBlip BlipPowerStreet1162;
CustomBlip BlipSpanishAvenue0605;
CustomBlip BlipLasLagunasBoulevard0604;
CustomBlip BlipTheRoyale;
//High-end Apartments
CustomBlip BlipEclipseTowersApartments;
CustomBlip BlipWeazelPlazaApartments;
CustomBlip BlipTinselTowersApartments;
CustomBlip BlipRichardsMajesticApartments;
CustomBlip Blip4IntegrityWayApartments;
CustomBlip Blip3AltaStreetTowerApartments;
CustomBlip BlipDelPerroHeightsApartments;

void CustomBlip::AddBlip(float x, float y, float z, float scale, char* title, int id, int colour)
{
	if (!enable || HUD::DOES_BLIP_EXIST(blip))
		return;

	blip = HUD::ADD_BLIP_FOR_COORD(x, y, z);
	HUD::SET_BLIP_SPRITE(blip, id);
	HUD::SET_BLIP_DISPLAY(blip, 4);
	HUD::SET_BLIP_SCALE(blip, scale);
	HUD::SET_BLIP_COLOUR(blip, colour);
	HUD::SET_BLIP_AS_SHORT_RANGE(blip, true);
	HUD::BEGIN_TEXT_COMMAND_SET_BLIP_NAME("STRING");
	HUD::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(title);
	HUD::END_TEXT_COMMAND_SET_BLIP_NAME(blip);
	return;
}

void CustomBlip::RemoveBlip()
{
	if (HUD::DOES_BLIP_EXIST(blip))
	{
		HUD::SET_BLIP_ROUTE(blip, false);
		HUD::REMOVE_BLIP(&blip);
	}
	return;
}

//Only main interiors are included (e.g. Fleeca Banks aren't shown, safehouses also)
void AddBlips()
{
	if (!iniBlips)
		return;

	int colour = 0;

	//Online Apartments
	if (iniBlipsOnlineApartments)
	{
		//Low-end Apartments
		char* lowEndText = "Low-end Apartment";
		BlipZancudoAvenue140.AddBlip(1900.1719f, 3772.9207f, 31.8744f, 1.00f, lowEndText, 40, 24);
		BlipGrapeseedAvenue1893.AddBlip(1662.7830f, 4776.2407f, 41.0076f, 1.00f, lowEndText, 40, 24);
		BlipLasLagunasBoulevard2143.AddBlip(-42.0982f, -58.3112f, 62.4603f, 1.00f, lowEndText, 40, 24);
		BlipCougarAvenue0069.AddBlip(-1533.477f, -326.7305f, 46.9113f, 1.00f, lowEndText, 40, 24);
		BlipProsperityStreet1237.AddBlip(-1564.138f, -406.5406f, 41.3890f, 1.00f, lowEndText, 40, 24);
		BlipSanVitasStreet1561.AddBlip(-201.4327f, 186.2523f, 79.3276f, 1.00f, lowEndText, 40, 24);
		BlipBoulevardDelPerro1115.AddBlip(-1606.642f, -432.2548f, 39.4367f, 1.00f, lowEndText, 40, 24);
		BlipVespucciBoulevard2057.AddBlip(-662.4279f, -853.6377f, 23.4586f, 1.00f, lowEndText, 40, 24);
		BlipSouthRockfordDrive0112.AddBlip(-813.2224f, -980.9390f, 13.1482f, 1.00f, lowEndText, 40, 24);
		//Medium Apartments
		char* mediumEndText = "Medium Apartment";
		BlipHangmanAve4.AddBlip(-1406.0433f, 526.8655f, 122.8362f, 1.00f, mediumEndText, 40, 18);
		BlipProcopioDrive4401.AddBlip(-302.4685f, 6327.2275f, 31.8920f, 1.00f, mediumEndText, 40, 18);
		BlipProcopioDrive4584.AddBlip(-105.3389f, 6528.8530f, 29.1719f, 1.00f, mediumEndText, 40, 18);
		BlipBayCityAvenue0115.AddBlip(-969.9915f, -1431.375f, 6.6792f, 1.00f, mediumEndText, 40, 18);
		BlipMiltonRoad0184.AddBlip(-511.7271f, 108.5600f, 62.8006f, 1.00f, mediumEndText, 40, 18);
		BlipSustanciaRoad12.AddBlip(1342.2675f, -1578.931f, 53.0533f, 1.00f, mediumEndText, 40, 18);
		BlipSouthMoMiltonDrive0504.AddBlip(-628.2673f, 169.7025f, 60.1525f, 1.00f, mediumEndText, 40, 18);
		BlipSouthRockfordDrive0325.AddBlip(-831.4262f, -862.1733f, 19.6947f, 1.00f, mediumEndText, 40, 18);
		BlipDreamTower.AddBlip(-762.9729f, -753.7900f, 26.8736f, 1.00f, mediumEndText, 40, 18);
		BlipPowerStreet1162.AddBlip(285.6400f, -160.2583f, 63.6221f, 1.00f, mediumEndText, 40, 18);
		BlipSpanishAvenue0605.AddBlip(3.3769f, 36.5695f, 70.5354f, 1.00f, mediumEndText, 40, 18);
		BlipLasLagunasBoulevard0604.AddBlip(9.6973f, 81.8959f, 77.4352f, 1.00f, mediumEndText, 40, 18);
		BlipTheRoyale.AddBlip(-197.6927f, 86.0134f, 68.7562f, 1.00f, mediumEndText, 40, 18);
		//High-end Apartments
		char* highEndText = "High-end Apartments";
		BlipEclipseTowersApartments.AddBlip(-775.0563f, 312.8823f, 84.6982f, 1.00f, highEndText, 40, 36);
		BlipWeazelPlazaApartments.AddBlip(-915.3770f, -452.9363f, 38.5999f, 1.00f, highEndText, 40, 36);
		BlipTinselTowersApartments.AddBlip(-616.9627f, 37.4050f, 42.5870f, 1.00f, highEndText, 40, 36);
		BlipRichardsMajesticApartments.AddBlip(-934.8232f, -381.5349f, 37.9613f, 1.00f, highEndText, 40, 36);
		Blip4IntegrityWayApartments.AddBlip(-47.9679f, -587.2177f, 36.9580f, 1.00f, highEndText, 40, 36);
		Blip3AltaStreetTowerApartments.AddBlip(-262.5153f, -971.1097f, 30.2198f, 1.00f, highEndText, 40, 36);
		BlipDelPerroHeightsApartments.AddBlip(-1442.0504f, -545.0800f, 33.7418f, 1.00f, highEndText, 40, 36);
	}

	BlipPremiumDeluxeMotorsport.AddBlip(-40.31f, -1097.43f, 26.80f, 1.00f, "Premium Deluxe Motorsport", 225, colour);
	BlipLesterHouse.AddBlip(1272.11f, -1715.84f, 55.00f, 0.90f, "Lester's House", 40, colour);
	BlipLesterFactory.AddBlip(718.61f, -959.62f, 25.00f, 1.00f, "Darnell Bros. Factory", 357, colour);
	BlipLifeinvader.AddBlip(-1067.95f, -243.73f, 38.50f, 0.90f, "Lifeinvader Office", 184, colour);
	BlipVangelico.AddBlip(-622.12f, -232.67f, 38.21f, 1.00f, "Vangelico", 171, colour);
	BlipMaxRenda.AddBlip(-588.63f, -284.51f, 38.21f, 1.00f, "Max Renda", 357, colour);
	BlipFIB.AddBlip(135.66f, -750.20f, 46.50f, 1.50f, "FIB", 188, colour);
	BlipChopshop.AddBlip(478.82f, -1316.81f, 29.35f, 1.00f, "Hayes Autos", 225, colour);
	BlipTequiLaLa.AddBlip(-558.22f, 284.78f, 83.29f, 0.90f, "Tequi-la-la", 93, colour);
	BlipFameorShame.AddBlip(-324.40f, -1970.24f, 31.00f, 1.00f, "Maze Bank Arena", 135, colour);
	BlipCluckingBell.AddBlip(-80.48f, 6243.07f, 32.00f, 1.00f, "Clucking Bell Farms", 273, colour);
	BlipFoundry.AddBlip(1097.63f, -2002.76f, 32.00f, 1.00f, "Grand Banks Steel Foundry", 366, colour);
	BlipEpsilonRoom.AddBlip(243.00f, 369.00f, 106.00f, 1.00f, "Epsilon Room", 206, colour);
	BlipJanitorHouse.AddBlip(-110.37f, -8.16f, 70.67f, 1.00f, "Janitor's House", 40, colour);
	BlipONeilRanch.AddBlip(2444.87f, 4975.30f, 46.5f, 1.00f, "O'Neil Ranch", 40, colour);
	BlipScrapyard.AddBlip(-593.20f, -1614.80f, 27.16f, 1.00f, "Rogers Salvage & Scrap", 318, colour);
	BlipHumaneLab.AddBlip(3618.40f, 3741.43f, 27.69f, 0.90f, "Humane Lab", 51, colour);
	BlipOmegaGarage.AddBlip(2329.54f, 2570.97f, 47.03f, 0.90f, "Omega's Garage", 50, colour);
	BlipBlaineCountyBank.AddBlip(-102.55f, 6465.36f, 31.98f, 1.00f, "Blaine County Bank", 108, colour);
	BlipDignityYacht.AddBlip(-2073.7793f, -1021.6921f, 4.0f, 1.00f, "Dignity Yacht", 404, colour);
	BlipContainerShip.AddBlip(-165.8346f, -2367.0241f, 17.0f, 1.00f, "Container Ship", 404, colour);
	BlipUnionDepositoryParking.AddBlip(7.32f, -712.08f, 34.00f, 0.90f, "Union Depository", 50, colour);
	BlipSlaughterhouse.AddBlip(975.27f, -2158.90f, 31.06f, 1.00f, "Raven Slaughterhouse", 310, colour);
	BlipSolomonOffice.AddBlip(-1011.6970f, -480.1367f, 38.9756f, 1.00f, "Solomon's Office", 120, colour);
	BlipMethlab.AddBlip(1396.8412f, 3610.8347f, 35.0f, 1.00f, "Ace Liquor", 51, colour);
	BlipMorgue.AddBlip(246.0f, -1374.0f, 32.5f, 1.00f, "LS County Morgue", 305, colour);
	BlipMotel.AddBlip(1121.32f, 2642.65f, 39.17f, 1.00f, "The Motor Motel", 40, colour);
	BlipPaletoSheriffOffice.AddBlip(-443.78f, 6009.06f, 31.86f, 1.00f, "Sheriff's Office", 60, colour);
	BlipSandySheriffOffice.AddBlip(1853.56f, 3691.51f, 34.59f, 1.00f, "Sheriff's Office", 60, colour);
	BlipPacificBank.AddBlip(247.9080f, 226.8860f, 110.4328f, 1.00f, "Pacific Standard Bank", 108, colour);
	return;
}

void RemoveBlips()
{
	iniBlips = false;
	BlipPremiumDeluxeMotorsport.RemoveBlip();
	BlipLesterHouse.RemoveBlip();
	BlipLesterFactory.RemoveBlip();
	BlipLifeinvader.RemoveBlip();
	BlipVangelico.RemoveBlip();
	BlipMaxRenda.RemoveBlip();
	BlipFIB.RemoveBlip();
	BlipChopshop.RemoveBlip();
	BlipTequiLaLa.RemoveBlip();
	BlipFameorShame.RemoveBlip();
	BlipCluckingBell.RemoveBlip();
	BlipFoundry.RemoveBlip();
	BlipEpsilonRoom.RemoveBlip();
	BlipJanitorHouse.RemoveBlip();
	BlipONeilRanch.RemoveBlip();
	BlipScrapyard.RemoveBlip();
	BlipHumaneLab.RemoveBlip();
	BlipOmegaGarage.RemoveBlip();
	BlipBlaineCountyBank.RemoveBlip();
	BlipDignityYacht.RemoveBlip();
	BlipContainerShip.RemoveBlip();
	BlipUnionDepositoryParking.RemoveBlip();
	BlipSlaughterhouse.RemoveBlip();
	BlipSolomonOffice.RemoveBlip();
	BlipMethlab.RemoveBlip();
	BlipMorgue.RemoveBlip();
	BlipMotel.RemoveBlip();
	BlipPaletoSheriffOffice.RemoveBlip();
	BlipSandySheriffOffice.RemoveBlip();
	BlipPacificBank.RemoveBlip();
	//Online Apartments
	if (iniBlipsOnlineApartments)
	{
		//Low-end Apartments
		BlipZancudoAvenue140.RemoveBlip();
		BlipGrapeseedAvenue1893.RemoveBlip();
		BlipLasLagunasBoulevard2143.RemoveBlip();
		BlipCougarAvenue0069.RemoveBlip();
		BlipProsperityStreet1237.RemoveBlip();
		BlipSanVitasStreet1561.RemoveBlip();
		BlipBoulevardDelPerro1115.RemoveBlip();
		BlipVespucciBoulevard2057.RemoveBlip();
		BlipSouthRockfordDrive0112.RemoveBlip();
		//Medium Apartments
		BlipHangmanAve4.RemoveBlip();
		BlipProcopioDrive4401.RemoveBlip();
		BlipProcopioDrive4584.RemoveBlip();
		BlipBayCityAvenue0115.RemoveBlip();
		BlipMiltonRoad0184.RemoveBlip();
		BlipSustanciaRoad12.RemoveBlip();
		BlipSouthMoMiltonDrive0504.RemoveBlip();
		BlipSouthRockfordDrive0325.RemoveBlip();
		BlipDreamTower.RemoveBlip();
		BlipPowerStreet1162.RemoveBlip();
		BlipSpanishAvenue0605.RemoveBlip();
		BlipLasLagunasBoulevard0604.RemoveBlip();
		BlipTheRoyale.RemoveBlip();
		//High-end Apartments
		BlipEclipseTowersApartments.RemoveBlip();
		BlipWeazelPlazaApartments.RemoveBlip();
		BlipTinselTowersApartments.RemoveBlip();
		BlipRichardsMajesticApartments.RemoveBlip();
		Blip4IntegrityWayApartments.RemoveBlip();
		Blip3AltaStreetTowerApartments.RemoveBlip();
		BlipDelPerroHeightsApartments.RemoveBlip();
	}
	return;
}
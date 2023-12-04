//ScriptHook
#include <natives.h>
#include <types.h>
//Custom
#include "functions.h"
#include "../globals.h"

//Only main interiors are included (e.g. Fleeca Banks aren't shown, safehouses also)
void AddBlips()
{
	if (!iniBlips)
		return;

	int colour = 4;

	if (iniPremiumDeluxeMotorsport)
		AddBlip(-40.31, -1097.43, 26.80, 1.00, "Premium Deluxe Motorsport", 225, colour);

	if (iniLesterHouse)
		AddBlip(1272.11, -1715.84, 55.00, 0.90, "Lester's House", 40, colour);

	if (iniLesterFactory && !(iniStoryCompatibility && STREAMING::IS_IPL_ACTIVE("id2_14_post_no_int")))
		AddBlip(718.61, -959.62, 25.00, 1.00, "Darnell Bros. Factory", 357, colour);

	if (iniLifeinvader)
		AddBlip(-1067.95, -243.73, 38.50, 0.90, "Lifeinvader Office", 184, colour);

	if (iniVangelico && !(iniStoryCompatibility && STREAMING::IS_IPL_ACTIVE("bh1_16_refurb")))
		AddBlip(-622.12, -232.67, 38.21, 1.00, "Vangelico", 171, colour);

	if (iniMaxRenda)
		AddBlip(-588.63, -284.51, 38.21, 1.00, "Max Renda", 357, colour);

	if (iniFIBLobby)
		AddBlip(135.66, -750.20, 46.50, 1.50, "FIB Lobby", 188, colour);

	if (iniChopshop)
		AddBlip(478.82, -1316.81, 29.35, 1.00, "Hayes Autos", 225, colour);

	if (iniTequiLaLa)
		AddBlip(-558.22, 284.78, 83.29, 0.90, "Tequi-la-la", 93, colour);

	if (iniFameorShame)
		AddBlip(-324.40, -1970.24, 31.00, 1.00, "Maze Bank Arena", 135, colour);

	if (iniCluckingBell)
		AddBlip(-80.48, 6243.07, 32.00, 1.00, "Clucking Bell Farms", 273, colour);

	if (iniFoundry)
		AddBlip(1097.63, -2002.76, 32.00, 1.00, "Grand Banks Steel Foundry", 366, colour);
	
	if (iniEpsilonRoom)
		AddBlip(243.00, 369.00, 106.00, 1.00, "Epsilon Room", 357, colour);

	if (iniJanitorHouse)
		AddBlip(-110.37, -8.16, 70.67, 1.00, "Janitor's House", 40, colour);

	if (iniONeilRanch && !(iniStoryCompatibility && (STREAMING::IS_IPL_ACTIVE("farm_burnt") || STREAMING::IS_IPL_ACTIVE("des_farmhs_endimap"))))
		AddBlip(2444.87, 4975.30, 46.5, 1.00, "O'Neil Ranch", 40, colour);

	if (iniScrapyard)
		AddBlip(-593.20, -1614.80, 27.16, 1.00, "Rogers Salvage & Scrap", 68, colour);

	if (iniHumaneLab)
		AddBlip(3618.40, 3741.43, 27.69, 0.90, "Humane Lab", 51, colour);

	if (iniOmegaGarage)
		AddBlip(2329.54, 2570.97, 47.03, 0.90, "Omega's Garage", 50, colour);

	if (iniBlaineCountyBank)
		AddBlip(-102.55, 6465.36, 31.98, 1.00, "Blaine County Savings Bank", 108, colour);

	if (iniUnionDepositoryParking)
		AddBlip(7.32, -712.08, 34.00, 0.90, "Union Depository Parking", 50, colour);

	if (iniSlaughterhouse)
		AddBlip(975.27, -2158.90, 31.06, 1.00, "Raven Slaughterhouse", 310, colour);

	if (iniPaletoSheriffOffice)
		AddBlip(-443.78, 6009.06, 31.86, 1.00, "Sheriff's Office", 60, colour);

	if (iniSandySheriffOffice)
		AddBlip(1853.56, 3691.51, 34.59, 1.00, "Sheriff's Office", 60, colour);
	return;
}
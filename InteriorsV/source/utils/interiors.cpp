//ScriptHook
#include <natives.h>
#include <types.h>
//Custom
#include "..\globals.h"
#include "interiors.h"
#include "functions.h"

float distance = 100000.0;  //use VDIST2 to save on resources by not calculating the sqr: sqr100000 = 315 units 

//////////////////////////////////////SAFEHOUSES//////////////////////////////////////

//Clinton Residence (Franklin's Aunt House)
void ClintonResidence()
{
	if (!iniClintonResidence)
		return;

	if (SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, -15.0, -1441.0, 31.0) < distance)
	{
		LoadIPL("v_franklins");
		OBJECT::_DOOR_CONTROL(520341586, -14.86892, -1441.182, 31.19323, false, 0.0, 0.0, 0.0);	// front
		OBJECT::_DOOR_CONTROL(703855057, -25.2784, -1431.061, 30.83955, false, 0.0, 0.0, 0.0);	// garage
	}
	return;
}

//3671 Whispymound Drive (Franklin's Mansion)
void FranklinMansion()
{
	if (!iniFranklinMansion)
		return;

	if (SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, 8.0, 540.0, 176.0) < distance)
	{
		int v_franklinshouse = INTERIOR::GET_INTERIOR_AT_COORDS(7.3, 531.3, 175.9);
		LoadIPL("v_franklinshouse");
		EnableInterior(v_franklinshouse);
		DisableInteriorProp(v_franklinshouse, "locked", false);
		EnableInteriorProp(v_franklinshouse, "unlocked", true);
		OBJECT::_DOOR_CONTROL(308207762, 7.518359, 539.5268, 176.1776, false, 0.0, 0.0, 0.0);	// front
		OBJECT::_DOOR_CONTROL(2052512905, 18.65038, 546.3401, 176.3448, false, 0.0, 0.0, 0.0);	// garage
	}
	return;
}

//Michael's House
void MichaelHouse()
{
	if (!iniMichaelHouse)
		return;

	if (SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, -820.0, 165.0, 70.0) < distance)
	{
		int v_michael = INTERIOR::GET_INTERIOR_AT_COORDS(-809.2, 180.7, 73.2);
		LoadIPL("v_michael");
		LoadIPL("v_michael_garage");

		if (!INTERIOR::_IS_INTERIOR_PROP_ENABLED(v_michael, "V_Michael_bed_Messy"))
			EnableInteriorProp(v_michael, "V_Michael_bed_tidy", true);

		//Check if player is NOT Michael
		if (PED::GET_PED_TYPE(PLAYER::PLAYER_PED_ID()) != 0)
		{
			if (OBJECT::DOOR_SYSTEM_FIND_EXISTING_DOOR(-844.051, 155.9619, 66.03221, -2125423493, &doorHash))	// front gate
			{
				OBJECT::_SET_DOOR_ACCELERATION_LIMIT(doorHash, 0, false, false);
				OBJECT::DOOR_SYSTEM_SET_AUTOMATIC_RATE(doorHash, 1.0, false, false);
				OBJECT::DOOR_SYSTEM_SET_AUTOMATIC_DISTANCE(doorHash, 15.15, false, false);
			}

			OBJECT::_DOOR_CONTROL(-1568354151, -848.9343, 179.3079, 70.0247, false, 0.0, 0.0, 0.0);		// front
			OBJECT::_DOOR_CONTROL(-1686014385, -816.1068, 177.5109, 72.82738, false, 0.0, 0.0, 0.0);	// front
			OBJECT::_DOOR_CONTROL(159994461, -816.716, 179.098, 72.82738, false, 0.0, 0.0, 0.0);		// front
			OBJECT::_DOOR_CONTROL(1245831483, -794.1853, 182.568, 73.04045, false, 0.0, 0.0, 0.0);		// rear
			OBJECT::_DOOR_CONTROL(-1454760130, -793.3943, 180.5075, 73.04045, false, 0.0, 0.0, 0.0);	// rear
			OBJECT::_DOOR_CONTROL(1245831483, -794.5051, 178.0124, 73.04045, false, 0.0, 0.0, 0.0);		// rear
			OBJECT::_DOOR_CONTROL(-1454760130, -796.5657, 177.2214, 73.04045, false, 0.0, 0.0, 0.0);	// rear
			OBJECT::_DOOR_CONTROL(30769481, -815.2816, 185.975, 72.99993, false, 0.0, 0.0, 0.0);		// garage
		}
	}
	return;
}

//Trevor's Trailer
void TrevorTrailer()
{
	if (!iniTrevorTrailer)
		return;

	if (SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, 1973.0, 3815.0, 34.0) < distance)
	{
		if (!STREAMING::IS_IPL_ACTIVE("trevorstrailertrash"))
		{
			UnloadIPL("trevorstrailer");
			LoadIPL("trevorstrailertidy");
		}
		OBJECT::_DOOR_CONTROL(132154435, 1972.769, 3815.366, 33.66326, false, 0.0, 0.0, 0.0);	// front
		OBJECT::_DOOR_CONTROL(67910261, 1972.787, 3824.554, 32.65174, false, 0.0, 0.0, 0.0);	// garage
	}
	return;
}

//////////////////////////////////MISSION INTERIORS//////////////////////////////////

//Premium Deluxe Motorsport (Simeon's Showroom)
void PremiumDeluxeMotorsport()
{
	if (!iniPremiumDeluxeMotorsport)
		return;

	if (SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, -45.0, -1100.0, 27.0) < distance)
	{
		UnloadIPL("fakeint");
		UnloadIPL("fakeint_lod");
		LoadIPL("shr_int");
		LoadIPL("shr_int_lod");
		int v_carshowroom = INTERIOR::GET_INTERIOR_AT_COORDS(-44.0, -1097.5, 27.0);
		EnableInterior(v_carshowroom);
		DisableInteriorProp(v_carshowroom, "shutter_closed", false);
		EnableInteriorProp(v_carshowroom, "shutter_open", true);
		OBJECT::_DOOR_CONTROL(1417577297, -37.33113, -1108.873, 26.7198, false, 0.0, 0.0, 0.0);		// front
		OBJECT::_DOOR_CONTROL(2059227086, -39.13366, -1108.218, 26.7198, false, 0.0, 0.0, 0.0);		// front
		OBJECT::_DOOR_CONTROL(1417577297, -60.54582, -1094.749, 26.88872, false, 0.0, 0.0, 0.0);	// front
		OBJECT::_DOOR_CONTROL(2059227086, -59.89302, -1092.952, 26.88362, false, 0.0, 0.0, 0.0);	// front
	}
	else
	{
		UnloadIPL("shr_int");
		UnloadIPL("shr_int_lod");
		LoadIPL("fakeint");
		LoadIPL("fakeint_lod");
	}
	return;
}

//Lester's House
void LesterHouse()
{
	if (!iniLesterHouse)
		return;

	if (SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, 1274.0, -1720.0, 55.0) < distance)
	{
		LoadIPL("v_lesters");
		OBJECT::_DOOR_CONTROL(1145337974, 1273.816, -1720.697, 54.92143, false, 0.0, 0.0, 0.0);	// front
	}
	else
		UnloadIPL("v_lesters");
	return;
}

//Darnell Bros. Factory (Leaster's Factory)
void LesterFactory()
{
	if (!iniLesterFactory || STREAMING::IS_IPL_ACTIVE("id2_14_during1") || STREAMING::IS_IPL_ACTIVE("id2_14_during2") || STREAMING::IS_IPL_ACTIVE("id2_14_on_fire"))
		return;

	if (iniStoryCompatibility && STREAMING::IS_IPL_ACTIVE("id2_14_post_no_int"))
		return;

	if (SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, 717.0, -975.0, 25.0) < distance)
	{
		UnloadIPL("id2_14_pre_no_int");
		UnloadIPL("id2_14_pre_no_int_lod");
		UnloadIPL("id2_14_post_no_int");
		UnloadIPL("id2_14_post_no_int_lod");
		LoadIPL("id2_14_during1");
		LoadIPL("id2_14_during1_lod");
		LoadIPL("id2_14_during_door");
		LoadIPL("id2_14_during_door_lod");
		SetScenarioGroup("sew_machine", true);
		OBJECT::_DOOR_CONTROL(826072862, 717.0, -975.0, 25.0, false, 0.0, 0.0, 0.0);	// front
		OBJECT::_DOOR_CONTROL(763780711, 719.0, -975.0, 25.0, false, 0.0, 0.0, 0.0);	// front
	}
	else
	{
		UnloadIPL("id2_14_during1");
		UnloadIPL("id2_14_during1_lod");
		UnloadIPL("id2_14_during_door");
		UnloadIPL("id2_14_during_door_lod");
		LoadIPL("id2_14_pre_no_int");
		LoadIPL("id2_14_pre_no_int_lod");
	}
	return;
}

//Lifeinvader Office
void Lifeinvader()
{
	if (!iniLifeinvader)
		return;

	if (SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, -1050.0, -235.0, 40.0) < distance)
	{
		UnloadIPL("facelobbyfake");
		UnloadIPL("facelobbyfake_lod");
		LoadIPL("facelobby");
		LoadIPL("facelobby_lod");
		OBJECT::_DOOR_CONTROL(1104171198, -1045.12, -232.004, 39.43794, false, 0.0, 0.0, 0.0);		// rear
		OBJECT::_DOOR_CONTROL(-1425071302, -1046.516, -229.3581, 39.43794, false, 0.0, 0.0, 0.0);	// rear
		OBJECT::_DOOR_CONTROL(-1679881977, -1083.62, -260.4166, 38.1867, false, 0.0, 0.0, 0.0);		// front
		OBJECT::_DOOR_CONTROL(-1045015371, -1080.974, -259.0203, 38.1867, false, 0.0, 0.0, 0.0);	// front
		OBJECT::_DOOR_CONTROL(-495720969, -1055.958, -236.4251, 44.171, false, 0.0, 0.0, 0.0);		// internal
		//"Imagineering room"
		OBJECT::_DOOR_CONTROL(969847031, -1057.767, -237.484, 43.021, false, 0.0, 0.0, 0.0);	// internal
		OBJECT::_DOOR_CONTROL(969847031, -1063.842, -240.6464, 43.021, false, 0.0, 0.0, 0.0);	// internal
	}
	else
	{
		LoadIPL("facelobbyfake");
		LoadIPL("facelobbyfake_lod");
		UnloadIPL("facelobby");
		UnloadIPL("facelobby_lod");
	}
	return;
}

//Floyd's Apartment
void FloydHouse()
{
	if (!iniFloydHouse || (iniStoryCompatibility && STREAMING::IS_IPL_ACTIVE("vb_30_crimetape")))
		return;
	
	UnloadIPL("vb_30_crimetape");
	OBJECT::_DOOR_CONTROL(-607040053, -1149.709, -1521.088, 10.78267, false, 0.0, 0.0, 0.0);	// front
	
	return;
}

//Vangelico Jewelry Store
void Vangelico()
{
	if (!iniVangelico || (iniStoryCompatibility && STREAMING::IS_IPL_ACTIVE("bh1_16_refurb")))
		return;

	if (SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, -630.0, -238.0, 38.0) < distance)
	{
		UnloadIPL("jewel2fake");
		UnloadIPL("jewel2fake_lod");
		UnloadIPL("bh1_16_refurb");
		LoadIPL("post_hiest_unload");
		LoadIPL("post_hiest_unload_lod");
		SetScenarioGroup("vangelico", true);
		OBJECT::_DOOR_CONTROL(9467943, -630.4265, -238.4375, 38.20653, false, 0.0, 0.0, 0.0);		// front
		OBJECT::_DOOR_CONTROL(1425919976, -631.9554, -236.3333, 38.20653, false, 0.0, 0.0, 0.0);	// front
	}
	else
	{
		LoadIPL("jewel2fake");
		LoadIPL("jewel2fake_lod");
		UnloadIPL("post_hiest_unload");
		UnloadIPL("post_hiest_unload_lod");
	}
	return;
}

//Max Renda Construction Site
void MaxRenda()
{
	if (iniMaxRenda && STREAMING::IS_IPL_ACTIVE("bh1_16_doors_shut"))
	{
		UnloadIPL("bh1_16_doors_shut");
		LoadIPL("refit_unload");
		LoadIPL("refit_unload_lod");
	}
	return;
}

//FIB Lobby
void FIBLobby()
{
	if (!iniFIBLobby)
		return;

	if (SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, 106.0, -745.0, 46.0) < distance)
	{
		UnloadIPL("fiblobbyfake");
		UnloadIPL("fiblobbyfake_lod");
		LoadIPL("fiblobby");
		LoadIPL("fiblobby_lod");
		OBJECT::_DOOR_CONTROL(-1517873911, 106.3793, -742.6982, 46.51962, false, 0.0, 0.0, 0.0);	// front
		OBJECT::_DOOR_CONTROL(-90456267, 105.7607, -746.646, 46.18266, false, 0.0, 0.0, 0.0);		// front
		OBJECT::_DOOR_CONTROL(-2051651622, 127.8489, -760.4548, 45.90111, false, 0.0, 0.0, 0.0);	// internal
		//Elevator doors
		OBJECT::_DOOR_CONTROL(-1225363909, 134.9403, -762.9027, 44.75291, false, 0.0, 0.0, 0.0);	// internal
		OBJECT::_DOOR_CONTROL(1219957182, 137.7594, -763.9288, 44.75291, false, 0.0, 0.0, 0.0);		// internal
		OBJECT::_DOOR_CONTROL(-1225363909, 127.8489, -760.4548, 45.90111, false, 0.0, 0.0, 0.0);	// internal
		OBJECT::_DOOR_CONTROL(1219957182, 139.1689, -764.4418, 44.75182, false, 0.0, 0.0, 0.0);		// internal
	}
	else
	{
		UnloadIPL("fiblobby");
		UnloadIPL("fiblobby_lod");
		LoadIPL("fiblobbyfake");
		LoadIPL("fiblobbyfake_lod");
	}
	return;
}

//Hayes Autos Chopshop (Devin Weston's Chop Shop)
void Chopshop()
{
	if (!iniChopshop)
		return;

	if (SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, 485.0, -1315.0, 30.0) < distance)
	{
		LoadIPL("v_chopshop");
		EnableInterior(INTERIOR::GET_INTERIOR_AT_COORDS(480.5, -1319.0, 30.0));
		AltUnlockDoor(-664582244, 482.8112, -1311.953, 29.35057);								// front
		//Replace buggy garage door with new one
		if (!OBJECT::_DOES_DOOR_EXIST(-190140885))
		{
			Object door = OBJECT::GET_CLOSEST_OBJECT_OF_TYPE(484.5642, -1315.574, 30.20331, 0.5, -190780785, false, true, true);
			ENTITY::SET_ENTITY_AS_MISSION_ENTITY(door, true, true);
			ENTITY::DELETE_ENTITY(&door);
			OBJECT::ADD_DOOR_TO_SYSTEM(-190140885, -190780785, 484.5642, -1315.574, 30.20331, false, false, false);
			OBJECT::_SET_DOOR_ACCELERATION_LIMIT(-190140885, 0, false, false);
		}
	}
	else
	{
		UnloadIPL("v_chopshop");
	}
	return;
}

//Tequi-la-la
void TequiLaLa()
{
	if (!iniTequiLaLa)
		return;

	if (SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, -565.0, 277.0, 84.0) < distance)
	{
		LoadIPL("v_rockclub");
		EnableInterior(INTERIOR::GET_INTERIOR_AT_COORDS(-565.0, 276.5, 83.5));
		OBJECT::_DOOR_CONTROL(993120320, -565.1712, 276.6259, 83.28626, false, 0.0, 0.0, 0.0);	// front
		OBJECT::_DOOR_CONTROL(993120320, -561.2866, 293.5044, 87.77851, false, 0.0, 0.0, 0.0);	// back
	}
	else
	{
		UnloadIPL("v_rockclub");
	}
	return;
}

//Maze Bank Arena (Fame or Shame)
void FameorShame()
{
	if (!iniFameorShame)
		return;

	if (SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, -262.0, -2021.0, 36.0) < distance)
	{
		UnloadIPL("sp1_10_fake_interior");
		UnloadIPL("sp1_10_fake_interior_lod");
		LoadIPL("sp1_10_real_interior");
		LoadIPL("sp1_10_real_interior_lod");
	}
	else
	{
		UnloadIPL("sp1_10_real_interior");
		UnloadIPL("sp1_10_real_interior_lod");
		LoadIPL("sp1_10_fake_interior");
		LoadIPL("sp1_10_fake_interior_lod");
	}
	return;
}

//Clucking Bell Farms
void CluckingBell()
{
	if (!iniCluckingBell)
		return;

	if (SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, -71.0, 6266.0, 32.0) < distance)
	{
		UnloadIPL("cs1_02_cf_offmission");
		UnloadIPL("cs1_02_cf_offmission_lod");
		LoadIPL("cs1_02_cf_onmission1");
		LoadIPL("cs1_02_cf_onmission1_lod");
		LoadIPL("cs1_02_cf_onmission2");
		LoadIPL("cs1_02_cf_onmission3");
		LoadIPL("cs1_02_cf_onmission3_lod");
		LoadIPL("cs1_02_cf_onmission4");
		LoadIPL("cs1_02_cf_onmission4_lod");
	}
	else
	{
		UnloadIPL("cs1_02_cf_onmission1");
		UnloadIPL("cs1_02_cf_onmission2");
		UnloadIPL("cs1_02_cf_onmission3");
		UnloadIPL("cs1_02_cf_onmission4");
		LoadIPL("cs1_02_cf_offmission");
	}
	return;
}

//Grand Banks Steel Foundry
void Foundry()
{
	if (!iniFoundry)
		return;

	if (SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, 1085.0, -2000.0, 35.0) < distance)
	{
		LoadIPL("v_foundry");
		EnableInterior(INTERIOR::GET_INTERIOR_AT_COORDS(1089.5, -1995.5, 33.0));
		OBJECT::_DOOR_CONTROL(-1428622127, 1083.547, -1975.435, 31.62222, false, 0.0, 0.0, 0.0);	// front
		OBJECT::_DOOR_CONTROL(-1428622127, 1065.237, -2006.079, 32.23295, false, 0.0, 0.0, 0.0);	// rear
		OBJECT::_DOOR_CONTROL(-1428622127, 1085.307, -2018.561, 41.62894, false, 0.0, 0.0, 0.0);	// rear
	}
	else
	{
		UnloadIPL("v_foundry");
	}
	return;
}

//Epsilon Encounter Room
void EpsilonRoom()
{
	if (!iniEpsilonRoom)
		return;

	if (SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, 241.0, 361.0, 106.0) < distance)
	{
		LoadIPL("v_epsilonism");
		EnableInterior(INTERIOR::GET_INTERIOR_AT_COORDS(245.5, 370.0, 106.3));
		OBJECT::_DOOR_CONTROL(-1230442770, 241.3621, 361.0471, 105.8883, false, 0.0, 0.0, 0.0);	// front
	}
	else
	{
		UnloadIPL("v_epsilonism");
	}
	return;
}

//Harvey Molina's Apartment (Janitor's House)
void JanitorHouse()
{
	if (!iniJanitorHouse)
		return;

	if (SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, -108.0, -9.0, 71.0) < distance)
	{
		LoadIPL("v_janitor");
		OBJECT::_DOOR_CONTROL(486670049, -107.5373, -9.018099, 70.67085, false, 0.0, 0.0, 0.0);	// front
	}
	else
	{
		UnloadIPL("v_janitor");
	}
	return;
}

//O'Neil Ranch
void ONeilRanch()
{
	if (!iniONeilRanch || (iniStoryCompatibility && (STREAMING::IS_IPL_ACTIVE("farm_burnt") || STREAMING::IS_IPL_ACTIVE("des_farmhs_endimap"))))
	{
		UnloadIPL("farmint_cap");
		UnloadIPL("farmint_cap_lod");
		return;
	}

	if (SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, 2445.0, 4976.0, 50.0) < distance)
	{
		UnloadIPL("farmint_cap");
		UnloadIPL("farmint_cap_lod");
		UnloadIPL("farm_burnt");
		UnloadIPL("farm_burnt_props");
		UnloadIPL("des_farmhs_endimap");
		LoadIPL("farm");
		LoadIPL("farmint");
		LoadIPL("farm_lod");
		LoadIPL("farm_props");
		LoadIPL("des_farmhouse");
	}
	else
	{
		UnloadIPL("farm");
		UnloadIPL("farmint");
		UnloadIPL("farm_lod");
		UnloadIPL("farm_props");
		UnloadIPL("des_farmhouse");
		LoadIPL("farmint_cap");
		LoadIPL("farmint_cap_lod");
	}
	return;
}

//Rogers Salvage & Scrap (Scrapyard)
void Scrapyard()
{
	if (!iniScrapyard)
		return;

	if (SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, -605.0, -1615.0, 27.0) < distance)
	{
		LoadIPL("v_recycle");
		int v_recycle = INTERIOR::GET_INTERIOR_AT_COORDS(-611.4, -1615.7, 29.2);
		EnableInterior(v_recycle);
		INTERIOR::UNPIN_INTERIOR(v_recycle);
		OBJECT::_DOOR_CONTROL(1099436502, -608.7289, -1610.315, 27.15894, false, 0.0, 0.0, 0.0);	// front
		OBJECT::_DOOR_CONTROL(-1627599682, -611.32, -1610.089, 27.15894, false, 0.0, 0.0, 0.0);		// front
		OBJECT::_DOOR_CONTROL(1099436502, -592.9376, -1631.577, 27.15931, false, 0.0, 0.0, 0.0);	// rear
		OBJECT::_DOOR_CONTROL(-1627599682, -592.7109, -1628.986, 27.15931, false, 0.0, 0.0, 0.0);	// rear
		DeleteObject(812467272, -589.5237, -1621.55, 33.16059);		// internal
		DeleteObject(812467272, -590.8198, -1621.436, 33.16059);	// internal
	}
	else
	{
		UnloadIPL("v_recycle");
	}
	return;
}

//Humane Lab
void HumaneLab()
{
	if (!iniHumaneLab)
		return;

	if (SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, 3625.0, 3750.0, 28.0) < distance)
	{
		LoadIPL("v_lab");
		OBJECT::_DOOR_CONTROL(-1081024910, 3620.843, 3751.527, 27.69009, false, 0.0, 0.0, -1.0);	// front
		OBJECT::_DOOR_CONTROL(-1081024910, 3627.713, 3746.716, 27.69009, false, 0.0, 0.0, -1.0);	// front
		//Underwater entrance at the cooling tunnels
		UnloadIPL("chemgrill_grp1");
	}
	else
	{
		UnloadIPL("v_lab");
	}
	return;
}

//Omega's Garage
void OmegaGarage()
{
	if (!iniOmegaGarage)
		return;

	if (SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, 2333.0, 2575.0, 47.0) < distance)
	{
		OBJECT::_DOOR_CONTROL(-26664553, 2333.235, 2574.973, 47.03088, false, 0.0, 0.0, 0.0);	// front
		OBJECT::_DOOR_CONTROL(914592203, 2329.655, 2576.642, 47.03088, false, 0.0, 0.0, 0.0);	// front
	}
	return;
}

//Blaine County Savings Bank
void BlaineCountyBank()
{
	if (!iniBlaineCountyBank)
		return;

	if (SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, -110.0, 6462.0, 32.0) < distance)
	{
		LoadIPL("v_bank4");
		OBJECT::_DOOR_CONTROL(-1666470363, -109.65, 6462.11, 31.98499, false, 0.0, 0.0, 0.0);		// front
		OBJECT::_DOOR_CONTROL(-353187150, -111.48, 6463.94, 31.98499, false, 0.0, 0.0, 0.0);		// front
		OBJECT::_DOOR_CONTROL(-1184592117, -108.9147, 6469.104, 31.91028, false, 0.0, 0.0, 0.0);	// internal
	}
	else
	{
		UnloadIPL("v_bank4");
	}
	return;
}

//Dignity Yacht
void DignityYacht()
{
	if (!iniDignityYacht)
		return;

	if (SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, -2073.0, -1024.0, 4.0) < 250000.0)
	{
		LoadIPL("smboat");
		LoadIPL("smboat_lod");
		LoadIPL("smboat_lodlights");
		LoadIPL("smboat_distantlights");
	}
	else
	{
		UnloadIPL("smboat");
		LoadIPL("smboat_lod");
		LoadIPL("smboat_lodlights");
		LoadIPL("smboat_distantlights");
	}
	return;
}

//SS Bulker Container Ship
void ContainerShip()
{
	if (!iniContainerShip || (iniStoryCompatibility && STREAMING::IS_IPL_ACTIVE("sunkcargoship")))
	{
		UnloadIPL("cargoship");
		UnloadIPL("cargoship_lod");
		return;
	}

	if (SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, -228.0, -2366.0, 17.0) < 250000.0)
	{
		UnloadIPL("sunkcargoship");
		UnloadIPL("sunkcargoship_lod");
		UnloadIPL("sunk_ship_fire");
		LoadIPL("cargoship");
		LoadIPL("cargoship_lod");
	}
	else
	{
		UnloadIPL("cargoship");
		LoadIPL("cargoship_lod");
	}
	return;
}

//Union Depository Vault
void UnionDepositoryVault()
{
	if (!iniUnionDepositoryParking)
		return;

	if (SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, 15.0, -690.0, 45.0) < distance)
		LoadIPL("FINBANK");
	else
		UnloadIPL("FINBANK");
	return;
}

//Union Depository Parking
void UnionDepositoryParking()
{
	if (!iniUnionDepositoryParking)
		return;

	if (SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, -16.0, -685.00, 34.0) < distance)
	{
		UnloadIPL("dt1_03_shutter");
		LoadIPL("dt1_03_carpark");
		EnableInterior(INTERIOR::GET_INTERIOR_AT_COORDS(-16.0, -685.00, 34.0));
	}
	else
	{
		UnloadIPL("dt1_03_carpark");
		LoadIPL("dt1_03_shutter");
	}
	return;
}

//Los Santos Naval Port Gates (Merryweather's Dock)
void MerryweatherDock()
{
	if (!iniMerryweatherDock)
		return;

	if (SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, 492.0, -3116.0, 5.0) < distance)
	{
		OBJECT::_DOOR_CONTROL(1286392437, 492.2758, -3115.934, 5.162354, false, 0.0, 0.0, 0.0);	// internal
		OBJECT::_DOOR_CONTROL(1286392437, 476.3276, -3115.925, 5.162354, false, 0.0, 0.0, 0.0);	// internal
	}
	return;
}

//Vanilla Unicorn Back Door
void StripclubBackDoor()
{
	if (!iniStripclubBackDoor)
		return;

	OBJECT::_DOOR_CONTROL(668467214, 96.09197, -1284.854, 29.43878, false, 0.0, 0.0, 0.0);	// internal
	return;
}

//Raven Slaughterhouse
void Slaughterhouse()
{
	if (!iniSlaughterhouse)
		return;

	if (SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, 994.0, -2143.0, 31.5) < distance)
	{
		LoadIPL("v_abattoir");
		EnableInterior(INTERIOR::GET_INTERIOR_AT_COORDS(981.0, -2186.0, 32.1));

		if (OBJECT::DOOR_SYSTEM_FIND_EXISTING_DOOR(962.0066, -2183.816, 31.06194, 1755793225, &doorHash))
		{
			OBJECT::_SET_DOOR_AJAR_ANGLE(doorHash, 1.0, false, true);
			OBJECT::DOOR_SYSTEM_SET_HOLD_OPEN(doorHash, true);
		}

		if (OBJECT::DOOR_SYSTEM_FIND_EXISTING_DOOR(962.9085, -2105.813, 34.20225, -1468417022, &doorHash))
		{
			OBJECT::_SET_DOOR_AJAR_ANGLE(doorHash, 1.0, false, true);
			OBJECT::DOOR_SYSTEM_SET_HOLD_OPEN(doorHash, true);
		}
	}
	else
	{
		UnloadIPL("v_abattoir");
	}
	return;
}

//////////////////////////////////UNUSED INTERIORS//////////////////////////////////

//Paleto Bay Sheriff's Office
void PaletoSheriffOffice()
{
	if (!iniPaletoSheriffOffice)
		return;

	if (SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, -445.0, 6017.0, 32.0) < distance)
	{
		UnloadIPL("cs1_16_sheriff_cap");
		LoadIPL("v_sheriff2");
		int v_sheriff2 = INTERIOR::GET_INTERIOR_AT_COORDS(-447.0, 6013.5, 32.3);
		EnableInterior(v_sheriff2);
		OBJECT::_DOOR_CONTROL(-1501157055, -444.4985, 6017.06, 31.86633, false, 0.0, 0.0, 0.0);	// front
		OBJECT::_DOOR_CONTROL(-1501157055, -442.66, 6015.222, 31.86633, false, 0.0, 0.0, 0.0);	// front
	}
	else
	{
		UnloadIPL("v_sheriff2");
		LoadIPL("cs1_16_sheriff_cap");
	}
	return;
}

//Sandy Shores Sheriff's Office
void SandySheriffOffice()
{
	if (!iniSandySheriffOffice)
		return;

	if (SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, 1856.0, 3684.0, 35.0) < distance)
	{
		UnloadIPL("sheriff_cap");
		LoadIPL("v_sheriff");
		int v_sheriff = INTERIOR::GET_INTERIOR_AT_COORDS(1853.0, 3688.0, 35.0);
		EnableInterior(v_sheriff);
		OBJECT::_DOOR_CONTROL(-1765048490, 1855.685, 3683.93, 34.59282, false, 0.0, 0.0, 0.0);	// front
	}
	else
	{
		UnloadIPL("v_sheriff");
		LoadIPL("sheriff_cap");
	}
	return;
}

//Mission Row Police Station Captain's Office & Armery
void PoliceStationRooms()
{
	if (!iniPoliceStationRooms)
		return;

	if (SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, 447.0, -980.0, 31.0) < distance)
	{
		OBJECT::_DOOR_CONTROL(-1320876379, 446.5728, -980.0104, 30.8393, false, 0.0, 0.0, 0.0);	// internal
		OBJECT::_DOOR_CONTROL(749848321, 453.0793, -983.1894, 30.83926, false, 0.0, 0.0, 0.0);	// internal
	}
	return;
}

//North Yankton Surveillance Room
void YanktonSurveillance()
{
	if (!iniYanktonSurveillance)
		return;

	OBJECT::_DOOR_CONTROL(-311575617, 5305.461, -5177.75, 83.66856, false, 0.0, 0.0, 0.0);	// internal
	return;
}

//Pacific Standard Public Deposit Bank Vault
void PacificBankVault()
{
	if (!iniPacificBankVault)
		return;

	if (SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, 266.0, 217.6, 110.0) < distance)
	{
		OBJECT::_DOOR_CONTROL(1956494919, 266.3624, 217.5697, 110.4328, false, 0.0, 0.0, 0.0);	// internal
		OBJECT::_DOOR_CONTROL(-1246222793, 256.3116, 220.6579, 106.4296, false, 0.0, 0.0, 0.0);	// internal
	}
	return;
}

//Garage Near Union Depository
void GarageNearUD()
{
	if (!iniGarageNearUD)
		return;

	AltUnlockDoor(-190780785, -33.80561, -621.6387, 36.06102);	// front
	return;
}

//Misc - Pier 400
void PierGates()
{
	if (!iniPierGates)
		return;

	if (SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, -150.0, -2550.0, 5.0) < distance)
	{
		OBJECT::_DOOR_CONTROL(1286392437, 19.4045, -2529.702, 5.047173, false, 0.0, 0.0, 0.0);		// external
		OBJECT::_DOOR_CONTROL(1286392437, 10.64414, -2542.213, 5.047173, false, 0.0, 0.0, 0.0);		// external
		OBJECT::_DOOR_CONTROL(1286392437, -202.6151, -2515.309, 5.047173, false, 0.0, 0.0, 0.0);	// external
		OBJECT::_DOOR_CONTROL(1286392437, -187.3406, -2515.309, 5.047173, false, 0.0, 0.0, 0.0);	// external
		OBJECT::_DOOR_CONTROL(569833973, -160.8777, -2636.198, 5.025181, false, 0.0, 0.0, 0.0);		// external
		OBJECT::_DOOR_CONTROL(569833973, -148.7143, -2636.198, 5.032078, false, 0.0, 0.0, 0.0);		// external
	}
	return;
}

//Garage in front of "Alpha Mail Couriers"
void GarageNearAMC()
{
	if (!iniGarageNearAMC)
		return;

	OBJECT::_DOOR_CONTROL(-190780785, 1204.555, -3110.386, 6.557831, false, 0.0, 0.0, 0.0);		// external
	return;
}

//Fleeca Banks Vaults
void FleecaBanks()
{
	if (!iniFleecaBanks)
		return;

	//Fleeca Bank - Blaine County
	if (SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, 1179.0, 2709.0, 38.0) < distance)
	{
		ENTITY::SET_ENTITY_ROTATION(OBJECT::GET_CLOSEST_OBJECT_OF_TYPE(1178.87, 2709.365, 38.36251, 0.3, -131754413, false, true, true), 0.0, 0.0, 0.0, 2, true);		// internal
		ENTITY::SET_ENTITY_ROTATION(OBJECT::GET_CLOSEST_OBJECT_OF_TYPE(1175.542, 2710.861, 38.22689, 0.3, 2121050683, false, true, true), 0.0, 0.0, 0.0, 2, true);		// internal
	}

	//Fleeca Bank - Los Santos County
	if (SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, -2960.0, 479.0, 16.0) < distance)
	{
		ENTITY::SET_ENTITY_ROTATION(OBJECT::GET_CLOSEST_OBJECT_OF_TYPE(-2960.176, 479.0105, 15.97156, 0.3, -131754413, false, true, true), 0.0, 0.0, -90.0, 2, true);	// internal
		ENTITY::SET_ENTITY_ROTATION(OBJECT::GET_CLOSEST_OBJECT_OF_TYPE(-2958.538, 482.2705, 15.83594, 0.3, 2121050683, false, true, true), 0.0, 0.0, -90.0, 2, true);	// internal
	}

	//Fleeca Bank - Burton
	if (SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, 310.0, -280.0, 54.0) < distance)
	{
		ENTITY::SET_ENTITY_ROTATION(OBJECT::GET_CLOSEST_OBJECT_OF_TYPE(309.7491, -280.1797, 54.43926, 0.3, -131754413, false, true, true), 0.0, 0.0, 160.0, 2, true);	// internal
		ENTITY::SET_ENTITY_ROTATION(OBJECT::GET_CLOSEST_OBJECT_OF_TYPE(312.358, -282.7301, 54.30365, 0.3, 2121050683, false, true, true), 0.0, 0.0, 160.0, 2, true);	// internal
	}

	//Fleeca Bank - Alta
	if (SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, -355.0, -51.0, 49.0) < distance)
	{
		ENTITY::SET_ENTITY_ROTATION(OBJECT::GET_CLOSEST_OBJECT_OF_TYPE(-355.3892, -51.06768, 49.31105, 0.3, -131754413, false, true, true), 0.0, 0.0, 160.0, 2, true);	// internal
		ENTITY::SET_ENTITY_ROTATION(OBJECT::GET_CLOSEST_OBJECT_OF_TYPE(-352.7365, -53.57248, 49.17543, 0.3, 2121050683, false, true, true), 0.0, 0.0, 160.0, 2, true);	// internal
	}

	//Fleeca Bank - Rockford Hills
	if (SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, -1215.0, -335.0, 38.0) < distance)
	{
		ENTITY::SET_ENTITY_ROTATION(OBJECT::GET_CLOSEST_OBJECT_OF_TYPE(-1214.906, -334.7281, 38.05551, 0.3, -131754413, false, true, true), 0.0, 0.0, -150.0, 2, true);	// internal
		ENTITY::SET_ENTITY_ROTATION(OBJECT::GET_CLOSEST_OBJECT_OF_TYPE(-1211.261, -334.5596, 37.91989, 0.3, 2121050683, false, true, true), 0.0, 0.0, -150.0, 2, true);	// internal
	}

	//Fleeca Bank - Pillbox Hill
	if (SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, 145.6, -1042.0, 30.0) < distance)
	{
		ENTITY::SET_ENTITY_ROTATION(OBJECT::GET_CLOSEST_OBJECT_OF_TYPE(145.4186, -1041.813, 29.64255, 0.3, -131754413, false, true, true), 0.0, 0.0, 160.0, 2, true);	// internal
		ENTITY::SET_ENTITY_ROTATION(OBJECT::GET_CLOSEST_OBJECT_OF_TYPE(148.0266, -1044.364, 29.50693, 0.3, 2121050683, false, true, true), 0.0, 0.0, 160.0, 2, true);	// internal
	}
	return;
}

/////////////////////////////////////SCENARIO GROUPS/////////////////////////////////////
//Thanks to Alex106: https://www.gta5-mods.com/scripts/scenario-groups

void ScenarioGroups()
{
	if (!iniScenarioGroups)
		return;

	//Ammunations NPCs: Chumash, Del Perro, Great Chaparral, Hawick, La Mesa, Little Seoul, Pillbox Hill, Sandy Shores
	SetScenarioGroup("ammunation", true);

	//Fleeca Banks NPCs
	SetScenarioGroup("countryside_banks", true);
	SetScenarioGroup("city_banks", true);

	//Fort Zancudo Guards
	SetScenarioGroup("fort_zancudo_guards", true);

	//Bolingbroke Penitentiary Guards
	SetScenarioGroup("guards_at_prison", true);

	//Paleto Bay Sheriff's Office NPCs
	SetScenarioGroup("paleto_cops", true);
	SetScenarioGroup("prison_transport", true);

	//Sandy Shores Sheriff's Office NPCs
	SetScenarioGroup("sandy_cops", true);

	//Rogers Salvage & Scrap (Scrapyard) NPCs
	SetScenarioGroup("scrap_security", true);

	//Blaine County Savings Bank NPCs
	if (!GAMEPLAY::GET_MISSION_FLAG())
		SetScenarioGroup("paleto_bank", true);
	else
		SetScenarioGroup("paleto_bank", false);
	return;
}

///////////////////////////////////////MAP FIXES/////////////////////////////////////////

void Fixes()
{
	if (!iniFixes)
		return;

	UnloadIPL("CS3_07_MPGates");
	LoadIPL("chop_props");
	LoadIPL("railing_start");
	LoadIPL("Carwash_with_spinners");
	LoadIPL("KT_CarWash");
	LoadIPL("golfflags");
	LoadIPL("cs5_4_trains");
	LoadIPL("ch1_02_closed");
	LoadIPL("v_tunnel_hole");
	LoadIPL("canyonriver01");
	LoadIPL("canyonriver01_lod");
	LoadIPL("cs3_05_water_grp1");
	LoadIPL("cs3_05_water_grp1_lod");
	LoadIPL("trv1_trail_start");
	LoadIPL("CanyonRvrShallow");
	return;
}

///////////////////////////////////////EXTRAS/////////////////////////////////////////

void UnlockDoors()
{
	//Michael's House Gate
	if (iniMichaelHouse && PED::GET_PED_TYPE(PLAYER::PLAYER_PED_ID()) != 0 && OBJECT::DOOR_SYSTEM_FIND_EXISTING_DOOR(-844.051, 155.9619, 66.03221, -2125423493, &doorHash))
	{
		OBJECT::_SET_DOOR_ACCELERATION_LIMIT(doorHash, 0, false, false);
		OBJECT::DOOR_SYSTEM_SET_AUTOMATIC_RATE(doorHash, 1.0, false, false);
		OBJECT::DOOR_SYSTEM_SET_AUTOMATIC_DISTANCE(doorHash, 15.15, false, false);
	}

	//Vangelico Jewelry Store doors
	if (iniVangelico && !(iniStoryCompatibility && STREAMING::IS_IPL_ACTIVE("bh1_16_refurb")) && SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, -630.0, -238.0, 38.0) < distance)
	{
		OBJECT::_DOOR_CONTROL(9467943, -630.4265, -238.4375, 38.20653, false, 0.0, 0.0, 0.0);
		OBJECT::_DOOR_CONTROL(1425919976, -631.9554, -236.3333, 38.20653, false, 0.0, 0.0, 0.0);
	}

	//Chopshop
	if (iniChopshop && SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, 485.0, -1315.0, 30.0) < distance)
	{
		AltUnlockDoor(-664582244, 482.8112, -1311.953, 29.35057);
		if (!OBJECT::_DOES_DOOR_EXIST(-190140885))
		{
			Object door = OBJECT::GET_CLOSEST_OBJECT_OF_TYPE(484.5642, -1315.574, 30.20331, 0.5, -190780785, false, true, true);
			ENTITY::SET_ENTITY_AS_MISSION_ENTITY(door, true, true);
			ENTITY::DELETE_ENTITY(&door);
			OBJECT::ADD_DOOR_TO_SYSTEM(-190140885, -190780785, 484.5642, -1315.574, 30.20331, false, false, false);
			OBJECT::_SET_DOOR_ACCELERATION_LIMIT(-190140885, 0, false, false);
		}
	}

	//Scrapyard
	if (iniScrapyard && SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, -605.0, -1615.0, 27.0) < distance)
	{
		OBJECT::_DOOR_CONTROL(1099436502, -608.7289, -1610.315, 27.15894, false, 0.0, 0.0, 0.0);
		OBJECT::_DOOR_CONTROL(-1627599682, -611.32, -1610.089, 27.15894, false, 0.0, 0.0, 0.0);
		OBJECT::_DOOR_CONTROL(1099436502, -592.9376, -1631.577, 27.15931, false, 0.0, 0.0, 0.0);
		OBJECT::_DOOR_CONTROL(-1627599682, -592.7109, -1628.986, 27.15931, false, 0.0, 0.0, 0.0);
	}

	//Foundry
	if (iniFoundry && SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, 1085.0, -2000.0, 35.0) < distance)
	{
		OBJECT::_DOOR_CONTROL(-1428622127, 1083.547, -1975.435, 31.62222, false, 0.0, 0.0, 0.0);
		OBJECT::_DOOR_CONTROL(-1428622127, 1065.237, -2006.079, 32.23295, false, 0.0, 0.0, 0.0);
		OBJECT::_DOOR_CONTROL(-1428622127, 1085.307, -2018.561, 41.62894, false, 0.0, 0.0, 0.0);
	}

	//Omega's Garage
	if (iniOmegaGarage && SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, 2333.0, 2575.0, 47.0) < distance)
	{
		OBJECT::_DOOR_CONTROL(-26664553, 2333.235, 2574.973, 47.03088, false, 0.0, 0.0, 0.0);
		OBJECT::_DOOR_CONTROL(914592203, 2329.655, 2576.642, 47.03088, false, 0.0, 0.0, 0.0);
	}

	if (iniPacificBankVault)
		PacificBankVault();

	return;
}
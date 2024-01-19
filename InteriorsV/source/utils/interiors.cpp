//ScriptHook
#include <natives.h>
// #include <types.h> //Already included in globals.h
//Custom
#include "..\globals.h"
#include "interiors.h"
#include "functions.h"

const float distance = 300.0f * 300.0f;  //Use VDIST2 to save on resources by not calculating the sqr: sqr100000 ~= 315m
const float gatesMinDist = 7.5f;
const float gatesMaxDist = 9.0f;
const float gatesAltMaxDist = 8.5f;
static const Hash prop_facgate_01 = 569833973;
static const Hash prop_facgate_01b = -655468553;
static Object lastBarrier = NULL;

static void UnlockMichaelBathroomWindow()
{
	const Hash windowHash = 1019527301;
	const float x = -801.900024f, y = 167.699997f, z = 77.580002f;

	DeleteObjectAtCoords(windowHash, -802.73333f, 167.5041f, 77.5824f, 0.15f);		// rear (v_ilev_mm_windowwc)
	Object window = GET_CLOSEST_OBJECT_OF_TYPE(x, y, z, 0.15f, windowHash, false, true, true);
	if (!DOES_ENTITY_EXIST(window))
	{
		window = CREATE_OBJECT(windowHash, x, y, 76.300002f, false, false, false);
		FREEZE_ENTITY_POSITION(window, true);
	}
	else
	{
		//Close when it's raining
		if (GET_RAIN_LEVEL() > 0.0f)
			SET_ENTITY_HEADING(window, -160.0f);
		else
			SET_ENTITY_HEADING(window, 0.0f);
	}
	return;
}

static void UnlockChopshopGarage()
{
	const float x = 484.5642f, y = -1315.574f, z = 30.20331f;
	const Hash modelHash = -190780785;		//joaat(prop_com_gar_door_01)
	const Hash doorHash = 455720570;		//joaat(DOORHASH_CARSTEAL_GARAGE_F_FIX)

	if (IS_DOOR_REGISTERED_WITH_SYSTEM(DOORHASH_CARSTEAL_GARAGE_F))
	{
		REMOVE_DOOR_FROM_SYSTEM(DOORHASH_CARSTEAL_GARAGE_F, false);
		Object door = GET_CLOSEST_OBJECT_OF_TYPE(x, y, z, 0.5f, modelHash, false, false, false);
		if (DOES_ENTITY_EXIST(door))
		{
			SET_ENTITY_AS_MISSION_ENTITY(door, true, true);
			DELETE_OBJECT(&door);
		}
	}	
	
	if (!IS_DOOR_REGISTERED_WITH_SYSTEM(doorHash))
	{
		ADD_DOOR_TO_SYSTEM(doorHash, modelHash, x, y, z, false, false, false);
		DOOR_SYSTEM_SET_DOOR_STATE(doorHash, DOORSTATE_UNLOCKED, false, false);
	}
	else if (DOOR_SYSTEM_GET_DOOR_STATE(doorHash) != 0)
		DOOR_SYSTEM_SET_DOOR_STATE(doorHash, DOORSTATE_UNLOCKED, false, false);
	return;
}

//////////////////////////////////////SAFEHOUSES//////////////////////////////////////

//Clinton Residence (Franklin's Aunt House)
void ClintonResidence()
{
	if (!iniClintonResidence)
		return;

	if (VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, -15.0f, -1441.0f, 31.0f) < distance)
	{
		LoadIPL("v_franklins");
		DOOR_SYSTEM_SET_DOOR_STATE(DOORHASH_F_HOUSE_SC_F, DOORSTATE_UNLOCKED, false, false);	// front (v_ilev_fa_frontdoor)
		DOOR_SYSTEM_SET_DOOR_STATE(DOORHASH_F_HOUSE_SC_G, DOORSTATE_UNLOCKED, false, false);	// garage (prop_sc1_21_g_door_01)
	}
	return;
}

//3671 Whispymound Drive (Franklin's Mansion)
void FranklinMansion()
{
	if (!iniFranklinMansion)
		return;

	if (VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, 8.0f, 540.0f, 176.0f) < distance)
	{
		int v_franklinshouse = GET_INTERIOR_AT_COORDS(7.3f, 531.3f, 175.9f);
		LoadIPL("v_franklinshouse");
		EnableInterior(v_franklinshouse);
		DisableInteriorProp(v_franklinshouse, "locked", false);
		EnableInteriorProp(v_franklinshouse, "unlocked", true);
		DOOR_SYSTEM_SET_DOOR_STATE(DOORHASH_F_HOUSE_VH_F, DOORSTATE_UNLOCKED, false, false);	// front (v_ilev_fh_frontdoor)
		OBJECT::SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(2052512905, 18.65038f, 546.3401f, 176.3448f, false, 0.0f, 0.0f, 0.0f);	// garage (prop_ch_025c_g_door_01)
	}
	return;
}

//Michael's House
void MichaelHouse()
{
	if (!iniMichaelHouse)
		return;

	if (VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, -820.0f, 165.0f, 70.0f) < distance)
	{
		int v_michael = GET_INTERIOR_AT_COORDS(-809.2f, 180.7f, 73.2f);
		LoadIPL("v_michael");
		LoadIPL("v_michael_garage");

		if (!IS_INTERIOR_ENTITY_SET_ACTIVE(v_michael, "V_Michael_bed_Messy"))
			EnableInteriorProp(v_michael, "V_Michael_bed_tidy", true);

		SetAutoDoorState(AUTODOOR_MICHAEL_MANSION_GATE, DOORSTATE_UNLOCKED, 0.75f, 15.0f, true);		// front gate (prop_lrggate_02_ld)
		DOOR_SYSTEM_SET_DOOR_STATE(DOORHASH_M_MANSION_GA_SM, DOORSTATE_UNLOCKED, false, false);	// front (prop_bh1_48_gate_1)
		DOOR_SYSTEM_SET_DOOR_STATE(DOORHASH_M_MANSION_F_R, DOORSTATE_UNLOCKED, false, false);	// rear (v_ilev_mm_doorm_r)
		DOOR_SYSTEM_SET_DOOR_STATE(DOORHASH_M_MANSION_F_L, DOORSTATE_UNLOCKED, false, false);	// rear (v_ilev_mm_doorm_l)
		DOOR_SYSTEM_SET_DOOR_STATE(DOORHASH_M_MANSION_G1, DOORSTATE_UNLOCKED, false, false);	// garage (prop_ld_garaged_01)
		DOOR_SYSTEM_SET_DOOR_STATE(DOORHASH_M_MANSION_R_R1, DOORSTATE_UNLOCKED, false, false);	// rear (prop_bh1_48_backdoor_r)
		DOOR_SYSTEM_SET_DOOR_STATE(DOORHASH_M_MANSION_R_L1, DOORSTATE_UNLOCKED, false, false);	// rear (prop_bh1_48_backdoor_l)
		DOOR_SYSTEM_SET_DOOR_STATE(DOORHASH_M_MANSION_R_R2, DOORSTATE_UNLOCKED, false, false);	// rear (prop_bh1_48_backdoor_r)
		DOOR_SYSTEM_SET_DOOR_STATE(DOORHASH_M_MANSION_R_L2, DOORSTATE_UNLOCKED, false, false);	// rear (prop_bh1_48_backdoor_l)
		UnlockMichaelBathroomWindow();
	}
	return;
}

//Trevor's Trailer
void TrevorTrailer()
{
	if (!iniTrevorTrailer)
		return;

	if (VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, 1973.0f, 3815.0f, 34.0f) < distance)
	{
		if (!IS_IPL_ACTIVE("trevorstrailertrash"))
		{
			UnloadIPL("trevorstrailer");
			LoadIPL("trevorstrailertidy");
		}
		DOOR_SYSTEM_SET_DOOR_STATE(DOORHASH_T_TRAILER_CS, DOORSTATE_UNLOCKED, false, false);	// front (v_ilev_trevtraildr)
		DOOR_SYSTEM_SET_DOOR_STATE(DOORHASH_T_TRAILER_CS_G, DOORSTATE_UNLOCKED, false, false);	// garage (prop_cs4_10_tr_gd_01)
	}
	return;
}

//////////////////////////////////MISSION INTERIORS//////////////////////////////////

//Premium Deluxe Motorsport (Simeon's Showroom)
void PremiumDeluxeMotorsport()
{
	if (!iniPremiumDeluxeMotorsport)
		return;

	if (VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, -45.0f, -1100.0f, 27.0f) < distance)
	{
		UnloadIPL("fakeint");
		UnloadIPL("fakeint_lod");
		LoadIPL("shr_int");
		LoadIPL("shr_int_lod");
		int v_carshowroom = GET_INTERIOR_AT_COORDS(-44.0f, -1097.5f, 27.0f);
		EnableInterior(v_carshowroom);
		DisableInteriorProp(v_carshowroom, "shutter_closed", false);
		EnableInteriorProp(v_carshowroom, "shutter_open", true);
		SetScenarioGroup("dealership", true);
		DOOR_SYSTEM_SET_DOOR_STATE(DOORHASH_DEALERSHIP_SIDE_R, DOORSTATE_UNLOCKED, false, false);	// side (v_ilev_csr_door_r)
		DOOR_SYSTEM_SET_DOOR_STATE(DOORHASH_DEALERSHIP_SIDE_L, DOORSTATE_UNLOCKED, false, false);	// side (v_ilev_csr_door_l)
		DOOR_SYSTEM_SET_DOOR_STATE(DOORHASH_DEALERSHIP_FRONT_R, DOORSTATE_UNLOCKED, false, false);	// front (v_ilev_csr_door_r)
		DOOR_SYSTEM_SET_DOOR_STATE(DOORHASH_DEALERSHIP_FRONT_L, DOORSTATE_UNLOCKED, false, false);	// front (v_ilev_csr_door_l)
		DOOR_SYSTEM_SET_DOOR_STATE(DOORHASH_ARM2_SIMEON_OFFICE, DOORSTATE_UNLOCKED, false, false);	// internal (v_ilev_fib_door1)
	}
	else if (playerControl)
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

	if (VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, 1274.0f, -1720.0f, 55.0f) < distance)
	{
		LoadIPL("v_lesters");
		DOOR_SYSTEM_SET_DOOR_STATE(DOORHASH_LESTER_F, DOORSTATE_UNLOCKED, false, false);	// front (v_ilev_lester_doorfront)
	}
	else if (playerControl)
		UnloadIPL("v_lesters");
	return;
}

//Darnell Bros. Factory (Leaster's Factory)
void LesterFactory()
{
	if (!iniLesterFactory || IS_IPL_ACTIVE("id2_14_during1") || IS_IPL_ACTIVE("id2_14_during2") || IS_IPL_ACTIVE("id2_14_on_fire"))
	{
		BlipLesterFactory.enable = false;
		return;
	}

	if (iniStoryCompatibility && IS_IPL_ACTIVE("id2_14_post_no_int"))
	{
		BlipLesterFactory.enable = false;
		return;
	}

	if (VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, 717.0f, -975.0f, 25.0f) < distance)
	{
		UnloadIPL("id2_14_pre_no_int");
		UnloadIPL("id2_14_pre_no_int_lod");
		UnloadIPL("id2_14_post_no_int");
		UnloadIPL("id2_14_post_no_int_lod");
		LoadIPL("id2_14_during1");
		LoadIPL("id2_14_during1_lod");
		SetScenarioGroup("sew_machine", true);
		DOOR_SYSTEM_SET_DOOR_STATE(DOORHASH_SWEATSHOP_R, DOORSTATE_UNLOCKED, false, false);	// front (v_ilev_ss_door8)
		DOOR_SYSTEM_SET_DOOR_STATE(DOORHASH_SWEATSHOP_L, DOORSTATE_UNLOCKED, false, false);	// front (v_ilev_ss_door7)
	}
	else if (playerControl)
	{
		UnloadIPL("id2_14_during1");
		UnloadIPL("id2_14_during1_lod");
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

	if (VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, -1050.0f, -235.0f, 40.0f) < distance)
	{
		UnloadIPL("facelobbyfake");
		UnloadIPL("facelobbyfake_lod");
		LoadIPL("facelobby");
		LoadIPL("facelobby_lod");

		DOOR_SYSTEM_SET_DOOR_STATE(DOORHASH_LIFE_INVADER_FRONT_R, DOORSTATE_UNLOCKED, false, false);	// front (v_ilev_fb_doorshortl)
		DOOR_SYSTEM_SET_DOOR_STATE(DOORHASH_LIFE_INVADER_FRONT_L, DOORSTATE_UNLOCKED, false, false);	// front (v_ilev_fb_doorshortr)
		DOOR_SYSTEM_SET_DOOR_STATE(DOORHASH_LIFE_INVADER_REAR_L, DOORSTATE_UNLOCKED, false, false);		// rear (v_ilev_fb_door01)
		DOOR_SYSTEM_SET_DOOR_STATE(DOORHASH_LIFE_INVADER_REAR_R, DOORSTATE_UNLOCKED, false, false);		// rear (v_ilev_fb_door02)
		DOOR_SYSTEM_SET_DOOR_STATE(DOORHASH_LINVADER_OFFICE_UP, DOORSTATE_UNLOCKED, false, false);		// internal (v_ilev_door_orangesolid)
		//"Imagineering room"
		SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(969847031, -1057.767f, -237.484f, 43.021f, false, 0.0f, 0.0f, 0.0f);		// internal (v_ilev_fb_sl_door01)
		SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(969847031, -1063.842f, -240.6464f, 43.021f, false, 0.0f, 0.0f, 0.0f);		// internal (v_ilev_fb_sl_door01)
	}
	else if (playerControl)
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
	if (!iniFloydHouse || (iniStoryCompatibility && IS_IPL_ACTIVE("vb_30_crimetape")))
		return;
	
	UnloadIPL("vb_30_crimetape");
	DOOR_SYSTEM_SET_DOOR_STATE(DOORHASH_T_APARTMENT_VB, DOORSTATE_UNLOCKED, false, false);	// front (v_ilev_trev_doorfront)
	return;
}

//Vangelico Jewelry Store
void Vangelico()
{
	if (!iniVangelico || (iniStoryCompatibility && IS_IPL_ACTIVE("bh1_16_refurb")))
	{
		BlipVangelico.enable = false;
		return;
	}

	if (VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, -630.0f, -238.0f, 38.0f) < distance)
	{
		UnloadIPL("jewel2fake");
		UnloadIPL("jewel2fake_lod");
		UnloadIPL("bh1_16_refurb");
		LoadIPL("post_hiest_unload");
		LoadIPL("post_hiest_unload_lod");
		SetScenarioGroup("vangelico", true);
		DOOR_SYSTEM_SET_DOOR_STATE(DOORHASH_HEIST_JEWELERS_R, DOORSTATE_UNLOCKED, false, false);	// front (p_jewel_door_r1)
		DOOR_SYSTEM_SET_DOOR_STATE(DOORHASH_HEIST_JEWELERS_L, DOORSTATE_UNLOCKED, false, false);	// front (p_jewel_door_l)
	}
	else if (playerControl)
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
	if (iniMaxRenda && IS_IPL_ACTIVE("bh1_16_doors_shut"))
	{
		UnloadIPL("bh1_16_doors_shut");
		LoadIPL("refit_unload");
		LoadIPL("refit_unload_lod");
	}
	return;
}

//FIB
void FIB()
{
	if (!iniFIB)
		return;

	//Lobby
	if (VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, 106.0f, -745.0f, 46.0f) < distance)
	{
		UnloadIPL("fiblobbyfake");
		UnloadIPL("fiblobbyfake_lod");
		LoadIPL("fiblobby");
		LoadIPL("fiblobby_lod");
		DOOR_SYSTEM_SET_DOOR_STATE(DOORHASH_FIB_F_R, DOORSTATE_UNLOCKED, false, false);	// front (v_ilev_fibl_door01)
		DOOR_SYSTEM_SET_DOOR_STATE(DOORHASH_FIB_F_L, DOORSTATE_UNLOCKED, false, false);	// front (v_ilev_fibl_door02)
		SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(-2051651622, 127.8489f, -760.4548f, 45.90111f, false, 0.0f, 0.0f, 0.0f);	// internal (v_ilev_fib_door1)
		//Elevator doors
		SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(-1225363909, 134.9403f, -762.9027f, 44.75291f, false, 0.0f, 0.0f, 0.0f);	// internal (v_ilev_fib_doore_l)
		SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(1219957182, 137.7594f, -763.9288f, 44.75291f, false, 0.0f, 0.0f, 0.0f);	// internal (v_ilev_fib_doore_r)
		SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(-1225363909, 127.8489f, -760.4548f, 45.90111f, false, 0.0f, 0.0f, 0.0f);	// internal (v_ilev_fib_doore_l)
		SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(1219957182, 139.1689f, -764.4418f, 44.75182f, false, 0.0f, 0.0f, 0.0f);	// internal (v_ilev_fib_doore_r)
	}
	else if (playerControl)
	{
		UnloadIPL("fiblobby");
		UnloadIPL("fiblobby_lod");
		LoadIPL("fiblobbyfake");
		LoadIPL("fiblobbyfake_lod");
	}

	//Floors
	if (VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, 135.09f, -736.37f, 248.48f) < distance)
	{
		LoadIPL("v_fib01");
		LoadIPL("v_fib02");
		LoadIPL("v_fib03");
		LoadIPL("v_fib04");
		//Floor 47
		SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(-2051651622, 125.179f, -759.5534f, 234.3023f, false, 0.0f, 0.0f, 0.0f);	// internal (v_ilev_fib_door1)
		SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(-2051651622, 125.3935f, -757.5027f, 234.3021f, false, 0.0f, 0.0f, 0.0f);	// internal (v_ilev_fib_door1)
		SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(-2051651622, 117.1114f, -760.746f, 234.3022f, false, 0.0f, 0.0f, 0.0f);	// internal (v_ilev_fib_door1)
		SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(-2051651622, 111.8105f, -749.3636f, 234.3022f, false, 0.0f, 0.0f, 0.0f);	// internal (v_ilev_fib_door1)
		SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(-2051651622, 111.7746f, -748.436f, 234.3021f, false, 0.0f, 0.0f, 0.0f);	// internal (v_ilev_fib_door1)
		SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(-2051651622, 117.9132f, -743.9565f, 234.3021f, false, 0.0f, 0.0f, 0.0f);	// internal (v_ilev_fib_door1)

		if (missionFlag)
			return;

		//Floor 53 Security Door
		DeleteObjectAtCoords(878161517, 150.5931f, -762.3801f, 258.3018f);	// internal (prop_secdoor_01)
		Teleport(115.0094f, -741.8607f, 257.1523f, -25.0f, 160.0f, 141.0533f, -765.8549f, 44.7520f, 240, 200, 80, 150, "Press ~INPUT_ENTER~ to go to floor 53.", "Press ~INPUT_ENTER~ to return to the lobby.", false);
		Teleport(136.1618f, -761.7862f, 241.0520f, 160.0f, 160.0f, 136.1337f, -761.8162f, 44.7520f, 240, 200, 80, 150, "Press ~INPUT_ENTER~ to go to floor 49.", "Press ~INPUT_ENTER~ to return to the lobby.", false);
		Teleport(136.1340f, -761.8201f, 233.1521f, 160.0f, 160.0f, 138.9534f, -762.8441f, 44.7520f, 240, 200, 80, 150, "Press ~INPUT_ENTER~ to go to floor 47.", "Press ~INPUT_ENTER~ to return to the lobby.", false);
	}
	else if (playerControl && !missionFlag)
	{
		UnloadIPL("v_fib01");
		UnloadIPL("v_fib02");
		UnloadIPL("v_fib04");
	}
	return;
}

//Hayes Autos Chopshop (Devin Weston's Chop Shop)
void Chopshop()
{
	if (!iniChopshop)
		return;

	if (VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, 485.0f, -1315.0f, 30.0f) < distance)
	{
		LoadIPL("v_chopshop");
		EnableInterior(GET_INTERIOR_AT_COORDS(480.5f, -1319.0f, 30.0f));
		DOOR_SYSTEM_SET_DOOR_STATE(DOORHASH_CARSTEAL_GARAGE_S, 0, false, false);	// front (v_ilev_cs_door)
		UnlockChopshopGarage();
	}
	else if (playerControl)
	{
		DisableInterior(GET_INTERIOR_AT_COORDS(480.5f, -1319.0f, 30.0f));
		UnloadIPL("v_chopshop");
	}

	return;
}

//Tequi-la-la
void TequiLaLa()
{
	if (!iniTequiLaLa)
		return;

	if (VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, -565.0f, 277.0f, 84.0f) < distance)
	{
		LoadIPL("v_rockclub");
		EnableInterior(GET_INTERIOR_AT_COORDS(-565.0f, 276.5f, 83.5f));
		DOOR_SYSTEM_SET_DOOR_STATE(DOORHASH_TEQUILA_CLUB_DOOR_F, DOORSTATE_UNLOCKED, false, false);	// front (v_ilev_roc_door4)
		DOOR_SYSTEM_SET_DOOR_STATE(DOORHASH_TEQUILA_CLUB_DOOR_R, DOORSTATE_UNLOCKED, false, false);	// rear (v_ilev_roc_door4)
	}
	else if (playerControl)
	{
		DisableInterior(GET_INTERIOR_AT_COORDS(-565.0f, 276.5f, 83.5f));
		UnloadIPL("v_rockclub");
	}

	return;
}

//Maze Bank Arena (Fame or Shame)
void FameorShame()
{
	//Fix for Franklin's garage camera stuck
	if (!iniFameorShame || !playerControl)
		return;

	if (VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, -262.0f, -2021.0f, 36.0f) < distance)
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

	if (VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, -71.0f, 6266.0f, 32.0f) < distance)
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
		DOOR_SYSTEM_SET_DOOR_STATE(DOORHASH_CHICKENFACTORY_EXT_GATE, DOORSTATE_UNLOCKED, false, false);	// front (prop_fnclink_03gate5)
	}
	else if (playerControl)
	{
		UnloadIPL("cs1_02_cf_onmission1");
		UnloadIPL("cs1_02_cf_onmission1_lod");
		UnloadIPL("cs1_02_cf_onmission2");
		UnloadIPL("cs1_02_cf_onmission3");
		UnloadIPL("cs1_02_cf_onmission3_lod");
		UnloadIPL("cs1_02_cf_onmission4");
		UnloadIPL("cs1_02_cf_onmission4_lod");
		LoadIPL("cs1_02_cf_offmission");
		LoadIPL("cs1_02_cf_offmission_lod");
	}
	return;
}

//Grand Banks Steel Foundry
void Foundry()
{
	if (!iniFoundry)
		return;

	if (VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, 1085.0f, -2000.0f, 35.0f) < distance)
	{
		LoadIPL("v_foundry");
		EnableInterior(GET_INTERIOR_AT_COORDS(1089.5f, -1995.5f, 33.0f));
		DOOR_SYSTEM_SET_DOOR_STATE(DOORHASH_FOUNDRY_B_01, DOORSTATE_UNLOCKED, false, false);	// front (prop_ron_door_01)
		DOOR_SYSTEM_SET_DOOR_STATE(DOORHASH_FOUNDRY_B_02, DOORSTATE_UNLOCKED, false, false);	// front (prop_ron_door_01)
		DOOR_SYSTEM_SET_DOOR_STATE(DOORHASH_FOUNDRY_T_01, DOORSTATE_UNLOCKED, false, false);	// top (prop_ron_door_01)
	}
	else if (playerControl)
	{
		DisableInterior(GET_INTERIOR_AT_COORDS(1089.5f, -1995.5f, 33.0f));
		UnloadIPL("v_foundry");
	}

	return;
}

//Epsilon Encounter Room
void EpsilonRoom()
{
	if (!iniEpsilonRoom)
		return;

	if (VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, 241.0f, 361.0f, 106.0f) < distance)
	{
		LoadIPL("v_epsilonism");
		EnableInterior(GET_INTERIOR_AT_COORDS(245.5f, 370.0f, 106.3f));
		DOOR_SYSTEM_SET_DOOR_STATE(DOORHASH_EPSILON2_STORAGE_ROOM, DOORSTATE_UNLOCKED, false, false);	// front (v_ilev_epsstoredoor)
	}
	else if (playerControl)
	{
		DisableInterior(GET_INTERIOR_AT_COORDS(245.5f, 370.0f, 106.3f));
		UnloadIPL("v_epsilonism");
	}

	return;
}

//Harvey Molina's Apartment (Janitor's House)
void JanitorHouse()
{
	if (!iniJanitorHouse)
		return;

	if (VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, -108.0f, -9.0f, 71.0f) < distance)
	{
		LoadIPL("v_janitor");
		DOOR_SYSTEM_SET_DOOR_STATE(DOORHASH_JANITORS_APARTMENT, DOORSTATE_UNLOCKED, false, false);	// front (v_ilev_janitor_frontdoor)
	}
	else if (playerControl)
		UnloadIPL("v_janitor");

	return;
}

//O'Neil Ranch
void ONeilRanch()
{
	if (!iniONeilRanch || (iniStoryCompatibility && (IS_IPL_ACTIVE("farm_burnt") || IS_IPL_ACTIVE("des_farmhs_endimap"))))
	{
		BlipONeilRanch.enable = false;
		UnloadIPL("farmint_cap");
		UnloadIPL("farmint_cap_lod");
		return;
	}

	if (VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, 2445.0f, 4976.0f, 50.0f) < distance)
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
	else if (playerControl)
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

	if (VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, -605.0f, -1615.0f, 27.0f) < distance)
	{
		LoadIPL("v_recycle");
		EnableInterior(GET_INTERIOR_AT_COORDS(-611.4f, -1615.7f, 29.2f));
		DOOR_SYSTEM_SET_DOOR_STATE(DOORHASH_RECYCLING_PLANT_F_R, DOORSTATE_UNLOCKED, false, false);	// front (v_ilev_rc_door3_r)
		DOOR_SYSTEM_SET_DOOR_STATE(DOORHASH_RECYCLING_PLANT_F_L, DOORSTATE_UNLOCKED, false, false);	// front (v_ilev_rc_door3_l)
		DOOR_SYSTEM_SET_DOOR_STATE(DOORHASH_RECYCLING_PLANT_R_R, DOORSTATE_UNLOCKED, false, false);	// rear (v_ilev_rc_door3_r)
		DOOR_SYSTEM_SET_DOOR_STATE(DOORHASH_RECYCLING_PLANT_R_L, DOORSTATE_UNLOCKED, false, false);	// rear (v_ilev_rc_door3_l)
		DeleteObjectAtCoords(812467272, -589.5237f, -1621.55f, 33.16059f);		// internal (v_ilev_rc_door1_st)
		DeleteObjectAtCoords(812467272, -590.8198f, -1621.436f, 33.16059f);		// internal (v_ilev_rc_door1_st)
	}
	else if (playerControl)
	{
		DisableInterior(GET_INTERIOR_AT_COORDS(-611.4f, -1615.7f, 29.2f));
		UnloadIPL("v_recycle");
	}

	return;
}

//Humane Lab
void HumaneLab()
{
	if (!iniHumaneLab)
		return;

	if (VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, 3625.0f, 3750.0f, 28.0f) < distance)
	{
		LoadIPL("v_lab");
		DOOR_SYSTEM_SET_OPEN_RATIO(DOORHASH_CHEMICAL_FACTORY_R, -1.0f, false, false);	// front (v_ilev_bl_shutter2)
		DOOR_SYSTEM_SET_DOOR_STATE(DOORHASH_CHEMICAL_FACTORY_R, DOORSTATE_LOCKED, false, false);
		DOOR_SYSTEM_SET_OPEN_RATIO(DOORHASH_CHEMICAL_FACTORY_L, -1.0f, false, false);	// front (v_ilev_bl_shutter2)
		DOOR_SYSTEM_SET_DOOR_STATE(DOORHASH_CHEMICAL_FACTORY_L, DOORSTATE_LOCKED, false, false);

		if (missionFlag)
			return;

		Teleport(3540.6599f, 3675.5315f, 19.9918f, 170.0f, 170.0f, 3540.6272f, 3675.3850f, 27.1211f, 240, 200, 80, 150, "Press ~INPUT_ENTER~ to take the elevator.", "Press ~INPUT_ENTER~ to take the elevator.", false);
		//Underwater entrance at the cooling tunnels
		UnloadIPL("chemgrill_grp1");
	}
	else if (playerControl && !missionFlag)
		UnloadIPL("v_lab");

	return;
}

//Omega's Garage
void OmegaGarage()
{
	if (!iniOmegaGarage)
		return;

	if (VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, 2333.0f, 2575.0f, 47.0f) < distance)
	{
		DOOR_SYSTEM_SET_DOOR_STATE(DOORHASH_OMEGA_SHED_R, DOORSTATE_UNLOCKED, false, false);	// front (prop_ch3_01_trlrdoor_r)
		DOOR_SYSTEM_SET_DOOR_STATE(DOORHASH_OMEGA_SHED_L, DOORSTATE_UNLOCKED, false, false);	// front (prop_ch3_01_trlrdoor_l)
	}
	return;
}

//Blaine County Savings Bank
void BlaineCountyBank()
{
	if (!iniBlaineCountyBank)
		return;

	if (VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, -110.0f, 6462.0f, 32.0f) < distance)
	{
		LoadIPL("v_bank4");
		DOOR_SYSTEM_SET_DOOR_STATE(DOORHASH_RURAL_BANK_F_R, DOORSTATE_UNLOCKED, false, false);		// front (v_ilev_bank4door01)
		DOOR_SYSTEM_SET_DOOR_STATE(DOORHASH_RURAL_BANK_F_L, DOORSTATE_UNLOCKED, false, false);		// front (v_ilev_bank4door02)
		DOOR_SYSTEM_SET_DOOR_STATE(DOORHASH_PALETO_BANK_TELLER, DOORSTATE_UNLOCKED, false, false);	// internal (v_ilev_cbankcountdoor01)
	}
	else if (playerControl)
	{
		UnloadIPL("v_bank4");
	}
	return;
}

//Dignity Yacht
void DignityYacht()
{
	if (!iniDignityYacht || IS_IPL_ACTIVE("smboat"))
		return;

	LoadIPL("smboat");
	LoadIPL("smboat_lod");
	LoadIPL("smboat_lodlights");
	LoadIPL("smboat_distantlights");
	return;
}

//SS Bulker Container Ship
void ContainerShip()
{
	if (!iniContainerShip || (iniStoryCompatibility && (IS_IPL_ACTIVE("sunkcargoship") || IS_IPL_ACTIVE("sunk_ship_fire"))))
	{
		UnloadIPL("cargoship");
		UnloadIPL("cargoship_lod");
		return;
	}
	else if (IS_IPL_ACTIVE("cargoship"))
		return;

	LoadIPL("cargoship");
	LoadIPL("cargoship_lod");
	return;
}

//Union Depository Vault
void UnionDepositoryVault()
{
	if (!iniUnionDepository)
		return;

	if (VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, 15.0f, -690.0f, 35.0f) < distance)
	{
		LoadIPL("finbank");

		if (missionFlag)
			return;

		Teleport(-0.1434f, -705.9488f, 15.1312f, -25.0f, 0.0f, 10.3384f, -671.1154f, 32.4495f, 240, 200, 80, 150, "Press ~INPUT_ENTER~ to enter the UD vault.", "Press ~INPUT_ENTER~ to exit the vault.", false);
		SetSlidingDoorsStateAtCoords(-726591477, 11.656f, -668.4662f, 32.44926f, 8.760172f, -668.6967f, 32.44926f, false, -1.0f, 2.25f, 2.75f);	// internal (v_ilev_finelevdoor01)
		SetSlidingDoorsStateAtCoords(-726591477, 2.095137f, -704.072f, 15.13071f, -0.6344414f, -703.0778f, 15.13071f, false, -1.0f, 2.25f, 2.75f);	// internal (v_ilev_finelevdoor01)
		SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(-1932297301, -1.727947f, -686.5417f, 16.68913f, true, 0.0f, 0.0f, 1.0f);	// internal (v_ilev_fin_vaultdoor)
		SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(-1011692606, 8.171528f, -672.4393f, 16.35861f, true, 0.0f, 0.0f, 0.0f);	// internal (v_ilev_fingate)
		SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(-1011692606, -3.58445f, -668.1644f, 16.35861f, true, 0.0f, 0.0f, 0.0f);	// internal (v_ilev_fingate)
	}
	else if (playerControl && !missionFlag)
		UnloadIPL("finbank");

	return;
}

//Union Depository Parking
void UnionDepositoryParking()
{
	if (!iniUnionDepository)
		return;

	if (VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, -16.0f, -685.00f, 34.0f) < distance)
	{
		UnloadIPL("dt1_03_shutter");
		LoadIPL("dt1_03_carpark");
		EnableInterior(GET_INTERIOR_AT_COORDS(-16.0f, -685.00f, 34.0f));
	}
	else if (playerControl)
	{
		DisableInterior(GET_INTERIOR_AT_COORDS(-16.0f, -685.00f, 34.0f));
		UnloadIPL("dt1_03_carpark");
		LoadIPL("dt1_03_shutter");
	}
	return;
}

//Raven Slaughterhouse
void Slaughterhouse()
{
	if (!iniSlaughterhouse)
		return;

	if (VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, 994.0f, -2143.0f, 31.5f) < distance)
	{
		LoadIPL("v_abattoir");
		EnableInterior(GET_INTERIOR_AT_COORDS(981.0f, -2186.0f, 32.1f));

		//Behaviour taken from decompiled scripts
		DOOR_SYSTEM_SET_OPEN_RATIO(DOORHASH_ABBATOIR_FRONT_L, 1.0f, false, false);				// front (v_ilev_abbmaindoor)
		DOOR_SYSTEM_SET_DOOR_STATE(DOORHASH_ABBATOIR_FRONT_L, DOORSTATE_LOCKED, false, false);
		DOOR_SYSTEM_SET_OPEN_RATIO(DOORHASH_ABATTOIR_EXIT, 1.0f, false, false);					// rear (prop_abat_slide)
		DOOR_SYSTEM_SET_DOOR_STATE(DOORHASH_ABATTOIR_EXIT, DOORSTATE_LOCKED, false, false);
	}
	else if (playerControl)
	{
		DisableInterior(GET_INTERIOR_AT_COORDS(981.0f, -2186.0f, 32.1f));
		UnloadIPL("v_abattoir");
	}

	return;
}

//Solomon's Office
void SolomonOffice()
{
	if (!iniSolomonOffice)
		return;

	if (VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, -1007.14f, -478.53f, 51.57f) < distance)
	{
		LoadIPL("v_58_sol_office");
		EnableInterior(GET_INTERIOR_AT_COORDS(-1007.14f, -478.53f, 51.57f));
		
		if (missionFlag)
			return;

		Teleport(-1002.9615f, -477.8428f, 49.0271f, 120.0f, 120.0f, -1011.6970f, -480.1367f, 38.9756f, 240, 200, 80, 150, "Press ~INPUT_ENTER~ to enter Solomon's office.", "Press ~INPUT_ENTER~ to exit the office.", false);
		SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(-2030220382, -1002.147f, -478.0642f, 50.11668f, true, 0.0f, 0.0f, 0.0f);	// internal (v_ilev_sol_off_door01)
	}
	else if (playerControl && !missionFlag)
	{
		DisableInterior(GET_INTERIOR_AT_COORDS(-1007.14f, -478.53f, 51.57f));
		UnloadIPL("v_58_sol_office");
	}

	return;
}

//Ace Liquor (Meth lab)
void Methlab()
{
	if (iniMethlab && VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, 1393.0f, 3599.5f, 35.0f) < distance)
	{
		DOOR_SYSTEM_SET_DOOR_STATE(DOORHASH_METHLAB_F_R, DOORSTATE_UNLOCKED, false, false);	// front (v_ilev_ml_door1)
		DOOR_SYSTEM_SET_DOOR_STATE(DOORHASH_METHLAB_F_L, DOORSTATE_UNLOCKED, false, false);	// front (v_ilev_ml_door1)
		DOOR_SYSTEM_SET_DOOR_STATE(DOORHASH_METHLAB_R, DOORSTATE_UNLOCKED, false, false);	// rear (v_ilev_ss_door04)
	}
	return;
}

//Los Santos County Coroner Office (Morgue)
void Morgue()
{
	if (!iniMorgue)
		return;

	if (VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, 246.0f, -1374.0f, 32.5f) < distance)
	{
		UnloadIPL("coroner_int_off");
		LoadIPL("coroner_int_on");
		LoadIPL("coronertrash");
		EnableInterior(GET_INTERIOR_AT_COORDS(275.446f, -1361.11f, 24.5378f));

		if (!missionFlag)
			Teleport(247.0606f, -1371.8202f, 23.5378f, -45.0f, 145.0f, 240.9777f, -1379.1080f, 32.7417f, 240, 200, 80, 150, "Press ~INPUT_ENTER~ to enter the LS County Morgue.", "Press ~INPUT_ENTER~ to exit the morgue.", false);
	}
	else if (playerControl && !missionFlag)
	{
		DisableInterior(GET_INTERIOR_AT_COORDS(275.446f, -1361.11f, 24.5378f));
		UnloadIPL("coroner_int_on");
		UnloadIPL("coronertrash");
		LoadIPL("coroner_int_off");
	}

	return;
}

//The Motor Motel Room
void Motel()
{
	if (!iniMotel)
		return;

	if (VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, 1121.32f, 2642.65f, 39.17f) < distance || VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, 151.3630f, -1007.6400f, -100.0000f) < distance)
	{
		LoadIPL("v_motel_mp");
		EnableInterior(GET_INTERIOR_AT_COORDS(152.2600f, -1004.4700f, -99.0000f));

		if (!missionFlag)
			Teleport(151.3630f, -1007.6400f, -100.0000f, 0.0f, 0.0f, 1121.4703f, 2641.7883f, 37.1487f, 240, 200, 80, 150, "Press ~INPUT_ENTER~ to enter the The Motor Motel.", "Press ~INPUT_ENTER~ to exit the room.", false);
	}
	else if (playerControl)
	{
		DisableInterior(GET_INTERIOR_AT_COORDS(152.2600f, -1004.4700f, -99.0000f));
	}
	return;
}

//////////////////////////////////UNUSED INTERIORS//////////////////////////////////

//Paleto Bay Sheriff's Office
void PaletoSheriffOffice()
{
	if (!iniPaletoSheriffOffice)
		return;

	if (VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, -445.0f, 6017.0f, 32.0f) < distance)
	{
		UnloadIPL("cs1_16_sheriff_cap");
		LoadIPL("v_sheriff2");
		EnableInterior(GET_INTERIOR_AT_COORDS(-447.0f, 6013.5f, 32.3f));
		DOOR_SYSTEM_SET_DOOR_STATE(DOORHASH_SHERIFF_FRONT_R, DOORSTATE_UNLOCKED, false, false);	// front (v_ilev_shrf2door)
		DOOR_SYSTEM_SET_DOOR_STATE(DOORHASH_SHERIFF_FRONT_L, DOORSTATE_UNLOCKED, false, false);	// front (v_ilev_shrf2door)
	}
	else if (playerControl)
	{
		DisableInterior(GET_INTERIOR_AT_COORDS(-447.0f, 6013.5f, 32.3f));
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

	if (VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, 1856.0f, 3684.0f, 35.0f) < distance)
	{
		UnloadIPL("sheriff_cap");
		LoadIPL("v_sheriff");
		EnableInterior(GET_INTERIOR_AT_COORDS(1853.0f, 3688.0f, 35.0f));
		DOOR_SYSTEM_SET_DOOR_STATE(DOORHASH_SHERIFF_CS4, DOORSTATE_UNLOCKED, false, false);	// front (v_ilev_shrfdoor)
	}
	else if (playerControl)
	{
		DisableInterior(GET_INTERIOR_AT_COORDS(1853.0f, 3688.0f, 35.0f));
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

	if (VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, 447.0f, -980.0f, 31.0f) < distance)
	{
		SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(-1320876379, 446.5728f, -980.0104f, 30.8393f, false, 0.0f, 0.0f, 0.0f);	// internal (v_ilev_ph_gendoor002)
		SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(749848321, 453.0793f, -983.1894f, 30.83926f, false, 0.0f, 0.0f, 0.0f);	// internal (v_ilev_arm_secdoor)
	}
	return;
}

//North Yankton Surveillance Room
void YanktonSurveillance()
{
	if (!iniYanktonSurveillance)
		return;

	SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(-311575617, 5305.461f, -5177.75f, 83.66856f, false, 0.0f, 0.0f, 0.0f);	// internal (v_ilev_cd_door3)
	return;
}

//Pacific Standard Public Deposit Bank Vault
void PacificBankVault()
{
	if (!iniPacificBankVault)
		return;

	if (VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, 266.0f, 217.6f, 110.0f) < distance)
	{

		DOOR_SYSTEM_SET_DOOR_STATE(DOORHASH_BANK_VINEWOOD_OFFICE, DOORSTATE_UNLOCKED, false, false);	// internal (v_ilev_bk_door)
		DOOR_SYSTEM_SET_DOOR_STATE(DOORHASH_BANK_VINEWOOD_TELLER, DOORSTATE_UNLOCKED, false, false);	// internal (v_ilev_bk_gate)
		SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(961976194, 255.2283f, 223.976f, 102.3932f, true, 0.0f, 0.0f, -0.95f);		// internal (v_ilev_bk_vaultdoor)
	}
	return;
}

//Fleeca Banks Vaults
void FleecaBanks()
{
	if (!iniFleecaBanks)
		return;

	//Fleeca Bank - Blaine County
	if (VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, 1179.0f, 2709.0f, 38.0f) < distance)
	{
		SetObjectYawAtCoords(-131754413, 1178.87f, 2709.365f, 38.36251f, 0.0f);			// internal
		SetObjectYawAtCoords(2121050683, 1175.542f, 2710.861f, 38.22689f, 0.0f);		// internal
	}

	//Fleeca Bank - Los Santos County
	if (VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, -2960.0f, 479.0f, 16.0f) < distance)
	{
		SetObjectYawAtCoords(-131754413, -2960.176f, 479.0105f, 15.97156f, -90.0f);		// internal
		SetObjectYawAtCoords(2121050683, -2958.538f, 482.2705f, 15.83594f, -90.0f);		// internal
	}

	//Fleeca Bank - Burton
	if (VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, 310.0f, -280.0f, 54.0f) < distance)
	{
		SetObjectYawAtCoords(-131754413, 309.7491f, -280.1797f, 54.43926f, 160.0f);		// internal
		SetObjectYawAtCoords(2121050683, 312.358f, -282.7301f, 54.30365f, 160.0f);		// internal
	}

	//Fleeca Bank - Alta
	if (VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, -355.0f, -51.0f, 49.0f) < distance)
	{
		SetObjectYawAtCoords(-131754413, -355.3892f, -51.06768f, 49.31105f, 160.0f);	// internal
		SetObjectYawAtCoords(2121050683, -352.7365f, -53.57248f, 49.17543f, 160.0f);	// internal
	}

	//Fleeca Bank - Rockford Hills
	if (VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, -1215.0f, -335.0f, 38.0f) < distance)
	{
		SetObjectYawAtCoords(-131754413, -1214.906f, -334.7281f, 38.05551f, -150.0f);	// internal
		SetObjectYawAtCoords(2121050683, -1211.261f, -334.5596f, 37.91989f, -150.0f);	// internal
	}

	//Fleeca Bank - Pillbox Hill
	if (VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, 145.6f, -1042.0f, 30.0f) < distance)
	{
		SetObjectYawAtCoords(-131754413, 145.4186f, -1041.813f, 29.64255f, 160.0f);		// internal
		SetObjectYawAtCoords(2121050683, 148.0266f, -1044.364f, 29.50693f, 160.0f);		// internal
	}
	// v_ilev_gb_teldr			-131754413
	// v_ilev_gb_vauldr			2121050683
	return;
}

/////////////////////////////////////MISC/////////////////////////////////////

void Misc()
{
	if (!iniMiscInteriors)
		return;

	//Los Santos Naval Port Gates (Merryweather's Dock)
	if (VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, 492.0f, -3116.0f, 5.0f) < distance)
	{
		DOOR_SYSTEM_SET_DOOR_STATE(AUTODOOR_MIL_DOCKS_GATE_IN, DOORSTATE_UNLOCKED, false, false);	// internal (prop_gate_docks_ld)
		DOOR_SYSTEM_SET_DOOR_STATE(AUTODOOR_MIL_DOCKS_GATE_OUT, DOORSTATE_UNLOCKED, false, false);	// internal (prop_gate_docks_ld)
	}

	//Vanilla Unicorn Back Door
	DOOR_SYSTEM_SET_DOOR_STATE(DOORHASH_STRIPCLUB_R, DOORSTATE_UNLOCKED, false, false);				// rear (prop_magenta_door)

	//Pier 400 Gates
	if (VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, -150.0f, -2570.0f, 5.0f) < distance)
	{
		DOOR_SYSTEM_SET_DOOR_STATE(AUTODOOR_DOCKS_FRONT_GATE_IN, DOORSTATE_UNLOCKED, false, false);		// external (prop_gate_docks_ld)
		DOOR_SYSTEM_SET_DOOR_STATE(AUTODOOR_DOCKS_FRONT_GATE_OUT, DOORSTATE_UNLOCKED, false, false);	// external (prop_gate_docks_ld)
		DOOR_SYSTEM_SET_DOOR_STATE(AUTODOOR_DOCKS_BACK_GATE_IN, DOORSTATE_UNLOCKED, false, false);		// external (prop_gate_docks_ld)
		DOOR_SYSTEM_SET_DOOR_STATE(AUTODOOR_DOCKS_BACK_GATE_OUT, DOORSTATE_UNLOCKED, false, false);		// external (prop_gate_docks_ld)
	}

	//Garage Near Union Depository
	if (VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, -33.80561f, -621.6387f, 36.06102f) < distance)
		SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(-190780785, -33.80561f, -621.6387f, 36.06102f, false, 1.5f, 0.0f, 0.0f);	// front (prop_com_gar_door_01)

	//Garage in front of "Alpha Mail Couriers"
	if (VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, 1204.555f, -3110.386f, 6.557831f) < distance)
		SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(-190780785, 1204.555f, -3110.386f, 6.557831f, false, 0.0f, 0.0f, 0.0f);	// external (prop_com_gar_door_01)

	//Impound Lot  (Mission Row)
	if (VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, 431.0f, -1001.0f, 27.0f) < distance)
	{
		DOOR_SYSTEM_SET_DOOR_STATE(AUTODOOR_IMPOUND_R, DOORSTATE_UNLOCKED, false, false);	// external (prop_com_gar_door_01) 
		DOOR_SYSTEM_SET_DOOR_STATE(AUTODOOR_IMPOUND_L, DOORSTATE_UNLOCKED, false, false);	// external (prop_com_gar_door_01)
	}

	//Epsilon Vinewood Hills Garage
	if (VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, -689.1114f, 506.9815f, 110.6122f) < distance)
		DOOR_SYSTEM_SET_DOOR_STATE(DOORHASH_EPSILON3_GARAGE, DOORSTATE_UNLOCKED, false, false);	// external (prop_ch2_09c_garage_door)

	//Stab City Trailer
	if (VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, 29.0f, 3661.5f, 41.0f) < distance)
	{
		DOOR_SYSTEM_SET_DOOR_STATE(DOORHASH_HENCHMAN_TRAILER_L, DOORSTATE_UNLOCKED, false, false);	// external (prop_magenta_door)
		DOOR_SYSTEM_SET_DOOR_STATE(DOORHASH_HENCHMAN_TRAILER_R, DOORSTATE_UNLOCKED, false, false);	// external (prop_cs4_05_tdoor)
	}

	//Vagos doors near the beach
	if (VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, -1100.0f, -1638.5f, 5.0f) < distance)
	{
		DOOR_SYSTEM_SET_DOOR_STATE(DOORHASH_ARM2_HENCH_01, DOORSTATE_UNLOCKED, false, false);	// external (prop_map_door_01)
		//Repossession Garages Fix
		if (!missionFlag)
		{
			SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(-2029892494, -1127.104f, -1586.979f, 5.092136f, false, 0.0f, 0.0f, 0.0f);	// external (prop_arm_gate_l)
			SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(-2029892494, -1131.989f, -1590.397f, 5.092136f, false, 0.0f, 0.0f, 0.0f);	// external (prop_arm_gate_l)
			DOOR_SYSTEM_SET_DOOR_STATE(DOORHASH_ARM2_GARAGE_01, DOORSTATE_UNLOCKED, false, false);	// external (prop_gar_door_01)
			DOOR_SYSTEM_SET_DOOR_STATE(DOORHASH_ARM2_GARAGE_02, DOORSTATE_UNLOCKED, false, false);	// external (prop_gar_door_02)
		}
	}

	//LSPD Auto Impound Gate
	if (VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, 375.9481f, -1632.531f, 27.24899f) < distance)
		DeleteObjectAtCoords(-577103870, 375.9481f, -1632.531f, 27.24899f);	// external (prop_sec_gate_01c)

	//Josh Bernstein's House Gates
	if (VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, -1119.335f, 292.975f, 66.5f) < distance)
	{
		DOOR_SYSTEM_SET_DOOR_STATE(DOORHASH_JOSH_GATE_F_R, DOORSTATE_UNLOCKED, false, false);	// external (prop_lrggate_01c_r)
		DOOR_SYSTEM_SET_DOOR_STATE(DOORHASH_JOSH_GATE_F_L, DOORSTATE_UNLOCKED, false, false);	// external (prop_lrggate_01c_l)
		DOOR_SYSTEM_SET_DOOR_STATE(DOORHASH_JOSH_GATE_R_R, DOORSTATE_UNLOCKED, false, false);	// external (prop_lrggate_01c_r)
		DOOR_SYSTEM_SET_DOOR_STATE(DOORHASH_JOSH_GATE_R_L, DOORSTATE_UNLOCKED, false, false);	// external (prop_lrggate_01c_l)
	}

	//Epsilon Center Gates
	if (VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, -725.095f, 89.825f, 56.68f) < distance)
	{
		DOOR_SYSTEM_SET_DOOR_STATE(DOORHASH_EPSILON_GATE_R, DOORSTATE_UNLOCKED, false, false);	// external (prop_gate_tep_01_r)
		DOOR_SYSTEM_SET_DOOR_STATE(DOORHASH_EPSILON_GATE_L, DOORSTATE_UNLOCKED, false, false);	// external (prop_gate_tep_01_l)
	}

	//Cletus Ewing's House Gate
	if (VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, 1803.94f, 3929.01f, 33.72f) < distance)
		DOOR_SYSTEM_SET_DOOR_STATE(DOORHASH_CLETUS_GATE, DOORSTATE_UNLOCKED, false, false);	// external (prop_fnclink_07gate1)
	return;
}

void Gates()
{
	if (!iniGates)
		return;

	SetSingleSlidingDoorStateAtCoords(prop_facgate_01, 1012.908f, -2456.231f, 27.52899f, -3.0f, 0.0f, false, 1.0f, gatesMinDist, gatesAltMaxDist);
	SetSingleSlidingDoorStateAtCoords(prop_facgate_01, 1000.681f, -2454.992f, 27.56737f, -3.0f, 0.0f, false, 1.0f, gatesMinDist, gatesAltMaxDist);
	SetSingleSlidingDoorStateAtCoords(prop_facgate_01, 1028.076f, -2364.72f, 29.5156f, -3.0f, 0.0f, false, 1.0f, gatesMinDist, gatesAltMaxDist);
	SetSingleSlidingDoorStateAtCoords(prop_facgate_01, 1033.22f, -2299.096f, 29.5156f, -3.0f, 0.0f, false, 1.0f, gatesMinDist, gatesAltMaxDist);
	SetSingleSlidingDoorStateAtCoords(prop_facgate_01, 1022.367f, -2417.209f, 28.39544f, -3.0f, 0.0f, false, 1.0f, gatesMinDist, gatesAltMaxDist);
	SetSlidingDoorsStateAtCoords(prop_facgate_01, 705.6044f, -1319.417f, 24.89731f, 712.9515f, -1329.419f, 24.93871f, false, 1.0f, gatesMinDist, gatesMaxDist);
	SetSingleSlidingDoorStateAtCoords(prop_facgate_01, 987.5148f, -1176.826f, 24.5557f, -3.0f, 0.0f, false, 1.0f, gatesMinDist, gatesAltMaxDist);
	SetSpecialGatesStateAtCoords(prop_facgate_01, prop_facgate_01b, 796.4732f, -921.7579f, 24.54157f, 795.7961f, -909.2122f, 24.40896f, false, 1.0f, gatesMinDist, gatesMaxDist);
	SetSpecialGatesStateAtCoords(prop_facgate_01, prop_facgate_01b, 795.0599f, -896.7894f, 24.28326f, 794.4017f, -884.3021f, 24.12696f, false, 1.0f, gatesMinDist, gatesMaxDist);
	SetSlidingDoorsStateAtCoords(prop_facgate_01, -160.8777f, -2636.198f, 5.025181f, -148.7143f, -2636.198f, 5.032078f, false, 1.0f, gatesMinDist, gatesMaxDist);
	SetSlidingDoorsStateAtCoords(prop_facgate_01, 155.318f, -2619.044f, 5.013092f, 167.4531f, -2619.572f, 5.013092f, false, 1.0f, gatesMinDist, gatesMaxDist);
	SetSingleSlidingDoorStateAtCoords(prop_facgate_01, 237.7759f, -2936.957f, 4.968819f, -3.0f, 0.0f, false, 1.0f, gatesMinDist, gatesAltMaxDist);
	SetSpecialGatesStateAtCoords(prop_facgate_01, prop_facgate_01b, 117.7632f, -1609.619f, 28.3253f, 107.1967f, -1615.722f, 28.32404f, false, 1.0f, gatesMinDist, gatesMaxDist);
	SetSlidingDoorsStateAtCoords(prop_facgate_01, 547.9453f, -1865.052f, 24.35131f, 538.541f, -1872.845f, 24.35131f, false, 1.0f, gatesMinDist, gatesMaxDist);
	SetSpecialGatesStateAtCoords(prop_facgate_01, prop_facgate_01b, 466.7599f, -1939.655f, 23.65514f, 455.7382f, -1944.846f, 23.65514f, false, 1.0f, gatesMinDist, gatesMaxDist);
	SetSpecialGatesStateAtCoords(prop_facgate_01, prop_facgate_01b, 550.9767f, -1896.741f, 24.14621f, 539.9556f, -1901.955f, 24.2161f, false, 1.0f, gatesMinDist, gatesMaxDist);
	SetSpecialGatesStateAtCoords(prop_facgate_01, prop_facgate_01b, 564.1142f, -1903.0f, 23.7104f, 570.6271f, -1913.332f, 23.7104f, false, 1.0f, gatesMinDist, gatesMaxDist);
	SetSlidingDoorsStateAtCoords(prop_facgate_01, -994.4996f, -2341.648f, 12.94479f, -984.079f, -2348.4f, 12.94479f, false, 1.0f, gatesMinDist, gatesMaxDist);
	SetSingleSlidingDoorStateAtCoords(prop_facgate_01, -1213.4f, -2079.3f, 12.90274f, -3.0f, 0.0f, false, 1.0f, gatesMinDist, gatesAltMaxDist);
	SetSingleSlidingDoorStateAtCoords(prop_facgate_01, -1099.531f, -2020.803f, 12.17445f, -3.0f, 0.0f, false, 1.0f, gatesMinDist, gatesAltMaxDist);
	SetSingleSlidingDoorStateAtCoords(prop_facgate_01, -1019.616f, -1897.02f, 13.41593f, -3.0f, 0.0f, false, 1.0f, gatesMinDist, gatesAltMaxDist);
	SetSingleSlidingDoorStateAtCoords(prop_facgate_01, 2491.868f, -303.4783f, 91.99238f, -3.0f, 0.0f, false, 1.0f, gatesMinDist, gatesAltMaxDist);
	SetSingleSlidingDoorStateAtCoords(prop_facgate_01, 1937.405f, -958.2576f, 78.15379f, -3.0f, 0.0f, false, 1.0f, gatesMinDist, gatesAltMaxDist);
	SetSingleSlidingDoorStateAtCoords(prop_facgate_01b, 1954.208f, -957.1394f, 78.15379f, 3.0f, 0.0f, false, -1.0f, gatesMinDist, gatesAltMaxDist);
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
	if (!missionFlag)
		SetScenarioGroup("paleto_bank", true);
	else
		SetScenarioGroup("paleto_bank", false);
	return;
}

///////////////////////////////////////EXTRAS/////////////////////////////////////////
//KEEP THIS UPDATED with the functions up here!!
void UnlockDoors()
{
	//Michael's House Gate and window
	if (iniMichaelHouse)
		SetAutoDoorState(AUTODOOR_MICHAEL_MANSION_GATE, DOORSTATE_UNLOCKED, 0.75f, 15.0f, true);

	//Vangelico Jewelry Store doors
	if (iniVangelico && !(iniStoryCompatibility && IS_IPL_ACTIVE("bh1_16_refurb")) && VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, -630.0f, -238.0f, 38.0f) < distance)
	{
		DOOR_SYSTEM_SET_DOOR_STATE(DOORHASH_HEIST_JEWELERS_R, DOORSTATE_UNLOCKED, false, false);
		DOOR_SYSTEM_SET_DOOR_STATE(DOORHASH_HEIST_JEWELERS_L, DOORSTATE_UNLOCKED, false, false);
	}

	//FIB
	if (iniFIB && !missionFlag)
	{
		DeleteObjectAtCoords(878161517, 150.5931f, -762.3801f, 258.3018f);
		Teleport(115.0094f, -741.8607f, 257.1523f, -25.0f, 160.0f, 141.0533f, -765.8549f, 44.7520f, 240, 200, 80, 150, "Press ~INPUT_ENTER~ to go to floor 53.", "Press ~INPUT_ENTER~ to return to the lobby.", false);
		Teleport(136.1618f, -761.7862f, 241.0520f, 160.0f, 160.0f, 136.1337f, -761.8162f, 44.7520f, 240, 200, 80, 150, "Press ~INPUT_ENTER~ to go to floor 49.", "Press ~INPUT_ENTER~ to return to the lobby.", false);
		Teleport(136.1340f, -761.8201f, 233.1521f, 160.0f, 160.0f, 138.9534f, -762.8441f, 44.7520f, 240, 200, 80, 150, "Press ~INPUT_ENTER~ to go to floor 47.", "Press ~INPUT_ENTER~ to return to the lobby.", false);
	}

	//Chopshop
	if (VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, 485.0f, -1315.0f, 30.0f) < distance)
	{
		DOOR_SYSTEM_SET_DOOR_STATE(DOORHASH_CARSTEAL_GARAGE_S, DOORSTATE_UNLOCKED, false, false);
		UnlockChopshopGarage();
	}

	//Foundry
	if (iniFoundry && VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, 1085.0f, -2000.0f, 35.0f) < distance)
	{
		DOOR_SYSTEM_SET_DOOR_STATE(DOORHASH_FOUNDRY_B_01, DOORSTATE_UNLOCKED, false, false);
		DOOR_SYSTEM_SET_DOOR_STATE(DOORHASH_FOUNDRY_B_02, DOORSTATE_UNLOCKED, false, false);
		DOOR_SYSTEM_SET_DOOR_STATE(DOORHASH_FOUNDRY_T_01, DOORSTATE_UNLOCKED, false, false);

	}

	//Scrapyard
	if (iniScrapyard && VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, -605.0f, -1615.0f, 27.0f) < distance)
	{
		DOOR_SYSTEM_SET_DOOR_STATE(DOORHASH_RECYCLING_PLANT_F_R, DOORSTATE_UNLOCKED, false, false);
		DOOR_SYSTEM_SET_DOOR_STATE(DOORHASH_RECYCLING_PLANT_F_L, DOORSTATE_UNLOCKED, false, false);
		DOOR_SYSTEM_SET_DOOR_STATE(DOORHASH_RECYCLING_PLANT_R_R, DOORSTATE_UNLOCKED, false, false);
		DOOR_SYSTEM_SET_DOOR_STATE(DOORHASH_RECYCLING_PLANT_R_L, DOORSTATE_UNLOCKED, false, false);
	}

	//Humane Lab
	if (iniHumaneLab && !missionFlag)
		Teleport(3540.6599f, 3675.5315f, 19.9918f, 170.0f, 170.0f, 3540.6272f, 3675.3850f, 27.1211f, 240, 200, 80, 150, "Press ~INPUT_ENTER~ to take the elevator.", "Press ~INPUT_ENTER~ to take the elevator.", false);

	//Omega's Garage
	if (iniOmegaGarage && VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, 2333.0f, 2575.0f, 47.0f) < distance)
	{
		DOOR_SYSTEM_SET_DOOR_STATE(DOORHASH_OMEGA_SHED_R, DOORSTATE_UNLOCKED, false, false);
		DOOR_SYSTEM_SET_DOOR_STATE(DOORHASH_OMEGA_SHED_L, DOORSTATE_UNLOCKED, false, false);
	}

	//Union Depository Vault Doors
	if (iniUnionDepository && !missionFlag && VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, 15.0f, -690.0f, 35.0f) < distance)
	{
		Teleport(-0.1434f, -705.9488f, 15.1312f, -25.0f, 0.0f, 10.3384f, -671.1154f, 32.4495f, 240, 200, 80, 150, "Press ~INPUT_ENTER~ to enter the UD vault.", "Press ~INPUT_ENTER~ to exit the vault.", false);
		SetSlidingDoorsStateAtCoords(-726591477, 11.656f, -668.4662f, 32.44926f, 8.760172f, -668.6967f, 32.44926f, false, -1.0f, 2.25f, 2.75f);
		SetSlidingDoorsStateAtCoords(-726591477, 2.095137f, -704.072f, 15.13071f, -0.6344414f, -703.0778f, 15.13071f, false, -1.0f, 2.25f, 2.75f);
	}

	//Solomon's Office
	if (iniSolomonOffice && !missionFlag)
		Teleport(-1002.9615f, -477.8428f, 49.0271f, 120.0f, 120.0f, -1011.6970f, -480.1367f, 38.9756f, 240, 200, 80, 150, "Press ~INPUT_ENTER~ to enter Solomon's office.", "Press ~INPUT_ENTER~ to exit the office.", false);

	//Los Santos County Coroner Office (Morgue)
	if (iniMorgue && !missionFlag)
		Teleport(247.0606f, -1371.8202f, 23.5378f, -45.0f, 145.0f, 240.9777f, -1379.1080f, 32.7417f, 240, 200, 80, 150, "Press ~INPUT_ENTER~ to enter the LS County Morgue.", "Press ~INPUT_ENTER~ to exit the morgue.", false);

	//The Motor Motel Room
	if (iniMotel && !missionFlag)
		Teleport(151.3630f, -1007.6400f, -100.0000f, 0.0f, 0.0f, 1121.4703f, 2641.7883f, 37.1487f, 240, 200, 80, 150, "Press ~INPUT_ENTER~ to enter the The Motor Motel.", "Press ~INPUT_ENTER~ to exit the room.", false);

	//Pacific Standard Public Deposit Bank Vault
	PacificBankVault();

	//Misc
	if (iniMiscInteriors)
	{		
		//Epsilon Center Gates
		if (VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, -725.095f, 89.825f, 56.68f) < distance)
		{
			DOOR_SYSTEM_SET_DOOR_STATE(DOORHASH_EPSILON_GATE_R, DOORSTATE_UNLOCKED, false, false);	// external (prop_gate_tep_01_r)
			DOOR_SYSTEM_SET_DOOR_STATE(DOORHASH_EPSILON_GATE_L, DOORSTATE_UNLOCKED, false, false);	// external (prop_gate_tep_01_l)
		}
	}
	return;
}

void UnlockBarriersNearPlayer()
{
	if (!iniUnlockBarriersNearPlayer)
		return;

	//Squared because of VDIST2
	const float minDist = 7.0f * 7.0f;
	const float maxDist = 8.5f * 8.5f;
	Object barrier = NULL;

	Object barrier1 = OBJECT::GET_CLOSEST_OBJECT_OF_TYPE(playerLoc.x, playerLoc.y, playerLoc.z, 20.0f, -1184516519, false, false, false);	//prop_sec_barrier_ld_01a
	Object barrier2 = OBJECT::GET_CLOSEST_OBJECT_OF_TYPE(playerLoc.x, playerLoc.y, playerLoc.z, 20.0f, 1230099731, false, false, false);	//prop_sec_barrier_ld_02a
	bool barrier1Exists = DOES_ENTITY_EXIST(barrier1);
	bool barrier2Exists = DOES_ENTITY_EXIST(barrier2);

	//Choose the closest barrier if both exists
	if (barrier1Exists && barrier2Exists)
	{
		Vector3 barrier1Loc = GET_ENTITY_COORDS(barrier1, false);
		Vector3 barrier2Loc = GET_ENTITY_COORDS(barrier2, false);
		float distance1 = VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, barrier1Loc.x, barrier1Loc.y, barrier1Loc.z);
		float distance2 = VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, barrier2Loc.x, barrier2Loc.y, barrier2Loc.z);
		if (distance1 < distance2)
			barrier = barrier1;
		else
			barrier = barrier2;
	}
	else if (barrier1Exists)
		barrier = barrier1;
	else if (barrier2Exists)
		barrier = barrier2;
	else
		return;

	Vector3 coords = GET_ENTITY_COORDS(barrier, false);
	float dist = VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, coords.x, coords.y, coords.z);
	if (dist < minDist)
	{
		//Check if last barrier has been closed correctly before opening a new one
		if (lastBarrier != barrier && DOES_ENTITY_EXIST(lastBarrier))
		{
			Vector3 lastBarrierLoc = GET_ENTITY_COORDS(lastBarrier, false);
			SET_STATE_OF_CLOSEST_DOOR_OF_TYPE(GET_ENTITY_MODEL(lastBarrier), lastBarrierLoc.x, lastBarrierLoc.y, lastBarrierLoc.z, false, -1.0f, true);
		}
		SET_STATE_OF_CLOSEST_DOOR_OF_TYPE(GET_ENTITY_MODEL(barrier), coords.x, coords.y, coords.z, false, 1.0f, true);
	}	
	else if (dist > maxDist)
		SET_STATE_OF_CLOSEST_DOOR_OF_TYPE(GET_ENTITY_MODEL(barrier), coords.x, coords.y, coords.z, false, -1.0f, true);

	lastBarrier = barrier;
	return;
}
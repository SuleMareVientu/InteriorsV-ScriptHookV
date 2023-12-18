//ScriptHook
#include <natives.h>
// #include <types.h> //Already included in globals.h
//Custom
#include "..\globals.h"
#include "interiors.h"
#include "functions.h"

float distance = 100000.0f;  //use VDIST2 to save on resources by not calculating the sqr: sqr100000 = 315 units

//////////////////////////////////////SAFEHOUSES//////////////////////////////////////

//Clinton Residence (Franklin's Aunt House)
void ClintonResidence()
{
	if (!iniClintonResidence)
		return;

	if (SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, -15.0f, -1441.0f, 31.0f) < distance)
	{
		LoadIPL("v_franklins");
		OBJECT::SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(520341586, -14.86892f, -1441.182f, 31.19323f, false, 0.0f, 0.0f, 0.0f);	// front (v_ilev_fa_frontdoor)
		OBJECT::SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(703855057, -25.2784f, -1431.061f, 30.83955f, false, 0.0f, 0.0f, 0.0f);	// garage (prop_sc1_21_g_door_01)
	}
	return;
}

//3671 Whispymound Drive (Franklin's Mansion)
void FranklinMansion()
{
	if (!iniFranklinMansion)
		return;

	if (SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, 8.0f, 540.0f, 176.0f) < distance)
	{
		int v_franklinshouse = INTERIOR::GET_INTERIOR_AT_COORDS(7.3f, 531.3f, 175.9f);
		LoadIPL("v_franklinshouse");
		EnableInterior(v_franklinshouse);
		DisableInteriorProp(v_franklinshouse, "locked", false);
		EnableInteriorProp(v_franklinshouse, "unlocked", true);
		OBJECT::SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(308207762, 7.518359f, 539.5268f, 176.1776f, false, 0.0f, 0.0f, 0.0f);		// front (v_ilev_fh_frontdoor)
		OBJECT::SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(2052512905, 18.65038f, 546.3401f, 176.3448f, false, 0.0f, 0.0f, 0.0f);	// garage (prop_ch_025c_g_door_01)
	}
	return;
}

//Michael's House
void MichaelHouse()
{
	if (!iniMichaelHouse)
		return;

	if (SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, -820.0f, 165.0f, 70.0f) < distance)
	{
		int v_michael = INTERIOR::GET_INTERIOR_AT_COORDS(-809.2f, 180.7f, 73.2f);
		LoadIPL("v_michael");
		LoadIPL("v_michael_garage");

		if (!INTERIOR::IS_INTERIOR_ENTITY_SET_ACTIVE(v_michael, "V_Michael_bed_Messy"))
			EnableInteriorProp(v_michael, "V_Michael_bed_tidy", true);

		//Check if player is NOT Michael
		if (PED::GET_PED_TYPE(PLAYER::PLAYER_PED_ID()) != 0)
		{
			SetDoorUnlockDistanceWithRate(-2125423493, -844.051f, 155.9619f, 66.03221f, 1.0f, 15.15f);	// front gate (prop_lrggate_02_ld)
			OBJECT::SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(-1568354151, -848.9343f, 179.3079f, 70.0247f, false, 0.0f, 0.0f, 0.0f);	// front (prop_bh1_48_gate_1)
			OBJECT::SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(-1686014385, -816.1068f, 177.5109f, 72.82738f, false, 0.0f, 0.0f, 0.0f);	// front (v_ilev_mm_doorm_r)
			OBJECT::SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(159994461, -816.716f, 179.098f, 72.82738f, false, 0.0f, 0.0f, 0.0f);		// front (v_ilev_mm_doorm_l)
			OBJECT::SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(1245831483, -794.1853f, 182.568f, 73.04045f, false, 0.0f, 0.0f, 0.0f);	// rear (prop_bh1_48_backdoor_r)
			OBJECT::SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(-1454760130, -793.3943f, 180.5075f, 73.04045f, false, 0.0f, 0.0f, 0.0f);	// rear (prop_bh1_48_backdoor_l)
			OBJECT::SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(1245831483, -794.5051f, 178.0124f, 73.04045f, false, 0.0f, 0.0f, 0.0f);	// rear (prop_bh1_48_backdoor_r)
			OBJECT::SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(-1454760130, -796.5657f, 177.2214f, 73.04045f, false, 0.0f, 0.0f, 0.0f);	// rear (prop_bh1_48_backdoor_l)
			OBJECT::SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(30769481, -815.2816f, 185.975f, 72.99993f, false, 0.0f, 0.0f, 0.0f);		// garage (prop_ld_garaged_01)
		}
	}
	return;
}

//Trevor's Trailer
void TrevorTrailer()
{
	if (!iniTrevorTrailer)
		return;

	if (SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, 1973.0f, 3815.0f, 34.0f) < distance)
	{
		if (!STREAMING::IS_IPL_ACTIVE("trevorstrailertrash"))
		{
			UnloadIPL("trevorstrailer");
			LoadIPL("trevorstrailertidy");
		}
		OBJECT::SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(132154435, 1972.769f, 3815.366f, 33.66326f, false, 0.0f, 0.0f, 0.0f);	// front (v_ilev_trevtraildr)
		OBJECT::SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(67910261, 1972.787f, 3824.554f, 32.65174f, false, 0.0f, 0.0f, 0.0f);	// garage (prop_cs4_10_tr_gd_01)
	}
	return;
}

//////////////////////////////////MISSION INTERIORS//////////////////////////////////

//Premium Deluxe Motorsport (Simeon's Showroom)
void PremiumDeluxeMotorsport()
{
	if (!iniPremiumDeluxeMotorsport)
		return;

	if (SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, -45.0f, -1100.0f, 27.0f) < distance)
	{
		UnloadIPL("fakeint");
		UnloadIPL("fakeint_lod");
		LoadIPL("shr_int");
		LoadIPL("shr_int_lod");
		int v_carshowroom = INTERIOR::GET_INTERIOR_AT_COORDS(-44.0f, -1097.5f, 27.0f);
		EnableInterior(v_carshowroom);
		DisableInteriorProp(v_carshowroom, "shutter_closed", false);
		EnableInteriorProp(v_carshowroom, "shutter_open", true);
		SetScenarioGroup("dealership", true);
		OBJECT::SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(1417577297, -37.33113f, -1108.873f, 26.7198f, false, 0.0f, 0.0f, 0.0f);	// front (v_ilev_csr_door_r)
		OBJECT::SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(2059227086, -39.13366f, -1108.218f, 26.7198f, false, 0.0f, 0.0f, 0.0f);	// front (v_ilev_csr_door_l)
		OBJECT::SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(1417577297, -60.54582f, -1094.749f, 26.88872f, false, 0.0f, 0.0f, 0.0f);	// front (v_ilev_csr_door_r)
		OBJECT::SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(2059227086, -59.89302f, -1092.952f, 26.88362f, false, 0.0f, 0.0f, 0.0f);	// front (v_ilev_csr_door_l)
		OBJECT::SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(-2051651622, -31.72353f, -1101.846f, 26.57225f, false, 0.0f, 0.0f, 0.0f);	// internal (v_ilev_fib_door1)
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

	if (SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, 1274.0f, -1720.0f, 55.0f) < distance)
	{
		LoadIPL("v_lesters");
		OBJECT::SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(1145337974, 1273.816f, -1720.697f, 54.92143f, false, 0.0f, 0.0f, 0.0f);	// front (v_ilev_lester_doorfront)
	}
	else
		UnloadIPL("v_lesters");
	return;
}

//Darnell Bros. Factory (Leaster's Factory)
void LesterFactory()
{
	if (!iniLesterFactory || STREAMING::IS_IPL_ACTIVE("id2_14_during1") || STREAMING::IS_IPL_ACTIVE("id2_14_during2") || STREAMING::IS_IPL_ACTIVE("id2_14_on_fire"))
	{
		BlipLesterFactory.enable = false;
		return;
	}

	if (iniStoryCompatibility && STREAMING::IS_IPL_ACTIVE("id2_14_post_no_int"))
	{
		BlipLesterFactory.enable = false;
		return;
	}

	if (SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, 717.0f, -975.0f, 25.0f) < distance)
	{
		UnloadIPL("id2_14_pre_no_int");
		UnloadIPL("id2_14_pre_no_int_lod");
		UnloadIPL("id2_14_post_no_int");
		UnloadIPL("id2_14_post_no_int_lod");
		LoadIPL("id2_14_during1");
		LoadIPL("id2_14_during1_lod");
		SetScenarioGroup("sew_machine", true);
		OBJECT::SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(245182344, 716.7808f, -975.4207f, 25.00572f, false, 0.0f, 0.0f, 0.0f);	// front (v_ilev_ss_door8)
		OBJECT::SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(-681066206, 719.3818f, -975.4185f, 25.00572f, false, 0.0f, 0.0f, 0.0f);		// front (v_ilev_ss_door7)
	}
	else
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

	if (SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, -1050.0f, -235.0f, 40.0f) < distance)
	{
		UnloadIPL("facelobbyfake");
		UnloadIPL("facelobbyfake_lod");
		LoadIPL("facelobby");
		LoadIPL("facelobby_lod");
		OBJECT::SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(1104171198, -1045.12f, -232.004f, 39.43794f, false, 0.0f, 0.0f, 0.0f);	// rear (v_ilev_fb_doorshortl)
		OBJECT::SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(-1425071302, -1046.516f, -229.3581f, 39.43794f, false, 0.0f, 0.0f, 0.0f);	// rear (v_ilev_fb_doorshortr)
		OBJECT::SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(-1679881977, -1083.62f, -260.4166f, 38.1867f, false, 0.0f, 0.0f, 0.0f);	// front (v_ilev_fb_door01)
		OBJECT::SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(-1045015371, -1080.974f, -259.0203f, 38.1867f, false, 0.0f, 0.0f, 0.0f);	// front (v_ilev_fb_door02)
		OBJECT::SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(-495720969, -1055.958f, -236.4251f, 44.171f, false, 0.0f, 0.0f, 0.0f);	// internal (v_ilev_door_orangesolid)
		//"Imagineering room"
		OBJECT::SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(969847031, -1057.767f, -237.484f, 43.021f, false, 0.0f, 0.0f, 0.0f);		// internal (v_ilev_fb_sl_door01)
		OBJECT::SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(969847031, -1063.842f, -240.6464f, 43.021f, false, 0.0f, 0.0f, 0.0f);		// internal (v_ilev_fb_sl_door01)
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
	OBJECT::SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(-607040053, -1149.709f, -1521.088f, 10.78267f, false, 0.0f, 0.0f, 0.0f);	// front (v_ilev_trev_doorfront)
	
	return;
}

//Vangelico Jewelry Store
void Vangelico()
{
	if (!iniVangelico || (iniStoryCompatibility && STREAMING::IS_IPL_ACTIVE("bh1_16_refurb")))
	{
		BlipVangelico.enable = false;
		return;
	}

	if (SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, -630.0f, -238.0f, 38.0f) < distance)
	{
		UnloadIPL("jewel2fake");
		UnloadIPL("jewel2fake_lod");
		UnloadIPL("bh1_16_refurb");
		LoadIPL("post_hiest_unload");
		LoadIPL("post_hiest_unload_lod");
		SetScenarioGroup("vangelico", true);
		OBJECT::SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(9467943, -630.4265f, -238.4375f, 38.20653f, false, 0.0f, 0.0f, 0.0f);		// front (p_jewel_door_r1)
		OBJECT::SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(1425919976, -631.9554f, -236.3333f, 38.20653f, false, 0.0f, 0.0f, 0.0f);	// front (p_jewel_door_l)
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

//FIB
void FIB()
{
	if (!iniFIB)
		return;

	//Lobby
	if (SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, 106.0f, -745.0f, 46.0f) < distance)
	{
		UnloadIPL("fiblobbyfake");
		UnloadIPL("fiblobbyfake_lod");
		LoadIPL("fiblobby");
		LoadIPL("fiblobby_lod");
		OBJECT::SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(-1517873911, 106.3793f, -742.6982f, 46.51962f, false, 0.0f, 0.0f, 0.0f);	// front (v_ilev_fibl_door02)
		OBJECT::SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(-90456267, 105.7607f, -746.646f, 46.18266f, false, 0.0f, 0.0f, 0.0f);		// front (v_ilev_fibl_door01)
		OBJECT::SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(-2051651622, 127.8489f, -760.4548f, 45.90111f, false, 0.0f, 0.0f, 0.0f);	// internal (v_ilev_fib_door1)
		//Elevator doors
		OBJECT::SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(-1225363909, 134.9403f, -762.9027f, 44.75291f, false, 0.0f, 0.0f, 0.0f);	// internal (v_ilev_fib_doore_l)
		OBJECT::SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(1219957182, 137.7594f, -763.9288f, 44.75291f, false, 0.0f, 0.0f, 0.0f);	// internal (v_ilev_fib_doore_r)
		OBJECT::SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(-1225363909, 127.8489f, -760.4548f, 45.90111f, false, 0.0f, 0.0f, 0.0f);	// internal (v_ilev_fib_doore_l)
		OBJECT::SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(1219957182, 139.1689f, -764.4418f, 44.75182f, false, 0.0f, 0.0f, 0.0f);	// internal (v_ilev_fib_doore_r)
	}
	else
	{
		UnloadIPL("fiblobby");
		UnloadIPL("fiblobby_lod");
		LoadIPL("fiblobbyfake");
		LoadIPL("fiblobbyfake_lod");
	}

	//Floors
	if (SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, 135.09f, -736.37f, 248.48f) < distance)
	{
		LoadIPL("v_fib01");
		LoadIPL("v_fib02");
		LoadIPL("v_fib03");
		LoadIPL("v_fib04");
		//Floor 47
		OBJECT::SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(-2051651622, 125.179f, -759.5534f, 234.3023f, false, 0.0f, 0.0f, 0.0f);	// internal (v_ilev_fib_door1)
		OBJECT::SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(-2051651622, 125.3935f, -757.5027f, 234.3021f, false, 0.0f, 0.0f, 0.0f);	// internal (v_ilev_fib_door1)
		OBJECT::SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(-2051651622, 117.1114f, -760.746f, 234.3022f, false, 0.0f, 0.0f, 0.0f);	// internal (v_ilev_fib_door1)
		OBJECT::SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(-2051651622, 111.8105f, -749.3636f, 234.3022f, false, 0.0f, 0.0f, 0.0f);	// internal (v_ilev_fib_door1)
		OBJECT::SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(-2051651622, 111.7746f, -748.436f, 234.3021f, false, 0.0f, 0.0f, 0.0f);	// internal (v_ilev_fib_door1)
		OBJECT::SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(-2051651622, 117.9132f, -743.9565f, 234.3021f, false, 0.0f, 0.0f, 0.0f);	// internal (v_ilev_fib_door1)

		if (missionFlag)
			return;

		//Floor 53 Security Door
		DeleteObjectAtCoords(878161517, 150.5931f, -762.3801f, 258.3018f);	// internal (prop_secdoor_01)
		Teleport(115.0094f, -741.8607f, 257.1523f, -25.0f, 160.0f, 141.0533f, -765.8549f, 44.7520f, 240, 200, 80, 150, "Press ~INPUT_ENTER~ to go to floor 53.", "Press ~INPUT_ENTER~ to return to the lobby.", false);
		Teleport(136.1618f, -761.7862f, 241.0520f, 160.0f, 160.0f, 136.1337f, -761.8162f, 44.7520f, 240, 200, 80, 150, "Press ~INPUT_ENTER~ to go to floor 49.", "Press ~INPUT_ENTER~ to return to the lobby.", false);
		Teleport(136.1340f, -761.8201f, 233.1521f, 160.0f, 160.0f, 138.9534f, -762.8441f, 44.7520f, 240, 200, 80, 150, "Press ~INPUT_ENTER~ to go to floor 47.", "Press ~INPUT_ENTER~ to return to the lobby.", false);
	}
	else
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

	if (SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, 485.0f, -1315.0f, 30.0f) < distance)
	{
		LoadIPL("v_chopshop");
		EnableInterior(INTERIOR::GET_INTERIOR_AT_COORDS(480.5f, -1319.0f, 30.0f));
		AltUnlockDoor(-664582244, 482.8112f, -1311.953f, 29.35057f);	// front (v_ilev_cs_door)
		//Replace buggy garage door with new one
		if (!OBJECT::IS_DOOR_REGISTERED_WITH_SYSTEM(-190140885))		//This is the doorHash, NOT the hash of  the object!
		{
			DeleteObjectAtCoords(-190780785, 484.5642f, -1315.574f, 30.20331f);		// prop_com_gar_door_01
			OBJECT::ADD_DOOR_TO_SYSTEM(-190140885, -190780785, 484.5642f, -1315.574f, 30.20331f, false, false, false);
			OBJECT::DOOR_SYSTEM_SET_DOOR_STATE(-190140885, 0, false, false);
		}
	}
	else
	{
		DisableInterior(INTERIOR::GET_INTERIOR_AT_COORDS(480.5f, -1319.0f, 30.0f));
		UnloadIPL("v_chopshop");
	}

	return;
}

//Tequi-la-la
void TequiLaLa()
{
	if (!iniTequiLaLa)
		return;

	if (SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, -565.0f, 277.0f, 84.0f) < distance)
	{
		LoadIPL("v_rockclub");
		EnableInterior(INTERIOR::GET_INTERIOR_AT_COORDS(-565.0f, 276.5f, 83.5f));
		OBJECT::SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(993120320, -565.1712f, 276.6259f, 83.28626f, false, 0.0f, 0.0f, 0.0f);	// front (v_ilev_roc_door4)
		OBJECT::SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(993120320, -561.2866f, 293.5044f, 87.77851f, false, 0.0f, 0.0f, 0.0f);	// rear (v_ilev_roc_door4)
	}
	else
	{
		DisableInterior(INTERIOR::GET_INTERIOR_AT_COORDS(-565.0f, 276.5f, 83.5f));
		UnloadIPL("v_rockclub");
	}

	return;
}

//Maze Bank Arena (Fame or Shame)
void FameorShame()
{
	if (!iniFameorShame)
		return;

	if (SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, -262.0f, -2021.0f, 36.0f) < distance)
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

	if (SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, -71.0f, 6266.0f, 32.0f) < distance)
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
		OBJECT::SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(-1156020871, -182.9104f, 6168.368f, 32.14053f, false, 0.0f, 0.0f, 0.0f);	// front (prop_fnclink_03gate5)
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

	if (SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, 1085.0f, -2000.0f, 35.0f) < distance)
	{
		LoadIPL("v_foundry");
		EnableInterior(INTERIOR::GET_INTERIOR_AT_COORDS(1089.5f, -1995.5f, 33.0f));
		OBJECT::SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(-1428622127, 1083.547f, -1975.435f, 31.62222f, false, 0.0f, 0.0f, 0.0f);	// front (prop_ron_door_01)
		OBJECT::SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(-1428622127, 1065.237f, -2006.079f, 32.23295f, false, 0.0f, 0.0f, 0.0f);	// rear (prop_ron_door_01)
		OBJECT::SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(-1428622127, 1085.307f, -2018.561f, 41.62894f, false, 0.0f, 0.0f, 0.0f);	// rear (prop_ron_door_01)
	}
	else
	{
		DisableInterior(INTERIOR::GET_INTERIOR_AT_COORDS(1089.5f, -1995.5f, 33.0f));
		UnloadIPL("v_foundry");
	}

	return;
}

//Epsilon Encounter Room
void EpsilonRoom()
{
	if (!iniEpsilonRoom)
		return;

	if (SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, 241.0f, 361.0f, 106.0f) < distance)
	{
		LoadIPL("v_epsilonism");
		EnableInterior(INTERIOR::GET_INTERIOR_AT_COORDS(245.5f, 370.0f, 106.3f));
		OBJECT::SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(-1230442770, 241.3621f, 361.0471f, 105.8883f, false, 0.0f, 0.0f, 0.0f);	// front (v_ilev_epsstoredoor)
	}
	else
	{
		DisableInterior(INTERIOR::GET_INTERIOR_AT_COORDS(245.5f, 370.0f, 106.3f));
		UnloadIPL("v_epsilonism");
	}

	return;
}

//Harvey Molina's Apartment (Janitor's House)
void JanitorHouse()
{
	if (!iniJanitorHouse)
		return;

	if (SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, -108.0f, -9.0f, 71.0f) < distance)
	{
		LoadIPL("v_janitor");
		OBJECT::SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(486670049, -107.5373f, -9.018099f, 70.67085f, false, 0.0f, 0.0f, 0.0f);	// front (v_ilev_janitor_frontdoor)
	}
	else
		UnloadIPL("v_janitor");

	return;
}

//O'Neil Ranch
void ONeilRanch()
{
	if (!iniONeilRanch || (iniStoryCompatibility && (STREAMING::IS_IPL_ACTIVE("farm_burnt") || STREAMING::IS_IPL_ACTIVE("des_farmhs_endimap"))))
	{
		BlipONeilRanch.enable = false;
		UnloadIPL("farmint_cap");
		UnloadIPL("farmint_cap_lod");
		return;
	}

	if (SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, 2445.0f, 4976.0f, 50.0f) < distance)
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

	if (SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, -605.0f, -1615.0f, 27.0f) < distance)
	{
		LoadIPL("v_recycle");
		EnableInterior(INTERIOR::GET_INTERIOR_AT_COORDS(-611.4f, -1615.7f, 29.2f));
		OBJECT::SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(1099436502, -608.7289f, -1610.315f, 27.15894f, false, 0.0f, 0.0f, 0.0f);	// front (v_ilev_rc_door3_l)
		OBJECT::SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(-1627599682, -611.32f, -1610.089f, 27.15894f, false, 0.0f, 0.0f, 0.0f);	// front (v_ilev_rc_door3_r)
		OBJECT::SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(1099436502, -592.9376f, -1631.577f, 27.15931f, false, 0.0f, 0.0f, 0.0f);	// rear (v_ilev_rc_door3_l)
		OBJECT::SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(-1627599682, -592.7109f, -1628.986f, 27.15931f, false, 0.0f, 0.0f, 0.0f);	// rear (v_ilev_rc_door3_r)
		DeleteObjectAtCoords(812467272, -589.5237f, -1621.55f, 33.16059f);		// internal (v_ilev_rc_door1_st)
		DeleteObjectAtCoords(812467272, -590.8198f, -1621.436f, 33.16059f);		// internal (v_ilev_rc_door1_st)
	}
	else
	{
		DisableInterior(INTERIOR::GET_INTERIOR_AT_COORDS(-611.4f, -1615.7f, 29.2f));
		UnloadIPL("v_recycle");
	}

	return;
}

//Humane Lab
void HumaneLab()
{
	if (!iniHumaneLab)
		return;

	if (SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, 3625.0f, 3750.0f, 28.0f) < distance)
	{
		LoadIPL("v_lab");
		OBJECT::SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(-1081024910, 3620.843f, 3751.527f, 27.69009f, true, 0.0f, 0.0f, -1.0f);	// front (v_ilev_bl_shutter2)
		OBJECT::SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(-1081024910, 3627.713f, 3746.716f, 27.69009f, true, 0.0f, 0.0f, -1.0f);	// front (v_ilev_bl_shutter2)
		
		if (missionFlag)
			return;

		Teleport(3540.6599f, 3675.5315f, 19.9918f, 170.0f, 170.0f, 3540.6272f, 3675.3850f, 27.1211f, 240, 200, 80, 150, "Press ~INPUT_ENTER~ to take the elevator.", "Press ~INPUT_ENTER~ to take the elevator.", false);
		//Underwater entrance at the cooling tunnels
		UnloadIPL("chemgrill_grp1");
	}
	else
		UnloadIPL("v_lab");

	return;
}

//Omega's Garage
void OmegaGarage()
{
	if (!iniOmegaGarage)
		return;

	if (SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, 2333.0f, 2575.0f, 47.0f) < distance)
	{
		OBJECT::SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(-26664553, 2333.235f, 2574.973f, 47.03088f, false, 0.0f, 0.0f, 0.0f);	// front (prop_ch3_01_trlrdoor_l)
		OBJECT::SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(914592203, 2329.655f, 2576.642f, 47.03088f, false, 0.0f, 0.0f, 0.0f);	// front (prop_ch3_01_trlrdoor_r)
	}
	return;
}

//Blaine County Savings Bank
void BlaineCountyBank()
{
	if (!iniBlaineCountyBank)
		return;

	if (SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, -110.0f, 6462.0f, 32.0f) < distance)
	{
		LoadIPL("v_bank4");
		OBJECT::SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(-1666470363, -109.65f, 6462.11f, 31.98499f, false, 0.0f, 0.0f, 0.0f);		// front (v_ilev_bank4door01)
		OBJECT::SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(-353187150, -111.48f, 6463.94f, 31.98499f, false, 0.0f, 0.0f, 0.0f);		// front  (v_ilev_bank4door02)
		OBJECT::SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(-1184592117, -108.9147f, 6469.104f, 31.91028f, false, 0.0f, 0.0f, 0.0f);	// internal (v_ilev_cbankcountdoor01)
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

	if (SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, -2073.0f, -1024.0f, 4.0f) < 250000.0f)
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

	if (SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, -228.0f, -2366.0f, 17.0f) < 250000.0f)
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
	if (!iniUnionDepository)
		return;

	if (SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, 15.0f, -690.0f, 35.0f) < distance)
	{
		LoadIPL("FINBANK");

		if (missionFlag)
			return;

		Teleport(-0.1434f, -705.9488f, 15.1312f, -25.0f, 0.0f, 10.3384f, -671.1154f, 32.4495f, 240, 200, 80, 150, "Press ~INPUT_ENTER~ to enter the UD vault.", "Press ~INPUT_ENTER~ to exit the vault.", false);
		OBJECT::SET_STATE_OF_CLOSEST_DOOR_OF_TYPE(-726591477, 11.656f, -668.4662f, 32.44926f, false, -1.0f, 0);		// internal (v_ilev_finelevdoor01)
		OBJECT::SET_STATE_OF_CLOSEST_DOOR_OF_TYPE(-726591477, 8.760172f, -668.6967f, 32.44926f, false, -1.0f, 0);	// internal (v_ilev_finelevdoor01)
		OBJECT::SET_STATE_OF_CLOSEST_DOOR_OF_TYPE(-726591477, 2.095137f, -704.072f, 15.13071f, false, -1.0f, 0);	// internal (v_ilev_finelevdoor01)
		OBJECT::SET_STATE_OF_CLOSEST_DOOR_OF_TYPE(-726591477, -0.6344414f, -703.0778f, 15.13071f, false, -1.0f, 0);	// internal (v_ilev_finelevdoor01)
		OBJECT::SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(-1932297301, -1.727947f, -686.5417f, 16.68913f, true, 0.0f, 0.0f, 1.0f);	// internal (v_ilev_fin_vaultdoor)
		OBJECT::SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(-1011692606, 8.171528f, -672.4393f, 16.35861f, true, 0.0f, 0.0f, 0.0f);	// internal (v_ilev_fingate)
		OBJECT::SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(-1011692606, -3.58445f, -668.1644f, 16.35861f, true, 0.0f, 0.0f, 0.0f);	// internal (v_ilev_fingate)
	}
	else if (!missionFlag)
		UnloadIPL("FINBANK");

	return;
}

//Union Depository Parking
void UnionDepositoryParking()
{
	if (!iniUnionDepository)
		return;

	if (SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, -16.0f, -685.00f, 34.0f) < distance)
	{
		UnloadIPL("dt1_03_shutter");
		LoadIPL("dt1_03_carpark");
		EnableInterior(INTERIOR::GET_INTERIOR_AT_COORDS(-16.0f, -685.00f, 34.0f));
	}
	else
	{
		DisableInterior(INTERIOR::GET_INTERIOR_AT_COORDS(-16.0f, -685.00f, 34.0f));
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

	if (SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, 994.0f, -2143.0f, 31.5f) < distance)
	{
		LoadIPL("v_abattoir");
		EnableInterior(INTERIOR::GET_INTERIOR_AT_COORDS(981.0f, -2186.0f, 32.1f));

		//Behaviour taken from decompiled scripts
		OBJECT::SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(1755793225, 962.0066f, -2183.816f, 31.06194f, true, 0.0f, 0.0f, 1.0f);	// front (v_ilev_abbmaindoor)
		OBJECT::SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(-1468417022, 962.9085f, -2105.813f, 34.20225f, true, 0.0f, 0.0f, 1.0f);	// rear (prop_abat_slide)
	}
	else
	{
		DisableInterior(INTERIOR::GET_INTERIOR_AT_COORDS(981.0f, -2186.0f, 32.1f));
		UnloadIPL("v_abattoir");
	}

	return;
}

//Solomon's Office
void SolomonOffice()
{
	if (!iniSolomonOffice || missionFlag)
		return;

	if (SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, -1007.14f, -478.53f, 51.57f) < distance)
	{
		LoadIPL("v_58_sol_office");
		EnableInterior(INTERIOR::GET_INTERIOR_AT_COORDS(-1007.14f, -478.53f, 51.57f));
		Teleport(-1002.9615f, -477.8428f, 49.0271f, 120.0f, 120.0f, -1011.6970f, -480.1367f, 38.9756f, 240, 200, 80, 150, "Press ~INPUT_ENTER~ to enter Solomon's office.", "Press ~INPUT_ENTER~ to exit the office.", false);
		OBJECT::SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(-2030220382, -1002.147f, -478.0642f, 50.11668f, true, 0.0f, 0.0f, 0.0f);	// internal (v_ilev_sol_off_door01)
	}
	else
	{
		DisableInterior(INTERIOR::GET_INTERIOR_AT_COORDS(-1007.14f, -478.53f, 51.57f));
		UnloadIPL("v_58_sol_office");
	}

	return;
}

//Ace Liquor (Meth lab)
void Methlab()
{
	if (iniMethlab && SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, 1393.0f, 3599.5f, 35.0f) < distance)
	{
		OBJECT::SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(-1212951353, 1392.927f, 3599.469f, 35.13078f, false, 0.0f, 0.0f, 0.0f);	// external (v_ilev_ml_door1)
		OBJECT::SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(-1212951353, 1395.371f, 3600.358f, 35.13078f, false, 0.0f, 0.0f, 0.0f);	// external (v_ilev_ml_door1)
	}
	return;
}

//Los Santos County Coroner Office (Morgue)
void Morgue()
{
	if (!iniMorgue)
		return;

	if (SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, 246.0f, -1374.0f, 32.5f) < distance)
	{
		UnloadIPL("coroner_int_off");
		LoadIPL("coroner_int_on");
		LoadIPL("coronertrash");
		EnableInterior(INTERIOR::GET_INTERIOR_AT_COORDS(275.446f, -1361.11f, 24.5378f));

		if (!missionFlag)
			Teleport(247.0606f, -1371.8202f, 23.5378f, -45.0f, 145.0f, 240.9777f, -1379.1080f, 32.7417f, 240, 200, 80, 150, "Press ~INPUT_ENTER~ to enter the LS County Morgue.", "Press ~INPUT_ENTER~ to exit the morgue.", false);
	}
	else
	{
		DisableInterior(INTERIOR::GET_INTERIOR_AT_COORDS(275.446f, -1361.11f, 24.5378f));
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

	if (SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, 1121.32f, 2642.65f, 39.17f) < distance || SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, 151.3630f, -1007.6400f, -100.0000f) < distance)
	{
		LoadIPL("v_motel_mp");
		EnableInterior(INTERIOR::GET_INTERIOR_AT_COORDS(152.2600f, -1004.4700f, -99.0000f));

		if (!missionFlag)
			Teleport(151.3630f, -1007.6400f, -100.0000f, 0.0f, 0.0f, 1121.4703f, 2641.7883f, 37.1487f, 240, 200, 80, 150, "Press ~INPUT_ENTER~ to enter the The Motor Motel.", "Press ~INPUT_ENTER~ to exit the room.", false);
	}
	return;
}

//////////////////////////////////UNUSED INTERIORS//////////////////////////////////

//Paleto Bay Sheriff's Office
void PaletoSheriffOffice()
{
	if (!iniPaletoSheriffOffice)
		return;

	if (SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, -445.0f, 6017.0f, 32.0f) < distance)
	{
		UnloadIPL("cs1_16_sheriff_cap");
		LoadIPL("v_sheriff2");
		EnableInterior(INTERIOR::GET_INTERIOR_AT_COORDS(-447.0f, 6013.5f, 32.3f));
		OBJECT::SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(-1501157055, -444.4985f, 6017.06f, 31.86633f, false, 0.0f, 0.0f, 0.0f);	// front (v_ilev_shrf2door)
		OBJECT::SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(-1501157055, -442.66f, 6015.222f, 31.86633f, false, 0.0f, 0.0f, 0.0f);	// front (v_ilev_shrf2door)
	}
	else
	{
		DisableInterior(INTERIOR::GET_INTERIOR_AT_COORDS(-447.0f, 6013.5f, 32.3f));
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

	if (SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, 1856.0f, 3684.0f, 35.0f) < distance)
	{
		UnloadIPL("sheriff_cap");
		LoadIPL("v_sheriff");
		EnableInterior(INTERIOR::GET_INTERIOR_AT_COORDS(1853.0f, 3688.0f, 35.0f));
		OBJECT::SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(-1765048490, 1855.685f, 3683.93f, 34.59282f, false, 0.0f, 0.0f, 0.0f);	// front (v_ilev_shrfdoor)
	}
	else
	{
		DisableInterior(INTERIOR::GET_INTERIOR_AT_COORDS(1853.0f, 3688.0f, 35.0f));
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

	if (SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, 447.0f, -980.0f, 31.0f) < distance)
	{
		OBJECT::SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(-1320876379, 446.5728f, -980.0104f, 30.8393f, false, 0.0f, 0.0f, 0.0f);	// internal (v_ilev_ph_gendoor002)
		OBJECT::SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(749848321, 453.0793f, -983.1894f, 30.83926f, false, 0.0f, 0.0f, 0.0f);	// internal (v_ilev_arm_secdoor)
	}
	return;
}

//North Yankton Surveillance Room
void YanktonSurveillance()
{
	if (!iniYanktonSurveillance)
		return;

	OBJECT::SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(-311575617, 5305.461f, -5177.75f, 83.66856f, false, 0.0f, 0.0f, 0.0f);	// internal (v_ilev_cd_door3)
	return;
}

//Pacific Standard Public Deposit Bank Vault
void PacificBankVault()
{
	if (!iniPacificBankVault)
		return;

	if (SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, 266.0f, 217.6f, 110.0f) < distance)
	{
		OBJECT::SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(1956494919, 266.3624f, 217.5697f, 110.4328f, false, 0.0f, 0.0f, 0.0f);	// internal (v_ilev_bk_door)
		OBJECT::SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(-1246222793, 256.3116f, 220.6579f, 106.4296f, false, 0.0f, 0.0f, 0.0f);	// internal (v_ilev_bk_gate)
		OBJECT::SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(961976194, 255.2283f, 223.976f, 102.3932f, true, 0.0f, 0.0f, -0.95f);		// internal (v_ilev_bk_vaultdoor)
	}
	return;
}

//Fleeca Banks Vaults
void FleecaBanks()
{
	if (!iniFleecaBanks)
		return;

	//Fleeca Bank - Blaine County
	if (SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, 1179.0f, 2709.0f, 38.0f) < distance)
	{
		ENTITY::SET_ENTITY_ROTATION(OBJECT::GET_CLOSEST_OBJECT_OF_TYPE(1178.87f, 2709.365f, 38.36251f, 0.3f, -131754413, false, true, true), 0.0f, 0.0f, 0.0f, 2, true);		// internal
		ENTITY::SET_ENTITY_ROTATION(OBJECT::GET_CLOSEST_OBJECT_OF_TYPE(1175.542f, 2710.861f, 38.22689f, 0.3f, 2121050683, false, true, true), 0.0f, 0.0f, 0.0f, 2, true);		// internal
	}

	//Fleeca Bank - Los Santos County
	if (SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, -2960.0f, 479.0f, 16.0f) < distance)
	{
		ENTITY::SET_ENTITY_ROTATION(OBJECT::GET_CLOSEST_OBJECT_OF_TYPE(-2960.176f, 479.0105f, 15.97156f, 0.3f, -131754413, false, true, true), 0.0f, 0.0f, -90.0f, 2, true);	// internal
		ENTITY::SET_ENTITY_ROTATION(OBJECT::GET_CLOSEST_OBJECT_OF_TYPE(-2958.538f, 482.2705f, 15.83594f, 0.3f, 2121050683, false, true, true), 0.0f, 0.0f, -90.0f, 2, true);	// internal
	}

	//Fleeca Bank - Burton
	if (SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, 310.0f, -280.0f, 54.0f) < distance)
	{
		ENTITY::SET_ENTITY_ROTATION(OBJECT::GET_CLOSEST_OBJECT_OF_TYPE(309.7491f, -280.1797f, 54.43926, 0.3f, -131754413, false, true, true), 0.0f, 0.0f, 160.0f, 2, true);		// internal
		ENTITY::SET_ENTITY_ROTATION(OBJECT::GET_CLOSEST_OBJECT_OF_TYPE(312.358f, -282.7301f, 54.30365, 0.3f, 2121050683, false, true, true), 0.0f, 0.0f, 160.0f, 2, true);		// internal
	}

	//Fleeca Bank - Alta
	if (SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, -355.0f, -51.0f, 49.0f) < distance)
	{
		ENTITY::SET_ENTITY_ROTATION(OBJECT::GET_CLOSEST_OBJECT_OF_TYPE(-355.3892f, -51.06768f, 49.31105f, 0.3f, -131754413, false, true, true), 0.0f, 0.0f, 160.0f, 2, true);	// internal
		ENTITY::SET_ENTITY_ROTATION(OBJECT::GET_CLOSEST_OBJECT_OF_TYPE(-352.7365f, -53.57248f, 49.17543f, 0.3f, 2121050683, false, true, true), 0.0f, 0.0f, 160.0f, 2, true);	// internal
	}

	//Fleeca Bank - Rockford Hills
	if (SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, -1215.0f, -335.0f, 38.0f) < distance)
	{
		ENTITY::SET_ENTITY_ROTATION(OBJECT::GET_CLOSEST_OBJECT_OF_TYPE(-1214.906f, -334.7281f, 38.05551f, 0.3f, -131754413, false, true, true), 0.0f, 0.0f, -150.0f, 2, true);	// internal
		ENTITY::SET_ENTITY_ROTATION(OBJECT::GET_CLOSEST_OBJECT_OF_TYPE(-1211.261f, -334.5596f, 37.91989f, 0.3f, 2121050683, false, true, true), 0.0f, 0.0f, -150.0f, 2, true);	// internal
	}

	//Fleeca Bank - Pillbox Hill
	if (SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, 145.6f, -1042.0f, 30.0f) < distance)
	{
		ENTITY::SET_ENTITY_ROTATION(OBJECT::GET_CLOSEST_OBJECT_OF_TYPE(145.4186f, -1041.813f, 29.64255f, 0.3f, -131754413, false, true, true), 0.0f, 0.0f, 160.0f, 2, true);	// internal
		ENTITY::SET_ENTITY_ROTATION(OBJECT::GET_CLOSEST_OBJECT_OF_TYPE(148.0266f, -1044.364f, 29.50693f, 0.3f, 2121050683, false, true, true), 0.0f, 0.0f, 160.0f, 2, true);	// internal
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
	if (SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, 492.0f, -3116.0f, 5.0f) < distance)
	{
		OBJECT::SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(1286392437, 492.2758f, -3115.934f, 5.162354f, false, 0.0f, 0.0f, 0.0f);	// internal (prop_gate_docks_ld)
		OBJECT::SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(1286392437, 476.3276f, -3115.925f, 5.162354f, false, 0.0f, 0.0f, 0.0f);	// internal (prop_gate_docks_ld)
	}

	//Vanilla Unicorn Back Door
	OBJECT::SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(668467214, 96.09197f, -1284.854f, 29.43878f, false, 0.0f, 0.0f, 0.0f);		// internal (prop_magenta_door)

	//Pier 400 Gates
	if (SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, -150.0f, -2570.0f, 5.0f) < distance)
	{
		OBJECT::SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(1286392437, 19.4045f, -2529.702f, 5.047173f, false, 0.0f, 0.0f, 0.0f);	// external (prop_gate_docks_ld)
		OBJECT::SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(1286392437, 10.64414f, -2542.213f, 5.047173f, false, 0.0f, 0.0f, 0.0f);	// external (prop_gate_docks_ld)
		OBJECT::SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(1286392437, -202.6151f, -2515.309f, 5.047173f, false, 0.0f, 0.0f, 0.0f);	// external (prop_gate_docks_ld)
		OBJECT::SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(1286392437, -187.3406f, -2515.309f, 5.047173f, false, 0.0f, 0.0f, 0.0f);	// external (prop_gate_docks_ld)
		SetDoorUnlockDistanceWithRate(569833973, -160.8777f, -2636.198f, 5.025181f, 1.0f, 15.15f);	// external (prop_facgate_01)
		SetDoorUnlockDistanceWithRate(569833973, -148.7143f, -2636.198f, 5.032078f, 1.0f, 15.15f);	// external (prop_facgate_01)
	}

	//Garage Near Union Depository
	if (SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, -33.80561f, -621.6387f, 36.06102f) < distance)
		AltUnlockDoor(-190780785, -33.80561f, -621.6387f, 36.06102f);	// front (prop_com_gar_door_01)

	//Garage in front of "Alpha Mail Couriers"
	if (SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, 1204.555f, -3110.386f, 6.557831f) < distance)
		OBJECT::SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(-190780785, 1204.555f, -3110.386f, 6.557831f, false, 0.0f, 0.0f, 0.0f);	// external (prop_com_gar_door_01)

	//Impound Lot  (Mission Row)
	if (SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, 431.0f, -1001.0f, 27.0f) < distance)
	{
		OBJECT::SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(-190780785, 431.4056f, -1001.169f, 26.71261f, false, 0.0f, 0.0f, 0.0f);	// external (prop_com_gar_door_01)
		OBJECT::SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(-190780785, 436.2234f, -1001.169f, 26.71261f, false, 0.0f, 0.0f, 0.0f);	// external (prop_com_gar_door_01)
	}

	//Vinewood Hills Garage
	if (SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, -689.1114f, 506.9815f, 110.6122f) < distance)
		OBJECT::SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(913904359, -689.1114f, 506.9815f, 110.6122f, false, 0.0f, 0.0f, 0.0f);	// external (prop_ch2_09c_garage_door)

	//Stab City Trailer
	if (SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, 29.0f, 3661.5f, 41.0f) < distance)
	{
		OBJECT::SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(668467214, 29.10205f, 3661.489f, 40.85468f, false, 0.0f, 0.0f, 0.0f);		// external (prop_magenta_door)
		OBJECT::SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(1342464176, 31.91804f, 3666.854f, 40.85857f, false, 0.0f, 0.0f, 0.0f);	// external (prop_cs4_05_tdoor)
	}

	//Vagos doors near the beach
	if (SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, -1100.0f, -1638.5f, 5.0f) < distance)
	{
		OBJECT::SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(-502195954, -1104.657f, -1638.481f, 4.675404f, false, 0.0f, 0.0f, 0.0f);		// external (prop_map_door_01)
		//Repossession Garages Fix
		if (!missionFlag)
		{
			OBJECT::SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(-2029892494, -1127.104f, -1586.979f, 5.092136f, false, 0.0f, 0.0f, 0.0f);	// external (prop_arm_gate_l)
			OBJECT::SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(-2029892494, -1131.989f, -1590.397f, 5.092136f, false, 0.0f, 0.0f, 0.0f);	// external (prop_arm_gate_l)
			OBJECT::SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(-1652821467, -1067.011f, -1665.597f, 4.789768f, false, 0.0f, 0.0f, 0.0f);	// external (prop_gar_door_01)
			OBJECT::SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(1013329911, -1064.759f, -1668.76f, 4.789768f, false, 0.0f, 0.0f, 0.0f);	// external (prop_gar_door_02)
		}
	}

	//LSPD Auto Impound Gate
	if (SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, 375.9481f, -1632.531f, 27.24899f) < distance)
		DeleteObjectAtCoords(-577103870, 375.9481f, -1632.531f, 27.24899f);	// external (prop_sec_gate_01c)

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
	if (iniMichaelHouse && PED::GET_PED_TYPE(PLAYER::PLAYER_PED_ID()) != 0)
	{
		SetDoorUnlockDistanceWithRate(-2125423493, -844.051f, 155.9619f, 66.03221f, 1.0f, 15.15f);
	}

	//Vangelico Jewelry Store doors
	if (iniVangelico && !(iniStoryCompatibility && STREAMING::IS_IPL_ACTIVE("bh1_16_refurb")) && SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, -630.0f, -238.0f, 38.0f) < distance)
	{
		OBJECT::SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(9467943, -630.4265f, -238.4375f, 38.20653f, false, 0.0f, 0.0f, 0.0f);
		OBJECT::SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(1425919976, -631.9554f, -236.3333f, 38.20653f, false, 0.0f, 0.0f, 0.0f);
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
	if (iniChopshop && SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, 485.0f, -1315.0f, 30.0f) < distance)
	{
		AltUnlockDoor(-664582244, 482.8112f, -1311.953f, 29.35057f);
		if (!OBJECT::IS_DOOR_REGISTERED_WITH_SYSTEM(-190140885))
		{
			DeleteObjectAtCoords(-190780785, 484.5642f, -1315.574f, 30.20331f);
			OBJECT::ADD_DOOR_TO_SYSTEM(-190140885, -190780785, 484.5642f, -1315.574f, 30.20331f, false, false, false);
			OBJECT::DOOR_SYSTEM_SET_DOOR_STATE(-190140885, 0, false, false);
		}
	}

	//Foundry
	if (iniFoundry && SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, 1085.0f, -2000.0f, 35.0f) < distance)
	{
		OBJECT::SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(-1428622127, 1083.547f, -1975.435f, 31.62222f, false, 0.0f, 0.0f, 0.0f);
		OBJECT::SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(-1428622127, 1065.237f, -2006.079f, 32.23295f, false, 0.0f, 0.0f, 0.0f);
		OBJECT::SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(-1428622127, 1085.307f, -2018.561f, 41.62894f, false, 0.0f, 0.0f, 0.0f);
	}

	//Scrapyard
	if (iniScrapyard && SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, -605.0f, -1615.0f, 27.0f) < distance)
	{
		OBJECT::SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(1099436502, -608.7289f, -1610.315f, 27.15894f, false, 0.0f, 0.0f, 0.0f);
		OBJECT::SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(-1627599682, -611.32f, -1610.089f, 27.15894f, false, 0.0f, 0.0f, 0.0f);
		OBJECT::SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(1099436502, -592.9376f, -1631.577f, 27.15931f, false, 0.0f, 0.0f, 0.0f);
		OBJECT::SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(-1627599682, -592.7109f, -1628.986f, 27.15931f, false, 0.0f, 0.0f, 0.0f);
	}

	//Humane Lab
	if (iniHumaneLab && !missionFlag)
		Teleport(3540.6599f, 3675.5315f, 19.9918f, 170.0f, 170.0f, 3540.6272f, 3675.3850f, 27.1211f, 240, 200, 80, 150, "Press ~INPUT_ENTER~ to take the elevator.", "Press ~INPUT_ENTER~ to take the elevator.", false);

	//Omega's Garage
	if (iniOmegaGarage && SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, 2333.0f, 2575.0f, 47.0f) < distance)
	{
		OBJECT::SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(-26664553, 2333.235f, 2574.973f, 47.03088f, false, 0.0f, 0.0f, 0.0f);
		OBJECT::SET_LOCKED_UNSTREAMED_IN_DOOR_OF_TYPE(914592203, 2329.655f, 2576.642f, 47.03088f, false, 0.0f, 0.0f, 0.0f);
	}

	//Union Depository Vault Doors
	if (iniUnionDepository && !missionFlag && SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, 15.0f, -690.0f, 35.0f) < distance)
	{
		Teleport(-0.1434f, -705.9488f, 15.1312f, -25.0f, 0.0f, 10.3384f, -671.1154f, 32.4495f, 240, 200, 80, 150, "Press ~INPUT_ENTER~ to enter the UD vault.", "Press ~INPUT_ENTER~ to exit the vault.", false);
		OBJECT::SET_STATE_OF_CLOSEST_DOOR_OF_TYPE(-726591477, 11.656f, -668.4662f, 32.44926f, false, -1.0f, 0);
		OBJECT::SET_STATE_OF_CLOSEST_DOOR_OF_TYPE(-726591477, 8.760172f, -668.6967f, 32.44926f, false, -1.0f, 0);
		OBJECT::SET_STATE_OF_CLOSEST_DOOR_OF_TYPE(-726591477, 2.095137f, -704.072f, 15.13071f, false, -1.0f, 0);
		OBJECT::SET_STATE_OF_CLOSEST_DOOR_OF_TYPE(-726591477, -0.6344414f, -703.0778f, 15.13071f, false, -1.0f, 0);
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

	return;
}
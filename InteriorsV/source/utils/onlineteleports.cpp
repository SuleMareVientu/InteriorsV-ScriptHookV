//ScriptHook
#include <natives.h>
// #include <types.h> //Already included in globals.h
//Custom
#include "functions.h"
#include "../globals.h"
#include "onlineteleports.h"

bool isInsideApartment = false;

//Yellow HUD Color
static const int R = 240;
static const int G = 200;
static const int B = 80;
static const int A = 150;

//Default Text
static char* enterMsg = "Press ~INPUT_ENTER~ to enter the apartment.";
static char* exitMsg = "Press ~INPUT_ENTER~ to exit the apartment.";

//Low End Apartment Coords
static const float xLow = 265.1470f;
static const float yLow = -1002.541f;
static const float zLow = -100.0087f;
static const float lowHeading = 0.0f;

//Medium End Apartment Coords
static const float xMedium = 346.4946f;
static const float yMedium = -1003.893f;
static const float zMedium = -100.1962f;
static const float MediumHeading = 0.0f;

static void LowEndApartments()
{
	if (
		Teleport(xLow, yLow, zLow, lowHeading, -150.0f, 1900.1719f, 3772.9207f, 31.8744f, R, G, B, A, enterMsg, exitMsg, true)	||	//140 Zancudo Avenue
		Teleport(xLow, yLow, zLow, lowHeading, -80.0f, 1662.7830f, 4776.2407f, 41.0076f, R, G, B, A, enterMsg, exitMsg, true)	||	//1893 Grapeseed Avenue
		Teleport(xLow, yLow, zLow, lowHeading, 80.0f, -42.0982f, -58.3112f, 62.4603f, R, G, B, A, enterMsg, exitMsg, true)		||	//2143 Las Lagunas Boulevard, Apt 9
		Teleport(xLow, yLow, zLow, lowHeading, 45.0f, -1533.477f, -326.7305f, 46.9113f, R, G, B, A, enterMsg, exitMsg, true)	||	//0069 Cougar Avenue, Apt 19
		Teleport(xLow, yLow, zLow, lowHeading, -130.0f, -1564.138f, -406.5406f, 41.3890f, R, G, B, A, enterMsg, exitMsg, true)	||	//1237 Prosperity Street, Apt 21
		Teleport(xLow, yLow, zLow, lowHeading, 90.0f, -201.4327f, 186.2523f, 79.3276f, R, G, B, A, enterMsg, exitMsg, true)		||	//1561 San Vitas Street, Apt 2
		Teleport(xLow, yLow, zLow, lowHeading, 50.0f, -1606.642f, -432.2548f, 39.4367f, R, G, B, A, enterMsg, exitMsg, true)	||	//1115 Boulevard Del Perro, Apt 18
		Teleport(xLow, yLow, zLow, lowHeading, 0.0f, -662.4279f, -853.6377f, 23.4586f, R, G, B, A, enterMsg, exitMsg, true)		||	//2057 Vespucci Boulevard, Apt 1
		Teleport(xLow, yLow, zLow, lowHeading, 130.0f, -813.2224f, -980.9390f, 13.1482f, R, G, B, A, enterMsg, exitMsg, true)		//0112 South Rockford Drive, Apt 13
		)
	{
		int interior = INTERIOR::GET_INTERIOR_AT_COORDS(261.4586f, -998.8196f, -99.00863f);
		EnableInterior(interior);
		EnableInteriorProp(interior, "Studio_Lo_Strip_C", false);
		EnableInteriorProp(interior, "Studio_Lo_Booze_A", false);
		EnableInteriorProp(interior, "Studio_Lo_Smoke_A", true);
	}
	return;
}

static void MediumEndApartments()
{
	if (
		Teleport(xMedium, yMedium, zMedium, MediumHeading, 90.0f, -1406.0433f, 526.8655f, 122.8362f, R, G, B, A, enterMsg, exitMsg, true)	||	//4 Hangman Ave
		Teleport(xMedium, yMedium, zMedium, MediumHeading, 40.0f, -302.4685f, 6327.2275f, 31.8920f, R, G, B, A, enterMsg, exitMsg, true)	||	//4401 Procopio Drive
		Teleport(xMedium, yMedium, zMedium, MediumHeading, -50.0f, -105.3389f, 6528.8530f, 29.1719f, R, G, B, A, enterMsg, exitMsg, true)	||	//4584 Procopio Drive
		Teleport(xMedium, yMedium, zMedium, MediumHeading, 100.0f, -969.9915f, -1431.375f, 6.6792f, R, G, B, A, enterMsg, exitMsg, true)	||	//0115 Bay City Avenue, Apt 45
		Teleport(xMedium, yMedium, zMedium, MediumHeading, 10.0f, -511.7271f, 108.5600f, 62.8006f, R, G, B, A, enterMsg, exitMsg, true)		||	//0184 Milton Road, Apt 13
		Teleport(xMedium, yMedium, zMedium, MediumHeading, -150.0f, 1342.2675f, -1578.931f, 53.0533f, R, G, B, A, enterMsg, exitMsg, true)	||	//12 Sustancia Road
		Teleport(xMedium, yMedium, zMedium, MediumHeading, 90.0f, -628.2673f, 169.7025f, 60.1525f, R, G, B, A, enterMsg, exitMsg, true)		||	//0504 South Mo Milton Drive
		Teleport(xMedium, yMedium, zMedium, MediumHeading, 0.0f, -831.4262f, -862.1733f, 19.6947f, R, G, B, A, enterMsg, exitMsg, true)		||	//0325 South Rockford Drive
		Teleport(xMedium, yMedium, zMedium, MediumHeading, -90.0f, -762.9729f, -753.7900f, 26.8736f, R, G, B, A, enterMsg, exitMsg, true)	||	//Dream Tower, Apt 15
		Teleport(xMedium, yMedium, zMedium, MediumHeading, 60.0f, 285.6400f, -160.2583f, 63.6221f, R, G, B, A, enterMsg, exitMsg, true)		||	//1162 Power Street, Apt 3
		Teleport(xMedium, yMedium, zMedium, MediumHeading, 170.0f, 3.3769f, 36.5695f, 70.5354f, R, G, B, A, enterMsg, exitMsg, true)		||	//0605 Spanish Avenue, Apt 1
		Teleport(xMedium, yMedium, zMedium, MediumHeading, -25.0f, 9.6973f, 81.8959f, 77.4352f, R, G, B, A, enterMsg, exitMsg, true)		||	//0604 Las Lagunas Boulevard, Apt 4
		Teleport(xMedium, yMedium, zMedium, MediumHeading, -5.0f, -197.6927f, 86.0134f, 68.7562f, R, G, B, A, enterMsg, exitMsg, true)			//The Royale, Apt 19
		)
	{
		int interior = INTERIOR::GET_INTERIOR_AT_COORDS(347.2686f, -999.2955f, -99.19622f);
		EnableInterior(interior);
		EnableInteriorProp(interior, "Apart_Mid_Strip_C", false);
		EnableInteriorProp(interior, "Apart_Mid_Booze_A", false);
		EnableInteriorProp(interior, "Apart_Mid_Smoke_A", true);
	}
	return;
}

static void EnableHighEndApartment(float x, float y, float z)
{
	int interior = INTERIOR::GET_INTERIOR_AT_COORDS(x, y, z);
	EnableInterior(interior);
	EnableInteriorProp(interior, "Apart_Hi_Strip_A", false);
	EnableInteriorProp(interior, "Apart_Hi_Booze_A", false);
	EnableInteriorProp(interior, "Apart_Hi_Smokes_A", true);
	return;
}

static void HighEndApartments()
{
	//Eclipse Towers, Apt 31
	Teleport(-774.1730f, 333.5828f, 206.6216f, 0.0f, 180.0f, -777.3174f, 312.8665f, 84.6982f, R, G, B, A, "Press ~INPUT_ENTER~ to enter apartment 31.", exitMsg, false);
	
	//Eclipse Towers, Apt 40
	Teleport(-781.9239f, 323.6453, 222.2577, -180.0f, 180.0f, -775.0563f, 312.8823f, 84.6982f, R, G, B, A, "Press ~INPUT_ENTER~ to enter apartment 40.", exitMsg, false);
	
	//Eclipse Towers, Apt 5
	Teleport(-774.6435f, 334.0733f, 159.0025f, 0.0f, 180.0f, -772.7392f, 312.8988f, 84.6982f, R, G, B, A, "Press ~INPUT_ENTER~ to enter apartment 5.", exitMsg, false);
		
	//Eclipse Towers, Apt 9
	Teleport(-781.8421f, 323.5967f, 175.7937f, -180.0f, 180.0f, -770.5235f, 312.8487f, 84.6982f, R, G, B, A, "Press ~INPUT_ENTER~ to enter apartment 9.", exitMsg, false);

	//Weazel Plaza, Apt 101
	Teleport(-906.4988f, -455.8776f, 125.5245f, -150.0f, 115.0f, -916.5256f, -450.6372f, 38.5999f, R, G, B, A, "Press ~INPUT_ENTER~ to enter apartment 101.", exitMsg, false);

	//Weazel Plaza, Apt 70
	Teleport(-891.8675f, -434.3725f, 120.6071f, 25.0f, 115.0f, -915.3770f, -452.9363f, 38.5999f, R, G, B, A, "Press ~INPUT_ENTER~ to enter apartment 70.", exitMsg, false);

	//Weazel Plaza, Apt 26
	Teleport(-888.4596f, -451.6940f, 94.4611f, -70.0f, 115.0f, -914.2271f, -455.1444f, 38.5999f, R, G, B, A, "Press ~INPUT_ENTER~ to enter apartment 26.", exitMsg, false);

	//Tinsel Towers, Apt 29
	Teleport(-604.9368f, 48.5689f, 92.6262f, 180.0f, -180.0f, -616.9627f, 37.4050f, 42.5870f, R, G, B, A, "Press ~INPUT_ENTER~ to enter apartment 29.", exitMsg, false);

	//Tinsel Towers, Apt 45
	Teleport(-596.4171f, 58.8616f, 107.0271f, 0.0f, -180.0f, -619.2788f, 37.3939f, 42.5871f, R, G, B, A, "Press ~INPUT_ENTER~ to enter apartment 45.", exitMsg, false);

	//Richards Majestic, Apt 51
	Teleport(-908.3109f, -370.2491f, 108.4403f, 35.0f, 115.0f, -937.5001f, -376.2820f, 37.9613f, R, G, B, A, "Press ~INPUT_ENTER~ to enter apartment 51.", exitMsg, false);

	//Richards Majestic, Apt. 4
	Teleport(-921.7794f, -380.9352f, 84.4805f, -150.0f, 115.0f, -934.8232f, -381.5349f, 37.9613f, R, G, B, A, "Press ~INPUT_ENTER~ to enter apartment 4.", exitMsg, false);

	//4 Integrity Way, Apt. 35
	Teleport(-22.9808f, -608.2526f, 99.2329f, -110.0f, 70.0f, -47.0121f, -584.5853f, 36.9580f, R, G, B, A, "Press ~INPUT_ENTER~ to enter apartment 35.", exitMsg, false);

	//4 Integrity Way, Apt. 30
	Teleport(-17.5179f, -588.9467f, 89.1149f, -25.0f, 70.0f, -47.9679f, -587.2177f, 36.9580f, R, G, B, A, "Press ~INPUT_ENTER~ to enter apartment 30.", exitMsg, false);

	//3 Alta Street Tower, Apt 57
	Teleport(-272.4795f, -940.1398f, 91.5109f, 70.0f, -170.0f, -262.5153f, -971.1097f, 30.2198f, R, G, B, A, "Press ~INPUT_ENTER~ to enter apartment 57.", exitMsg, false);

	//3 Alta Street Tower, Apt 10
	Teleport(-270.7699f, -968.1721f, 76.2314f, -110.0f, -145.0f, -260.8047f, -970.3950f, 30.2200f, R, G, B, A, "Press ~INPUT_ENTER~ to enter apartment 10.", exitMsg, false);

	//Del Perro Heights, Apt 20
	Teleport(-1451.538f, -523.6300f, 68.5566f, 40.0f, -150.0f, -1443.0387f, -545.7762f, 33.7418f, R, G, B, A, "Press ~INPUT_ENTER~ to enter apartment 20.", exitMsg, false);

	//Del Perro Heights, Apt 7
	Teleport(-1451.538f, -523.6300f, 55.9290f, 40.0f, -150.0f, -1442.0504f, -545.0800f, 33.7418f, R, G, B, A, "Press ~INPUT_ENTER~ to enter apartment 7.", exitMsg, false);
	
	return;
}

void HighEndApartmentsCulling()
{
	//Model culling works only for SPmap, this is NOT made for the MPmap
	//Original model names can be found inside am_mp_property_int.c
	
	int currentInterior = INTERIOR::GET_INTERIOR_AT_COORDS(playerLoc.x, playerLoc.y, playerLoc.z);
	if (!isInsideApartment || currentInterior == 0)
	{
		isInsideApartment = false;

		//Eclipse Towers Apartments
		if (SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, -777.3174f, 312.8665f, 84.6982f) < distance)
		{
			DisableInterior(INTERIOR::GET_INTERIOR_AT_COORDS(-797.5f, 335.31f, 207.29f));
			DisableInterior(INTERIOR::GET_INTERIOR_AT_COORDS(-755.5f, 318.52f, 222.61f));
			DisableInterior(INTERIOR::GET_INTERIOR_AT_COORDS(-801.29f, 336.86f, 159.42f));
			DisableInterior(INTERIOR::GET_INTERIOR_AT_COORDS(-758.99f, 319.74f, 175.97f));
		}

		//Weazel Plaza Apartments
		if (SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, -916.5256f, -450.6372f, 38.5999f) < distance)
		{
			DisableInterior(INTERIOR::GET_INTERIOR_AT_COORDS(-889.31f, -450.9f, 126.21f));
			DisableInterior(INTERIOR::GET_INTERIOR_AT_COORDS(-906.66f, -439.15f, 121.21f));
			DisableInterior(INTERIOR::GET_INTERIOR_AT_COORDS(-891.68f, -434.44f, 95.98f));
		}

		//Tinsel Towers Apartments
		if (SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, -616.9627f, 37.4050f, 42.5870f) < distance)
		{
			DisableInterior(INTERIOR::GET_INTERIOR_AT_COORDS(-586.9371f, 46.5519f, 92.2204f));
			DisableInterior(INTERIOR::GET_INTERIOR_AT_COORDS(-617.6090f, 63.0240f, 106.6243f));
		}

		//Richards Majestic
		if (SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, -937.5001f, -376.2820f, 37.9613f) < distance)
		{
			DisableInterior(INTERIOR::GET_INTERIOR_AT_COORDS(-929.0226f, -379.9931f, 108.03774f));
			DisableInterior(INTERIOR::GET_INTERIOR_AT_COORDS(-905.5511f, -375.1243f, 84.0079f));
		}

		//4 Integrity Way Apartments
		if (SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, -47.9679f, -587.2177f, 36.9580f) < distance)
		{
			DisableInterior(INTERIOR::GET_INTERIOR_AT_COORDS(-15.0248f, -590.8832f, 98.8302f));
			DisableInterior(INTERIOR::GET_INTERIOR_AT_COORDS(-36.1545f, -581.2134f, 88.7091f));
		}

		//3 Alta Street Tower Apartments
		if (SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, -262.5153f, -971.1097f, 30.2198f) < distance)
		{
			DisableInterior(INTERIOR::GET_INTERIOR_AT_COORDS(-272.4795f, -940.1398f, 91.5109f));
			DisableInterior(INTERIOR::GET_INTERIOR_AT_COORDS(-270.7699f, -968.1721f, 76.2314f));
		}

		//Del Perro Heights Apartments
		if (SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, -1442.0504f, -545.0800f, 33.7418f) < distance)
		{
			DisableInterior(INTERIOR::GET_INTERIOR_AT_COORDS(-1451.538f, -523.6300f, 68.5566f));
			DisableInterior(INTERIOR::GET_INTERIOR_AT_COORDS(-1451.538f, -523.6300f, 55.9290f));
		}
		return;
	}

	char* pedScenario = "PROP_HUMAN_SEAT_CHAIR";

	//Eclipse Towers Apartments culling
	if (SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, -777.3174f, 312.8665f, 84.6982f) < distance &&
		(currentInterior == INTERIOR::GET_INTERIOR_AT_COORDS(-797.5f, 335.31f, 207.29f) ||	//Eclipse Towers, Apt 31
		currentInterior == INTERIOR::GET_INTERIOR_AT_COORDS(-755.5f, 318.52f, 222.61f)	||	//Eclipse Towers, Apt 40
		currentInterior == INTERIOR::GET_INTERIOR_AT_COORDS(-801.29f, 336.86f, 159.42f) ||	//Eclipse Towers, Apt 5
		currentInterior == INTERIOR::GET_INTERIOR_AT_COORDS(-758.99f, 319.74f, 175.97f))	//Eclipse Towers, Apt 9
		)
	{
		EnableHighEndApartment(-797.5f, 335.31f, 207.29f);
		EnableHighEndApartment(-755.5f, 318.52f, 222.61f);
		EnableHighEndApartment(-801.29f, 336.86f, 159.42f);
		EnableHighEndApartment(-758.99f, 319.74f, 175.97f);
		INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(1590383694);	//ss1_11_flats
		INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(-1799920002);	//ss1_11_ss1_emissive_a
		INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(651180941);		//ss1_11_detail01b
		INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(-1862254987);	//ss1_11_Flats_LOD
		INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(738827591);		//SS1_02_Building01_LOD
		INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(287959306);		//SS1_LOD_01_02_08_09_10_11
		INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(2064708988);	//SS1_02_SLOD1
		GRAPHICS::DISABLE_OCCLUSION_THIS_FRAME();
		DeleteScenarioPedAtCoords(-785.2530f, 334.0298f, 200.9106f, pedScenario);
		DeleteScenarioPedAtCoords(-770.8542f, 323.2263f, 216.5474f, pedScenario);
		DeleteScenarioPedAtCoords(-785.7202f, 334.4220f, 153.2912f, pedScenario);
		DeleteScenarioPedAtCoords(-770.7636f, 323.2263f, 170.0934f, pedScenario);
	}

	//Weazel Plaza Apartments culling
	if (SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, -916.5256f, -450.6372f, 38.5999f) < distance &&
		(currentInterior == INTERIOR::GET_INTERIOR_AT_COORDS(-889.31f, -450.9f, 126.21f) ||	//Weazel Plaza, Apt 101
		currentInterior == INTERIOR::GET_INTERIOR_AT_COORDS(-906.66f, -439.15f, 121.21f) ||	//Weazel Plaza, Apt 70
		currentInterior == INTERIOR::GET_INTERIOR_AT_COORDS(-891.68f, -434.44f, 95.98f))	//Weazel Plaza, Apt 26
		)
	{
		EnableHighEndApartment(-889.31f, -450.9f, 126.21f);
		EnableHighEndApartment(-906.66f, -439.15f, 121.21f);
		EnableHighEndApartment(-891.68f, -434.44f, 95.98f);
		INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(1359069635);	//bh1_09_bld_01
		INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(41930611);		//bh1_09_ema
		INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(-200410159);	//prop_wall_light_12a
		GRAPHICS::DISABLE_OCCLUSION_THIS_FRAME();
		DeleteScenarioPedAtCoords(-896.5284f, -450.9871f, 119.8241f, pedScenario);
		DeleteScenarioPedAtCoords(-901.8891f, -439.0873f, 114.8968f, pedScenario);
		DeleteScenarioPedAtCoords(-893.1642f, -441.6309f, 88.7508f, pedScenario);
	}

	//Tinsel Towers Apartments culling
	if (SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, -616.9627f, 37.4050f, 42.5870f) < distance &&
		(currentInterior == INTERIOR::GET_INTERIOR_AT_COORDS(-586.9371f, 46.5519f, 92.2204f) ||	//Tinsel Towers, Apt 29
		currentInterior == INTERIOR::GET_INTERIOR_AT_COORDS(-617.6090f, 63.0240f, 106.6243f))	//Tinsel Towers, Apt 45
		)
	{
		EnableHighEndApartment(-586.9371f, 46.5519f, 92.2204f);
		EnableHighEndApartment(-617.6090f, 63.0240f, 106.6243f);
		INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(-1426709080);	//ss1_02_building01
		INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(253211729);		//SS1_Emissive_SS1_02a_LOD
		INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(-500045280);	//ss1_02_ss1_emissive_ss1_02
		GRAPHICS::DISABLE_OCCLUSION_THIS_FRAME();
		DeleteScenarioPedAtCoords(-607.4993f, 59.0075f, 101.3167f, pedScenario);
		DeleteScenarioPedAtCoords(-593.8669f, 48.3100f, 86.9158f, pedScenario);
	}

	//Richards Majestic Apartments culling
	if (SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, -937.5001f, -376.2820f, 37.9613f) < distance &&
		(currentInterior == INTERIOR::GET_INTERIOR_AT_COORDS(-929.0226f, -379.9931f, 108.03774f) ||	//Richards Majestic, Apt 51
		currentInterior == INTERIOR::GET_INTERIOR_AT_COORDS(-905.5511f, -375.1243f, 84.0079f))		//Richards Majestic, Apt. 4
		)
	{
		EnableHighEndApartment(-929.0226f, -379.9931f, 108.03774f);
		EnableHighEndApartment(-905.5511f, -375.1243f, 84.0079f);
		INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(-952859393);	//bh1_08_bld2
		INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(935186440);		//bh1_emissive_bh1_08
		INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(1828238070);	//bh1_08_bld2_LOD
		INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(-603554352);	//bh1_08_em
		GRAPHICS::DISABLE_OCCLUSION_THIS_FRAME();
		DeleteScenarioPedAtCoords(-918.3259f, -375.0222f, 102.7300f, pedScenario);
		DeleteScenarioPedAtCoords(-911.7831f, -376.1330f, 78.7702f, pedScenario);
	}

	//4 Integrity Way Apartments culling
	if (SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, -47.9679f, -587.2177f, 36.9580f) < distance &&
		(currentInterior == INTERIOR::GET_INTERIOR_AT_COORDS(-15.0248f, -590.8832f, 98.8302f) ||	//4 Integrity Way, Apt. 35
		currentInterior == INTERIOR::GET_INTERIOR_AT_COORDS(-36.1545f, -581.2134f, 88.7091f))		//4 Integrity Way, Apt. 30
		)
	{
		EnableHighEndApartment(-15.0248f, -590.8832f, 98.8302f);
		EnableHighEndApartment(-36.1545f, -581.2134f, 88.7091f);
		INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(-180177302);	//dt1_03_build1x
		INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(-1825769292);	//DT1_Emissive_DT1_03_b1
		INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(-285026450);	//dt1_03_dt1_Emissive_b1
		GRAPHICS::DISABLE_OCCLUSION_THIS_FRAME();
		DeleteScenarioPedAtCoords(-18.9438f, -597.9114f, 93.5225f, pedScenario);
		DeleteScenarioPedAtCoords(-27.8779f, -584.8820f, 83.4045f, pedScenario);
	}

	//3 Alta Street Tower Apartments culling
	if (SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, -262.5153f, -971.1097f, 30.2198f) < distance &&
		(currentInterior == INTERIOR::GET_INTERIOR_AT_COORDS(-272.4795f, -940.1398f, 91.5109f) ||	//3 Alta Street Tower, Apt 57
		currentInterior == INTERIOR::GET_INTERIOR_AT_COORDS(-270.7699f, -968.1721f, 76.2314f))		//3 Alta Street Tower, Apt 10
		)
	{
		EnableHighEndApartment(-272.4795f, -940.1398f, 91.5109f);
		EnableHighEndApartment(-270.7699f, -968.1721f, 76.2314f);
		INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(-1294038851);	//dt1_20_build2
		INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(-312225717);	//dt1_20_dt1_emissive_dt1_20
		GRAPHICS::DISABLE_OCCLUSION_THIS_FRAME();
		DeleteScenarioPedAtCoords(-276.4401f, -950.4869f, 85.8006f, pedScenario);
		DeleteScenarioPedAtCoords(-266.7457f, -957.8518f, 70.5210f, pedScenario);
	}

	//Del Perro Heights Apartments culling
	if (SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, -1442.0504f, -545.0800f, 33.7418f) < distance &&
		(currentInterior == INTERIOR::GET_INTERIOR_AT_COORDS(-1451.538f, -523.6300f, 68.5566f) ||	//Del Perro Heights, Apt 20
		currentInterior == INTERIOR::GET_INTERIOR_AT_COORDS(-1451.538f, -523.6300f, 55.9290f))		//Del Perro Heights, Apt 7
		)
	{
		EnableHighEndApartment(-1451.538f, -523.6300f, 68.5566f);
		EnableHighEndApartment(-1451.538f, -523.6300f, 55.9290f);
		INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(-160801422);	//sm_14_bld2
		INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(-1969201018);	//sm_14_emissive
		GRAPHICS::DISABLE_OCCLUSION_THIS_FRAME();
		DeleteScenarioPedAtCoords(-1460.754f, -529.7892f, 62.8463f, pedScenario);
		DeleteScenarioPedAtCoords(-1460.754f, -529.7892f, 50.2187f, pedScenario);
	}

	return;
}

void Teleports()
{
	//Low End Apartments
	if (iniLowEndApartments)
		LowEndApartments();

	//Medium End Apartments
	if (iniMediumEndApartments)
		MediumEndApartments();

	//High End Apartments
	if (iniHighEndApartments)
	{
		HighEndApartmentsCulling();
		HighEndApartments();
	}
	return;
}
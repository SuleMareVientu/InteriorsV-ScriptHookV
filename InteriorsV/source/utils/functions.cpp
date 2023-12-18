//ScriptHook
#include <natives.h>
// #include <types.h> //Already included in globals.h
//Custom
#include "functions.h"
#include "../globals.h"
#include "../script.h"
#include "onlineteleports.h"

Hash doorHash = NULL;

static int lastTimer = 0;
static float lastMarkerOutX = 0.0f;
static float lastMarkerOutZ = 0.0f;
static float markerStartX = 0.0f;
static float markerStartY = 0.0f;
static float markerStartZ = 0.0f;
static float headingStartGlobal = 0.0f;

/*
#include "string"
char* ToString(Any var)
{
	std::string str = std::to_string(var);
	char* c = strcpy((char*)malloc(str.length() + 1), str.c_str());
	return(c);
}
*/

void Print(char* string, int ms)
{
	HUD::BEGIN_TEXT_COMMAND_PRINT("STRING");
	HUD::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(string);
	HUD::END_TEXT_COMMAND_PRINT(ms, 1);
	return;
}

void PrintInt(int value, int ms)
{
	HUD::BEGIN_TEXT_COMMAND_PRINT("NUMBER");
	HUD::ADD_TEXT_COMPONENT_INTEGER(value);
	HUD::END_TEXT_COMMAND_PRINT(ms, 1);
	return;
}

void PrintFloat(float value, int ms)
{
	HUD::BEGIN_TEXT_COMMAND_PRINT("NUMBER");
	HUD::ADD_TEXT_COMPONENT_FLOAT(value, 4);
	HUD::END_TEXT_COMMAND_PRINT(ms, 1);
	return;
}

void PrintHelp(char* string)
{
	HUD::BEGIN_TEXT_COMMAND_DISPLAY_HELP("STRING");
	HUD::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(string);
	HUD::END_TEXT_COMMAND_DISPLAY_HELP(0, false, false, -1);
	return;
}

void LoadIPL(char* ipl)
{
	if (!STREAMING::IS_IPL_ACTIVE(ipl))
		STREAMING::REQUEST_IPL(ipl);
	return;
}

void UnloadIPL(char* ipl)
{
	if (STREAMING::IS_IPL_ACTIVE(ipl))
		STREAMING::REMOVE_IPL(ipl);
	return;
}

void EnableInterior(int interior)
{
	if (INTERIOR::IS_INTERIOR_DISABLED(interior) || INTERIOR::IS_INTERIOR_CAPPED(interior))
	{
		INTERIOR::PIN_INTERIOR_IN_MEMORY(interior);
		STREAMING::SET_INTERIOR_ACTIVE(interior, true);
		INTERIOR::DISABLE_INTERIOR(interior, false);
		INTERIOR::CAP_INTERIOR(interior, false);
	}
	return;
}

void DisableInterior(int interior)
{
	if (!INTERIOR::IS_INTERIOR_DISABLED(interior))
	{
		STREAMING::SET_INTERIOR_ACTIVE(interior, false);
		INTERIOR::UNPIN_INTERIOR(interior);
		INTERIOR::DISABLE_INTERIOR(interior, true);
	}
	return;
}

void AltUnlockDoor(Hash EntityHash, float x, float y, float z)
{
	if (OBJECT::DOOR_SYSTEM_FIND_EXISTING_DOOR(x, y, z, EntityHash, &doorHash))
	{
		if (OBJECT::DOOR_SYSTEM_GET_DOOR_STATE(doorHash) != 0)
			OBJECT::DOOR_SYSTEM_SET_DOOR_STATE(doorHash, 0, false, false);
	}
	return;
}

void ForceUnlockDoor(Hash EntityHash, float x, float y, float z, int seed)
{
	if (!OBJECT::DOOR_SYSTEM_FIND_EXISTING_DOOR(x, y, z, EntityHash, &doorHash))
	{
		Hash newDoorHash = EntityHash + seed;
		Object door = OBJECT::GET_CLOSEST_OBJECT_OF_TYPE(x, y, z, 0.5f, EntityHash, false, true, true);
		if (ENTITY::DOES_ENTITY_EXIST(door))
		{
			ENTITY::SET_ENTITY_AS_MISSION_ENTITY(door, true, true);
			OBJECT::DELETE_OBJECT(&door);
		}
		OBJECT::ADD_DOOR_TO_SYSTEM(newDoorHash, EntityHash, x, y, z, false, false, false);
		OBJECT::DOOR_SYSTEM_SET_DOOR_STATE(newDoorHash, 0, false, false);
	}
	return;
}

void SetDoorUnlockDistance(Hash EntityHash, float x, float y, float z, float distance)
{
	if (OBJECT::DOOR_SYSTEM_FIND_EXISTING_DOOR(x, y, z, EntityHash, &doorHash))
	{
		OBJECT::DOOR_SYSTEM_SET_DOOR_STATE(doorHash, 0, false, false);
		OBJECT::DOOR_SYSTEM_SET_AUTOMATIC_DISTANCE(doorHash, distance, false, false);
	}
	return;
}

void SetDoorUnlockDistanceWithRate(Hash EntityHash, float x, float y, float z, float rate, float distance)
{
	if (OBJECT::DOOR_SYSTEM_FIND_EXISTING_DOOR(x, y, z, EntityHash, &doorHash))
	{
		OBJECT::DOOR_SYSTEM_SET_DOOR_STATE(doorHash, 0, false, false);
		OBJECT::DOOR_SYSTEM_SET_AUTOMATIC_RATE(doorHash, rate, false, false);
		OBJECT::DOOR_SYSTEM_SET_AUTOMATIC_DISTANCE(doorHash, distance, false, false);
	}
	return;
}

void DeleteObjectAtCoords(Hash EntityHash, float x, float y, float z)
{
	Object obj = OBJECT::GET_CLOSEST_OBJECT_OF_TYPE(x, y, z, 0.5f, EntityHash, false, true, true);
	if (ENTITY::DOES_ENTITY_EXIST(obj))
	{
		ENTITY::SET_ENTITY_AS_MISSION_ENTITY(obj, true, true);
		OBJECT::DELETE_OBJECT(&obj);
	}
	return;
}

void DeletePedAtCoords(float x, float y, float z)
{
	Ped ped = NULL;
	PED::SET_SCENARIO_PEDS_TO_BE_RETURNED_BY_NEXT_COMMAND(true);
	PED::GET_CLOSEST_PED(x, y, z, 0.5f, true, true, &ped, false, true, -1);
	if (ENTITY::DOES_ENTITY_EXIST(ped))
	{
		ENTITY::SET_ENTITY_AS_MISSION_ENTITY(ped, true, true);
		PED::DELETE_PED(&ped);
	}
	return;
}

void DeleteScenarioPedAtCoords(float x, float y, float z, char* scenario)
{
	Ped ped = NULL;
	PED::SET_SCENARIO_PEDS_TO_BE_RETURNED_BY_NEXT_COMMAND(true);
	PED::GET_CLOSEST_PED(x, y, z, 0.5f, true, true, &ped, false, true, -1);
	if (ENTITY::DOES_ENTITY_EXIST(ped) && PED::IS_PED_USING_SCENARIO(ped, scenario))
	{
		ENTITY::SET_ENTITY_AS_MISSION_ENTITY(ped, true, true);
		PED::DELETE_PED(&ped);
	}
	return;
}

void EnableInteriorProp(int interior, char* prop, bool refresh)
{
	if (!INTERIOR::IS_INTERIOR_ENTITY_SET_ACTIVE(interior, prop))
	{
		INTERIOR::ACTIVATE_INTERIOR_ENTITY_SET(interior, prop);
		if (refresh)
			INTERIOR::REFRESH_INTERIOR(interior);
	}
	return;
}

void DisableInteriorProp(int interior, char* prop, bool refresh)
{
	if (INTERIOR::IS_INTERIOR_ENTITY_SET_ACTIVE(interior, prop))
	{
		INTERIOR::DEACTIVATE_INTERIOR_ENTITY_SET(interior, prop);
		if (refresh)
			INTERIOR::REFRESH_INTERIOR(interior);
	}
	return;
}

void SetScenarioGroup(char* scenarioGroup, bool toggle)
{
	if (TASK::DOES_SCENARIO_GROUP_EXIST(scenarioGroup))
	{
		if (toggle && !TASK::IS_SCENARIO_GROUP_ENABLED(scenarioGroup))
			TASK::SET_SCENARIO_GROUP_ENABLED(scenarioGroup, true);
		else if (!toggle && TASK::IS_SCENARIO_GROUP_ENABLED(scenarioGroup))
			TASK::SET_SCENARIO_GROUP_ENABLED(scenarioGroup, false);
	}
	return;
}

void AddBlip(float x, float y, float z, float scale, char* title, int id, int colour)
{
	Blip blip = HUD::ADD_BLIP_FOR_COORD(x, y, z);
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

bool Teleport(float x, float y, float z, float heading, float headingOut, float markerX, float markerY, float markerZ, int red, int green, int blue, int alpha, char* text, char* textOut, bool overlapCheck)
{
	float distanceStart = SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, markerX, markerY, markerZ);
	float distanceEnd = SYSTEM::VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, x, y, z);

	if (distanceStart < distance)
		GRAPHICS::DRAW_MARKER(1, markerX, markerY, markerZ, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.75f, 0.75f, 0.75f, red, green, blue, alpha, false, false, 2, false, NULL, NULL, false);

	//Check for overlap with other markers at same coords (low-end and medium apartments)
	if (distanceEnd < distance && (lastTimer != SYSTEM::TIMERA() || (lastTimer == SYSTEM::TIMERA() && (x != lastMarkerOutX || z != lastMarkerOutZ))))
	{
		GRAPHICS::DRAW_MARKER(1, x, y, z, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.75f, 0.75f, 0.75f, red, green, blue, alpha, false, false, 2, false, NULL, NULL, false);
		lastMarkerOutX = x;
		lastMarkerOutZ = z;
		lastTimer = SYSTEM::TIMERA();
	}

	//Prevent player overlapping with floor
	z = z + 1.0f;
	markerZ = markerZ + 1.0f;

	if (distanceStart < 2.25f)
	{
		PrintHelp(text);
		if (PAD::IS_DISABLED_CONTROL_JUST_PRESSED(2, 23) && !CAM::IS_SCREEN_FADING_IN() && !CAM::IS_SCREEN_FADED_OUT())
		{
			isInsideApartment = true;
			ENTITY::FREEZE_ENTITY_POSITION(playerPed, true);
			CAM::DO_SCREEN_FADE_OUT(300);
			while (!CAM::IS_SCREEN_FADED_OUT())
			{
				WAIT(0);
			}

			ENTITY::SET_ENTITY_COORDS_NO_OFFSET(playerPed, x, y, z, false, false, false);
			playerLoc = { x, playerLoc._paddingx , y, playerLoc._paddingy, z, playerLoc._paddingz };
			ENTITY::SET_ENTITY_HEADING(playerPed, heading);
			CAM::SET_GAMEPLAY_CAM_RELATIVE_HEADING(0.0f);
			CAM::SET_GAMEPLAY_CAM_RELATIVE_PITCH(0.0f, 0.0f);
			
			//Asset streaming check
			update();
			HighEndApartmentsCulling();
			int interior = INTERIOR::GET_INTERIOR_AT_COORDS(x, y, z);
			//Compatibility with 4 Integrity Way apartments and Union Depository
			if (interior != 0 &&
				interior != INTERIOR::GET_INTERIOR_AT_COORDS(-47.0121f, -584.5853f, 36.9580f)	&&	//4 Integrity Way apartments
				interior != INTERIOR::GET_INTERIOR_AT_COORDS(-0.1434f, -705.9488f, 15.1312f)		//Union Depository Vault
				)
			{
				while (INTERIOR::IS_VALID_INTERIOR(interior) && !INTERIOR::IS_INTERIOR_READY(interior))
				{
					WAIT(0);
				}
			}
			STREAMING::LOAD_SCENE(x, y, z);

			ENTITY::FREEZE_ENTITY_POSITION(playerPed, false);
			CAM::DO_SCREEN_FADE_IN(300);
			if (overlapCheck)
			{
				markerStartX = markerX;
				markerStartY = markerY;
				markerStartZ = markerZ;
				headingStartGlobal = headingOut;
			}
		}
		else
			return true;
	}

	if (distanceEnd < 2.25f)
	{
		PrintHelp(textOut);
		if (PAD::IS_DISABLED_CONTROL_JUST_PRESSED(2, 23) && !CAM::IS_SCREEN_FADING_IN() && !CAM::IS_SCREEN_FADED_OUT())
		{
			if (overlapCheck)
			{
				markerX = markerStartX;
				markerY = markerStartY;
				markerZ = markerStartZ;
				headingOut = headingStartGlobal;
			}

			isInsideApartment = false;
			ENTITY::FREEZE_ENTITY_POSITION(playerPed, true);
			CAM::DO_SCREEN_FADE_OUT(300);
			while (!CAM::IS_SCREEN_FADED_OUT())
			{
				WAIT(0);
			}

			ENTITY::SET_ENTITY_COORDS_NO_OFFSET(playerPed, markerX, markerY, markerZ, false, false, false);
			playerLoc = { markerX, playerLoc._paddingx , markerY, playerLoc._paddingy, markerZ, playerLoc._paddingz };
			ENTITY::SET_ENTITY_HEADING(playerPed, headingOut);
			CAM::SET_GAMEPLAY_CAM_RELATIVE_HEADING(0.0f);
			CAM::SET_GAMEPLAY_CAM_RELATIVE_PITCH(0.0f, 0.0f);
			
			//Asset streaming check
			update();
			//Compatibility with 4 Integrity Way apartments and Union Depository
			int interior = INTERIOR::GET_INTERIOR_AT_COORDS(markerX, markerY, markerZ);
			if (interior != 0 && 
				interior != INTERIOR::GET_INTERIOR_AT_COORDS(-47.0121f, -584.5853f, 36.9580f)	&&	//4 Integrity Way apartments
				interior != INTERIOR::GET_INTERIOR_AT_COORDS(10.3384f, -671.1154f, 32.4495f)		//Union Depository Parking
				)
			{
				while (INTERIOR::IS_VALID_INTERIOR(interior) && !INTERIOR::IS_INTERIOR_READY(interior))
				{
					WAIT(0);
				}
			}
			STREAMING::LOAD_SCENE(markerX, markerY, markerZ);

			ENTITY::FREEZE_ENTITY_POSITION(playerPed, false);
			CAM::DO_SCREEN_FADE_IN(300);
		}
	}
	return false;
}
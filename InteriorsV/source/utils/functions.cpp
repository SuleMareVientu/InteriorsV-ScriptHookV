//ScriptHook
#include <natives.h>
// #include <types.h> //Already included in globals.h
//Custom
#include "functions.h"
#include "../globals.h"
#include "../script.h"
#include "onlineteleports.h"

Hash tempDoorHash = NULL;
static int lastTimer = 0;
static float lastMarkerOutX = 0.0f;
static float lastMarkerOutZ = 0.0f;
//Default values when teleporting for the first time from a low/medium end apartment
static float markerStartX = 3.3769f;
static float markerStartY = 36.5695f;
static float markerStartZ = 70.5354f;
static float headingStartGlobal = 170.0f;

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
	BEGIN_TEXT_COMMAND_PRINT("STRING");
	ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(string);
	END_TEXT_COMMAND_PRINT(ms, 1);
	return;
}

void PrintInt(int value, int ms)
{
	BEGIN_TEXT_COMMAND_PRINT("NUMBER");
	ADD_TEXT_COMPONENT_INTEGER(value);
	END_TEXT_COMMAND_PRINT(ms, 1);
	return;
}

void PrintFloat(float value, int ms)
{
	BEGIN_TEXT_COMMAND_PRINT("NUMBER");
	ADD_TEXT_COMPONENT_FLOAT(value, 4);
	END_TEXT_COMMAND_PRINT(ms, 1);
	return;
}

void PrintHelp(char* string)
{
	BEGIN_TEXT_COMMAND_DISPLAY_HELP("STRING");
	ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(string);
	END_TEXT_COMMAND_DISPLAY_HELP(0, false, false, -1);
	return;
}

void LoadIPL(char* ipl)
{
	if (!IS_IPL_ACTIVE(ipl))
		REQUEST_IPL(ipl);
	return;
}

void UnloadIPL(char* ipl)
{
	if (IS_IPL_ACTIVE(ipl))
		REMOVE_IPL(ipl);
	return;
}

void EnableInterior(int interior)
{
	if (!IS_VALID_INTERIOR(interior))
		return;

	bool isDisabled = IS_INTERIOR_DISABLED(interior);
	bool isCapped = IS_INTERIOR_CAPPED(interior);

	if (isDisabled || isCapped)
	{
		PIN_INTERIOR_IN_MEMORY(interior);
		SET_INTERIOR_ACTIVE(interior, true);
		if (isDisabled)
			DISABLE_INTERIOR(interior, false);
		if (isCapped)
			CAP_INTERIOR(interior, false);
	}
	return;
}

void DisableInterior(int interior)
{
	if (!IS_VALID_INTERIOR(interior))
		return;

	if (!IS_INTERIOR_DISABLED(interior))
	{
		SET_INTERIOR_ACTIVE(interior, false);
		UNPIN_INTERIOR(interior);
		CAP_INTERIOR(interior, true);
		DISABLE_INTERIOR(interior, true);
	}
	return;
}

void SetDoorState(Hash DoorHash, int state, bool requestDoor, bool forceUpdate)
{
	if (!IS_DOOR_REGISTERED_WITH_SYSTEM(DoorHash) || DOOR_SYSTEM_GET_DOOR_STATE(DoorHash) == state)
		return;
	
	DOOR_SYSTEM_SET_DOOR_STATE(DoorHash, state, requestDoor, forceUpdate);
	return;
}

void SetDoorStateAtCoords(Hash EntityHash, float x, float y, float z, int state, bool forceUpdate, bool requestDoor)
{
	if (DOOR_SYSTEM_FIND_EXISTING_DOOR(x, y, z, EntityHash, &tempDoorHash))
	{
		if (DOOR_SYSTEM_GET_DOOR_STATE(tempDoorHash) != state)
			DOOR_SYSTEM_SET_DOOR_STATE(tempDoorHash, state, requestDoor, forceUpdate);
	}
	return;
}

void SetAutoDoorState(Hash doorHash, int state, float rate, float distance, bool forceUpdate)
{
	if (rate >= 0.0f)
		DOOR_SYSTEM_SET_AUTOMATIC_RATE(doorHash, rate, false, false);
	if (distance >= 0.0f)
		DOOR_SYSTEM_SET_AUTOMATIC_DISTANCE(doorHash, distance, false, false);

	DOOR_SYSTEM_SET_DOOR_STATE(doorHash, state, false, forceUpdate);
	return;
}

void SetSlidingDoorsStateAtCoords(Hash EntityHash, float x1, float y1, float z1, float x2, float y2, float z2, bool state, float openRatio, float minDistance, float maxDistance, bool removeSpring)
{
	float distance = VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, ((x1 + x2) * 0.5f), ((y1 + y2) * 0.5f), ((z1 + z2) * 0.5f));
	if (distance < (minDistance * minDistance))
	{
		SET_STATE_OF_CLOSEST_DOOR_OF_TYPE(EntityHash, x1, y1, z1, state, openRatio, removeSpring);
		SET_STATE_OF_CLOSEST_DOOR_OF_TYPE(EntityHash, x2, y2, z2, state, openRatio, removeSpring);
	}
	else if (distance > (maxDistance * maxDistance))
	{
		SET_STATE_OF_CLOSEST_DOOR_OF_TYPE(EntityHash, x1, y1, z1, state, -openRatio, removeSpring);
		SET_STATE_OF_CLOSEST_DOOR_OF_TYPE(EntityHash, x2, y2, z2, state, -openRatio, removeSpring);	}
	return;
}

void SetSingleSlidingDoorStateAtCoords(Hash EntityHash, float x, float y, float z, float offsetX, float offsetY, bool state, float openRatio, float minDistance, float maxDistance, bool removeSpring)
{
	if (VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, x, y, z) > 750.0f)
		return;

	Object door = GET_CLOSEST_OBJECT_OF_TYPE(x, y, z, 10.0f, EntityHash, false, false, false);
	if (!DOES_ENTITY_EXIST(door))
		return;

	Vector3 worldOffsetCoords = GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(door, offsetX, offsetY, 0.0f);
	float distance = VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, worldOffsetCoords.x, worldOffsetCoords.y, z);
	if (distance < (minDistance * minDistance))
		SET_STATE_OF_CLOSEST_DOOR_OF_TYPE(EntityHash, x, y, z, state, openRatio, removeSpring);
	else if (distance > (maxDistance * maxDistance))
		SET_STATE_OF_CLOSEST_DOOR_OF_TYPE(EntityHash, x, y, z, state, -openRatio, removeSpring);
	return;
}

void SetSpecialGatesStateAtCoords(Hash EntityHash, Hash SecondaryEntityHash, float x1, float y1, float z1, float x2, float y2, float z2, bool state, float openRatio, float minDistance, float maxDistance, bool removeSpring)
{
	float distance = VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, ((x1 + x2) * 0.5f), ((y1 + y2) * 0.5f), ((z1 + z2) * 0.5f));
	if (distance < (minDistance * minDistance))
	{
		SET_STATE_OF_CLOSEST_DOOR_OF_TYPE(EntityHash, x1, y1, z1, state, openRatio, removeSpring);
		SET_STATE_OF_CLOSEST_DOOR_OF_TYPE(SecondaryEntityHash, x2, y2, z2, state, -openRatio, removeSpring);
	}
	else if (distance > (maxDistance * maxDistance))
	{
		SET_STATE_OF_CLOSEST_DOOR_OF_TYPE(EntityHash, x1, y1, z1, state, -openRatio, removeSpring);
		SET_STATE_OF_CLOSEST_DOOR_OF_TYPE(SecondaryEntityHash, x2, y2, z2, state, openRatio, removeSpring);
	}
	return;
}

bool DeleteObjectAtCoords(Hash EntityHash, float x, float y, float z, float radius)
{
	Object obj = GET_CLOSEST_OBJECT_OF_TYPE(x, y, z, radius, EntityHash, false, true, true);
	if (!DOES_ENTITY_EXIST(obj))
		return false;

	SET_ENTITY_AS_MISSION_ENTITY(obj, true, true);
	DELETE_OBJECT(&obj);
	return true;
}

void DeleteScenarioPedAtCoords(float x, float y, float z, char* scenario)
{
	Ped ped = NULL;
	SET_SCENARIO_PEDS_TO_BE_RETURNED_BY_NEXT_COMMAND(true);
	GET_CLOSEST_PED(x, y, z, 0.5f, true, true, &ped, false, true, -1);
	if (DOES_ENTITY_EXIST(ped) && IS_PED_USING_SCENARIO(ped, scenario))
	{
		SET_ENTITY_AS_MISSION_ENTITY(ped, true, true);
		DELETE_PED(&ped);
	}
	return;
}

void SetObjectYawAtCoords(Hash hash, float x, float y, float z, float yaw)
{
	Object door = GET_CLOSEST_OBJECT_OF_TYPE(x, y, z, 0.3f, hash, false, false, false);

	if (!DOES_ENTITY_EXIST(door))
		return;

	SET_ENTITY_HEADING(door, yaw);
	return;
}

void EnableInteriorProp(int interior, char* prop, bool refresh)
{
	if (!IS_INTERIOR_ENTITY_SET_ACTIVE(interior, prop))
	{
		ACTIVATE_INTERIOR_ENTITY_SET(interior, prop);
		if (refresh)
			REFRESH_INTERIOR(interior);
	}
	return;
}

void DisableInteriorProp(int interior, char* prop, bool refresh)
{
	if (IS_INTERIOR_ENTITY_SET_ACTIVE(interior, prop))
	{
		DEACTIVATE_INTERIOR_ENTITY_SET(interior, prop);
		if (refresh)
			REFRESH_INTERIOR(interior);
	}
	return;
}

void SetScenarioGroup(char* scenarioGroup, bool toggle)
{
	if (DOES_SCENARIO_GROUP_EXIST(scenarioGroup))
	{
		if (toggle && !IS_SCENARIO_GROUP_ENABLED(scenarioGroup))
			SET_SCENARIO_GROUP_ENABLED(scenarioGroup, true);
		else if (!toggle && IS_SCENARIO_GROUP_ENABLED(scenarioGroup))
			SET_SCENARIO_GROUP_ENABLED(scenarioGroup, false);
	}
	return;
}

void AddBlip(float x, float y, float z, float scale, char* title, int id, int colour)
{
	Blip blip = ADD_BLIP_FOR_COORD(x, y, z);
	SET_BLIP_SPRITE(blip, id);
	SET_BLIP_DISPLAY(blip, 4);
	SET_BLIP_SCALE(blip, scale);
	SET_BLIP_COLOUR(blip, colour);
	SET_BLIP_AS_SHORT_RANGE(blip, true);
	BEGIN_TEXT_COMMAND_SET_BLIP_NAME("STRING");
	ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(title);
	END_TEXT_COMMAND_SET_BLIP_NAME(blip);
	return;
}

bool AdditionalChecks(Ped ped)
{
	if (IS_PED_RAGDOLL(ped)				||
		IS_PED_GETTING_UP(ped)			||
		IS_PED_FALLING(ped)				||
		IS_PED_JUMPING(ped)				||
		IS_PED_IN_MELEE_COMBAT(ped)		||
		IS_PED_IN_COVER(ped, false)		||
		IS_PED_SHOOTING(ped)			||
		!IS_PED_ON_FOOT(ped)			||
		IS_PED_TAKING_OFF_HELMET(ped))
		return false;
	else
		return true;
}

bool Teleport(float x, float y, float z, float heading, float headingOut, float markerX, float markerY, float markerZ, int red, int green, int blue, int alpha, char* text, char* textOut, bool overlapCheck)
{
	float distanceStart = VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, markerX, markerY, markerZ);
	float distanceEnd = VDIST2(playerLoc.x, playerLoc.y, playerLoc.z, x, y, z);

	if (distanceStart < distance)
		DRAW_MARKER(1, markerX, markerY, markerZ, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.75f, 0.75f, 0.75f, red, green, blue, alpha, false, false, 2, false, NULL, NULL, false);

	//Check for overlap with other markers at same coords (low-end and medium apartments)
	if (distanceEnd < distance && (lastTimer != TIMERA() || (lastTimer == TIMERA() && (x != lastMarkerOutX || z != lastMarkerOutZ))))
	{
		DRAW_MARKER(1, x, y, z, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.75f, 0.75f, 0.75f, red, green, blue, alpha, false, false, 2, false, NULL, NULL, false);
		lastMarkerOutX = x;
		lastMarkerOutZ = z;
		lastTimer = TIMERA();
	}

	//Prevent player overlapping with floor
	z = z + 1.0f;
	markerZ = markerZ + 1.0f;

	if (distanceStart < 2.25f)
	{
		PrintHelp(text);
		if (IS_DISABLED_CONTROL_JUST_PRESSED(2, 23) && AdditionalChecks(playerPed) && !IS_SCREEN_FADING_IN() && !IS_SCREEN_FADED_OUT())
		{
			isInsideApartment = true;
			FREEZE_ENTITY_POSITION(playerPed, true);
			DO_SCREEN_FADE_OUT(300);
			while (!IS_SCREEN_FADED_OUT())
			{
				WAIT(0);
			}

			SET_ENTITY_COORDS_NO_OFFSET(playerPed, x, y, z, false, false, false);
			playerLoc = { x, playerLoc._paddingx , y, playerLoc._paddingy, z, playerLoc._paddingz };
			SET_ENTITY_HEADING(playerPed, heading);
			SET_GAMEPLAY_CAM_RELATIVE_HEADING(0.0f);
			SET_GAMEPLAY_CAM_RELATIVE_PITCH(0.0f, 0.0f);
			
			//Asset streaming check
			update();
			HighEndApartmentsCulling();
			int interior = GET_INTERIOR_AT_COORDS(x, y, z);
			//Compatibility with 4 Integrity Way apartments and Union Depository
			if (interior != 0 &&
				interior != GET_INTERIOR_AT_COORDS(-47.0121f, -584.5853f, 36.9580f)	&&	//4 Integrity Way apartments
				interior != GET_INTERIOR_AT_COORDS(-0.1434f, -705.9488f, 15.1312f)		//Union Depository Vault
				)
			{
				while (IS_VALID_INTERIOR(interior) && !IS_INTERIOR_READY(interior))
				{
					WAIT(0);
				}
			}
			LOAD_SCENE(x, y, z);

			FREEZE_ENTITY_POSITION(playerPed, false);
			DO_SCREEN_FADE_IN(300);
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
		if (IS_DISABLED_CONTROL_JUST_PRESSED(2, 23) && AdditionalChecks(playerPed) && !IS_SCREEN_FADING_IN() && !IS_SCREEN_FADED_OUT())
		{
			if (overlapCheck)
			{
				markerX = markerStartX;
				markerY = markerStartY;
				markerZ = markerStartZ;
				headingOut = headingStartGlobal;
			}

			isInsideApartment = false;
			FREEZE_ENTITY_POSITION(playerPed, true);
			DO_SCREEN_FADE_OUT(300);
			while (!IS_SCREEN_FADED_OUT())
			{
				WAIT(0);
			}

			SET_ENTITY_COORDS_NO_OFFSET(playerPed, markerX, markerY, markerZ, false, false, false);
			playerLoc = { markerX, playerLoc._paddingx , markerY, playerLoc._paddingy, markerZ, playerLoc._paddingz };
			SET_ENTITY_HEADING(playerPed, headingOut);
			SET_GAMEPLAY_CAM_RELATIVE_HEADING(0.0f);
			SET_GAMEPLAY_CAM_RELATIVE_PITCH(0.0f, 0.0f);
			
			//Asset streaming check
			update();
			//Compatibility with 4 Integrity Way apartments and Union Depository
			int interior = GET_INTERIOR_AT_COORDS(markerX, markerY, markerZ);
			if (interior != 0 && 
				interior != GET_INTERIOR_AT_COORDS(-47.0121f, -584.5853f, 36.9580f)	&&	//4 Integrity Way apartments
				interior != GET_INTERIOR_AT_COORDS(10.3384f, -671.1154f, 32.4495f)		//Union Depository Parking
				)
			{
				while (IS_VALID_INTERIOR(interior) && !IS_INTERIOR_READY(interior))
				{
					WAIT(0);
				}
			}
			LOAD_SCENE(markerX, markerY, markerZ);

			FREEZE_ENTITY_POSITION(playerPed, false);
			DO_SCREEN_FADE_IN(300);
		}
	}
	return false;
}
//ScriptHook
#include <natives.h>
#include <types.h>
//Custom
#include "functions.h"
#include "../globals.h"

Hash doorHash;

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
	UI::BEGIN_TEXT_COMMAND_PRINT("STRING");
	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(string);
	UI::END_TEXT_COMMAND_PRINT(ms, 1);
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
	INTERIOR::_LOAD_INTERIOR(interior);
	STREAMING::SET_INTERIOR_ACTIVE(interior, true);
	INTERIOR::DISABLE_INTERIOR(interior, false);
	INTERIOR::CAP_INTERIOR(interior, false);
	return;
}

void AltUnlockDoor(Hash EntityHash, float x, float y, float z)
{
	if (OBJECT::DOOR_SYSTEM_FIND_EXISTING_DOOR(x, y, z, EntityHash, &doorHash))
	{
		if (OBJECT::DOOR_SYSTEM_GET_DOOR_STATE(doorHash) != 0)
			OBJECT::_SET_DOOR_ACCELERATION_LIMIT(doorHash, 0, false, false);
	}
	return;
}

void ForceUnlockDoor(Hash EntityHash, float x, float y, float z, int seed)
{
	if (!OBJECT::DOOR_SYSTEM_FIND_EXISTING_DOOR(x, y, z, EntityHash, &doorHash))
	{
		Hash newDoorHash = EntityHash + seed;
		Object door = OBJECT::GET_CLOSEST_OBJECT_OF_TYPE(x, y, z, 0.5, EntityHash, false, true, true);
		ENTITY::SET_ENTITY_AS_MISSION_ENTITY(door, true, true);
		ENTITY::DELETE_ENTITY(&door);
		OBJECT::ADD_DOOR_TO_SYSTEM(newDoorHash, EntityHash, x, y, z, false, false, false);
		OBJECT::_SET_DOOR_ACCELERATION_LIMIT(newDoorHash, 0, false, false);
	}
	return;
}

void DeleteObject(Hash EntityHash, float x, float y, float z)
{
	Object entity = OBJECT::GET_CLOSEST_OBJECT_OF_TYPE(x, y, z, 0.5, EntityHash, false, true, true);
	ENTITY::SET_ENTITY_AS_MISSION_ENTITY(entity, true, true);
	OBJECT::DELETE_OBJECT(&entity);
	return;
}

void EnableInteriorProp(int interior, char* prop, bool refresh)
{
	if (!INTERIOR::_IS_INTERIOR_PROP_ENABLED(interior, prop))
	{
		INTERIOR::_ENABLE_INTERIOR_PROP(interior, prop);
		if (refresh)
			INTERIOR::REFRESH_INTERIOR(interior);
	}
	return;
}

void DisableInteriorProp(int interior, char* prop, bool refresh)
{
	if (INTERIOR::_IS_INTERIOR_PROP_ENABLED(interior, prop))
	{
		INTERIOR::_DISABLE_INTERIOR_PROP(interior, prop);
		if (refresh)
			INTERIOR::REFRESH_INTERIOR(interior);
	}
	return;
}

void SetScenarioGroup(char* scenarioGroup, bool toggle)
{
	if (AI::DOES_SCENARIO_GROUP_EXIST(scenarioGroup) && !AI::IS_SCENARIO_GROUP_ENABLED(scenarioGroup))
	{
		AI::SET_SCENARIO_GROUP_ENABLED(scenarioGroup, toggle);
	}
	return;
}

void AddBlip(float x, float y, float z, float scale, char* title, int id, int colour)
{
	Blip blip = UI::ADD_BLIP_FOR_COORD(x, y, z);
	UI::SET_BLIP_SPRITE(blip, id);
	UI::SET_BLIP_DISPLAY(blip, 4);
	UI::SET_BLIP_SCALE(blip, scale);
	UI::SET_BLIP_COLOUR(blip, colour);
	UI::SET_BLIP_AS_SHORT_RANGE(blip, true);
	UI::BEGIN_TEXT_COMMAND_SET_BLIP_NAME("STRING");
	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(title);
	UI::END_TEXT_COMMAND_SET_BLIP_NAME(blip);
	return;
}
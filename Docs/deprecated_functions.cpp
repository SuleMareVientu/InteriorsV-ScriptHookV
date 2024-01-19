void SetDoorStateAtCoords(Hash EntityHash, float x, float y, float z, int state, bool requestDoor = false, bool forceUpdate = false);
void ForceUnlockDoor(Hash EntityHash, float x, float y, float z, int seed);
void SetDoorUnlockDistance(Hash EntityHash, float x, float y, float z, float distance);
void SetDoorUnlockDistanceWithRate(Hash EntityHash, float x, float y, float z, float rate, float distance);
void DeletePedAtCoords(float x, float y, float z);

void ForceUnlockDoor(Hash EntityHash, float x, float y, float z, int seed)
{
	if (!DOOR_SYSTEM_FIND_EXISTING_DOOR(x, y, z, EntityHash, &doorHash))
	{
		Hash newDoorHash = EntityHash + seed;
		Object door = GET_CLOSEST_OBJECT_OF_TYPE(x, y, z, 0.5f, EntityHash, false, true, true);
		if (DOES_ENTITY_EXIST(door))
		{
			SET_ENTITY_AS_MISSION_ENTITY(door, true, true);
			DELETE_OBJECT(&door);
		}
		ADD_DOOR_TO_SYSTEM(newDoorHash, EntityHash, x, y, z, false, false, false);
		DOOR_SYSTEM_SET_DOOR_STATE(newDoorHash, 0, false, false);
	}
	return;
}

void SetDoorUnlockDistance(Hash EntityHash, float x, float y, float z, float distance)
{
	if (DOOR_SYSTEM_FIND_EXISTING_DOOR(x, y, z, EntityHash, &doorHash))
	{
		DOOR_SYSTEM_SET_DOOR_STATE(doorHash, 0, false, false);
		DOOR_SYSTEM_SET_AUTOMATIC_DISTANCE(doorHash, distance, false, false);
	}
	return;
}

void SetDoorUnlockDistanceWithRate(Hash EntityHash, float x, float y, float z, float rate, float distance)
{
	if (DOOR_SYSTEM_FIND_EXISTING_DOOR(x, y, z, EntityHash, &doorHash))
	{
		if (DOOR_SYSTEM_GET_DOOR_STATE(doorHash) != 0)
			DOOR_SYSTEM_SET_DOOR_STATE(doorHash, 0, false, true);

		//DOOR_SYSTEM_SET_HOLD_OPEN(doorHash, false);
		DOOR_SYSTEM_SET_AUTOMATIC_RATE(doorHash, rate, false, false);
		DOOR_SYSTEM_SET_AUTOMATIC_DISTANCE(doorHash, distance, false, false);
	}
	return;
}

void DeletePedAtCoords(float x, float y, float z)
{
	Ped ped = NULL;
	SET_SCENARIO_PEDS_TO_BE_RETURNED_BY_NEXT_COMMAND(true);
	GET_CLOSEST_PED(x, y, z, 0.5f, true, true, &ped, false, true, -1);
	if (DOES_ENTITY_EXIST(ped))
	{
		SET_ENTITY_AS_MISSION_ENTITY(ped, true, true);
		DELETE_PED(&ped);
	}
	return;
}
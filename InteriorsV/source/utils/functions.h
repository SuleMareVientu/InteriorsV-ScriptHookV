#pragma once

//char* ToString(Any var);
void Print(char* string, int ms);
void PrintInt(int value, int ms);
void PrintFloat(float value, int ms);
void PrintHelp(char* string);
void LoadIPL(char* ipl);
void UnloadIPL(char* ipl);
void EnableInterior(int interior);
void DisableInterior(int interior);
void SetDoorState(Hash DoorHash, int state, bool requestDoor = false, bool forceUpdate = false);
void SetDoorStateAtCoords(Hash EntityHash, float x, float y, float z, int state, bool forceUpdate = false, bool requestDoor = false);
void SetAutoDoorState(Hash doorHash, int state, float rate = -1.0f, float distance = -1.0f, bool forceUpdate = false);
void SetSlidingDoorsStateAtCoords(Hash EntityHash, float x1, float y1, float z1, float x2, float y2, float z2, bool state, float openRatio, float minDistance, float maxDistance, bool removeSpring = true);
void SetSingleSlidingDoorStateAtCoords(Hash EntityHash, float x, float y, float z, float offsetX, float offsetY, bool state, float openRatio, float minDistance, float maxDistance, bool removeSpring = true);
void SetSpecialGatesStateAtCoords(Hash EntityHash, Hash SecondaryEntityHash, float x1, float y1, float z1, float x2, float y2, float z2, bool state, float openRatio, float minDistance, float maxDistance, bool removeSpring = true);
bool DeleteObjectAtCoords(Hash EntityHash, float x, float y, float z, float radius = 0.5f);
void DeleteScenarioPedAtCoords(float x, float y, float z, char* scenario);
void SetObjectYawAtCoords(Hash hash, float x, float y, float z, float yaw);
void EnableInteriorProp(int interior, char* prop, bool refresh);
void DisableInteriorProp(int interior, char* prop, bool refresh);
void SetScenarioGroup(char* scenarioGroup, bool toggle);
void AddBlip(float x, float y, float z, float scale, char* title, int id, int colour);
bool AdditionalChecks(Ped ped);
bool Teleport(float x, float y, float z, float heading, float headingOut, float markerX, float markerY, float markerZ, int red, int green, int blue, int alpha, char* text, char* textOut, bool overlapCheck);
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
void AltUnlockDoor(Hash EntityHash, float x, float y, float z);
void ForceUnlockDoor(Hash EntityHash, float x, float y, float z, int seed);
void SetDoorUnlockDistance(Hash EntityHash, float x, float y, float z, float distance);
void SetDoorUnlockDistanceWithRate(Hash EntityHash, float x, float y, float z, float rate, float distance);
void DeleteObjectAtCoords(Hash EntityHash, float x, float y, float z);
void DeletePedAtCoords(float x, float y, float z);
void DeleteScenarioPedAtCoords(float x, float y, float z, char* scenario);
void EnableInteriorProp(int interior, char* prop, bool refresh);
void DisableInteriorProp(int interior, char* prop, bool refresh);
void SetScenarioGroup(char* scenarioGroup, bool toggle);
void AddBlip(float x, float y, float z, float scale, char* title, int id, int colour);
bool AdditionalChecks(Ped ped);
bool Teleport(float x, float y, float z, float heading, float headingOut, float markerX, float markerY, float markerZ, int red, int green, int blue, int alpha, char* text, char* textOut, bool overlapCheck);
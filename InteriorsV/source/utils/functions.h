#pragma once

//char* ToString(Any var);
void Print(char* string, int ms);
void LoadIPL(char* ipl);
void UnloadIPL(char* ipl);
void EnableInterior(int interior);
void AltUnlockDoor(Hash EntityHash, float x, float y, float z);
void ForceUnlockDoor(Hash EntityHash, float x, float y, float z, int seed);
void DeleteObject(Hash EntityHash, float x, float y, float z);
void EnableInteriorProp(int interior, char* prop, bool refresh);
void DisableInteriorProp(int interior, char* prop, bool refresh);
void SetScenarioGroup(char* scenarioGroup, bool toggle);
void AddBlip(float x, float y, float z, float scale, char* title, int id, int colour);
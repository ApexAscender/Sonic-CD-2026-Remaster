#ifndef O_DAGARDEN_CHARACTERSPAWN_H
#define O_DAGARDEN_CHARACTERSPAWN_H

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS
#include "NativeScriptOps.hpp"

namespace O_DAGarden_CharacterSpawn {
void ObjectMain();
void CharacterSpawn_SpawnBlueBird();
void CharacterSpawn_SpawnShootStar();
void CharacterSpawn_SpawnSetup();
extern const Native::NativeFunctionDef funcs[3];
}

#endif
#endif // O_DAGARDEN_CHARACTERSPAWN_H

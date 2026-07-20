#ifndef O_R5_BOSSPLATFORM_H
#define O_R5_BOSSPLATFORM_H

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS
#include "NativeScriptOps.hpp"

namespace O_R5_BossPlatform {
void ObjectStartup();
void ObjectMain();
void ObjectPlayerInteraction();
void ObjectDraw();
void BossPlatform_Conveyor_Update();
void BossPlatform_Conveyor_WindDown();
void BossPlatform_SpawnLandingSparks();
extern const Native::NativeFunctionDef funcs[3];
}

#endif
#endif // O_R5_BOSSPLATFORM_H

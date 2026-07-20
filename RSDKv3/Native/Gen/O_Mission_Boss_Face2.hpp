#ifndef O_MISSION_BOSS_FACE2_H
#define O_MISSION_BOSS_FACE2_H

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS
#include "NativeScriptOps.hpp"

namespace O_Mission_Boss_Face2 {
void ObjectStartup();
void ObjectMain();
void ObjectPlayerInteraction();
void ObjectDraw();
void R1_EGGMAN2_Oscillation();
extern const Native::NativeFunctionDef funcs[1];
}

#endif
#endif // O_MISSION_BOSS_FACE2_H

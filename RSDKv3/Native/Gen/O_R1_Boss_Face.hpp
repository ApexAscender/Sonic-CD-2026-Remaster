#ifndef O_R1_BOSS_FACE_H
#define O_R1_BOSS_FACE_H

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS
#include "NativeScriptOps.hpp"

namespace O_R1_Boss_Face {
void ObjectStartup();
void ObjectMain();
void ObjectPlayerInteraction();
void ObjectDraw();
void R1_EGGMAN_Oscillation();
extern const Native::NativeFunctionDef funcs[1];
}

#endif
#endif // O_R1_BOSS_FACE_H

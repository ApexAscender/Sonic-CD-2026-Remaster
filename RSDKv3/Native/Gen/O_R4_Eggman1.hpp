#ifndef O_R4_EGGMAN1_H
#define O_R4_EGGMAN1_H

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS
#include "NativeScriptOps.hpp"

namespace O_R4_Eggman1 {
void ObjectStartup();
void ObjectMain();
void ObjectPlayerInteraction();
void ObjectDraw();
void ChaseEggman_Oscillation();
extern const Native::NativeFunctionDef funcs[1];
}

#endif
#endif // O_R4_EGGMAN1_H

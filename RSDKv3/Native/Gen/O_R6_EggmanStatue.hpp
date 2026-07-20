#ifndef O_R6_EGGMANSTATUE_H
#define O_R6_EGGMANSTATUE_H

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS
#include "NativeScriptOps.hpp"

namespace O_R6_EggmanStatue {
void ObjectStartup();
void ObjectMain();
void ObjectPlayerInteraction();
void ObjectDraw();
void EggmanStatue_HandleBombDrop();
extern const Native::NativeFunctionDef funcs[1];
}

#endif
#endif // O_R6_EGGMANSTATUE_H

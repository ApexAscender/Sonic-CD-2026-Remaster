#ifndef O_R4_HORIZONTALDOOR_H
#define O_R4_HORIZONTALDOOR_H

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS
#include "NativeScriptOps.hpp"

namespace O_R4_HorizontalDoor {
void ObjectStartup();
void ObjectMain();
void ObjectPlayerInteraction();
void ObjectDraw();
void HorizontalDoor_CheckClose();
extern const Native::NativeFunctionDef funcs[1];
}

#endif
#endif // O_R4_HORIZONTALDOOR_H

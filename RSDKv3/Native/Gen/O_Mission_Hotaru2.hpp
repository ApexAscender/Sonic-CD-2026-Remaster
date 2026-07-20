#ifndef O_MISSION_HOTARU2_H
#define O_MISSION_HOTARU2_H

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS
#include "NativeScriptOps.hpp"

namespace O_Mission_Hotaru2 {
void ObjectStartup();
void ObjectMain();
void ObjectPlayerInteraction();
void ObjectDraw();
void Hotaru2_Set_Destination();
extern const Native::NativeFunctionDef funcs[1];
}

#endif
#endif // O_MISSION_HOTARU2_H

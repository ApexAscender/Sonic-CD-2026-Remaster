#ifndef O_R4_WATER_H
#define O_R4_WATER_H

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS
#include "NativeScriptOps.hpp"

namespace O_R4_Water {
void ObjectStartup();
void ObjectMain();
void ObjectDraw();
void Water_CreateAirBubble();
void Water_CreateCountBubble();
extern const Native::NativeFunctionDef funcs[2];
}

#endif
#endif // O_R4_WATER_H

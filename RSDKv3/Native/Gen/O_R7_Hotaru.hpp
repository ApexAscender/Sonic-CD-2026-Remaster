#ifndef O_R7_HOTARU_H
#define O_R7_HOTARU_H

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS
#include "NativeScriptOps.hpp"

namespace O_R7_Hotaru {
void ObjectStartup();
void ObjectMain();
void ObjectPlayerInteraction();
void ObjectDraw();
void Hotaru_HotaruBreak();
extern const Native::NativeFunctionDef funcs[1];
}

#endif
#endif // O_R7_HOTARU_H

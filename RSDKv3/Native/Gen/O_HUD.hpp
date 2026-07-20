#ifndef O_HUD_H
#define O_HUD_H

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS
#include "NativeScriptOps.hpp"

namespace O_HUD {
void ObjectStartup();
void ObjectDraw();
void HUD_DrawStandard();
void HUD_DrawMobile();
extern const Native::NativeFunctionDef funcs[2];
}

#endif
#endif // O_HUD_H

#ifndef O_TOUCHCONTROLS_H
#define O_TOUCHCONTROLS_H

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS
#include "NativeScriptOps.hpp"

namespace O_TouchControls {
void ObjectStartup();
void ObjectMain();
void ObjectDraw();
void DebugMode_ChangeItem();
extern const Native::NativeFunctionDef funcs[1];
}

#endif
#endif // O_TOUCHCONTROLS_H

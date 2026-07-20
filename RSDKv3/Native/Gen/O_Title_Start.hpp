#ifndef O_TITLE_START_H
#define O_TITLE_START_H

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS
#include "NativeScriptOps.hpp"

namespace O_Title_Start {
void ObjectStartup();
void ObjectMain();
void ObjectDraw();
void TouchStart_HandleCheatCodes();
extern const Native::NativeFunctionDef funcs[1];
}

#endif
#endif // O_TITLE_START_H

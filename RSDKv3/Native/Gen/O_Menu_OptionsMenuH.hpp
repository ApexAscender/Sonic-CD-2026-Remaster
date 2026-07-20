#ifndef O_MENU_OPTIONSMENUH_H
#define O_MENU_OPTIONSMENUH_H

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS
#include "NativeScriptOps.hpp"

namespace O_Menu_OptionsMenuH {
void ObjectStartup();
void ObjectMain();
void ObjectDraw();
void OptionsMenuH_DrawOptions();
extern const Native::NativeFunctionDef funcs[1];
}

#endif
#endif // O_MENU_OPTIONSMENUH_H

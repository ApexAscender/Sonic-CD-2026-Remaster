#ifndef O_MENU_OPTIONSMENU_H
#define O_MENU_OPTIONSMENU_H

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS
#include "NativeScriptOps.hpp"

namespace O_Menu_OptionsMenu {
void ObjectStartup();
void ObjectMain();
void ObjectDraw();
void OptionsMenu_DrawOptions();
extern const Native::NativeFunctionDef funcs[1];
}

#endif
#endif // O_MENU_OPTIONSMENU_H

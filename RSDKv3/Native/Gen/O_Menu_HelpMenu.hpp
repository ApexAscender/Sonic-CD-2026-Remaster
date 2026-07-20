#ifndef O_MENU_HELPMENU_H
#define O_MENU_HELPMENU_H

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS
#include "NativeScriptOps.hpp"

namespace O_Menu_HelpMenu {
void ObjectStartup();
void ObjectMain();
void ObjectDraw();
void HelpMenu_PageLoad();
extern const Native::NativeFunctionDef funcs[1];
}

#endif
#endif // O_MENU_HELPMENU_H

#ifndef O_MENU_EXTRASMENU_H
#define O_MENU_EXTRASMENU_H

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS
#include "NativeScriptOps.hpp"

namespace O_Menu_ExtrasMenu {
void ObjectStartup();
void ObjectMain();
void ObjectDraw();
void ExtrasMenu_DrawUnlocks();
extern const Native::NativeFunctionDef funcs[1];
}

#endif
#endif // O_MENU_EXTRASMENU_H

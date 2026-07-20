#ifndef O_MENU_MENUBUTTON_H
#define O_MENU_MENUBUTTON_H

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS
#include "NativeScriptOps.hpp"

namespace O_Menu_MenuButton {
void ObjectStartup();
void ObjectMain();
void ObjectDraw();
void MenuButton_SetupMenuWindow();
extern const Native::NativeFunctionDef funcs[1];
}

#endif
#endif // O_MENU_MENUBUTTON_H

#ifndef O_MENU_MENUHEADING_H
#define O_MENU_MENUHEADING_H

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS
#include "NativeScriptOps.hpp"

namespace O_Menu_MenuHeading {
void ObjectStartup();
void ObjectMain();
void ObjectDraw();
void MenuHeading_CheckTouchBack();
extern const Native::NativeFunctionDef funcs[1];
}

#endif
#endif // O_MENU_MENUHEADING_H

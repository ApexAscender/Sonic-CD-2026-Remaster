#ifndef O_MENU_MENUWINDOW_H
#define O_MENU_MENUWINDOW_H

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS
#include "NativeScriptOps.hpp"

namespace O_Menu_MenuWindow {
void ObjectStartup();
void ObjectMain();
void ObjectDraw();
}

#endif
#endif // O_MENU_MENUWINDOW_H

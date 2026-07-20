#ifndef O_MENU_LOADSAVEMENU_H
#define O_MENU_LOADSAVEMENU_H

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS
#include "NativeScriptOps.hpp"

namespace O_Menu_LoadSaveMenu {
void ObjectStartup();
void ObjectMain();
void ObjectDraw();
void LoadSaveMenu_DrawSaveFiles();
void LoadSaveMenu_DrawDeleteNoSave();
void LoadSaveMenu_CheckTouchSave();
void LoadSaveMenu_SetShowDelete();
extern const Native::NativeFunctionDef funcs[4];
}

#endif
#endif // O_MENU_LOADSAVEMENU_H

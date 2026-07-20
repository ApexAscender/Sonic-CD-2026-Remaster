#ifndef O_MENU_DEMOMENU_H
#define O_MENU_DEMOMENU_H

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS
#include "NativeScriptOps.hpp"

namespace O_Menu_DemoMenu {
void ObjectStartup();
void ObjectMain();
void ObjectDraw();
void DemoMenu_StageTimeRecord();
void DemoMenu_StageTotalTimeRecord();
void DemoMenu_StagePortraitMovement();
extern const Native::NativeFunctionDef funcs[3];
}

#endif
#endif // O_MENU_DEMOMENU_H

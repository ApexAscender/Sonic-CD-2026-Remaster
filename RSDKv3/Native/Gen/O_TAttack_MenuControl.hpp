#ifndef O_TATTACK_MENUCONTROL_H
#define O_TATTACK_MENUCONTROL_H

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS
#include "NativeScriptOps.hpp"

namespace O_TAttack_MenuControl {
void ObjectStartup();
void ObjectMain();
void ObjectDraw();
void MenuControl_IconTransitions();
void MenuControl_DefaultRecord();
void MenuControl_ZoneUnlockCheck();
void MenuControl_TotalRegularRecord();
void MenuControl_TotalSpecialRecord();
extern const Native::NativeFunctionDef funcs[5];
}

#endif
#endif // O_TATTACK_MENUCONTROL_H

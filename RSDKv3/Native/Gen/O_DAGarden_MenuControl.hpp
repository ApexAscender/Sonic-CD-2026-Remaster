#ifndef O_DAGARDEN_MENUCONTROL_H
#define O_DAGARDEN_MENUCONTROL_H

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS
#include "NativeScriptOps.hpp"

namespace O_DAGarden_MenuControl {
void ObjectStartup();
void ObjectMain();
void MenuControl_ChangeTrack();
extern const Native::NativeFunctionDef funcs[1];
}

#endif
#endif // O_DAGARDEN_MENUCONTROL_H

#ifndef O_SPECIAL_SPECIALSETUP_H
#define O_SPECIAL_SPECIALSETUP_H

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS
#include "NativeScriptOps.hpp"

namespace O_Special_SpecialSetup {
void ObjectStartup();
void ObjectMain();
void ObjectDraw();
}

#endif
#endif // O_SPECIAL_SPECIALSETUP_H

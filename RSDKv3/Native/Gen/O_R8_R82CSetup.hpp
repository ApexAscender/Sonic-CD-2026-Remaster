#ifndef O_R8_R82CSETUP_H
#define O_R8_R82CSETUP_H

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS
#include "NativeScriptOps.hpp"

namespace O_R8_R82CSetup {
void ObjectStartup();
void ObjectMain();
void ObjectPlayerInteraction();
}

#endif
#endif // O_R8_R82CSETUP_H

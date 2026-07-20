#ifndef O_R8_R82ASETUP_H
#define O_R8_R82ASETUP_H

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS
#include "NativeScriptOps.hpp"

namespace O_R8_R82ASetup {
void ObjectStartup();
void ObjectMain();
void ObjectPlayerInteraction();
}

#endif
#endif // O_R8_R82ASETUP_H

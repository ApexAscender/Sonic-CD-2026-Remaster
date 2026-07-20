#ifndef O_R8_R82DSETUP_H
#define O_R8_R82DSETUP_H

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS
#include "NativeScriptOps.hpp"

namespace O_R8_R82DSetup {
void ObjectStartup();
void ObjectMain();
void ObjectPlayerInteraction();
}

#endif
#endif // O_R8_R82DSETUP_H

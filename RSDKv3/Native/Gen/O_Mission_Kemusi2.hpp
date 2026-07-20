#ifndef O_MISSION_KEMUSI2_H
#define O_MISSION_KEMUSI2_H

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS
#include "NativeScriptOps.hpp"

namespace O_Mission_Kemusi2 {
void ObjectStartup();
void ObjectMain();
void ObjectPlayerInteraction();
void ObjectDraw();
}

#endif
#endif // O_MISSION_KEMUSI2_H

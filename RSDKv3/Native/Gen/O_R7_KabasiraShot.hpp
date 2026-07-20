#ifndef O_R7_KABASIRASHOT_H
#define O_R7_KABASIRASHOT_H

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS
#include "NativeScriptOps.hpp"

namespace O_R7_KabasiraShot {
void ObjectStartup();
void ObjectMain();
void ObjectPlayerInteraction();
void ObjectDraw();
}

#endif
#endif // O_R7_KABASIRASHOT_H

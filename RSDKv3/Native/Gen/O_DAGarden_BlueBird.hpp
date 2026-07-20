#ifndef O_DAGARDEN_BLUEBIRD_H
#define O_DAGARDEN_BLUEBIRD_H

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS
#include "NativeScriptOps.hpp"

namespace O_DAGarden_BlueBird {
void ObjectStartup();
void ObjectMain();
void ObjectDraw();
}

#endif
#endif // O_DAGARDEN_BLUEBIRD_H

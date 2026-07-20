#ifndef O_DAGARDEN_UFO_H
#define O_DAGARDEN_UFO_H

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS
#include "NativeScriptOps.hpp"

namespace O_DAGarden_UFO {
void ObjectStartup();
void ObjectMain();
void ObjectDraw();
}

#endif
#endif // O_DAGARDEN_UFO_H

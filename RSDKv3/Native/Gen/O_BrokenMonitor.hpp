#ifndef O_BROKENMONITOR_H
#define O_BROKENMONITOR_H

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS
#include "NativeScriptOps.hpp"

namespace O_BrokenMonitor {
void ObjectStartup();
void ObjectMain();
void ObjectDraw();
}

#endif
#endif // O_BROKENMONITOR_H

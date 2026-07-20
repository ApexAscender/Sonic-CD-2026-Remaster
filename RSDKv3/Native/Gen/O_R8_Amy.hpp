#ifndef O_R8_AMY_H
#define O_R8_AMY_H

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS
#include "NativeScriptOps.hpp"

namespace O_R8_Amy {
void ObjectStartup();
void ObjectMain();
void ObjectDraw();
}

#endif
#endif // O_R8_AMY_H

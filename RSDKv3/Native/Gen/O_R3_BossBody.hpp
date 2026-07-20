#ifndef O_R3_BOSSBODY_H
#define O_R3_BOSSBODY_H

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS
#include "NativeScriptOps.hpp"

namespace O_R3_BossBody {
void ObjectStartup();
void ObjectMain();
void ObjectPlayerInteraction();
void ObjectDraw();
void BossBody_LaunchBomb();
extern const Native::NativeFunctionDef funcs[1];
}

#endif
#endif // O_R3_BOSSBODY_H

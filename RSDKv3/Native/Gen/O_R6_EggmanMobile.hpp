#ifndef O_R6_EGGMANMOBILE_H
#define O_R6_EGGMANMOBILE_H

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS
#include "NativeScriptOps.hpp"

namespace O_R6_EggmanMobile {
void ObjectStartup();
void ObjectMain();
void ObjectPlayerInteraction();
void ObjectDraw();
void R6_EGG_DESCEND();
void R6_EGG_MOVE();
void R6_EGG_ROUTE_1ST_FLOOR();
void R6_EGG_ROUTE_2ST_FLOOR();
void R6_EGG_STEAM();
extern const Native::NativeFunctionDef funcs[5];
}

#endif
#endif // O_R6_EGGMANMOBILE_H

#ifndef O_CREDITS_CREDITSCONTROL_H
#define O_CREDITS_CREDITSCONTROL_H

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS
#include "NativeScriptOps.hpp"

namespace O_Credits_CreditsControl {
void ObjectStartup();
void ObjectMain();
void ObjectDraw();
}

#endif
#endif // O_CREDITS_CREDITSCONTROL_H

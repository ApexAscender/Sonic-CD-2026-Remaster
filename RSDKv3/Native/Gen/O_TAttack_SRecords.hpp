#ifndef O_TATTACK_SRECORDS_H
#define O_TATTACK_SRECORDS_H

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS
#include "NativeScriptOps.hpp"

namespace O_TAttack_SRecords {
void ObjectStartup();
void ObjectMain();
void ObjectDraw();
void SRecords_DrawRecords();
extern const Native::NativeFunctionDef funcs[1];
}

#endif
#endif // O_TATTACK_SRECORDS_H

#ifndef O_STAGESETUP_H
#define O_STAGESETUP_H

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS
#include "NativeScriptOps.hpp"

namespace O_StageSetup {
void ObjectStartup();
void ObjectMain();
void ObjectPlayerInteraction();
void StageSetup_CheckGoodFuture();
void StageSetup_SaveStageState();
void StageSetup_LoadStageState();
void EditorHelpers_DrawHitbox();
void EditorHelpers_DrawX();
void EditorHelpers_FindTimePeriod();
extern const Native::NativeFunctionDef funcs[6];
}

#endif
#endif // O_STAGESETUP_H

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R6_R6BounceFloor.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from R6BounceFloor.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R6_R6BounceFloor::ObjectStartup()
{
    objectEntityList[1000].type = TypeNameID("R6BounceFloor");
    objectEntityList[1000].priority = 1;
}

void O_R6_R6BounceFloor::ObjectPlayerInteraction()
{
    Entity *self = Self();

    scriptEng.tempValue[2] = pXPos();
    scriptEng.tempValue[2] >>= 16;
    scriptEng.tempValue[2] += pCollisionRight();
    scriptEng.tempValue[3] = pYPos();
    scriptEng.tempValue[3] >>= 16;
    scriptEng.tempValue[3] += pCollisionBottom();
    scriptEng.tempValue[3] += 2;
    scriptEng.tempValue[0] = Get16x16TileInfo_Script(scriptEng.tempValue[2], scriptEng.tempValue[3], 8);
    scriptEng.tempValue[2] = pXPos();
    scriptEng.tempValue[2] >>= 16;
    scriptEng.tempValue[2] += pCollisionLeft();
    scriptEng.tempValue[1] = Get16x16TileInfo_Script(scriptEng.tempValue[2], scriptEng.tempValue[3], 8);
    scriptEng.tempValue[0] |= scriptEng.tempValue[1];
    if (scriptEng.tempValue[0] == 1) {
        if (playerListPos == GVar("PLAYER_KNUCKLES")) {
            if (pState() == PlayerStateID("Player_State_LedgePullUp")) {
                scriptEng.tempValue[0] = 0;
                self->values[2] = 1;
            }
        }
    }
    if (scriptEng.tempValue[0] == 1) {
        if (objectEntityList[19].scale == 1) {
            if (pYVel() > -1) {
                pAnimation() = GVar("ANI_JUMPING");
                pGravity() = 1;
                pTimer() = 0;
                pYVel() = -0x160000;
                pState() = PlayerStateID("Player_State_Air_NoDropDash");
                PlaySfx(globalSFXCount + 0, 0);
            }
        }
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS

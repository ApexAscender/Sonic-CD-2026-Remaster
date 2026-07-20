#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R3_TubeSwitch.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from TubeSwitch.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R3_TubeSwitch::ObjectPlayerInteraction()
{
    Entity *self = Self();

    PlayerObjectCollision(C_TOUCH, -16, -16, 16, 16);
    if (CheckResult() == 1) {
        switch (self->propertyValue) {
            case 0:
            if (pSpeed() > 0) {
                pDirection() = 0;
                pState() = PlayerStateID("Player_State_TubeRoll");
                pAnimation() = GVar("ANI_JUMPING");
                PlayerValue(6) = 0xA0000;
                if (pSpeed() < 0xA0000) {
                    pSpeed() = 0xA0000;
                }
                if (pGravity() == 1) {
                    pGravity() = 0;
                    pYPos() = self->YPos;
                }
            } else {
                if (pGravity() == 0) {
                    if (pSpeed() > -0x20000) {
                        pSpeed() = -0x20000;
                    }
                }
                pState() = PlayerStateID("Player_State_Roll");
                pAnimation() = GVar("ANI_JUMPING");
            }
            break;
            case 1:
            if (pSpeed() < 0) {
                pState() = PlayerStateID("Player_State_TubeRoll");
                pAnimation() = GVar("ANI_JUMPING");
                PlayerValue(6) = 0xA0000;
                if (pSpeed() > -0xA0000) {
                    pSpeed() = -0xA0000;
                }
            } else {
                if (pGravity() == 0) {
                    if (pSpeed() < 0x20000) {
                        pSpeed() = 0x20000;
                    }
                }
                pState() = PlayerStateID("Player_State_Roll");
                pAnimation() = GVar("ANI_JUMPING");
            }
            break;
            case 2:
            if (self->values[0] == 0) {
                if (pGravity() == 1) {
                    pGravity() = 0;
                    pState() = PlayerStateID("Player_State_TubeRoll");
                    pAnimation() = GVar("ANI_JUMPING");
                    pCollisionMode() = 3;
                    pAngle() = 64;
                    pSpeed() = 0x100000;
                    PlayerValue(6) = 0x100000;
                } else {
                    if (pSpeed() > 0) {
                        pGravity() = 0;
                        pState() = PlayerStateID("Player_State_TubeRoll");
                        pAnimation() = GVar("ANI_JUMPING");
                        pCollisionMode() = 3;
                        pAngle() = 64;
                        pSpeed() = 0x100000;
                        PlayerValue(6) = 0x100000;
                    } else {
                        pGravity() = 1;
                        pYVel() = pSpeed();
                        pSpeed() = 0;
                        pXVel() = 0;
                    }
                }
            }
            break;
            case 3:
            if (self->values[0] == 0) {
                if (pGravity() == 1) {
                    pGravity() = 0;
                    pState() = PlayerStateID("Player_State_TubeRoll");
                    pAnimation() = GVar("ANI_JUMPING");
                    pCollisionMode() = 3;
                    pAngle() = 64;
                    pSpeed() = -0xA0000;
                    PlayerValue(6) = 0xA0000;
                }
                if (pCollisionMode() == 3) {
                    if (pSpeed() < 0) {
                        pGravity() = 0;
                        pState() = PlayerStateID("Player_State_TubeRoll");
                        pAnimation() = GVar("ANI_JUMPING");
                        pCollisionMode() = 3;
                        pAngle() = 64;
                        pSpeed() = -0xA0000;
                        PlayerValue(6) = 0xA0000;
                    } else {
                        pGravity() = 1;
                        pYVel() = pSpeed();
                        pSpeed() = 0;
                        pXVel() = 0;
                    }
                }
            }
            break;
            case 4:
            if (pGravity() == 0) {
                pState() = PlayerStateID("Player_State_Roll");
            } else {
                pXPos() = self->XPos;
            }
            if (pAnimation() != GVar("ANI_JUMPING")) {
                pAnimation() = GVar("ANI_JUMPING");
                PlayerValue(2) = 240;
            }
            break;
            case 5:
            if (self->values[0] == 0) {
                if (pYVel() > 0) {
                    pState() = PlayerStateID("Player_State_TubeRoll");
                    pAnimation() = GVar("ANI_JUMPING");
                    pGravity() = 0;
                    pCollisionMode() = 3;
                    pAngle() = 64;
                    pSpeed() = 0x100000;
                    PlayerValue(6) = 0x100000;
                }
            } else {
                if (pState() == PlayerStateID("Player_State_Air")) {
                    pAnimation() = GVar("ANI_JUMPING");
                }
            }
            break;
            case 6:
            if (self->values[0] == 0) {
                if (pGravity() == 1) {
                    pGravity() = 0;
                    pState() = PlayerStateID("Player_State_TubeRoll");
                    pAnimation() = GVar("ANI_JUMPING");
                    pCollisionMode() = 3;
                    pAngle() = 64;
                    pSpeed() = 0x100000;
                    PlayerValue(6) = 0x100000;
                } else {
                    pGravity() = 1;
                    pYVel() = pSpeed();
                    pYVel() = -pYVel();
                    pSpeed() = 0;
                    pXVel() = 0;
                }
            }
            break;
            case 7:
            if (self->values[0] == 0) {
                if (pYVel() > 0) {
                    pGravity() = 0;
                    pState() = PlayerStateID("Player_State_TubeRoll");
                    pAnimation() = GVar("ANI_JUMPING");
                    pCollisionMode() = 1;
                    pAngle() = 192;
                    pSpeed() = -0x100000;
                    PlayerValue(6) = 0x100000;
                }
            } else {
                pAnimation() = GVar("ANI_JUMPING");
            }
            break;
            case 8:
            if (pState() != PlayerStateID("Player_State_Fly")) {
                if (pGravity() == 0) {
                    pState() = PlayerStateID("Player_State_Roll");
                }
                pAnimation() = GVar("ANI_JUMPING");
            }
            break;
            case 9:
            if (self->values[0] == 0) {
                if (pYVel() > 0) {
                    pGravity() = 0;
                    pState() = PlayerStateID("Player_State_TubeRoll");
                    pAnimation() = GVar("ANI_JUMPING");
                    pCollisionMode() = 3;
                    pAngle() = 64;
                    pSpeed() = 0x80000;
                    PlayerValue(6) = 0x80000;
                }
            } else {
                pAnimation() = GVar("ANI_JUMPING");
            }
            break;
            case 10:
            if (self->values[0] == 0) {
                if (pGravity() == 0) {
                    pGravity() = 1;
                    pYVel() = pSpeed();
                    pSpeed() = 0;
                    pXVel() = 0;
                }
            }
            break;
            case 11:
            if (pYVel() > 0) {
                if (pXPos() > self->XPos) {
                    scriptEng.tempValue[0] = pXPos();
                    scriptEng.tempValue[0] -= self->XPos;
                    if (scriptEng.tempValue[0] < 0x60000) {
                        pGravity() = 1;
                        pYVel() = -0x30000;
                    }
                } else {
                    scriptEng.tempValue[0] = self->XPos;
                    scriptEng.tempValue[0] -= pXPos();
                    if (scriptEng.tempValue[0] < 0x60000) {
                        pGravity() = 1;
                        pYVel() = -0x30000;
                    }
                }
            }
            break;
            case 12:
            if (pState() != PlayerStateID("Player_State_Fly")) {
                if (pXVel() > 0x40000) {
                    if (pGravity() == 0) {
                        pState() = PlayerStateID("Player_State_Roll");
                    }
                    pAnimation() = GVar("ANI_JUMPING");
                }
            }
            break;
        }
        self->values[0] = 1;
    } else {
        self->values[0] = 0;
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS

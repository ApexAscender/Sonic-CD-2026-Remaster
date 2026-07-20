#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R4_WaterTrigger.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from WaterTrigger.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R4_WaterTrigger::ObjectPlayerInteraction()
{
    Entity *self = Self();

    switch (self->propertyValue) {
        case 0:
        if (objectEntityList[objectLoop - 1].propertyValue == 1) {
            PlayerObjectCollision(C_TOUCH, -112, -64, 0, 160);
            if (CheckResult() == 1) {
                if (pState() != PlayerStateID("Player_State_Death")) {
                    if (pState() != PlayerStateID("Player_State_Drown")) {
                        pState() = PlayerStateID("Player_State_WaterCurrent");
                        pAnimation() = GVar("ANI_FANROTATE");
                        pControlMode() = -1;
                        pLeft() = 0;
                        pRight() = 0;
                        pUp() = 0;
                        pDown() = 0;
                        if (pYPos() < self->YPos) {
                            pXVel() = -0x40000;
                            pSpeed() = -0x40000;
                        } else {
                            pXVel() = 0;
                            pSpeed() = 0;
                        }
                        pYVel() = -0x40000;
                    }
                }
            } else {
                if (pState() == PlayerStateID("Player_State_WaterCurrent")) {
                    pState() = PlayerStateID("Player_State_Air");
                    pControlMode() = 0;
                    pAnimation() = GVar("ANI_WALKING");
                }
            }
        }
        break;
        case 1:
        PlayerObjectCollision(C_TOUCH, -128, 0, 112, 64);
        if (CheckResult() == 1) {
            if (pState() != PlayerStateID("Player_State_Death")) {
                if (pState() != PlayerStateID("Player_State_Drown")) {
                    pState() = PlayerStateID("Player_State_WaterCurrent");
                    pAnimation() = GVar("ANI_FANROTATE");
                    pControlMode() = -1;
                    pLeft() = 0;
                    pRight() = 0;
                    pUp() = 0;
                    pDown() = 0;
                    pXVel() = 0x60000;
                    pSpeed() = 0x60000;
                    pYVel() = 0x20000;
                }
            }
        } else {
            if (pState() == PlayerStateID("Player_State_WaterCurrent")) {
                scriptEng.tempValue[0] = self->XPos;
                scriptEng.tempValue[0] += 0x840000;
                if (pXPos() > scriptEng.tempValue[0]) {
                    pState() = PlayerStateID("Player_State_Air");
                    pControlMode() = 0;
                    pAnimation() = GVar("ANI_WALKING");
                }
            }
        }
        break;
        case 2:
        PlayerObjectCollision(C_TOUCH, -128, 0, 112, 64);
        if (CheckResult() == 1) {
            if (pState() != PlayerStateID("Player_State_Death")) {
                if (pState() != PlayerStateID("Player_State_Drown")) {
                    pState() = PlayerStateID("Player_State_WaterCurrent");
                    pAnimation() = GVar("ANI_FANROTATE");
                    pControlMode() = -1;
                    pLeft() = 0;
                    pRight() = 0;
                    pUp() = 0;
                    pDown() = 0;
                    pXVel() = -0x60000;
                    pSpeed() = -0x60000;
                    pYVel() = 0x20000;
                }
            }
        } else {
            if (pState() == PlayerStateID("Player_State_WaterCurrent")) {
                scriptEng.tempValue[0] = self->XPos;
                scriptEng.tempValue[0] += 0x840000;
                if (pXPos() > scriptEng.tempValue[0]) {
                    pState() = PlayerStateID("Player_State_Air");
                    pControlMode() = 0;
                    pAnimation() = GVar("ANI_WALKING");
                }
            }
        }
        break;
        case 3:
        PlayerObjectCollision(C_TOUCH, -128, 0, 112, 64);
        if (CheckResult() == 1) {
            if (pState() != PlayerStateID("Player_State_Death")) {
                if (pState() != PlayerStateID("Player_State_Drown")) {
                    pState() = PlayerStateID("Player_State_WaterCurrent");
                    pAnimation() = GVar("ANI_FANROTATE");
                    pControlMode() = -1;
                    pLeft() = 0;
                    pRight() = 0;
                    pUp() = 0;
                    pDown() = 0;
                    pXVel() = -0x60000;
                    pSpeed() = -0x60000;
                    pYVel() = 0x20000;
                }
            }
        } else {
            if (pYPos() > self->YPos) {
                if (pState() == PlayerStateID("Player_State_WaterCurrent")) {
                    pState() = PlayerStateID("Player_State_Air");
                    pControlMode() = 0;
                    pAnimation() = GVar("ANI_WALKING");
                }
            }
        }
        break;
        case 4:
        PlayerObjectCollision(C_TOUCH, 0, -64, 256, 64);
        if (CheckResult() == 1) {
            if (pState() != PlayerStateID("Player_State_Death")) {
                if (pState() != PlayerStateID("Player_State_Drown")) {
                    pState() = PlayerStateID("Player_State_WaterCurrent");
                    pAnimation() = GVar("ANI_FANROTATE");
                    pXVel() = 0x40000;
                    pSpeed() = 0x40000;
                    pYVel() = 0;
                }
            }
        }
        break;
        case 5:
        PlayerObjectCollision(C_TOUCH, -64, -160, 64, 0);
        if (CheckResult() == 1) {
            if (pState() != PlayerStateID("Player_State_Death")) {
                if (pState() != PlayerStateID("Player_State_Drown")) {
                    pState() = PlayerStateID("Player_State_WaterCurrent");
                    pAnimation() = GVar("ANI_FANROTATE");
                    pControlMode() = -1;
                    pLeft() = 0;
                    pRight() = 0;
                    pUp() = 0;
                    pDown() = 0;
                    if (pXPos() < self->XPos) {
                        pXVel() = 0x40000;
                        pSpeed() = 0x40000;
                    } else {
                        pXVel() = 0;
                        pSpeed() = 0;
                    }
                    pYVel() = 0x40000;
                }
            }
        } else {
            if (pYPos() > self->YPos) {
                if (pState() == PlayerStateID("Player_State_WaterCurrent")) {
                    pState() = PlayerStateID("Player_State_Air");
                    pAngle() = 0;
                    pControlMode() = 0;
                    pAnimation() = GVar("ANI_WALKING");
                }
            }
        }
        break;
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS

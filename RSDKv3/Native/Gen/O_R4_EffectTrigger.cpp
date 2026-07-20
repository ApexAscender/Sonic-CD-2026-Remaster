#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R4_EffectTrigger.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from EffectTrigger.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R4_EffectTrigger::ObjectMain()
{
    Entity *self = Self();

    switch (self->propertyValue) {
        case 0:
        if (pXPos() < 0x2800000) {
            activeTileLayers[0] = 1;
            self->type = TypeNameID("Blank Object");
            objectEntityList[19].type = TypeNameID("BGAnimation");
        }
        break;
        case 1:
        if (pYPos() > self->YPos) {
            activeTileLayers[0] = 2;
            objectEntityList[19].type = TypeNameID("BGAnimation");
        } else {
            activeTileLayers[0] = 1;
            objectEntityList[19].type = TypeNameID("BGAnimation");
        }
        break;
        case 2:
        if (pXPos() > self->XPos) {
            GVar("Stage.NewWaterLevel") = 0x2640000;
        } else {
            GVar("Stage.NewWaterLevel") = 0x2840000;
        }
        break;
        case 4:
        PlayerObjectCollision(C_TOUCH, -10, -16, 10, 16);
        if (CheckResult() == 1) {
            if (pState() != PlayerStateID("Player_State_Death")) {
                if (pState() != PlayerStateID("Player_State_Drown")) {
                    GVar("Warp.Timer") = 0;
                    pState() = PlayerStateID("Player_State_WaterCurrent");
                    pAnimation() = GVar("ANI_FANROTATE");
                    pXVel() = 0;
                    pYVel() = -0x40000;
                    if (pXPos() < self->XPos) {
                        pXPos() += 0x10000;
                    } else {
                        pXPos() -= 0x10000;
                    }
                }
            }
        } else {
            if (pState() == PlayerStateID("Player_State_WaterCurrent")) {
                PlayerObjectCollision(C_TOUCH, -64, -16, -32, 16);
                if (CheckResult() == 1) {
                    pState() = PlayerStateID("Player_State_Air");
                    pAnimation() = GVar("ANI_WALKING");
                }
                PlayerObjectCollision(C_TOUCH, 32, -16, 64, 16);
                if (CheckResult() == 1) {
                    pState() = PlayerStateID("Player_State_Air");
                    pAnimation() = GVar("ANI_WALKING");
                }
            }
        }
        break;
        case 5:
        PlayerObjectCollision(C_TOUCH, -10, -16, 10, 16);
        if (CheckResult() == 1) {
            if (pState() != PlayerStateID("Player_State_Death")) {
                if (pState() != PlayerStateID("Player_State_Drown")) {
                    GVar("Warp.Timer") = 0;
                    pState() = PlayerStateID("Player_State_WaterCurrent");
                    pAnimation() = GVar("ANI_FANROTATE");
                    pXVel() = 0;
                    pYVel() = 0x40000;
                    if (pXPos() < self->XPos) {
                        pXPos() += 0x10000;
                    } else {
                        pXPos() -= 0x10000;
                    }
                }
            }
        } else {
            if (pState() == PlayerStateID("Player_State_WaterCurrent")) {
                PlayerObjectCollision(C_TOUCH, -64, -16, -32, 16);
                if (CheckResult() == 1) {
                    pState() = PlayerStateID("Player_State_Ground");
                    pAnimation() = GVar("ANI_WALKING");
                }
                PlayerObjectCollision(C_TOUCH, 32, -16, 64, 16);
                if (CheckResult() == 1) {
                    pState() = PlayerStateID("Player_State_Ground");
                    pAnimation() = GVar("ANI_WALKING");
                }
            }
        }
        break;
        case 6:
        PlayerObjectCollision(C_TOUCH, -16, -16, 16, 16);
        if (CheckResult() == 1) {
            if (pState() != PlayerStateID("Player_State_Death")) {
                if (pState() != PlayerStateID("Player_State_Drown")) {
                    pXVel() = -0x40000;
                    pAnimation() = GVar("ANI_FANROTATE");
                }
            }
        }
        break;
        case 7:
        PlayerObjectCollision(C_TOUCH, -16, -16, 16, 16);
        if (CheckResult() == 1) {
            if (pState() != PlayerStateID("Player_State_Death")) {
                if (pState() != PlayerStateID("Player_State_Drown")) {
                    pXVel() = 0x40000;
                    pAnimation() = GVar("ANI_FANROTATE");
                }
            }
        }
        break;
        case 8:
        PlayerObjectCollision(C_TOUCH, -16, -16, 16, 16);
        if (CheckResult() == 1) {
            if (pState() != PlayerStateID("Player_State_Death")) {
                if (pState() != PlayerStateID("Player_State_Drown")) {
                    pYVel() = -0x40000;
                    pAnimation() = GVar("ANI_FANROTATE");
                }
            }
        }
        break;
        case 9:
        PlayerObjectCollision(C_TOUCH, -16, -16, 16, 16);
        if (CheckResult() == 1) {
            if (pState() != PlayerStateID("Player_State_Death")) {
                if (pState() != PlayerStateID("Player_State_Drown")) {
                    pYVel() = 0x40000;
                    pAnimation() = GVar("ANI_FANROTATE");
                }
            }
        }
        break;
        case 10:
        PlayerObjectCollision(C_TOUCH, -16, -16, 16, 16);
        if (CheckResult() == 1) {
            if (pState() != PlayerStateID("Player_State_Death")) {
                if (pState() != PlayerStateID("Player_State_Drown")) {
                    pXVel() = 0;
                }
            }
        }
        break;
        case 11:
        PlayerObjectCollision(C_TOUCH, -16, -16, 16, 16);
        if (CheckResult() == 1) {
            if (pState() != PlayerStateID("Player_State_Death")) {
                if (pState() != PlayerStateID("Player_State_Drown")) {
                    pYVel() = 0;
                }
            }
        }
        break;
        case 12:
        PlayerObjectCollision(C_TOUCH, -16, -16, 16, 16);
        if (CheckResult() == 1) {
            if (pState() != PlayerStateID("Player_State_Death")) {
                if (pState() != PlayerStateID("Player_State_Drown")) {
                    pYVel() = 0x40000;
                    pState() = PlayerStateID("Player_State_Air");
                    pAnimation() = GVar("ANI_WALKING");
                }
            }
        }
        break;
        case 13:
        if (pXPos() > self->XPos) {
            GVar("Stage.NewWaterLevel") = 0x7800000;
        } else {
            GVar("Stage.NewWaterLevel") = 0x5340000;
        }
        break;
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS

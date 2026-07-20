#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R5_TubeSwitch.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from TubeSwitch.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R5_TubeSwitch::ObjectPlayerInteraction()
{
    Entity *self = Self();

    PlayerObjectCollision(C_TOUCH, -16, -16, 16, 16);
    if (CheckResult() == 1) {
        switch (self->propertyValue) {
            case 0:
            if (pSpeed() >= 0) {
                if (pState() != PlayerStateID("Player_State_TubeRoll")) {
                    PlaySfx(6, 0);
                }
                pDirection() = 0;
                pState() = PlayerStateID("Player_State_TubeRoll");
                pAnimation() = GVar("ANI_JUMPING");
                PlayerValue(6) = 0x20000;
                if (pSpeed() < 0x20000) {
                    pSpeed() = 0x20000;
                }
            } else {
                if (pSpeed() > -0x20000) {
                    pSpeed() = -0x20000;
                }
                pState() = PlayerStateID("Player_State_Roll");
                pAnimation() = GVar("ANI_JUMPING");
            }
            break;
            case 1:
            if (pSpeed() <= 0) {
                if (pState() != PlayerStateID("Player_State_TubeRoll")) {
                    PlaySfx(6, 0);
                }
                pState() = PlayerStateID("Player_State_TubeRoll");
                pAnimation() = GVar("ANI_JUMPING");
                PlayerValue(6) = 0x80000;
                if (pSpeed() > -0x20000) {
                    pSpeed() = -0x20000;
                }
            } else {
                if (pSpeed() < 0x20000) {
                    pSpeed() = 0x20000;
                }
                pState() = PlayerStateID("Player_State_Roll");
                pAnimation() = GVar("ANI_JUMPING");
            }
            break;
            case 2:
            pGravity() = 1;
            pCollisionMode() = 0;
            pXVel() = 0;
            pSpeed() = 0;
            break;
            case 3:
            if (GVar("ConveyorBelt_Flag") == 0) {
                if (pYPos() < self->YPos) {
                    if (pState() != PlayerStateID("Player_State_Static")) {
                        PlaySfx(7, 0);
                    }
                    pState() = PlayerStateID("Player_State_Static");
                    if (pAnimation() != GVar("ANI_JUMPING")) {
                        pAnimation() = GVar("ANI_JUMPING");
                    }
                    PlayerValue(2) = 240;
                    pSpeed() = 0;
                    pTimer() = 0;
                    pXPos() = self->XPos;
                    pXVel() = 0;
                    pYVel() = 0xA0000;
                }
            } else {
                if (pState() == PlayerStateID("Player_State_Static")) {
                    pState() = PlayerStateID("Player_State_Air");
                }
            }
            break;
            case 4:
            if (GVar("ConveyorBelt_Flag") == 3) {
                if (pYPos() > self->YPos) {
                    if (GVar("Warp.Destination") > 0) {
                        if (GVar("Warp.Timer") == 0) {
                            GVar("Warp.Timer") = 1;
                            ResetObjectEntity(3, TypeNameID("Warp Star"), 0, pXPos(), pYPos());
                            objectEntityList[3].values[0] = 7;
                            objectEntityList[3].drawOrder = 4;
                        }
                    }
                    if (pState() != PlayerStateID("Player_State_Static")) {
                        PlaySfx(7, 0);
                    }
                    pState() = PlayerStateID("Player_State_Static");
                    if (pAnimation() != GVar("ANI_JUMPING")) {
                        pAnimation() = GVar("ANI_JUMPING");
                    }
                    PlayerValue(2) = 240;
                    pSpeed() = 0;
                    pTimer() = 0;
                    pXPos() = self->XPos;
                    pXVel() = 0;
                    pYVel() = -0x80000;
                }
            } else {
                if (pState() == PlayerStateID("Player_State_Static")) {
                    pState() = PlayerStateID("Player_State_Air");
                }
            }
            break;
            case 5:
            if (pYVel() < 0) {
                pGravity() = 0;
                pState() = PlayerStateID("Player_State_TubeRoll");
                pAnimation() = GVar("ANI_JUMPING");
                pCollisionMode() = 3;
                pAngle() = 64;
                pSpeed() = -0xA0000;
                PlayerValue(6) = 0xA0000;
            }
            break;
            case 6:
            if (pYVel() > 0) {
                pGravity() = 0;
                pState() = PlayerStateID("Player_State_TubeRoll");
                pAnimation() = GVar("ANI_JUMPING");
                pCollisionMode() = 3;
                pAngle() = 64;
                pSpeed() = pYVel();
                PlayerValue(6) = 0xA0000;
            }
            break;
            case 7:
            pGravity() = 0;
            pState() = PlayerStateID("Player_State_TubeRoll");
            pAnimation() = GVar("ANI_JUMPING");
            if (pCollisionMode() != 3) {
                pCollisionMode() = 3;
                pAngle() = 64;
            }
            if (GVar("ConveyorBelt_Flag") == 3) {
                pSpeed() = -0xD0000;
                PlayerValue(6) = 0xD0000;
            } else {
                pSpeed() = 0xA0000;
                PlayerValue(6) = 0xA0000;
            }
            break;
            case 8:
            if (GVar("ConveyorBelt_Flag") == 3) {
                pGravity() = 0;
                pState() = PlayerStateID("Player_State_TubeRoll");
                pAnimation() = GVar("ANI_JUMPING");
                pCollisionMode() = 3;
                pAngle() = 64;
                pSpeed() = -0xD0000;
                PlayerValue(6) = 0xD0000;
                if (self->values[0] == 0) {
                    PlaySfx(7, 0);
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

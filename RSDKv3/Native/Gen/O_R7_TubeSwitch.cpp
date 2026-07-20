#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R7_TubeSwitch.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from TubeSwitch.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R7_TubeSwitch::ObjectPlayerInteraction()
{
    Entity *self = Self();

    PlayerObjectCollision(C_TOUCH, -16, -16, 16, 16);
    if (CheckResult() == 1) {
        switch (self->propertyValue) {
            case 0:
            if (self->values[0] == 0) {
                if (pState() != PlayerStateID("Player_State_TubeAirRoll")) {
                    pState() = PlayerStateID("Player_State_TubeAirRoll");
                    pGravity() = 0;
                    pAnimation() = GVar("ANI_JUMPING");
                    PlayerValue(6) = 0xD0000;
                } else {
                    pState() = PlayerStateID("Player_State_Roll");
                    pAnimation() = GVar("ANI_JUMPING");
                }
            }
            break;
            case 1:
            pState() = PlayerStateID("Player_State_Air");
            pAnimation() = GVar("ANI_JUMPING");
            if (pGravity() == 1) {
                if (pYVel() < 0) {
                    pYVel() = -0xD0000;
                } else {
                    pYVel() = 0xD0000;
                }
            } else {
                switch (pCollisionMode()) {
                    case 1:
                    if (pSpeed() < 0) {
                        pYVel() = 0xD0000;
                    } else {
                        pYVel() = -0xD0000;
                    }
                    break;
                    case 3:
                    if (pSpeed() < 0) {
                        pYVel() = -0xD0000;
                    } else {
                        pYVel() = 0xD0000;
                    }
                    break;
                }
            }
            pGravity() = 1;
            pXPos() = self->XPos;
            pXVel() = 0;
            pSpeed() = 0;
            break;
            case 2:
            if (self->values[0] == 0) {
                if (pState() != PlayerStateID("Player_State_TubeAirRoll")) {
                    pXPos() = self->XPos;
                    pState() = PlayerStateID("Player_State_TubeAirRoll");
                    pAnimation() = GVar("ANI_JUMPING");
                    PlayerValue(6) = 0xD0000;
                    pCollisionMode() = 3;
                    pAngle() = 64;
                    pGravity() = 0;
                    pXVel() = 0;
                    if (pYVel() < 0) {
                        pSpeed() = -0xD0000;
                    } else {
                        pSpeed() = 0xD0000;
                    }
                    pYVel() = 0;
                    pRight() = 0;
                    pLeft() = 0;
                } else {
                    pState() = PlayerStateID("Player_State_Air");
                    pAnimation() = GVar("ANI_JUMPING");
                    switch (pCollisionMode()) {
                        case 1:
                        if (pSpeed() < 0) {
                            pYVel() = 0xD0000;
                        } else {
                            pYVel() = -0xD0000;
                        }
                        break;
                        case 3:
                        if (pSpeed() < 0) {
                            pYVel() = -0xD0000;
                        } else {
                            pYVel() = 0xD0000;
                        }
                        break;
                    }
                    pGravity() = 1;
                    pXPos() = self->XPos;
                    pXVel() = 0;
                    pSpeed() = 0;
                }
            }
            break;
            case 3:
            if (self->values[0] == 0) {
                if (pCollisionMode() == 2) {
                    pCollisionMode() = 0;
                    pAngle() = 0;
                    pSpeed() = -pSpeed();
                    pXVel() = -pXVel();
                }
            }
            break;
            case 4:
            if (self->values[0] == 0) {
                pState() = PlayerStateID("Player_State_Roll");
                pAnimation() = GVar("ANI_JUMPING");
                if (pXPos() < self->XPos) {
                    if (pSpeed() < 0xA0000) {
                        pSpeed() = 0xA0000;
                    }
                    pDirection() = 0;
                } else {
                    if (pSpeed() > -0xA0000) {
                        pSpeed() = -0xA0000;
                    }
                    pDirection() = 1;
                }
            }
            break;
            case 5:
            if (pYVel() < 0) {
                if (pState() != PlayerStateID("Player_State_TubeAirRoll")) {
                    if (pLeft() == 1) {
                        pState() = PlayerStateID("Player_State_TubeAirRoll");
                        pGravity() = 0;
                        pCollisionMode() = 3;
                        pAngle() = 64;
                        pAnimation() = GVar("ANI_JUMPING");
                        PlayerValue(6) = 0xD0000;
                        pSpeed() = -0xD0000;
                        pXVel() = 0;
                        pYVel() = 0;
                        pXPos() -= 0x80000;
                    }
                    if (pRight() == 1) {
                        pState() = PlayerStateID("Player_State_TubeAirRoll");
                        pGravity() = 0;
                        pCollisionMode() = 1;
                        pAngle() = 192;
                        pAnimation() = GVar("ANI_JUMPING");
                        PlayerValue(6) = 0xD0000;
                        pSpeed() = 0xD0000;
                        pXVel() = 0;
                        pYVel() = 0;
                        pXPos() += 0x80000;
                    }
                }
            }
            break;
            case 6:
            if (self->values[0] == 0) {
                if (pState() == PlayerStateID("Player_State_Air")) {
                    pXPos() = self->XPos;
                    pXVel() = 0;
                    pSpeed() = 0;
                }
            }
            break;
            case 7:
            if (self->values[0] == 0) {
                if (pCollisionMode() == 2) {
                    pCollisionMode() = 0;
                    pAngle() += 128;
                    pSpeed() = -pSpeed();
                    pXVel() = -pXVel();
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

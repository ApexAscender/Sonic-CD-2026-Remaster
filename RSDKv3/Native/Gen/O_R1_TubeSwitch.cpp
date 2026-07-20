#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R1_TubeSwitch.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from TubeSwitch.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R1_TubeSwitch::ObjectPlayerInteraction()
{
    Entity *self = Self();

    PlayerObjectCollision(C_TOUCH, -16, -16, 16, 16);
    if (CheckResult() == 1) {
        switch (self->propertyValue) {
            case 0:
            if (pSpeed() > 0) {
                if (pState() != PlayerStateID("Player_State_TubeRoll")) {
                    PlaySfx(7, 0);
                }
                pDirection() = 0;
                pState() = PlayerStateID("Player_State_TubeRoll");
                pAnimation() = GVar("ANI_JUMPING");
                PlayerValue(6) = 0xA0000;
                if (pSpeed() < 0xA0000) {
                    pSpeed() = 0xA0000;
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
            if (pState() != PlayerStateID("Player_State_TubeRoll")) {
                PlaySfx(7, 0);
            }
            pGravity() = 0;
            pState() = PlayerStateID("Player_State_TubeRoll");
            pAnimation() = GVar("ANI_JUMPING");
            pCollisionMode() = 3;
            pAngle() = 64;
            pSpeed() = 0x100000;
            PlayerValue(6) = 0x100000;
            break;
            case 2:
            if (self->values[0] == 0) {
                if (pCollisionMode() == 0) {
                    pCollisionMode() = 2;
                    pSpeed() = -pSpeed();
                    pAngle() = 128;
                } else {
                    pCollisionMode() = 0;
                    pSpeed() = -pSpeed();
                    pAngle() = 0;
                    pYPos() += 0x40000;
                }
                pState() = PlayerStateID("Player_State_TubeRoll");
                pAnimation() = GVar("ANI_JUMPING");
            }
            break;
            case 3:
            if (pYVel() < 0) {
                pGravity() = 0;
                pState() = PlayerStateID("Player_State_TubeRoll");
                pAnimation() = GVar("ANI_JUMPING");
                pCollisionMode() = 1;
                pAngle() = 192;
                PlayerValue(6) = 0xA0000;
                pSpeed() = pYVel();
                pSpeed() = -pSpeed();
            }
            break;
            case 4:
            if (pSpeed() < 0) {
                if (pState() != PlayerStateID("Player_State_TubeRoll")) {
                    PlaySfx(7, 0);
                }
                pState() = PlayerStateID("Player_State_TubeRoll");
                pAnimation() = GVar("ANI_JUMPING");
                PlayerValue(6) = 0xA0000;
            } else {
                pState() = PlayerStateID("Player_State_Roll");
                pAnimation() = GVar("ANI_JUMPING");
            }
            break;
            case 5:
            if (pGravity() == 1) {
                pXVel() = self->values[1];
                pSpeed() = self->values[1];
            } else {
                if (pCollisionMode() == 1) {
                    pAngle() = 196;
                    scriptEng.tempValue[0] = Cos256(pAngle());
                    scriptEng.tempValue[0] *= pSpeed();
                    scriptEng.tempValue[0] >>= 8;
                    if (scriptEng.tempValue[0] != 0) {
                        self->values[1] = scriptEng.tempValue[0];
                    }
                }
            }
            break;
            case 6:
            if (pState() == PlayerStateID("Player_State_TubeRoll")) {
                if (pYVel() < -0x60000) {
                    pYVel() = -0x60000;
                }
            } else {
                pAnimation() = GVar("ANI_JUMPING");
            }
            break;
            case 7:
            if (pState() == PlayerStateID("Player_State_TubeRoll")) {
                self->propertyValue = 8;
            }
            break;
            case 8:
            if (pGravity() == 1) {
                pYVel() = -0xA8000;
                self->propertyValue = 7;
            }
            break;
        }
        self->values[0] = 1;
    } else {
        self->values[0] = 0;
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS

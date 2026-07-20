#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R6_TubeSwitch.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from TubeSwitch.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R6_TubeSwitch::ObjectStartup()
{
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Tube SW")) {
            switch (objectEntityList[scriptEng.arrayPosition[0]].propertyValue) {
                case 0:
                case 1:
                case 2:
                case 3:
                case 4:
                case 7:
                objectEntityList[scriptEng.arrayPosition[0]].values[2] = -16;
                objectEntityList[scriptEng.arrayPosition[0]].values[3] = 16;
                break;
                case 5:
                case 6:
                case 8:
                objectEntityList[scriptEng.arrayPosition[0]].values[2] = -48;
                objectEntityList[scriptEng.arrayPosition[0]].values[3] = 48;
                break;
                case 9:
                case 10:
                objectEntityList[scriptEng.arrayPosition[0]].values[2] = -8;
                objectEntityList[scriptEng.arrayPosition[0]].values[3] = 8;
                break;
                case 11:
                objectEntityList[scriptEng.arrayPosition[0]].values[2] = -16;
                objectEntityList[scriptEng.arrayPosition[0]].values[3] = 16;
                break;
            }
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_R6_TubeSwitch::ObjectPlayerInteraction()
{
    Entity *self = Self();

    PlayerObjectCollision(C_TOUCH, self->values[2], self->values[2], self->values[3], self->values[3]);
    if (CheckResult() == 1) {
        switch (self->propertyValue) {
            case 0:
            if (self->values[5] == 1) {
                pSpeed() = 1;
                self->values[5] = 0;
            }
            if (pSpeed() > -1) {
                pDirection() = 0;
                pSpeed() = 0xA0000;
                pState() = PlayerStateID("Player_State_TubeRoll");
                pAnimation() = GVar("ANI_JUMPING");
                PlayerValue(6) = 0xA0000;
            } else {
                pState() = PlayerStateID("Player_State_Roll");
                pAnimation() = GVar("ANI_JUMPING");
            }
            break;
            case 1:
            if (pCollisionMode() == 0) {
                if (pSpeed() < 1) {
                    pDirection() = 1;
                    pSpeed() = -0xA0000;
                    pState() = PlayerStateID("Player_State_TubeRoll");
                    pAnimation() = GVar("ANI_JUMPING");
                    PlayerValue(6) = 0xA0000;
                } else {
                    pState() = PlayerStateID("Player_State_Roll");
                    pAnimation() = GVar("ANI_JUMPING");
                }
            } else {
                pGravity() = 1;
                pSpeed() = -pSpeed();
                pXVel() = pSpeed();
                pState() = PlayerStateID("Player_State_Air");
            }
            break;
            case 2:
            pGravity() = 1;
            pCollisionMode() = 0;
            pXVel() = 0;
            pSpeed() = 0;
            break;
            case 3:
            if (pYVel() < 1) {
                pState() = PlayerStateID("Player_State_TubeRoll");
                PlayerValue(6) = 0xC0000;
                pSpeed() = -0xC0000;
                pGravity() = 0;
                pAngle() = 64;
                pCollisionMode() = 3;
                pAnimation() = GVar("ANI_JUMPING");
                cameraAdjustY = 0;
            } else {
                if (pState() != PlayerStateID("Player_State_Fly")) {
                    pAnimation() = GVar("ANI_JUMPING");
                }
            }
            break;
            case 4:
            if (pState() == PlayerStateID("Player_State_TubeRoll")) {
                pState() = PlayerStateID("Player_State_Roll");
            }
            break;
            case 5:
            if (pState() == PlayerStateID("Player_State_TubeAirRoll")) {
                if (pJumpPress() == 1) {
                    self->values[1] = 1;
                } else {
                    if (pJumpHold() == 0) {
                        self->values[1] = 0;
                    }
                }
                if (self->values[1] == 1) {
                    PlayerObjectCollision(C_TOUCH, -16, -16, 16, 16);
                    if (CheckResult() == 1) {
                        pState() = PlayerStateID("Player_State_Air");
                        pGravity() = 1;
                        pXPos() = self->XPos;
                        pYPos() = self->YPos;
                        pSpeed() = -0x80000;
                        pXVel() = -0x80000;
                        pYVel() = -0x40000;
                        self->values[1] = 0;
                        self->values[4] = 1;
                    }
                }
            } else {
                PlayerObjectCollision(C_TOUCH, -16, -16, 16, 16);
                if (CheckResult() == 1) {
                    if (self->values[4] == 0) {
                        pGravity() = 0;
                        pXPos() = self->XPos;
                        pYPos() = self->YPos;
                        pXVel() = 0;
                        pYVel() = 0;
                        pSpeed() = 0x80000;
                        pState() = PlayerStateID("Player_State_TubeAirRoll");
                        pAnimation() = GVar("ANI_JUMPING");
                        PlayerValue(6) = 0x80000;
                        pAngle() = 224;
                        pCollisionMode() = 0;
                        PlaySfx(7, 0);
                        self->values[4] = 1;
                    }
                } else {
                    self->values[4] = 0;
                }
            }
            break;
            case 6:
            if (pState() == PlayerStateID("Player_State_TubeAirRoll")) {
                if (pJumpPress() == 1) {
                    self->values[1] = 1;
                } else {
                    if (pJumpHold() == 0) {
                        self->values[1] = 0;
                    }
                }
                if (self->values[1] == 1) {
                    PlayerObjectCollision(C_TOUCH, -16, -16, 16, 16);
                    if (CheckResult() == 1) {
                        pState() = PlayerStateID("Player_State_Air");
                        pGravity() = 1;
                        pXPos() = self->XPos;
                        pYPos() = self->YPos;
                        self->values[1] = 0;
                        pSpeed() = 0x80000;
                        pXVel() = 0x80000;
                        pYVel() = -0x40000;
                        self->values[4] = 1;
                    }
                }
            } else {
                PlayerObjectCollision(C_TOUCH, -16, -16, 16, 16);
                if (CheckResult() == 1) {
                    if (self->values[4] == 0) {
                        pGravity() = 0;
                        pXPos() = self->XPos;
                        pYPos() = self->YPos;
                        pXVel() = 0;
                        pYVel() = 0;
                        pSpeed() = 0x80000;
                        pState() = PlayerStateID("Player_State_TubeAirRoll");
                        pAnimation() = GVar("ANI_JUMPING");
                        PlayerValue(6) = 0x80000;
                        pAngle() = 36;
                        pCollisionMode() = 3;
                        PlaySfx(7, 0);
                        self->values[4] = 1;
                    }
                } else {
                    self->values[4] = 0;
                }
            }
            break;
            case 7:
            if (self->values[0] == 0) {
                if (pState() == PlayerStateID("Player_State_TubeAirRoll")) {
                    pSpeed() = -pSpeed();
                    if (pCollisionMode() == 0) {
                        pCollisionMode() = 2;
                        pAngle() = 128;
                    } else {
                        pCollisionMode() = 0;
                        pAngle() = 0;
                    }
                }
            }
            break;
            case 8:
            if (pState() == PlayerStateID("Player_State_TubeAirRoll")) {
                if (pJumpPress() == 1) {
                    self->values[1] = 1;
                } else {
                    if (pJumpHold() == 0) {
                        self->values[1] = 0;
                    }
                }
                if (self->values[1] == 1) {
                    PlayerObjectCollision(C_TOUCH, -16, -16, 16, 16);
                    if (CheckResult() == 1) {
                        pState() = PlayerStateID("Player_State_Air");
                        pGravity() = 1;
                        pXPos() = self->XPos;
                        pYPos() = self->YPos;
                        pSpeed() = -0x80000;
                        pXVel() = -0x80000;
                        pYVel() = 0x20000;
                        self->values[1] = 0;
                        self->values[4] = 1;
                    }
                }
            } else {
                PlayerObjectCollision(C_TOUCH, -16, -16, 16, 16);
                if (CheckResult() == 1) {
                    if (self->values[4] == 0) {
                        pSpeed() = -0x80000;
                        pGravity() = 0;
                        pXPos() = self->XPos;
                        pYPos() = self->YPos;
                        pXVel() = 0;
                        pYVel() = 0;
                        pState() = PlayerStateID("Player_State_TubeAirRoll");
                        pAnimation() = GVar("ANI_JUMPING");
                        PlayerValue(6) = 0x80000;
                        pAngle() = 172;
                        pCollisionMode() = 1;
                        PlaySfx(7, 0);
                        self->values[4] = 1;
                    }
                } else {
                    self->values[4] = 0;
                }
            }
            break;
            case 9:
            if (pYVel() < 1) {
                pState() = PlayerStateID("Player_State_TubeRoll");
                PlayerValue(6) = 0xC0000;
                pSpeed() = 0xC0000;
                pGravity() = 0;
                pAngle() = 192;
                pCollisionMode() = 1;
                pAnimation() = GVar("ANI_JUMPING");
                cameraAdjustY = 0;
            } else {
                pAnimation() = GVar("ANI_JUMPING");
            }
            break;
            case 10:
            if (self->values[0] == 0) {
                if (pState() == PlayerStateID("Player_State_Roll")) {
                    pState() = PlayerStateID("Player_State_Air");
                    pGravity() = 1;
                    pSpeed() = 0;
                    pXVel() = 0;
                }
                if (pState() == PlayerStateID("Player_State_TubeRoll")) {
                    pState() = PlayerStateID("Player_State_Roll");
                }
            }
            break;
            case 11:
            if (pState() != PlayerStateID("Player_State_TubeAirRoll")) {
                if (self->values[0] == 0) {
                    pGravity() = 0;
                    pXPos() = self->XPos;
                    pYPos() = self->YPos;
                    pXVel() = 0;
                    pYVel() = 0;
                    pSpeed() = 0x80000;
                    pState() = PlayerStateID("Player_State_TubeAirRoll");
                    pAnimation() = GVar("ANI_JUMPING");
                    PlayerValue(6) = 0x80000;
                    pAngle() = 224;
                    pCollisionMode() = 0;
                    PlaySfx(7, 0);
                }
            }
            break;
            case 12:
            if (pYVel() > -1) {
                pState() = PlayerStateID("Player_State_TubeRoll");
                PlayerValue(6) = 0xC0000;
                pSpeed() = -0xC0000;
                pGravity() = 0;
                pAngle() = 192;
                pCollisionMode() = 1;
                pAnimation() = GVar("ANI_JUMPING");
                cameraAdjustY = 0;
            } else {
                pState() = PlayerStateID("Player_State_TubeRoll");
                PlayerValue(6) = 0xC0000;
                pSpeed() = pYVel();
                pSpeed() = -pSpeed();
                pGravity() = 0;
                pAngle() = 192;
                pCollisionMode() = 1;
                pAnimation() = GVar("ANI_JUMPING");
            }
            break;
        }
        self->values[0] = 1;
    } else {
        self->values[0] = 0;
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS

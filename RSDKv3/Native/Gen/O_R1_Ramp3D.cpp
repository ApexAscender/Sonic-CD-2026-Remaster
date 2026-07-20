#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R1_Ramp3D.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from Ramp3D.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R1_Ramp3D::ObjectStartup()
{
    if (pXPos() > 0x7D00000) {
        yBoundary2 = 1280;
        objectEntityList[15].type = TypeNameID("Background FX");
        objectEntityList[15].priority = 1;
        objectEntityList[15].drawOrder = 0;
    }
    if (pXPos() > 0xFA00000) {
        yBoundary2 = 1024;
    }
}

void O_R1_Ramp3D::ObjectPlayerInteraction()
{
    Entity *self = Self();

    switch (self->propertyValue) {
        case 0:
        if (pGravity() == 0) {
            PlayerObjectCollision(C_TOUCH, -16, -16, 16, 16);
            if (CheckResult() == 1) {
                if (pState() != PlayerStateID("Player_State_Static")) {
                    pState() = PlayerStateID("Player_State_Static");
                    pTrackScroll() = 1;
                    pTileCollisions() = 0;
                    pSpeed() = 0;
                    pXVel() = 0;
                    pYVel() = -0xC0000;
                    pAnimationSpeed() = 0;
                }
            }
        }
        break;
        case 1:
        PlayerObjectCollision(C_TOUCH, -16, -16, 16, 16);
        if (CheckResult() == 1) {
            pState() = PlayerStateID("Player_State_Air");
            pTileCollisions() = 1;
            pSpeed() = 0x80000;
            pXVel() = 0x80000;
            pYVel() = -0xE0000;
            pGravity() = 1;
            pRotation() = 384;
            newYBoundary2 = 1280;
            newXBoundary1 = 2080;
            if (pAnimation() == GVar("ANI_ROLL3D")) {
                pAnimation() = GVar("ANI_JUMPING");
            } else {
                if (pAnimation() != GVar("ANI_JUMPING")) {
                    pAnimation() = GVar("ANI_WALKING");
                }
            }
            objectEntityList[15].type = TypeNameID("Background FX");
            objectEntityList[15].priority = 1;
            objectEntityList[15].drawOrder = 0;
            scriptEng.arrayPosition[0] = 0;
            while (scriptEng.arrayPosition[0] < 2) {
                hParallax.scrollPos[scriptEng.arrayPosition[0]] = 0;
                scriptEng.arrayPosition[0]++;
            }
        }
        break;
        case 2:
        if (pState() == PlayerStateID("Player_State_Static")) {
            PlayerObjectCollision(C_TOUCH, -16, -16, 16, 16);
            if (CheckResult() == 1) {
                pState() = PlayerStateID("Player_State_Air");
                pTileCollisions() = 1;
                pSpeed() = 0x40000;
                pXVel() = 0x40000;
                pYVel() = -0xC0000;
                pGravity() = 1;
                pRotation() = 384;
                newYBoundary2 = 1280;
                if (pAnimation() == GVar("ANI_ROLL3D")) {
                    pAnimation() = GVar("ANI_JUMPING");
                } else {
                    if (pAnimation() != GVar("ANI_JUMPING")) {
                        pAnimation() = GVar("ANI_WALKING");
                    }
                }
            }
        }
        break;
        case 3:
        if (pXPos() > self->XPos) {
            yBoundary2 = 1024;
        } else {
            yBoundary2 = 1280;
        }
        break;
        case 4:
        if (pXPos() > self->XPos) {
            if (pGravity() == 0) {
                if (pState() != PlayerStateID("Player_State_Static")) {
                    if (pState() == PlayerStateID("Player_State_Roll")) {
                        if (pAngle() > 216) {
                            pAnimation() = GVar("ANI_JUMPING");
                        } else {
                            if (pAngle() == 0) {
                                pAnimation() = GVar("ANI_JUMPING");
                            } else {
                                pAnimation() = GVar("ANI_ROLL3D");
                            }
                        }
                    } else {
                        if (pSpeed() != 0) {
                            pState() = PlayerStateID("Player_State_Ramp3D");
                        }
                    }
                }
            }
            objectEntityList[objectLoop + 3].values[0] = pXPos();
            objectEntityList[objectLoop + 3].values[0] -= self->XPos;
            objectEntityList[objectLoop + 5].values[0] = objectEntityList[objectLoop + 3].values[0];
            objectEntityList[objectLoop + 5].values[0] /= 3;
            objectEntityList[objectLoop + 3].values[0] >>= 1;
            objectEntityList[objectLoop + 4].values[0] = objectEntityList[objectLoop + 3].values[0];
            objectEntityList[objectLoop + 3].values[0] += objectEntityList[objectLoop + 3].XPos;
            objectEntityList[objectLoop + 4].values[0] += objectEntityList[objectLoop + 4].XPos;
            objectEntityList[objectLoop + 5].values[0] += objectEntityList[objectLoop + 5].XPos;
            scriptEng.tempValue[0] = self->YPos;
            scriptEng.tempValue[0] -= pYPos();
            if (scriptEng.tempValue[0] < 0xE00000) {
                scriptEng.tempValue[0] = pXPos();
                scriptEng.tempValue[0] -= self->values[1];
                hParallax.scrollPos[0] += scriptEng.tempValue[0];
                scriptEng.arrayPosition[0] = 13;
                scriptEng.tempValue[2] = 128;
                while (scriptEng.arrayPosition[0] < 141) {
                    scriptEng.tempValue[1] = scriptEng.tempValue[0];
                    scriptEng.tempValue[1] *= scriptEng.tempValue[2];
                    scriptEng.tempValue[1] >>= 7;
                    hParallax.scrollPos[scriptEng.arrayPosition[0]] += scriptEng.tempValue[1];
                    scriptEng.arrayPosition[0]++;
                    scriptEng.tempValue[2]--;
                }
                scriptEng.tempValue[0] <<= 1;
                hParallax.scrollPos[1] += scriptEng.tempValue[0];
            }
        } else {
            objectEntityList[objectLoop + 3].values[0] = objectEntityList[objectLoop + 3].XPos;
            objectEntityList[objectLoop + 4].values[0] = objectEntityList[objectLoop + 4].XPos;
            objectEntityList[objectLoop + 5].values[0] = objectEntityList[objectLoop + 5].XPos;
            if (pGravity() == 0) {
                if (pState() == PlayerStateID("Player_State_Ramp3D")) {
                    pState() = PlayerStateID("Player_State_Ground");
                }
            }
        }
        self->values[1] = pXPos();
        break;
        case 5:
        CheckResult() = (pState() == PlayerStateID("Player_State_Air"));
        scriptEng.tempValue[0] = CheckResult();
        if (scriptEng.tempValue[0] != 0) {
            PlayerObjectCollision(C_TOUCH, -16, -128, 16, 16);
            if (CheckResult() == 1) {
                pAnimation() = GVar("ANI_DROPPING");
                self->values[1] = pXPos();
            }
            if (pAnimation() == GVar("ANI_DROPPING")) {
                pSpeed() = 0;
                pXVel() = 0;
                pXPos() = self->values[1];
            }
        }
        break;
        case 6:
        if (pYPos() < self->YPos) {
            if (pXPos() > self->XPos) {
                yBoundary2 = 792;
            } else {
                yBoundary2 = 1024;
            }
        }
        break;
        case 7:
        if (pXPos() > self->XPos) {
            yBoundary2 = 1024;
            if (pGravity() == 0) {
                if (pState() == PlayerStateID("Player_State_Ramp3D")) {
                    pState() = PlayerStateID("Player_State_Ground");
                }
            }
        } else {
            yBoundary2 = 792;
        }
        break;
        case 8:
        PlayerObjectCollision(C_TOUCH, -16, -16, 16, 16);
        if (CheckResult() == 1) {
            pTimer() = 0;
            pState() = PlayerStateID("Player_State_Air");
            pTileCollisions() = 1;
            pSpeed() = 0x80000;
            pXVel() = 0x80000;
            pYVel() = -0xE0000;
            pGravity() = 1;
            pRotation() = 384;
            newYBoundary2 = 1280;
            newXBoundary1 = 2080;
            if (pAnimation() == GVar("ANI_ROLL3D")) {
                pAnimation() = GVar("ANI_JUMPING");
            } else {
                if (pAnimation() != GVar("ANI_JUMPING")) {
                    pAnimation() = GVar("ANI_WALKING");
                }
            }
            objectEntityList[15].type = TypeNameID("Background FX");
            objectEntityList[15].priority = 1;
            objectEntityList[15].drawOrder = 0;
            scriptEng.arrayPosition[0] = 0;
            while (scriptEng.arrayPosition[0] < 2) {
                hParallax.scrollPos[scriptEng.arrayPosition[0]] = 0;
                scriptEng.arrayPosition[0]++;
            }
        }
        if (pYVel() < 0) {
            pControlMode() = -1;
            pLeft() = 0;
            pRight() = 0;
            self->priority = 1;
        } else {
            pControlMode() = 0;
            self->priority = 0;
        }
        break;
    }
}

void O_R1_Ramp3D::Ramp3D_SetPlayerLaunch()
{
}

const Native::NativeFunctionDef O_R1_Ramp3D::funcs[1] = {
    { "Ramp3D_SetPlayerLaunch", O_R1_Ramp3D::Ramp3D_SetPlayerLaunch },
};

#endif // RETRO_USE_NATIVE_OBJECTS

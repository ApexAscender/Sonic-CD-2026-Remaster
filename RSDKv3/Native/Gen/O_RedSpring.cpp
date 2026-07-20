#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_RedSpring.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from RedSpring.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_RedSpring::ObjectStartup()
{
    LoadSpriteSheet("Global/Items.gif");
    AddSpriteFrame(-16, -8, 32, 16, 84, 1);
    AddSpriteFrame(-8, -16, 16, 32, 117, 1);
    AddSpriteFrame(-8, -16, 16, 32, 175, 1);
    AddSpriteFrame(-16, -8, 32, 16, 84, 59);
    AddSpriteFrame(-16, -16, 32, 32, 84, 117);
    AddSpriteFrame(-16, -16, 32, 32, 117, 165);
    AddSpriteFrame(-16, -16, 32, 32, 84, 117);
    AddSpriteFrame(-16, -16, 32, 32, 117, 165);
    AddSpriteFrame(-16, 0, 32, 8, 84, 1);
    AddSpriteFrame(-8, -16, 8, 32, 125, 1);
    AddSpriteFrame(0, -16, 8, 32, 175, 1);
    AddSpriteFrame(-16, -8, 32, 8, 84, 67);
    AddSpriteFrame(-16, -16, 32, 32, 84, 150);
    AddSpriteFrame(-16, -16, 32, 32, 150, 165);
    AddSpriteFrame(-16, -16, 32, 32, 84, 150);
    AddSpriteFrame(-16, -16, 32, 32, 150, 165);
    AddSpriteFrame(-16, -32, 32, 40, 84, 18);
    AddSpriteFrame(-8, -16, 40, 32, 134, 1);
    AddSpriteFrame(-16, -16, 40, 32, 192, 1);
    AddSpriteFrame(-16, -8, 32, 40, 84, 76);
    AddSpriteFrame(-16, -32, 48, 48, 117, 34);
    AddSpriteFrame(-32, -32, 48, 48, 166, 34);
    AddSpriteFrame(-16, -32, 48, 48, 117, 34);
    AddSpriteFrame(-32, -32, 48, 48, 166, 34);
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Red Spring")) {
            if (objectEntityList[scriptEng.arrayPosition[0]].propertyValue > 7) {
                objectEntityList[scriptEng.arrayPosition[0]].propertyValue -= 8;
                objectEntityList[scriptEng.arrayPosition[0]].values[7] = 1;
            }
            if (objectEntityList[scriptEng.arrayPosition[0]].propertyValue > 5) {
                objectEntityList[scriptEng.arrayPosition[0]].direction = 2;
            }
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_RedSpring::ObjectPlayerInteraction()
{
    Entity *self = Self();

    switch (self->propertyValue) {
        case 0:
        scriptEng.tempValue[0] = 0;
        if (pGravity() == 1) {
            scriptEng.tempValue[0] = 1;
        }
        if (pCollisionMode() > 0) {
            if (pYVel() < 0) {
                scriptEng.tempValue[0] = 1;
            }
        }
        if (scriptEng.tempValue[0] == 0) {
            PlayerObjectCollision(C_BOX, -16, -8, 16, 8);
            PlayerObjectCollision(C_TOUCH, -16, -10, 16, -6);
            if (CheckResult() == 1) {
                PlayerValue(7) = GVar("ANI_WALKING");
                if (pAnimation() == GVar("ANI_RUNNING")) {
                    PlayerValue(7) = GVar("ANI_RUNNING");
                }
                if (pAnimation() == GVar("ANI_PEELOUT")) {
                    PlayerValue(7) = GVar("ANI_PEELOUT");
                }
                self->values[0] = 1;
                pState() = PlayerStateID("Player_State_Air");
                pGravity() = 1;
                pYVel() = -0x100000;
                pAnimation() = GVar("ANI_BOUNCING");
                pTimer() = 0;
                PlaySfx(11, 0);
                HapticEffect_Script(9, 0, 0, 0);
            }
        } else {
            if (pYVel() >= 0) {
                PlayerObjectCollision(C_PLATFORM, -16, -8, 16, 8);
                PlayerObjectCollision(C_TOUCH, -16, -10, 16, -6);
                if (CheckResult() == 1) {
                    PlayerValue(7) = GVar("ANI_WALKING");
                    if (pAnimation() == GVar("ANI_RUNNING")) {
                        PlayerValue(7) = GVar("ANI_RUNNING");
                    }
                    if (pAnimation() == GVar("ANI_PEELOUT")) {
                        PlayerValue(7) = GVar("ANI_PEELOUT");
                    }
                    self->values[0] = 1;
                    pState() = PlayerStateID("Player_State_Air");
                    pGravity() = 1;
                    pYVel() = -0x100000;
                    pAnimation() = GVar("ANI_BOUNCING");
                    pTimer() = 0;
                    PlaySfx(11, 0);
                    HapticEffect_Script(9, 0, 0, 0);
                }
            }
        }
        break;
        case 1:
        PlayerObjectCollision(C_BOX, -8, -16, 8, 16);
        if (pGravity() == 0) {
            PlayerObjectCollision(C_TOUCH, 6, -15, 11, 15);
            if (CheckResult() == 1) {
                self->values[0] = 1;
                pAngle() = 0;
                pSpeed() = 0x100000;
                pCollisionMode() = 0;
                pPushing() = 0;
                pDirection() = 0;
                pControlLock() = 16;
                PlaySfx(11, 0);
                HapticEffect_Script(9, 0, 0, 0);
            }
        } else {
            if (self->values[7] == 1) {
                PlayerObjectCollision(C_TOUCH, 6, -15, 11, 15);
                if (CheckResult() == 1) {
                    self->values[0] = 1;
                    pAngle() = 0;
                    pSpeed() = 0x100000;
                    pCollisionMode() = 0;
                    pPushing() = 0;
                    pDirection() = 0;
                    pControlLock() = 16;
                    PlaySfx(11, 0);
                    HapticEffect_Script(9, 0, 0, 0);
                }
            }
        }
        break;
        case 2:
        PlayerObjectCollision(C_BOX, -8, -16, 8, 16);
        if (pGravity() == 0) {
            PlayerObjectCollision(C_TOUCH, -10, -15, -6, 15);
            if (CheckResult() == 1) {
                self->values[0] = 1;
                pSpeed() = -0x100000;
                pCollisionMode() = 0;
                pPushing() = 0;
                pDirection() = 1;
                pControlLock() = 16;
                PlaySfx(11, 0);
                HapticEffect_Script(9, 0, 0, 0);
            }
        } else {
            if (self->values[7] == 1) {
                PlayerObjectCollision(C_TOUCH, -10, -15, -6, 15);
                if (CheckResult() == 1) {
                    self->values[0] = 1;
                    pSpeed() = -0x100000;
                    pYVel() = 0x20000;
                    pCollisionMode() = 0;
                    pPushing() = 0;
                    pDirection() = 1;
                    pControlLock() = 16;
                    PlaySfx(11, 0);
                    HapticEffect_Script(9, 0, 0, 0);
                }
            }
        }
        break;
        case 3:
        PlayerObjectCollision(C_BOX, -16, -8, 16, 8);
        PlayerObjectCollision(C_TOUCH, -15, 6, 15, 10);
        if (CheckResult() == 1) {
            if (pCollisionMode() == 2) {
                pSpeed() = -pSpeed();
                pXVel() = -pXVel();
            }
            self->values[0] = 1;
            pState() = PlayerStateID("Player_State_Air");
            pGravity() = 1;
            pYVel() = 0x100000;
            pTimer() = 0;
            PlaySfx(11, 0);
            HapticEffect_Script(9, 0, 0, 0);
        }
        break;
        case 4:
        PlayerObjectCollision(C_TOUCH, -12, -16, 12, 12);
        if (pGravity() == 0) {
            if (CheckResult() == 1) {
                self->values[0] = 1;
                pState() = PlayerStateID("Player_State_Air");
                pGravity() = 1;
                pSpeed() = 0xB4000;
                pYVel() = -0xB4000;
                pAnimation() = GVar("ANI_WALKING");
                pDirection() = 0;
                pTimer() = 0;
                PlaySfx(11, 0);
                HapticEffect_Script(9, 0, 0, 0);
            }
        }
        if (pYVel() >= 0) {
            if (CheckResult() == 1) {
                self->values[0] = 1;
                pState() = PlayerStateID("Player_State_Air");
                pGravity() = 1;
                pSpeed() = 0xB4000;
                pYVel() = -0xB4000;
                pAnimation() = GVar("ANI_WALKING");
                pDirection() = 0;
                pTimer() = 0;
                PlaySfx(11, 0);
                HapticEffect_Script(9, 0, 0, 0);
            }
        }
        break;
        case 5:
        PlayerObjectCollision(C_TOUCH, -12, -16, 12, 12);
        if (pYVel() >= 0) {
            if (CheckResult() == 1) {
                self->values[0] = 1;
                pState() = PlayerStateID("Player_State_Air");
                pGravity() = 1;
                pSpeed() = -0xB4000;
                pYVel() = -0xB4000;
                pAnimation() = GVar("ANI_WALKING");
                pDirection() = 1;
                pTimer() = 0;
                PlaySfx(11, 0);
                HapticEffect_Script(9, 0, 0, 0);
            }
        }
        if (pGravity() == 0) {
            if (CheckResult() == 1) {
                self->values[0] = 1;
                pState() = PlayerStateID("Player_State_Air");
                pGravity() = 1;
                pSpeed() = -0xB4000;
                pYVel() = -0xB4000;
                pAnimation() = GVar("ANI_WALKING");
                pDirection() = 1;
                pTimer() = 0;
                PlaySfx(11, 0);
                HapticEffect_Script(9, 0, 0, 0);
            }
        }
        break;
        case 6:
        PlayerObjectCollision(C_TOUCH, -12, -12, 12, 12);
        if (CheckResult() == 1) {
            self->values[0] = 1;
            pState() = PlayerStateID("Player_State_Air");
            pGravity() = 1;
            pSpeed() = 0xB4000;
            pYVel() = 0xB4000;
            pTimer() = 0;
            PlaySfx(11, 0);
            HapticEffect_Script(9, 0, 0, 0);
        }
        break;
        case 7:
        PlayerObjectCollision(C_TOUCH, -12, -12, 12, 12);
        if (CheckResult() == 1) {
            self->values[0] = 1;
            pState() = PlayerStateID("Player_State_Air");
            pGravity() = 1;
            pSpeed() = -0xB4000;
            pYVel() = 0xB4000;
            pTimer() = 0;
            PlaySfx(11, 0);
            HapticEffect_Script(9, 0, 0, 0);
        }
        break;
    }
}

void O_RedSpring::ObjectDraw()
{
    Entity *self = Self();

    if (self->values[0] == 0) {
        DrawSpriteFX_Script(self->propertyValue, FX_FLIP, self->XPos, self->YPos);
    } else {
        self->values[0]++;
        scriptEng.tempValue[0] = self->values[0];
        scriptEng.tempValue[0] >>= 1;
        switch (scriptEng.tempValue[0]) {
            case 0:
            case 1:
            DrawSpriteFX_Script(self->propertyValue, FX_FLIP, self->XPos, self->YPos);
            break;
            case 2:
            case 6:
            scriptEng.tempValue[1] = self->propertyValue;
            scriptEng.tempValue[1] += 8;
            DrawSpriteFX_Script(scriptEng.tempValue[1], FX_FLIP, self->XPos, self->YPos);
            break;
            case 3:
            case 4:
            case 5:
            scriptEng.tempValue[1] = self->propertyValue;
            scriptEng.tempValue[1] += 16;
            DrawSpriteFX_Script(scriptEng.tempValue[1], FX_FLIP, self->XPos, self->YPos);
            break;
        }
        if (self->values[0] > 12) {
            self->values[0] = 0;
        }
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS

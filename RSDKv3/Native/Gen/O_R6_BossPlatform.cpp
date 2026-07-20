#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R6_BossPlatform.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from BossPlatform.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R6_BossPlatform::ObjectStartup()
{
    LoadSpriteSheet("R6/Objects3.gif");
    if (objectEntityList[24].propertyValue == 2) {
        AddSpriteFrame(-16, -16, 32, 32, 223, 200);
    } else {
        AddSpriteFrame(-16, -16, 32, 32, 141, 220);
    }
}

void O_R6_BossPlatform::ObjectMain()
{
    Entity *self = Self();

    self->values[1] = self->YPos;
    if (self->values[3] > 0) {
        self->values[2] += self->values[3];
        self->YPos += self->values[2];
        ObjectTileCollision_Script(0, -16, 16, 0);
        scriptEng.tempValue[0] = CheckResult();
        ObjectTileCollision_Script(0, 16, 16, 0);
        scriptEng.tempValue[0] |= CheckResult();
        if (scriptEng.tempValue[0] == 1) {
            PlaySfx(globalSFXCount + 3, 0);
            self->values[3] = 0;
            self->values[2] = 0;
            HapticEffect_Script(96, 0, 0, 0);
        }
    } else {
        scriptEng.arrayPosition[0] = self->values[5];
        if (objectEntityList[scriptEng.arrayPosition[0]].state == 4) {
            if (objectEntityList[scriptEng.arrayPosition[0]].values[0] > 29) {
                PlayerObjectCollision(C_TOUCH, -16, -512, 16, 512);
                if (CheckResult() == 1) {
                    self->values[3] = 3584;
                    HapticEffect_Script(44, 0, 0, 0);
                } else {
                    self->values[3] = 2816;
                }
                self->values[2] = -0x60000;
            }
        }
    }
    self->values[4] = self->YPos;
    self->values[4] -= self->values[1];
    if (self->values[6] > 0) {
        self->values[6]--;
    }
}

void O_R6_BossPlatform::ObjectPlayerInteraction()
{
    Entity *self = Self();

    if (self->values[6] == 0) {
        scriptEng.tempValue[0] = self->YPos;
        self->YPos = self->values[1];
        PlayerObjectCollision(C_BOX, -16, -18, 16, 16);
        if (CheckResult() == 1) {
            pYPos() += self->values[4];
            pYPos() += 0x20000;
        } else {
            if (self->values[3] > 0) {
                if (CheckResult() == 4) {
                    CallScriptFunctionNamed("Player_Hit", scriptSub);
                    if (pState() == PlayerStateID("Player_State_GotHit")) {
                        self->values[6] = 20;
                    }
                }
            }
            PlayerObjectCollision(C_TOUCH, -16, -32, 16, 16);
            if (CheckResult() == 1) {
                if (pYVel() < -0x40000) {
                    if (pJumpPress() == 1) {
                        scriptEng.tempValue[1] = self->values[2];
                        scriptEng.tempValue[1] >>= 1;
                        pYVel() += scriptEng.tempValue[1];
                    }
                }
            }
        }
        self->YPos = scriptEng.tempValue[0];
    }
}

void O_R6_BossPlatform::ObjectDraw()
{
    DrawSprite_Frame(0);
}

#endif // RETRO_USE_NATIVE_OBJECTS

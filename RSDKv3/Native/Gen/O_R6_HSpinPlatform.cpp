#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R6_HSpinPlatform.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from HSpinPlatform.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R6_HSpinPlatform::ObjectStartup()
{
    LoadSpriteSheet("R6/Objects.gif");
    AddSpriteFrame(-24, -16, 48, 32, 1, 84);
    AddSpriteFrame(-24, -16, 48, 32, 50, 84);
    AddSpriteFrame(-8, 16, 16, 16, 1, 117);
    AddSpriteFrame(-8, 16, 16, 16, 18, 117);
    AddSpriteFrame(-8, 16, 16, 16, 35, 117);
    AddSpriteFrame(-8, 16, 16, 16, 35, 117);
    AddSpriteFrame(-8, 16, 16, 16, 35, 117);
    AddSpriteFrame(-8, 16, 16, 16, 52, 117);
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("H Spin Platform")) {
            objectEntityList[scriptEng.arrayPosition[0]].drawOrder = 4;
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_R6_HSpinPlatform::ObjectMain()
{
    Entity *self = Self();

    self->values[3] = GVar("Oscillation");
    self->values[3] <<= 1;
    if (self->propertyValue == 1) {
        self->values[3] += 256;
    }
    self->values[2] = Sin512(self->values[3]);
    self->values[2] <<= 13;
    self->values[2] += self->XPos;
    self->values[2] &= 0xFFFF0000;
    self->values[2] -= self->values[1];
}

void O_R6_HSpinPlatform::ObjectPlayerInteraction()
{
    Entity *self = Self();

    scriptEng.tempValue[1] = self->XPos;
    self->XPos = self->values[1];
    PlayerObjectCollision(C_PLATFORM, -24, -12, 24, 8);
    if (CheckResult() == 1) {
        pXPos() += self->values[2];
        if (pState() != PlayerStateID("Player_State_SpinningTop")) {
            pSpeed() = 0;
            self->values[4] = 1;
            PlayerValue(6) = 0xC00;
            if (pXPos() > self->XPos) {
                pTimer() = pXPos();
                pTimer() -= self->XPos;
                self->values[0] = 128;
            } else {
                pTimer() = self->XPos;
                pTimer() -= pXPos();
                self->values[0] = 384;
            }
        }
        if (pXPos() > self->XPos) {
            if (pLeft() == 1) {
                pTimer() -= 2048;
            }
            if (pRight() == 1) {
                pTimer() += 2048;
            }
        } else {
            if (pLeft() == 1) {
                pTimer() += 2048;
            }
            if (pRight() == 1) {
                pTimer() -= 2048;
            }
        }
        pState() = PlayerStateID("Player_State_SpinningTop");
        pAnimation() = GVar("ANI_SPINNING_TOP");
        pXPos() = Sin512(self->values[0]);
        pXPos() *= pTimer();
        pXPos() >>= 9;
        pXPos() += self->XPos;
        scriptEng.tempValue[0] = self->values[0];
        scriptEng.tempValue[0] -= 128;
        scriptEng.tempValue[0] /= 86;
        pFrame() = scriptEng.tempValue[0];
        self->values[0] += 8;
        if (self->values[0] > 639) {
            self->values[0] -= 512;
        }
        if (pJumpPress() == 1) {
            CallScriptFunctionNamed("Player_Action_Jump", scriptSub);
            pSpeed() = pXPos();
            pSpeed() -= self->XPos;
            pSpeed() >>= 3;
            pState() = PlayerStateID("Player_State_Air");
            pTimer() = 0;
            PlaySfx(0, 0);
        }
    } else {
        if (self->values[4] == 1) {
            if (pState() == PlayerStateID("Player_State_SpinningTop")) {
                if (pGravity() == 0) {
                    pState() = PlayerStateID("Player_State_Ground");
                    self->values[4] = 0;
                    pTimer() = 0;
                } else {
                }
            }
        }
    }
    self->XPos = scriptEng.tempValue[1];
}

void O_R6_HSpinPlatform::ObjectDraw()
{
    Entity *self = Self();

    self->values[1] = Sin512(self->values[3]);
    self->values[1] <<= 13;
    self->values[1] += self->XPos;
    self->values[1] &= 0xFFFF0000;
    scriptEng.tempValue[0] = self->values[5];
    scriptEng.tempValue[0] /= 10;
    self->values[5]++;
    self->values[5] %= 20;
    DrawSprite_FrameXY(scriptEng.tempValue[0], self->values[1], self->YPos);
    scriptEng.tempValue[0] = self->values[6];
    scriptEng.tempValue[0] /= 10;
    scriptEng.tempValue[0] += 2;
    self->values[6]++;
    self->values[6] %= 60;
    DrawSprite_FrameXY(scriptEng.tempValue[0], self->values[1], self->YPos);
}

#endif // RETRO_USE_NATIVE_OBJECTS

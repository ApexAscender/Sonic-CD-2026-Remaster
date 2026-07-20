#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R1_SpinTop.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from SpinTop.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R1_SpinTop::ObjectStartup()
{
    LoadSpriteSheet("R1/Objects.gif");
    AddSpriteFrame(-16, -8, 32, 16, 101, 76);
    AddSpriteFrame(-16, -8, 32, 16, 101, 76);
    AddSpriteFrame(-16, -8, 32, 16, 134, 76);
}

void O_R1_SpinTop::ObjectPlayerInteraction()
{
    Entity *self = Self();

    PlayerObjectCollision(C_BOX, -16, -8, 16, 24);
    scriptEng.tempValue[1] = self->values[0];
    if (CheckResult() == 1) {
        if (pState() != PlayerStateID("Player_State_SpinningTop")) {
            pSpeed() = 0;
            self->values[1] = 1;
            PlayerValue(6) = 0x1000;
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
                pTimer() -= 0x1000;
            }
            if (pRight() == 1) {
                pTimer() += 0x1000;
            }
        } else {
            if (pLeft() == 1) {
                pTimer() += 0x1000;
            }
            if (pRight() == 1) {
                pTimer() -= 0x1000;
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
        self->values[0] += 16;
        if (self->values[0] > 639) {
            self->values[0] -= 512;
        }
        if (pJumpPress() == 1) {
            CallScriptFunctionNamed("Player_Action_Jump", scriptSub);
            pSpeed() = pXPos();
            pSpeed() -= self->XPos;
            pSpeed() >>= 2;
            pState() = PlayerStateID("Player_State_Air");
            pTimer() = 0;
            PlaySfx(globalSFXCount + 1, 0);
        }
    } else {
        if (self->values[1] == 1) {
            if (pState() == PlayerStateID("Player_State_SpinningTop")) {
                if (pGravity() == 0) {
                    pState() = PlayerStateID("Player_State_Ground");
                    self->values[1] = 0;
                    pTimer() = 0;
                }
            }
        }
    }
}

void O_R1_SpinTop::ObjectDraw()
{
    Entity *self = Self();

    DrawSprite_Frame(self->frame);
    scriptEng.tempValue[0] = GVar("Ring.AniCount");
    scriptEng.tempValue[0] &= 1;
    if (scriptEng.tempValue[0] == 0) {
        self->frame++;
        if (self->frame > 2) {
            self->frame = 0;
        }
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS

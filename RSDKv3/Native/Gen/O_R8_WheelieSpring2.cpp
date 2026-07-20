#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R8_WheelieSpring2.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from WheelieSpring2.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R8_WheelieSpring2::ObjectStartup()
{
    LoadSpriteSheet("Global/Items.gif");
    AddSpriteFrame(-16, -16, 32, 16, 84, 1);
    AddSpriteFrame(-16, -8, 32, 8, 84, 1);
    AddSpriteFrame(-16, -40, 32, 40, 84, 18);
    AddSpriteFrame(-8, 0, 16, 16, 233, 0);
    AddSpriteFrame(-8, 0, 16, 16, 233, 17);
}

void O_R8_WheelieSpring2::ObjectMain()
{
    Entity *self = Self();

    if (self->state == 0) {
        if (self->values[0] < self->propertyValue) {
            self->values[0]++;
            self->XPos += 0x10000;
        } else {
            self->state = 1;
            self->values[0] = self->propertyValue;
            self->values[0] = -self->values[0];
        }
    } else {
        if (self->values[0] < self->propertyValue) {
            self->values[0]++;
            self->XPos -= 0x10000;
        } else {
            self->state = 0;
            self->values[0] = self->propertyValue;
            self->values[0] = -self->values[0];
        }
    }
    ObjectTileGrip_Script(0, 0, 15, 0);
}

void O_R8_WheelieSpring2::ObjectPlayerInteraction()
{
    Entity *self = Self();

    if (pState() != PlayerStateID("Player_State_Static")) {
        if (pYVel() >= 0) {
            PlayerObjectCollision(C_BOX, -16, -16, 16, 16);
            PlayerObjectCollision(C_TOUCH, -15, -18, 15, -12);
            if (CheckResult() == 1) {
                self->frame = 1;
                pState() = PlayerStateID("Player_State_Air");
                pGravity() = 1;
                pYVel() = -0x100000;
                PlayerValue(7) = GVar("ANI_WALKING");
                if (pAnimation() == GVar("ANI_RUNNING")) {
                    PlayerValue(7) = GVar("ANI_RUNNING");
                }
                if (pAnimation() == GVar("ANI_PEELOUT")) {
                    PlayerValue(7) = GVar("ANI_PEELOUT");
                }
                pAnimation() = GVar("ANI_BOUNCING");
                pTimer() = 0;
                PlaySfx(11, 0);
                HapticEffect_Script(9, 0, 0, 0);
            }
        }
        if (pGravity() == 0) {
            PlayerObjectCollision(C_BOX, -16, -20, 16, 16);
            PlayerObjectCollision(C_TOUCH, -15, -18, 15, -12);
            if (CheckResult() == 1) {
                self->frame = 1;
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
}

void O_R8_WheelieSpring2::ObjectDraw()
{
    Entity *self = Self();

    if (self->frame == 0) {
        DrawSprite_Frame(0);
    } else {
        self->frame++;
        scriptEng.tempValue[0] = self->frame;
        scriptEng.tempValue[0] >>= 1;
        switch (scriptEng.tempValue[0]) {
            case 0:
            case 1:
            DrawSprite_Frame(0);
            break;
            case 2:
            case 6:
            DrawSprite_Frame(1);
            break;
            case 3:
            case 4:
            case 5:
            DrawSprite_Frame(2);
            break;
        }
        if (self->frame > 12) {
            self->frame = 0;
        }
    }
    scriptEng.tempValue[0] = self->values[0];
    scriptEng.tempValue[0] += self->propertyValue;
    scriptEng.tempValue[0] %= 18;
    scriptEng.tempValue[0] /= 9;
    scriptEng.tempValue[0] += 3;
    DrawSprite_Frame(scriptEng.tempValue[0]);
}

#endif // RETRO_USE_NATIVE_OBJECTS

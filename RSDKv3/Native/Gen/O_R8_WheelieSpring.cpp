#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R8_WheelieSpring.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from WheelieSpring.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R8_WheelieSpring::ObjectStartup()
{
    LoadSpriteSheet("Global/Items.gif");
    AddSpriteFrame(-16, -16, 32, 16, 84, 1);
    AddSpriteFrame(-16, -16, 32, 16, 84, 183);
    AddSpriteFrame(-16, -8, 32, 8, 84, 1);
    AddSpriteFrame(-16, -8, 32, 8, 84, 183);
    AddSpriteFrame(-16, -40, 32, 40, 84, 18);
    AddSpriteFrame(-16, -40, 32, 40, 215, 34);
    AddSpriteFrame(-8, 0, 16, 16, 233, 0);
    AddSpriteFrame(-8, 0, 16, 16, 233, 17);
}

void O_R8_WheelieSpring::ObjectMain()
{
    Entity *self = Self();

    if (self->state == 0) {
        if (self->values[0] < 96) {
            self->values[0]++;
            self->XPos += 0x10000;
            ObjectTileGrip_Script(0, 8, 15, 0);
            if (CheckResult() == 0) {
                self->state = 1;
                self->values[0] = -64;
            } else {
                ObjectTileCollision_Script(1, 40, -16, 0);
                if (CheckResult() == 1) {
                    self->state = 1;
                    self->values[0] = -64;
                }
            }
            ObjectTileGrip_Script(0, 0, 15, 0);
        } else {
            self->state = 1;
            self->values[0] = -64;
        }
    } else {
        if (self->values[0] < 96) {
            self->values[0]++;
            self->XPos -= 0x10000;
            ObjectTileGrip_Script(0, -8, 15, 0);
            if (CheckResult() == 0) {
                self->state = 0;
                self->values[0] = -64;
            } else {
                ObjectTileCollision_Script(3, -40, -16, 0);
                if (CheckResult() == 1) {
                    self->state = 0;
                    self->values[0] = -64;
                }
            }
            ObjectTileGrip_Script(0, 0, 15, 0);
        } else {
            self->state = 0;
            self->values[0] = -64;
        }
    }
}

void O_R8_WheelieSpring::ObjectPlayerInteraction()
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
                if (self->propertyValue == 0) {
                    pYVel() = -0x100000;
                } else {
                    pYVel() = -0xA0000;
                }
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
            }
        }
        if (pGravity() == 0) {
            PlayerObjectCollision(C_BOX, -16, -20, 16, 16);
            PlayerObjectCollision(C_TOUCH, -15, -18, 15, -12);
            if (CheckResult() == 1) {
                self->frame = 1;
                pState() = PlayerStateID("Player_State_Air");
                pGravity() = 1;
                if (self->propertyValue == 0) {
                    pYVel() = -0x100000;
                } else {
                    pYVel() = -0xA0000;
                }
                pAnimation() = GVar("ANI_BOUNCING");
                pTimer() = 0;
                PlaySfx(11, 0);
            }
        }
    }
}

void O_R8_WheelieSpring::ObjectDraw()
{
    Entity *self = Self();

    if (self->propertyValue == 0) {
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
                DrawSprite_Frame(2);
                break;
                case 3:
                case 4:
                case 5:
                DrawSprite_Frame(4);
                break;
            }
            if (self->frame > 12) {
                self->frame = 0;
            }
        }
    } else {
        if (self->frame == 0) {
            DrawSprite_Frame(1);
        } else {
            self->frame++;
            scriptEng.tempValue[0] = self->frame;
            scriptEng.tempValue[0] >>= 1;
            switch (scriptEng.tempValue[0]) {
                case 0:
                case 1:
                DrawSprite_Frame(1);
                break;
                case 2:
                case 6:
                DrawSprite_Frame(3);
                break;
                case 3:
                case 4:
                case 5:
                DrawSprite_Frame(5);
                break;
            }
            if (self->frame > 12) {
                self->frame = 0;
            }
        }
    }
    scriptEng.tempValue[0] = self->values[0];
    scriptEng.tempValue[0] += 64;
    scriptEng.tempValue[0] %= 18;
    scriptEng.tempValue[0] /= 9;
    scriptEng.tempValue[0] += 6;
    DrawSprite_Frame(scriptEng.tempValue[0]);
}

#endif // RETRO_USE_NATIVE_OBJECTS

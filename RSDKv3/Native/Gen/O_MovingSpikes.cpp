#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_MovingSpikes.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from MovingSpikes.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_MovingSpikes::ObjectStartup()
{
    LoadSpriteSheet("Global/Items3.gif");
    AddSpriteFrame(-16, -16, 32, 32, 50, 1);
    AddSpriteFrame(-16, -16, 32, 32, 50, 34);
    AddSpriteFrame(-16, -16, 32, 32, 50, 67);
    AddSpriteFrame(-16, -16, 32, 32, 50, 100);
}

void O_MovingSpikes::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        if (self->values[0] < 60) {
            self->values[0]++;
        } else {
            self->state = 1;
            self->values[0] = 0;
            PlaySfx(globalSFXCount + 4, 0);
        }
        break;
        case 1:
        if (self->values[1] < 0x200000) {
            self->values[1] += 0x80000;
        } else {
            self->state = 2;
        }
        break;
        case 2:
        if (self->values[0] < 60) {
            self->values[0]++;
        } else {
            self->state = 3;
            self->values[0] = 0;
            PlaySfx(globalSFXCount + 4, 0);
        }
        break;
        case 3:
        if (self->values[1] > 0) {
            self->values[1] -= 0x80000;
        } else {
            self->state = 0;
        }
        break;
    }
}

void O_MovingSpikes::ObjectPlayerInteraction()
{
    Entity *self = Self();

    scriptEng.tempValue[0] = self->values[1];
    scriptEng.tempValue[0] >>= 16;
    scriptEng.tempValue[0] -= 16;
    scriptEng.tempValue[1] = scriptEng.tempValue[0];
    scriptEng.tempValue[1] += 32;
    switch (self->propertyValue) {
        case 0:
        if (pState() != PlayerStateID("Player_State_Hurt")) {
            PlayerObjectCollision(C_BOX, -16, scriptEng.tempValue[0], 16, scriptEng.tempValue[1]);
        }
        if (self->state != 2) {
            if (pYVel() > -1) {
                if (PlayerValue(4) == 0) {
                    PlayerObjectCollision(C_TOUCH, -15, -18, 15, -12);
                    if (CheckResult() == 1) {
                        pState() = PlayerStateID("Player_State_GotHit");
                        pGravity() = 1;
                        pYPos() -= 0x10000;
                        if (pXPos() > self->XPos) {
                            pSpeed() = 0x20000;
                        } else {
                            pSpeed() = -0x20000;
                        }
                    }
                }
            }
        }
        break;
        case 1:
        scriptEng.tempValue[0] = -scriptEng.tempValue[0];
        scriptEng.tempValue[1] = -scriptEng.tempValue[1];
        PlayerObjectCollision(C_BOX, scriptEng.tempValue[1], -16, scriptEng.tempValue[0], 16);
        if (self->state != 2) {
            if (PlayerValue(4) == 0) {
                PlayerObjectCollision(C_TOUCH, 8, -15, 18, 15);
                if (CheckResult() == 1) {
                    pState() = PlayerStateID("Player_State_GotHit");
                    pSpeed() = 0x20000;
                }
            }
        }
        break;
        case 2:
        PlayerObjectCollision(C_BOX, scriptEng.tempValue[0], -16, scriptEng.tempValue[1], 16);
        if (self->state != 2) {
            if (PlayerValue(4) == 0) {
                PlayerObjectCollision(C_TOUCH, -18, -15, -8, 15);
                if (CheckResult() == 1) {
                    pState() = PlayerStateID("Player_State_GotHit");
                    pSpeed() = -0x20000;
                }
            }
        }
        break;
        case 3:
        scriptEng.tempValue[0] = -scriptEng.tempValue[0];
        scriptEng.tempValue[1] = -scriptEng.tempValue[1];
        PlayerObjectCollision(C_BOX, -16, scriptEng.tempValue[1], 16, scriptEng.tempValue[0]);
        if (self->state != 2) {
            if (pYVel() < 1) {
                if (PlayerValue(4) == 0) {
                    PlayerObjectCollision(C_TOUCH, -14, 12, 14, 18);
                    if (CheckResult() == 1) {
                        pState() = PlayerStateID("Player_State_GotHit");
                        if (pXPos() > self->XPos) {
                            pSpeed() = 0x20000;
                        } else {
                            pSpeed() = -0x20000;
                        }
                    }
                }
            }
        }
        break;
    }
}

void O_MovingSpikes::ObjectDraw()
{
    Entity *self = Self();

    switch (self->propertyValue) {
        case 0:
        scriptEng.tempValue[0] = self->YPos;
        scriptEng.tempValue[0] += self->values[1];
        DrawSprite_FrameXY(self->propertyValue, self->XPos, scriptEng.tempValue[0]);
        break;
        case 1:
        scriptEng.tempValue[0] = self->XPos;
        scriptEng.tempValue[0] -= self->values[1];
        DrawSprite_FrameXY(self->propertyValue, scriptEng.tempValue[0], self->YPos);
        break;
        case 2:
        scriptEng.tempValue[0] = self->XPos;
        scriptEng.tempValue[0] += self->values[1];
        DrawSprite_FrameXY(self->propertyValue, scriptEng.tempValue[0], self->YPos);
        break;
        case 3:
        scriptEng.tempValue[0] = self->YPos;
        scriptEng.tempValue[0] -= self->values[1];
        DrawSprite_FrameXY(self->propertyValue, self->XPos, scriptEng.tempValue[0]);
        break;
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS

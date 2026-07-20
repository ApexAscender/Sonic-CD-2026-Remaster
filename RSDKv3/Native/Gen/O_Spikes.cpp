#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_Spikes.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from Spikes.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_Spikes::ObjectStartup()
{
    LoadSpriteSheet("Global/Items3.gif");
    AddSpriteFrame(-16, -16, 32, 32, 50, 1);
    AddSpriteFrame(-16, -16, 32, 32, 50, 34);
    AddSpriteFrame(-16, -16, 32, 32, 50, 67);
    AddSpriteFrame(-16, -16, 32, 32, 50, 100);
}

void O_Spikes::ObjectPlayerInteraction()
{
    Entity *self = Self();

    switch (self->propertyValue) {
        case 0:
        PlayerObjectCollision(C_BOX, -16, -12, 16, 16);
        if (pYVel() > -1) {
            if (PlayerValue(4) == 0) {
                PlayerObjectCollision(C_TOUCH, -15, -13, 15, -12);
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
        break;
        case 1:
        PlayerObjectCollision(C_BOX, -16, -16, 15, 16);
        if (pXVel() <= 0) {
            if (PlayerValue(4) == 0) {
                PlayerObjectCollision(C_TOUCH, 12, -15, 16, 15);
                if (CheckResult() == 1) {
                    pState() = PlayerStateID("Player_State_GotHit");
                    pSpeed() = 0x20000;
                }
            }
        }
        break;
        case 2:
        PlayerObjectCollision(C_BOX, -15, -16, 16, 16);
        if (PlayerValue(4) == 0) {
            PlayerObjectCollision(C_TOUCH, -16, -15, -12, 15);
            if (CheckResult() == 1) {
                pState() = PlayerStateID("Player_State_GotHit");
                pSpeed() = -0x20000;
            }
        }
        break;
        case 3:
        scriptEng.tempValue[0] = pYVel();
        PlayerObjectCollision(C_BOX, -16, -16, 16, 15);
        if (scriptEng.tempValue[0] < 1) {
            if (PlayerValue(4) == 0) {
                PlayerObjectCollision(C_TOUCH, -15, 12, 15, 16);
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
        break;
    }
}

void O_Spikes::ObjectDraw()
{
    Entity *self = Self();

    DrawSprite_Frame(self->propertyValue);
}

#endif // RETRO_USE_NATIVE_OBJECTS

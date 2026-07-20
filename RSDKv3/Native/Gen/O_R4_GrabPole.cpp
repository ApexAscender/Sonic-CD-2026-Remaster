#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R4_GrabPole.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from GrabPole.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R4_GrabPole::ObjectStartup()
{
    LoadSpriteSheet("R4/Objects3.gif");
    if (objectEntityList[24].propertyValue < 3) {
        AddSpriteFrame(-4, -46, 8, 92, 134, 46);
        AddSpriteFrame(-4, -46, 16, 92, 117, 46);
    } else {
        AddSpriteFrame(-4, -46, 8, 92, 51, 163);
        AddSpriteFrame(-4, -46, 16, 92, 34, 163);
    }
}

void O_R4_GrabPole::ObjectMain()
{
    Entity *self = Self();

    if (self->state == 1) {
        if (pState() == PlayerStateID("Player_State_Death")) {
            self->state = 0;
        }
        if (pState() == PlayerStateID("Player_State_Drown")) {
            self->state = 0;
        }
        if (self->state > 0) {
            if (self->values[0] < 180) {
                self->values[0]++;
                pXPos() = self->XPos;
                pDirection() = 0;
                if (playerListPos == 0) {
                    pXPos() += 0x140000;
                } else {
                    pXPos() += 0x100000;
                }
            } else {
                self->frame = 1;
                self->state = 2;
                pState() = PlayerStateID("Player_State_Air");
            }
        }
    }
}

void O_R4_GrabPole::ObjectPlayerInteraction()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        PlayerObjectCollision(C_TOUCH, 16, -28, 32, 28);
        if (CheckResult() == 1) {
            self->state = 1;
            pState() = PlayerStateID("Player_State_Static");
            pAnimation() = GVar("ANI_CLINGING");
            pDirection() = 0;
            pSpeed() = 0;
            pXVel() = 0;
            pYVel() = 0;
        }
        break;
        case 1:
        if (pUp() == 1) {
            pYPos() -= 0x10000;
        }
        if (pDown() == 1) {
            pYPos() += 0x10000;
        }
        if (pJumpPress() == 1) {
            self->frame = 1;
            self->state = 2;
            pState() = PlayerStateID("Player_State_Air");
        }
        PlayerObjectCollision(C_BOX, 0, -64, 32, -46);
        PlayerObjectCollision(C_BOX, 0, 46, 32, 64);
        break;
    }
}

void O_R4_GrabPole::ObjectDraw()
{
    Entity *self = Self();

    DrawSprite_Frame(self->frame);
}

#endif // RETRO_USE_NATIVE_OBJECTS

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R1_BouncePole.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from BouncePole.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R1_BouncePole::ObjectStartup()
{
    LoadSpriteSheet("R1/Objects.gif");
    AddSpriteFrame(-16, -8, 32, 16, 190, 34);
    AddSpriteFrame(-16, -8, 32, 16, 190, 34);
    AddSpriteFrame(-16, -8, 32, 20, 190, 80);
    AddSpriteFrame(-16, -8, 32, 16, 190, 34);
    AddSpriteFrame(-16, -20, 32, 28, 190, 51);
    AddSpriteFrame(-16, -8, 32, 16, 190, 34);
    AddSpriteFrame(-16, -8, 32, 20, 190, 80);
    AddSpriteFrame(-16, -8, 32, 16, 190, 34);
    AddSpriteFrame(-16, -8, 32, 16, 190, 34);
    AddSpriteFrame(-16, -8, 32, 20, 190, 80);
    AddSpriteFrame(-16, -8, 32, 16, 190, 34);
    AddSpriteFrame(-16, -20, 32, 28, 190, 51);
    AddSpriteFrame(-16, -8, 32, 16, 190, 34);
    AddSpriteFrame(-16, -8, 32, 20, 190, 80);
    AddSpriteFrame(-16, -8, 32, 16, 190, 34);
    AddSpriteFrame(-16, -8, 32, 16, 190, 34);
    AddSpriteFrame(-16, -8, 32, 20, 190, 80);
    AddSpriteFrame(-16, -8, 32, 16, 190, 34);
    AddSpriteFrame(-16, -20, 32, 28, 190, 51);
    AddSpriteFrame(-16, -8, 32, 16, 190, 34);
    AddSpriteFrame(-16, -8, 32, 20, 190, 80);
}

void O_R1_BouncePole::ObjectPlayerInteraction()
{
    Entity *self = Self();

    PlayerObjectCollision(C_TOUCH, -16, -8, 16, 8);
    if (CheckResult() == 1) {
        if (pGravity() == 1) {
            if (pYVel() > 0) {
                pState() = PlayerStateID("Player_State_Air");
                pTimer() = 0;
                pAnimation() = GVar("ANI_JUMPING");
                pYVel() = -pYVel();
                pYVel() -= 0x20000;
                if (pYVel() < -0xA0000) {
                    pYVel() = -0xA0000;
                }
                self->frame = 1;
            }
        }
    }
}

void O_R1_BouncePole::ObjectDraw()
{
    Entity *self = Self();

    self->direction = self->propertyValue;
    DrawSpriteFX_Script(self->frame, FX_FLIP, self->XPos, self->YPos);
    if (self->frame > 0) {
        self->values[0]++;
        if (self->values[0] == 3) {
            self->values[0] = 0;
            self->frame++;
            if (self->frame > 20) {
                self->frame = 0;
            }
        }
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS

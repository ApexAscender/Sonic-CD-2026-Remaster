#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R6_PohBeeBullet.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from PohBeeBullet.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R6_PohBeeBullet::ObjectStartup()
{
    LoadSpriteSheet("R6/Objects.gif");
    AddSpriteFrame(-8, -8, 16, 16, 197, 68);
    AddSpriteFrame(-8, -8, 16, 16, 69, 117);
    AddSpriteFrame(-8, -8, 16, 16, 1, 134);
    AddSpriteFrame(-8, -8, 16, 16, 17, 134);
}

void O_R6_PohBeeBullet::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        if (self->values[0] < 4) {
            self->values[0]++;
        } else {
            self->values[0] = 0;
            self->state++;
            self->frame = 1;
        }
        break;
        case 1:
        self->XPos += self->values[1];
        self->YPos += self->values[2];
        if (self->values[0] < 12) {
            self->values[0]++;
        } else {
            self->values[0] = 0;
            self->state++;
            self->frame = 2;
        }
        break;
        case 2:
        self->XPos += self->values[1];
        self->YPos += self->values[2];
        if (self->values[0] > 1) {
            self->frame = 3;
        } else {
            self->frame = 2;
        }
        self->values[0]++;
        self->values[0] &= 3;
        break;
    }
    if (GetObjectOutOfBounds(objectLoop) == 1) {
        self->type = TypeNameID("Blank Object");
    }
}

void O_R6_PohBeeBullet::ObjectPlayerInteraction()
{
    Entity *self = Self();

    if (self->state > 0) {
        PlayerObjectCollision(C_TOUCH, -6, -6, 6, 6);
        if (CheckResult() == 1) {
            CallScriptFunctionNamed("Player_Hit", scriptSub);
        }
    }
}

void O_R6_PohBeeBullet::ObjectDraw()
{
    Entity *self = Self();

    DrawSpriteFX_Script(self->frame, FX_FLIP, self->XPos, self->YPos);
}

#endif // RETRO_USE_NATIVE_OBJECTS

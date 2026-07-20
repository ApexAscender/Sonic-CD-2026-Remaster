#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R1_Flower.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from Flower.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R1_Flower::ObjectStartup()
{
    LoadSpriteSheet("R1/Objects2.gif");
    AddSpriteFrame(-4, -8, 8, 16, 180, 1);
    AddSpriteFrame(-4, -8, 8, 16, 180, 18);
    AddSpriteFrame(-8, -16, 16, 16, 26, 229);
    AddSpriteFrame(-8, -16, 16, 16, 43, 229);
    AddSpriteFrame(-8, -16, 16, 16, 60, 229);
    AddSpriteFrame(-12, -24, 24, 24, 165, 90);
    AddSpriteFrame(-12, -48, 24, 48, 165, 66);
    AddSpriteFrame(-12, -48, 24, 48, 165, 115);
    AddSpriteFrame(0, 0, 0, 0, 0, 0);
}

void O_R1_Flower::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        self->frame = 8;
        self->values[0]++;
        if (self->values[0] == 20) {
            self->values[0] = 0;
            self->state++;
        }
        break;
        case 1:
        self->frame = self->values[0];
        self->frame >>= 2;
        self->values[0]++;
        self->values[0] &= 7;
        self->YPos += 0x20000;
        ObjectTileCollision_Script(0, 0, 8, 0);
        if (CheckResult() == 1) {
            self->YPos += 0x80000;
            self->state++;
            self->values[0] = 0;
            self->frame = 2;
        }
        break;
        case 2:
        self->values[0]++;
        if (self->values[0] == 4) {
            self->values[0] = 0;
            self->state++;
            self->frame = 3;
        }
        break;
        case 3:
        self->values[0]++;
        if (self->values[0] == 4) {
            self->values[0] = 0;
            self->state++;
            self->frame = 2;
        }
        break;
        case 4:
        self->values[0]++;
        if (self->values[0] == 4) {
            self->values[0] = 0;
            self->state++;
            self->frame = 3;
        }
        break;
        case 5:
        self->values[0]++;
        if (self->values[0] == 5) {
            self->values[0] = 0;
            self->state++;
            self->frame = 4;
        }
        break;
        case 6:
        self->values[0]++;
        if (self->values[0] == 4) {
            self->values[0] = 0;
            self->state++;
            self->frame = 5;
        }
        break;
        case 7:
        self->values[0]++;
        if (self->values[0] == 2) {
            self->values[0] = 0;
            self->state++;
            self->frame = 6;
        }
        break;
        case 8:
        self->values[0]++;
        if (self->values[0] == 20) {
            self->values[0] = 0;
            self->state++;
            self->frame = 7;
        }
        break;
        case 9:
        self->values[0]++;
        if (self->values[0] == 20) {
            self->values[0] = 0;
            self->state--;
            self->frame = 6;
        }
        break;
    }
}

void O_R1_Flower::ObjectDraw()
{
    Entity *self = Self();

    DrawSprite_Frame(self->frame);
}

#endif // RETRO_USE_NATIVE_OBJECTS

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R4_CountdownBubble.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from CountdownBubble.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R4_CountdownBubble::ObjectStartup()
{
    LoadSpriteSheet("R4/Objects2.gif");
    AddSpriteFrame(-4, -4, 8, 8, 35, 135);
    AddSpriteFrame(-4, -4, 8, 8, 44, 135);
    AddSpriteFrame(-4, -4, 8, 8, 53, 135);
    AddSpriteFrame(-8, -8, 16, 16, 101, 210);
    AddSpriteFrame(-8, -12, 16, 24, 101, 185);
    AddSpriteFrame(-8, -12, 16, 24, 67, 135);
    AddSpriteFrame(-8, -12, 0, 0, 67, 135);
    AddSpriteFrame(-8, -12, 16, 24, 84, 210);
    AddSpriteFrame(-8, -12, 16, 24, 84, 135);
    AddSpriteFrame(-8, -12, 0, 0, 67, 135);
    AddSpriteFrame(-8, -12, 16, 24, 67, 210);
    AddSpriteFrame(-8, -12, 16, 24, 67, 160);
    AddSpriteFrame(-8, -12, 0, 0, 67, 135);
    AddSpriteFrame(-8, -12, 16, 24, 84, 210);
    AddSpriteFrame(-8, -12, 16, 24, 84, 160);
    AddSpriteFrame(-8, -12, 0, 0, 67, 135);
    AddSpriteFrame(-8, -12, 16, 24, 84, 210);
    AddSpriteFrame(-8, -12, 16, 24, 67, 185);
    AddSpriteFrame(-8, -12, 0, 0, 67, 135);
    AddSpriteFrame(-8, -12, 16, 24, 101, 160);
    AddSpriteFrame(-8, -12, 16, 24, 84, 185);
    AddSpriteFrame(-8, -12, 0, 0, 67, 135);
}

void O_R4_CountdownBubble::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        self->YPos += self->values[3];
        self->values[0]++;
        if (self->values[0] > 6) {
            self->values[0] = 0;
            self->frame++;
        }
        if (self->frame < 4) {
            self->XPos = Sin512(self->values[1]);
            self->XPos <<= 9;
            self->XPos += self->values[2];
            self->values[1] += 4;
            self->values[1] &= 511;
        } else {
            scriptEng.tempValue[0] = self->propertyValue;
            scriptEng.tempValue[0] *= 3;
            self->frame += scriptEng.tempValue[0];
            self->values[2] = (objectEntityList[objectLoop].XPos >> 16);
            self->values[2] -= xScrollOffset;
            self->values[4] = (objectEntityList[objectLoop].YPos >> 16);
            self->values[4] -= yScrollOffset;
            self->state++;
        }
        break;
        case 1:
        self->values[0]++;
        if (self->values[0] == 6) {
            self->values[0] = 0;
            self->frame++;
            self->state++;
        }
        break;
        case 2:
        self->values[0]++;
        if (self->values[0] == 6) {
            self->values[0] = 0;
            self->frame++;
            self->state++;
        }
        break;
        case 3:
        self->values[0]++;
        if (self->values[0] == 8) {
            self->values[0] = 0;
            self->frame--;
            self->state++;
        }
        break;
        case 4:
        self->values[0]++;
        if (self->values[0] == 8) {
            self->values[0] = 0;
            self->frame++;
            self->state++;
        }
        break;
        case 5:
        self->values[0]++;
        if (self->values[0] == 8) {
            self->values[0] = 0;
            self->frame--;
            self->state++;
        }
        break;
        case 6:
        self->values[0]++;
        if (self->values[0] == 8) {
            self->values[0] = 0;
            self->frame++;
            self->state++;
        }
        break;
        case 7:
        self->values[0]++;
        if (self->values[0] == 8) {
            self->values[0] = 0;
            self->frame--;
            self->state++;
        }
        break;
        case 8:
        self->values[0]++;
        if (self->values[0] == 9) {
            self->type = TypeNameID("Blank Object");
        }
        break;
    }
}

void O_R4_CountdownBubble::ObjectDraw()
{
    Entity *self = Self();

    if (self->state == 0) {
        DrawSprite_Frame(self->frame);
    } else {
        DrawSprite_ScreenXY(self->frame, self->values[2], self->values[4]);
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS

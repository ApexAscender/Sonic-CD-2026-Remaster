#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R5_Eggman.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from Eggman.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R5_Eggman::ObjectStartup()
{
    LoadSpriteSheet("R5/Objects2.gif");
    AddSpriteFrame(-24, -24, 40, 56, 174, 181);
    AddSpriteFrame(-24, -24, 40, 56, 215, 181);
    AddSpriteFrame(-24, -24, 48, 48, 158, 18);
    AddSpriteFrame(-24, -24, 48, 48, 207, 18);
    AddSpriteFrame(-24, -24, 48, 56, 158, 67);
    AddSpriteFrame(-24, -24, 48, 56, 207, 67);
    AddSpriteFrame(-32, -25, 64, 48, 66, 138);
    AddSpriteFrame(-32, -23, 48, 56, 150, 124);
    AddSpriteFrame(-32, -21, 56, 56, 199, 124);
    AddSpriteFrame(-32, -23, 48, 56, 150, 124);
    AddSpriteFrame(-24, -40, 48, 16, 158, 1);
    AddSpriteFrame(-24, -40, 48, 16, 207, 1);
    AddSpriteFrame(-20, -40, 0, 0, 158, 1);
    AddSpriteFrame(-20, -40, 48, 16, 158, 1);
    AddSpriteFrame(-20, -40, 48, 16, 207, 1);
}

void O_R5_Eggman::ObjectDraw()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        DrawSprite_Frame(0);
        break;
        case 1:
        DrawSprite_Frame(1);
        break;
        case 2:
        scriptEng.tempValue[0] = self->frame;
        scriptEng.tempValue[0] >>= 3;
        scriptEng.tempValue[0] += 2;
        DrawSprite_Frame(scriptEng.tempValue[0]);
        self->frame++;
        self->frame &= 15;
        if (self->values[0] < 4) {
            scriptEng.tempValue[0] += 8;
            DrawSprite_Frame(scriptEng.tempValue[0]);
        }
        self->values[0]++;
        self->values[0] &= 7;
        break;
        case 3:
        scriptEng.tempValue[0] = self->frame;
        scriptEng.tempValue[0] &= 15;
        scriptEng.tempValue[0] >>= 3;
        scriptEng.tempValue[0] += 4;
        DrawSprite_Frame(scriptEng.tempValue[0]);
        self->frame++;
        if (self->values[0] < 4) {
            scriptEng.tempValue[0] += 6;
            DrawSprite_Frame(scriptEng.tempValue[0]);
        }
        self->values[0]++;
        self->values[0] &= 7;
        if (self->frame == 48) {
            self->values[0] = 0;
            self->frame = 0;
            self->state = 4;
        }
        break;
        case 4:
        DrawSprite_Frame(0);
        if (self->values[0] < 20) {
            self->values[0]++;
        } else {
            self->values[0] = 0;
            self->state = 3;
        }
        break;
        case 5:
        DrawSprite_Frame(1);
        if (self->values[0] < 20) {
            self->values[0]++;
        } else {
            self->values[0] = 0;
            self->frame = 0;
            self->state = 3;
        }
        break;
        case 6:
        scriptEng.tempValue[0] = self->frame;
        scriptEng.tempValue[0] /= 6;
        scriptEng.tempValue[0] += 6;
        DrawSprite_Frame(scriptEng.tempValue[0]);
        self->frame++;
        self->frame %= 24;
        scriptEng.tempValue[0] = self->values[0];
        scriptEng.tempValue[0] /= 6;
        scriptEng.tempValue[0] += 12;
        scriptEng.tempValue[1] = self->values[0];
        scriptEng.tempValue[1] %= 6;
        if (scriptEng.tempValue[1] < 3) {
            self->direction = 1;
            DrawSpriteFX_Script(scriptEng.tempValue[0], FX_FLIP, self->XPos, self->YPos);
            self->direction = 0;
        }
        self->values[0]++;
        self->values[0] %= 12;
        self->XPos += 0x10000;
        if (GetObjectOutOfBounds(objectLoop) == 1) {
            ResetObjectEntity(objectLoop, TypeNameID("Blank Object"), 0, 0, 0);
        }
        break;
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS

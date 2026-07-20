#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R3_Eggman.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from Eggman.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R3_Eggman::ObjectStartup()
{
    LoadSpriteSheet("R3/Objects2.gif");
    AddSpriteFrame(-24, -56, 48, 24, 1, 166);
    AddSpriteFrame(-24, -56, 48, 24, 50, 166);
    AddSpriteFrame(-24, -56, 48, 24, 148, 174);
    AddSpriteFrame(-24, -56, 48, 24, 99, 166);
    AddSpriteFrame(-24, -32, 48, 16, 148, 107);
    AddSpriteFrame(-24, -32, 48, 16, 148, 124);
    AddSpriteFrame(-16, -48, 32, 16, 84, 50);
    AddSpriteFrame(-32, -67, 56, 64, 199, 134);
    AddSpriteFrame(-23, -67, 56, 64, 199, 69);
    AddSpriteFrame(-24, -56, 48, 56, 197, 199);
    AddSpriteFrame(-24, -56, 48, 56, 147, 199);
    AddSpriteFrame(-16, -56, 72, 64, 1, 191);
    AddSpriteFrame(-16, -56, 72, 64, 74, 191);
}

void O_R3_Eggman::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        self->values[0]++;
        self->values[0] %= 40;
        break;
        case 1:
        if (self->values[1] < 41) {
            self->values[1]++;
        } else {
            self->values[1] = 0;
            self->values[0] = 0;
            if (objectEntityList[objectLoop + 1].state < 5) {
                self->state = 0;
            } else {
                self->state = 2;
            }
        }
        break;
        case 2:
        self->values[0]++;
        self->values[0] &= 31;
        break;
        case 3:
        self->values[0]++;
        self->values[0] &= 7;
        break;
    }
}

void O_R3_Eggman::ObjectDraw()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        DrawSprite_Frame(4);
        scriptEng.tempValue[0] = self->values[0];
        scriptEng.tempValue[0] /= 10;
        DrawSprite_Frame(scriptEng.tempValue[0]);
        break;
        case 1:
        scriptEng.tempValue[1] = self->values[1];
        scriptEng.tempValue[1] <<= 8;
        scriptEng.tempValue[1] /= 40;
        scriptEng.tempValue[0] = Sin512(scriptEng.tempValue[1]);
        scriptEng.tempValue[0] <<= 11;
        scriptEng.tempValue[0] = -scriptEng.tempValue[0];
        scriptEng.tempValue[0] += self->YPos;
        scriptEng.tempValue[1] = self->values[1];
        scriptEng.tempValue[1] &= 15;
        scriptEng.tempValue[1] >>= 3;
        scriptEng.tempValue[1] += 7;
        DrawSprite_FrameXY(scriptEng.tempValue[1], self->XPos, scriptEng.tempValue[0]);
        scriptEng.tempValue[0] = objectEntityList[objectLoop + 1].values[5];
        scriptEng.tempValue[0] &= 1;
        scriptEng.tempValue[0] += 4;
        DrawSprite_Frame(scriptEng.tempValue[0]);
        DrawSprite_Frame(6);
        break;
        case 2:
        scriptEng.tempValue[0] = self->values[0];
        scriptEng.tempValue[0] >>= 4;
        scriptEng.tempValue[0] += 9;
        DrawSprite_Frame(scriptEng.tempValue[0]);
        break;
        case 3:
        scriptEng.tempValue[0] = self->values[0];
        scriptEng.tempValue[0] >>= 2;
        scriptEng.tempValue[0] += 11;
        DrawSprite_Frame(scriptEng.tempValue[0]);
        self->XPos += 0x40000;
        if (GetObjectOutOfBounds(objectLoop) == 1) {
            ResetObjectEntity(objectLoop, TypeNameID("Blank Object"), 0, 0, 0);
        }
        break;
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_TAttack_BGAnimation.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from BGAnimation.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_TAttack_BGAnimation::ObjectStartup()
{
    LoadSpriteSheet("TAttack/TimeAttack.gif");
    LoadPalette("TimeAttack.act", 0, 0, 0, 256);
    MatrixTranslateXYZM(MAT_WORLD, 0, 0, 0);
    MatrixRotateXYZM(MAT_VIEW, 0, 0, 0);
    AddSpriteFrame(0, 0, 152, 30, 70, 666);
    AddSpriteFrame(0, 0, 24, 256, 463, 577);
    AddSpriteFrame(24, 0, 24, 256, 487, 577);
    AddSpriteFrame(0, 0, 448, 14, 1, 701);
    AddSpriteFrame(448, 0, 448, 14, 1, 701);
    AddSpriteFrame(0, 0, 104, 13, 358, 687);
    AddSpriteFrame(-16, 0, 80, 16, 326, 798);
    AddSpriteFrame(-16, 0, 80, 16, 326, 815);
    objectEntityList[31].type = TypeNameID("BGAnimation");
}

void O_TAttack_BGAnimation::ObjectMain()
{
    Entity *self = Self();

    self->values[1]--;
    if (self->values[1] < -31) {
        self->values[1] += 32;
    }
    self->values[2]++;
    if (self->values[2] > -1) {
        self->values[2] -= 32;
    }
    self->values[3]++;
    if (self->values[3] > -1) {
        self->values[3] -= 96;
    }
}

void O_TAttack_BGAnimation::ObjectDraw()
{
    Entity *self = Self();

    if (self->drawOrder == 3) {
        DrawRectangle(0, 0, 2, SCREEN_YSIZE, 0, 0, 0, 255);
        scriptEng.tempValue[0] = SCREEN_CENTERX;
        scriptEng.tempValue[0] -= 32;
        DrawRectangle(0, 160, scriptEng.tempValue[0], 2, 0, 0, 0, 255);
        scriptEng.tempValue[0] += 48;
        switch (objectEntityList[0].state) {
            case 0:
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 14:
            case 16:
            case 17:
            case 18:
            case 19:
            DrawRectangle(scriptEng.tempValue[0], 0, SCREEN_CENTERX, SCREEN_YSIZE, 224, 0, 0, 255);
            DrawRectangle(scriptEng.tempValue[0], 175, SCREEN_CENTERX, 38, 0, 0, 96, 255);
            DrawRectangle(scriptEng.tempValue[0], 31, SCREEN_CENTERX, 9, 0, 0, 0, 255);
            break;
            case 6:
            case 7:
            case 8:
            case 9:
            case 10:
            case 11:
            case 12:
            case 13:
            case 15:
            DrawRectangle(scriptEng.tempValue[0], 0, SCREEN_CENTERX, 32, 224, 0, 0, 255);
            DrawRectangle(scriptEng.tempValue[0], 226, SCREEN_CENTERX, 14, 224, 0, 0, 255);
            DrawRectangle(scriptEng.tempValue[0], 31, SCREEN_CENTERX, 2, 0, 0, 0, 255);
            break;
        }
        scriptEng.tempValue[0] -= 50;
        DrawRectangle(2, 0, scriptEng.tempValue[0], 160, 160, 160, 64, 255);
        DrawRectangle(2, 162, scriptEng.tempValue[0], 78, 0, 128, 0, 255);
        scriptEng.tempValue[1] = self->values[3];
        scriptEng.tempValue[1] >>= 1;
        DrawSprite_ScreenXY(3, scriptEng.tempValue[1], 226);
        DrawSprite_ScreenXY(4, scriptEng.tempValue[1], 226);
        scriptEng.tempValue[0] += 2;
        scriptEng.tempValue[1] = self->values[1];
        scriptEng.tempValue[1] >>= 1;
        DrawSprite_ScreenXY(1, scriptEng.tempValue[0], scriptEng.tempValue[1]);
        scriptEng.tempValue[1] = self->values[2];
        scriptEng.tempValue[1] >>= 1;
        DrawSprite_ScreenXY(2, scriptEng.tempValue[0], scriptEng.tempValue[1]);
        drawListEntries[4].entityRefs[drawListEntries[4].listSize] = objectLoop;
        drawListEntries[4].listSize++;
        self->drawOrder = 4;
    } else {
        DrawRectangle(0, 213, SCREEN_XSIZE, 13, 0, 0, 0, 255);
        DrawSprite_ScreenXY(0, 24, 195);
        scriptEng.tempValue[0] = SCREEN_CENTERX;
        scriptEng.tempValue[0] += 19;
        DrawSprite_ScreenXY(5, scriptEng.tempValue[0], 213);
        if (objectEntityList[0].values[7] == 1) {
            scriptEng.tempValue[0] = SCREEN_XSIZE;
            scriptEng.tempValue[0] -= 64;
            scriptEng.tempValue[1] = objectEntityList[40].XPos;
            scriptEng.tempValue[1] -= -0x480000;
            scriptEng.tempValue[1] >>= 17;
            scriptEng.tempValue[0] += scriptEng.tempValue[1];
            if (objectEntityList[0].values[3] == 8) {
                DrawSprite_ScreenXY(7, scriptEng.tempValue[0], 197);
            } else {
                DrawSprite_ScreenXY(6, scriptEng.tempValue[0], 197);
            }
        }
        self->drawOrder = 3;
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS

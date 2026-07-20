#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_LBoards_BGAnimation.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from BGAnimation.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_LBoards_BGAnimation::ObjectStartup()
{
    LoadSpriteSheet("LBoards/Leaderboards.gif");
    LoadPalette("TimeAttack.act", 0, 0, 0, 256);
    MatrixTranslateXYZM(MAT_WORLD, 0, 0, 0);
    MatrixRotateXYZM(MAT_VIEW, 0, 0, 0);
    AddSpriteFrame(0, 0, 152, 30, 70, 90);
    AddSpriteFrame(0, 0, 24, 256, 463, 1);
    AddSpriteFrame(24, 0, 24, 256, 487, 1);
    AddSpriteFrame(0, 0, 448, 14, 1, 125);
    AddSpriteFrame(448, 0, 448, 14, 1, 125);
    AddSpriteFrame(0, 0, 104, 13, 358, 111);
    AddSpriteFrame(0, 0, 64, 16, 326, 188);
    AddSpriteFrame(0, 0, 64, 16, 326, 205);
    objectEntityList[31].type = TypeNameID("BG Animation");
}

void O_LBoards_BGAnimation::ObjectMain()
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

void O_LBoards_BGAnimation::ObjectDraw()
{
    Entity *self = Self();

    if (self->drawOrder == 3) {
        DrawRectangle(0, 0, 2, SCREEN_YSIZE, 0, 0, 0, 255);
        scriptEng.tempValue[0] = SCREEN_CENTERX;
        scriptEng.tempValue[0] -= 20;
        DrawRectangle(0, 160, scriptEng.tempValue[0], 2, 0, 0, 0, 255);
        scriptEng.tempValue[0] += 36;
        DrawRectangle(scriptEng.tempValue[0], 0, SCREEN_CENTERX, SCREEN_YSIZE, 224, 0, 0, 255);
        DrawRectangle(scriptEng.tempValue[0], 175, SCREEN_CENTERX, 38, 0, 0, 96, 255);
        scriptEng.tempValue[0] -= 38;
        DrawRectangle(2, 0, scriptEng.tempValue[0], 160, 160, 160, 64, 255);
        DrawRectangle(2, 162, scriptEng.tempValue[0], 78, 0, 128, 0, 255);
        DrawRectangle(0, 31, SCREEN_XSIZE, 9, 0, 0, 0, 255);
        scriptEng.tempValue[1] = self->values[3];
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
        DrawSprite_ScreenXY(0, 16, 195);
        scriptEng.tempValue[0] = SCREEN_CENTERX;
        scriptEng.tempValue[0] += 19;
        DrawSprite_ScreenXY(5, scriptEng.tempValue[0], 213);
        self->drawOrder = 3;
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS

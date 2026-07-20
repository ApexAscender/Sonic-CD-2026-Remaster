#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_TitleCards_SS_TitleCard.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from SS_TitleCard.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_TitleCards_SS_TitleCard::ObjectStartup()
{
    switch (Engine.language) {
        case 0:
        case 5:
        LoadSpriteSheet("Special/ScoreScreen.gif");
        break;
        case 1:
        LoadSpriteSheet("Special/ScoreScreen_FR.gif");
        break;
        case 2:
        LoadSpriteSheet("Special/ScoreScreen_IT.gif");
        break;
        case 3:
        LoadSpriteSheet("Special/ScoreScreen_DE.gif");
        break;
        case 4:
        LoadSpriteSheet("Special/ScoreScreen_ES.gif");
        break;
    }
    objectEntityList[20].type = TypeNameID("TitleCard");
    objectEntityList[20].values[3] = 384;
    objectEntityList[20].priority = 1;
    objectEntityList[20].drawOrder = 6;
    objectEntityList[20].values[0] = -216;
    objectEntityList[20].values[1] = 336;
    objectEntityList[20].values[7] = SCREEN_CENTERX;
    objectEntityList[20].values[7] -= 160;
    if (objectEntityList[20].values[7] > 3) {
        objectEntityList[20].values[7] -= 4;
    }
    objectEntityList[20].values[7] &= 248;
    objectEntityList[20].values[1] += objectEntityList[20].values[7];
    objectEntityList[20].values[1] += objectEntityList[20].values[7];
    objectEntityList[20].values[2] = 12;
    objectEntityList[20].values[2] += 8;
    objectEntityList[20].values[4] = GVar("Fade_Colour");
    objectEntityList[20].values[4] >>= 16;
    objectEntityList[20].values[5] = GVar("Fade_Colour");
    objectEntityList[20].values[5] &= 0x00FF00;
    objectEntityList[20].values[5] >>= 8;
    objectEntityList[20].values[6] = GVar("Fade_Colour");
    objectEntityList[20].values[6] &= 0x0000FF;
    AddSpriteFrame(0, 0, 32, 184, 224, 37);
    AddSpriteFrame(96, 96, 48, 48, 41, 1);
    AddSpriteFrame(96, 96, 48, 48, 90, 1);
    AddSpriteFrame(96, 96, 48, 48, 139, 1);
    AddSpriteFrame(64, 97, 48, 16, 41, 67);
    AddSpriteFrame(64, 81, 160, 16, 52, 227);
    AddSpriteFrame(16, 81, 160, 16, 52, 227);
    AddSpriteFrame(100, 32, 24, 48, 182, 124);
    AddSpriteFrame(0, 0, 16, 55, 207, 124);
    AddSpriteFrame(17, 32, 10, 23, 176, 180);
    AddSpriteFrame(28, 32, 9, 23, 187, 180);
    AddSpriteFrame(38, 32, 8, 23, 197, 180);
    AddSpriteFrame(47, 32, 6, 23, 206, 180);
    AddSpriteFrame(54, 32, 11, 23, 212, 180);
    AddSpriteFrame(66, 32, 9, 23, 176, 203);
    AddSpriteFrame(0, 56, 16, 55, 207, 124);
    AddSpriteFrame(17, 56, 10, 23, 186, 203);
    AddSpriteFrame(28, 56, 11, 23, 212, 180);
    AddSpriteFrame(40, 56, 10, 23, 197, 203);
    AddSpriteFrame(51, 56, 9, 23, 187, 180);
}

void O_TitleCards_SS_TitleCard::ObjectDraw()
{
    Entity *self = Self();

    objectEntityList[4].values[1] = 100;
    objectEntityList[4].values[2] = 0;
    switch (self->state) {
        case 0:
        if (self->values[3] > 0) {
            if (self->values[3] == 256) {
                PlayMusic(0);
                pControlMode() = 0;
            }
            SetFade(self->values[4], self->values[5], self->values[6], self->values[3]);
            self->values[3] -= 8;
        } else {
            self->state = 1;
            self->values[3] = 0;
        }
        pControlMode() = -1;
        break;
        case 1:
        scriptEng.tempValue[0] = 144;
        scriptEng.tempValue[0] += self->values[7];
        if (self->values[1] > scriptEng.tempValue[0]) {
            self->values[1] -= 8;
        } else {
            if (self->values[0] == 0) {
                self->state = 2;
            }
        }
        if (self->values[0] < 0) {
            self->values[0] += 8;
        }
        break;
        case 2:
        if (self->values[3] == 160) {
            self->state = 3;
        } else {
            self->values[3]++;
        }
        break;
        case 3:
        if (self->values[1] < 408) {
            self->values[1] += 16;
            self->values[0] -= 16;
        } else {
            ResetObjectEntity(20, TypeNameID("Blank Object"), 0, 0, 0);
            pControlMode() = 0;
            if (GVar("Options.GameMode") == 2) {
                timeEnabled = 1;
            }
        }
        break;
    }
    if (self->type > TypeNameID("Blank Object")) {
        scriptEng.tempValue[0] = 136;
        scriptEng.tempValue[0] += self->values[7];
        DrawSprite_ScreenXY(0, scriptEng.tempValue[0], self->values[0]);
        DrawSprite_ScreenXY(5, self->values[1], 64);
        DrawSprite_ScreenXY(6, self->values[1], 64);
        DrawSprite_ScreenXY(7, self->values[1], 64);
        scriptEng.tempValue[0] = self->values[1];
        scriptEng.tempValue[0] += 150;
        DrawRectangle(scriptEng.tempValue[0], 147, SCREEN_XSIZE, 9, 0, 0, 0, 255);
        scriptEng.tempValue[0] = 8;
        while (scriptEng.tempValue[0] < self->values[2]) {
            DrawSprite_ScreenXY(scriptEng.tempValue[0], self->values[1], 64);
            scriptEng.tempValue[0]++;
        }
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS

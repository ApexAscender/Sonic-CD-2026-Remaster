#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_Title_Logo.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from Logo.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_Title_Logo::ObjectStartup()
{
    LoadSpriteSheet("Title/Title.gif");
    AddSpriteFrame(-130, 0, 130, 152, 381, 73);
    AddSpriteFrame(0, 0, 220, 80, 1, 122);
    AddSpriteFrame(-47, -96, 104, 120, 1, 1);
    AddSpriteFrame(0, 0, 56, 48, 106, 33);
    AddSpriteFrame(0, -38, 45, 55, 210, 203);
    AddSpriteFrame(0, -44, 32, 61, 223, 125);
    AddSpriteFrame(-1, -44, 25, 61, 230, 63);
    AddSpriteFrame(-10, -44, 30, 61, 225, 1);
    AddSpriteFrame(-1, -44, 25, 61, 230, 63);
    AddSpriteFrame(0, -44, 32, 61, 223, 125);
    AddSpriteFrame(0, -38, 45, 55, 210, 203);
    AddSpriteFrame(0, -44, 32, 61, 223, 125);
    AddSpriteFrame(-1, -44, 25, 61, 230, 63);
    AddSpriteFrame(-10, -44, 30, 61, 225, 1);
    AddSpriteFrame(-1, -44, 25, 61, 230, 63);
    AddSpriteFrame(0, -44, 32, 61, 223, 125);
    AddSpriteFrame(0, 0, 176, 68, 256, 4);
    AddSpriteFrame(-124, 0, 124, 68, 256, 77);
    AddSpriteFrame(-174, 0, 174, 68, 246, 267);
}

void O_Title_Logo::ObjectDraw()
{
    Entity *self = Self();

    scriptEng.tempValue[0] = SCREEN_CENTERX;
    scriptEng.tempValue[0] <<= 1;
    DrawSprite_ScreenXY(16, 0, 100);
    DrawSprite_ScreenXY(17, scriptEng.tempValue[0], 100);
    switch (self->state) {
        case 0:
        SetFade(255, 255, 255, self->values[0]);
        self->direction = 0;
        DrawSpriteScreenFX_Script(0, FX_FLIP, SCREEN_CENTERX, 40);
        self->direction = 1;
        DrawSpriteScreenFX_Script(0, FX_FLIP, SCREEN_CENTERX, 40);
        DrawSprite_ScreenXY(2, SCREEN_CENTERX, 120);
        scriptEng.tempValue[0] = SCREEN_CENTERX;
        scriptEng.tempValue[0] -= 110;
        DrawSprite_ScreenXY(1, scriptEng.tempValue[0], 135);
        scriptEng.tempValue[0] += 121;
        DrawSprite_ScreenXY(4, scriptEng.tempValue[0], 110);
        if (self->values[0] > 0) {
            self->values[0] -= 8;
        } else {
            self->state = 1;
            self->frame = 4;
        }
        break;
        case 1:
        self->direction = 0;
        DrawSpriteScreenFX_Script(0, FX_FLIP, SCREEN_CENTERX, 40);
        self->direction = 1;
        DrawSpriteScreenFX_Script(0, FX_FLIP, SCREEN_CENTERX, 40);
        DrawSprite_ScreenXY(2, SCREEN_CENTERX, 120);
        if (self->frame > 7) {
            if (self->frame < 13) {
                scriptEng.tempValue[0] = SCREEN_CENTERX;
                scriptEng.tempValue[0] -= 43;
                DrawSprite_ScreenXY(3, scriptEng.tempValue[0], 48);
            }
        }
        scriptEng.tempValue[0] = SCREEN_CENTERX;
        scriptEng.tempValue[0] -= 110;
        DrawSprite_ScreenXY(1, scriptEng.tempValue[0], 135);
        scriptEng.tempValue[0] += 121;
        DrawSprite_ScreenXY(self->frame, scriptEng.tempValue[0], 110);
        self->values[0]++;
        if (self->values[0] > 1) {
            self->values[0] = 0;
            self->frame++;
            if (self->frame > 15) {
                self->state = 2;
                objectEntityList[objectLoop + 1].type = TypeNameID("Touch Start");
                objectEntityList[objectLoop + 1].XPos = (SCREEN_CENTERX) << 16;
                objectEntityList[objectLoop + 1].YPos = (200) << 16;
            }
        }
        break;
        case 2:
        self->direction = 0;
        DrawSpriteScreenFX_Script(0, FX_FLIP, SCREEN_CENTERX, 40);
        self->direction = 1;
        DrawSpriteScreenFX_Script(0, FX_FLIP, SCREEN_CENTERX, 40);
        DrawSprite_ScreenXY(2, SCREEN_CENTERX, 120);
        scriptEng.tempValue[0] = SCREEN_CENTERX;
        scriptEng.tempValue[0] -= 110;
        DrawSprite_ScreenXY(1, scriptEng.tempValue[0], 135);
        scriptEng.tempValue[0] += 121;
        DrawSprite_ScreenXY(4, scriptEng.tempValue[0], 110);
        break;
    }
    if (RETRO_GAMEPLATFORMID == 6) {
        if (keyPress.B == 1) {
            Engine.Callback(7);
        }
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS

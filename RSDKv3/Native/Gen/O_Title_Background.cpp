#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_Title_Background.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from Background.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_Title_Background::ObjectStartup()
{
    LoadSpriteSheet("Title/Title.gif");
    AddSpriteFrame(0, 0, 176, 68, 256, 4);
    AddSpriteFrame(-144, 0, 144, 68, 257, 251);
    AddSpriteFrame(0, 0, 120, 104, 257, 146);
    scriptEng.tempValue[0] = 447;
    scriptEng.tempValue[1] = 168;
    while (scriptEng.tempValue[0] < 511) {
        AddSpriteFrame(0, scriptEng.tempValue[1], 512, 4, 0, scriptEng.tempValue[0]);
        AddSpriteFrame(-512, scriptEng.tempValue[1], 512, 4, 0, scriptEng.tempValue[0]);
        scriptEng.tempValue[0] += 4;
        scriptEng.tempValue[1] += 4;
    }
    scriptEng.tempValue[0] -= 16;
    while (scriptEng.tempValue[1] < 240) {
        AddSpriteFrame(0, scriptEng.tempValue[1], 512, 4, 0, scriptEng.tempValue[0]);
        AddSpriteFrame(-512, scriptEng.tempValue[1], 512, 4, 0, scriptEng.tempValue[0]);
        scriptEng.tempValue[0] += 4;
        scriptEng.tempValue[1] += 4;
    }
}

void O_Title_Background::ObjectDraw()
{
    Entity *self = Self();

    scriptEng.tempValue[0] = SCREEN_CENTERX;
    scriptEng.tempValue[0] <<= 1;
    DrawRectangle(0, 0, scriptEng.tempValue[0], 100, 0, 0, 96, 255);
    DrawRectangle(0, 0, scriptEng.tempValue[0], 180, 0, 0, 96, 255);
    scriptEng.tempValue[0] = Sin512(self->values[0]);
    scriptEng.tempValue[0] >>= 7;
    scriptEng.tempValue[0] -= 16;
    DrawSprite_ScreenXY(2, 280, scriptEng.tempValue[0]);
    self->values[0]++;
    self->values[0] &= 511;
    scriptEng.tempValue[0] = 3;
    scriptEng.tempValue[1] = 16;
    scriptEng.arrayPosition[0] = 40;
    while (scriptEng.tempValue[0] < 39) {
        objectEntityList[scriptEng.arrayPosition[0]].XPos += scriptEng.tempValue[1];
        if (objectEntityList[scriptEng.arrayPosition[0]].XPos > 0x2000000) {
            objectEntityList[scriptEng.arrayPosition[0]].XPos -= 0x2000000;
        }
        scriptEng.tempValue[2] = objectEntityList[scriptEng.arrayPosition[0]].XPos;
        scriptEng.tempValue[2] >>= 16;
        scriptEng.arrayPosition[0]++;
        DrawSprite_ScreenXY(scriptEng.tempValue[0], scriptEng.tempValue[2], 0);
        scriptEng.tempValue[0]++;
        DrawSprite_ScreenXY(scriptEng.tempValue[0], scriptEng.tempValue[2], 0);
        scriptEng.tempValue[0]++;
        scriptEng.tempValue[1] += 0x2000;
    }
    self->values[1]++;
    self->values[1] &= 511;
}

#endif // RETRO_USE_NATIVE_OBJECTS

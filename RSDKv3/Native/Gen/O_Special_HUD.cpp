#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_Special_HUD.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from HUD.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_Special_HUD::ObjectStartup()
{
    LoadSpriteSheet("Special/Objects.gif");
    objectEntityList[4].type = TypeNameID("HUD");
    objectEntityList[4].priority = 1;
    objectEntityList[4].drawOrder = 6;
    objectEntityList[4].values[4] = -1;
    AddSpriteFrame(0, 0, 8, 13, 206, 84);
    AddSpriteFrame(0, 0, 8, 13, 215, 84);
    AddSpriteFrame(0, 0, 8, 13, 224, 84);
    AddSpriteFrame(0, 0, 8, 13, 233, 84);
    AddSpriteFrame(0, 0, 8, 13, 242, 84);
    AddSpriteFrame(0, 0, 8, 13, 206, 98);
    AddSpriteFrame(0, 0, 8, 13, 215, 98);
    AddSpriteFrame(0, 0, 8, 13, 224, 98);
    AddSpriteFrame(0, 0, 8, 13, 233, 98);
    AddSpriteFrame(0, 0, 8, 13, 242, 98);
    AddSpriteFrame(0, 0, 24, 16, 206, 58);
    AddSpriteFrame(0, 0, 24, 8, 231, 58);
    AddSpriteFrame(0, 0, 31, 8, 206, 75);
    AddSpriteFrame(0, 0, 8, 13, 224, 112);
    AddSpriteFrame(0, 0, 8, 13, 233, 112);
}

void O_Special_HUD::ObjectDraw()
{
    Entity *self = Self();

    scriptEng.tempValue[1] = SCREEN_CENTERX;
    scriptEng.tempValue[1] -= 128;
    DrawSprite_ScreenXY(10, scriptEng.tempValue[1], 10);
    scriptEng.tempValue[0] = self->values[0];
    scriptEng.tempValue[0] /= 10;
    scriptEng.tempValue[1] += 24;
    DrawSprite_ScreenXY(scriptEng.tempValue[0], scriptEng.tempValue[1], 11);
    scriptEng.tempValue[0] = self->values[0];
    scriptEng.tempValue[0] %= 10;
    scriptEng.tempValue[1] += 8;
    DrawSprite_ScreenXY(scriptEng.tempValue[0], scriptEng.tempValue[1], 11);
    scriptEng.tempValue[1] += 48;
    DrawSprite_ScreenXY(11, scriptEng.tempValue[1], 16);
    if (GVar("Options.GameMode") < 2) {
        scriptEng.tempValue[0] = self->values[1];
        scriptEng.tempValue[0] /= 100;
        scriptEng.tempValue[1] += 40;
        DrawSprite_ScreenXY(scriptEng.tempValue[0], scriptEng.tempValue[1], 11);
        scriptEng.tempValue[0] = self->values[1];
        scriptEng.tempValue[0] %= 100;
        scriptEng.tempValue[0] /= 10;
        scriptEng.tempValue[1] += 8;
        DrawSprite_ScreenXY(scriptEng.tempValue[0], scriptEng.tempValue[1], 11);
        scriptEng.tempValue[0] = self->values[1];
        scriptEng.tempValue[0] %= 10;
        scriptEng.tempValue[1] += 8;
        DrawSprite_ScreenXY(scriptEng.tempValue[0], scriptEng.tempValue[1], 11);
        scriptEng.tempValue[1] += 64;
    } else {
        if (stageMinutes > 29) {
            stageMinutes = 30;
            stageSeconds = 0;
            stageMilliseconds = 0;
        }
        scriptEng.tempValue[1] += 40;
        DrawNumbers_Script(0, scriptEng.tempValue[1], 11, stageMinutes, 2, 8, 1);
        scriptEng.tempValue[1] += 8;
        DrawSprite_ScreenXY(13, scriptEng.tempValue[1], 11);
        scriptEng.tempValue[1] += 16;
        DrawNumbers_Script(0, scriptEng.tempValue[1], 11, stageSeconds, 2, 8, 1);
        scriptEng.tempValue[1] += 8;
        DrawSprite_ScreenXY(14, scriptEng.tempValue[1], 11);
        scriptEng.tempValue[1] += 16;
        DrawNumbers_Script(0, scriptEng.tempValue[1], 11, stageMilliseconds, 2, 8, 1);
        scriptEng.tempValue[1] += 32;
    }
    DrawSprite_ScreenXY(12, scriptEng.tempValue[1], 16);
    scriptEng.tempValue[0] = self->values[3];
    scriptEng.tempValue[0] /= 100;
    scriptEng.tempValue[1] += 32;
    DrawSprite_ScreenXY(scriptEng.tempValue[0], scriptEng.tempValue[1], 11);
    scriptEng.tempValue[0] = self->values[3];
    scriptEng.tempValue[0] %= 100;
    scriptEng.tempValue[0] /= 10;
    scriptEng.tempValue[1] += 8;
    DrawSprite_ScreenXY(scriptEng.tempValue[0], scriptEng.tempValue[1], 11);
    scriptEng.tempValue[0] = self->values[3];
    scriptEng.tempValue[0] %= 10;
    scriptEng.tempValue[1] += 8;
    DrawSprite_ScreenXY(scriptEng.tempValue[0], scriptEng.tempValue[1], 11);
}

#endif // RETRO_USE_NATIVE_OBJECTS

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_HUD.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from HUD.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_HUD::ObjectStartup()
{
    if (playerListPos == 0) {
        LoadSpriteSheet("Global/Display.gif");
    }
    if (playerListPos == 1) {
        LoadSpriteSheet("Global/Display_t.gif");
    }
    objectEntityList[24].values[3] = ScriptFuncID("HUD_DrawStandard");
    AddSpriteFrame(0, 0, 8, 11, 1, 50);
    AddSpriteFrame(0, 0, 8, 11, 10, 50);
    AddSpriteFrame(0, 0, 8, 11, 19, 50);
    AddSpriteFrame(0, 0, 8, 11, 28, 50);
    AddSpriteFrame(0, 0, 8, 11, 1, 62);
    AddSpriteFrame(0, 0, 8, 11, 10, 62);
    AddSpriteFrame(0, 0, 8, 11, 19, 62);
    AddSpriteFrame(0, 0, 8, 11, 28, 62);
    AddSpriteFrame(0, 0, 8, 11, 1, 74);
    AddSpriteFrame(0, 0, 8, 11, 10, 74);
    AddSpriteFrame(0, 0, 39, 43, 1, 1);
    AddSpriteFrame(0, 0, 31, 11, 1, 119);
    AddSpriteFrame(0, 0, 39, 11, 1, 131);
    AddSpriteFrame(0, 0, 29, 4, 1, 45);
    AddSpriteFrame(0, 0, 8, 8, 1, 98);
    AddSpriteFrame(0, 0, 32, 16, 90, 67);
    AddSpriteFrame(0, 0, 32, 16, 123, 67);
    AddSpriteFrame(0, 0, 16, 16, 187, 189);
    AddSpriteFrame(0, 0, 16, 16, 204, 189);
    AddSpriteFrame(0, 0, 16, 16, 237, 223);
    AddSpriteFrame(0, 0, 16, 16, 237, 223);
    AddSpriteFrame(0, 0, 8, 8, 10, 98);
}

void O_HUD::ObjectDraw()
{
    Entity *self = Self();

    if (PlayerValue(0) == 0) {
        self->values[4]++;
        if (self->values[4] == 16) {
            self->values[4] = 0;
        }
    } else {
        if (stageMinutes == 9) {
            self->values[4]++;
            if (self->values[4] == 16) {
                self->values[4] = 0;
            }
        }
    }
    CallScriptFunction(self->values[3], scriptSub);
}

void O_HUD::HUD_DrawStandard()
{
    Entity *self = Self();

    DrawSprite_ScreenXY(10, 17, 13);
    if (stageMinutes == 9) {
        if (self->values[4] > 7) {
            DrawSprite_ScreenXY(11, 17, 29);
        }
    }
    if (PlayerValue(0) == 0) {
        if (self->values[4] > 7) {
            DrawSprite_ScreenXY(12, 17, 45);
        }
    }
    DrawSprite_ScreenXY(13, 67, 29);
    DrawNumbers_Script(0, 104, 13, GVar("Player.Score"), 6, 8, 0);
    DrawNumbers_Script(0, 104, 29, stageMilliseconds, 2, 8, 1);
    DrawNumbers_Script(0, 80, 29, stageSeconds, 2, 8, 1);
    DrawNumbers_Script(0, 56, 29, stageMinutes, 1, 8, 1);
    DrawNumbers_Script(0, 80, 45, PlayerValue(0), 3, 8, 0);
    if (debugMode == 1) {
        scriptEng.tempValue[0] = pXPos();
        scriptEng.tempValue[0] >>= 16;
        scriptEng.tempValue[1] = SCREEN_XSIZE;
        scriptEng.tempValue[1] -= 24;
        DrawNumbers_Script(0, scriptEng.tempValue[1], 13, scriptEng.tempValue[0], 5, 8, 1);
        scriptEng.tempValue[0] = pYPos();
        scriptEng.tempValue[0] >>= 16;
        if (scriptEng.tempValue[0] < 0) {
            scriptEng.tempValue[0] = -scriptEng.tempValue[0];
        }
        DrawNumbers_Script(0, scriptEng.tempValue[1], 29, scriptEng.tempValue[0], 5, 8, 1);
        scriptEng.tempValue[1] -= 42;
        DrawSprite_ScreenXY(14, scriptEng.tempValue[1], 15);
        DrawSprite_ScreenXY(21, scriptEng.tempValue[1], 31);
    }
    scriptEng.tempValue[0] = self->propertyValue;
    scriptEng.tempValue[0] += 17;
    DrawSprite_ScreenXY(scriptEng.tempValue[0], 16, 212);
    DrawSprite_ScreenXY(14, 32, 220);
    if (GVar("Player.Lives") < 10) {
        DrawNumbers_Script(0, 40, 217, GVar("Player.Lives"), 1, 8, 1);
        scriptEng.tempValue[1] = 52;
    } else {
        DrawNumbers_Script(0, 48, 217, GVar("Player.Lives"), 2, 8, 1);
        scriptEng.tempValue[1] = 60;
    }
    scriptEng.tempValue[5] = 214;
    switch (GVar("Warp.Destination")) {
        case 1:
        if (GVar("Warp.Timer") < 100) {
            DrawSprite_ScreenXY(15, scriptEng.tempValue[1], scriptEng.tempValue[5]);
        } else {
            scriptEng.tempValue[0] = GVar("Warp.Timer");
            scriptEng.tempValue[0] &= 1;
            if (scriptEng.tempValue[0] == 0) {
                DrawSprite_ScreenXY(15, scriptEng.tempValue[1], scriptEng.tempValue[5]);
            }
        }
        break;
        case 2:
        if (GVar("Warp.Timer") < 100) {
            DrawSprite_ScreenXY(16, scriptEng.tempValue[1], scriptEng.tempValue[5]);
        } else {
            scriptEng.tempValue[0] = GVar("Warp.Timer");
            scriptEng.tempValue[0] &= 1;
            if (scriptEng.tempValue[0] == 0) {
                DrawSprite_ScreenXY(16, scriptEng.tempValue[1], scriptEng.tempValue[5]);
            }
        }
        break;
    }
}

void O_HUD::HUD_DrawMobile()
{
    Entity *self = Self();

    DrawSprite_ScreenXY(10, 17, 9);
    if (stageMinutes == 9) {
        if (self->values[4] > 7) {
            DrawSprite_ScreenXY(11, 17, 25);
        }
    }
    if (PlayerValue(0) == 0) {
        if (self->values[4] > 7) {
            DrawSprite_ScreenXY(12, 17, 41);
        }
    }
    DrawSprite_ScreenXY(13, 67, 25);
    DrawNumbers_Script(0, 104, 9, GVar("Player.Score"), 6, 8, 0);
    DrawNumbers_Script(0, 104, 25, stageMilliseconds, 2, 8, 1);
    DrawNumbers_Script(0, 80, 25, stageSeconds, 2, 8, 1);
    DrawNumbers_Script(0, 56, 25, stageMinutes, 1, 8, 1);
    DrawNumbers_Script(0, 80, 41, PlayerValue(0), 3, 8, 0);
    if (debugMode == 1) {
        scriptEng.tempValue[0] = pXPos();
        scriptEng.tempValue[0] >>= 16;
        scriptEng.tempValue[1] = SCREEN_XSIZE;
        scriptEng.tempValue[1] -= 16;
        DrawNumbers_Script(0, scriptEng.tempValue[1], 25, scriptEng.tempValue[0], 5, 8, 1);
        scriptEng.tempValue[0] = pYPos();
        scriptEng.tempValue[0] >>= 16;
        if (scriptEng.tempValue[0] < 0) {
            scriptEng.tempValue[0] = -scriptEng.tempValue[0];
        }
        DrawNumbers_Script(0, scriptEng.tempValue[1], 41, scriptEng.tempValue[0], 5, 8, 1);
        scriptEng.tempValue[1] -= 42;
        DrawSprite_ScreenXY(14, scriptEng.tempValue[1], 27);
        DrawSprite_ScreenXY(21, scriptEng.tempValue[1], 43);
    }
    scriptEng.tempValue[1] = SCREEN_XSIZE;
    scriptEng.tempValue[1] -= 48;
    scriptEng.tempValue[0] = self->propertyValue;
    scriptEng.tempValue[0] += 17;
    DrawSprite_ScreenXY(scriptEng.tempValue[0], scriptEng.tempValue[1], 8);
    scriptEng.tempValue[1] += 16;
    DrawSprite_ScreenXY(14, scriptEng.tempValue[1], 16);
    if (GVar("Player.Lives") < 10) {
        scriptEng.tempValue[1] += 8;
        DrawNumbers_Script(0, scriptEng.tempValue[1], 13, GVar("Player.Lives"), 1, 8, 1);
    } else {
        scriptEng.tempValue[1] += 16;
        DrawNumbers_Script(0, scriptEng.tempValue[1], 13, GVar("Player.Lives"), 2, 8, 1);
        scriptEng.tempValue[1] -= 8;
    }
    switch (GVar("Warp.Destination")) {
        case 1:
        scriptEng.tempValue[1] -= 79;
        if (GVar("Warp.Timer") < 100) {
            DrawSprite_ScreenXY(15, scriptEng.tempValue[1], 8);
        } else {
            scriptEng.tempValue[0] = GVar("Warp.Timer");
            scriptEng.tempValue[0] &= 1;
            if (scriptEng.tempValue[0] == 0) {
                DrawSprite_ScreenXY(15, scriptEng.tempValue[1], 8);
            }
        }
        break;
        case 2:
        scriptEng.tempValue[1] -= 79;
        if (GVar("Warp.Timer") < 100) {
            DrawSprite_ScreenXY(16, scriptEng.tempValue[1], 8);
        } else {
            scriptEng.tempValue[0] = GVar("Warp.Timer");
            scriptEng.tempValue[0] &= 1;
            if (scriptEng.tempValue[0] == 0) {
                DrawSprite_ScreenXY(16, scriptEng.tempValue[1], 8);
            }
        }
        break;
    }
}

const Native::NativeFunctionDef O_HUD::funcs[2] = {
    { "HUD_DrawStandard", O_HUD::HUD_DrawStandard },
    { "HUD_DrawMobile", O_HUD::HUD_DrawMobile },
};

#endif // RETRO_USE_NATIVE_OBJECTS

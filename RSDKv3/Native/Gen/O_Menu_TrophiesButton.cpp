#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_Menu_TrophiesButton.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from TrophiesButton.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_Menu_TrophiesButton::ObjectStartup()
{
    LoadSpriteSheet("Menu/Trophies.gif");
    AddSpriteFrame(-63, -39, 126, 78, 129, 385);
    AddSpriteFrame(-60, -37, 120, 74, 260, 387);
    scriptEng.tempValue[0] = SCREEN_CENTERX;
    scriptEng.tempValue[0] -= 160;
    scriptEng.tempValue[0] <<= 16;
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Exit Button")) {
            objectEntityList[scriptEng.arrayPosition[0]].XPos += scriptEng.tempValue[0];
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_Menu_TrophiesButton::ObjectMain()
{
    Entity *self = Self();

    if (objectEntityList[0].state == 2) {
        if (Engine.message == 2) {
            self->values[1] = 0;
        }
        scriptEng.tempValue[0] = self->XPos;
        scriptEng.tempValue[0] >>= 16;
        scriptEng.tempValue[1] = scriptEng.tempValue[0];
        scriptEng.tempValue[0] -= 18;
        scriptEng.tempValue[0] -= xScrollOffset;
        scriptEng.tempValue[1] += 18;
        scriptEng.tempValue[1] -= xScrollOffset;
        CheckTouchRect_Script(scriptEng.tempValue[0], 0, scriptEng.tempValue[1], 48);
        if (CheckResult() > -1) {
            self->values[1] = 1;
        } else {
            CheckTouchRect_Script(0, 0, SCREEN_XSIZE, SCREEN_YSIZE);
            if (CheckResult() < 0) {
                if (self->values[1] == 1) {
                    self->values[1] = 0;
                    PlaySfx(26, 0);
                    StopMusic();
                    objectEntityList[0].state = 5;
                }
            } else {
                self->values[1] = 0;
            }
        }
    }
}

void O_Menu_TrophiesButton::ObjectDraw()
{
    Entity *self = Self();

    self->scale = 128;
    if (self->values[1] == 1) {
        DrawSpriteFX_Script(1, FX_SCALE, self->XPos, self->YPos);
    } else {
        DrawSpriteFX_Script(0, FX_SCALE, self->XPos, self->YPos);
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_Menu_HelpButtons.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from HelpButtons.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_Menu_HelpButtons::ObjectStartup()
{
    LoadSpriteSheet("Menu/Buttons.gif");
    AddSpriteFrame(-63, -39, 126, 78, 1, 1);
    AddSpriteFrame(-60, -37, 120, 74, 132, 3);
    AddSpriteFrame(-63, -39, 126, 78, 1, 81);
    AddSpriteFrame(-60, -37, 120, 74, 132, 83);
    AddSpriteFrame(-63, -39, 126, 78, 1, 161);
    AddSpriteFrame(-60, -37, 120, 74, 132, 163);
    scriptEng.tempValue[0] = SCREEN_CENTERX;
    scriptEng.tempValue[0] -= 160;
    scriptEng.tempValue[0] <<= 16;
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Help Buttons")) {
            objectEntityList[scriptEng.arrayPosition[0]].XPos += scriptEng.tempValue[0];
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_Menu_HelpButtons::ObjectMain()
{
    Entity *self = Self();

    if (objectEntityList[0].state == 2) {
        if (Engine.message == 2) {
            objectEntityList[0].values[1] = 0;
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
            objectEntityList[0].values[1] = self->propertyValue;
            objectEntityList[0].values[1]++;
        } else {
            CheckTouchRect_Script(0, 0, SCREEN_XSIZE, SCREEN_YSIZE);
            if (CheckResult() < 0) {
                switch (self->propertyValue) {
                    case 0:
                    if (objectEntityList[0].values[1] == 1) {
                        objectEntityList[0].values[1] = 0;
                        if (objectEntityList[0].values[3] < 8) {
                            PlaySfx(27, 0);
                            objectEntityList[0].values[0] = 256;
                            objectEntityList[0].state = 3;
                        }
                    }
                    break;
                    case 1:
                    if (objectEntityList[0].values[1] == 2) {
                        objectEntityList[0].values[1] = 0;
                        if (objectEntityList[0].values[3] > 0) {
                            PlaySfx(27, 0);
                            objectEntityList[0].state = 4;
                        }
                    }
                    break;
                    case 2:
                    if (objectEntityList[0].values[1] == 3) {
                        objectEntityList[0].values[1] = 0;
                        PlaySfx(26, 0);
                        StopMusic();
                        objectEntityList[0].state = 5;
                    }
                    break;
                }
            } else {
                switch (self->propertyValue) {
                    case 0:
                    if (objectEntityList[0].values[1] == 1) {
                        objectEntityList[0].values[1] = 0;
                    }
                    break;
                    case 1:
                    if (objectEntityList[0].values[1] == 2) {
                        objectEntityList[0].values[1] = 0;
                    }
                    break;
                    case 2:
                    if (objectEntityList[0].values[1] == 3) {
                        objectEntityList[0].values[1] = 0;
                    }
                    break;
                }
            }
        }
    }
}

void O_Menu_HelpButtons::ObjectDraw()
{
    Entity *self = Self();

    self->scale = 128;
    switch (self->propertyValue) {
        case 0:
        if (objectEntityList[0].values[1] == 1) {
            DrawSpriteFX_Script(1, FX_SCALE, self->XPos, self->YPos);
        } else {
            DrawSpriteFX_Script(0, FX_SCALE, self->XPos, self->YPos);
        }
        break;
        case 1:
        if (objectEntityList[0].values[1] == 2) {
            DrawSpriteFX_Script(3, FX_SCALE, self->XPos, self->YPos);
        } else {
            DrawSpriteFX_Script(2, FX_SCALE, self->XPos, self->YPos);
        }
        break;
        case 2:
        if (objectEntityList[0].values[1] == 3) {
            DrawSpriteFX_Script(5, FX_SCALE, self->XPos, self->YPos);
        } else {
            DrawSpriteFX_Script(4, FX_SCALE, self->XPos, self->YPos);
        }
        break;
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS

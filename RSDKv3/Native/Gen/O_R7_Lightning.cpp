#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R7_Lightning.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from Lightning.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R7_Lightning::ObjectStartup()
{
    LoadSpriteSheet("R7/Objects3.gif");
    AddSpriteFrame(-8, 0, 16, 40, 43, 140);
    AddSpriteFrame(-8, 0, 16, 24, 60, 140);
    AddSpriteFrame(-16, 0, 32, 40, 77, 132);
    AddSpriteFrame(-8, 0, 16, 24, 60, 140);
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Lightning")) {
            objectEntityList[scriptEng.arrayPosition[0]].priority = 1;
            objectEntityList[scriptEng.arrayPosition[0]].drawOrder = 1;
            objectEntityList[scriptEng.arrayPosition[0]].inkEffect = 2;
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_R7_Lightning::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        if (self->values[0] < 256) {
            self->values[0]++;
        } else {
            self->values[0] = 0;
            self->alpha = 254;
            self->values[1] = 128;
            self->state++;
        }
        break;
        case 1:
        if (self->alpha > 0) {
            self->alpha -= 2;
        } else {
            self->state = 0;
            self->frame++;
            self->frame &= 3;
        }
        if (self->values[1] > 0) {
            self->values[1] -= 4;
        }
        break;
    }
}

void O_R7_Lightning::ObjectDraw()
{
    Entity *self = Self();

    if (self->state > 0) {
        if (self->drawOrder == 1) {
            self->YPos = yScrollOffset;
            self->YPos *= self->propertyValue;
            self->YPos >>= 7;
            self->YPos = -self->YPos;
            self->YPos += 312;
            scriptEng.tempValue[0] = self->values[1];
            scriptEng.tempValue[0] >>= 1;
            DrawRectangle(0, 0, SCREEN_XSIZE, SCREEN_YSIZE, 224, 192, 128, scriptEng.tempValue[0]);
            scriptEng.tempValue[0] = xScrollOffset;
            scriptEng.tempValue[0] >>= 3;
            scriptEng.tempValue[0] &= 511;
            scriptEng.tempValue[0] = -scriptEng.tempValue[0];
            scriptEng.tempValue[1] = self->frame;
            scriptEng.tempValue[0] += 64;
            if (scriptEng.tempValue[0] < -64) {
                scriptEng.tempValue[0] += 512;
                DrawSpriteScreenFX_Script(scriptEng.tempValue[1], FX_INK, scriptEng.tempValue[0], self->YPos);
                scriptEng.tempValue[0] -= 512;
            } else {
                DrawSpriteScreenFX_Script(scriptEng.tempValue[1], FX_INK, scriptEng.tempValue[0], self->YPos);
            }
            scriptEng.tempValue[1]++;
            scriptEng.tempValue[1] &= 3;
            scriptEng.tempValue[0] += 128;
            if (scriptEng.tempValue[0] < -64) {
                scriptEng.tempValue[0] += 512;
                DrawSpriteScreenFX_Script(scriptEng.tempValue[1], FX_INK, scriptEng.tempValue[0], self->YPos);
                scriptEng.tempValue[0] -= 512;
            } else {
                DrawSpriteScreenFX_Script(scriptEng.tempValue[1], FX_INK, scriptEng.tempValue[0], self->YPos);
            }
            scriptEng.tempValue[1]++;
            scriptEng.tempValue[1] &= 3;
            scriptEng.tempValue[0] += 128;
            if (scriptEng.tempValue[0] < -64) {
                scriptEng.tempValue[0] += 512;
                DrawSpriteScreenFX_Script(scriptEng.tempValue[1], FX_INK, scriptEng.tempValue[0], self->YPos);
                scriptEng.tempValue[0] -= 512;
            } else {
                DrawSpriteScreenFX_Script(scriptEng.tempValue[1], FX_INK, scriptEng.tempValue[0], self->YPos);
            }
            scriptEng.tempValue[1]++;
            scriptEng.tempValue[1] &= 3;
            scriptEng.tempValue[0] += 96;
            if (scriptEng.tempValue[0] < -64) {
                scriptEng.tempValue[0] += 512;
                DrawSpriteScreenFX_Script(scriptEng.tempValue[1], FX_INK, scriptEng.tempValue[0], self->YPos);
                scriptEng.tempValue[0] -= 512;
            } else {
                DrawSpriteScreenFX_Script(scriptEng.tempValue[1], FX_INK, scriptEng.tempValue[0], self->YPos);
            }
            drawListEntries[5].entityRefs[drawListEntries[5].listSize] = objectLoop;
            drawListEntries[5].listSize++;
            self->drawOrder = 5;
        } else {
            DrawRectangle(0, 0, SCREEN_XSIZE, SCREEN_YSIZE, 224, 224, 192, self->values[1]);
            self->drawOrder = 1;
        }
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS

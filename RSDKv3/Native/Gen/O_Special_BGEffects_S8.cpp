#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_Special_BGEffects_S8.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from BGEffects_S8.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_Special_BGEffects_S8::ObjectStartup()
{
    xBoundary1 = 0x2800000;
    xBoundary2 = 0xD800000;
    yBoundary1 = 0x3000000;
    yBoundary2 = 0xD000000;
    scriptEng.tempValue[0] = SCREEN_XSIZE;
    scriptEng.tempValue[0] -= 320;
    scriptEng.tempValue[0] <<= 15;
    hParallax.scrollPos[0] = 0x600000;
    hParallax.scrollPos[0] -= scriptEng.tempValue[0];
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("BGEffects")) {
            objectEntityList[scriptEng.arrayPosition[0]].priority = 1;
            objectEntityList[scriptEng.arrayPosition[0]].drawOrder = 0;
            objectEntityList[scriptEng.arrayPosition[0]].values[2] = 368;
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_Special_BGEffects_S8::ObjectDraw()
{
    Entity *self = Self();

    self->values[3]++;
    if (self->values[3] > 2) {
        self->values[3] = 0;
        self->values[5]++;
        self->values[5] %= 3;
        switch (self->values[5]) {
            case 0:
            Copy16x16Tile(237, 308);
            Copy16x16Tile(238, 309);
            Copy16x16Tile(239, 310);
            Copy16x16Tile(240, 311);
            Copy16x16Tile(241, 312);
            Copy16x16Tile(242, 313);
            Copy16x16Tile(243, 314);
            Copy16x16Tile(244, 315);
            break;
            case 1:
            Copy16x16Tile(237, 316);
            Copy16x16Tile(238, 317);
            Copy16x16Tile(239, 318);
            Copy16x16Tile(240, 319);
            Copy16x16Tile(241, 320);
            Copy16x16Tile(242, 321);
            Copy16x16Tile(243, 322);
            Copy16x16Tile(244, 323);
            break;
            case 2:
            Copy16x16Tile(237, 324);
            Copy16x16Tile(238, 325);
            Copy16x16Tile(239, 326);
            Copy16x16Tile(240, 327);
            Copy16x16Tile(241, 328);
            Copy16x16Tile(242, 329);
            Copy16x16Tile(243, 330);
            Copy16x16Tile(244, 331);
            break;
        }
    }
    self->values[4]++;
    if (self->values[4] > 5) {
        self->values[4] = 0;
        self->values[6]++;
        self->values[6] &= 3;
        switch (self->values[6]) {
            case 0:
            Copy16x16Tile(135, 332);
            Copy16x16Tile(136, 333);
            Copy16x16Tile(137, 336);
            Copy16x16Tile(138, 337);
            break;
            case 1:
            Copy16x16Tile(135, 334);
            Copy16x16Tile(136, 335);
            Copy16x16Tile(137, 338);
            Copy16x16Tile(138, 339);
            break;
            case 2:
            Copy16x16Tile(135, 340);
            Copy16x16Tile(136, 341);
            Copy16x16Tile(137, 344);
            Copy16x16Tile(138, 345);
            break;
            case 3:
            Copy16x16Tile(135, 342);
            Copy16x16Tile(136, 343);
            Copy16x16Tile(137, 346);
            Copy16x16Tile(138, 347);
            break;
        }
    }
    scriptEng.tempValue[1] = self->values[2];
    scriptEng.tempValue[2] = stageLayouts[0].angle;
    if (scriptEng.tempValue[1] < scriptEng.tempValue[2]) {
        scriptEng.tempValue[3] = scriptEng.tempValue[2];
        scriptEng.tempValue[3] -= scriptEng.tempValue[1];
        if (scriptEng.tempValue[3] > 256) {
            scriptEng.tempValue[1] += 512;
        }
    } else {
        scriptEng.tempValue[3] = scriptEng.tempValue[1];
        scriptEng.tempValue[3] -= scriptEng.tempValue[2];
        if (scriptEng.tempValue[3] > 256) {
            scriptEng.tempValue[2] += 512;
        }
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS

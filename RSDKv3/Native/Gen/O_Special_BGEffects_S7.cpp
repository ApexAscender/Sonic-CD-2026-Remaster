#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_Special_BGEffects_S7.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from BGEffects_S7.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_Special_BGEffects_S7::ObjectStartup()
{
    xBoundary1 = 0x2800000;
    xBoundary2 = 0xD800000;
    yBoundary1 = 0x2800000;
    yBoundary2 = 0xD800000;
    hParallax.scrollPos[0] += 0x800000;
    hParallax.scrollPos[2] -= 0x800000;
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("BGEffects")) {
            objectEntityList[scriptEng.arrayPosition[0]].priority = 1;
            objectEntityList[scriptEng.arrayPosition[0]].drawOrder = 0;
            objectEntityList[scriptEng.arrayPosition[0]].values[2] = 256;
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_Special_BGEffects_S7::ObjectDraw()
{
    Entity *self = Self();

    self->values[3]++;
    if (self->values[3] > 2) {
        self->values[3] = 0;
        self->values[5]++;
        self->values[5] %= 3;
        switch (self->values[5]) {
            case 0:
            Copy16x16Tile(269, 484);
            Copy16x16Tile(270, 485);
            Copy16x16Tile(271, 486);
            Copy16x16Tile(272, 487);
            Copy16x16Tile(273, 488);
            Copy16x16Tile(274, 489);
            Copy16x16Tile(275, 490);
            Copy16x16Tile(276, 491);
            break;
            case 1:
            Copy16x16Tile(269, 492);
            Copy16x16Tile(270, 493);
            Copy16x16Tile(271, 494);
            Copy16x16Tile(272, 495);
            Copy16x16Tile(273, 496);
            Copy16x16Tile(274, 497);
            Copy16x16Tile(275, 498);
            Copy16x16Tile(276, 499);
            break;
            case 2:
            Copy16x16Tile(269, 500);
            Copy16x16Tile(270, 501);
            Copy16x16Tile(271, 502);
            Copy16x16Tile(272, 503);
            Copy16x16Tile(273, 504);
            Copy16x16Tile(274, 505);
            Copy16x16Tile(275, 506);
            Copy16x16Tile(276, 507);
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
            Copy16x16Tile(129, 508);
            Copy16x16Tile(130, 509);
            Copy16x16Tile(134, 512);
            Copy16x16Tile(135, 513);
            break;
            case 1:
            Copy16x16Tile(129, 510);
            Copy16x16Tile(130, 511);
            Copy16x16Tile(134, 514);
            Copy16x16Tile(135, 515);
            break;
            case 2:
            Copy16x16Tile(129, 516);
            Copy16x16Tile(130, 517);
            Copy16x16Tile(134, 520);
            Copy16x16Tile(135, 521);
            break;
            case 3:
            Copy16x16Tile(129, 518);
            Copy16x16Tile(130, 519);
            Copy16x16Tile(134, 522);
            Copy16x16Tile(135, 523);
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
    scriptEng.tempValue[0] = scriptEng.tempValue[1];
    scriptEng.tempValue[0] -= scriptEng.tempValue[2];
    self->values[2] = stageLayouts[0].angle;
    scriptEng.tempValue[1] = 0x10000;
    scriptEng.tempValue[2] = 0x20000;
    scriptEng.tempValue[3] = 0x30000;
    scriptEng.tempValue[1] *= scriptEng.tempValue[0];
    scriptEng.tempValue[2] *= scriptEng.tempValue[0];
    scriptEng.tempValue[3] *= scriptEng.tempValue[0];
    hParallax.scrollPos[0] += scriptEng.tempValue[1];
    hParallax.scrollPos[1] += scriptEng.tempValue[2];
    hParallax.scrollPos[2] += scriptEng.tempValue[3];
}

#endif // RETRO_USE_NATIVE_OBJECTS

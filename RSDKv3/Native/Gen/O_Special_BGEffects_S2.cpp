#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_Special_BGEffects_S2.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from BGEffects_S2.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_Special_BGEffects_S2::ObjectStartup()
{
    xBoundary1 = 0x3800000;
    xBoundary2 = 0xC800000;
    yBoundary1 = 0x3800000;
    yBoundary2 = 0xC800000;
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

void O_Special_BGEffects_S2::ObjectDraw()
{
    Entity *self = Self();

    self->values[3]++;
    if (self->values[3] > 2) {
        self->values[3] = 0;
        self->values[5]++;
        self->values[5] %= 3;
        switch (self->values[5]) {
            case 0:
            Copy16x16Tile(122, 428);
            Copy16x16Tile(123, 429);
            Copy16x16Tile(124, 430);
            Copy16x16Tile(125, 431);
            Copy16x16Tile(126, 432);
            Copy16x16Tile(127, 433);
            Copy16x16Tile(128, 434);
            Copy16x16Tile(129, 435);
            break;
            case 1:
            Copy16x16Tile(122, 436);
            Copy16x16Tile(123, 437);
            Copy16x16Tile(124, 438);
            Copy16x16Tile(125, 439);
            Copy16x16Tile(126, 440);
            Copy16x16Tile(127, 441);
            Copy16x16Tile(128, 442);
            Copy16x16Tile(129, 443);
            break;
            case 2:
            Copy16x16Tile(122, 444);
            Copy16x16Tile(123, 445);
            Copy16x16Tile(124, 446);
            Copy16x16Tile(125, 447);
            Copy16x16Tile(126, 448);
            Copy16x16Tile(127, 449);
            Copy16x16Tile(128, 450);
            Copy16x16Tile(129, 451);
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
            Copy16x16Tile(157, 452);
            Copy16x16Tile(158, 453);
            Copy16x16Tile(159, 456);
            Copy16x16Tile(160, 457);
            break;
            case 1:
            Copy16x16Tile(157, 454);
            Copy16x16Tile(158, 455);
            Copy16x16Tile(159, 458);
            Copy16x16Tile(160, 459);
            break;
            case 2:
            Copy16x16Tile(157, 460);
            Copy16x16Tile(158, 461);
            Copy16x16Tile(159, 464);
            Copy16x16Tile(160, 465);
            break;
            case 3:
            Copy16x16Tile(157, 462);
            Copy16x16Tile(158, 463);
            Copy16x16Tile(159, 466);
            Copy16x16Tile(160, 467);
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
    scriptEng.tempValue[1] = 0x20000;
    scriptEng.tempValue[2] = 0x10000;
    scriptEng.tempValue[1] *= scriptEng.tempValue[0];
    scriptEng.tempValue[2] *= scriptEng.tempValue[0];
    hParallax.scrollPos[0] += scriptEng.tempValue[1];
    hParallax.scrollPos[1] += scriptEng.tempValue[2];
}

#endif // RETRO_USE_NATIVE_OBJECTS

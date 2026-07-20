#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_Special_BGEffects_S1.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from BGEffects_S1.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_Special_BGEffects_S1::ObjectStartup()
{
    xBoundary1 = 0x3800000;
    xBoundary2 = 0xC800000;
    yBoundary1 = 0x3800000;
    yBoundary2 = 0xC800000;
    hParallax.scrollPos[0] += 0xF0000;
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("BGEffects")) {
            objectEntityList[scriptEng.arrayPosition[0]].priority = 1;
            objectEntityList[scriptEng.arrayPosition[0]].drawOrder = 0;
            objectEntityList[scriptEng.arrayPosition[0]].values[2] = 368;
        }
        scriptEng.arrayPosition[0]++;
    }
    SetLayerDeformation(2, 128, 16, 0, 0, 0);
}

void O_Special_BGEffects_S1::ObjectDraw()
{
    Entity *self = Self();

    self->values[3]++;
    if (self->values[3] > 2) {
        self->values[3] = 0;
        self->values[5]++;
        self->values[5] %= 3;
        switch (self->values[5]) {
            case 0:
            Copy16x16Tile(260, 420);
            Copy16x16Tile(259, 421);
            Copy16x16Tile(258, 422);
            Copy16x16Tile(257, 423);
            Copy16x16Tile(264, 424);
            Copy16x16Tile(263, 425);
            Copy16x16Tile(262, 426);
            Copy16x16Tile(261, 427);
            break;
            case 1:
            Copy16x16Tile(260, 428);
            Copy16x16Tile(259, 429);
            Copy16x16Tile(258, 430);
            Copy16x16Tile(257, 431);
            Copy16x16Tile(264, 432);
            Copy16x16Tile(263, 433);
            Copy16x16Tile(262, 434);
            Copy16x16Tile(261, 435);
            break;
            case 2:
            Copy16x16Tile(260, 436);
            Copy16x16Tile(259, 437);
            Copy16x16Tile(258, 438);
            Copy16x16Tile(257, 439);
            Copy16x16Tile(264, 440);
            Copy16x16Tile(263, 441);
            Copy16x16Tile(262, 442);
            Copy16x16Tile(261, 443);
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
            Copy16x16Tile(99, 444);
            Copy16x16Tile(98, 445);
            Copy16x16Tile(101, 448);
            Copy16x16Tile(100, 449);
            break;
            case 1:
            Copy16x16Tile(99, 446);
            Copy16x16Tile(98, 447);
            Copy16x16Tile(101, 450);
            Copy16x16Tile(100, 451);
            break;
            case 2:
            Copy16x16Tile(99, 452);
            Copy16x16Tile(98, 453);
            Copy16x16Tile(101, 456);
            Copy16x16Tile(100, 457);
            break;
            case 3:
            Copy16x16Tile(99, 454);
            Copy16x16Tile(98, 455);
            Copy16x16Tile(101, 458);
            Copy16x16Tile(100, 459);
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
    scriptEng.tempValue[1] = 0x02000;
    scriptEng.tempValue[2] = 0x20000;
    scriptEng.tempValue[3] = 0x10000;
    scriptEng.tempValue[1] *= scriptEng.tempValue[0];
    scriptEng.tempValue[2] *= scriptEng.tempValue[0];
    scriptEng.tempValue[3] *= scriptEng.tempValue[0];
    hParallax.scrollPos[2] += scriptEng.tempValue[2];
    hParallax.scrollPos[3] += scriptEng.tempValue[3];
}

#endif // RETRO_USE_NATIVE_OBJECTS

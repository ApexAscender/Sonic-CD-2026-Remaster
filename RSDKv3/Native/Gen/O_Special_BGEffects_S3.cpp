#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_Special_BGEffects_S3.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from BGEffects_S3.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_Special_BGEffects_S3::ObjectStartup()
{
    xBoundary1 = 0x3400000;
    xBoundary2 = 0xCC00000;
    yBoundary1 = 0x3400000;
    yBoundary2 = 0xCC00000;
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("BGEffects")) {
            objectEntityList[scriptEng.arrayPosition[0]].priority = 1;
            objectEntityList[scriptEng.arrayPosition[0]].drawOrder = 0;
            objectEntityList[scriptEng.arrayPosition[0]].values[2] = 368;
        }
        scriptEng.arrayPosition[0]++;
    }
    scriptEng.tempValue[0] = 1;
    while (scriptEng.tempValue[0] < 4) {
        RotatePalette(202, 205, 1);
        CopyPalette(0, scriptEng.tempValue[0]);
        scriptEng.tempValue[0]++;
    }
    RotatePalette(202, 205, 1);
}

void O_Special_BGEffects_S3::ObjectDraw()
{
    Entity *self = Self();

    self->values[3]++;
    if (self->values[3] > 2) {
        self->values[3] = 0;
        self->values[5]++;
        self->values[5] %= 3;
        switch (self->values[5]) {
            case 0:
            Copy16x16Tile(296, 520);
            Copy16x16Tile(297, 521);
            Copy16x16Tile(298, 522);
            Copy16x16Tile(299, 523);
            Copy16x16Tile(300, 524);
            Copy16x16Tile(301, 525);
            Copy16x16Tile(302, 526);
            Copy16x16Tile(303, 527);
            break;
            case 1:
            Copy16x16Tile(296, 528);
            Copy16x16Tile(297, 529);
            Copy16x16Tile(298, 530);
            Copy16x16Tile(299, 531);
            Copy16x16Tile(300, 532);
            Copy16x16Tile(301, 533);
            Copy16x16Tile(302, 534);
            Copy16x16Tile(303, 535);
            break;
            case 2:
            Copy16x16Tile(296, 536);
            Copy16x16Tile(297, 537);
            Copy16x16Tile(298, 538);
            Copy16x16Tile(299, 539);
            Copy16x16Tile(300, 540);
            Copy16x16Tile(301, 541);
            Copy16x16Tile(302, 542);
            Copy16x16Tile(303, 543);
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
            Copy16x16Tile(189, 544);
            Copy16x16Tile(190, 545);
            Copy16x16Tile(191, 548);
            Copy16x16Tile(192, 549);
            break;
            case 1:
            Copy16x16Tile(189, 546);
            Copy16x16Tile(190, 547);
            Copy16x16Tile(191, 550);
            Copy16x16Tile(192, 551);
            break;
            case 2:
            Copy16x16Tile(189, 552);
            Copy16x16Tile(190, 553);
            Copy16x16Tile(191, 556);
            Copy16x16Tile(192, 557);
            break;
            case 3:
            Copy16x16Tile(189, 554);
            Copy16x16Tile(190, 555);
            Copy16x16Tile(191, 558);
            Copy16x16Tile(192, 559);
            break;
        }
    }
    self->animationTimer++;
    if (self->animationTimer > 7) {
        self->animationTimer = 0;
        self->values[7]++;
        self->values[7] &= 3;
        SetActivePalette(self->values[7], 0, SCREEN_YSIZE);
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
    scriptEng.tempValue[1] = 0x40000;
    scriptEng.tempValue[2] = 0x30000;
    scriptEng.tempValue[3] = 0x10000;
    scriptEng.tempValue[4] = 0x20000;
    scriptEng.tempValue[1] *= scriptEng.tempValue[0];
    scriptEng.tempValue[2] *= scriptEng.tempValue[0];
    scriptEng.tempValue[3] *= scriptEng.tempValue[0];
    scriptEng.tempValue[4] *= scriptEng.tempValue[0];
    hParallax.scrollPos[1] += scriptEng.tempValue[1];
    hParallax.scrollPos[2] += scriptEng.tempValue[2];
    hParallax.scrollPos[3] += scriptEng.tempValue[3];
    hParallax.scrollPos[4] += scriptEng.tempValue[4];
}

#endif // RETRO_USE_NATIVE_OBJECTS

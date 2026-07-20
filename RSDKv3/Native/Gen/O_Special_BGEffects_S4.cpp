#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_Special_BGEffects_S4.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from BGEffects_S4.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_Special_BGEffects_S4::ObjectStartup()
{
    xBoundary1 = 0x3000000;
    xBoundary2 = 0xD000000;
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
    scriptEng.tempValue[0] = 1;
    while (scriptEng.tempValue[0] < 4) {
        RotatePalette(224, 227, 1);
        RotatePalette(240, 243, 1);
        CopyPalette(0, scriptEng.tempValue[0]);
        scriptEng.tempValue[0]++;
    }
    RotatePalette(224, 227, 1);
    RotatePalette(240, 243, 1);
}

void O_Special_BGEffects_S4::ObjectDraw()
{
    Entity *self = Self();

    self->values[3]++;
    if (self->values[3] > 2) {
        self->values[3] = 0;
        self->values[5]++;
        self->values[5] %= 3;
        switch (self->values[5]) {
            case 0:
            Copy16x16Tile(328, 484);
            Copy16x16Tile(329, 485);
            Copy16x16Tile(330, 486);
            Copy16x16Tile(331, 487);
            Copy16x16Tile(332, 488);
            Copy16x16Tile(333, 489);
            Copy16x16Tile(334, 490);
            Copy16x16Tile(335, 491);
            break;
            case 1:
            Copy16x16Tile(328, 492);
            Copy16x16Tile(329, 493);
            Copy16x16Tile(330, 494);
            Copy16x16Tile(331, 495);
            Copy16x16Tile(332, 496);
            Copy16x16Tile(333, 497);
            Copy16x16Tile(334, 498);
            Copy16x16Tile(335, 499);
            break;
            case 2:
            Copy16x16Tile(328, 500);
            Copy16x16Tile(329, 501);
            Copy16x16Tile(330, 502);
            Copy16x16Tile(331, 503);
            Copy16x16Tile(332, 504);
            Copy16x16Tile(333, 505);
            Copy16x16Tile(334, 506);
            Copy16x16Tile(335, 507);
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
    self->values[4]++;
    if (self->values[4] > 5) {
        self->values[4] = 0;
        self->values[6]++;
        self->values[6] &= 3;
        switch (self->values[6]) {
            case 0:
            Copy16x16Tile(134, 508);
            Copy16x16Tile(135, 509);
            Copy16x16Tile(136, 512);
            Copy16x16Tile(137, 513);
            break;
            case 1:
            Copy16x16Tile(134, 510);
            Copy16x16Tile(135, 511);
            Copy16x16Tile(136, 514);
            Copy16x16Tile(137, 515);
            break;
            case 2:
            Copy16x16Tile(134, 516);
            Copy16x16Tile(135, 517);
            Copy16x16Tile(136, 520);
            Copy16x16Tile(137, 521);
            break;
            case 3:
            Copy16x16Tile(134, 518);
            Copy16x16Tile(135, 519);
            Copy16x16Tile(136, 522);
            Copy16x16Tile(137, 523);
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
    scriptEng.tempValue[1] = 0x08000;
    scriptEng.tempValue[2] = 0x10000;
    scriptEng.tempValue[3] = 0x20000;
    scriptEng.tempValue[1] *= scriptEng.tempValue[0];
    scriptEng.tempValue[2] *= scriptEng.tempValue[0];
    scriptEng.tempValue[3] *= scriptEng.tempValue[0];
    hParallax.scrollPos[0] += scriptEng.tempValue[1];
    hParallax.scrollPos[1] += scriptEng.tempValue[2];
    hParallax.scrollPos[2] += scriptEng.tempValue[3];
}

#endif // RETRO_USE_NATIVE_OBJECTS

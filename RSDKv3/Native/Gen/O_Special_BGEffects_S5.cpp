#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_Special_BGEffects_S5.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from BGEffects_S5.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_Special_BGEffects_S5::ObjectStartup()
{
    xBoundary1 = 0x3000000;
    xBoundary2 = 0xD000000;
    yBoundary1 = 0x3000000;
    yBoundary2 = 0xD000000;
    hParallax.scrollPos[0] = 0xB00000;
    scriptEng.tempValue[0] = SCREEN_XSIZE;
    scriptEng.tempValue[0] -= 320;
    scriptEng.tempValue[0] <<= 15;
    hParallax.scrollPos[1] = 0x600000;
    hParallax.scrollPos[1] -= scriptEng.tempValue[0];
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("BGEffects")) {
            objectEntityList[scriptEng.arrayPosition[0]].priority = 1;
            objectEntityList[scriptEng.arrayPosition[0]].drawOrder = 0;
            objectEntityList[scriptEng.arrayPosition[0]].values[2] = 192;
            objectEntityList[scriptEng.arrayPosition[0]].scale = 1536;
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_Special_BGEffects_S5::ObjectDraw()
{
    Entity *self = Self();

    self->values[3]++;
    if (self->values[3] > 2) {
        self->values[3] = 0;
        self->values[5]++;
        self->values[5] %= 3;
        switch (self->values[5]) {
            case 0:
            Copy16x16Tile(174, 472);
            Copy16x16Tile(175, 473);
            Copy16x16Tile(176, 474);
            Copy16x16Tile(177, 475);
            Copy16x16Tile(183, 476);
            Copy16x16Tile(184, 477);
            Copy16x16Tile(185, 478);
            Copy16x16Tile(186, 479);
            break;
            case 1:
            Copy16x16Tile(174, 480);
            Copy16x16Tile(175, 481);
            Copy16x16Tile(176, 482);
            Copy16x16Tile(177, 483);
            Copy16x16Tile(183, 484);
            Copy16x16Tile(184, 485);
            Copy16x16Tile(185, 486);
            Copy16x16Tile(186, 487);
            break;
            case 2:
            Copy16x16Tile(174, 488);
            Copy16x16Tile(175, 489);
            Copy16x16Tile(176, 490);
            Copy16x16Tile(177, 491);
            Copy16x16Tile(183, 492);
            Copy16x16Tile(184, 493);
            Copy16x16Tile(185, 494);
            Copy16x16Tile(186, 495);
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
            Copy16x16Tile(76, 496);
            Copy16x16Tile(77, 497);
            Copy16x16Tile(82, 500);
            Copy16x16Tile(83, 501);
            break;
            case 1:
            Copy16x16Tile(76, 498);
            Copy16x16Tile(77, 499);
            Copy16x16Tile(82, 502);
            Copy16x16Tile(83, 503);
            break;
            case 2:
            Copy16x16Tile(76, 504);
            Copy16x16Tile(77, 505);
            Copy16x16Tile(82, 508);
            Copy16x16Tile(83, 509);
            break;
            case 3:
            Copy16x16Tile(76, 506);
            Copy16x16Tile(77, 507);
            Copy16x16Tile(82, 510);
            Copy16x16Tile(83, 511);
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
    scriptEng.tempValue[1] *= scriptEng.tempValue[0];
    hParallax.scrollPos[0] += scriptEng.tempValue[1];
    scriptEng.tempValue[2] *= scriptEng.tempValue[0];
    hParallax.scrollPos[2] += scriptEng.tempValue[2];
    hParallax.scrollPos[2] %= 0x600000;
    hParallax.scrollPos[3] = hParallax.scrollPos[2];
    hParallax.scrollPos[3] >>= 16;
    scriptEng.arrayPosition[0] = 128;
    scriptEng.tempValue[2] = 0x4000;
    scriptEng.tempValue[3] = 0;
    while (scriptEng.arrayPosition[0] > -1) {
        scriptEng.tempValue[4] = hParallax.scrollPos[3];
        scriptEng.tempValue[4] *= scriptEng.tempValue[2];
        scriptEng.tempValue[4] >>= 14;
        bgDeformationData2[scriptEng.arrayPosition[0]] = scriptEng.tempValue[4];
        scriptEng.tempValue[2] -= scriptEng.tempValue[3];
        scriptEng.tempValue[3]++;
        scriptEng.arrayPosition[0]--;
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS

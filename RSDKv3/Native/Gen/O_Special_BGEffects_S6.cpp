#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_Special_BGEffects_S6.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from BGEffects_S6.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_Special_BGEffects_S6::ObjectStartup()
{
    xBoundary1 = 0x2800000;
    xBoundary2 = 0xD800000;
    yBoundary1 = 0x3000000;
    yBoundary2 = 0xD000000;
    SetLayerDeformation(2, 64, 64, 0, 0, 0);
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

void O_Special_BGEffects_S6::ObjectDraw()
{
    Entity *self = Self();

    self->values[3]++;
    if (self->values[3] > 2) {
        self->values[3] = 0;
        self->values[5]++;
        self->values[5] %= 3;
        switch (self->values[5]) {
            case 0:
            Copy16x16Tile(37, 348);
            Copy16x16Tile(38, 349);
            Copy16x16Tile(39, 350);
            Copy16x16Tile(40, 351);
            Copy16x16Tile(41, 352);
            Copy16x16Tile(42, 353);
            Copy16x16Tile(43, 354);
            Copy16x16Tile(44, 355);
            break;
            case 1:
            Copy16x16Tile(37, 356);
            Copy16x16Tile(38, 357);
            Copy16x16Tile(39, 358);
            Copy16x16Tile(40, 359);
            Copy16x16Tile(41, 360);
            Copy16x16Tile(42, 361);
            Copy16x16Tile(43, 362);
            Copy16x16Tile(44, 363);
            break;
            case 2:
            Copy16x16Tile(37, 364);
            Copy16x16Tile(38, 365);
            Copy16x16Tile(39, 366);
            Copy16x16Tile(40, 367);
            Copy16x16Tile(41, 368);
            Copy16x16Tile(42, 369);
            Copy16x16Tile(43, 370);
            Copy16x16Tile(44, 371);
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
            Copy16x16Tile(134, 372);
            Copy16x16Tile(135, 373);
            Copy16x16Tile(136, 376);
            Copy16x16Tile(137, 377);
            break;
            case 1:
            Copy16x16Tile(134, 374);
            Copy16x16Tile(135, 375);
            Copy16x16Tile(136, 378);
            Copy16x16Tile(137, 379);
            break;
            case 2:
            Copy16x16Tile(134, 380);
            Copy16x16Tile(135, 381);
            Copy16x16Tile(136, 384);
            Copy16x16Tile(137, 385);
            break;
            case 3:
            Copy16x16Tile(134, 382);
            Copy16x16Tile(135, 383);
            Copy16x16Tile(136, 386);
            Copy16x16Tile(137, 387);
            break;
        }
    }
    self->values[0]++;
    if (self->values[0] > 1) {
        stageLayouts[1].deformationOffset++;
        self->values[0] = 0;
    }
    self->values[1]++;
    if (self->values[1] > 3) {
        self->values[1] = 0;
        RotatePalette(209, 221, 0);
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
    scriptEng.tempValue[1] *= scriptEng.tempValue[0];
    scriptEng.tempValue[2] *= scriptEng.tempValue[0];
    hParallax.scrollPos[1] += scriptEng.tempValue[2];
}

#endif // RETRO_USE_NATIVE_OBJECTS

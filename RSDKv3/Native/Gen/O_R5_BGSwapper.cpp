#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R5_BGSwapper.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from BGSwapper.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R5_BGSwapper::ObjectStartup()
{
    scriptEng.tempValue[0] = 0x4000;
    scriptEng.tempValue[1] = 0;
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("BG Swapper")) {
            if ((objectEntityList[scriptEng.arrayPosition[0]].XPos >> 16) < scriptEng.tempValue[0]) {
                scriptEng.tempValue[0] = (objectEntityList[scriptEng.arrayPosition[0]].XPos >> 16);
            }
            if ((objectEntityList[scriptEng.arrayPosition[0]].XPos >> 16) > scriptEng.tempValue[1]) {
                scriptEng.tempValue[1] = (objectEntityList[scriptEng.arrayPosition[0]].XPos >> 16);
            }
        }
        scriptEng.arrayPosition[0]++;
    }
    scriptEng.tempValue[2] = pXPos();
    scriptEng.tempValue[2] >>= 16;
    if (scriptEng.tempValue[2] > scriptEng.tempValue[0]) {
        if (scriptEng.tempValue[2] > scriptEng.tempValue[1]) {
            activeTileLayers[0] = 1;
        } else {
            activeTileLayers[0] = 2;
        }
    } else {
        activeTileLayers[0] = 1;
    }
}

void O_R5_BGSwapper::ObjectDraw()
{
    Entity *self = Self();

    if (self->propertyValue == 0) {
        if (pXPos() > self->XPos) {
            activeTileLayers[0] = 2;
        } else {
            activeTileLayers[0] = 1;
        }
    } else {
        if (pXPos() > self->XPos) {
            activeTileLayers[0] = 1;
        } else {
            activeTileLayers[0] = 2;
        }
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS

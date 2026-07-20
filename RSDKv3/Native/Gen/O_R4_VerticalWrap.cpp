#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R4_VerticalWrap.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from VerticalWrap.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R4_VerticalWrap::ObjectStartup()
{
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Water")) {
            scriptEng.tempValue[0] = scriptEng.arrayPosition[0];
        }
        scriptEng.arrayPosition[0]++;
    }
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Vertical Wrap")) {
            objectEntityList[scriptEng.arrayPosition[0]].values[0] = scriptEng.tempValue[0];
            switch (objectEntityList[scriptEng.arrayPosition[0]].propertyValue) {
                case 0:
                case 1:
                objectEntityList[scriptEng.arrayPosition[0]].values[1] = 0x5340000;
                objectEntityList[scriptEng.arrayPosition[0]].values[2] = 0;
                break;
                case 2:
                case 3:
                objectEntityList[scriptEng.arrayPosition[0]].propertyValue -= 2;
                objectEntityList[scriptEng.arrayPosition[0]].values[1] = 0x5A00000;
                objectEntityList[scriptEng.arrayPosition[0]].values[2] = 1;
                break;
                case 4:
                case 5:
                objectEntityList[scriptEng.arrayPosition[0]].propertyValue -= 2;
                objectEntityList[scriptEng.arrayPosition[0]].values[1] = 0x5100000;
                objectEntityList[scriptEng.arrayPosition[0]].values[2] = 0;
                break;
            }
        }
        scriptEng.arrayPosition[0]++;
    }
    if (pXPos() > 0x3200000) {
        yBoundary2 = 2048;
    }
}

void O_R4_VerticalWrap::ObjectMain()
{
    Entity *self = Self();

    if (pXPos() > self->XPos) {
        yBoundary2 = 2048;
        if (GetObjectOutOfBounds(objectLoop) == 1) {
            self->priority = 0;
        }
        if (GVar("Stage.NewWaterLevel") > self->values[1]) {
            GVar("Stage.NewWaterLevel") = self->values[1];
            scriptEng.arrayPosition[0] = self->values[0];
            objectEntityList[scriptEng.arrayPosition[0]].YPos = yScrollOffset;
            objectEntityList[scriptEng.arrayPosition[0]].YPos += 256;
            objectEntityList[scriptEng.arrayPosition[0]].YPos <<= 16;
            if (self->values[2] == 1) {
                if (objectEntityList[scriptEng.arrayPosition[0]].YPos < self->values[1]) {
                    objectEntityList[scriptEng.arrayPosition[0]].YPos = self->values[1];
                }
            }
        }
    } else {
        if (self->propertyValue == 0) {
            if (GVar("Stage.NewWaterLevel") < 0xC000000) {
                GVar("Stage.NewWaterLevel") = 0xC000000;
                scriptEng.arrayPosition[0] = self->values[0];
                objectEntityList[scriptEng.arrayPosition[0]].YPos = 0xC000000;
            }
        } else {
            if (pYPos() > self->YPos) {
                if (GVar("Stage.NewWaterLevel") < 0xC000000) {
                    GVar("Stage.NewWaterLevel") = 0xC000000;
                    scriptEng.arrayPosition[0] = self->values[0];
                    objectEntityList[scriptEng.arrayPosition[0]].YPos = 0xC000000;
                }
            }
        }
        yBoundary2 = 2304;
        self->priority = 1;
        if (pYVel() >= 0) {
            if (yScrollOffset > 2047) {
                pYPos() -= 0x8000000;
                yScrollOffset -= 2048;
            }
        }
        if (pYVel() <= 0) {
            if (yScrollOffset < 1) {
                pYPos() += 0x8000000;
                yScrollOffset += 2048;
            }
        }
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS

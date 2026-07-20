#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R4_StreamChange.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from StreamChange.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R4_StreamChange::ObjectMain()
{
    Entity *self = Self();

    if (objectEntityList[objectLoop - 2].propertyValue == 1) {
        if (self->propertyValue != self->values[1]) {
            scriptEng.arrayPosition[0] = objectLoop;
            objectEntityList[scriptEng.arrayPosition[0]].values[1] = self->propertyValue;
            if (self->propertyValue == 0) {
                scriptEng.arrayPosition[0]++;
                while (objectEntityList[scriptEng.arrayPosition[0]].type != TypeNameID("Stream Change")) {
                    if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Water Stream L")) {
                        objectEntityList[scriptEng.arrayPosition[0]].type = TypeNameID("Water Stream R");
                    } else {
                        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Water Stream R")) {
                            objectEntityList[scriptEng.arrayPosition[0]].type = TypeNameID("Water Stream L");
                        }
                    }
                    if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Water Stream U")) {
                        objectEntityList[scriptEng.arrayPosition[0]].type = TypeNameID("Water Stream D");
                    } else {
                        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Water Stream D")) {
                            objectEntityList[scriptEng.arrayPosition[0]].type = TypeNameID("Water Stream U");
                        }
                    }
                    if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Water Stream C")) {
                        if (objectEntityList[scriptEng.arrayPosition[0]].values[1] == 64) {
                            objectEntityList[scriptEng.arrayPosition[0]].values[1] = 192;
                        } else {
                            objectEntityList[scriptEng.arrayPosition[0]].values[1] = 64;
                        }
                    }
                    scriptEng.arrayPosition[0]++;
                }
            } else {
                scriptEng.arrayPosition[0]--;
                while (objectEntityList[scriptEng.arrayPosition[0]].type != TypeNameID("Stream Change")) {
                    if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Water Stream L")) {
                        objectEntityList[scriptEng.arrayPosition[0]].type = TypeNameID("Water Stream R");
                    } else {
                        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Water Stream R")) {
                            objectEntityList[scriptEng.arrayPosition[0]].type = TypeNameID("Water Stream L");
                        }
                    }
                    if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Water Stream U")) {
                        objectEntityList[scriptEng.arrayPosition[0]].type = TypeNameID("Water Stream D");
                    } else {
                        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Water Stream D")) {
                            objectEntityList[scriptEng.arrayPosition[0]].type = TypeNameID("Water Stream U");
                        }
                    }
                    if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Water Stream C")) {
                        if (objectEntityList[scriptEng.arrayPosition[0]].values[1] == 64) {
                            objectEntityList[scriptEng.arrayPosition[0]].values[1] = 192;
                        } else {
                            objectEntityList[scriptEng.arrayPosition[0]].values[1] = 64;
                        }
                    }
                    scriptEng.arrayPosition[0]--;
                }
            }
            objectEntityList[scriptEng.arrayPosition[0]].values[1] = self->propertyValue;
        }
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS

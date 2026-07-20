#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_Mission_IcdBlockCollision.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from IcdBlockCollision.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_Mission_IcdBlockCollision::ObjectMain()
{
    Entity *self = Self();

    if (self->values[0] == 0) {
        scriptEng.arrayPosition[0] = 1056;
        while (scriptEng.arrayPosition[0] < 1184) {
            CheckResult() = (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Ice Block"));
            scriptEng.tempValue[0] = CheckResult();
            CheckResult() = (objectEntityList[scriptEng.arrayPosition[0]].propertyValue == 0);
            scriptEng.tempValue[0] &= CheckResult();
            CheckResult() = (objectEntityList[scriptEng.arrayPosition[0]].state == 0);
            scriptEng.tempValue[0] &= CheckResult();
            if (scriptEng.tempValue[0] == 1) {
                self->values[0] = scriptEng.arrayPosition[0];
                self->priority = 1;
                scriptEng.arrayPosition[0] = 10000;
            }
            scriptEng.arrayPosition[0]++;
        }
    }
    if (self->values[0] != 0) {
        scriptEng.arrayPosition[1] = self->values[0];
        scriptEng.arrayPosition[0] = 32;
        if (objectEntityList[scriptEng.arrayPosition[1]].state == 1) {
            self->values[0] = 0;
            self->priority = 0;
            scriptEng.arrayPosition[0] = 10000;
        }
        while (scriptEng.arrayPosition[0] < 1056) {
            CheckResult() = (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("MissionBlock"));
            scriptEng.tempValue[0] = CheckResult();
            CheckResult() = (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Moving Blocks"));
            scriptEng.tempValue[0] |= CheckResult();
            if (scriptEng.tempValue[0] == 1) {
                scriptEng.tempValue[1] = objectEntityList[scriptEng.arrayPosition[0]].YPos;
                scriptEng.tempValue[1] -= objectEntityList[scriptEng.arrayPosition[1]].YPos;
                CheckResult() = (scriptEng.tempValue[1] < 0x280000);
                scriptEng.tempValue[0] = CheckResult();
                CheckResult() = (scriptEng.tempValue[1] > -0x200000);
                scriptEng.tempValue[0] &= CheckResult();
                if (scriptEng.tempValue[0] == 1) {
                    scriptEng.tempValue[1] = objectEntityList[scriptEng.arrayPosition[0]].XPos;
                    scriptEng.tempValue[1] -= objectEntityList[scriptEng.arrayPosition[1]].XPos;
                    CheckResult() = (scriptEng.tempValue[1] < 0x200000);
                    scriptEng.tempValue[0] = CheckResult();
                    CheckResult() = (scriptEng.tempValue[1] > -0x200000);
                    scriptEng.tempValue[0] &= CheckResult();
                    if (scriptEng.tempValue[0] == 1) {
                        objectEntityList[scriptEng.arrayPosition[1]].YPos = objectEntityList[scriptEng.arrayPosition[0]].YPos;
                        objectEntityList[scriptEng.arrayPosition[1]].YPos -= 0x280000;
                        objectEntityList[scriptEng.arrayPosition[1]].state = 1;
                        objectEntityList[scriptEng.arrayPosition[1]].values[2] = 0;
                        PlaySfx(globalSFXCount + 4, 0);
                        self->values[0] = 0;
                        self->priority = 0;
                        scriptEng.arrayPosition[0] = 10000;
                    }
                }
            }
            scriptEng.arrayPosition[0]++;
        }
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS

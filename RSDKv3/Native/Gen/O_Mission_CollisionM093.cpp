#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_Mission_CollisionM093.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from CollisionM093.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_Mission_CollisionM093::ObjectStartup()
{
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("CollisionM093")) {
            objectEntityList[scriptEng.arrayPosition[0]].priority = 1;
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_Mission_CollisionM093::ObjectMain()
{
    Entity *self = Self();

    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        CheckResult() = 0;
        switch (objectEntityList[scriptEng.arrayPosition[0]].type) {
            case 53:
            case 54:
            case 57:
            case 76:
            CheckResult() = 1;
            break;
        }
        if (CheckResult() == 1) {
            scriptEng.arrayPosition[1] = 32;
            self->XPos = objectEntityList[scriptEng.arrayPosition[0]].XPos;
            self->XPos >>= 16;
            self->YPos = objectEntityList[scriptEng.arrayPosition[0]].YPos;
            self->YPos >>= 16;
        } else {
            scriptEng.arrayPosition[1] = 2000;
        }
        while (scriptEng.arrayPosition[1] < 1056) {
            if (objectEntityList[scriptEng.arrayPosition[1]].type == TypeNameID("MissionBlock")) {
                if (objectEntityList[scriptEng.arrayPosition[1]].propertyValue <= 1) {
                    scriptEng.tempValue[3] = -16;
                } else {
                    scriptEng.tempValue[3] = -32;
                    scriptEng.tempValue[3] *= objectEntityList[scriptEng.arrayPosition[1]].propertyValue;
                    scriptEng.tempValue[3] += 16;
                }
                scriptEng.tempValue[4] = 16;
                scriptEng.tempValue[0] = objectEntityList[scriptEng.arrayPosition[1]].XPos;
                scriptEng.tempValue[0] >>= 16;
                scriptEng.tempValue[0] -= self->XPos;
                CheckResult() = (scriptEng.tempValue[0] > scriptEng.tempValue[3]);
                scriptEng.tempValue[1] = CheckResult();
                CheckResult() = (scriptEng.tempValue[0] < scriptEng.tempValue[4]);
                scriptEng.tempValue[1] &= CheckResult();
                if (scriptEng.tempValue[1] == 1) {
                    scriptEng.tempValue[2] = objectEntityList[scriptEng.arrayPosition[1]].YPos;
                    scriptEng.tempValue[2] >>= 16;
                    scriptEng.tempValue[1] = self->YPos;
                    scriptEng.tempValue[1] += 16;
                    scriptEng.tempValue[2] -= scriptEng.tempValue[1];
                    CheckResult() = (scriptEng.tempValue[2] > -16);
                    scriptEng.tempValue[1] = CheckResult();
                    CheckResult() = (scriptEng.tempValue[2] < 15);
                    scriptEng.tempValue[1] &= CheckResult();
                    if (scriptEng.tempValue[1] == 1) {
                        self->YPos = objectEntityList[scriptEng.arrayPosition[1]].YPos;
                        self->YPos >>= 16;
                        self->YPos -= 32;
                        objectEntityList[scriptEng.arrayPosition[0]].YPos = self->YPos;
                        objectEntityList[scriptEng.arrayPosition[0]].YPos <<= 16;
                        scriptEng.tempValue[2] = 16;
                    }
                    if (scriptEng.tempValue[2] == 16) {
                        switch (objectEntityList[scriptEng.arrayPosition[0]].type) {
                            case 53:
                            case 54:
                            objectEntityList[scriptEng.arrayPosition[0]].values[0] = objectEntityList[scriptEng.arrayPosition[0]].values[2];
                            switch (objectEntityList[scriptEng.arrayPosition[0]].state) {
                                case 0:
                                objectEntityList[scriptEng.arrayPosition[0]].state = 1;
                                break;
                                case 1:
                                scriptEng.tempValue[5] = scriptEng.tempValue[3];
                                scriptEng.tempValue[5] += 4;
                                if (scriptEng.tempValue[0] > scriptEng.tempValue[5]) {
                                    objectEntityList[scriptEng.arrayPosition[0]].values[0]++;
                                    if (objectEntityList[scriptEng.arrayPosition[0]].values[0] != 320) {
                                        objectEntityList[scriptEng.arrayPosition[0]].state = 2;
                                        objectEntityList[scriptEng.arrayPosition[0]].direction = 1;
                                    }
                                }
                                break;
                                case 2:
                                scriptEng.tempValue[5] = scriptEng.tempValue[4];
                                scriptEng.tempValue[5] -= 4;
                                if (scriptEng.tempValue[0] < scriptEng.tempValue[5]) {
                                    objectEntityList[scriptEng.arrayPosition[0]].values[0]--;
                                    if (objectEntityList[scriptEng.arrayPosition[0]].values[0] != -320) {
                                        objectEntityList[scriptEng.arrayPosition[0]].state = 1;
                                        objectEntityList[scriptEng.arrayPosition[0]].direction = 0;
                                    }
                                }
                                break;
                            }
                            objectEntityList[scriptEng.arrayPosition[0]].values[2] = objectEntityList[scriptEng.arrayPosition[0]].values[0];
                            break;
                            case 57:
                            case 76:
                            if (objectEntityList[scriptEng.arrayPosition[0]].state == 0) {
                                if (objectEntityList[scriptEng.arrayPosition[0]].values[1] > 0) {
                                    objectEntityList[scriptEng.arrayPosition[0]].YPos += 0x80000;
                                    objectEntityList[scriptEng.arrayPosition[0]].frame = 0;
                                    objectEntityList[scriptEng.arrayPosition[0]].drawOrder = 3;
                                    if (objectEntityList[scriptEng.arrayPosition[0]].propertyValue == 0) {
                                        objectEntityList[scriptEng.arrayPosition[0]].state = 1;
                                    } else {
                                        objectEntityList[scriptEng.arrayPosition[0]].state = 2;
                                        objectEntityList[scriptEng.arrayPosition[0]].direction = 1;
                                    }
                                }
                            }
                            break;
                        }
                    }
                }
            }
            scriptEng.arrayPosition[1]++;
        }
        scriptEng.arrayPosition[0]++;
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS

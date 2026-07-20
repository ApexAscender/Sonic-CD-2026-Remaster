#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_DAGarden_Buttons.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from Buttons.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_DAGarden_Buttons::ObjectStartup()
{
    LoadSpriteSheet("DAGarden/Objects.gif");
    AddSpriteFrame(-32, -16, 63, 31, 146, 577);
    AddSpriteFrame(-32, -16, 63, 31, 146, 609);
    AddSpriteFrame(-32, -16, 63, 31, 210, 577);
    AddSpriteFrame(-32, -16, 63, 31, 210, 609);
    AddSpriteFrame(-32, -16, 63, 31, 274, 577);
    AddSpriteFrame(-32, -16, 63, 31, 274, 609);
    AddSpriteFrame(-32, -16, 63, 31, 338, 577);
    AddSpriteFrame(-32, -16, 63, 31, 338, 609);
    AddSpriteFrame(-32, -16, 63, 31, 210, 641);
    AddSpriteFrame(-32, -16, 63, 31, 210, 673);
    AddSpriteFrame(-32, -16, 63, 31, 274, 641);
    AddSpriteFrame(-32, -16, 63, 31, 274, 673);
    AddSpriteFrame(-32, -16, 63, 31, 338, 641);
    AddSpriteFrame(-32, -16, 63, 31, 338, 673);
    AddSpriteFrame(-32, -16, 63, 31, 402, 641);
    AddSpriteFrame(-32, -16, 63, 31, 402, 673);
    AddSpriteFrame(-32, -16, 63, 31, 402, 577);
    AddSpriteFrame(-32, -16, 63, 31, 402, 609);
}

void O_DAGarden_Buttons::ObjectMain()
{
    Entity *self = Self();

    if (objectEntityList[0].state > 1) {
        if (objectEntityList[0].state < 4) {
            if (Engine.message == 2) {
                self->values[1] = 0;
            }
            scriptEng.tempValue[0] = self->XPos;
            scriptEng.tempValue[0] >>= 16;
            scriptEng.tempValue[1] = scriptEng.tempValue[0];
            scriptEng.tempValue[0] -= 32;
            scriptEng.tempValue[0] -= xScrollOffset;
            scriptEng.tempValue[1] += 32;
            scriptEng.tempValue[1] -= xScrollOffset;
            CheckTouchRect_Script(scriptEng.tempValue[0], 0, scriptEng.tempValue[1], 32);
            if (CheckResult() > -1) {
                self->values[1] = self->propertyValue;
                self->values[1]++;
                switch (self->propertyValue) {
                    case 0:
                    if (objectEntityList[32].values[1] < 0x4000) {
                        objectEntityList[32].values[1] += 8;
                    }
                    break;
                    case 1:
                    if (objectEntityList[32].values[1] > 48) {
                        objectEntityList[32].values[1] -= 8;
                    }
                    break;
                    case 2:
                    if (objectEntityList[32].values[3] < 256) {
                        objectEntityList[32].values[3] += 2;
                    }
                    break;
                    case 3:
                    if (objectEntityList[32].values[3] > -256) {
                        objectEntityList[32].values[3] -= 2;
                    }
                    break;
                }
            } else {
                CheckTouchRect_Script(0, 0, SCREEN_XSIZE, SCREEN_YSIZE);
                if (CheckResult() < 0) {
                    switch (self->propertyValue) {
                        case 0:
                        if (self->values[1] == 1) {
                            self->values[1] = 0;
                            objectEntityList[35].propertyValue = 1;
                        }
                        break;
                        case 1:
                        if (self->values[1] == 2) {
                            self->values[1] = 0;
                            objectEntityList[35].propertyValue = 0;
                        }
                        break;
                        case 2:
                        if (self->values[1] == 3) {
                            self->values[1] = 0;
                        }
                        break;
                        case 3:
                        if (self->values[1] == 4) {
                            self->values[1] = 0;
                        }
                        break;
                        case 4:
                        if (self->values[1] == 5) {
                            self->values[1] = 0;
                            PlaySfx(23, 0);
                            objectEntityList[33].state = 4;
                        }
                        break;
                        case 5:
                        if (self->values[1] == 6) {
                            self->values[1] = 0;
                            objectEntityList[0].state = 4;
                            StopMusic();
                        }
                        break;
                        case 6:
                        if (self->values[1] == 7) {
                            self->values[1] = 0;
                            PlaySfx(23, 0);
                            objectEntityList[33].state = 2;
                        }
                        break;
                        case 7:
                        if (self->values[1] == 8) {
                            self->values[1] = 0;
                            PlaySfx(27, 0);
                            objectEntityList[0].state = 3;
                            objectEntityList[33].XPos = SCREEN_XSIZE;
                            objectEntityList[33].XPos += 96;
                            objectEntityList[33].XPos <<= 16;
                            objectEntityList[33].state = 1;
                            objectEntityList[33].drawOrder = 5;
                            objectEntityList[33].priority = 1;
                            objectEntityList[35].propertyValue = 4;
                            objectEntityList[36].propertyValue = 5;
                            objectEntityList[37].propertyValue = 6;
                        }
                        break;
                        case 8:
                        if (self->values[1] == 9) {
                            self->values[1] = 0;
                            StopMusic();
                            PlaySfx(27, 0);
                            objectEntityList[0].state = 6;
                        }
                        break;
                    }
                } else {
                    switch (self->propertyValue) {
                        case 0:
                        if (self->values[1] == 1) {
                            self->values[1] = 0;
                        }
                        break;
                        case 1:
                        if (self->values[1] == 2) {
                            self->values[1] = 0;
                        }
                        break;
                        case 2:
                        if (self->values[1] == 3) {
                            self->values[1] = 0;
                        }
                        break;
                        case 3:
                        if (self->values[1] == 4) {
                            self->values[1] = 0;
                        }
                        break;
                        case 4:
                        if (self->values[1] == 5) {
                            self->values[1] = 0;
                        }
                        break;
                        case 5:
                        if (self->values[1] == 6) {
                            self->values[1] = 0;
                        }
                        break;
                        case 6:
                        if (self->values[1] == 7) {
                            self->values[1] = 0;
                        }
                        break;
                        case 7:
                        if (self->values[1] == 8) {
                            self->values[1] = 0;
                        }
                        break;
                        case 8:
                        if (self->values[1] == 9) {
                            self->values[1] = 0;
                        }
                        break;
                    }
                }
            }
        }
    }
}

void O_DAGarden_Buttons::ObjectDraw()
{
    Entity *self = Self();

    scriptEng.tempValue[0] = self->propertyValue;
    scriptEng.tempValue[0] <<= 1;
    scriptEng.tempValue[1] = self->propertyValue;
    scriptEng.tempValue[1]++;
    if (self->values[1] == scriptEng.tempValue[1]) {
        scriptEng.tempValue[0]++;
    }
    DrawSprite_Frame(scriptEng.tempValue[0]);
}

#endif // RETRO_USE_NATIVE_OBJECTS

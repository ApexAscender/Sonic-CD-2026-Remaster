#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R8_ConveyorPlatforms.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from ConveyorPlatforms.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R8_ConveyorPlatforms::ObjectStartup()
{
    LoadSpriteSheet("R8/Objects.gif");
    AddSpriteFrame(-16, -8, 32, 16, 107, 98);
    AddSpriteFrame(-16, -12, 32, 24, 107, 115);
    AddSpriteFrame(-12, -16, 24, 32, 230, 34);
    AddSpriteFrame(-8, -16, 16, 32, 239, 212);
    AddSpriteFrame(-12, -16, 24, 32, 230, 34);
    AddSpriteFrame(-16, -12, 32, 24, 107, 115);
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("CPlatforms")) {
            if (objectEntityList[scriptEng.arrayPosition[0]].propertyValue == 0) {
                scriptEng.arrayPosition[0]++;
                objectEntityList[scriptEng.arrayPosition[0]].values[1] = 0;
                objectEntityList[scriptEng.arrayPosition[0]].values[6] = 1;
                objectEntityList[scriptEng.arrayPosition[0]].values[2] = objectEntityList[scriptEng.arrayPosition[0]].XPos;
                objectEntityList[scriptEng.arrayPosition[0]].values[3] = objectEntityList[scriptEng.arrayPosition[0]].YPos;
                scriptEng.arrayPosition[0]++;
                objectEntityList[scriptEng.arrayPosition[0]].values[1] = 90;
                objectEntityList[scriptEng.arrayPosition[0]].values[6] = 1;
                objectEntityList[scriptEng.arrayPosition[0]].values[2] = objectEntityList[scriptEng.arrayPosition[0]].XPos;
                objectEntityList[scriptEng.arrayPosition[0]].values[3] = objectEntityList[scriptEng.arrayPosition[0]].YPos;
                scriptEng.arrayPosition[0]++;
                objectEntityList[scriptEng.arrayPosition[0]].values[1] = 180;
                objectEntityList[scriptEng.arrayPosition[0]].values[6] = 1;
                objectEntityList[scriptEng.arrayPosition[0]].values[2] = objectEntityList[scriptEng.arrayPosition[0]].XPos;
                objectEntityList[scriptEng.arrayPosition[0]].values[3] = objectEntityList[scriptEng.arrayPosition[0]].YPos;
                scriptEng.arrayPosition[0]++;
                objectEntityList[scriptEng.arrayPosition[0]].values[1] = 268;
                objectEntityList[scriptEng.arrayPosition[0]].values[6] = 1;
                objectEntityList[scriptEng.arrayPosition[0]].values[2] = objectEntityList[scriptEng.arrayPosition[0]].XPos;
                objectEntityList[scriptEng.arrayPosition[0]].values[3] = objectEntityList[scriptEng.arrayPosition[0]].YPos;
                scriptEng.arrayPosition[0]++;
                objectEntityList[scriptEng.arrayPosition[0]].values[1] = 358;
                objectEntityList[scriptEng.arrayPosition[0]].values[6] = 1;
                objectEntityList[scriptEng.arrayPosition[0]].values[2] = objectEntityList[scriptEng.arrayPosition[0]].XPos;
                objectEntityList[scriptEng.arrayPosition[0]].values[3] = objectEntityList[scriptEng.arrayPosition[0]].YPos;
            }
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_R8_ConveyorPlatforms::ObjectMain()
{
    Entity *self = Self();

    if (self->propertyValue == 0) {
        scriptEng.tempValue[2] = 0;
        scriptEng.arrayPosition[0] = objectLoop;
        scriptEng.arrayPosition[0]++;
        while (scriptEng.tempValue[2] < 5) {
            objectEntityList[scriptEng.arrayPosition[0]].values[0] = objectEntityList[scriptEng.arrayPosition[0]].values[1];
            objectEntityList[scriptEng.arrayPosition[0]].values[0] += self->values[0];
            objectEntityList[scriptEng.arrayPosition[0]].values[0] %= 448;
            if (objectEntityList[scriptEng.arrayPosition[0]].values[0] < 160) {
                objectEntityList[scriptEng.arrayPosition[0]].values[4] = self->XPos;
                objectEntityList[scriptEng.arrayPosition[0]].values[4] -= 0x400000;
                scriptEng.tempValue[0] = objectEntityList[scriptEng.arrayPosition[0]].values[0];
                scriptEng.tempValue[0] <<= 16;
                objectEntityList[scriptEng.arrayPosition[0]].values[4] += scriptEng.tempValue[0];
                objectEntityList[scriptEng.arrayPosition[0]].values[5] = self->YPos;
                objectEntityList[scriptEng.arrayPosition[0]].values[5] -= 0x3A0000;
                scriptEng.tempValue[0] = objectEntityList[scriptEng.arrayPosition[0]].values[0];
                scriptEng.tempValue[0] <<= 15;
                objectEntityList[scriptEng.arrayPosition[0]].values[5] += scriptEng.tempValue[0];
            } else {
                if (objectEntityList[scriptEng.arrayPosition[0]].values[0] < 224) {
                    scriptEng.tempValue[0] = objectEntityList[scriptEng.arrayPosition[0]].values[0];
                    scriptEng.tempValue[0] -= 144;
                    scriptEng.tempValue[0] <<= 2;
                    if (scriptEng.tempValue[0] > 144) {
                        objectEntityList[scriptEng.arrayPosition[0]].rotation++;
                        objectEntityList[scriptEng.arrayPosition[0]].rotation %= 24;
                        objectEntityList[scriptEng.arrayPosition[0]].values[6] = 0;
                    }
                    objectEntityList[scriptEng.arrayPosition[0]].values[4] = Sin512(scriptEng.tempValue[0]);
                    objectEntityList[scriptEng.arrayPosition[0]].values[4] *= 0xC00;
                    objectEntityList[scriptEng.arrayPosition[0]].values[4] += self->XPos;
                    objectEntityList[scriptEng.arrayPosition[0]].values[4] += 0x500000;
                    objectEntityList[scriptEng.arrayPosition[0]].values[5] = Cos512(scriptEng.tempValue[0]);
                    objectEntityList[scriptEng.arrayPosition[0]].values[5] *= -0xC00;
                    objectEntityList[scriptEng.arrayPosition[0]].values[5] += self->YPos;
                    objectEntityList[scriptEng.arrayPosition[0]].values[5] += 0x280000;
                } else {
                    if (objectEntityList[scriptEng.arrayPosition[0]].values[0] < 384) {
                        objectEntityList[scriptEng.arrayPosition[0]].rotation++;
                        objectEntityList[scriptEng.arrayPosition[0]].rotation %= 24;
                        objectEntityList[scriptEng.arrayPosition[0]].values[6] = 0;
                        scriptEng.tempValue[0] = objectEntityList[scriptEng.arrayPosition[0]].values[0];
                        scriptEng.tempValue[0] -= 224;
                        objectEntityList[scriptEng.arrayPosition[0]].values[4] = self->XPos;
                        objectEntityList[scriptEng.arrayPosition[0]].values[4] += 0x3E0000;
                        scriptEng.tempValue[1] = scriptEng.tempValue[0];
                        scriptEng.tempValue[1] <<= 16;
                        objectEntityList[scriptEng.arrayPosition[0]].values[4] -= scriptEng.tempValue[1];
                        objectEntityList[scriptEng.arrayPosition[0]].values[5] = self->YPos;
                        objectEntityList[scriptEng.arrayPosition[0]].values[5] += 0x390000;
                        scriptEng.tempValue[1] = scriptEng.tempValue[0];
                        scriptEng.tempValue[1] <<= 15;
                        objectEntityList[scriptEng.arrayPosition[0]].values[5] -= scriptEng.tempValue[1];
                    } else {
                        scriptEng.tempValue[0] = objectEntityList[scriptEng.arrayPosition[0]].values[0];
                        scriptEng.tempValue[0] -= 368;
                        scriptEng.tempValue[0] <<= 2;
                        if (scriptEng.tempValue[0] > 144) {
                            objectEntityList[scriptEng.arrayPosition[0]].rotation = 0;
                            objectEntityList[scriptEng.arrayPosition[0]].values[6] = 1;
                        } else {
                            objectEntityList[scriptEng.arrayPosition[0]].rotation++;
                            objectEntityList[scriptEng.arrayPosition[0]].rotation %= 24;
                            objectEntityList[scriptEng.arrayPosition[0]].values[6] = 0;
                        }
                        objectEntityList[scriptEng.arrayPosition[0]].values[4] = Sin512(scriptEng.tempValue[0]);
                        objectEntityList[scriptEng.arrayPosition[0]].values[4] *= -0xC00;
                        objectEntityList[scriptEng.arrayPosition[0]].values[4] += self->XPos;
                        objectEntityList[scriptEng.arrayPosition[0]].values[4] -= 0x500000;
                        objectEntityList[scriptEng.arrayPosition[0]].values[5] = Cos512(scriptEng.tempValue[0]);
                        objectEntityList[scriptEng.arrayPosition[0]].values[5] *= 0xC00;
                        objectEntityList[scriptEng.arrayPosition[0]].values[5] += self->YPos;
                        objectEntityList[scriptEng.arrayPosition[0]].values[5] -= 0x280000;
                    }
                }
            }
            objectEntityList[scriptEng.arrayPosition[0]].values[4] &= 0xFFFF0000;
            objectEntityList[scriptEng.arrayPosition[0]].values[2] = objectEntityList[scriptEng.arrayPosition[0]].values[4];
            objectEntityList[scriptEng.arrayPosition[0]].values[4] -= objectEntityList[scriptEng.arrayPosition[0]].XPos;
            objectEntityList[scriptEng.arrayPosition[0]].values[5] &= 0xFFFF0000;
            objectEntityList[scriptEng.arrayPosition[0]].values[3] = objectEntityList[scriptEng.arrayPosition[0]].values[5];
            objectEntityList[scriptEng.arrayPosition[0]].values[5] -= objectEntityList[scriptEng.arrayPosition[0]].YPos;
            scriptEng.tempValue[2]++;
            scriptEng.arrayPosition[0]++;
        }
        self->values[0]++;
        self->values[0] %= 448;
    }
}

void O_R8_ConveyorPlatforms::ObjectPlayerInteraction()
{
    Entity *self = Self();

    if (self->propertyValue == 1) {
        if (self->values[6] == 1) {
            PlayerObjectCollision(C_PLATFORM, -16, -5, 16, 11);
            if (CheckResult() == 1) {
                pXPos() += self->values[4];
                pYPos() += self->values[5];
            }
        }
    }
}

void O_R8_ConveyorPlatforms::ObjectDraw()
{
    Entity *self = Self();

    if (self->propertyValue == 1) {
        self->XPos = self->values[2];
        self->YPos = self->values[3];
        scriptEng.tempValue[0] = self->rotation;
        scriptEng.tempValue[0] >>= 1;
        switch (scriptEng.tempValue[0]) {
            case 0:
            case 6:
            DrawSprite_Frame(0);
            break;
            case 1:
            case 7:
            DrawSprite_Frame(1);
            break;
            case 2:
            case 8:
            DrawSprite_Frame(2);
            break;
            case 3:
            case 9:
            DrawSprite_Frame(3);
            break;
            case 4:
            case 10:
            self->direction = 1;
            DrawSpriteFX_Script(4, FX_FLIP, self->XPos, self->YPos);
            break;
            case 5:
            case 11:
            self->direction = 1;
            DrawSpriteFX_Script(5, FX_FLIP, self->XPos, self->YPos);
            break;
        }
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS

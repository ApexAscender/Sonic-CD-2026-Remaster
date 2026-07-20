#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_Special_UFO.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from UFO.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_Special_UFO::ObjectStartup()
{
    LoadSpriteSheet("Special/Objects.gif");
    AddSpriteFrame(-40, -28, 80, 56, 1, 1);
    AddSpriteFrame(-40, -28, 80, 56, 82, 1);
    AddSpriteFrame(-40, -28, 80, 56, 163, 1);
    AddSpriteFrame(-40, -8, 80, 16, 1, 117);
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("UFO")) {
            objectEntityList[scriptEng.arrayPosition[0]].priority = 1;
            if (objectEntityList[scriptEng.arrayPosition[0]].propertyValue < 2) {
                objectEntityList[4].values[0]++;
            } else {
                objectEntityList[scriptEng.arrayPosition[0]].type = TypeNameID("Blank Object");
                objectEntityList[4].values[6] = scriptEng.arrayPosition[0];
            }
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_Special_UFO::ObjectMain()
{
    Entity *self = Self();

    if (self->values[3] == 0) {
        scriptEng.arrayPosition[0] = self->values[0];
        if (objectEntityList[scriptEng.arrayPosition[0]].type != TypeNameID("UFO Node")) {
            self->values[0] = objectLoop;
            self->values[0]++;
            scriptEng.arrayPosition[0] = self->values[0];
        }
        self->XPos = objectEntityList[scriptEng.arrayPosition[0]].XPos;
        self->YPos = objectEntityList[scriptEng.arrayPosition[0]].YPos;
        self->values[3] = objectEntityList[scriptEng.arrayPosition[0]].propertyValue;
        self->values[3] *= 2;
        scriptEng.arrayPosition[0]++;
        self->values[0]++;
        if (objectEntityList[scriptEng.arrayPosition[0]].type != TypeNameID("UFO Node")) {
            self->values[0] = objectLoop;
            self->values[0]++;
            scriptEng.arrayPosition[0] = self->values[0];
        }
        self->values[1] = objectEntityList[scriptEng.arrayPosition[0]].XPos;
        self->values[1] -= self->XPos;
        self->values[1] /= self->values[3];
        self->values[2] = objectEntityList[scriptEng.arrayPosition[0]].YPos;
        self->values[2] -= self->YPos;
        self->values[2] /= self->values[3];
    } else {
        self->values[3]--;
        self->XPos += self->values[1];
        self->YPos += self->values[2];
    }
    scriptEng.tempValue[0] = self->XPos;
    scriptEng.tempValue[0] -= stageLayouts[0].XPos;
    scriptEng.tempValue[0] >>= 8;
    scriptEng.tempValue[1] = self->YPos;
    scriptEng.tempValue[1] -= stageLayouts[0].ZPos;
    scriptEng.tempValue[1] >>= 8;
    scriptEng.tempValue[2] = Sin512(stageLayouts[0].angle);
    scriptEng.tempValue[2] *= scriptEng.tempValue[1];
    scriptEng.tempValue[3] = Cos512(stageLayouts[0].angle);
    scriptEng.tempValue[3] *= scriptEng.tempValue[0];
    self->values[4] = scriptEng.tempValue[2];
    self->values[4] -= scriptEng.tempValue[3];
    self->values[4] >>= 9;
    scriptEng.tempValue[2] = Cos512(stageLayouts[0].angle);
    scriptEng.tempValue[2] *= scriptEng.tempValue[1];
    scriptEng.tempValue[3] = Sin512(stageLayouts[0].angle);
    scriptEng.tempValue[3] *= scriptEng.tempValue[0];
    self->values[5] = scriptEng.tempValue[2];
    self->values[5] += scriptEng.tempValue[3];
    self->values[5] >>= 9;
    if (pYPos() > 0x360000) {
        if (pYPos() < 0x7A0000) {
            if (self->values[5] < 0x58C8) {
                if (self->values[5] > 0x5094) {
                    if (self->values[4] > -0x2000) {
                        if (self->values[4] < 0x2000) {
                            scriptEng.tempValue[0] = self->values[4];
                            scriptEng.tempValue[0] *= 192;
                            scriptEng.tempValue[0] /= self->values[5];
                            scriptEng.tempValue[0] += SCREEN_CENTERX;
                            scriptEng.tempValue[0] <<= 16;
                            scriptEng.tempValue[1] = stageLayouts[0].YPos;
                            scriptEng.tempValue[1] >>= 8;
                            scriptEng.tempValue[1] -= 0x6000;
                            scriptEng.tempValue[1] *= 96;
                            scriptEng.tempValue[1] /= self->values[5];
                            scriptEng.tempValue[1] += 128;
                            scriptEng.tempValue[1] <<= 16;
                            PlaySfx(1, 0);
                            HapticEffect_Script(55, 0, 0, 0);
                            switch (self->propertyValue) {
                                case 0:
                                objectEntityList[4].values[0]--;
                                if (objectEntityList[4].values[4] == self->propertyValue) {
                                    objectEntityList[4].values[3] <<= 1;
                                } else {
                                    objectEntityList[4].values[3] += 20;
                                }
                                break;
                                case 1:
                                objectEntityList[4].values[0]--;
                                objectEntityList[4].values[5] = 600;
                                break;
                                case 2:
                                objectEntityList[4].values[1] += 30;
                                break;
                            }
                            objectEntityList[4].values[4] = self->propertyValue;
                            CreateTempObject(TypeNameID("UFO PowerUp"), self->propertyValue, scriptEng.tempValue[0], scriptEng.tempValue[1]);
                            objectEntityList[scriptEng.arrayPosition[2]].values[0] = rand() % 100;
                            objectEntityList[scriptEng.arrayPosition[2]].values[1] = scriptEng.tempValue[0];
                            objectEntityList[scriptEng.arrayPosition[2]].values[2] = scriptEng.tempValue[1];
                            objectEntityList[scriptEng.arrayPosition[2]].values[4] = -0x40000;
                            objectEntityList[scriptEng.arrayPosition[2]].values[5] = 0x58C8;
                            if (objectEntityList[4].values[0] == 0) {
                                objectEntityList[scriptEng.arrayPosition[2]].values[7] = 1;
                            }
                            ResetObjectEntity(objectLoop, TypeNameID("Blank Object"), 0, 0, 0);
                        }
                    }
                }
            }
        }
    }
}

void O_Special_UFO::ObjectDraw()
{
    Entity *self = Self();

    if (self->values[5] > 256) {
        self->scale = 0xC00000;
        self->scale /= self->values[5];
        scriptEng.tempValue[0] = 768;
        scriptEng.tempValue[0] -= self->scale;
        scriptEng.tempValue[0] /= 6;
        scriptEng.tempValue[1] = self->values[5];
        scriptEng.tempValue[1] >>= 12;
        if (scriptEng.tempValue[0] > 0) {
            self->scale += scriptEng.tempValue[0];
            self->scale -= scriptEng.tempValue[1];
        }
        scriptEng.tempValue[0] = self->values[4];
        scriptEng.tempValue[0] *= 192;
        scriptEng.tempValue[0] /= self->values[5];
        scriptEng.tempValue[0] += SCREEN_CENTERX;
        scriptEng.tempValue[1] = stageLayouts[0].YPos;
        scriptEng.tempValue[1] >>= 8;
        scriptEng.tempValue[1] -= 0x6000;
        scriptEng.tempValue[1] *= 96;
        scriptEng.tempValue[1] /= self->values[5];
        scriptEng.tempValue[1] += 128;
        DrawSpriteScreenFX_Script(self->propertyValue, FX_SCALE, scriptEng.tempValue[0], scriptEng.tempValue[1]);
        scriptEng.tempValue[1] = stageLayouts[0].YPos;
        scriptEng.tempValue[1] >>= 8;
        scriptEng.tempValue[1] *= 96;
        scriptEng.tempValue[1] /= self->values[5];
        scriptEng.tempValue[1] += 128;
        DrawSpriteScreenFX_Script(3, FX_SCALE, scriptEng.tempValue[0], scriptEng.tempValue[1]);
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R3_MetalSonic.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from MetalSonic.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R3_MetalSonic::ObjectStartup()
{
    LoadSpriteSheet("R3/Objects.gif");
    AddSpriteFrame(-24, -16, 48, 32, 67, 68);
    AddSpriteFrame(-24, -16, 48, 32, 116, 68);
    AddSpriteFrame(-16, -24, 32, 48, 1, 108);
    AddSpriteFrame(-24, -12, 24, 24, 214, 43);
    AddSpriteFrame(0, 0, 2, 2, 165, 68);
    AddSpriteFrame(-28, -16, 32, 32, 165, 68);
    AddSpriteFrame(0, 0, 2, 2, 165, 68);
}

void O_R3_MetalSonic::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        break;
        case 1:
        self->XPos -= 0x30000;
        self->frame++;
        self->frame &= 1;
        scriptEng.tempValue[0] = 0;
        scriptEng.arrayPosition[0] = objectLoop;
        scriptEng.arrayPosition[0]++;
        while (scriptEng.tempValue[0] < 3) {
            if (objectEntityList[scriptEng.arrayPosition[0]].type > TypeNameID("Blank Object")) {
                scriptEng.tempValue[1] = objectEntityList[scriptEng.arrayPosition[0]].XPos;
                scriptEng.tempValue[1] += 0x240000;
                if (self->XPos < scriptEng.tempValue[1]) {
                    objectEntityList[scriptEng.arrayPosition[0]].type = TypeNameID("Blank Object");
                    scriptEng.tempValue[2] = objectEntityList[scriptEng.arrayPosition[0]].propertyValue;
                    scriptEng.tempValue[2] <<= 2;
                    CreateTempObject(TypeNameID("Spike Debris"), scriptEng.tempValue[2], objectEntityList[scriptEng.arrayPosition[0]].XPos, objectEntityList[scriptEng.arrayPosition[0]].YPos);
                    objectEntityList[scriptEng.arrayPosition[2]].XPos = ((objectEntityList[scriptEng.arrayPosition[2]].XPos >> 16) - (9)) << 16;
                    objectEntityList[scriptEng.arrayPosition[2]].YPos = ((objectEntityList[scriptEng.arrayPosition[2]].YPos >> 16) - (9)) << 16;
                    objectEntityList[scriptEng.arrayPosition[2]].values[0] = -0x10000;
                    objectEntityList[scriptEng.arrayPosition[2]].values[1] = -0x30000;
                    scriptEng.tempValue[2]++;
                    CreateTempObject(TypeNameID("Spike Debris"), scriptEng.tempValue[2], objectEntityList[scriptEng.arrayPosition[0]].XPos, objectEntityList[scriptEng.arrayPosition[0]].YPos);
                    objectEntityList[scriptEng.arrayPosition[2]].XPos = ((objectEntityList[scriptEng.arrayPosition[2]].XPos >> 16) + (8)) << 16;
                    objectEntityList[scriptEng.arrayPosition[2]].YPos = ((objectEntityList[scriptEng.arrayPosition[2]].YPos >> 16) - (9)) << 16;
                    objectEntityList[scriptEng.arrayPosition[2]].values[0] = 0x10000;
                    objectEntityList[scriptEng.arrayPosition[2]].values[1] = -0x30000;
                    scriptEng.tempValue[2]++;
                    CreateTempObject(TypeNameID("Spike Debris"), scriptEng.tempValue[2], objectEntityList[scriptEng.arrayPosition[0]].XPos, objectEntityList[scriptEng.arrayPosition[0]].YPos);
                    objectEntityList[scriptEng.arrayPosition[2]].XPos = ((objectEntityList[scriptEng.arrayPosition[2]].XPos >> 16) - (9)) << 16;
                    objectEntityList[scriptEng.arrayPosition[2]].YPos = ((objectEntityList[scriptEng.arrayPosition[2]].YPos >> 16) + (8)) << 16;
                    objectEntityList[scriptEng.arrayPosition[2]].values[0] = -0x10000;
                    objectEntityList[scriptEng.arrayPosition[2]].values[1] = -0x18000;
                    scriptEng.tempValue[2]++;
                    CreateTempObject(TypeNameID("Spike Debris"), scriptEng.tempValue[2], objectEntityList[scriptEng.arrayPosition[0]].XPos, objectEntityList[scriptEng.arrayPosition[0]].YPos);
                    objectEntityList[scriptEng.arrayPosition[2]].XPos = ((objectEntityList[scriptEng.arrayPosition[2]].XPos >> 16) + (8)) << 16;
                    objectEntityList[scriptEng.arrayPosition[2]].YPos = ((objectEntityList[scriptEng.arrayPosition[2]].YPos >> 16) + (8)) << 16;
                    objectEntityList[scriptEng.arrayPosition[2]].values[0] = 0x10000;
                    objectEntityList[scriptEng.arrayPosition[2]].values[1] = -0x18000;
                    scriptEng.tempValue[2]++;
                    PlaySfx(globalSFXCount + 8, 0);
                    HapticEffect_Script(96, 0, 0, 0);
                }
            }
            scriptEng.arrayPosition[0]++;
            scriptEng.tempValue[0]++;
        }
        scriptEng.tempValue[0] = objectEntityList[objectLoop - 1].XPos;
        scriptEng.tempValue[0] += 0x200000;
        if (self->XPos < scriptEng.tempValue[0]) {
            self->state = 2;
            self->frame = 2;
            self->values[1] = self->YPos;
            objectEntityList[objectLoop - 1].frame = 8;
            objectEntityList[objectLoop - 1].state = 4;
            PlaySfx(globalSFXCount + 9, 0);
        }
        break;
        case 2:
        if (self->values[0] > 8) {
            if (pXPos() < self->XPos) {
                self->direction = 1;
            } else {
                self->direction = 0;
            }
        }
        self->YPos = Sin512(self->values[0]);
        self->YPos <<= 9;
        self->YPos += self->values[1];
        self->values[0] += 8;
        if (self->values[0] > 607) {
            self->state = 3;
            self->values[0] = 0;
        }
        break;
        case 3:
        if (pXPos() < self->XPos) {
            self->direction = 1;
        } else {
            self->direction = 0;
        }
        if (self->values[0] < 40) {
            self->values[0]++;
            self->values[1] -= 0x20000;
            self->YPos -= 0x20000;
        } else {
            self->state = 4;
            self->values[0] = 256;
        }
        break;
        case 4:
        if (pXPos() < self->XPos) {
            self->direction = 1;
        } else {
            self->direction = 0;
        }
        self->YPos = Sin512(self->values[0]);
        self->YPos <<= 9;
        self->YPos += self->values[1];
        self->values[0] += 8;
        if (self->values[0] > 976) {
            self->state = 5;
            self->direction = 0;
        }
        break;
        case 5:
        if (self->values[3] < 0x60000) {
            self->values[3] += 0x2000;
        }
        self->XPos += self->values[3];
        if (GetObjectOutOfBounds(objectLoop) == 1) {
            scriptEng.tempValue[0] = objectLoop;
            ResetObjectEntity(scriptEng.tempValue[0], TypeNameID("Blank Object"), 0, 0, 0);
            scriptEng.tempValue[0]--;
            ResetObjectEntity(scriptEng.tempValue[0], TypeNameID("Blank Object"), 0, 0, 0);
        }
        break;
    }
}

void O_R3_MetalSonic::ObjectDraw()
{
    Entity *self = Self();

    if (self->state < 2) {
        DrawSprite_Frame(self->frame);
    } else {
        objectEntityList[objectLoop - 1].XPos = self->XPos;
        objectEntityList[objectLoop - 1].YPos = self->YPos;
        objectEntityList[objectLoop - 1].direction = self->direction;
        scriptEng.tempValue[0] = self->values[4];
        scriptEng.tempValue[0] >>= 1;
        scriptEng.tempValue[0] += 3;
        DrawSpriteFX_Script(scriptEng.tempValue[0], FX_FLIP, self->XPos, self->YPos);
        self->values[4]++;
        self->values[4] &= 7;
        DrawSpriteFX_Script(self->frame, FX_FLIP, self->XPos, self->YPos);
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R8_TwinWalker.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from TwinWalker.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R8_TwinWalker::ObjectStartup()
{
    LoadSpriteSheet("R8/Objects2.gif");
    AddSpriteFrame(-24, -40, 48, 80, 51, 1);
    AddSpriteFrame(-4, -4, 8, 8, 19, 67);
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Twin Walker")) {
            objectEntityList[scriptEng.arrayPosition[0]].values[1] = objectEntityList[scriptEng.arrayPosition[0]].XPos;
            objectEntityList[scriptEng.arrayPosition[0]].XPos += 0x400000;
            objectEntityList[scriptEng.arrayPosition[0]].values[2] = objectEntityList[scriptEng.arrayPosition[0]].YPos;
            objectEntityList[scriptEng.arrayPosition[0]].values[5] = 256;
            objectEntityList[scriptEng.arrayPosition[0]].values[6] = objectEntityList[scriptEng.arrayPosition[0]].XPos;
            objectEntityList[scriptEng.arrayPosition[0]].values[7] = objectEntityList[scriptEng.arrayPosition[0]].YPos;
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_R8_TwinWalker::ObjectMain()
{
    Entity *self = Self();

    if (GetObjectOutOfBounds(objectLoop) == 1) {
        self->state = 2;
        self->XPos = self->values[6];
        self->YPos = self->values[7];
        self->values[1] = self->values[6];
        self->values[1] -= 0x400000;
        self->values[2] = self->values[7];
        self->values[5] = 256;
    }
    switch (self->state) {
        case 0:
        self->values[3] = Cos512(self->values[5]);
        self->values[3] *= 0x2000;
        self->values[3] += self->XPos;
        self->values[3] &= 0xFFFF0000;
        self->values[3] -= self->values[1];
        self->values[4] = Sin512(self->values[5]);
        self->values[4] *= 0x2000;
        self->values[4] += self->YPos;
        self->values[4] &= 0xFFFF0000;
        self->values[4] -= self->values[2];
        break;
        case 1:
        self->values[5] += 4;
        self->values[5] &= 511;
        self->values[3] = Cos512(self->values[5]);
        self->values[3] *= 0x2000;
        self->values[3] += self->XPos;
        self->values[3] &= 0xFFFF0000;
        self->values[4] = Sin512(self->values[5]);
        self->values[4] *= 0x2000;
        self->values[4] += self->YPos;
        self->values[4] &= 0xFFFF0000;
        scriptEng.tempValue[0] = self->XPos;
        scriptEng.tempValue[1] = self->YPos;
        self->XPos = self->values[3];
        self->YPos = self->values[4];
        ObjectTileCollision_Script(0, 0, 40, 0);
        if (CheckResult() == 1) {
            self->values[1] = scriptEng.tempValue[0];
            self->values[2] = scriptEng.tempValue[1];
            self->values[3] = 0;
            self->values[4] = 0;
            self->values[5] += 252;
            self->values[5] &= 511;
            scriptEng.tempValue[0] = Cos512(self->values[5]);
            scriptEng.tempValue[0] *= 0x2000;
            scriptEng.tempValue[0] += self->XPos;
            scriptEng.tempValue[0] &= 0xFFFF0000;
            scriptEng.tempValue[0] -= self->values[1];
            self->XPos -= scriptEng.tempValue[0];
            self->state = 0;
        } else {
            self->XPos = scriptEng.tempValue[0];
            self->YPos = scriptEng.tempValue[1];
            self->values[3] -= self->values[1];
            self->values[4] -= self->values[2];
        }
        break;
        case 2:
        if (GetObjectOutOfBounds(objectLoop) == 1) {
            self->state = 0;
            self->priority = 0;
        }
        break;
    }
}

void O_R8_TwinWalker::ObjectPlayerInteraction()
{
    Entity *self = Self();

    if (self->state < 2) {
        PlayerObjectCollision(C_PLATFORM, -24, -40, 24, -24);
        scriptEng.tempValue[0] = self->XPos;
        scriptEng.tempValue[1] = self->YPos;
        self->XPos = self->values[1];
        self->YPos = self->values[2];
        PlayerObjectCollision(C_PLATFORM, -24, -40, 24, -24);
        if (CheckResult() == 1) {
            pXPos() += self->values[3];
            pYPos() += self->values[4];
            scriptEng.tempValue[2] = self->values[1];
            scriptEng.tempValue[2] -= self->values[6];
            if (scriptEng.tempValue[2] < 0x2800000) {
                if (self->state == 0) {
                    self->state = 1;
                    self->priority = 1;
                }
            }
        }
        self->XPos = scriptEng.tempValue[0];
        self->YPos = scriptEng.tempValue[1];
    }
}

void O_R8_TwinWalker::ObjectDraw()
{
    Entity *self = Self();

    if (self->state < 2) {
        scriptEng.tempValue[1] = 64;
        self->values[1] = Cos512(self->values[5]);
        self->values[1] *= scriptEng.tempValue[1];
        self->values[1] <<= 7;
        self->values[1] += self->XPos;
        self->values[1] &= 0xFFFF0000;
        self->values[2] = Sin512(self->values[5]);
        self->values[2] *= scriptEng.tempValue[1];
        self->values[2] <<= 7;
        self->values[2] += self->YPos;
        self->values[2] &= 0xFFFF0000;
        DrawSprite_FrameXY(0, self->values[1], self->values[2]);
        DrawSprite_FrameXY(1, self->values[1], self->values[2]);
        DrawSprite_Frame(0);
        DrawSprite_Frame(1);
        scriptEng.tempValue[0] = 0;
        scriptEng.tempValue[1] = 8;
        while (scriptEng.tempValue[0] < 7) {
            scriptEng.tempValue[2] = Cos512(self->values[5]);
            scriptEng.tempValue[2] *= scriptEng.tempValue[1];
            scriptEng.tempValue[2] <<= 7;
            scriptEng.tempValue[2] += self->XPos;
            scriptEng.tempValue[2] &= 0xFFFF0000;
            scriptEng.tempValue[3] = Sin512(self->values[5]);
            scriptEng.tempValue[3] *= scriptEng.tempValue[1];
            scriptEng.tempValue[3] <<= 7;
            scriptEng.tempValue[3] += self->YPos;
            scriptEng.tempValue[3] &= 0xFFFF0000;
            DrawSprite_FrameXY(1, scriptEng.tempValue[2], scriptEng.tempValue[3]);
            scriptEng.tempValue[0]++;
            scriptEng.tempValue[1] += 8;
        }
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS

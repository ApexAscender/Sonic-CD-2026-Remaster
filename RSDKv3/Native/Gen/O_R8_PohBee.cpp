#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R8_PohBee.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from PohBee.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R8_PohBee::ObjectStartup()
{
    LoadSpriteSheet("R8/Objects.gif");
    AddSpriteFrame(-19, -20, 48, 36, 75, 140);
    AddSpriteFrame(-19, -20, 48, 36, 124, 140);
    AddSpriteFrame(-8, -8, 16, 16, 58, 114);
    AddSpriteFrame(-12, -12, 24, 24, 230, 67);
    AddSpriteFrame(-12, -12, 24, 24, 75, 114);
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Poh Bee")) {
            objectEntityList[scriptEng.arrayPosition[0]].values[1] = objectEntityList[scriptEng.arrayPosition[0]].XPos;
            objectEntityList[scriptEng.arrayPosition[0]].values[2] = objectEntityList[scriptEng.arrayPosition[0]].YPos;
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_R8_PohBee::ObjectMain()
{
    Entity *self = Self();

    if (GetObjectOutOfBounds(objectLoop) == 1) {
        self->XPos = self->values[1];
        self->values[0] = 0;
        self->state = 0;
    }
    self->rotation += 9;
    self->rotation &= 2047;
    if (self->propertyValue == 0) {
        self->values[6] += 10;
        self->values[6] &= 2047;
        switch (self->state) {
            case 0:
            self->direction = 1;
            if (self->values[0] < 128) {
                self->values[0]++;
                self->XPos += 0x10000;
            } else {
                self->state = 1;
                self->values[0] = 0;
            }
            break;
            case 1:
            self->direction = 0;
            if (self->values[0] < 128) {
                self->values[0]++;
                self->XPos -= 0x10000;
            } else {
                self->state = 0;
                self->values[0] = 0;
            }
            break;
        }
        self->values[3] += 8;
        self->values[3] &= 511;
        self->YPos = Sin512(self->values[3]);
        self->YPos <<= 12;
        self->YPos += self->values[2];
        scriptEng.tempValue[0] = self->rotation;
        scriptEng.tempValue[0] >>= 2;
        self->values[4] = Sin512(scriptEng.tempValue[0]);
        self->values[4] >>= 2;
        self->values[4] += 136;
        self->values[4] *= 120;
        self->values[4] >>= 7;
        scriptEng.tempValue[0] = self->values[6];
        scriptEng.tempValue[0] >>= 2;
        self->values[5] = Sin512(scriptEng.tempValue[0]);
        self->values[5] >>= 2;
        self->values[5] += 144;
        self->values[5] *= 112;
        self->values[5] >>= 7;
    } else {
        switch (self->state) {
            case 0:
            self->direction = 1;
            if (self->values[0] < 256) {
                self->values[0]++;
                self->XPos += 0x8000;
            } else {
                self->state = 1;
                self->values[0] = 0;
            }
            break;
            case 1:
            self->direction = 0;
            if (self->values[0] < 256) {
                self->values[0]++;
                self->XPos -= 0x8000;
            } else {
                self->state = 0;
                self->values[0] = 0;
            }
            break;
        }
        self->values[3] += 6;
        self->values[3] &= 511;
        self->YPos = Sin512(self->values[3]);
        self->YPos <<= 11;
        self->YPos += self->values[2];
        scriptEng.tempValue[0] = self->rotation;
        scriptEng.tempValue[0] >>= 2;
        self->values[4] = Sin512(scriptEng.tempValue[0]);
        self->values[4] >>= 2;
        self->values[4] += 136;
        self->values[4] *= 120;
        self->values[4] >>= 7;
    }
    self->values[7] = self->YPos;
    self->values[7] += 0xD0000;
    CallScriptFunctionNamed("StageSetup_CheckGoodFuture", scriptSub);
}

void O_R8_PohBee::ObjectPlayerInteraction()
{
    Entity *self = Self();

    PlayerObjectCollision(C_TOUCH, -20, -16, 20, 14);
    if (CheckResult() == 1) {
        CallScriptFunctionNamed("Player_BadnikBreak", scriptSub);
    }
    scriptEng.tempValue[0] = self->XPos;
    scriptEng.tempValue[1] = self->YPos;
    self->XPos = Cos512(self->values[4]);
    self->XPos *= 0x2A00;
    self->XPos += scriptEng.tempValue[0];
    self->YPos = Sin512(self->values[4]);
    self->YPos *= 0x2A00;
    self->YPos += self->values[7];
    PlayerObjectCollision(C_TOUCH, -9, -9, 9, 9);
    if (CheckResult() == 1) {
        CallScriptFunctionNamed("Player_Hit", scriptSub);
    }
    if (self->propertyValue == 0) {
        self->XPos = Cos512(self->values[5]);
        self->XPos *= 0x1200;
        self->XPos += scriptEng.tempValue[0];
        self->YPos = Sin512(self->values[5]);
        self->YPos *= 0x1200;
        self->YPos += self->values[7];
        PlayerObjectCollision(C_TOUCH, -9, -9, 9, 9);
        if (CheckResult() == 1) {
            CallScriptFunctionNamed("Player_Hit", scriptSub);
        }
    }
    self->XPos = scriptEng.tempValue[0];
    self->YPos = scriptEng.tempValue[1];
}

void O_R8_PohBee::ObjectDraw()
{
    Entity *self = Self();

    if (self->propertyValue == 0) {
        scriptEng.tempValue[0] = 0;
        scriptEng.tempValue[1] = 4;
        while (scriptEng.tempValue[0] < 10) {
            scriptEng.tempValue[2] = Cos512(self->values[4]);
            scriptEng.tempValue[2] *= scriptEng.tempValue[1];
            scriptEng.tempValue[2] <<= 7;
            scriptEng.tempValue[2] += self->XPos;
            scriptEng.tempValue[3] = Sin512(self->values[4]);
            scriptEng.tempValue[3] *= scriptEng.tempValue[1];
            scriptEng.tempValue[3] <<= 7;
            scriptEng.tempValue[3] += self->values[7];
            DrawSprite_FrameXY(2, scriptEng.tempValue[2], scriptEng.tempValue[3]);
            scriptEng.tempValue[0]++;
            scriptEng.tempValue[1] += 8;
        }
        scriptEng.tempValue[2] = Cos512(self->values[4]);
        scriptEng.tempValue[2] *= scriptEng.tempValue[1];
        scriptEng.tempValue[2] <<= 7;
        scriptEng.tempValue[2] += self->XPos;
        scriptEng.tempValue[3] = Sin512(self->values[4]);
        scriptEng.tempValue[3] *= scriptEng.tempValue[1];
        scriptEng.tempValue[3] <<= 7;
        scriptEng.tempValue[3] += self->values[7];
        DrawSprite_FrameXY(3, scriptEng.tempValue[2], scriptEng.tempValue[3]);
        scriptEng.tempValue[0] = 0;
        scriptEng.tempValue[1] = 4;
        while (scriptEng.tempValue[0] < 4) {
            scriptEng.tempValue[2] = Cos512(self->values[5]);
            scriptEng.tempValue[2] *= scriptEng.tempValue[1];
            scriptEng.tempValue[2] <<= 7;
            scriptEng.tempValue[2] += self->XPos;
            scriptEng.tempValue[3] = Sin512(self->values[5]);
            scriptEng.tempValue[3] *= scriptEng.tempValue[1];
            scriptEng.tempValue[3] <<= 7;
            scriptEng.tempValue[3] += self->values[7];
            DrawSprite_FrameXY(2, scriptEng.tempValue[2], scriptEng.tempValue[3]);
            scriptEng.tempValue[0]++;
            scriptEng.tempValue[1] += 8;
        }
        scriptEng.tempValue[2] = Cos512(self->values[5]);
        scriptEng.tempValue[2] *= scriptEng.tempValue[1];
        scriptEng.tempValue[2] <<= 7;
        scriptEng.tempValue[2] += self->XPos;
        scriptEng.tempValue[3] = Sin512(self->values[5]);
        scriptEng.tempValue[3] *= scriptEng.tempValue[1];
        scriptEng.tempValue[3] <<= 7;
        scriptEng.tempValue[3] += self->values[7];
        DrawSprite_FrameXY(3, scriptEng.tempValue[2], scriptEng.tempValue[3]);
    } else {
        scriptEng.tempValue[0] = 0;
        scriptEng.tempValue[1] = 4;
        while (scriptEng.tempValue[0] < 10) {
            scriptEng.tempValue[2] = Cos512(self->values[4]);
            scriptEng.tempValue[2] *= scriptEng.tempValue[1];
            scriptEng.tempValue[2] <<= 7;
            scriptEng.tempValue[2] += self->XPos;
            scriptEng.tempValue[3] = Sin512(self->values[4]);
            scriptEng.tempValue[3] *= scriptEng.tempValue[1];
            scriptEng.tempValue[3] <<= 7;
            scriptEng.tempValue[3] += self->values[7];
            DrawSprite_FrameXY(2, scriptEng.tempValue[2], scriptEng.tempValue[3]);
            scriptEng.tempValue[0]++;
            scriptEng.tempValue[1] += 8;
        }
        scriptEng.tempValue[2] = Cos512(self->values[4]);
        scriptEng.tempValue[2] *= scriptEng.tempValue[1];
        scriptEng.tempValue[2] <<= 7;
        scriptEng.tempValue[2] += self->XPos;
        scriptEng.tempValue[3] = Sin512(self->values[4]);
        scriptEng.tempValue[3] *= scriptEng.tempValue[1];
        scriptEng.tempValue[3] <<= 7;
        scriptEng.tempValue[3] += self->values[7];
        DrawSprite_FrameXY(4, scriptEng.tempValue[2], scriptEng.tempValue[3]);
    }
    self->animationTimer++;
    self->animationTimer &= 3;
    self->frame = self->animationTimer;
    self->frame >>= 1;
    DrawSpriteFX_Script(self->frame, FX_FLIP, self->XPos, self->YPos);
}

#endif // RETRO_USE_NATIVE_OBJECTS

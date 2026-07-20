#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R7_Kabasira.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from Kabasira.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R7_Kabasira::ObjectStartup()
{
    LoadSpriteSheet("R7/Objects.gif");
    AddSpriteFrame(-8, -8, 16, 16, 133, 100);
    AddSpriteFrame(-8, -8, 16, 16, 150, 100);
    AddSpriteFrame(-8, -8, 16, 16, 167, 100);
    AddSpriteFrame(-8, -8, 16, 16, 184, 100);
    AddSpriteFrame(-8, -8, 16, 16, 99, 100);
    AddSpriteFrame(-8, -8, 16, 16, 116, 100);
    AddSpriteFrame(-8, -6, 8, 8, 243, 101);
    AddSpriteFrame(-8, -6, 8, 8, 243, 110);
    AddSpriteFrame(-12, -6, 24, 8, 218, 101);
    AddSpriteFrame(-12, -6, 24, 8, 218, 110);
    AddSpriteFrame(-8, -6, 16, 8, 218, 92);
    AddSpriteFrame(-8, -6, 16, 8, 235, 92);
    AddSpriteFrame(0, -6, 8, 8, 240, 74);
    AddSpriteFrame(0, -6, 8, 8, 240, 83);
    AddSpriteFrame(-8, -6, 16, 8, 218, 92);
    AddSpriteFrame(-8, -6, 16, 8, 235, 92);
    AddSpriteFrame(-12, -6, 24, 8, 218, 101);
    AddSpriteFrame(-12, -6, 24, 8, 218, 110);
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Kabasira")) {
            objectEntityList[scriptEng.arrayPosition[0]].values[2] = objectEntityList[scriptEng.arrayPosition[0]].XPos;
            objectEntityList[scriptEng.arrayPosition[0]].values[3] = objectEntityList[scriptEng.arrayPosition[0]].YPos;
            objectEntityList[scriptEng.arrayPosition[0]].inkEffect = 2;
            objectEntityList[scriptEng.arrayPosition[0]].values[0] = 120;
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_R7_Kabasira::ObjectMain()
{
    Entity *self = Self();

    if (GetObjectOutOfBounds(objectLoop) == 1) {
        self->state = 2;
        self->values[0] = 0;
        self->values[1] = 256;
        self->direction = 0;
        self->XPos = self->values[2];
        self->YPos = self->values[3];
    }
    if (self->propertyValue == 0) {
        self->values[1] += 2;
        self->values[1] &= 511;
        self->frame = self->animationTimer;
        self->frame >>= 3;
        self->animationTimer++;
        self->animationTimer &= 15;
        if (self->values[0] == 0) {
            self->values[0] = 240;
            PlaySfx(globalSFXCount + 2, 0);
            if (pXPos() > self->XPos) {
                CreateTempObject(TypeNameID("Kabasira Shot"), 0, self->XPos, self->YPos);
            } else {
                CreateTempObject(TypeNameID("Kabasira Shot"), 1, self->XPos, self->YPos);
            }
            objectEntityList[scriptEng.arrayPosition[2]].inkEffect = 2;
            objectEntityList[scriptEng.arrayPosition[2]].alpha = 192;
            scriptEng.tempValue[0] = pXPos();
            scriptEng.tempValue[0] -= self->XPos;
            scriptEng.tempValue[1] = pYPos();
            scriptEng.tempValue[1] -= self->YPos;
            scriptEng.tempValue[2] = ArcTanLookup(scriptEng.tempValue[0], scriptEng.tempValue[1]);
            objectEntityList[scriptEng.arrayPosition[2]].values[1] = Cos256(scriptEng.tempValue[2]);
            objectEntityList[scriptEng.arrayPosition[2]].values[2] = Sin256(scriptEng.tempValue[2]);
            objectEntityList[scriptEng.arrayPosition[2]].values[1] <<= 9;
            objectEntityList[scriptEng.arrayPosition[2]].values[2] <<= 9;
        } else {
            self->values[0]--;
        }
    } else {
        self->values[1]++;
        self->values[1] &= 511;
        self->frame = self->animationTimer;
        self->frame >>= 4;
        self->animationTimer++;
        self->animationTimer &= 31;
    }
    self->YPos = Cos512(self->values[1]);
    self->YPos <<= 13;
    self->YPos += self->values[3];
    scriptEng.tempValue[0] = self->values[1];
    scriptEng.tempValue[0] <<= 1;
    self->XPos = Sin512(scriptEng.tempValue[0]);
    self->XPos *= 0xA00;
    self->XPos += self->values[2];
    CallScriptFunctionNamed("StageSetup_CheckGoodFuture", scriptSub);
}

void O_R7_Kabasira::ObjectPlayerInteraction()
{
    PlayerObjectCollision(C_TOUCH, -6, -6, 6, 6);
    if (CheckResult() == 1) {
        CallScriptFunctionNamed("Player_BadnikBreak", scriptSub);
    }
}

void O_R7_Kabasira::ObjectDraw()
{
    Entity *self = Self();

    if (self->state < 2) {
        scriptEng.tempValue[0] = 0;
        scriptEng.tempValue[1] = 488;
        scriptEng.tempValue[3] = self->values[1];
        scriptEng.tempValue[3] += 464;
        scriptEng.tempValue[3] &= 511;
        self->alpha = 64;
        while (scriptEng.tempValue[0] < 4) {
            scriptEng.tempValue[2] = self->values[1];
            scriptEng.tempValue[2] += scriptEng.tempValue[1];
            scriptEng.tempValue[2] &= 511;
            scriptEng.tempValue[2] /= 42;
            scriptEng.tempValue[2] %= 12;
            self->values[5] = Cos512(scriptEng.tempValue[3]);
            self->values[5] <<= 13;
            self->values[5] += self->values[3];
            scriptEng.tempValue[4] = scriptEng.tempValue[3];
            scriptEng.tempValue[4] <<= 1;
            self->values[4] = Sin512(scriptEng.tempValue[4]);
            self->values[4] *= 0xA00;
            self->values[4] += self->values[2];
            switch (scriptEng.tempValue[2]) {
                case 0:
                case 6:
                DrawSpriteFX_Script(scriptEng.tempValue[2], FX_INK, self->values[4], self->values[5]);
                DrawSpriteFX_Script(0, FX_INK, self->values[4], self->values[5]);
                scriptEng.tempValue[2] = 6;
                scriptEng.tempValue[2] += self->frame;
                break;
                case 1:
                case 7:
                DrawSpriteFX_Script(scriptEng.tempValue[2], FX_INK, self->values[4], self->values[5]);
                DrawSpriteFX_Script(1, FX_INK, self->values[4], self->values[5]);
                scriptEng.tempValue[2] = 8;
                scriptEng.tempValue[2] += self->frame;
                break;
                case 2:
                case 8:
                DrawSpriteFX_Script(scriptEng.tempValue[2], FX_INK, self->values[4], self->values[5]);
                DrawSpriteFX_Script(2, FX_INK, self->values[4], self->values[5]);
                scriptEng.tempValue[2] = 10;
                scriptEng.tempValue[2] += self->frame;
                break;
                case 3:
                case 9:
                DrawSpriteFX_Script(3, FX_INK, self->values[4], self->values[5]);
                scriptEng.tempValue[2] = 12;
                scriptEng.tempValue[2] += self->frame;
                DrawSpriteFX_Script(scriptEng.tempValue[2], FX_INK, self->values[4], self->values[5]);
                break;
                case 4:
                case 10:
                scriptEng.tempValue[2] = 14;
                scriptEng.tempValue[2] += self->frame;
                DrawSpriteFX_Script(scriptEng.tempValue[2], FX_INK, self->values[4], self->values[5]);
                DrawSpriteFX_Script(4, FX_INK, self->values[4], self->values[5]);
                break;
                case 5:
                case 11:
                scriptEng.tempValue[2] = 16;
                scriptEng.tempValue[2] += self->frame;
                DrawSpriteFX_Script(scriptEng.tempValue[2], FX_INK, self->values[4], self->values[5]);
                DrawSpriteFX_Script(5, FX_INK, self->values[4], self->values[5]);
                break;
            }
            scriptEng.tempValue[0]++;
            scriptEng.tempValue[1] += 8;
            scriptEng.tempValue[3] += 12;
            scriptEng.tempValue[3] &= 511;
            self->alpha += 32;
        }
        scriptEng.tempValue[0] = self->values[1];
        scriptEng.tempValue[0] += 8;
        scriptEng.tempValue[0] &= 511;
        scriptEng.tempValue[0] /= 42;
        scriptEng.tempValue[0] %= 12;
        switch (scriptEng.tempValue[0]) {
            case 0:
            case 6:
            DrawSprite_FrameXY(0, self->values[4], self->values[5]);
            scriptEng.tempValue[2] = 6;
            scriptEng.tempValue[2] += self->frame;
            DrawSprite_FrameXY(scriptEng.tempValue[2], self->values[4], self->values[5]);
            break;
            case 1:
            case 7:
            DrawSprite_FrameXY(1, self->values[4], self->values[5]);
            scriptEng.tempValue[2] = 8;
            scriptEng.tempValue[2] += self->frame;
            DrawSprite_FrameXY(scriptEng.tempValue[2], self->values[4], self->values[5]);
            break;
            case 2:
            case 8:
            DrawSprite_FrameXY(2, self->values[4], self->values[5]);
            scriptEng.tempValue[2] = 10;
            scriptEng.tempValue[2] += self->frame;
            DrawSprite_FrameXY(scriptEng.tempValue[2], self->values[4], self->values[5]);
            break;
            case 3:
            case 9:
            DrawSprite_FrameXY(3, self->values[4], self->values[5]);
            scriptEng.tempValue[2] = 12;
            scriptEng.tempValue[2] += self->frame;
            DrawSprite_FrameXY(scriptEng.tempValue[2], self->values[4], self->values[5]);
            break;
            case 4:
            case 10:
            scriptEng.tempValue[2] = 14;
            scriptEng.tempValue[2] += self->frame;
            DrawSprite_FrameXY(scriptEng.tempValue[2], self->values[4], self->values[5]);
            DrawSprite_FrameXY(4, self->values[4], self->values[5]);
            break;
            case 5:
            case 11:
            scriptEng.tempValue[2] = 16;
            scriptEng.tempValue[2] += self->frame;
            DrawSprite_FrameXY(scriptEng.tempValue[2], self->values[4], self->values[5]);
            DrawSprite_FrameXY(5, self->values[4], self->values[5]);
            break;
        }
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS

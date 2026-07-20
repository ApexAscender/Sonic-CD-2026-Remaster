#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_FlowerPod_R5_FlowerPod.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from R5_FlowerPod.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_FlowerPod_R5_FlowerPod::ObjectStartup()
{
    LoadSpriteSheet("R5/Objects3.gif");
    AddSpriteFrame(-32, 6, 64, 42, 1, 55);
    AddSpriteFrame(-32, -48, 64, 54, 1, 1);
    AddSpriteFrame(-32, -48, 64, 54, 1, 98);
    AddSpriteFrame(-32, -10, 64, 16, 1, 153);
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Flower Pod")) {
            scriptEng.tempValue[0] = SCREEN_CENTERX;
            scriptEng.tempValue[0] -= 160;
            scriptEng.tempValue[0] <<= 16;
            objectEntityList[scriptEng.arrayPosition[0]].XPos -= scriptEng.tempValue[0];
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_FlowerPod_R5_FlowerPod::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        scriptEng.tempValue[0] = self->YPos;
        scriptEng.tempValue[0] += 0x40005A;
        if (pYPos() < scriptEng.tempValue[0]) {
            newXBoundary1 = self->XPos;
            newXBoundary1 >>= 16;
            newXBoundary1 -= SCREEN_CENTERX;
            newXBoundary2 = self->XPos;
            newXBoundary2 >>= 16;
            newXBoundary2 += SCREEN_CENTERX;
        }
        if (self->values[0] < 60) {
            self->frame = 1;
        } else {
            scriptEng.tempValue[0] = self->values[0];
            scriptEng.tempValue[0] -= 60;
            scriptEng.tempValue[0] >>= 1;
            switch (scriptEng.tempValue[0]) {
                case 0:
                self->frame = 2;
                break;
                case 1:
                case 2:
                self->frame = 1;
                break;
                case 3:
                self->frame = 2;
                break;
                case 4:
                case 5:
                self->frame = 1;
                break;
                case 6:
                self->frame = 2;
                break;
            }
        }
        self->values[0]++;
        if (self->values[0] == 74) {
            self->values[0] = 0;
        }
        break;
        case 1:
        if (self->values[0] < 120) {
            self->values[0]++;
            scriptEng.tempValue[0] = self->values[0];
            scriptEng.tempValue[0] &= 3;
            if (scriptEng.tempValue[0] == 3) {
                scriptEng.tempValue[0] = rand() % 64;
                scriptEng.tempValue[0] -= 32;
                scriptEng.tempValue[0] <<= 16;
                scriptEng.tempValue[0] += self->XPos;
                scriptEng.tempValue[1] = rand() % 40;
                scriptEng.tempValue[1] -= 40;
                scriptEng.tempValue[1] <<= 16;
                scriptEng.tempValue[1] += self->YPos;
                CreateTempObject(TypeNameID("Explosion"), 0, scriptEng.tempValue[0], scriptEng.tempValue[1]);
                PlaySfx(22, 0);
            }
        } else {
            self->state = 2;
            self->values[0] = 256;
            self->inkEffect = 2;
            self->alpha = 255;
            scriptEng.tempValue[0] = self->XPos;
            scriptEng.tempValue[0] -= 0x30000;
            scriptEng.tempValue[1] = self->YPos;
            scriptEng.tempValue[1] -= 0x180000;
            CreateTempObject(TypeNameID("Pod Seed"), 1, scriptEng.tempValue[0], scriptEng.tempValue[1]);
            objectEntityList[scriptEng.arrayPosition[2]].values[2] = -0x20000;
            objectEntityList[scriptEng.arrayPosition[2]].values[3] = -0x60000;
            objectEntityList[scriptEng.arrayPosition[2]].values[1] = objectLoop;
            scriptEng.tempValue[0] += 0x10000;
            CreateTempObject(TypeNameID("Pod Seed"), 0, scriptEng.tempValue[0], scriptEng.tempValue[1]);
            objectEntityList[scriptEng.arrayPosition[2]].values[2] = -0x15554;
            objectEntityList[scriptEng.arrayPosition[2]].values[3] = -0x60000;
            scriptEng.tempValue[0] += 0x10000;
            CreateTempObject(TypeNameID("Pod Seed"), 0, scriptEng.tempValue[0], scriptEng.tempValue[1]);
            objectEntityList[scriptEng.arrayPosition[2]].values[2] = -0xAAAA;
            objectEntityList[scriptEng.arrayPosition[2]].values[3] = -0x60000;
            scriptEng.tempValue[0] += 0x10000;
            CreateTempObject(TypeNameID("Pod Seed"), 0, scriptEng.tempValue[0], scriptEng.tempValue[1]);
            objectEntityList[scriptEng.arrayPosition[2]].values[2] = 0;
            objectEntityList[scriptEng.arrayPosition[2]].values[3] = -0x60000;
            scriptEng.tempValue[0] += 0x10000;
            CreateTempObject(TypeNameID("Pod Seed"), 0, scriptEng.tempValue[0], scriptEng.tempValue[1]);
            objectEntityList[scriptEng.arrayPosition[2]].values[2] = 0xAAAA;
            objectEntityList[scriptEng.arrayPosition[2]].values[3] = -0x60000;
            scriptEng.tempValue[0] += 0x10000;
            CreateTempObject(TypeNameID("Pod Seed"), 0, scriptEng.tempValue[0], scriptEng.tempValue[1]);
            objectEntityList[scriptEng.arrayPosition[2]].values[2] = 0x15554;
            objectEntityList[scriptEng.arrayPosition[2]].values[3] = -0x60000;
            scriptEng.tempValue[0] += 0x10000;
            CreateTempObject(TypeNameID("Pod Seed"), 0, scriptEng.tempValue[0], scriptEng.tempValue[1]);
            objectEntityList[scriptEng.arrayPosition[2]].values[2] = 0x20000;
            objectEntityList[scriptEng.arrayPosition[2]].values[3] = -0x60000;
        }
        break;
        case 2:
        if (self->values[0] > 0) {
            self->values[0] -= 16;
            self->alpha = self->values[0];
        }
        break;
        case 3:
        if (pControlMode() == -1) {
            pLeft() = 0;
            pRight() = 1;
            pUp() = 0;
            pDown() = 0;
            pJumpHold() = 0;
        }
        scriptEng.tempValue[0] = self->XPos;
        scriptEng.tempValue[0] += 0xA00000;
        if (pXPos() > scriptEng.tempValue[0]) {
            PlayMusic(1);
            self->state = 4;
            objectEntityList[30].type = TypeNameID("ActFinish");
            objectEntityList[30].drawOrder = 6;
            objectEntityList[30].priority = 1;
        }
        break;
        case 4:
        if (pControlMode() == -1) {
            pRight() = 1;
        }
        break;
    }
}

void O_FlowerPod_R5_FlowerPod::ObjectPlayerInteraction()
{
    Entity *self = Self();

    if (self->state == 0) {
        CheckResult() = 0;
        if (pAnimation() == GVar("ANI_JUMPING")) {
            CheckResult() = 1;
        }
        if (CheckResult() == 1) {
            PlayerObjectCollision(C_TOUCH, -28, -46, 28, 6);
            if (CheckResult() == 1) {
                timeEnabled = 0;
                self->state = 1;
                self->frame = 3;
                self->values[0] = 0;
                pYVel() >>= 1;
                pYVel() = -pYVel();
                HapticEffect_Script(55, 0, 0, 0);
            }
        }
    }
    scriptEng.tempValue[0] = SCREEN_CENTERX;
    scriptEng.tempValue[0] += 40;
    scriptEng.tempValue[0] <<= 16;
    scriptEng.tempValue[1] = self->XPos;
    scriptEng.tempValue[1] += scriptEng.tempValue[0];
    if (pXPos() > scriptEng.tempValue[1]) {
        pXPos() = scriptEng.tempValue[1];
        pSpeed() = 0;
        pXVel() = 0;
        if (pGravity() == 0) {
            pYVel() = 0;
        }
    }
}

void O_FlowerPod_R5_FlowerPod::ObjectDraw()
{
    Entity *self = Self();

    if (self->state < 2) {
        DrawSprite_Frame(0);
        DrawSprite_Frame(self->frame);
    } else {
        DrawSpriteFX_Script(0, FX_INK, self->XPos, self->YPos);
        DrawSpriteFX_Script(self->frame, FX_INK, self->XPos, self->YPos);
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS

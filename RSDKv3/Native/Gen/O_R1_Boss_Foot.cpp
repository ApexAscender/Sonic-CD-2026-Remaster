#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R1_Boss_Foot.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from Boss_Foot.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R1_Boss_Foot::ObjectStartup()
{
    LoadSpriteSheet("R1/Objects3.gif");
    AddSpriteFrame(-32, -20, 58, 40, 1, 66);
}

void O_R1_Boss_Foot::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        self->values[2] = 0x4000;
        self->values[5] = 0x8000;
        self->values[6] = -0x80000;
        self->values[7] = 0x100000;
        self->values[4] = (1) ? (self->values[4] | (1 << 0)) : (self->values[4] & ~(1 << 0));
        BossFoot_HandleMovement();
        self->state = 2;
        break;
        case 1:
        self->values[6] -= self->values[2];
        self->values[7] += self->values[5];
        scriptEng.tempValue[1] = 1;
        scriptEng.tempValue[0] = ((self->values[4] >> 4) & 1);
        CheckResult() = scriptEng.tempValue[0];
        scriptEng.tempValue[0] = ((self->values[4] >> 7) & 1);
        CheckResult() &= scriptEng.tempValue[0];
        if (CheckResult() == 1) {
            if (self->values[7] >= 0xC0000) {
                self->values[4] = (1) ? (self->values[4] | (1 << 0)) : (self->values[4] & ~(1 << 0));
                self->state = 2;
                scriptEng.tempValue[1] = 0;
            }
        } else {
            if (self->values[7] >= 0x100000) {
                self->values[4] = (1) ? (self->values[4] | (1 << 0)) : (self->values[4] & ~(1 << 0));
                self->state = 2;
                scriptEng.tempValue[1] = 0;
            }
        }
        if (scriptEng.tempValue[1] == 1) {
            BossFoot_SaveFootPosition();
            ObjectTileCollision_Script(0, 0, 20, 0);
            if (CheckResult() == 1) {
                BossFoot_StepEarthQuake();
            }
        }
        break;
        case 2:
        scriptEng.tempValue[0] = ((self->values[4] >> 4) & 1);
        if (scriptEng.tempValue[0] == 0) {
            BossFoot_HandleMovement();
            ObjectTileCollision_Script(0, 0, 20, 0);
            if (CheckResult() == 1) {
                BossFoot_StepEarthQuake();
            }
        }
        break;
        case 3:
        self->values[6] += self->values[2];
        self->values[7] -= self->values[5];
        if (self->values[7] <= 0) {
            self->values[6] = 0;
            self->values[7] = 0;
            self->values[4] = (1) ? (self->values[4] | (1 << 0)) : (self->values[4] & ~(1 << 0));
            self->state = 4;
        }
        BossFoot_SaveFootPosition();
        break;
        case 4:
        BossFoot_HandleMovement();
        break;
        case 5:
        scriptEng.arrayPosition[0] = self->values[1];
        scriptEng.arrayPosition[1] = objectEntityList[scriptEng.arrayPosition[0]].values[1];
        scriptEng.arrayPosition[0] = objectEntityList[scriptEng.arrayPosition[1]].values[1];
        scriptEng.arrayPosition[1] = objectEntityList[scriptEng.arrayPosition[0]].values[1];
        self->XPos = objectEntityList[scriptEng.arrayPosition[1]].XPos;
        self->XPos -= 0xA0000;
        self->YPos = objectEntityList[scriptEng.arrayPosition[1]].YPos;
        break;
        case 6:
        scriptEng.tempValue[0] = ((self->values[4] >> 4) & 1);
        if (scriptEng.tempValue[0] == 0) {
            self->values[2] -= 0x660;
        } else {
            self->values[2] += 0x660;
        }
        self->XPos += self->values[2];
        self->values[5] += 0x1660;
        self->YPos += self->values[5];
        if (GetObjectOutOfBounds(objectLoop) == 1) {
            self->type = TypeNameID("Blank Object");
            self->priority = 0;
        }
        break;
    }
}

void O_R1_Boss_Foot::ObjectPlayerInteraction()
{
    Entity *self = Self();

    if (self->state < 6) {
        if (PlayerValue(4) == 0) {
            PlayerObjectCollision(C_TOUCH, -28, -20, 26, 20);
            if (CheckResult() == 1) {
                scriptEng.arrayPosition[0] = self->values[0];
                scriptEng.arrayPosition[1] = objectEntityList[scriptEng.arrayPosition[0]].values[0];
                scriptEng.arrayPosition[0] = objectEntityList[scriptEng.arrayPosition[1]].values[0];
                scriptEng.arrayPosition[1] = objectEntityList[scriptEng.arrayPosition[0]].values[0];
                objectEntityList[scriptEng.arrayPosition[1]].animation = 1;
                objectEntityList[scriptEng.arrayPosition[1]].direction = 180;
                pState() = PlayerStateID("Player_State_GotHit");
                if (pXPos() > self->XPos) {
                    pSpeed() = 0x20000;
                } else {
                    pSpeed() = -0x20000;
                }
            }
        }
    }
}

void O_R1_Boss_Foot::ObjectDraw()
{
    DrawSprite_Frame(0);
}

void O_R1_Boss_Foot::BossFoot_HandleMovement()
{
    Entity *self = Self();

    scriptEng.arrayPosition[0] = self->values[0];
    self->XPos = objectEntityList[scriptEng.arrayPosition[0]].XPos;
    self->XPos -= 0xB0000;
    self->XPos += self->values[6];
    self->YPos = objectEntityList[scriptEng.arrayPosition[0]].YPos;
    self->YPos += 0xE0000;
    self->YPos += self->values[7];
}

void O_R1_Boss_Foot::BossFoot_StepEarthQuake()
{
    Entity *self = Self();

    self->values[4] = (1) ? (self->values[4] | (1 << 4)) : (self->values[4] & ~(1 << 4));
    scriptEng.arrayPosition[0] = self->values[0];
    objectEntityList[scriptEng.arrayPosition[0]].values[4] = (1) ? (objectEntityList[scriptEng.arrayPosition[0]].values[4] | (1 << 4)) : (objectEntityList[scriptEng.arrayPosition[0]].values[4] & ~(1 << 4));
    scriptEng.arrayPosition[1] = objectEntityList[scriptEng.arrayPosition[0]].values[0];
    objectEntityList[scriptEng.arrayPosition[1]].values[4] = (1) ? (objectEntityList[scriptEng.arrayPosition[1]].values[4] | (1 << 4)) : (objectEntityList[scriptEng.arrayPosition[1]].values[4] & ~(1 << 4));
    cameraShakeY = 4;
    scriptEng.arrayPosition[0] = self->values[1];
    scriptEng.arrayPosition[0]++;
    if (objectEntityList[scriptEng.arrayPosition[0]].values[5] > 2) {
        scriptEng.arrayPosition[0]--;
        objectEntityList[scriptEng.arrayPosition[0]].YPos -= 0x18000;
        scriptEng.arrayPosition[0]--;
        objectEntityList[scriptEng.arrayPosition[0]].YPos -= 0x18000;
    }
    PlaySfx(globalSFXCount + 0, 0);
    HapticEffect_Script(100, 0, 0, 0);
}

void O_R1_Boss_Foot::BossFoot_SaveFootPosition()
{
    Entity *self = Self();

    scriptEng.tempValue[0] = ((self->values[4] >> 4) & 1);
    if (scriptEng.tempValue[0] == 0) {
        BossFoot_HandleMovement();
    } else {
        scriptEng.tempValue[0] = ((self->values[4] >> 5) & 1);
        if (scriptEng.tempValue[0] == 1) {
            scriptEng.tempValue[6] = self->values[2];
            scriptEng.tempValue[7] = self->values[5];
            if (self->state != 3) {
                scriptEng.tempValue[6] = -scriptEng.tempValue[6];
                scriptEng.tempValue[7] = -scriptEng.tempValue[7];
            }
            scriptEng.arrayPosition[0] = self->values[0];
            objectEntityList[scriptEng.arrayPosition[0]].XPos -= scriptEng.tempValue[6];
            objectEntityList[scriptEng.arrayPosition[0]].YPos += scriptEng.tempValue[7];
            scriptEng.arrayPosition[1] = objectEntityList[scriptEng.arrayPosition[0]].values[0];
            objectEntityList[scriptEng.arrayPosition[1]].XPos -= scriptEng.tempValue[6];
            objectEntityList[scriptEng.arrayPosition[1]].YPos += scriptEng.tempValue[7];
            scriptEng.arrayPosition[0] = objectEntityList[scriptEng.arrayPosition[1]].values[0];
            objectEntityList[scriptEng.arrayPosition[0]].XPos -= scriptEng.tempValue[6];
            objectEntityList[scriptEng.arrayPosition[0]].YPos += scriptEng.tempValue[7];
            scriptEng.arrayPosition[1] = objectEntityList[scriptEng.arrayPosition[0]].values[0];
            objectEntityList[scriptEng.arrayPosition[1]].XPos -= scriptEng.tempValue[6];
            objectEntityList[scriptEng.arrayPosition[1]].YPos += scriptEng.tempValue[7];
        }
    }
}

void O_R1_Boss_Foot::BossFoot_Unused()
{
    Entity *self = Self();

    scriptEng.tempValue[0] = self->YPos;
    ObjectTileCollision_Script(0, 0, 20, 0);
    if (CheckResult() == 1) {
        scriptEng.tempValue[0] = ((self->values[4] >> 5) & 1);
        if (scriptEng.tempValue[0] == 1) {
            scriptEng.tempValue[0] -= self->YPos;
            scriptEng.arrayPosition[0] = self->values[0];
            objectEntityList[scriptEng.arrayPosition[0]].YPos -= scriptEng.tempValue[0];
            scriptEng.arrayPosition[1] = objectEntityList[scriptEng.arrayPosition[0]].values[0];
            objectEntityList[scriptEng.arrayPosition[1]].YPos -= scriptEng.tempValue[0];
            scriptEng.arrayPosition[0] = objectEntityList[scriptEng.arrayPosition[1]].values[0];
            objectEntityList[scriptEng.arrayPosition[1]].YPos -= scriptEng.tempValue[0];
            scriptEng.arrayPosition[1] = objectEntityList[scriptEng.arrayPosition[0]].values[0];
            objectEntityList[scriptEng.arrayPosition[1]].YPos -= scriptEng.tempValue[0];
        }
    }
}

const Native::NativeFunctionDef O_R1_Boss_Foot::funcs[4] = {
    { "BossFoot_HandleMovement", O_R1_Boss_Foot::BossFoot_HandleMovement },
    { "BossFoot_StepEarthQuake", O_R1_Boss_Foot::BossFoot_StepEarthQuake },
    { "BossFoot_SaveFootPosition", O_R1_Boss_Foot::BossFoot_SaveFootPosition },
    { "BossFoot_Unused", O_R1_Boss_Foot::BossFoot_Unused },
};

#endif // RETRO_USE_NATIVE_OBJECTS

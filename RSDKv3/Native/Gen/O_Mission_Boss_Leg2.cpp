#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_Mission_Boss_Leg2.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from Boss_Leg2.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_Mission_Boss_Leg2::ObjectStartup()
{
    LoadSpriteSheet("R1/Objects3.gif");
    AddSpriteFrame(-12, -20, 24, 40, 74, 1);
}

void O_Mission_Boss_Leg2::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        scriptEng.tempValue[0] = 0x4000;
        scriptEng.tempValue[0] *= self->propertyValue;
        scriptEng.tempValue[0] /= 10;
        self->values[2] = scriptEng.tempValue[0];
        self->values[2] <<= 1;
        self->values[5] = scriptEng.tempValue[0];
        self->state = 1;
        break;
        case 1:
        scriptEng.arrayPosition[0] = self->values[0];
        self->XPos = objectEntityList[scriptEng.arrayPosition[0]].XPos;
        self->XPos += 0x40000;
        self->YPos = objectEntityList[scriptEng.arrayPosition[0]].YPos;
        self->YPos += 0x100000;
        break;
        case 2:
        scriptEng.arrayPosition[0] = self->values[0];
        scriptEng.arrayPosition[1] = objectEntityList[scriptEng.arrayPosition[0]].values[0];
        scriptEng.arrayPosition[0] = objectEntityList[scriptEng.arrayPosition[1]].values[1];
        scriptEng.arrayPosition[1] = objectEntityList[scriptEng.arrayPosition[0]].values[1];
        self->XPos = objectEntityList[scriptEng.arrayPosition[1]].XPos;
        self->XPos -= 0xA0000;
        self->YPos = objectEntityList[scriptEng.arrayPosition[1]].YPos;
        break;
        case 3:
        scriptEng.arrayPosition[0] = self->values[1];
        if (self->values[6] < 0x80000) {
            scriptEng.tempValue[1] = self->values[2];
            self->values[6] += scriptEng.tempValue[1];
            scriptEng.tempValue[0] = ((self->values[4] >> 4) & 1);
            if (scriptEng.tempValue[0] == 1) {
                scriptEng.tempValue[1] = -scriptEng.tempValue[1];
                scriptEng.tempValue[2] = 0;
                BossLeg2_SaveLegPosition();
            } else {
                BossLeg2_HandleMovement();
            }
        } else {
            BossLeg2_HandleMovement();
        }
        break;
        case 4:
        scriptEng.arrayPosition[0] = self->values[1];
        if (self->values[6] > -0x80000) {
            scriptEng.tempValue[1] = self->values[2];
            self->values[6] -= scriptEng.tempValue[1];
            scriptEng.tempValue[0] = ((self->values[4] >> 4) & 1);
            if (scriptEng.tempValue[0] == 1) {
                scriptEng.tempValue[2] = 0;
                BossLeg2_SaveLegPosition();
            } else {
                BossLeg2_HandleMovement();
            }
        } else {
            BossLeg2_HandleMovement();
        }
        break;
        case 5:
        if (self->values[6] > -0x80000) {
            scriptEng.tempValue[1] = self->values[2];
            self->values[6] -= scriptEng.tempValue[1];
        } else {
            scriptEng.tempValue[1] = 0;
        }
        if (self->values[7] > -0x40000) {
            scriptEng.tempValue[2] = self->values[5];
            self->values[7] -= scriptEng.tempValue[2];
        } else {
            scriptEng.tempValue[2] = 0;
        }
        scriptEng.tempValue[0] = ((self->values[4] >> 4) & 1);
        if (scriptEng.tempValue[0] == 1) {
            BossLeg2_SaveLegPosition();
        } else {
            BossLeg2_HandleMovement();
        }
        break;
        case 6:
        if (self->values[6] > -0x80000) {
            scriptEng.tempValue[1] = self->values[2];
            self->values[6] -= scriptEng.tempValue[1];
        } else {
            scriptEng.tempValue[1] = 0;
        }
        if (self->values[7] < 0x40000) {
            scriptEng.tempValue[2] = self->values[5];
            self->values[7] += scriptEng.tempValue[2];
        } else {
            scriptEng.tempValue[2] = 0;
        }
        scriptEng.tempValue[0] = ((self->values[4] >> 4) & 1);
        if (scriptEng.tempValue[0] == 1) {
            scriptEng.tempValue[2] = -scriptEng.tempValue[2];
            BossLeg2_SaveLegPosition();
        } else {
            BossLeg2_HandleMovement();
        }
        break;
        case 7:
        scriptEng.tempValue[0] = ((self->values[4] >> 4) & 1);
        if (scriptEng.tempValue[0] == 0) {
            self->values[2] -= 0x600;
        } else {
            self->values[2] += 0x600;
        }
        self->values[5] += 0x1A60;
        self->XPos += self->values[2];
        self->YPos += self->values[5];
        if (GetObjectOutOfBounds(objectLoop) == 1) {
            self->type = TypeNameID("Blank Object");
            self->priority = 0;
        }
        break;
    }
}

void O_Mission_Boss_Leg2::ObjectPlayerInteraction()
{
    Entity *self = Self();

    if (self->state < 7) {
        if (PlayerValue(4) == 0) {
            PlayerObjectCollision(C_TOUCH, -12, -20, 12, -20);
            if (CheckResult() == 1) {
                pState() = PlayerStateID("Player_State_GotHit");
                scriptEng.arrayPosition[0] = self->values[0];
                scriptEng.arrayPosition[1] = objectEntityList[scriptEng.arrayPosition[0]].values[0];
                scriptEng.arrayPosition[0] = objectEntityList[scriptEng.arrayPosition[1]].values[0];
                objectEntityList[scriptEng.arrayPosition[0]].animation = 1;
                objectEntityList[scriptEng.arrayPosition[0]].direction = 180;
                if (pXPos() > self->XPos) {
                    pSpeed() = 0x20000;
                } else {
                    pSpeed() = -0x20000;
                }
            }
        }
    }
}

void O_Mission_Boss_Leg2::ObjectDraw()
{
    DrawSprite_Frame(0);
}

void O_Mission_Boss_Leg2::BossLeg2_SaveLegPosition()
{
    Entity *self = Self();

    scriptEng.tempValue[0] = ((self->values[4] >> 5) & 1);
    if (scriptEng.tempValue[0] == 1) {
        scriptEng.arrayPosition[0] = self->values[0];
        objectEntityList[scriptEng.arrayPosition[0]].XPos += scriptEng.tempValue[1];
        objectEntityList[scriptEng.arrayPosition[0]].YPos += scriptEng.tempValue[2];
        scriptEng.arrayPosition[1] = objectEntityList[scriptEng.arrayPosition[0]].values[0];
        objectEntityList[scriptEng.arrayPosition[1]].XPos += scriptEng.tempValue[1];
        objectEntityList[scriptEng.arrayPosition[1]].YPos += scriptEng.tempValue[2];
        scriptEng.arrayPosition[0] = objectEntityList[scriptEng.arrayPosition[1]].values[0];
        objectEntityList[scriptEng.arrayPosition[0]].XPos += scriptEng.tempValue[1];
        objectEntityList[scriptEng.arrayPosition[0]].YPos += scriptEng.tempValue[2];
    }
}

void O_Mission_Boss_Leg2::BossLeg2_HandleMovement()
{
    Entity *self = Self();

    scriptEng.arrayPosition[0] = self->values[0];
    self->XPos = objectEntityList[scriptEng.arrayPosition[0]].XPos;
    self->XPos += 0x40000;
    self->XPos += self->values[6];
    self->YPos = objectEntityList[scriptEng.arrayPosition[0]].YPos;
    self->YPos += 0x100000;
    self->YPos += self->values[7];
}

const Native::NativeFunctionDef O_Mission_Boss_Leg2::funcs[2] = {
    { "BossLeg2_SaveLegPosition", O_Mission_Boss_Leg2::BossLeg2_SaveLegPosition },
    { "BossLeg2_HandleMovement", O_Mission_Boss_Leg2::BossLeg2_HandleMovement },
};

#endif // RETRO_USE_NATIVE_OBJECTS

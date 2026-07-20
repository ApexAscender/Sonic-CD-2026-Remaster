#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R1_Boss_Arm.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from Boss_Arm.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R1_Boss_Arm::ObjectStartup()
{
    LoadSpriteSheet("R1/Objects3.gif");
    AddSpriteFrame(-15, -8, 32, 16, 141, 34);
    AddSpriteFrame(-6, -8, 24, 16, 174, 34);
    AddSpriteFrame(2, -8, 16, 16, 124, 51);
    AddSpriteFrame(9, -8, 24, 16, 141, 51);
}

void O_R1_Boss_Arm::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        self->state = 1;
        case 1:
        BossArm_HandleArmMovement();
        break;
        case 2:
        self->values[2] -= 0x620;
        self->XPos += self->values[2];
        self->values[5] += 0x1220;
        self->YPos += self->values[5];
        self->values[3]++;
        if (self->values[3] == 7) {
            self->values[3] = 0;
            CreateTempObject(TypeNameID("Explosion"), 0, self->XPos, self->YPos);
            PlaySfx(22, 0);
        }
        if (GetObjectOutOfBounds(objectLoop) == 1) {
            self->type = TypeNameID("Blank Object");
            self->priority = 0;
        }
        break;
        case 3:
        if (self->values[6] > 0) {
            self->values[6] -= 0x8000;
        }
        BossArm_HandleArmMovement();
        break;
        case 4:
        if (self->values[6] < 0x100000) {
            self->values[6] += 0x8000;
        }
        BossArm_HandleArmMovement();
        break;
        case 5:
        if (self->values[6] < 0x80000) {
            self->values[6] += 0x8000;
        } else {
            self->frame = 1;
        }
        scriptEng.arrayPosition[0] = self->values[0];
        self->XPos = objectEntityList[scriptEng.arrayPosition[0]].XPos;
        self->XPos -= 0x240000;
        self->XPos += self->values[6];
        if (self->values[7] < 0x80000) {
            self->values[7] += 0x10000;
        }
        self->YPos = objectEntityList[scriptEng.arrayPosition[0]].YPos;
        self->YPos += self->values[7];
        break;
    }
}

void O_R1_Boss_Arm::ObjectDraw()
{
    DrawSprite_Frame(3);
    DrawSprite_Frame(0);
}

void O_R1_Boss_Arm::BossArm_HandleArmMovement()
{
    Entity *self = Self();

    scriptEng.arrayPosition[0] = self->values[0];
    self->XPos = objectEntityList[scriptEng.arrayPosition[0]].XPos;
    self->XPos -= 0x240000;
    self->XPos += self->values[6];
    self->YPos = objectEntityList[scriptEng.arrayPosition[0]].YPos;
    scriptEng.tempValue[1] = 1;
    scriptEng.tempValue[0] = ((self->values[4] >> 7) & 1);
    if (scriptEng.tempValue[0] == 0) {
        if (pYPos() < self->YPos) {
            if (self->values[7] > -0x80000) {
                self->values[7] -= 0x10000;
            }
            scriptEng.tempValue[1] = 0;
        }
    }
    if (scriptEng.tempValue[1] == 1) {
        if (self->values[7] < 0x80000) {
            self->values[7] += 0x10000;
        }
    }
    self->YPos += self->values[7];
}

const Native::NativeFunctionDef O_R1_Boss_Arm::funcs[1] = {
    { "BossArm_HandleArmMovement", O_R1_Boss_Arm::BossArm_HandleArmMovement },
};

#endif // RETRO_USE_NATIVE_OBJECTS

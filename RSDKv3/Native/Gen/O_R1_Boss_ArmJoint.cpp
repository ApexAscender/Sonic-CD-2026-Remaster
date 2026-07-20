#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R1_Boss_ArmJoint.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from Boss_ArmJoint.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R1_Boss_ArmJoint::ObjectStartup()
{
    LoadSpriteSheet("R1/Objects3.gif");
    AddSpriteFrame(-8, -8, 16, 16, 124, 34);
}

void O_R1_Boss_ArmJoint::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        if (self->drawOrder == 3) {
            self->values[2] = 128;
        }
        self->state = 3;
        case 1:
        self->values[2] -= 2;
        if (self->values[2] <= 0) {
            self->state = 2;
            self->values[2] = 0;
            self->values[4] = (1) ? (self->values[4] | (1 << 0)) : (self->values[4] & ~(1 << 0));
        }
        BossArmJoint_HandleMovement();
        break;
        case 2:
        BossArmJoint_HandleMovement();
        break;
        case 3:
        self->values[2] += 2;
        if (self->values[2] >= 48) {
            self->state = 4;
            self->values[2] = 48;
            self->values[4] = (1) ? (self->values[4] | (1 << 0)) : (self->values[4] & ~(1 << 0));
        }
        BossArmJoint_HandleMovement();
        break;
        case 4:
        BossArmJoint_HandleMovement();
        break;
        case 5:
        self->values[2] += 0x600;
        self->XPos += self->values[2];
        self->values[5] += 0x1F00;
        self->YPos += self->values[5];
        if (GetObjectOutOfBounds(objectLoop) == 1) {
            self->type = TypeNameID("Blank Object");
            self->priority = 0;
        }
        break;
    }
}

void O_R1_Boss_ArmJoint::ObjectDraw()
{
    DrawSprite_Frame(0);
}

void O_R1_Boss_ArmJoint::BossArmJoint_HandleMovement()
{
    Entity *self = Self();

    scriptEng.tempValue[0] = self->values[2];
    scriptEng.tempValue[0] += 64;
    scriptEng.tempValue[6] = Sin256(scriptEng.tempValue[0]);
    scriptEng.tempValue[6] <<= 12;
    scriptEng.tempValue[7] = Cos256(scriptEng.tempValue[0]);
    scriptEng.tempValue[7] <<= 12;
    scriptEng.arrayPosition[0] = self->values[0];
    self->XPos = objectEntityList[scriptEng.arrayPosition[0]].XPos;
    self->XPos += scriptEng.tempValue[7];
    self->YPos = objectEntityList[scriptEng.arrayPosition[0]].YPos;
    self->YPos += scriptEng.tempValue[6];
    if (self->drawOrder == 2) {
        self->XPos -= 0xA0000;
    }
}

const Native::NativeFunctionDef O_R1_Boss_ArmJoint::funcs[1] = {
    { "BossArmJoint_HandleMovement", O_R1_Boss_ArmJoint::BossArmJoint_HandleMovement },
};

#endif // RETRO_USE_NATIVE_OBJECTS

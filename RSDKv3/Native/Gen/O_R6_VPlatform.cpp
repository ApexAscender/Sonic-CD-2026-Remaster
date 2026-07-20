#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R6_VPlatform.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from VPlatform.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R6_VPlatform::ObjectStartup()
{
    LoadSpriteSheet("R6/Objects.gif");
    AddSpriteFrame(-24, -16, 48, 32, 1, 84);
    AddSpriteFrame(-8, 16, 16, 16, 35, 117);
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("V Platform")) {
            objectEntityList[scriptEng.arrayPosition[0]].drawOrder = 4;
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_R6_VPlatform::ObjectMain()
{
    Entity *self = Self();

    self->values[3] = GVar("Oscillation");
    self->values[3] <<= 1;
    if (self->propertyValue == 0) {
        self->values[3] += 256;
    }
    self->values[2] = Sin512(self->values[3]);
    self->values[2] <<= 13;
    self->values[2] += self->YPos;
    self->values[2] &= 0xFFFF0000;
    self->values[2] -= self->values[1];
}

void O_R6_VPlatform::ObjectPlayerInteraction()
{
    Entity *self = Self();

    scriptEng.tempValue[0] = self->YPos;
    self->YPos = self->values[1];
    PlayerObjectCollision(C_PLATFORM, -24, -12, 24, 8);
    if (CheckResult() == 1) {
        pYPos() += self->values[2];
        if (pState() == PlayerStateID("Player_State_SpinningTop")) {
            pState() = PlayerStateID("Player_State_Ground");
        }
    }
    self->YPos = scriptEng.tempValue[0];
}

void O_R6_VPlatform::ObjectDraw()
{
    Entity *self = Self();

    self->values[1] = Sin512(self->values[3]);
    self->values[1] <<= 13;
    self->values[1] += self->YPos;
    self->values[1] &= 0xFFFF0000;
    DrawSprite_FrameXY(0, self->XPos, self->values[1]);
    DrawSprite_FrameXY(1, self->XPos, self->values[1]);
}

#endif // RETRO_USE_NATIVE_OBJECTS

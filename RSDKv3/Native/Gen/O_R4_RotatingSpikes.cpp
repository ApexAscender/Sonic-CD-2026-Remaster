#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R4_RotatingSpikes.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from RotatingSpikes.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R4_RotatingSpikes::ObjectStartup()
{
    LoadSpriteSheet("R4/Objects.gif");
    AddSpriteFrame(-8, -8, 16, 16, 163, 52);
    AddSpriteFrame(-8, -8, 16, 16, 180, 52);
    AddSpriteFrame(-16, -16, 32, 32, 221, 53);
}

void O_R4_RotatingSpikes::ObjectMain()
{
    Entity *self = Self();

    self->values[0] += 2;
    self->values[0] &= 511;
}

void O_R4_RotatingSpikes::ObjectPlayerInteraction()
{
    Entity *self = Self();

    scriptEng.tempValue[0] = 0;
    scriptEng.tempValue[1] = self->propertyValue;
    scriptEng.tempValue[1]--;
    scriptEng.tempValue[1] <<= 4;
    scriptEng.tempValue[2] = self->XPos;
    scriptEng.tempValue[3] = self->YPos;
    self->XPos = Cos512(self->values[0]);
    self->XPos *= scriptEng.tempValue[1];
    self->XPos <<= 7;
    self->XPos += scriptEng.tempValue[2];
    self->YPos = Sin512(self->values[0]);
    self->YPos *= scriptEng.tempValue[1];
    self->YPos <<= 7;
    self->YPos += scriptEng.tempValue[3];
    PlayerObjectCollision(C_TOUCH, -12, -12, 12, 12);
    if (CheckResult() == 1) {
        CallScriptFunctionNamed("Player_Hit", scriptSub);
    }
    self->XPos = scriptEng.tempValue[2];
    self->YPos = scriptEng.tempValue[3];
}

void O_R4_RotatingSpikes::ObjectDraw()
{
    Entity *self = Self();

    DrawSprite_Frame(0);
    scriptEng.tempValue[0] = 0;
    scriptEng.tempValue[1] = 16;
    scriptEng.tempValue[4] = self->propertyValue;
    scriptEng.tempValue[4]--;
    while (scriptEng.tempValue[0] < scriptEng.tempValue[4]) {
        scriptEng.tempValue[2] = Cos512(self->values[0]);
        scriptEng.tempValue[2] *= scriptEng.tempValue[1];
        scriptEng.tempValue[2] <<= 7;
        scriptEng.tempValue[2] += self->XPos;
        scriptEng.tempValue[3] = Sin512(self->values[0]);
        scriptEng.tempValue[3] *= scriptEng.tempValue[1];
        scriptEng.tempValue[3] <<= 7;
        scriptEng.tempValue[3] += self->YPos;
        DrawSprite_FrameXY(1, scriptEng.tempValue[2], scriptEng.tempValue[3]);
        scriptEng.tempValue[0]++;
        scriptEng.tempValue[1] += 16;
    }
    scriptEng.tempValue[2] = Cos512(self->values[0]);
    scriptEng.tempValue[2] *= scriptEng.tempValue[1];
    scriptEng.tempValue[2] <<= 7;
    scriptEng.tempValue[2] += self->XPos;
    scriptEng.tempValue[3] = Sin512(self->values[0]);
    scriptEng.tempValue[3] *= scriptEng.tempValue[1];
    scriptEng.tempValue[3] <<= 7;
    scriptEng.tempValue[3] += self->YPos;
    DrawSprite_FrameXY(2, scriptEng.tempValue[2], scriptEng.tempValue[3]);
}

#endif // RETRO_USE_NATIVE_OBJECTS

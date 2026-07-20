#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R4_RotatingSpikes2.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from RotatingSpikes2.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R4_RotatingSpikes2::ObjectStartup()
{
    LoadSpriteSheet("R4/Objects.gif");
    AddSpriteFrame(-16, -16, 32, 32, 221, 53);
}

void O_R4_RotatingSpikes2::ObjectMain()
{
    Entity *self = Self();

    if (self->propertyValue < 128) {
        self->values[0] += 2;
        self->values[0] &= 511;
    } else {
        self->values[0] -= 2;
        if (self->values[0] < 0) {
            self->values[0] += 512;
        }
    }
}

void O_R4_RotatingSpikes2::ObjectPlayerInteraction()
{
    Entity *self = Self();

    scriptEng.tempValue[0] = self->XPos;
    scriptEng.tempValue[1] = self->YPos;
    scriptEng.tempValue[2] = self->values[0];
    scriptEng.tempValue[3] = 0;
    if (self->propertyValue < 128) {
        while (scriptEng.tempValue[3] < 4) {
            self->XPos = Cos512(scriptEng.tempValue[2]);
            self->XPos <<= 13;
            self->XPos += scriptEng.tempValue[0];
            self->YPos = Sin512(scriptEng.tempValue[2]);
            self->YPos <<= 13;
            self->YPos += scriptEng.tempValue[1];
            PlayerObjectCollision(C_TOUCH, -12, -12, 12, 12);
            if (CheckResult() == 1) {
                CallScriptFunctionNamed("Player_Hit", scriptSub);
            }
            scriptEng.tempValue[2] += 16;
            scriptEng.tempValue[3]++;
        }
    } else {
        scriptEng.tempValue[2] += 64;
        while (scriptEng.tempValue[3] < 4) {
            self->XPos = Cos512(scriptEng.tempValue[2]);
            self->XPos <<= 13;
            self->XPos += scriptEng.tempValue[0];
            self->YPos = Sin512(scriptEng.tempValue[2]);
            self->YPos <<= 13;
            self->YPos += scriptEng.tempValue[1];
            PlayerObjectCollision(C_TOUCH, -12, -12, 12, 12);
            if (CheckResult() == 1) {
                CallScriptFunctionNamed("Player_Hit", scriptSub);
            }
            scriptEng.tempValue[2] -= 16;
            scriptEng.tempValue[3]++;
        }
    }
    self->XPos = scriptEng.tempValue[0];
    self->YPos = scriptEng.tempValue[1];
}

void O_R4_RotatingSpikes2::ObjectDraw()
{
    Entity *self = Self();

    scriptEng.tempValue[2] = self->values[0];
    scriptEng.tempValue[3] = 0;
    if (self->propertyValue < 128) {
        while (scriptEng.tempValue[3] < 4) {
            scriptEng.tempValue[0] = Cos512(scriptEng.tempValue[2]);
            scriptEng.tempValue[0] <<= 13;
            scriptEng.tempValue[0] += self->XPos;
            scriptEng.tempValue[1] = Sin512(scriptEng.tempValue[2]);
            scriptEng.tempValue[1] <<= 13;
            scriptEng.tempValue[1] += self->YPos;
            DrawSprite_FrameXY(0, scriptEng.tempValue[0], scriptEng.tempValue[1]);
            scriptEng.tempValue[2] += 16;
            scriptEng.tempValue[3]++;
        }
    } else {
        scriptEng.tempValue[2] += 64;
        while (scriptEng.tempValue[3] < 4) {
            scriptEng.tempValue[0] = Cos512(scriptEng.tempValue[2]);
            scriptEng.tempValue[0] <<= 13;
            scriptEng.tempValue[0] += self->XPos;
            scriptEng.tempValue[1] = Sin512(scriptEng.tempValue[2]);
            scriptEng.tempValue[1] <<= 13;
            scriptEng.tempValue[1] += self->YPos;
            DrawSprite_FrameXY(0, scriptEng.tempValue[0], scriptEng.tempValue[1]);
            scriptEng.tempValue[2] -= 16;
            scriptEng.tempValue[3]++;
        }
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS

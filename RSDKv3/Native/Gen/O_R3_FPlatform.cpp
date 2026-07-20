#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R3_FPlatform.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from FPlatform.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R3_FPlatform::ObjectStartup()
{
    LoadSpriteSheet("R3/Objects.gif");
    AddSpriteFrame(-32, -16, 64, 32, 100, 1);
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("F Platform")) {
            objectEntityList[scriptEng.arrayPosition[0]].values[3] = objectEntityList[scriptEng.arrayPosition[0]].YPos;
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_R3_FPlatform::ObjectMain()
{
    Entity *self = Self();

    if (self->values[0] == 1) {
        if (self->values[1] < 16) {
            self->values[1]++;
            scriptEng.tempValue[0] = self->values[1];
            scriptEng.tempValue[0] &= 3;
            if (scriptEng.tempValue[0] == 3) {
                self->values[2] = 0x10000;
            } else {
                self->values[2] = 0;
            }
        } else {
            self->values[2] = 0;
        }
    } else {
        if (self->values[1] > 0) {
            self->values[1]--;
            scriptEng.tempValue[0] = self->values[1];
            scriptEng.tempValue[0] &= 3;
            if (scriptEng.tempValue[0] == 3) {
                self->values[2] = -0x10000;
            } else {
                self->values[2] = 0;
            }
        } else {
            self->values[2] = 0;
            self->YPos = self->values[3];
        }
    }
    self->values[0] = 0;
}

void O_R3_FPlatform::ObjectPlayerInteraction()
{
    Entity *self = Self();

    PlayerObjectCollision(C_PLATFORM, -32, -17, 32, 12);
    if (CheckResult() == 1) {
        self->values[0] = 1;
        pYPos() += self->values[2];
        pYPos() += 0x10000;
    }
}

void O_R3_FPlatform::ObjectDraw()
{
    Entity *self = Self();

    self->YPos += self->values[2];
    DrawSprite_Frame(0);
}

#endif // RETRO_USE_NATIVE_OBJECTS

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R6_AngelRing.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from AngelRing.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R6_AngelRing::ObjectMain()
{
    Entity *self = Self();

    if (GetObjectOutOfBounds(objectLoop) == 1) {
        self->state = 0;
        self->values[3] = 0;
        self->values[2] = 0;
        self->priority = 0;
    }
    if (self->values[3] > 0) {
        if (self->values[2] < 12) {
            self->values[2]++;
        } else {
            self->values[2] = 0;
            CreateTempObject(TypeNameID("Lose Ring"), 0, self->XPos, self->YPos);
            objectEntityList[scriptEng.arrayPosition[2]].values[0] = rand() % 8;
            objectEntityList[scriptEng.arrayPosition[2]].values[0] <<= 15;
            objectEntityList[scriptEng.arrayPosition[2]].values[0] -= 0x14000;
            objectEntityList[scriptEng.arrayPosition[2]].values[1] = -0x20000;
            objectEntityList[scriptEng.arrayPosition[2]].animationSpeed = 256;
            self->values[3]--;
        }
    }
}

void O_R6_AngelRing::ObjectPlayerInteraction()
{
    Entity *self = Self();

    if (self->state == 0) {
        PlayerObjectCollision(C_TOUCH, -64, -64, -12, 96);
        if (CheckResult() == 1) {
            self->state = 1;
            self->values[3] = 60;
            self->priority = 1;
            self->values[2] = 0;
            if (playerListPos == 0) {
                if (debugMode == 0) {
                    SetAchievement(5, 100);
                }
            }
        }
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS

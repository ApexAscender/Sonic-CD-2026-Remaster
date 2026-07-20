#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_TimeWarpFix.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from TimeWarpFix.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_TimeWarpFix::ObjectStartup()
{
}

void O_TimeWarpFix::ObjectMain()
{
    Entity *self = Self();

    switch (self->propertyValue) {
        case 0:
        PlayerObjectCollision(C_TOUCH, -16, -16, 16, 16);
        if (CheckResult() == 1) {
            if (GVar("Warp.Destination") > 0) {
                if (GVar("Warp.Timer") > 99) {
                    if (GVar("Warp.Timer") < 220) {
                        GVar("Warp.Destination") = 0;
                    }
                }
                GVar("Warp.Timer") = 0;
            }
        }
        break;
        case 1:
        if (pXPos() < self->XPos) {
            GVar("Warp.Destination") = 0;
            GVar("Warp.Timer") = 0;
        }
        break;
        case 2:
        PlayerObjectCollision(C_TOUCH, -48, -48, 48, 48);
        if (CheckResult() == 1) {
            self->type = TypeNameID("Blank Object");
            pXPos() = objectEntityList[objectLoop + 1].XPos;
            pYPos() = objectEntityList[objectLoop + 1].YPos;
        }
        self->values[0]++;
        if (self->values[0] == 2) {
            self->type = TypeNameID("Blank Object");
        }
        break;
        case 3:
        PlayerObjectCollision(C_TOUCH, -96, -96, 96, 96);
        if (CheckResult() == 1) {
            self->type = TypeNameID("Blank Object");
            pXPos() = objectEntityList[objectLoop + 1].XPos;
            pYPos() = objectEntityList[objectLoop + 1].YPos;
            pGravity() = 1;
        }
        self->values[0]++;
        if (self->values[0] == 2) {
            self->type = TypeNameID("Blank Object");
        }
        break;
        case 4:
        break;
    }
}

void O_TimeWarpFix::ObjectPlayerInteraction()
{
    PlayerObjectCollision(C_TOUCH, -14, -15, 14, 16);
}

#endif // RETRO_USE_NATIVE_OBJECTS

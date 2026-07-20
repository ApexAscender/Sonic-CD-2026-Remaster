#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R3_OneWayPlat.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from OneWayPlat.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R3_OneWayPlat::ObjectStartup()
{
    LoadSpriteSheet("R3/Objects.gif");
    AddSpriteFrame(-96, -8, 64, 16, 165, 1);
}

void O_R3_OneWayPlat::ObjectPlayerInteraction()
{
    PlayerObjectCollision(C_PLATFORM, -32, -8, 32, 8);
}

void O_R3_OneWayPlat::ObjectDraw()
{
    Entity *self = Self();

    if (pYPos() < self->YPos) {
        if (self->values[0] < 0x400000) {
            self->values[0] += 0x100000;
        }
    } else {
        if (self->values[0] > 0) {
            self->values[0] -= 0x100000;
        }
    }
    scriptEng.tempValue[0] = self->XPos;
    scriptEng.tempValue[0] += self->values[0];
    DrawSprite_FrameXY(0, scriptEng.tempValue[0], self->YPos);
}

#endif // RETRO_USE_NATIVE_OBJECTS

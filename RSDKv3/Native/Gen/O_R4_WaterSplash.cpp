#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R4_WaterSplash.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from WaterSplash.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R4_WaterSplash::ObjectStartup()
{
    LoadSpriteSheet("R4/Objects.gif");
    AddSpriteFrame(-16, -16, 32, 16, 148, 95);
    AddSpriteFrame(-16, -64, 32, 64, 181, 103);
    AddSpriteFrame(-16, -48, 32, 48, 148, 145);
    AddSpriteFrame(-16, -32, 32, 32, 148, 112);
    AddSpriteFrame(-16, -32, 32, 32, 181, 168);
}

void O_R4_WaterSplash::ObjectMain()
{
    Entity *self = Self();

    objectEntityList[objectLoop].YPos = (waterLevel) << 16;
    self->values[0]++;
    if (self->values[0] > 4) {
        self->values[0] = 0;
        self->frame++;
        if (self->frame > 4) {
            self->type = TypeNameID("Blank Object");
        }
    }
}

void O_R4_WaterSplash::ObjectDraw()
{
    Entity *self = Self();

    DrawSprite_Frame(self->frame);
}

#endif // RETRO_USE_NATIVE_OBJECTS

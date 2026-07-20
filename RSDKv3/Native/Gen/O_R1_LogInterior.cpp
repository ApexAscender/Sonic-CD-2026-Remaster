#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R1_LogInterior.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from LogInterior.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R1_LogInterior::ObjectStartup()
{
    LoadSpriteSheet("R1/Objects2.gif");
    AddSpriteFrame(-16, -16, 32, 32, 190, 197);
    AddSpriteFrame(-16, -16, 32, 32, 223, 197);
}

void O_R1_LogInterior::ObjectDraw()
{
    Entity *self = Self();

    DrawSprite_Frame(self->propertyValue);
}

#endif // RETRO_USE_NATIVE_OBJECTS

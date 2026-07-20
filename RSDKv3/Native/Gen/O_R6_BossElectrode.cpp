#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R6_BossElectrode.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from BossElectrode.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R6_BossElectrode::ObjectStartup()
{
    LoadSpriteSheet("R6/Objects2.gif");
    AddSpriteFrame(-8, -16, 16, 32, 239, 183);
    AddSpriteFrame(-8, -16, 16, 32, 239, 216);
}

void O_R6_BossElectrode::ObjectDraw()
{
    Entity *self = Self();

    DrawSprite_Frame(self->propertyValue);
}

#endif // RETRO_USE_NATIVE_OBJECTS

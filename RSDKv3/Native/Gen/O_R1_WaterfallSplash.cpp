#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R1_WaterfallSplash.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from WaterfallSplash.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R1_WaterfallSplash::ObjectStartup()
{
    LoadSpriteSheet("R1/Objects3.gif");
    AddSpriteFrame(-16, -16, 32, 32, 1, 221);
    AddSpriteFrame(-12, -12, 24, 24, 34, 221);
    AddSpriteFrame(-8, -8, 16, 16, 59, 221);
}

void O_R1_WaterfallSplash::ObjectDraw()
{
    Entity *self = Self();

    scriptEng.tempValue[0] = self->frame;
    scriptEng.tempValue[0] >>= 2;
    DrawSprite_Frame(scriptEng.tempValue[0]);
    self->frame++;
    if (self->frame > 11) {
        self->type = TypeNameID("Blank Object");
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS

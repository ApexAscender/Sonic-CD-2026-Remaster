#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R7_LoveHeart.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from LoveHeart.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R7_LoveHeart::ObjectStartup()
{
    LoadSpriteSheet("R7/Objects2.gif");
    AddSpriteFrame(-8, -8, 16, 16, 193, 134);
    AddSpriteFrame(-8, -8, 16, 16, 193, 150);
}

void O_R7_LoveHeart::ObjectDraw()
{
    Entity *self = Self();

    if (self->values[0] > 144) {
        scriptEng.tempValue[0] = self->values[0];
        scriptEng.tempValue[0] -= 144;
        scriptEng.tempValue[0] <<= 3;
        if (scriptEng.tempValue[0] > 255) {
            scriptEng.tempValue[0] = 255;
        }
        self->alpha = 255;
        self->alpha -= scriptEng.tempValue[0];
        if (self->alpha == 0) {
            self->type = TypeNameID("Blank Object");
        }
    }
    scriptEng.tempValue[0] = Sin512(self->values[1]);
    scriptEng.tempValue[0] <<= 9;
    scriptEng.tempValue[0] += self->XPos;
    if (self->values[0] > 19) {
        DrawSpriteFX_Script(1, FX_INK, scriptEng.tempValue[0], self->YPos);
    } else {
        DrawSprite_FrameXY(0, scriptEng.tempValue[0], self->YPos);
    }
    self->YPos -= 0x6000;
    self->values[1] += 8;
    self->values[1] &= 511;
    self->values[0]++;
}

#endif // RETRO_USE_NATIVE_OBJECTS

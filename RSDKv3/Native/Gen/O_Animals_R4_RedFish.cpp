#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_Animals_R4_RedFish.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from R4_RedFish.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_Animals_R4_RedFish::ObjectStartup()
{
    LoadSpriteSheet("R4/Objects3.gif");
    AddSpriteFrame(-8, -12, 16, 24, 1, 67);
    AddSpriteFrame(-8, -12, 16, 24, 18, 67);
}

void O_Animals_R4_RedFish::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        if (self->values[1] < 512) {
            self->values[1] += 2;
            self->XPos += 0x10000;
        } else {
            self->state = 1;
            self->direction = 1;
        }
        break;
        case 1:
        if (self->values[1] > 0) {
            self->values[1] -= 2;
            self->XPos -= 0x10000;
        } else {
            self->state = 0;
            self->direction = 0;
        }
        break;
    }
    self->values[0]++;
    if (self->values[0] > 19) {
        self->values[0] = 0;
        self->frame++;
        self->frame &= 1;
    }
}

void O_Animals_R4_RedFish::ObjectDraw()
{
    Entity *self = Self();

    if (GVar("MetalSonic_Destroyed") == 1) {
        scriptEng.tempValue[1] = Sin512(self->values[1]);
        scriptEng.tempValue[1] <<= 12;
        scriptEng.tempValue[1] += self->YPos;
        DrawSpriteFX_Script(self->frame, FX_FLIP, self->XPos, scriptEng.tempValue[1]);
    }
    if (objectEntityList[24].propertyValue == 2) {
        scriptEng.tempValue[1] = Sin512(self->values[1]);
        scriptEng.tempValue[1] <<= 12;
        scriptEng.tempValue[1] += self->YPos;
        DrawSpriteFX_Script(self->frame, FX_FLIP, self->XPos, scriptEng.tempValue[1]);
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS

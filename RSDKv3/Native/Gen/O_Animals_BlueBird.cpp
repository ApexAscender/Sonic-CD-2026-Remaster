#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_Animals_BlueBird.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from BlueBird.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_Animals_BlueBird::ObjectStartup()
{
    LoadSpriteSheet("Global/Items3.gif");
    AddSpriteFrame(-8, -8, 16, 16, 240, 199);
    AddSpriteFrame(-8, -8, 16, 16, 240, 216);
}

void O_Animals_BlueBird::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        if (self->values[1] > 0) {
            self->values[1] -= 2;
        } else {
            self->state = 1;
            self->direction = 1;
        }
        break;
        case 1:
        if (self->values[1] < 256) {
            self->values[1] += 2;
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

void O_Animals_BlueBird::ObjectDraw()
{
    Entity *self = Self();

    if (GVar("MetalSonic_Destroyed") == 1) {
        scriptEng.tempValue[0] = Cos512(self->values[1]);
        scriptEng.tempValue[0] <<= 14;
        scriptEng.tempValue[0] += self->XPos;
        scriptEng.tempValue[1] = Sin512(self->values[1]);
        scriptEng.tempValue[1] <<= 14;
        scriptEng.tempValue[1] += self->YPos;
        DrawSpriteFX_Script(self->frame, FX_FLIP, scriptEng.tempValue[0], scriptEng.tempValue[1]);
    }
    if (objectEntityList[24].propertyValue == 2) {
        scriptEng.tempValue[0] = Cos512(self->values[1]);
        scriptEng.tempValue[0] <<= 14;
        scriptEng.tempValue[0] += self->XPos;
        scriptEng.tempValue[1] = Sin512(self->values[1]);
        scriptEng.tempValue[1] <<= 14;
        scriptEng.tempValue[1] += self->YPos;
        DrawSpriteFX_Script(self->frame, FX_FLIP, scriptEng.tempValue[0], scriptEng.tempValue[1]);
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS

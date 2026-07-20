#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R8_Forcefield.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from Forcefield.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R8_Forcefield::ObjectStartup()
{
    LoadSpriteSheet("R8/Objects3.gif");
    AddSpriteFrame(-8, 80, 16, 16, 90, 35);
    AddSpriteFrame(-8, 80, 16, 16, 107, 35);
    AddSpriteFrame(-8, 80, 16, 16, 124, 35);
    AddSpriteFrame(-8, 80, 16, 16, 107, 35);
    AddSpriteFrame(-8, -82, 16, 82, 74, 114);
    AddSpriteFrame(-8, 0, 16, 82, 74, 114);
}

void O_R8_Forcefield::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        if (self->propertyValue > 168) {
            self->propertyValue--;
        } else {
            self->state++;
        }
        self->frame = self->animationTimer;
        self->frame >>= 2;
        self->animationTimer++;
        self->animationTimer &= 15;
        scriptEng.tempValue[1] = GVar("Oscillation");
        scriptEng.tempValue[1] <<= 3;
        scriptEng.tempValue[0] = Sin512(scriptEng.tempValue[1]);
        scriptEng.tempValue[0] >>= 4;
        scriptEng.tempValue[0] += 190;
        self->alpha = scriptEng.tempValue[0];
        self->inkEffect = 2;
        self->drawOrder = 4;
        break;
        case 1:
        self->frame = self->animationTimer;
        self->frame >>= 2;
        self->animationTimer++;
        self->animationTimer &= 15;
        scriptEng.tempValue[1] = GVar("Oscillation");
        scriptEng.tempValue[1] <<= 3;
        scriptEng.tempValue[0] = Sin512(scriptEng.tempValue[1]);
        scriptEng.tempValue[0] >>= 4;
        scriptEng.tempValue[0] += 190;
        self->alpha = scriptEng.tempValue[0];
        break;
        case 2:
        self->frame = 0;
        if (self->alpha > 0) {
            self->alpha -= 2;
        }
        break;
    }
}

void O_R8_Forcefield::ObjectPlayerInteraction()
{
    Entity *self = Self();

    if (self->alpha > 0) {
        scriptEng.tempValue[0] = self->propertyValue;
        scriptEng.tempValue[0] -= 8;
        PlayerObjectCollision(C_BOX, scriptEng.tempValue[0], -96, 240, 96);
        scriptEng.tempValue[0] = -scriptEng.tempValue[0];
        PlayerObjectCollision(C_BOX, -240, -96, scriptEng.tempValue[0], 96);
    }
}

void O_R8_Forcefield::ObjectDraw()
{
    Entity *self = Self();

    scriptEng.tempValue[0] = self->propertyValue;
    scriptEng.tempValue[0] *= -0x10000;
    scriptEng.tempValue[0] += self->XPos;
    DrawSpriteFX_Script(4, FX_INK, scriptEng.tempValue[0], self->YPos);
    DrawSpriteFX_Script(5, FX_INK, scriptEng.tempValue[0], self->YPos);
    self->direction = 0;
    DrawSpriteFX_Script(self->frame, FX_FLIP, scriptEng.tempValue[0], self->YPos);
    self->direction = 2;
    DrawSpriteFX_Script(self->frame, FX_FLIP, scriptEng.tempValue[0], self->YPos);
    scriptEng.tempValue[0] = self->propertyValue;
    scriptEng.tempValue[0] <<= 16;
    scriptEng.tempValue[0] += self->XPos;
    DrawSpriteFX_Script(4, FX_INK, scriptEng.tempValue[0], self->YPos);
    DrawSpriteFX_Script(5, FX_INK, scriptEng.tempValue[0], self->YPos);
    self->direction = 0;
    DrawSpriteFX_Script(self->frame, FX_FLIP, scriptEng.tempValue[0], self->YPos);
    self->direction = 2;
    DrawSpriteFX_Script(self->frame, FX_FLIP, scriptEng.tempValue[0], self->YPos);
}

#endif // RETRO_USE_NATIVE_OBJECTS

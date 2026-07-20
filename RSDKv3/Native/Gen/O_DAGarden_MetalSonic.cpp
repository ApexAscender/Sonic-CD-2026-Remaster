#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_DAGarden_MetalSonic.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from MetalSonic.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_DAGarden_MetalSonic::ObjectStartup()
{
    LoadSpriteSheet("DAGarden/Objects.gif");
    AddSpriteFrame(-16, -24, 32, 48, 429, 804);
    AddSpriteFrame(-24, -12, 24, 24, 462, 804);
    AddSpriteFrame(-24, -12, 24, 24, 487, 804);
    AddSpriteFrame(-24, -12, 0, 0, 462, 804);
    AddSpriteFrame(-24, -12, 0, 0, 487, 804);
}

void O_DAGarden_MetalSonic::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        self->values[3] = SCREEN_CENTERX;
        self->values[3] <<= 16;
        if (self->XPos < self->values[3]) {
            self->direction = 0;
        } else {
            self->direction = 1;
        }
        self->state++;
        break;
        case 1:
        scriptEng.tempValue[0] = self->values[3];
        scriptEng.tempValue[0] -= self->XPos;
        scriptEng.tempValue[0] >>= 5;
        scriptEng.tempValue[1] = 0x780000;
        scriptEng.tempValue[1] -= self->YPos;
        scriptEng.tempValue[1] >>= 5;
        self->XPos += scriptEng.tempValue[0];
        self->YPos += scriptEng.tempValue[1];
        self->values[0]++;
        if (self->values[0] == 120) {
            self->values[0] = 0;
            self->values[1] = self->YPos;
            self->state++;
        }
        self->animationTimer++;
        self->animationTimer &= 7;
        break;
        case 2:
        self->values[2] += 8;
        self->values[2] &= 511;
        self->YPos = Sin512(self->values[2]);
        self->YPos <<= 9;
        self->YPos += self->values[1];
        self->values[0]++;
        if (self->values[0] == 100) {
            self->values[0] = 0;
            self->values[1] = self->YPos;
            self->direction++;
            self->direction &= 1;
            self->state++;
        }
        self->animationTimer++;
        self->animationTimer &= 7;
        break;
        case 3:
        self->values[2] += 64;
        self->values[2] &= 511;
        self->YPos = Sin512(self->values[2]);
        self->YPos <<= 7;
        self->YPos += self->values[1];
        if (self->direction == 1) {
            self->XPos += 0x8000;
        } else {
            self->XPos -= 0x8000;
        }
        self->values[0]++;
        if (self->values[0] == 90) {
            self->values[0] = 0;
            self->values[4] = 0x10000;
            self->state++;
        }
        self->animationTimer++;
        self->animationTimer &= 7;
        break;
        case 4:
        if (self->direction == 0) {
            self->XPos += self->values[4];
        } else {
            self->XPos -= self->values[4];
        }
        self->values[4] += 0x3000;
        self->animationTimer += 2;
        self->animationTimer %= 5;
        break;
    }
    if (GetObjectOutOfBounds(objectLoop) == 1) {
        self->type = TypeNameID("Blank Object");
    }
}

void O_DAGarden_MetalSonic::ObjectDraw()
{
    Entity *self = Self();

    scriptEng.tempValue[0] = self->animationTimer;
    scriptEng.tempValue[0] >>= 1;
    scriptEng.tempValue[0]++;
    DrawSpriteFX_Script(scriptEng.tempValue[0], FX_FLIP, self->XPos, self->YPos);
    DrawSpriteFX_Script(0, FX_FLIP, self->XPos, self->YPos);
}

#endif // RETRO_USE_NATIVE_OBJECTS

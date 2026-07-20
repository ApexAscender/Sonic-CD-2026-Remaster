#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R1_EggJetpack.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from EggJetpack.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R1_EggJetpack::ObjectStartup()
{
    LoadSpriteSheet("R1/Objects3.gif");
    AddSpriteFrame(-28, -24, 56, 56, 1, 107);
    AddSpriteFrame(-28, -24, 56, 56, 1, 164);
    AddSpriteFrame(-28, -24, 56, 56, 58, 107);
    AddSpriteFrame(-28, -24, 56, 56, 58, 164);
}

void O_R1_EggJetpack::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        if (self->values[0] < 64) {
            self->values[0]++;
            if (self->values[0] > 27) {
                self->XPos += 0x8000;
                self->YPos -= 0x20000;
            }
        } else {
            self->values[0] = 0;
            self->state = 2;
            self->values[4] = self->YPos;
        }
        break;
        case 2:
        self->values[3] += 3;
        self->values[3] &= 255;
        scriptEng.tempValue[0] = Sin256(self->values[3]);
        scriptEng.tempValue[0] <<= 11;
        self->XPos += 0x28000;
        self->YPos = self->values[4];
        self->YPos -= scriptEng.tempValue[0];
        if (GetObjectOutOfBounds(objectLoop) == 1) {
            self->type = TypeNameID("Blank Object");
            objectEntityList[objectLoop - 1].state = 5;
            objectEntityList[objectLoop - 1].rotation = 0;
        }
        break;
    }
}

void O_R1_EggJetpack::ObjectDraw()
{
    Entity *self = Self();

    scriptEng.tempValue[0] = self->frame;
    scriptEng.tempValue[0] >>= 2;
    scriptEng.tempValue[0] += self->state;
    DrawSprite_Frame(scriptEng.tempValue[0]);
    self->frame++;
    self->frame &= 7;
}

#endif // RETRO_USE_NATIVE_OBJECTS

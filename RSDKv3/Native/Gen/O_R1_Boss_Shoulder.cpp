#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R1_Boss_Shoulder.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from Boss_Shoulder.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R1_Boss_Shoulder::ObjectStartup()
{
    LoadSpriteSheet("R1/Objects3.gif");
    AddSpriteFrame(-24, -12, 40, 24, 66, 66);
}

void O_R1_Boss_Shoulder::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        self->state = 1;
        case 1:
        scriptEng.arrayPosition[0] = self->values[0];
        self->XPos = objectEntityList[scriptEng.arrayPosition[0]].XPos;
        self->XPos += 0x180000;
        self->YPos = objectEntityList[scriptEng.arrayPosition[0]].YPos;
        self->YPos -= 0xC0000;
        break;
        case 2:
        self->values[2] -= 0x600;
        self->XPos += self->values[2];
        self->values[5] += 0x1800;
        self->YPos += self->values[5];
        if (GetObjectOutOfBounds(objectLoop) == 1) {
            self->type = TypeNameID("Blank Object");
            self->priority = 0;
        }
        break;
    }
}

void O_R1_Boss_Shoulder::ObjectDraw()
{
    DrawSprite_Frame(0);
}

#endif // RETRO_USE_NATIVE_OBJECTS

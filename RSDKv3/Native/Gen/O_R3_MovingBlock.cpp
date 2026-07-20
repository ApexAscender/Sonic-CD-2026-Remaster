#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R3_MovingBlock.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from MovingBlock.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R3_MovingBlock::ObjectStartup()
{
    LoadSpriteSheet("R3/Objects.gif");
    AddSpriteFrame(-16, -16, 32, 32, 1, 1);
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Moving Block")) {
            objectEntityList[scriptEng.arrayPosition[0]].values[1] = objectEntityList[scriptEng.arrayPosition[0]].XPos;
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_R3_MovingBlock::ObjectMain()
{
    Entity *self = Self();

    self->values[0] += 2;
    self->values[0] &= 511;
    self->XPos = Sin512(self->values[0]);
    self->XPos <<= 13;
    self->XPos += self->values[1];
    objectEntityList[objectLoop + 1].XPos = self->XPos;
}

void O_R3_MovingBlock::ObjectPlayerInteraction()
{
    PlayerObjectCollision(C_BOX, -16, -16, 16, 16);
}

void O_R3_MovingBlock::ObjectDraw()
{
    DrawSprite_Frame(0);
}

#endif // RETRO_USE_NATIVE_OBJECTS

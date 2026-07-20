#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_FlowerPod_PodSeed.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from PodSeed.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_FlowerPod_PodSeed::ObjectStartup()
{
    if (playerListPos == 0) {
        LoadSpriteSheet("Global/Items2.gif");
    }
    if (playerListPos == 1) {
        LoadSpriteSheet("Global/Items2_t.gif");
    }
    AddSpriteFrame(-8, -8, 16, 16, 83, 66);
    AddSpriteFrame(-8, -8, 16, 16, 83, 83);
    AddSpriteFrame(-8, -8, 16, 16, 83, 100);
    AddSpriteFrame(-8, -8, 16, 16, 83, 117);
    AddSpriteFrame(-8, -8, 16, 16, 83, 83);
    AddSpriteFrame(-8, -8, 16, 16, 83, 134);
}

void O_FlowerPod_PodSeed::ObjectMain()
{
    Entity *self = Self();

    self->frame = self->values[0];
    self->frame /= 3;
    self->values[0]++;
    self->values[0] %= 18;
    self->XPos += self->values[2];
    self->YPos += self->values[3];
    self->values[3] += 0x4000;
    if (self->values[3] > 0x60000) {
        ObjectTileCollision_Script(0, 0, 8, 0);
        if (CheckResult() == 1) {
            if (self->propertyValue == 1) {
                scriptEng.arrayPosition[0] = self->values[1];
                objectEntityList[scriptEng.arrayPosition[0]].state++;
                pControlMode() = -1;
            }
            ResetObjectEntity(objectLoop, GVar("Flower_TypeNo"), 0, self->XPos, self->YPos);
            self->YPos += 0x80000;
            self->state = 2;
            self->frame = 2;
            self->drawOrder = 4;
        }
    }
}

void O_FlowerPod_PodSeed::ObjectDraw()
{
    Entity *self = Self();

    DrawSprite_Frame(self->frame);
}

#endif // RETRO_USE_NATIVE_OBJECTS

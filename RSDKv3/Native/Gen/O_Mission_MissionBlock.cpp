#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_Mission_MissionBlock.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from MissionBlock.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_Mission_MissionBlock::ObjectStartup()
{
    LoadSpriteSheet("Mission/Objects.gif");
    AddSpriteFrame(-16, -16, 32, 32, 1, 1);
}

void O_Mission_MissionBlock::ObjectPlayerInteraction()
{
    Entity *self = Self();

    if (self->propertyValue <= 1) {
        PlayerObjectCollision(C_BOX, -16, -16, 16, 16);
    } else {
        scriptEng.tempValue[0] = 32;
        scriptEng.tempValue[0] *= self->propertyValue;
        scriptEng.tempValue[0] -= 16;
        PlayerObjectCollision(C_BOX, -16, -16, scriptEng.tempValue[0], 16);
    }
}

void O_Mission_MissionBlock::ObjectDraw()
{
    Entity *self = Self();

    if (self->propertyValue <= 1) {
        DrawSprite_Frame(0);
    } else {
        scriptEng.tempValue[0] = self->XPos;
        scriptEng.tempValue[1] = self->YPos;
        scriptEng.tempValue[2] = 0;
        while (scriptEng.tempValue[2] < self->propertyValue) {
            DrawSprite_FrameXY(0, scriptEng.tempValue[0], scriptEng.tempValue[1]);
            scriptEng.tempValue[0] += 0x200000;
            scriptEng.tempValue[2]++;
        }
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS

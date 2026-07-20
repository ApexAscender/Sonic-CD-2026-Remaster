#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_Special_TimeStone.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from TimeStone.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_Special_TimeStone::ObjectStartup()
{
    LoadSpriteSheet("Special/Objects.gif");
    AddSpriteFrame(-10, -12, 20, 24, 1, 232);
    AddSpriteFrame(-10, -12, 20, 24, 22, 232);
    AddSpriteFrame(-10, -12, 20, 24, 43, 232);
    AddSpriteFrame(-10, -12, 20, 24, 64, 232);
    AddSpriteFrame(-12, -12, 24, 24, 83, 143);
    AddSpriteFrame(-8, -8, 16, 16, 83, 126);
}

void O_Special_TimeStone::ObjectDraw()
{
    Entity *self = Self();

    scriptEng.tempValue[0] = self->frame;
    scriptEng.tempValue[0] /= 12;
    self->frame++;
    if (self->frame > 47) {
        self->frame = 0;
    }
    if (self->state == 0) {
        scriptEng.tempValue[1] = self->YPos;
        scriptEng.tempValue[1] -= 0x200000;
        DrawSpriteFX_Script(5, FX_FLIP, self->XPos, scriptEng.tempValue[1]);
        scriptEng.tempValue[1] += 0xC0000;
        DrawSpriteFX_Script(4, FX_FLIP, self->XPos, scriptEng.tempValue[1]);
        self->direction = self->frame;
        self->direction %= 24;
        self->direction /= 6;
        if ((objectEntityList[objectLoop].YPos >> 16) < 200) {
            self->YPos += 0x18000;
        } else {
            objectEntityList[objectLoop].YPos = (200) << 16;
            self->state = 1;
            PlaySfx(21, 0);
            objectEntityList[2].state = 10;
            objectEntityList[2].frame++;
        }
    }
    DrawSprite_Frame(scriptEng.tempValue[0]);
}

#endif // RETRO_USE_NATIVE_OBJECTS

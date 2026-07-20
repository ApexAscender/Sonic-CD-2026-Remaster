#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_TAttack_SLargeIcon.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from SLargeIcon.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_TAttack_SLargeIcon::ObjectStartup()
{
    LoadSpriteSheet("TAttack/TimeAttack.gif");
    AddSpriteFrame(-64, -72, 128, 144, 0, 288);
    AddSpriteFrame(-64, -72, 128, 144, 128, 288);
    AddSpriteFrame(-64, -72, 128, 144, 256, 288);
    AddSpriteFrame(-64, -72, 128, 144, 384, 288);
    AddSpriteFrame(-64, -72, 128, 144, 0, 432);
    AddSpriteFrame(-64, -72, 128, 144, 128, 432);
    AddSpriteFrame(-64, -72, 128, 144, 256, 432);
    AddSpriteFrame(-64, -72, 128, 144, 384, 432);
    AddSpriteFrame(-67, -75, 134, 150, 306, 873);
    AddSpriteFrame(-67, -95, 64, 20, 280, 680);
    AddSpriteFrame(-67, -95, 64, 20, 135, 617);
    AddSpriteFrame(0, 0, 64, 20, 280, 659);
    AddSpriteFrame(0, 0, 64, 20, 200, 617);
    AddSpriteFrame(0, 0, 64, 20, 345, 659);
    AddSpriteFrame(0, 0, 64, 20, 265, 617);
}

void O_TAttack_SLargeIcon::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        break;
        case 1:
        scriptEng.tempValue[0] = SCREEN_CENTERX;
        scriptEng.tempValue[0] -= 72;
        scriptEng.tempValue[0] <<= 16;
        if (self->XPos < scriptEng.tempValue[0]) {
            self->XPos += 0x100000;
            if (self->XPos > scriptEng.tempValue[0]) {
                self->XPos = scriptEng.tempValue[0];
            }
        } else {
            self->state = 0;
        }
        break;
        case 2:
        if (self->XPos > -0x480000) {
            self->XPos -= 0x100000;
            if (self->XPos < -0x480000) {
                self->XPos = -0x480000;
            }
        } else {
            self->state = 0;
        }
        break;
    }
}

void O_TAttack_SLargeIcon::ObjectDraw()
{
    Entity *self = Self();

    DrawSprite_Frame(8);
    DrawSprite_Frame(self->propertyValue);
    scriptEng.tempValue[0] = SCREEN_CENTERX;
    scriptEng.tempValue[0] -= 72;
    scriptEng.tempValue[0] <<= 16;
    scriptEng.tempValue[0] -= self->XPos;
    scriptEng.tempValue[0] >>= 16;
    scriptEng.tempValue[0] += SCREEN_CENTERX;
    scriptEng.tempValue[0] += 20;
    scriptEng.tempValue[1] = scriptEng.tempValue[0];
    scriptEng.tempValue[1] += 68;
}

#endif // RETRO_USE_NATIVE_OBJECTS

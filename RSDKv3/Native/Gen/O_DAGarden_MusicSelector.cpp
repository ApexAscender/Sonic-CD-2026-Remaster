#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_DAGarden_MusicSelector.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from MusicSelector.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_DAGarden_MusicSelector::ObjectStartup()
{
    LoadSpriteSheet("DAGarden/Objects.gif");
    AddSpriteFrame(-49, -4, 98, 8, 1, 577);
    AddSpriteFrame(-68, -4, 136, 8, 1, 586);
    AddSpriteFrame(-68, -4, 136, 8, 1, 595);
    AddSpriteFrame(-54, -4, 108, 8, 1, 604);
    AddSpriteFrame(-72, -4, 144, 8, 1, 613);
    AddSpriteFrame(-72, -4, 144, 8, 1, 622);
    AddSpriteFrame(-46, -4, 92, 8, 1, 631);
    AddSpriteFrame(-65, -4, 130, 8, 1, 640);
    AddSpriteFrame(-65, -4, 130, 8, 1, 649);
    AddSpriteFrame(-54, -4, 108, 8, 1, 658);
    AddSpriteFrame(-72, -4, 144, 8, 1, 667);
    AddSpriteFrame(-72, -4, 144, 8, 1, 676);
    AddSpriteFrame(-55, -4, 110, 8, 1, 685);
    AddSpriteFrame(-73, -4, 146, 8, 1, 694);
    AddSpriteFrame(-73, -4, 146, 8, 1, 703);
    AddSpriteFrame(-61, -4, 122, 8, 1, 712);
    AddSpriteFrame(-79, -4, 158, 8, 1, 721);
    AddSpriteFrame(-79, -4, 158, 8, 1, 730);
    AddSpriteFrame(-59, -4, 118, 8, 1, 739);
    AddSpriteFrame(-77, -4, 154, 8, 1, 748);
    AddSpriteFrame(-77, -4, 154, 8, 1, 757);
    AddSpriteFrame(-38, -4, 76, 8, 1, 766);
    AddSpriteFrame(-46, -4, 92, 8, 1, 775);
    AddSpriteFrame(-33, -4, 66, 8, 1, 784);
    AddSpriteFrame(-36, -4, 72, 8, 1, 793);
    AddSpriteFrame(-18, -4, 36, 8, 1, 802);
    AddSpriteFrame(-37, -4, 74, 8, 1, 811);
    AddSpriteFrame(-30, -4, 60, 8, 1, 820);
    AddSpriteFrame(-18, -4, 36, 8, 1, 829);
    AddSpriteFrame(-45, -4, 90, 8, 1, 838);
    AddSpriteFrame(-40, -4, 81, 8, 1, 847);
}

void O_DAGarden_MusicSelector::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        break;
        case 1:
        self->XPos -= 0xC0000;
        scriptEng.tempValue[0] = SCREEN_CENTERX;
        scriptEng.tempValue[0] <<= 16;
        if (self->XPos <= scriptEng.tempValue[0]) {
            self->XPos = scriptEng.tempValue[0];
            self->state = 0;
        }
        break;
        case 2:
        self->XPos -= 0xC0000;
        if (self->XPos < -0x600000) {
            scriptEng.tempValue[0] = SCREEN_XSIZE;
            scriptEng.tempValue[0] += 192;
            scriptEng.tempValue[0] <<= 16;
            self->XPos += scriptEng.tempValue[0];
            self->state = 1;
            if (self->frame < 30) {
                self->frame++;
            } else {
                self->frame = 0;
            }
        }
        break;
        case 3:
        self->XPos += 0xC0000;
        scriptEng.tempValue[0] = SCREEN_CENTERX;
        scriptEng.tempValue[0] <<= 16;
        if (self->XPos >= scriptEng.tempValue[0]) {
            self->XPos = scriptEng.tempValue[0];
            self->state = 0;
        }
        break;
        case 4:
        self->XPos += 0xC0000;
        scriptEng.tempValue[0] = SCREEN_XSIZE;
        scriptEng.tempValue[0] += 96;
        scriptEng.tempValue[0] <<= 16;
        if (self->XPos > scriptEng.tempValue[0]) {
            self->XPos -= scriptEng.tempValue[0];
            self->XPos -= 0x600000;
            self->state = 3;
            if (self->frame > 0) {
                self->frame--;
            } else {
                self->frame = 30;
            }
        }
        break;
    }
}

void O_DAGarden_MusicSelector::ObjectDraw()
{
    Entity *self = Self();

    DrawSprite_Frame(self->frame);
}

#endif // RETRO_USE_NATIVE_OBJECTS

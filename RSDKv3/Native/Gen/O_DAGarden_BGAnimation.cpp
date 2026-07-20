#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_DAGarden_BGAnimation.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from BGAnimation.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_DAGarden_BGAnimation::ObjectStartup()
{
    LoadSpriteSheet("DAGarden/Objects.gif");
    AddSpriteFrame(0, 0, 256, 192, 0, 0);
    AddSpriteFrame(256, 0, 256, 192, 0, 0);
    AddSpriteFrame(0, 0, 256, 192, 256, 0);
    AddSpriteFrame(256, 0, 256, 192, 256, 0);
    AddSpriteFrame(0, 0, 256, 192, 0, 192);
    AddSpriteFrame(256, 0, 256, 192, 0, 192);
    AddSpriteFrame(0, 0, 256, 192, 256, 192);
    AddSpriteFrame(256, 0, 256, 192, 256, 192);
    AddSpriteFrame(0, 0, 256, 192, 0, 384);
    AddSpriteFrame(256, 0, 256, 192, 0, 384);
    AddSpriteFrame(0, 0, 256, 192, 256, 384);
    AddSpriteFrame(256, 0, 256, 192, 256, 384);
    objectEntityList[31].type = TypeNameID("BG Animation");
    objectEntityList[31].XPos = 0;
    objectEntityList[31].YPos = 0x180000;
}

void O_DAGarden_BGAnimation::ObjectDraw()
{
    Entity *self = Self();

    if (self->drawOrder == 3) {
        switch (self->state) {
            case 0:
            DrawSprite_Frame(0);
            DrawSprite_Frame(1);
            self->values[0]++;
            if (self->values[0] > 480) {
                self->values[0] = 0;
                self->alpha = 0;
                self->inkEffect = 2;
                self->state++;
            }
            break;
            case 1:
            DrawSprite_Frame(0);
            DrawSprite_Frame(1);
            if (self->alpha < 248) {
                self->alpha += 4;
            } else {
                self->alpha = 255;
                self->state++;
            }
            DrawSpriteFX_Script(2, FX_INK, self->XPos, self->YPos);
            DrawSpriteFX_Script(3, FX_INK, self->XPos, self->YPos);
            break;
            case 2:
            DrawSprite_Frame(2);
            DrawSprite_Frame(3);
            self->values[0]++;
            if (self->values[0] > 480) {
                self->values[0] = 0;
                self->alpha = 0;
                self->state++;
            }
            break;
            case 3:
            DrawSprite_Frame(2);
            DrawSprite_Frame(3);
            if (self->alpha < 248) {
                self->alpha += 4;
            } else {
                self->alpha = 255;
                objectEntityList[objectLoop + 7].values[2] = 1;
                self->state++;
            }
            DrawSpriteFX_Script(4, FX_INK, self->XPos, self->YPos);
            DrawSpriteFX_Script(5, FX_INK, self->XPos, self->YPos);
            break;
            case 4:
            DrawSprite_Frame(4);
            DrawSprite_Frame(5);
            self->values[0]++;
            if (self->values[0] > 480) {
                self->values[0] = 0;
                self->alpha = 0;
                self->state++;
            }
            break;
            case 5:
            DrawSprite_Frame(4);
            DrawSprite_Frame(5);
            if (self->alpha < 248) {
                self->alpha += 4;
            } else {
                self->alpha = 255;
                self->state++;
            }
            DrawSpriteFX_Script(6, FX_INK, self->XPos, self->YPos);
            DrawSpriteFX_Script(7, FX_INK, self->XPos, self->YPos);
            break;
            case 6:
            DrawSprite_Frame(6);
            DrawSprite_Frame(7);
            self->values[0]++;
            if (self->values[0] > 480) {
                self->values[0] = 0;
                self->alpha = 0;
                self->state++;
            }
            break;
            case 7:
            DrawSprite_Frame(6);
            DrawSprite_Frame(7);
            if (self->alpha < 248) {
                self->alpha += 4;
            } else {
                self->alpha = 255;
                self->state++;
            }
            DrawSpriteFX_Script(8, FX_INK, self->XPos, self->YPos);
            DrawSpriteFX_Script(9, FX_INK, self->XPos, self->YPos);
            break;
            case 8:
            DrawSprite_Frame(8);
            DrawSprite_Frame(9);
            self->values[0]++;
            if (self->values[0] > 512) {
                self->values[0] = 0;
                self->alpha = 0;
                objectEntityList[objectLoop + 7].values[2] = 0;
                self->state++;
            }
            break;
            case 9:
            DrawSprite_Frame(8);
            DrawSprite_Frame(9);
            if (self->alpha < 248) {
                self->alpha += 2;
            } else {
                self->alpha = 255;
                self->state++;
            }
            DrawSpriteFX_Script(10, FX_INK, self->XPos, self->YPos);
            DrawSpriteFX_Script(11, FX_INK, self->XPos, self->YPos);
            break;
            case 10:
            DrawSprite_Frame(10);
            DrawSprite_Frame(11);
            self->values[0]++;
            if (self->values[0] > 480) {
                self->values[0] = 0;
                self->alpha = 0;
                self->state++;
            }
            break;
            case 11:
            DrawSprite_Frame(10);
            DrawSprite_Frame(11);
            if (self->alpha < 248) {
                self->alpha += 4;
            } else {
                self->alpha = 255;
                self->state = 0;
            }
            DrawSpriteFX_Script(0, FX_INK, self->XPos, self->YPos);
            DrawSpriteFX_Script(1, FX_INK, self->XPos, self->YPos);
            break;
        }
        drawListEntries[4].entityRefs[drawListEntries[4].listSize] = objectLoop;
        drawListEntries[4].listSize++;
        self->drawOrder = 4;
    } else {
        DrawRectangle(0, 0, SCREEN_XSIZE, 32, 0, 0, 0, 255);
        DrawRectangle(0, 208, SCREEN_XSIZE, 32, 0, 0, 0, 255);
        self->drawOrder = 3;
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_Invincibility.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from Invincibility.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_Invincibility::ObjectStartup()
{
    LoadSpriteSheet("Global/Items3.gif");
    AddSpriteFrame(-24, -24, 48, 48, 1, 1);
    AddSpriteFrame(-24, -24, 48, 48, 1, 50);
    AddSpriteFrame(-24, -24, 48, 48, 1, 99);
    AddSpriteFrame(-24, -24, 48, 48, 1, 148);
}

void O_Invincibility::ObjectDraw()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        self->values[0]++;
        if (self->values[0] > 3) {
            self->values[0] = 0;
            CreateTempObject(TypeNameID("Invincibility"), 0, pXPos(), pYPos());
            objectEntityList[scriptEng.arrayPosition[2]].state = 1;
            objectEntityList[scriptEng.arrayPosition[2]].inkEffect = 2;
            objectEntityList[scriptEng.arrayPosition[2]].alpha = 256;
            objectEntityList[scriptEng.arrayPosition[2]].drawOrder = 4;
            self->frame = GVar("Ring.Frame");
            self->frame &= 3;
            if (GVar("Warp.Timer") == 0) {
                DrawSprite_FrameXY(self->frame, pXPos(), pYPos());
            }
        }
        break;
        case 1:
        self->frame = GVar("Ring.Frame");
        self->frame &= 3;
        if (GVar("Warp.Timer") == 0) {
            DrawSpriteFX_Script(self->frame, FX_INK, self->XPos, self->YPos);
        }
        self->alpha -= 8;
        if (self->alpha == 128) {
            self->type = TypeNameID("Blank Object");
        }
        break;
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS

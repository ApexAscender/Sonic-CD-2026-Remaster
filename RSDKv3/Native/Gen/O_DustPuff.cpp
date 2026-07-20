#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_DustPuff.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from DustPuff.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_DustPuff::ObjectStartup()
{
    LoadSpriteSheet("Global/Items3.gif");
    AddSpriteFrame(-7, -11, 13, 14, 148, 129);
    AddSpriteFrame(-7, -11, 13, 14, 161, 137);
    AddSpriteFrame(-6, -11, 13, 14, 240, 233);
    AddSpriteFrame(-7, -11, 13, 14, 243, 177);
    AddSpriteFrame(-32, -10, 32, 10, 181, 183);
    AddSpriteFrame(-32, -12, 32, 12, 148, 198);
    AddSpriteFrame(-32, -16, 32, 16, 181, 194);
    AddSpriteFrame(-32, -18, 32, 18, 115, 192);
    AddSpriteFrame(-32, -20, 32, 20, 148, 177);
    AddSpriteFrame(-32, -21, 32, 21, 214, 177);
    AddSpriteFrame(-32, -23, 32, 23, 50, 232);
}

void O_DustPuff::ObjectDraw()
{
    Entity *self = Self();

    if (self->frame > 3) {
        activePlayer = self->propertyValue;
        self->direction = pDirection();
        self->XPos = pXPos();
        objectEntityList[objectLoop].YPos = (pCollisionBottom()) << 16;
        self->YPos += pYPos();
        activePlayer = 0;
        if (pAnimation() != GVar("ANI_SPINDASH")) {
            self->type = TypeNameID("Blank Object");
        } else {
            DrawSpriteFX_Script(self->frame, FX_FLIP, self->XPos, self->YPos);
        }
    } else {
        DrawSpriteFX_Script(self->frame, FX_FLIP, self->XPos, self->YPos);
    }
    switch (self->frame) {
        case 0:
        case 1:
        case 2:
        self->animationTimer++;
        if (self->animationTimer > 3) {
            self->frame++;
            self->animationTimer = 0;
        }
        break;
        case 3:
        self->animationTimer++;
        if (self->animationTimer > 3) {
            self->type = TypeNameID("Blank Object");
        }
        break;
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        self->animationTimer++;
        if (self->animationTimer > 1) {
            self->frame++;
            self->animationTimer = 0;
        }
        break;
        case 10:
        self->animationTimer++;
        if (self->animationTimer > 1) {
            self->frame = 4;
            self->animationTimer = 0;
        }
        break;
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R8_HotaruLaser.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from HotaruLaser.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R8_HotaruLaser::ObjectStartup()
{
    LoadSpriteSheet("R8/Objects3.gif");
    AddSpriteFrame(-12, -8, 24, 16, 146, 158);
    AddSpriteFrame(-12, -8, 24, 16, 171, 158);
    AddSpriteFrame(-4, -8, 8, 22, 196, 133);
}

void O_R8_HotaruLaser::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        self->YPos += 0x80000;
        ObjectTileCollision_Script(0, 0, 8, 0);
        if (CheckResult() == 1) {
            self->values[1] = self->YPos;
            self->state++;
        }
        break;
        case 1:
        if (self->values[0] < 2) {
            self->YPos += 0x80000;
            self->values[0]++;
        } else {
            self->type = TypeNameID("Blank Object");
        }
        break;
    }
}

void O_R8_HotaruLaser::ObjectPlayerInteraction()
{
    Entity *self = Self();

    scriptEng.arrayPosition[0] = self->values[2];
    if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Hotaru")) {
        PlayerObjectCollision(C_TOUCH, -4, -8, 4, 8);
        if (CheckResult() == 1) {
            CallScriptFunctionNamed("Player_Hit", scriptSub);
        }
    }
}

void O_R8_HotaruLaser::ObjectDraw()
{
    Entity *self = Self();

    DrawSprite_Frame(2);
    scriptEng.tempValue[0] = self->animationTimer;
    scriptEng.tempValue[0] >>= 1;
    DrawSprite_FrameXY(scriptEng.tempValue[0], self->XPos, self->values[1]);
    self->animationTimer++;
    self->animationTimer &= 3;
}

#endif // RETRO_USE_NATIVE_OBJECTS

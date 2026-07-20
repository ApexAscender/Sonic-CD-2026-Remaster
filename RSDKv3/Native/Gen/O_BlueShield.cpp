#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_BlueShield.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from BlueShield.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_BlueShield::ObjectStartup()
{
    if (playerListPos == 0) {
        LoadSpriteSheet("Global/Items2.gif");
    }
    if (playerListPos == 1) {
        LoadSpriteSheet("Global/Items2_t.gif");
    }
    AddSpriteFrame(-24, -24, 48, 48, 109, 196);
    AddSpriteFrame(0, 0, 0, 0, 109, 196);
    AddSpriteFrame(-24, -24, 48, 48, 158, 196);
    AddSpriteFrame(0, 0, 0, 0, 109, 196);
    AddSpriteFrame(-24, -24, 48, 48, 207, 196);
    AddSpriteFrame(0, 0, 0, 0, 109, 196);
}

void O_BlueShield::ObjectMain()
{
    Entity *self = Self();

    self->drawOrder = objectEntityList[objectLoop - 2].drawOrder;
    if (pState() == PlayerStateID("Player_State_Death")) {
        self->type = TypeNameID("Blank Object");
    }
    if (pState() == PlayerStateID("Player_State_Drown")) {
        self->type = TypeNameID("Blank Object");
    }
}

void O_BlueShield::ObjectDraw()
{
    Entity *self = Self();

    self->values[0]++;
    if (self->values[0] == 2) {
        self->values[0] = 0;
        self->frame++;
        if (self->frame > 5) {
            self->frame = 0;
        }
    }
    if (GVar("Warp.Timer") == 0) {
        if (pVisible() == 1) {
            DrawSpriteFX_Script(self->frame, FX_INK, pXPos(), pYPos());
        }
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS

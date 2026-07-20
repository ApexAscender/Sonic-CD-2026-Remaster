#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_FuturePost.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from FuturePost.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_FuturePost::ObjectStartup()
{
    LoadSpriteSheet("Global/Items.gif");
    AddSpriteFrame(-8, -24, 16, 48, 35, 204);
    AddSpriteFrame(-16, -40, 32, 16, 52, 239);
    AddSpriteFrame(-8, -40, 16, 16, 51, 183);
    AddSpriteFrame(-3, -40, 8, 16, 68, 183);
    AddSpriteFrame(-8, -40, 16, 16, 52, 200);
    AddSpriteFrame(-16, -40, 32, 16, 85, 239);
    AddSpriteFrame(-8, -40, 16, 16, 51, 183);
    AddSpriteFrame(-3, -40, 8, 16, 68, 183);
    AddSpriteFrame(-8, -40, 16, 16, 52, 200);
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Future Post")) {
            if (objectEntityList[scriptEng.arrayPosition[0]].propertyValue == 1) {
                objectEntityList[scriptEng.arrayPosition[0]].drawOrder = 1;
                objectEntityList[scriptEng.arrayPosition[0]].values[1] = 1;
            }
            if (GVar("Options.GameMode") == 2) {
                objectEntityList[scriptEng.arrayPosition[0]].type = TypeNameID("Blank Object");
            }
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_FuturePost::ObjectPlayerInteraction()
{
    Entity *self = Self();

    if (self->state == 0) {
        if (pCollisionPlane() == self->values[1]) {
            PlayerObjectCollision(C_TOUCH, -8, -24, 8, 32);
            if (CheckResult() == 1) {
                GVar("Warp.Destination") = 2;
                self->state = 1;
                self->priority = 1;
                self->frame = 1;
                PlaySfx(12, 0);
                HapticEffect_Script(20, 0, 0, 0);
            }
        }
    }
}

void O_FuturePost::ObjectDraw()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        DrawSprite_Frame(0);
        DrawSprite_Frame(1);
        break;
        case 1:
        DrawSprite_Frame(0);
        self->values[0]++;
        if (self->values[0] == 64) {
            self->values[0] = 0;
            self->state = 2;
            self->priority = 0;
        }
        DrawSprite_Frame(self->frame);
        scriptEng.tempValue[0] = self->values[0];
        scriptEng.tempValue[0] &= 1;
        self->frame += scriptEng.tempValue[0];
        if (self->frame > 8) {
            self->frame = 1;
        }
        break;
        case 2:
        DrawSprite_Frame(0);
        DrawSprite_Frame(5);
        break;
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R5_KWeb.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from KWeb.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R5_KWeb::ObjectStartup()
{
    LoadSpriteSheet("R5/Objects.gif");
    AddSpriteFrame(-12, -8, 24, 16, 69, 1);
    AddSpriteFrame(-12, -8, 24, 16, 94, 1);
}

void O_R5_KWeb::ObjectMain()
{
    Entity *self = Self();

    if (self->state == 0) {
        self->XPos += self->values[1];
        if (GetObjectOutOfBounds(objectLoop) == 1) {
            self->type = TypeNameID("Blank Object");
        } else {
            scriptEng.tempValue[0] = yScrollOffset;
            scriptEng.tempValue[0] -= 8;
            scriptEng.tempValue[0] <<= 16;
            if (self->YPos < scriptEng.tempValue[0]) {
                self->type = TypeNameID("Blank Object");
            }
        }
    } else {
        if (self->values[0] < 120) {
            self->values[0]++;
            if (pSpeed() > 0x4000) {
                pSpeed() = 0x4000;
            }
            if (pSpeed() < -0x4000) {
                pSpeed() = -0x4000;
            }
        } else {
            self->type = TypeNameID("Blank Object");
        }
    }
}

void O_R5_KWeb::ObjectPlayerInteraction()
{
    Entity *self = Self();

    PlayerObjectCollision(C_TOUCH, -6, -6, 6, 6);
    if (CheckResult() == 1) {
        self->state = 1;
    }
}

void O_R5_KWeb::ObjectDraw()
{
    Entity *self = Self();

    if (self->state == 1) {
        self->XPos = pXPos();
        self->YPos = pYPos();
    }
    scriptEng.tempValue[0] = self->frame;
    scriptEng.tempValue[0] /= 3;
    DrawSprite_Frame(scriptEng.tempValue[0]);
    self->frame++;
    self->frame %= 6;
}

#endif // RETRO_USE_NATIVE_OBJECTS

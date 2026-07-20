#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R1_BoostSpinner.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from BoostSpinner.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R1_BoostSpinner::ObjectStartup()
{
    LoadSpriteSheet("R1/Objects2.gif");
    AddSpriteFrame(-24, -24, 48, 48, 1, 82);
    AddSpriteFrame(-34, -24, 56, 48, 50, 82);
    AddSpriteFrame(-38, -24, 57, 48, 107, 82);
    AddSpriteFrame(-40, -24, 56, 48, 1, 131);
    AddSpriteFrame(-40, -24, 56, 48, 58, 131);
    AddSpriteFrame(-40, -24, 64, 48, 58, 180);
    AddSpriteFrame(-40, -24, 56, 48, 1, 180);
    AddSpriteFrame(-40, -24, 64, 48, 123, 180);
    AddSpriteFrame(-40, -24, 56, 48, 58, 131);
    AddSpriteFrame(-40, -24, 64, 48, 58, 180);
    AddSpriteFrame(-40, -24, 56, 48, 1, 180);
    AddSpriteFrame(-40, -24, 64, 48, 123, 180);
    AddSpriteFrame(-40, -24, 56, 48, 58, 131);
    AddSpriteFrame(-40, -24, 64, 48, 58, 180);
    AddSpriteFrame(-40, -24, 56, 48, 1, 180);
    AddSpriteFrame(-40, -24, 64, 48, 123, 180);
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Boost Spinner")) {
            objectEntityList[scriptEng.arrayPosition[0]].drawOrder = 4;
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_R1_BoostSpinner::ObjectPlayerInteraction()
{
    Entity *self = Self();

    if (self->state == 0) {
        if (self->frame == 3) {
            PlayerObjectCollision(C_TOUCH, 0, -24, 128, 8);
            if (CheckResult() == 1) {
                self->state = 1;
                self->values[2] = 4;
                HapticEffect_Script(30, 0, 0, 0);
            }
        }
    }
}

void O_R1_BoostSpinner::ObjectDraw()
{
    Entity *self = Self();

    scriptEng.tempValue[0] = self->values[0];
    scriptEng.tempValue[0] -= self->XPos;
    scriptEng.tempValue[0] >>= 20;
    self->frame = scriptEng.tempValue[0];
    if (self->frame > 3) {
        self->frame = 3;
    }
    if (self->state == 1) {
        DrawSprite_FrameXY(self->values[2], self->values[0], self->YPos);
        self->values[1]++;
        if (self->values[1] == 3) {
            self->values[1] = 0;
            self->values[2]++;
            if (self->values[2] == 16) {
                self->state = 0;
            }
        }
    } else {
        DrawSprite_FrameXY(self->frame, self->values[0], self->YPos);
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS

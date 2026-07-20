#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R6_FlipDoor.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from FlipDoor.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R6_FlipDoor::ObjectStartup()
{
    LoadSpriteSheet("R6/Objects.gif");
    AddSpriteFrame(-4, -32, 8, 64, 230, 1);
    AddSpriteFrame(-4, -32, 48, 48, 83, 34);
    AddSpriteFrame(-4, -32, 64, 8, 132, 34);
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Flip Door")) {
            objectEntityList[scriptEng.arrayPosition[0]].drawOrder = 4;
            objectEntityList[scriptEng.arrayPosition[0]].direction = objectEntityList[scriptEng.arrayPosition[0]].propertyValue;
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_R6_FlipDoor::ObjectMain()
{
    Entity *self = Self();

    if (self->frame == 0) {
        if (pObjectInteractions() == 1) {
            PlayerObjectCollision(C_BOX, -4, -32, 4, 32);
        }
    }
    if (self->direction == 0) {
        switch (self->state) {
            case 0:
            self->frame = 0;
            PlayerObjectCollision(C_TOUCH, -48, -32, 0, 32);
            if (CheckResult() == 1) {
                self->state = 1;
                PlaySfx(globalSFXCount + 9, 0);
            }
            break;
            case 1:
            if (self->values[0] < 4) {
                self->values[0]++;
                self->frame = 1;
            } else {
                self->values[0] = 0;
                self->state = 2;
            }
            break;
            case 2:
            self->frame = 2;
            PlayerObjectCollision(C_TOUCH, -48, -32, 64, 64);
            if (CheckResult() == 0) {
                self->state = 3;
            }
            break;
            case 3:
            if (self->values[0] < 4) {
                self->values[0]++;
                self->frame = 1;
            } else {
                self->values[0] = 0;
                self->state = 0;
            }
            break;
        }
    } else {
        switch (self->state) {
            case 0:
            self->frame = 0;
            PlayerObjectCollision(C_TOUCH, 0, -32, 48, 32);
            if (CheckResult() == 1) {
                self->state = 1;
                PlaySfx(globalSFXCount + 9, 0);
            }
            break;
            case 1:
            if (self->values[0] < 4) {
                self->values[0]++;
                self->frame = 1;
            } else {
                self->values[0] = 0;
                self->state = 2;
            }
            break;
            case 2:
            self->frame = 2;
            PlayerObjectCollision(C_TOUCH, -64, -32, 48, 64);
            if (CheckResult() == 0) {
                self->state = 3;
            }
            break;
            case 3:
            if (self->values[0] < 4) {
                self->values[0]++;
                self->frame = 1;
            } else {
                self->values[0] = 0;
                self->state = 0;
            }
            break;
        }
    }
}

void O_R6_FlipDoor::ObjectDraw()
{
    Entity *self = Self();

    DrawSpriteFX_Script(self->frame, FX_FLIP, self->XPos, self->YPos);
}

#endif // RETRO_USE_NATIVE_OBJECTS

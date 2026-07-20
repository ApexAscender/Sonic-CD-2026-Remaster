#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R5_CBSwitch.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from CBSwitch.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R5_CBSwitch::ObjectStartup()
{
    LoadSpriteSheet("R5/Objects.gif");
    if (objectEntityList[24].propertyValue == 1) {
        AddSpriteFrame(-4, -16, 32, 28, 1, 225);
        AddSpriteFrame(-8, -36, 16, 48, 206, 207);
        AddSpriteFrame(-28, -16, 32, 28, 34, 225);
    } else {
        AddSpriteFrame(-4, -16, 32, 28, 1, 18);
        AddSpriteFrame(-8, -36, 16, 48, 125, 1);
        AddSpriteFrame(-28, -16, 32, 28, 34, 18);
    }
}

void O_R5_CBSwitch::ObjectPlayerInteraction()
{
    Entity *self = Self();

    if (self->values[1] == 0) {
        if (pXPos() > self->XPos) {
            PlayerObjectCollision(C_TOUCH, 0, -12, 16, 16);
            self->values[1] = CheckResult();
            if (CheckResult() == 1) {
                switch (self->state) {
                    case 0:
                    case 3:
                    PlaySfx(globalSFXCount + 3, 0);
                    HapticEffect_Script(20, 0, 0, 0);
                    if (GVar("ConveyorBelt_Flag") == 0) {
                        GVar("ConveyorBelt_Flag") = 3;
                        self->state = 1;
                    } else {
                        GVar("ConveyorBelt_Flag") = 0;
                        self->state = 4;
                    }
                    break;
                }
            }
        } else {
            PlayerObjectCollision(C_TOUCH, -16, -12, 0, 16);
            self->values[1] = CheckResult();
            if (CheckResult() == 1) {
                switch (self->state) {
                    case 0:
                    case 3:
                    PlaySfx(globalSFXCount + 3, 0);
                    HapticEffect_Script(20, 0, 0, 0);
                    if (GVar("ConveyorBelt_Flag") == 0) {
                        GVar("ConveyorBelt_Flag") = 3;
                        self->state = 1;
                    } else {
                        GVar("ConveyorBelt_Flag") = 0;
                        self->state = 4;
                    }
                    break;
                }
            }
        }
    } else {
        if (pXPos() > self->XPos) {
            PlayerObjectCollision(C_TOUCH, 0, -12, 16, 16);
            self->values[1] = CheckResult();
        } else {
            PlayerObjectCollision(C_TOUCH, -16, -12, 0, 16);
            self->values[1] = CheckResult();
        }
    }
}

void O_R5_CBSwitch::ObjectDraw()
{
    Entity *self = Self();

    switch (self->state) {
        case 1:
        if (self->values[0] < 7) {
            self->values[0]++;
        } else {
            self->values[0] = 0;
            GVar("ConveyorBelt_Frame") = 1;
            self->state = 2;
        }
        break;
        case 2:
        if (self->values[0] < 7) {
            self->values[0]++;
        } else {
            self->values[0] = 0;
            GVar("ConveyorBelt_Frame") = 2;
            self->state = 3;
        }
        break;
        case 4:
        if (self->values[0] < 7) {
            self->values[0]++;
        } else {
            self->values[0] = 0;
            GVar("ConveyorBelt_Frame") = 1;
            self->state = 5;
        }
        break;
        case 5:
        if (self->values[0] < 7) {
            self->values[0]++;
        } else {
            self->values[0] = 0;
            GVar("ConveyorBelt_Frame") = 0;
            self->state = 0;
        }
        break;
    }
    DrawSprite_Frame(GVar("ConveyorBelt_Frame"));
}

#endif // RETRO_USE_NATIVE_OBJECTS

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R5_NoroNoro.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from NoroNoro.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R5_NoroNoro::ObjectStartup()
{
    LoadSpriteSheet("R5/Objects.gif");
    AddSpriteFrame(-16, -24, 32, 40, 1, 150);
    AddSpriteFrame(-16, -24, 32, 40, 34, 150);
    AddSpriteFrame(-16, -16, 32, 32, 66, 117);
    AddSpriteFrame(-16, -8, 16, 8, 67, 18);
}

void O_R5_NoroNoro::ObjectMain()
{
    Entity *self = Self();

    self->frame++;
    self->frame %= 60;
    switch (self->state) {
        case 0:
        ObjectTileCollision_Script(0, 0, 16, 0);
        if (CheckResult() == 1) {
            self->state = 1;
        } else {
            self->YPos += 0x10000;
        }
        break;
        case 1:
        self->XPos -= 0x4000;
        self->values[0]--;
        if (self->values[0] == -320) {
            self->state = 2;
            self->direction = 1;
        }
        ObjectTileGrip_Script(0, 0, 16, 0);
        if (CheckResult() == 0) {
            self->state = 2;
            self->values[0] = 0;
            self->direction = 1;
        }
        break;
        case 2:
        self->XPos += 0x4000;
        self->values[0]++;
        if (self->values[0] == 320) {
            self->state = 1;
            self->direction = 0;
        }
        ObjectTileGrip_Script(0, 0, 16, 0);
        if (CheckResult() == 0) {
            self->state = 1;
            self->values[0] = 0;
            self->direction = 0;
        }
        break;
    }
    CallScriptFunctionNamed("StageSetup_CheckGoodFuture", scriptSub);
}

void O_R5_NoroNoro::ObjectPlayerInteraction()
{
    Entity *self = Self();

    if (pGravity() == 1) {
        if (self->propertyValue == 0) {
            if (self->type == TypeNameID("Noro Noro")) {
                if (self->state > 0) {
                    PlayerObjectCollision(C_TOUCH, -96, -256, 96, 256);
                    if (CheckResult() == 1) {
                        if (self->values[1] == 0) {
                            PlaySfx(globalSFXCount + 1, 0);
                        }
                        self->values[1] = 1;
                    } else {
                        self->values[1] = 0;
                    }
                    if (self->values[1] == 1) {
                        PlayerObjectCollision(C_TOUCH, -8, -18, 8, -2);
                        if (CheckResult() == 1) {
                            CallScriptFunctionNamed("Player_Hit", scriptSub);
                        }
                    }
                }
            }
        }
        PlayerObjectCollision(C_TOUCH, -14, -14, 14, 14);
        if (CheckResult() == 1) {
            CallScriptFunctionNamed("Player_BadnikBreak", scriptSub);
        }
    } else {
        PlayerObjectCollision(C_TOUCH, -14, -14, 14, 14);
        if (CheckResult() == 1) {
            CallScriptFunctionNamed("Player_BadnikBreak", scriptSub);
        }
        if (self->propertyValue == 0) {
            if (self->type == TypeNameID("Noro Noro")) {
                if (self->state > 0) {
                    PlayerObjectCollision(C_TOUCH, -96, -256, 96, 256);
                    if (CheckResult() == 1) {
                        if (self->values[1] == 0) {
                            PlaySfx(globalSFXCount + 1, 0);
                        }
                        self->values[1] = 1;
                    } else {
                        self->values[1] = 0;
                    }
                    if (self->values[1] == 1) {
                        PlayerObjectCollision(C_TOUCH, -8, -18, 8, -2);
                        if (CheckResult() == 1) {
                            CallScriptFunctionNamed("Player_Hit", scriptSub);
                        }
                    }
                }
            }
        }
    }
}

void O_R5_NoroNoro::ObjectDraw()
{
    Entity *self = Self();

    if (self->propertyValue == 0) {
        DrawSpriteFX_Script(self->values[1], FX_FLIP, self->XPos, self->YPos);
    } else {
        DrawSpriteFX_Script(2, FX_FLIP, self->XPos, self->YPos);
    }
    if (self->frame > 29) {
        DrawSpriteFX_Script(3, FX_FLIP, self->XPos, self->YPos);
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS

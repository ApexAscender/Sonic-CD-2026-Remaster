#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R8_BladePole.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from BladePole.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R8_BladePole::ObjectStartup()
{
    LoadSpriteSheet("R8/Objects.gif");
    AddSpriteFrame(-16, -48, 32, 24, 67, 216);
    AddSpriteFrame(-12, -48, 24, 32, 34, 213);
    AddSpriteFrame(-16, -24, 32, 24, 67, 216);
    AddSpriteFrame(-12, -24, 24, 32, 34, 213);
    AddSpriteFrame(-32, -48, 64, 8, 50, 182);
    AddSpriteFrame(-24, -48, 48, 8, 50, 191);
    AddSpriteFrame(-16, -48, 32, 8, 99, 191);
    AddSpriteFrame(-4, -48, 8, 8, 115, 182);
    AddSpriteFrame(-16, -48, 32, 8, 222, 245);
    AddSpriteFrame(-24, -48, 48, 8, 1, 246);
    AddSpriteFrame(-32, -24, 64, 8, 50, 182);
    AddSpriteFrame(-24, -24, 48, 8, 50, 191);
    AddSpriteFrame(-16, -24, 32, 8, 99, 191);
    AddSpriteFrame(-4, -24, 8, 8, 115, 182);
    AddSpriteFrame(-16, -24, 32, 8, 222, 245);
    AddSpriteFrame(-24, -24, 48, 8, 1, 246);
    AddSpriteFrame(-8, -40, 16, 88, 222, 123);
    AddSpriteFrame(-8, -40, 16, 88, 239, 123);
}

void O_R8_BladePole::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        ObjectTileGrip_Script(0, 0, 48, 0);
        if (CheckResult() == 1) {
            self->state = 1;
            self->values[0] = -64;
        } else {
            self->YPos += 0x10000;
        }
        break;
        case 1:
        if (self->values[0] < 96) {
            self->values[0]++;
            self->XPos += 0x10000;
            ObjectTileGrip_Script(0, 0, 48, 0);
            if (CheckResult() == 0) {
                self->state = 2;
                self->values[0] = -64;
            }
        } else {
            self->state = 2;
            self->values[0] = -64;
        }
        break;
        case 2:
        if (self->values[0] < 96) {
            self->values[0]++;
            self->XPos -= 0x10000;
            ObjectTileGrip_Script(0, 0, 48, 0);
            if (CheckResult() == 0) {
                self->state = 1;
                self->values[0] = -64;
            }
        } else {
            self->state = 1;
            self->values[0] = -64;
        }
        break;
    }
    switch (self->frame) {
        case 0:
        case 2:
        if (self->animationTimer < 4) {
            self->animationTimer++;
        } else {
            self->animationTimer = 0;
            self->frame++;
        }
        break;
        case 1:
        if (self->animationTimer < 72) {
            self->animationTimer++;
        } else {
            self->animationTimer = 0;
            self->frame++;
        }
        break;
        case 3:
        if (self->animationTimer < 72) {
            self->animationTimer++;
        } else {
            self->animationTimer = 0;
            self->frame = 0;
        }
        break;
    }
}

void O_R8_BladePole::ObjectPlayerInteraction()
{
    Entity *self = Self();

    switch (self->frame) {
        case 1:
        PlayerObjectCollision(C_TOUCH, -28, -48, 28, -40);
        if (CheckResult() == 1) {
            CallScriptFunctionNamed("Player_Hit", scriptSub);
        }
        break;
        case 3:
        PlayerObjectCollision(C_TOUCH, -28, 16, 28, 24);
        if (CheckResult() == 1) {
            CallScriptFunctionNamed("Player_Hit", scriptSub);
        }
        break;
    }
}

void O_R8_BladePole::ObjectDraw()
{
    Entity *self = Self();

    scriptEng.tempValue[0] = self->values[0];
    scriptEng.tempValue[0] += 64;
    scriptEng.tempValue[0] %= 18;
    scriptEng.tempValue[0] /= 9;
    scriptEng.tempValue[0] += 16;
    DrawSprite_Frame(scriptEng.tempValue[0]);
    switch (self->frame) {
        case 0:
        case 2:
        DrawSprite_Frame(0);
        self->direction = 2;
        DrawSpriteFX_Script(2, FX_FLIP, self->XPos, self->YPos);
        break;
        case 1:
        scriptEng.tempValue[0] = self->animationTimer;
        scriptEng.tempValue[0] /= 3;
        scriptEng.tempValue[0] %= 6;
        scriptEng.tempValue[0] += 4;
        DrawSprite_Frame(scriptEng.tempValue[0]);
        DrawSpriteFX_Script(3, FX_FLIP, self->XPos, self->YPos);
        break;
        case 3:
        scriptEng.tempValue[0] = self->animationTimer;
        scriptEng.tempValue[0] /= 3;
        scriptEng.tempValue[0] %= 6;
        scriptEng.tempValue[0] += 10;
        DrawSprite_Frame(1);
        DrawSpriteFX_Script(scriptEng.tempValue[0], FX_FLIP, self->XPos, self->YPos);
        break;
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS

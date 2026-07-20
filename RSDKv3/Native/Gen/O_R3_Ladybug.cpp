#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R3_Ladybug.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from Ladybug.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R3_Ladybug::ObjectStartup()
{
    LoadSpriteSheet("R3/Objects.gif");
    AddSpriteFrame(-16, -16, 32, 32, 67, 134);
    AddSpriteFrame(-16, -16, 32, 32, 100, 134);
    AddSpriteFrame(-16, -16, 32, 32, 133, 134);
    AddSpriteFrame(-16, -16, 32, 32, 67, 101);
    AddSpriteFrame(-16, -16, 32, 32, 100, 101);
    AddSpriteFrame(-16, -16, 32, 32, 133, 101);
}

void O_R3_Ladybug::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        if (self->XPos > pXPos()) {
            self->direction = 0;
        } else {
            self->direction = 1;
        }
        scriptEng.tempValue[0] = self->values[0];
        scriptEng.tempValue[0] <<= 4;
        scriptEng.tempValue[1] = Sin512(scriptEng.tempValue[0]);
        scriptEng.tempValue[1] >>= 8;
        scriptEng.tempValue[1] += 24;
        ObjectTileGrip_Script(0, 0, scriptEng.tempValue[1], 0);
        PlayerObjectCollision(C_TOUCH, -64, -256, 64, 256);
        if (CheckResult() == 1) {
            self->state = 1;
            self->drawOrder = 4;
            if (self->XPos > pXPos()) {
                self->values[1] = 0x10000;
                self->direction = 1;
            } else {
                self->values[1] = -0x10000;
                self->direction = 0;
            }
        }
        break;
        case 1:
        scriptEng.tempValue[0] = self->values[0];
        scriptEng.tempValue[0] &= 3;
        if (scriptEng.tempValue[0] < 3) {
            self->XPos += self->values[1];
        }
        if (self->values[0] < 16) {
            ObjectTileGrip_Script(0, 0, 24, 0);
        } else {
            ObjectTileGrip_Script(0, 0, 23, 0);
        }
        if (CheckResult() == 0) {
            self->state = 2;
        }
        if (self->propertyValue == 0) {
            if (self->values[2] < 128) {
                self->values[2]++;
            } else {
                self->values[2] = 0;
                CreateTempObject(TypeNameID("Ladybug Bomb"), 0, self->XPos, self->YPos);
                objectEntityList[scriptEng.arrayPosition[2]].YPos += 0x140000;
            }
        }
        break;
        case 2:
        self->YPos -= 0x8000;
        break;
    }
    self->values[0]++;
    self->values[0] &= 31;
    self->frame++;
    self->frame %= 12;
    CallScriptFunctionNamed("StageSetup_CheckGoodFuture", scriptSub);
}

void O_R3_Ladybug::ObjectPlayerInteraction()
{
    PlayerObjectCollision(C_TOUCH, -16, -16, 16, 20);
    if (CheckResult() == 1) {
        CallScriptFunctionNamed("Player_BadnikBreak", scriptSub);
    }
}

void O_R3_Ladybug::ObjectDraw()
{
    Entity *self = Self();

    scriptEng.tempValue[0] = self->frame;
    scriptEng.tempValue[0] >>= 2;
    if (self->propertyValue == 1) {
        scriptEng.tempValue[0] += 3;
    }
    DrawSpriteFX_Script(scriptEng.tempValue[0], FX_FLIP, self->XPos, self->YPos);
}

#endif // RETRO_USE_NATIVE_OBJECTS

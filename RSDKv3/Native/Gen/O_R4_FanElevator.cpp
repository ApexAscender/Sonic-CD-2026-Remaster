#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R4_FanElevator.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from FanElevator.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R4_FanElevator::ObjectStartup()
{
    LoadSpriteSheet("R4/Objects3.gif");
    if (objectEntityList[24].propertyValue < 2) {
        AddSpriteFrame(-32, -32, 32, 48, 84, 46);
        AddSpriteFrame(-32, 16, 32, 16, 110, 144);
        AddSpriteFrame(-32, -32, 32, 48, 84, 95);
        AddSpriteFrame(-32, 16, 32, 16, 110, 161);
    } else {
        AddSpriteFrame(-32, -32, 32, 48, 84, 46);
        AddSpriteFrame(-32, 16, 32, 16, 126, 228);
        AddSpriteFrame(-32, -32, 32, 48, 84, 95);
        AddSpriteFrame(-32, 16, 32, 16, 158, 228);
    }
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Fan Elevator")) {
            objectEntityList[scriptEng.arrayPosition[0]].direction = 1;
            objectEntityList[scriptEng.arrayPosition[0]].priority = 3;
            objectEntityList[scriptEng.arrayPosition[0]].values[1] = objectEntityList[scriptEng.arrayPosition[0]].YPos;
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_R4_FanElevator::ObjectMain()
{
    Entity *self = Self();

    if (self->state == 0) {
        if (self->values[2] < 0x10000) {
            self->values[2] += 0x2000;
        }
        if (self->YPos == self->values[1]) {
            scriptEng.tempValue[0] = pYPos();
            scriptEng.tempValue[0] -= self->YPos;
            if (scriptEng.tempValue[0] < 0xA00000) {
                self->values[2] = 0;
            }
        } else {
            scriptEng.tempValue[0] = self->YPos;
            scriptEng.tempValue[0] -= self->values[1];
            if (scriptEng.tempValue[0] > 0x2A00000) {
                self->YPos = self->values[1];
            }
        }
    }
    self->YPos += self->values[2];
}

void O_R4_FanElevator::ObjectPlayerInteraction()
{
    Entity *self = Self();

    PlayerObjectCollision(C_PLATFORM, -32, -28, 32, 8);
    if (CheckResult() == 1) {
        self->values[2] = -0x20000;
        if (self->state == 0) {
            PlaySfx(globalSFXCount + 8, 0);
        }
        self->state = 1;
    } else {
        if (self->values[2] < 0) {
            self->values[2] = 0;
        }
        self->state = 0;
    }
}

void O_R4_FanElevator::ObjectDraw()
{
    Entity *self = Self();

    if (self->state == 0) {
        DrawSprite_Frame(0);
        DrawSprite_Frame(1);
        DrawSpriteFX_Script(0, FX_FLIP, self->XPos, self->YPos);
        DrawSpriteFX_Script(1, FX_FLIP, self->XPos, self->YPos);
    } else {
        DrawSprite_Frame(2);
        DrawSprite_Frame(3);
        DrawSpriteFX_Script(2, FX_FLIP, self->XPos, self->YPos);
        DrawSpriteFX_Script(3, FX_FLIP, self->XPos, self->YPos);
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS

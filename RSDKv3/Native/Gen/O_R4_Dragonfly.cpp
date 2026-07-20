#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R4_Dragonfly.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from Dragonfly.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R4_Dragonfly::ObjectStartup()
{
    LoadSpriteSheet("R4/Objects.gif");
    AddSpriteFrame(-29, -20, 64, 32, 18, 119);
    AddSpriteFrame(-29, -16, 64, 28, 83, 152);
    AddSpriteFrame(-29, -20, 64, 32, 18, 86);
    AddSpriteFrame(-29, -16, 64, 28, 18, 152);
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Dragonfly")) {
            objectEntityList[scriptEng.arrayPosition[0]].values[1] = objectEntityList[scriptEng.arrayPosition[0]].YPos;
            objectEntityList[scriptEng.arrayPosition[0]].values[0] = 1024;
            objectEntityList[scriptEng.arrayPosition[0]].values[0] >>= objectEntityList[scriptEng.arrayPosition[0]].propertyValue;
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_R4_Dragonfly::ObjectMain()
{
    Entity *self = Self();

    if (self->propertyValue == 0) {
        switch (self->state) {
            case 0:
            self->YPos = Sin512(self->values[0]);
            self->YPos <<= 11;
            self->YPos += self->values[1];
            self->XPos -= 0x10000;
            self->values[0] -= 8;
            if (self->values[0] == 0) {
                self->state = 1;
                self->direction = 1;
            }
            break;
            case 1:
            self->YPos = Sin512(self->values[0]);
            self->YPos = -self->YPos;
            self->YPos <<= 11;
            self->YPos += self->values[1];
            self->XPos += 0x10000;
            self->values[0] += 8;
            if (self->values[0] == 2048) {
                self->state = 0;
                self->direction = 0;
            }
            break;
        }
    } else {
        switch (self->state) {
            case 0:
            self->YPos = Sin512(self->values[0]);
            self->YPos <<= 11;
            self->YPos += self->values[1];
            self->XPos -= 0x8000;
            self->values[0] -= 2;
            if (self->values[0] == 0) {
                self->state = 1;
                self->direction = 1;
            }
            break;
            case 1:
            self->YPos = Sin512(self->values[0]);
            self->YPos = -self->YPos;
            self->YPos <<= 11;
            self->YPos += self->values[1];
            self->XPos += 0x8000;
            self->values[0] += 2;
            if (self->values[0] == 1024) {
                self->state = 0;
                self->direction = 0;
            }
            break;
        }
    }
    CallScriptFunctionNamed("StageSetup_CheckGoodFuture", scriptSub);
}

void O_R4_Dragonfly::ObjectPlayerInteraction()
{
    PlayerObjectCollision(C_TOUCH, -20, -10, 20, 10);
    if (CheckResult() == 1) {
        CallScriptFunctionNamed("Player_BadnikBreak", scriptSub);
    }
}

void O_R4_Dragonfly::ObjectDraw()
{
    Entity *self = Self();

    scriptEng.tempValue[0] = self->frame;
    scriptEng.tempValue[0] /= 3;
    if (self->propertyValue == 0) {
        DrawSpriteFX_Script(scriptEng.tempValue[0], FX_FLIP, self->XPos, self->YPos);
    } else {
        scriptEng.tempValue[0] += 2;
        DrawSpriteFX_Script(scriptEng.tempValue[0], FX_FLIP, self->XPos, self->YPos);
    }
    self->frame++;
    self->frame %= 6;
}

#endif // RETRO_USE_NATIVE_OBJECTS

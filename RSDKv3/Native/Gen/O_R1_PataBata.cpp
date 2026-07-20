#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R1_PataBata.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from PataBata.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R1_PataBata::ObjectStartup()
{
    LoadSpriteSheet("R1/Objects.gif");
    AddSpriteFrame(-16, -16, 32, 32, 1, 51);
    AddSpriteFrame(-16, -8, 32, 16, 1, 84);
    AddSpriteFrame(-16, -16, 32, 32, 117, 1);
    AddSpriteFrame(-16, -8, 32, 16, 1, 84);
    AddSpriteFrame(-16, -16, 32, 32, 1, 51);
    AddSpriteFrame(-16, -16, 32, 32, 150, 1);
    AddSpriteFrame(-16, -8, 32, 16, 1, 84);
    AddSpriteFrame(-16, -16, 32, 32, 183, 1);
    AddSpriteFrame(-16, -8, 32, 16, 1, 84);
    AddSpriteFrame(-16, -16, 32, 32, 150, 1);
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("PataBata")) {
            objectEntityList[scriptEng.arrayPosition[0]].values[1] = objectEntityList[scriptEng.arrayPosition[0]].YPos;
            objectEntityList[scriptEng.arrayPosition[0]].values[0] = 1024;
            objectEntityList[scriptEng.arrayPosition[0]].frame = objectEntityList[scriptEng.arrayPosition[0]].propertyValue;
            objectEntityList[scriptEng.arrayPosition[0]].frame *= 20;
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_R1_PataBata::ObjectMain()
{
    Entity *self = Self();

    if (self->propertyValue == 0) {
        self->frame++;
        if (self->frame > 39) {
            self->frame = 0;
        }
        switch (self->state) {
            case 0:
            self->YPos = Sin512(self->values[0]);
            self->YPos <<= 12;
            self->YPos += self->values[1];
            self->XPos -= 0x8000;
            self->values[0] -= 4;
            if (self->values[0] == 0) {
                self->state = 1;
                self->direction = 1;
            }
            break;
            case 1:
            self->YPos = Sin512(self->values[0]);
            self->YPos = -self->YPos;
            self->YPos <<= 12;
            self->YPos += self->values[1];
            self->XPos += 0x8000;
            self->values[0] += 4;
            if (self->values[0] == 2048) {
                self->state = 0;
                self->direction = 0;
            }
            break;
        }
    } else {
        self->frame++;
        if (self->frame > 39) {
            self->frame = 20;
        }
        switch (self->state) {
            case 0:
            self->YPos = Sin512(self->values[0]);
            self->YPos <<= 11;
            self->YPos += self->values[1];
            self->XPos -= 0x4000;
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
            self->XPos += 0x4000;
            self->values[0] += 2;
            if (self->values[0] == 2048) {
                self->state = 0;
                self->direction = 0;
            }
            break;
        }
    }
    CallScriptFunctionNamed("StageSetup_CheckGoodFuture", scriptSub);
}

void O_R1_PataBata::ObjectPlayerInteraction()
{
    PlayerObjectCollision(C_TOUCH, -14, -14, 14, 14);
    if (CheckResult() == 1) {
        CallScriptFunctionNamed("Player_BadnikBreak", scriptSub);
    }
}

void O_R1_PataBata::ObjectDraw()
{
    Entity *self = Self();

    if (self->propertyValue == 0) {
        scriptEng.tempValue[0] = self->frame;
        scriptEng.tempValue[0] >>= 3;
        DrawSpriteFX_Script(scriptEng.tempValue[0], FX_FLIP, self->XPos, self->YPos);
    } else {
        scriptEng.tempValue[0] = self->frame;
        scriptEng.tempValue[0] >>= 2;
        DrawSpriteFX_Script(scriptEng.tempValue[0], FX_FLIP, self->XPos, self->YPos);
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS

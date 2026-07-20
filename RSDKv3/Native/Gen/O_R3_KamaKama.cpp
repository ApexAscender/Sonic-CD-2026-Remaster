#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R3_KamaKama.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from KamaKama.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R3_KamaKama::ObjectStartup()
{
    LoadSpriteSheet("R3/Objects.gif");
    AddSpriteFrame(0, 4, 16, 16, 198, 119);
    AddSpriteFrame(0, 4, 16, 16, 215, 119);
    AddSpriteFrame(0, 4, 16, 16, 232, 119);
    AddSpriteFrame(0, 4, 16, 16, 215, 119);
    AddSpriteFrame(-10, -4, 24, 16, 215, 102);
    AddSpriteFrame(-10, -3, 24, 16, 215, 102);
    AddSpriteFrame(-16, -20, 16, 16, 198, 102);
    AddSpriteFrame(-16, -19, 16, 16, 198, 102);
    AddSpriteFrame(-16, -20, 16, 16, 198, 136);
    AddSpriteFrame(-16, -19, 16, 16, 198, 102);
    AddSpriteFrame(-10, -4, 24, 16, 232, 136);
    AddSpriteFrame(-10, -3, 24, 16, 198, 153);
    AddSpriteFrame(-16, -20, 16, 16, 215, 136);
    AddSpriteFrame(-16, -19, 16, 16, 240, 102);
    AddSpriteFrame(-16, -20, 16, 16, 198, 136);
    AddSpriteFrame(-16, -19, 16, 16, 240, 102);
    AddSpriteFrame(-22, -14, 24, 20, 173, 101);
    AddSpriteFrame(-22, -14, 24, 20, 173, 122);
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Kama Kama")) {
            objectEntityList[scriptEng.arrayPosition[0]].values[3] = objectEntityList[scriptEng.arrayPosition[0]].XPos;
            objectEntityList[scriptEng.arrayPosition[0]].values[4] = objectEntityList[scriptEng.arrayPosition[0]].YPos;
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_R3_KamaKama::ObjectMain()
{
    Entity *self = Self();

    self->values[1]++;
    self->values[1] &= 15;
    switch (self->state) {
        case 0:
        ObjectTileGrip_Script(0, 0, 19, 0);
        if (self->XPos > pXPos()) {
            self->direction = 0;
        } else {
            self->direction = 1;
        }
        PlayerObjectCollision(C_TOUCH, -96, -48, 96, 48);
        if (CheckResult() == 1) {
            self->state = 1;
            self->priority = 1;
            if (self->propertyValue == 0) {
                CreateTempObject(TypeNameID("Kama Kama Blade"), 24, self->XPos, self->YPos);
                objectEntityList[scriptEng.arrayPosition[2]].direction = self->direction;
                objectEntityList[scriptEng.arrayPosition[2]].YPos = ((objectEntityList[scriptEng.arrayPosition[2]].YPos >> 16) - (6)) << 16;
                objectEntityList[scriptEng.arrayPosition[2]].values[2] = objectLoop;
                if (self->direction == 0) {
                    objectEntityList[scriptEng.arrayPosition[2]].XPos = ((objectEntityList[scriptEng.arrayPosition[2]].XPos >> 16) - (8)) << 16;
                } else {
                    objectEntityList[scriptEng.arrayPosition[2]].XPos = ((objectEntityList[scriptEng.arrayPosition[2]].XPos >> 16) + (8)) << 16;
                }
                CreateTempObject(TypeNameID("Kama Kama Blade"), 56, self->XPos, self->YPos);
                objectEntityList[scriptEng.arrayPosition[2]].direction = self->direction;
                objectEntityList[scriptEng.arrayPosition[2]].YPos = ((objectEntityList[scriptEng.arrayPosition[2]].YPos >> 16) - (4)) << 16;
                objectEntityList[scriptEng.arrayPosition[2]].values[2] = objectLoop;
                if (self->direction == 0) {
                    objectEntityList[scriptEng.arrayPosition[2]].XPos = ((objectEntityList[scriptEng.arrayPosition[2]].XPos >> 16) - (16)) << 16;
                } else {
                    objectEntityList[scriptEng.arrayPosition[2]].XPos = ((objectEntityList[scriptEng.arrayPosition[2]].XPos >> 16) + (16)) << 16;
                }
            }
        }
        break;
        case 1:
        if (self->values[0] < 110) {
            self->values[0]++;
        } else {
            self->state = 2;
            self->values[0] = 0;
        }
        break;
        case 2:
        if (self->values[0] < 48) {
            self->values[0]++;
        } else {
            self->state = 3;
            self->values[0] = 0;
            self->frame = 0;
            if (self->direction == 0) {
                self->values[2] = -0x10000;
            } else {
                self->values[2] = 0x10000;
            }
            if (self->propertyValue > 0) {
                self->values[2] >>= 1;
            }
        }
        break;
        case 3:
        self->frame++;
        self->frame &= 31;
        self->XPos += self->values[2];
        ObjectTileGrip_Script(0, 0, 19, 0);
        if (CheckResult() == 0) {
            self->state = 4;
            self->values[0] = 60;
        }
        break;
        case 4:
        self->frame++;
        self->frame &= 31;
        if (self->values[0] > 0) {
            self->values[0]--;
        } else {
            self->state = 3;
            self->values[2] = -self->values[2];
            if (self->direction == 0) {
                self->direction = 1;
            } else {
                self->direction = 0;
            }
        }
        break;
    }
    if (GetObjectOutOfBounds(objectLoop) == 1) {
        self->priority = 0;
        self->state = 0;
        self->values[0] = 0;
        self->values[1] = 0;
        self->frame = 0;
        self->XPos = self->values[3];
        self->YPos = self->values[4];
    }
    CallScriptFunctionNamed("StageSetup_CheckGoodFuture", scriptSub);
}

void O_R3_KamaKama::ObjectPlayerInteraction()
{
    PlayerObjectCollision(C_TOUCH, -16, -16, 16, 20);
    if (CheckResult() == 1) {
        CallScriptFunctionNamed("Player_BadnikBreak", scriptSub);
    }
}

void O_R3_KamaKama::ObjectDraw()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        scriptEng.tempValue[0] = self->values[1];
        scriptEng.tempValue[0] >>= 3;
        DrawSpriteFX_Script(scriptEng.tempValue[0], FX_FLIP, self->XPos, self->YPos);
        if (self->propertyValue == 0) {
            scriptEng.tempValue[1] = scriptEng.tempValue[0];
            scriptEng.tempValue[1] += 4;
            DrawSpriteFX_Script(scriptEng.tempValue[1], FX_FLIP, self->XPos, self->YPos);
            scriptEng.tempValue[1] += 12;
            DrawSpriteFX_Script(scriptEng.tempValue[1], FX_FLIP, self->XPos, self->YPos);
            scriptEng.tempValue[1] -= 10;
            DrawSpriteFX_Script(scriptEng.tempValue[1], FX_FLIP, self->XPos, self->YPos);
        } else {
            scriptEng.tempValue[1] = scriptEng.tempValue[0];
            scriptEng.tempValue[1] += 10;
            DrawSpriteFX_Script(scriptEng.tempValue[1], FX_FLIP, self->XPos, self->YPos);
            scriptEng.tempValue[1] += 2;
            DrawSpriteFX_Script(scriptEng.tempValue[1], FX_FLIP, self->XPos, self->YPos);
        }
        break;
        case 1:
        scriptEng.tempValue[0] = self->values[1];
        scriptEng.tempValue[0] >>= 3;
        DrawSpriteFX_Script(scriptEng.tempValue[0], FX_FLIP, self->XPos, self->YPos);
        if (self->propertyValue == 0) {
            scriptEng.tempValue[1] = scriptEng.tempValue[0];
            scriptEng.tempValue[1] += 4;
            DrawSpriteFX_Script(scriptEng.tempValue[1], FX_FLIP, self->XPos, self->YPos);
            scriptEng.tempValue[1] += 2;
            DrawSpriteFX_Script(scriptEng.tempValue[1], FX_FLIP, self->XPos, self->YPos);
        } else {
            scriptEng.tempValue[1] = scriptEng.tempValue[0];
            scriptEng.tempValue[1] += 10;
            DrawSpriteFX_Script(scriptEng.tempValue[1], FX_FLIP, self->XPos, self->YPos);
            scriptEng.tempValue[1] += 2;
            DrawSpriteFX_Script(scriptEng.tempValue[1], FX_FLIP, self->XPos, self->YPos);
        }
        break;
        case 2:
        scriptEng.tempValue[0] = self->values[1];
        scriptEng.tempValue[0] >>= 3;
        DrawSpriteFX_Script(scriptEng.tempValue[0], FX_FLIP, self->XPos, self->YPos);
        if (self->propertyValue == 0) {
            scriptEng.tempValue[1] = scriptEng.tempValue[0];
            scriptEng.tempValue[1] += 4;
            DrawSpriteFX_Script(scriptEng.tempValue[1], FX_FLIP, self->XPos, self->YPos);
            scriptEng.tempValue[1] += 4;
            DrawSpriteFX_Script(scriptEng.tempValue[1], FX_FLIP, self->XPos, self->YPos);
        } else {
            scriptEng.tempValue[1] = scriptEng.tempValue[0];
            scriptEng.tempValue[1] += 10;
            DrawSpriteFX_Script(scriptEng.tempValue[1], FX_FLIP, self->XPos, self->YPos);
            scriptEng.tempValue[1] += 4;
            DrawSpriteFX_Script(scriptEng.tempValue[1], FX_FLIP, self->XPos, self->YPos);
        }
        break;
        case 3:
        case 4:
        scriptEng.tempValue[0] = self->frame;
        scriptEng.tempValue[0] >>= 3;
        DrawSpriteFX_Script(scriptEng.tempValue[0], FX_FLIP, self->XPos, self->YPos);
        scriptEng.tempValue[0] = self->values[1];
        scriptEng.tempValue[0] >>= 3;
        if (self->propertyValue == 0) {
            scriptEng.tempValue[1] = scriptEng.tempValue[0];
            scriptEng.tempValue[1] += 4;
            DrawSpriteFX_Script(scriptEng.tempValue[1], FX_FLIP, self->XPos, self->YPos);
            scriptEng.tempValue[1] += 2;
            DrawSpriteFX_Script(scriptEng.tempValue[1], FX_FLIP, self->XPos, self->YPos);
        } else {
            scriptEng.tempValue[1] = scriptEng.tempValue[0];
            scriptEng.tempValue[1] += 10;
            DrawSpriteFX_Script(scriptEng.tempValue[1], FX_FLIP, self->XPos, self->YPos);
            scriptEng.tempValue[1] += 2;
            DrawSpriteFX_Script(scriptEng.tempValue[1], FX_FLIP, self->XPos, self->YPos);
        }
        break;
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS

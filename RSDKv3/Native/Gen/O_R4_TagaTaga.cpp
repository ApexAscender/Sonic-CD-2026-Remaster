#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R4_TagaTaga.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from TagaTaga.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R4_TagaTaga::ObjectStartup()
{
    LoadSpriteSheet("R4/Objects.gif");
    AddSpriteFrame(-20, -12, 40, 24, 215, 86);
    AddSpriteFrame(-20, -12, 40, 24, 215, 111);
    AddSpriteFrame(-1, -10, 8, 8, 206, 52);
    AddSpriteFrame(3, -10, 8, 8, 206, 52);
    AddSpriteFrame(7, -9, 8, 8, 206, 52);
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Taga Taga")) {
            objectEntityList[scriptEng.arrayPosition[0]].values[1] = objectEntityList[scriptEng.arrayPosition[0]].XPos;
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_R4_TagaTaga::ObjectMain()
{
    Entity *self = Self();

    if (self->propertyValue == 0) {
        switch (self->state) {
            case 0:
            if (self->values[0] == 0) {
                self->state = 1;
                self->direction = 1;
                self->values[0] = 192;
            } else {
                self->values[0]--;
                self->XPos -= 0x10000;
            }
            break;
            case 1:
            if (self->values[0] == 0) {
                self->state = 0;
                self->direction = 0;
                self->values[0] = 192;
            } else {
                self->values[0]--;
                self->XPos += 0x10000;
            }
            break;
            case 2:
            if (self->values[0] < 120) {
                self->values[0]++;
                if (self->values[0] == 60) {
                    CreateTempObject(TypeNameID("Taga Spike"), 0, self->XPos, self->YPos);
                    objectEntityList[scriptEng.arrayPosition[2]].XPos -= 0x10000;
                    objectEntityList[scriptEng.arrayPosition[2]].YPos -= 0xA0000;
                    objectEntityList[scriptEng.arrayPosition[2]].values[1] = -0x20000;
                    objectEntityList[scriptEng.arrayPosition[2]].values[2] = -0x30000;
                    CreateTempObject(TypeNameID("Taga Spike"), 0, self->XPos, self->YPos);
                    objectEntityList[scriptEng.arrayPosition[2]].XPos += 0x30000;
                    objectEntityList[scriptEng.arrayPosition[2]].YPos -= 0xA0000;
                    objectEntityList[scriptEng.arrayPosition[2]].values[1] = 0x10000;
                    objectEntityList[scriptEng.arrayPosition[2]].values[2] = -0x30000;
                    CreateTempObject(TypeNameID("Taga Spike"), 0, self->XPos, self->YPos);
                    objectEntityList[scriptEng.arrayPosition[2]].XPos += 0x70000;
                    objectEntityList[scriptEng.arrayPosition[2]].YPos -= 0x90000;
                    objectEntityList[scriptEng.arrayPosition[2]].values[1] += 0x20000;
                    objectEntityList[scriptEng.arrayPosition[2]].values[2] = -0x30000;
                    PlaySfx(globalSFXCount + 5, 0);
                }
            } else {
                self->XPos -= 0x40000;
                if (GetObjectOutOfBounds(objectLoop) == 1) {
                    self->state = 4;
                    self->XPos = self->values[1];
                }
            }
            break;
            case 3:
            if (self->values[0] < 120) {
                self->values[0]++;
                if (self->values[0] == 60) {
                    CreateTempObject(TypeNameID("Taga Spike"), 0, self->XPos, self->YPos);
                    objectEntityList[scriptEng.arrayPosition[2]].XPos += 0x10000;
                    objectEntityList[scriptEng.arrayPosition[2]].YPos -= 0xA0000;
                    objectEntityList[scriptEng.arrayPosition[2]].values[1] = 0x20000;
                    objectEntityList[scriptEng.arrayPosition[2]].values[2] = -0x30000;
                    CreateTempObject(TypeNameID("Taga Spike"), 0, self->XPos, self->YPos);
                    objectEntityList[scriptEng.arrayPosition[2]].XPos -= 0x30000;
                    objectEntityList[scriptEng.arrayPosition[2]].YPos -= 0xA0000;
                    objectEntityList[scriptEng.arrayPosition[2]].values[1] = -0x10000;
                    objectEntityList[scriptEng.arrayPosition[2]].values[2] = -0x30000;
                    CreateTempObject(TypeNameID("Taga Spike"), 0, self->XPos, self->YPos);
                    objectEntityList[scriptEng.arrayPosition[2]].XPos -= 0x70000;
                    objectEntityList[scriptEng.arrayPosition[2]].YPos -= 0x90000;
                    objectEntityList[scriptEng.arrayPosition[2]].values[1] = -0x20000;
                    objectEntityList[scriptEng.arrayPosition[2]].values[2] = -0x30000;
                    PlaySfx(globalSFXCount + 5, 0);
                }
            } else {
                self->XPos += 0x40000;
                if (GetObjectOutOfBounds(objectLoop) == 1) {
                    self->state = 4;
                    self->XPos = self->values[1];
                }
            }
            break;
            case 4:
            if (GetObjectOutOfBounds(objectLoop) == 1) {
                self->state = 0;
                self->values[0] = 0;
                self->direction = 0;
                self->XPos = self->values[1];
            }
            break;
        }
    } else {
        switch (self->state) {
            case 0:
            if (self->values[0] == 0) {
                self->state = 1;
                self->direction = 1;
                self->values[0] = 384;
            } else {
                self->values[0]--;
                self->XPos -= 0x8000;
            }
            break;
            case 1:
            if (self->values[0] == 0) {
                self->state = 0;
                self->direction = 0;
                self->values[0] = 384;
            } else {
                self->values[0]--;
                self->XPos += 0x8000;
            }
            break;
            case 2:
            if (self->values[0] < 120) {
                self->values[0]++;
            } else {
                self->XPos -= 0x18000;
                if (GetObjectOutOfBounds(objectLoop) == 1) {
                    self->state = 4;
                    self->XPos = self->values[1];
                }
            }
            break;
            case 3:
            if (self->values[0] < 120) {
                self->values[0]++;
            } else {
                self->XPos += 0x18000;
                if (GetObjectOutOfBounds(objectLoop) == 1) {
                    self->state = 4;
                    self->XPos = self->values[1];
                }
            }
            break;
            case 4:
            if (GetObjectOutOfBounds(objectLoop) == 1) {
                self->state = 0;
                self->values[0] = 0;
                self->direction = 0;
                self->XPos = self->values[1];
            }
            break;
        }
    }
    CallScriptFunctionNamed("StageSetup_CheckGoodFuture", scriptSub);
}

void O_R4_TagaTaga::ObjectPlayerInteraction()
{
    Entity *self = Self();

    if (self->propertyValue == 0) {
        switch (self->state) {
            case 0:
            PlayerObjectCollision(C_TOUCH, -128, -32, 0, 8);
            if (CheckResult() == 1) {
                self->state = 2;
                self->values[0] = 0;
                self->priority = 1;
            }
            break;
            case 1:
            PlayerObjectCollision(C_TOUCH, 0, -32, 128, 8);
            if (CheckResult() == 1) {
                self->state = 3;
                self->values[0] = 0;
                self->priority = 1;
            }
            break;
        }
    }
    if (self->state < 4) {
        PlayerObjectCollision(C_TOUCH, -12, -8, 12, 8);
        if (CheckResult() == 1) {
            CallScriptFunctionNamed("Player_BadnikBreak", scriptSub);
        }
    }
}

void O_R4_TagaTaga::ObjectDraw()
{
    Entity *self = Self();

    if (self->propertyValue == 0) {
        if (self->state < 4) {
            scriptEng.tempValue[0] = self->frame;
            scriptEng.tempValue[0] >>= 5;
            DrawSpriteFX_Script(scriptEng.tempValue[0], FX_FLIP, self->XPos, self->YPos);
        }
        if (self->state < 2) {
            DrawSpriteFX_Script(2, FX_FLIP, self->XPos, self->YPos);
            DrawSpriteFX_Script(3, FX_FLIP, self->XPos, self->YPos);
            DrawSpriteFX_Script(4, FX_FLIP, self->XPos, self->YPos);
            self->frame++;
            self->frame &= 63;
        } else {
            if (self->values[0] < 60) {
                DrawSpriteFX_Script(2, FX_FLIP, self->XPos, self->YPos);
                DrawSpriteFX_Script(3, FX_FLIP, self->XPos, self->YPos);
                DrawSpriteFX_Script(4, FX_FLIP, self->XPos, self->YPos);
            }
        }
    } else {
        if (self->state < 4) {
            scriptEng.tempValue[0] = self->frame;
            scriptEng.tempValue[0] >>= 5;
            DrawSpriteFX_Script(scriptEng.tempValue[0], FX_FLIP, self->XPos, self->YPos);
        }
        if (self->state < 2) {
            self->frame++;
            self->frame &= 63;
        }
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS

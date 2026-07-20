#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R8_Hotaru.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from Hotaru.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R8_Hotaru::ObjectStartup()
{
    LoadSpriteSheet("R8/Objects3.gif");
    AddSpriteFrame(-12, -24, 24, 40, 96, 133);
    AddSpriteFrame(-12, -24, 24, 40, 121, 133);
    AddSpriteFrame(-12, -10, 24, 24, 146, 133);
    AddSpriteFrame(-12, -10, 24, 24, 171, 133);
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Hotaru")) {
            objectEntityList[scriptEng.arrayPosition[0]].alpha = 0;
            objectEntityList[scriptEng.arrayPosition[0]].inkEffect = 2;
            if (objectEntityList[24].propertyValue == 3) {
                objectEntityList[scriptEng.arrayPosition[0]].drawOrder = 2;
            }
            scriptEng.arrayPosition[1] = scriptEng.arrayPosition[0];
            scriptEng.arrayPosition[1]++;
            scriptEng.tempValue[0] = 0;
            while (scriptEng.tempValue[0] < 3) {
                objectEntityList[scriptEng.arrayPosition[1]].propertyValue = 1;
                objectEntityList[scriptEng.arrayPosition[1]].drawOrder = 4;
                objectEntityList[scriptEng.arrayPosition[1]].inkEffect = 2;
                objectEntityList[scriptEng.arrayPosition[1]].values[3] = (objectEntityList[scriptEng.arrayPosition[0]].XPos >> 16);
                objectEntityList[scriptEng.arrayPosition[1]].values[4] = (objectEntityList[scriptEng.arrayPosition[0]].YPos >> 16);
                objectEntityList[scriptEng.arrayPosition[1]].values[5] = (objectEntityList[scriptEng.arrayPosition[0]].XPos >> 16);
                objectEntityList[scriptEng.arrayPosition[1]].values[5] -= 112;
                objectEntityList[scriptEng.arrayPosition[1]].values[6] = (objectEntityList[scriptEng.arrayPosition[0]].XPos >> 16);
                objectEntityList[scriptEng.arrayPosition[1]].values[6] += 112;
                scriptEng.tempValue[0]++;
                scriptEng.arrayPosition[1]++;
            }
            scriptEng.arrayPosition[0] += 3;
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_R8_Hotaru::ObjectMain()
{
    Entity *self = Self();

    if (self->propertyValue == 0) {
        switch (self->state) {
            case 0:
            scriptEng.tempValue[0] = self->XPos;
            scriptEng.tempValue[0] -= 0x300000;
            if (pXPos() > scriptEng.tempValue[0]) {
                self->state++;
            }
            break;
            case 1:
            if (self->values[0] < 60) {
                self->values[0]++;
            } else {
                self->values[0] = 0;
                objectEntityList[objectLoop + 1].type = TypeNameID("Hotaru");
                objectEntityList[objectLoop + 1].XPos = self->XPos;
                objectEntityList[objectLoop + 1].XPos -= 0x500000;
                objectEntityList[objectLoop + 1].YPos = self->YPos;
                objectEntityList[objectLoop + 1].YPos += 0x300000;
                self->state++;
            }
            break;
            case 2:
            if (objectEntityList[objectLoop + 1].type != TypeNameID("Hotaru")) {
                self->state++;
            } else {
                if (objectEntityList[objectLoop + 1].state < 2) {
                    scriptEng.tempValue[0] = 176;
                } else {
                    scriptEng.tempValue[0] = 0;
                }
                scriptEng.tempValue[0] -= self->alpha;
                scriptEng.tempValue[0] >>= 3;
                self->alpha += scriptEng.tempValue[0];
            }
            break;
            case 3:
            if (self->values[0] < 60) {
                self->values[0]++;
            } else {
                self->values[0] = 0;
                objectEntityList[objectLoop + 2].type = TypeNameID("Hotaru");
                objectEntityList[objectLoop + 2].values[7] = 1;
                objectEntityList[objectLoop + 2].XPos = self->XPos;
                objectEntityList[objectLoop + 2].XPos -= 0x500000;
                objectEntityList[objectLoop + 2].YPos = self->YPos;
                objectEntityList[objectLoop + 2].YPos += 0x280000;
                objectEntityList[objectLoop + 3].type = TypeNameID("Hotaru");
                objectEntityList[objectLoop + 3].values[7] = 0;
                objectEntityList[objectLoop + 3].XPos = self->XPos;
                objectEntityList[objectLoop + 3].XPos += 0x500000;
                objectEntityList[objectLoop + 3].YPos = self->YPos;
                objectEntityList[objectLoop + 3].YPos += 0x280000;
                self->state++;
            }
            break;
            case 4:
            if (objectEntityList[objectLoop + 2].type != TypeNameID("Hotaru")) {
                if (objectEntityList[objectLoop + 3].type != TypeNameID("Hotaru")) {
                    scriptEng.tempValue[0] = 3840;
                    scriptEng.tempValue[0] -= SCREEN_CENTERX;
                    newXBoundary1 = scriptEng.tempValue[0];
                    scriptEng.tempValue[0] += SCREEN_XSIZE;
                    newXBoundary2 = scriptEng.tempValue[0];
                    self->priority = 1;
                    self->state++;
                } else {
                    if (objectEntityList[objectLoop + 3].state < 2) {
                        scriptEng.tempValue[0] = 176;
                    } else {
                        scriptEng.tempValue[0] = 0;
                    }
                    scriptEng.tempValue[0] -= self->alpha;
                    scriptEng.tempValue[0] >>= 3;
                    self->alpha += scriptEng.tempValue[0];
                }
            } else {
                if (objectEntityList[objectLoop + 2].state < 2) {
                    scriptEng.tempValue[0] = 176;
                } else {
                    scriptEng.tempValue[0] = 0;
                }
                scriptEng.tempValue[0] -= self->alpha;
                scriptEng.tempValue[0] >>= 3;
                self->alpha += scriptEng.tempValue[0];
            }
            break;
            case 5:
            if (objectEntityList[objectLoop + 2].state > 1) {
                if (objectEntityList[objectLoop + 3].state > 1) {
                    objectEntityList[objectLoop + 5].state = 1;
                }
            }
            if (objectEntityList[24].propertyValue == 3) {
                if (self->alpha < 176) {
                    self->alpha++;
                }
            } else {
                if (self->alpha > 0) {
                    self->alpha--;
                }
            }
            PlayerObjectCollision(C_TOUCH, -192, -256, 420, 256);
            if (CheckResult() == 0) {
                ResetObjectEntity(objectLoop, TypeNameID("Blank Object"), 0, 0, 0);
            }
            break;
        }
    } else {
        switch (self->state) {
            case 0:
            if (self->values[0] < 60) {
                self->values[0]++;
            } else {
                self->values[0] = 32;
                Hotaru_Set_Destination();
                self->state++;
            }
            self->alpha = self->values[0];
            self->alpha <<= 2;
            break;
            case 1:
            self->XPos += self->values[1];
            self->YPos += self->values[2];
            scriptEng.tempValue[0] = self->values[0];
            scriptEng.tempValue[0] &= 3;
            if (scriptEng.tempValue[0] == 0) {
                CreateTempObject(TypeNameID("Hotaru Trail"), 0, self->XPos, self->YPos);
                objectEntityList[scriptEng.arrayPosition[2]].inkEffect = 2;
                objectEntityList[scriptEng.arrayPosition[2]].alpha = 248;
            }
            self->values[0]--;
            if (self->values[0] == 0) {
                self->state++;
            }
            break;
            case 2:
            self->values[0]++;
            if (self->values[0] == 32) {
                self->values[0] = 0;
                self->state++;
                PlaySfx(globalSFXCount + 4, 0);
            }
            break;
            case 3:
            scriptEng.tempValue[0] = self->values[0];
            scriptEng.tempValue[0] &= 1;
            if (scriptEng.tempValue[0] == 0) {
                CreateTempObject(TypeNameID("Hotaru Laser"), 0, self->XPos, self->YPos);
                objectEntityList[scriptEng.arrayPosition[2]].values[2] = objectLoop;
            }
            self->values[0]++;
            if (self->values[0] == 20) {
                self->values[0] = 0;
                self->state++;
            }
            break;
            case 4:
            self->values[0]++;
            if (self->values[0] == 16) {
                self->values[0] = 32;
                Hotaru_Set_Destination();
                self->state = 1;
            }
            break;
        }
    }
}

void O_R8_Hotaru::ObjectPlayerInteraction()
{
    Entity *self = Self();

    if (self->propertyValue == 1) {
        if (self->state == 3) {
            if (self->values[0] > 1) {
                PlayerObjectCollision(C_TOUCH, -5, -5, 5, 5);
                if (CheckResult() == 1) {
                    CallScriptFunctionNamed("Player_BadnikBreak", scriptSub);
                }
            }
        }
    }
}

void O_R8_Hotaru::ObjectDraw()
{
    Entity *self = Self();

    if (self->propertyValue == 1) {
        switch (self->state) {
            case 0:
            DrawSpriteFX_Script(2, FX_INK, self->XPos, self->YPos);
            break;
            case 1:
            DrawSprite_Frame(2);
            break;
            case 2:
            scriptEng.tempValue[0] = self->values[0];
            scriptEng.tempValue[0] &= 3;
            scriptEng.tempValue[0] >>= 1;
            if (scriptEng.tempValue[0] == 0) {
                DrawSprite_Frame(3);
            } else {
                DrawSprite_Frame(0);
            }
            break;
            case 3:
            scriptEng.tempValue[0] = self->values[0];
            scriptEng.tempValue[0] &= 7;
            scriptEng.tempValue[0] >>= 2;
            DrawSprite_Frame(scriptEng.tempValue[0]);
            DrawSprite_Frame(3);
            break;
            case 4:
            scriptEng.tempValue[0] = self->values[0];
            scriptEng.tempValue[0] &= 3;
            scriptEng.tempValue[0] >>= 1;
            if (scriptEng.tempValue[0] == 0) {
                DrawSprite_Frame(3);
            } else {
                DrawSprite_Frame(0);
            }
            break;
        }
    } else {
        DrawRectangle(0, 0, SCREEN_XSIZE, SCREEN_YSIZE, 0, 0, 0, self->alpha);
    }
}

void O_R8_Hotaru::Hotaru_Set_Destination()
{
    Entity *self = Self();

    if (self->values[7] == 0) {
        scriptEng.tempValue[0] = 1;
    } else {
        scriptEng.tempValue[1] = pXPos();
        scriptEng.tempValue[1] >>= 16;
        scriptEng.tempValue[1] &= 0x7FF8;
        CheckResult() = (scriptEng.tempValue[1] < self->values[5]);
        scriptEng.tempValue[0] = CheckResult();
        CheckResult() = (scriptEng.tempValue[1] > self->values[6]);
        scriptEng.tempValue[0] |= CheckResult();
    }
    if (scriptEng.tempValue[0] == 1) {
        scriptEng.tempValue[2] = GVar("Oscillation");
        scriptEng.tempValue[2] &= 127;
        scriptEng.tempValue[2] += self->values[3];
        scriptEng.tempValue[2] -= 64;
        scriptEng.tempValue[3] = pXPos();
        scriptEng.tempValue[3] >>= 16;
        scriptEng.tempValue[3] *= 5;
        scriptEng.tempValue[3] &= 31;
        scriptEng.tempValue[3] += self->values[4];
    } else {
        scriptEng.tempValue[2] = scriptEng.tempValue[1];
        scriptEng.tempValue[3] = self->values[4];
        scriptEng.tempValue[3] -= 8;
    }
    self->values[1] = scriptEng.tempValue[2];
    self->values[1] -= (objectEntityList[objectLoop].XPos >> 16);
    self->values[1] <<= 11;
    self->values[2] = scriptEng.tempValue[3];
    self->values[2] -= (objectEntityList[objectLoop].YPos >> 16);
    self->values[2] <<= 11;
    self->values[7]++;
    self->values[7] &= 1;
}

const Native::NativeFunctionDef O_R8_Hotaru::funcs[1] = {
    { "Hotaru_Set_Destination", O_R8_Hotaru::Hotaru_Set_Destination },
};

#endif // RETRO_USE_NATIVE_OBJECTS

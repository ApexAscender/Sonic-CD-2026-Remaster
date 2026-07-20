#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_Transporter.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from Transporter.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_Transporter::ObjectStartup()
{
    LoadSpriteSheet("Global/Items3.gif");
    AddSpriteFrame(-40, -32, 80, 24, 175, 61);
    AddSpriteFrame(-40, -32, 80, 24, 175, 86);
    AddSpriteFrame(-40, -32, 80, 24, 175, 111);
    AddSpriteFrame(-40, -32, 80, 24, 175, 86);
    AddSpriteFrame(-6, -8, 12, 16, 149, 1);
    AddSpriteFrame(-6, -8, 12, 16, 162, 1);
    AddSpriteFrame(-6, -8, 12, 16, 149, 18);
    AddSpriteFrame(-6, -8, 12, 16, 162, 18);
    AddSpriteFrame(-22, -8, 12, 16, 149, 1);
    AddSpriteFrame(-22, -8, 12, 16, 162, 1);
    AddSpriteFrame(-22, -8, 12, 16, 149, 18);
    AddSpriteFrame(-22, -8, 12, 16, 162, 18);
    AddSpriteFrame(10, -8, 12, 16, 149, 1);
    AddSpriteFrame(10, -8, 12, 16, 162, 1);
    AddSpriteFrame(10, -8, 12, 16, 149, 18);
    AddSpriteFrame(10, -8, 12, 16, 162, 18);
    AddSpriteFrame(-40, 16, 80, 16, 175, 44);
    AddSpriteFrame(-40, -32, 80, 25, 175, 18);
    AddSpriteFrame(-40, 16, 80, 16, 175, 1);
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Transporter")) {
            objectEntityList[scriptEng.arrayPosition[0]].direction = 2;
            if (GVar("Transporter_Destroyed") == 1) {
                switch (objectEntityList[scriptEng.arrayPosition[0]].propertyValue) {
                    case 0:
                    objectEntityList[scriptEng.arrayPosition[0]].propertyValue = 2;
                    break;
                    case 1:
                    objectEntityList[scriptEng.arrayPosition[0]].propertyValue = 3;
                    break;
                }
            } else {
                if (objectEntityList[scriptEng.arrayPosition[0]].propertyValue == 0) {
                    objectEntityList[scriptEng.arrayPosition[0]].YPos = ((objectEntityList[scriptEng.arrayPosition[0]].YPos >> 16) - (16)) << 16;
                }
                objectEntityList[scriptEng.arrayPosition[0]].values[1] = objectEntityList[scriptEng.arrayPosition[0]].YPos;
                objectEntityList[scriptEng.arrayPosition[0]].values[3] = -0x2000;
            }
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_Transporter::ObjectMain()
{
    Entity *self = Self();

    if (self->propertyValue == 0) {
        switch (self->state) {
            case 0:
            self->values[2]++;
            if (self->values[2] == 32) {
                self->values[3] = 0x2000;
                self->values[2] = 0;
                self->state = 1;
            }
            break;
            case 1:
            self->values[2]++;
            if (self->values[2] == 32) {
                self->values[3] = -0x2000;
                self->values[2] = 0;
                self->state = 0;
            }
            break;
            case 2:
            scriptEng.tempValue[0] = rand() % 80;
            scriptEng.tempValue[0] -= 40;
            scriptEng.tempValue[0] <<= 16;
            scriptEng.tempValue[0] += self->XPos;
            scriptEng.tempValue[1] = rand() % 64;
            scriptEng.tempValue[1] -= 32;
            scriptEng.tempValue[1] <<= 16;
            scriptEng.tempValue[1] += self->YPos;
            CreateTempObject(TypeNameID("Explosion"), 0, scriptEng.tempValue[0], scriptEng.tempValue[1]);
            scriptEng.tempValue[0] = self->values[2];
            scriptEng.tempValue[0] &= 3;
            if (scriptEng.tempValue[0] == 0) {
                PlaySfx(22, 0);
            }
            self->values[2]++;
            if (self->values[2] == 60) {
                self->priority = 0;
                self->values[2] = 0;
                self->state = 0;
                self->propertyValue = 2;
                objectEntityList[objectLoop].YPos = ((objectEntityList[objectLoop].YPos >> 16) + (16)) << 16;
                PlaySfx(21, 0);
            }
            break;
        }
    }
}

void O_Transporter::ObjectPlayerInteraction()
{
    Entity *self = Self();

    if (self->propertyValue == 0) {
        if (self->state < 2) {
            CheckResult() = (pAnimation() == GVar("ANI_JUMPING"));
            scriptEng.tempValue[0] = CheckResult();
            if (scriptEng.tempValue[0] == 1) {
                PlayerObjectCollision(C_TOUCH, -38, -32, 38, 32);
                if (CheckResult() == 1) {
                    self->state = 2;
                    self->YPos = self->values[1];
                    GVar("Transporter_Destroyed") = 1;
                    GVar("Good_Future") = 1;
                    self->priority = 1;
                    GVar("Player.Score") += 1500;
                    if (actID < 3) {
                        scriptEng.tempValue[0] = stageListPosition;
                        scriptEng.tempValue[0] /= 10;
                        scriptEng.tempValue[0] <<= 1;
                        scriptEng.tempValue[0] += actID;
                        scriptEng.tempValue[0]--;
                        GVar("Good_Future_List") = (1) ? (GVar("Good_Future_List") | (1 << scriptEng.tempValue[0])) : (GVar("Good_Future_List") & ~(1 << scriptEng.tempValue[0]));
                    }
                    if (playerListPos == 0) {
                        if (debugMode == 0) {
                            if (GVar("Good_Future_List") > 16382) {
                                if (GVar("MetalSonic_List") > 11) {
                                    SetAchievement(11, 100);
                                }
                            }
                        }
                    }
                    HapticEffect_Script(90, 0, 0, 0);
                }
            } else {
                PlayerObjectCollision(C_BOX, -38, -32, 38, 36);
                if (CheckResult() == 1) {
                    pYPos() += self->values[3];
                }
            }
        }
    }
}

void O_Transporter::ObjectDraw()
{
    Entity *self = Self();

    switch (self->propertyValue) {
        case 0:
        if (self->state < 2) {
            self->YPos += self->values[3];
            DrawSprite_Frame(self->frame);
            DrawSpriteFX_Script(self->frame, FX_FLIP, self->XPos, self->YPos);
            scriptEng.tempValue[0] = self->frame;
            scriptEng.tempValue[0] += 4;
            DrawSprite_Frame(scriptEng.tempValue[0]);
            scriptEng.tempValue[0] += 4;
            DrawSprite_Frame(scriptEng.tempValue[0]);
            scriptEng.tempValue[0] += 4;
            DrawSprite_Frame(scriptEng.tempValue[0]);
            self->values[0]++;
            if (self->values[0] > 3) {
                self->values[0] = 0;
                self->frame++;
                if (self->frame > 3) {
                    self->frame = 0;
                }
            }
        }
        break;
        case 1:
        DrawSprite_Frame(17);
        DrawSpriteFX_Script(17, FX_FLIP, self->XPos, self->YPos);
        break;
        case 2:
        DrawSprite_Frame(16);
        break;
        case 3:
        DrawSprite_Frame(18);
        break;
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS

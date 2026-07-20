#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_MSProjector.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from MSProjector.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_MSProjector::ObjectStartup()
{
    LoadSpriteSheet("Global/Items3.gif");
    scriptEng.tempValue[0] = objectScriptList[objectEntityList[objectLoop].type].spriteSheetID;
    AddSpriteFrame(-12, -12, 24, 24, 150, 86);
    AddSpriteFrame(-29, -10, 16, 8, 158, 111);
    AddSpriteFrame(-29, -10, 16, 8, 158, 120);
    AddSpriteFrame(-108, -28, 40, 40, 175, 136);
    AddSpriteFrame(-108, -28, 40, 40, 216, 136);
    scriptEng.tempValue[2] = stageListPosition;
    if (scriptEng.tempValue[2] >= 70) {
        if (scriptEng.tempValue[2] <= 77) {
            scriptEng.tempValue[2] -= 70;
        } else {
            if (scriptEng.tempValue[2] <= 95) {
                scriptEng.tempValue[2] -= 68;
            } else {
                if (scriptEng.tempValue[2] <= 133) {
                    scriptEng.tempValue[2] -= 56;
                }
            }
        }
    }
    scriptEng.tempValue[2] /= 10;
    switch (scriptEng.tempValue[2]) {
        case 0:
        case 3:
        scriptEng.tempValue[3] = 8;
        AddSpriteFrame(-112, -3, 24, 16, 150, 52);
        AddSpriteFrame(-112, -3, 24, 16, 150, 69);
        AddSpriteFrame(-8, -8, 16, 16, 240, 199);
        AddSpriteFrame(-8, -8, 16, 16, 240, 216);
        break;
        case 1:
        scriptEng.tempValue[3] = 8;
        LoadSpriteSheet("R3/Objects3.gif");
        AddSpriteFrame(-108, -11, 16, 24, 132, 35);
        AddSpriteFrame(-112, -3, 24, 16, 149, 26);
        AddSpriteFrame(-8, -8, 16, 16, 132, 1);
        AddSpriteFrame(-8, -8, 16, 16, 132, 18);
        break;
        case 2:
        scriptEng.tempValue[3] = 4;
        LoadSpriteSheet("R4/Objects3.gif");
        AddSpriteFrame(-8, -12, 16, 24, 1, 92);
        AddSpriteFrame(-8, -12, 16, 24, 18, 92);
        AddSpriteFrame(-8, -12, 16, 24, 1, 67);
        AddSpriteFrame(-8, -12, 16, 24, 18, 67);
        break;
        case 4:
        scriptEng.tempValue[3] = 8;
        LoadSpriteSheet("R6/Objects3.gif");
        AddSpriteFrame(-112, -3, 24, 16, 1, 201);
        AddSpriteFrame(-112, -3, 24, 16, 26, 201);
        AddSpriteFrame(-12, -8, 24, 16, 1, 218);
        AddSpriteFrame(-12, -8, 24, 16, 26, 218);
        break;
        case 5:
        scriptEng.tempValue[3] = 8;
        LoadSpriteSheet("R7/Objects3.gif");
        AddSpriteFrame(-108, -11, 16, 24, 1, 192);
        AddSpriteFrame(-112, -3, 24, 16, 18, 158);
        AddSpriteFrame(-8, -8, 16, 16, 1, 158);
        AddSpriteFrame(-8, -8, 16, 16, 1, 175);
        break;
        case 6:
        scriptEng.tempValue[3] = 8;
        LoadSpriteSheet("R8/Objects2.gif");
        AddSpriteFrame(-112, -3, 24, 16, 1, 234);
        AddSpriteFrame(-112, -3, 24, 16, 26, 234);
        AddSpriteFrame(-8, -8, 16, 16, 143, 110);
        AddSpriteFrame(-8, -8, 16, 16, 143, 127);
        break;
    }
    scriptEng.tempValue[1] = objectScriptList[objectEntityList[objectLoop].type].spriteSheetID;
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("MSProjector")) {
            objectEntityList[scriptEng.arrayPosition[0]].values[4] = scriptEng.tempValue[0];
            objectEntityList[scriptEng.arrayPosition[0]].values[5] = scriptEng.tempValue[1];
            objectEntityList[scriptEng.arrayPosition[0]].values[6] = scriptEng.tempValue[3];
            if (GVar("MetalSonic_Destroyed") == 1) {
                objectEntityList[scriptEng.arrayPosition[0]].type = TypeNameID("Blank Object");
            }
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_MSProjector::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        self->values[0]++;
        if (self->values[0] == 16) {
            self->values[0] = 0;
            self->state = 1;
        }
        self->values[1] = self->values[0];
        self->values[1] &= 3;
        self->frame++;
        if (self->frame == 56) {
            self->frame = 0;
        }
        break;
        case 1:
        self->values[0]++;
        if (self->values[0] == 12) {
            self->values[0] = 0;
            self->state = 0;
        }
        self->values[1] = self->values[0];
        self->values[1] %= 3;
        self->frame++;
        if (self->frame == 56) {
            self->frame = 0;
        }
        break;
        case 2:
        scriptEng.tempValue[0] = self->values[0];
        scriptEng.tempValue[0] &= 3;
        if (scriptEng.tempValue[0] == 0) {
            scriptEng.tempValue[0] = rand() % 32;
            scriptEng.tempValue[0] -= 16;
            scriptEng.tempValue[0] <<= 16;
            scriptEng.tempValue[0] += self->XPos;
            scriptEng.tempValue[1] = rand() % 32;
            scriptEng.tempValue[1] -= 16;
            scriptEng.tempValue[1] <<= 16;
            scriptEng.tempValue[1] += self->YPos;
            CreateTempObject(TypeNameID("Explosion"), 0, scriptEng.tempValue[0], scriptEng.tempValue[1]);
            objectEntityList[scriptEng.arrayPosition[2]].drawOrder = 4;
            PlaySfx(22, 0);
        }
        self->values[0]++;
        if (self->values[0] == 60) {
            ResetObjectEntity(objectLoop, TypeNameID("Blank Object"), 0, self->XPos, self->YPos);
        }
        break;
    }
}

void O_MSProjector::ObjectPlayerInteraction()
{
    Entity *self = Self();

    if (self->state < 2) {
        CheckResult() = (pAnimation() == GVar("ANI_JUMPING"));
        scriptEng.tempValue[0] = CheckResult();
        if (scriptEng.tempValue[0] == 1) {
            PlayerObjectCollision(C_TOUCH, -13, -13, 13, 13);
            if (CheckResult() == 1) {
                self->values[0] = 0;
                GVar("MetalSonic_Destroyed") = 1;
                self->priority = 1;
                self->state = 2;
                GVar("MetalSonic_List")++;
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
            if (pGravity() == 1) {
                PlayerObjectCollision(C_BOX, -12, -12, 12, 12);
            }
        } else {
            PlayerObjectCollision(C_BOX, -12, -12, 12, 12);
        }
    }
}

void O_MSProjector::ObjectDraw()
{
    Entity *self = Self();

    objectScriptList[objectEntityList[objectLoop].type].spriteSheetID = self->values[4];
    DrawSprite_Frame(0);
    if (self->state < 2) {
        self->values[3]++;
        self->values[3] &= 31;
        scriptEng.tempValue[2] = self->values[3];
        scriptEng.tempValue[2] >>= 4;
        scriptEng.tempValue[2] += 7;
        self->values[2] += self->values[6];
        self->values[2] &= 511;
        scriptEng.tempValue[0] = Cos512(self->values[2]);
        scriptEng.tempValue[1] = Sin512(self->values[2]);
        if (scriptEng.tempValue[1] < 0) {
            self->direction = 0;
        } else {
            self->direction = 1;
        }
        scriptEng.tempValue[0] <<= 12;
        scriptEng.tempValue[1] <<= 11;
        scriptEng.tempValue[0] += self->XPos;
        scriptEng.tempValue[1] += self->YPos;
        scriptEng.tempValue[0] -= 0x580000;
        scriptEng.tempValue[1] -= 0x180000;
        scriptEng.tempValue[3] = self->values[0];
        scriptEng.tempValue[3] &= 1;
        if (scriptEng.tempValue[3] == 0) {
            scriptEng.tempValue[3] = self->values[0];
            scriptEng.tempValue[3] &= 3;
            scriptEng.tempValue[3] >>= 1;
            scriptEng.tempValue[3]++;
            DrawSprite_Frame(scriptEng.tempValue[3]);
        }
        if (self->values[1] < 2) {
            if (self->values[6] == 8) {
                if (self->frame < 28) {
                    objectScriptList[objectEntityList[objectLoop].type].spriteSheetID = self->values[5];
                    DrawSprite_Frame(5);
                    objectScriptList[objectEntityList[objectLoop].type].spriteSheetID = self->values[4];
                    DrawSprite_Frame(3);
                } else {
                    objectScriptList[objectEntityList[objectLoop].type].spriteSheetID = self->values[5];
                    DrawSprite_Frame(6);
                    objectScriptList[objectEntityList[objectLoop].type].spriteSheetID = self->values[4];
                    DrawSprite_Frame(4);
                }
                objectScriptList[objectEntityList[objectLoop].type].spriteSheetID = self->values[5];
                DrawSpriteFX_Script(scriptEng.tempValue[2], FX_FLIP, scriptEng.tempValue[0], scriptEng.tempValue[1]);
            } else {
                objectScriptList[objectEntityList[objectLoop].type].spriteSheetID = self->values[4];
                if (self->frame < 28) {
                    DrawSprite_Frame(3);
                } else {
                    DrawSprite_Frame(4);
                }
                objectScriptList[objectEntityList[objectLoop].type].spriteSheetID = self->values[5];
                DrawSpriteFX_Script(scriptEng.tempValue[2], FX_FLIP, scriptEng.tempValue[0], scriptEng.tempValue[1]);
                scriptEng.tempValue[4] = self->values[2];
                scriptEng.tempValue[4] += 320;
                scriptEng.tempValue[4] &= 511;
                scriptEng.tempValue[0] = Cos512(scriptEng.tempValue[4]);
                scriptEng.tempValue[1] = Sin512(scriptEng.tempValue[4]);
                if (scriptEng.tempValue[1] < 0) {
                    self->direction = 0;
                } else {
                    self->direction = 1;
                }
                scriptEng.tempValue[0] <<= 12;
                scriptEng.tempValue[1] <<= 11;
                scriptEng.tempValue[0] += self->XPos;
                scriptEng.tempValue[1] += self->YPos;
                scriptEng.tempValue[0] -= 0x600000;
                scriptEng.tempValue[1] -= 0x180000;
                scriptEng.tempValue[2] -= 2;
                DrawSpriteFX_Script(scriptEng.tempValue[2], FX_FLIP, scriptEng.tempValue[0], scriptEng.tempValue[1]);
            }
        }
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS

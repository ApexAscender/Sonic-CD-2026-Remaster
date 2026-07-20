#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R8_EggMobile.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from EggMobile.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R8_EggMobile::ObjectStartup()
{
    LoadSpriteSheet("R8/Objects3.gif");
    AddSpriteFrame(-36, -60, 88, 112, 1, 1);
    AddSpriteFrame(-36, -36, 72, 72, 1, 114);
    AddSpriteFrame(-36, -36, 32, 16, 90, 1);
    AddSpriteFrame(-36, -36, 32, 16, 123, 1);
    AddSpriteFrame(-18, -28, 36, 32, 90, 67);
    AddSpriteFrame(-18, -28, 36, 32, 127, 67);
    AddSpriteFrame(-18, -28, 36, 32, 164, 67);
    AddSpriteFrame(-18, -28, 36, 32, 201, 67);
    AddSpriteFrame(-22, -28, 44, 32, 166, 100);
    AddSpriteFrame(-22, -28, 44, 32, 211, 100);
    AddSpriteFrame(-12, -28, 32, 32, 133, 100);
    AddSpriteFrame(-8, 28, 25, 17, 26, 237);
    AddSpriteFrame(-8, 28, 25, 17, 52, 237);
    AddSpriteFrame(-8, 28, 25, 17, 78, 237);
    AddSpriteFrame(-8, 28, 25, 17, 104, 237);
    AddSpriteFrame(-8, 28, 25, 17, 112, 219);
    AddSpriteFrame(-30, 23, 12, 11, 42, 225);
    AddSpriteFrame(-30, 23, 12, 11, 55, 225);
    AddSpriteFrame(-30, 23, 12, 11, 68, 225);
    AddSpriteFrame(-30, 23, 12, 11, 81, 225);
    AddSpriteFrame(-30, 23, 12, 11, 94, 225);
    AddSpriteFrame(49, -9, 2, 2, 27, 247);
    AddSpriteFrame(49, -9, 2, 2, 53, 247);
    AddSpriteFrame(49, -9, 2, 2, 79, 247);
    AddSpriteFrame(49, -9, 2, 2, 105, 247);
    AddSpriteFrame(49, -9, 2, 2, 113, 229);
    AddSpriteFrame(-19, -19, 8, 20, 42, 204);
    AddSpriteFrame(-19, -19, 8, 20, 51, 204);
    AddSpriteFrame(-19, -19, 8, 20, 60, 204);
    AddSpriteFrame(-19, -19, 8, 20, 69, 204);
    AddSpriteFrame(-19, -19, 8, 20, 78, 204);
    AddSpriteFrame(17, -13, 4, 10, 87, 206);
    AddSpriteFrame(17, -13, 4, 10, 92, 206);
    AddSpriteFrame(17, -13, 4, 10, 97, 206);
    AddSpriteFrame(17, -13, 4, 10, 102, 206);
    AddSpriteFrame(17, -13, 4, 10, 107, 206);
    AddSpriteFrame(14, -59, 4, 3, 107, 217);
    AddSpriteFrame(14, -59, 4, 3, 107, 221);
    AddSpriteFrame(14, -59, 4, 3, 107, 225);
    AddSpriteFrame(14, -59, 4, 3, 107, 229);
    AddSpriteFrame(14, -59, 4, 3, 107, 233);
    AddSpriteFrame(32, -47, 5, 3, 112, 215);
    AddSpriteFrame(32, -47, 5, 3, 117, 215);
    AddSpriteFrame(32, -47, 5, 3, 122, 215);
    AddSpriteFrame(32, -47, 5, 3, 127, 215);
    AddSpriteFrame(32, -47, 5, 3, 132, 215);
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Egg Mobile")) {
            objectEntityList[scriptEng.arrayPosition[0]].drawOrder = 2;
            objectEntityList[scriptEng.arrayPosition[0]].type = TypeNameID("Blank Object");
            scriptEng.arrayPosition[0]--;
            objectEntityList[scriptEng.arrayPosition[0]].type = TypeNameID("Blank Object");
            objectEntityList[scriptEng.arrayPosition[0]].values[5] = 1;
            objectEntityList[scriptEng.arrayPosition[0]].drawOrder = 2;
            scriptEng.arrayPosition[0]--;
            objectEntityList[scriptEng.arrayPosition[0]].type = TypeNameID("Blank Object");
            objectEntityList[scriptEng.arrayPosition[0]].values[5] = 1;
            objectEntityList[scriptEng.arrayPosition[0]].drawOrder = 2;
            scriptEng.arrayPosition[0]--;
            objectEntityList[scriptEng.arrayPosition[0]].type = TypeNameID("Blank Object");
            objectEntityList[scriptEng.arrayPosition[0]].values[5] = 1;
            objectEntityList[scriptEng.arrayPosition[0]].drawOrder = 2;
            scriptEng.arrayPosition[0]--;
            objectEntityList[scriptEng.arrayPosition[0]].type = TypeNameID("Blank Object");
            objectEntityList[scriptEng.arrayPosition[0]].values[5] = 1;
            objectEntityList[scriptEng.arrayPosition[0]].drawOrder = 2;
            scriptEng.arrayPosition[0] += 4;
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_R8_EggMobile::ObjectMain()
{
    Entity *self = Self();

    self->values[3] += self->values[6];
    if (self->values[3] < 0) {
        self->values[3] += 5120;
    }
    self->values[3] %= 5120;
    self->rotation = self->values[3];
    self->rotation /= 10;
    if (objectEntityList[objectLoop + 1].values[3] == 0) {
        CallScriptFunction(objectEntityList[objectLoop + 1].values[1], scriptSub);
    }
    CallScriptFunction(self->state, scriptSub);
    EggMobile_HandleWingRotation();
    if (self->values[7] > 0) {
        if (self->values[7] > 20) {
            scriptEng.tempValue[0] = self->values[7];
            scriptEng.tempValue[0] &= 15;
            if (scriptEng.tempValue[0] == 0) {
                scriptEng.tempValue[0] = rand() % 48;
                scriptEng.tempValue[0] -= 24;
                scriptEng.tempValue[0] <<= 16;
                scriptEng.tempValue[0] += self->XPos;
                scriptEng.tempValue[1] = rand() % 48;
                scriptEng.tempValue[1] -= 32;
                scriptEng.tempValue[1] <<= 16;
                scriptEng.tempValue[1] += self->YPos;
                CreateTempObject(TypeNameID("Boss Spark"), 0, scriptEng.tempValue[0], scriptEng.tempValue[1]);
                objectEntityList[scriptEng.arrayPosition[2]].inkEffect = 0;
                objectEntityList[scriptEng.arrayPosition[2]].alpha = 248;
                scriptEng.tempValue[0] = rand() % 48;
                scriptEng.tempValue[0] -= 24;
                scriptEng.tempValue[0] <<= 16;
                scriptEng.tempValue[0] += self->XPos;
                scriptEng.tempValue[1] = rand() % 48;
                scriptEng.tempValue[1] -= 32;
                scriptEng.tempValue[1] <<= 16;
                scriptEng.tempValue[1] += self->YPos;
                CreateTempObject(TypeNameID("Boss Spark"), 0, scriptEng.tempValue[0], scriptEng.tempValue[1]);
                objectEntityList[scriptEng.arrayPosition[2]].inkEffect = 0;
                objectEntityList[scriptEng.arrayPosition[2]].alpha = 248;
            }
        }
        self->values[7]--;
    }
    if (self->values[6] != 0) {
        switch (objectEntityList[objectLoop + 2].values[7]) {
            case 0:
            objectEntityList[objectLoop + 2].animationTimer += 6;
            if (objectEntityList[objectLoop + 2].animationTimer == 42) {
                PlaySfx(globalSFXCount + 6, 0);
            }
            if (objectEntityList[objectLoop + 2].animationTimer > 59) {
                objectEntityList[objectLoop + 2].animationTimer -= 60;
                PlaySfx(globalSFXCount + 6, 0);
            }
            break;
            case 1:
            objectEntityList[objectLoop + 2].animationTimer += 3;
            if (objectEntityList[objectLoop + 2].animationTimer > 59) {
                objectEntityList[objectLoop + 2].animationTimer -= 60;
                if (objectEntityList[objectLoop + 2].animationSpeed == 0) {
                    PlaySfx(globalSFXCount + 6, 0);
                    objectEntityList[objectLoop + 2].animationSpeed = 1;
                } else {
                    PlaySfx(globalSFXCount + 7, 0);
                    objectEntityList[objectLoop + 2].animationSpeed = 0;
                }
            }
            break;
            case 2:
            objectEntityList[objectLoop + 2].animationTimer += 8;
            if (objectEntityList[objectLoop + 2].animationTimer > 59) {
                objectEntityList[objectLoop + 2].animationTimer -= 60;
                PlaySfx(globalSFXCount + 6, 0);
            }
            break;
            case 3:
            objectEntityList[objectLoop + 2].animationTimer += 10;
            if (objectEntityList[objectLoop + 2].animationTimer > 59) {
                objectEntityList[objectLoop + 2].animationTimer -= 60;
                PlaySfx(globalSFXCount + 6, 0);
            }
            break;
            case 4:
            objectEntityList[objectLoop + 2].animationTimer += 16;
            if (objectEntityList[objectLoop + 2].animationTimer > 59) {
                objectEntityList[objectLoop + 2].animationTimer -= 60;
                PlaySfx(globalSFXCount + 6, 0);
            }
            break;
        }
    }
}

void O_R8_EggMobile::ObjectPlayerInteraction()
{
    Entity *self = Self();

    if (objectEntityList[objectLoop + 2].state == 0) {
        if (self->values[7] == 0) {
            PlayerObjectCollision(C_TOUCH, -24, -24, 24, 24);
            if (CheckResult() == 1) {
                CheckResult() = 0;
                if (pAnimation() == GVar("ANI_JUMPING")) {
                    CheckResult() = 1;
                }
                if (pAnimation() == GVar("ANI_SPINDASH")) {
                    CheckResult() = 1;
                }
                if (CheckResult() == 0) {
                    CallScriptFunctionNamed("Player_Hit", scriptSub);
                    if (pState() == PlayerStateID("Player_State_GotHit")) {
                        self->animation = 2;
                    }
                } else {
                    self->values[3] >>= 5;
                    self->values[3] <<= 5;
                    pSpeed() = -pSpeed();
                    pXVel() = -pXVel();
                    pYVel() = -pYVel();
                    scriptEng.tempValue[0] = 0;
                    scriptEng.arrayPosition[0] = objectLoop;
                    scriptEng.arrayPosition[0]--;
                    scriptEng.tempValue[1] = 0x10000;
                    while (scriptEng.tempValue[0] < 4) {
                        if (objectEntityList[scriptEng.arrayPosition[0]].values[5] == 1) {
                            EggMobile_DropDamagedWing();
                            if (scriptEng.tempValue[6] < scriptEng.tempValue[1]) {
                                scriptEng.arrayPosition[1] = scriptEng.arrayPosition[0];
                                scriptEng.tempValue[1] = scriptEng.tempValue[6];
                            }
                        }
                        scriptEng.arrayPosition[0]--;
                        scriptEng.tempValue[0]++;
                    }
                    if (scriptEng.tempValue[1] < 0x10000) {
                        objectEntityList[scriptEng.arrayPosition[1]].values[5] = 0;
                        objectEntityList[scriptEng.arrayPosition[1]].state = 5;
                        objectEntityList[scriptEng.arrayPosition[1]].priority = 1;
                        if (objectEntityList[scriptEng.arrayPosition[1]].XPos > self->XPos) {
                            objectEntityList[scriptEng.arrayPosition[1]].values[1] = 0x10000;
                        } else {
                            objectEntityList[scriptEng.arrayPosition[1]].values[1] = -0x10000;
                        }
                        objectEntityList[scriptEng.arrayPosition[1]].values[2] = -0x30000;
                    }
                    objectEntityList[objectLoop + 1].values[0]--;
                    switch (objectEntityList[objectLoop + 1].values[0]) {
                        case 0:
                        timeEnabled = 0;
                        GVar("Player.Score") += 1000;
                        objectEntityList[objectLoop + 2].state = 1;
                        self->animation = 3;
                        self->values[0] = 0;
                        if (objectEntityList[24].propertyValue == 3) {
                            self->state = ScriptFuncID("EggMobile_Destroyed");
                        } else {
                            self->state = ScriptFuncID("EggMobile_Destroyed");
                        }
                        objectEntityList[objectLoop + 3].state++;
                        objectEntityList[objectLoop + 3].alpha >>= 1;
                        objectEntityList[objectLoop + 3].alpha <<= 1;
                        objectEntityList[objectLoop + 2].values[0] = 0;
                        self->animationTimer = 0;
                        objectEntityList[objectLoop + 1].values[3] = 1;
                        objectEntityList[objectLoop + 2].values[7] = 5;
                        HapticEffect_Script(90, 0, 0, 0);
                        break;
                        case 1:
                        self->values[7] = 120;
                        objectEntityList[objectLoop + 1].values[2] = 0;
                        objectEntityList[objectLoop + 1].values[3] = 1;
                        self->state = ScriptFuncID("EggMobile_Hit");
                        self->values[2] = 0x10000;
                        objectEntityList[objectLoop + 1].values[1] = ScriptFuncID("Helper1Controller_OneWing");
                        self->values[0] = 0;
                        self->animation = 1;
                        objectEntityList[objectLoop + 2].values[7] = 4;
                        PlaySfx(globalSFXCount + 5, 0);
                        HapticEffect_Script(75, 0, 0, 0);
                        break;
                        case 2:
                        self->values[7] = 120;
                        objectEntityList[objectLoop + 1].values[2] = 0;
                        objectEntityList[objectLoop + 1].values[3] = 1;
                        self->state = ScriptFuncID("EggMobile_Hit");
                        self->values[2] = 0xE000;
                        objectEntityList[objectLoop + 1].values[1] = ScriptFuncID("Helper1Controller_TwoWings");
                        self->values[0] = 0;
                        self->animation = 1;
                        objectEntityList[objectLoop + 2].values[7] = 3;
                        PlaySfx(globalSFXCount + 5, 0);
                        HapticEffect_Script(75, 0, 0, 0);
                        break;
                        case 3:
                        self->values[7] = 120;
                        objectEntityList[objectLoop + 1].values[2] = 0;
                        objectEntityList[objectLoop + 1].values[3] = 1;
                        self->state = ScriptFuncID("EggMobile_Hit");
                        self->values[2] = 0xC000;
                        objectEntityList[objectLoop + 1].values[1] = ScriptFuncID("Helper1Controller_ThreeWings");
                        self->values[0] = 0;
                        self->animation = 1;
                        objectEntityList[objectLoop + 2].values[7] = 2;
                        PlaySfx(globalSFXCount + 5, 0);
                        HapticEffect_Script(75, 0, 0, 0);
                        break;
                    }
                }
            }
        }
    }
    scriptEng.tempValue[0] = pCollisionRight();
    scriptEng.tempValue[0] <<= 16;
    scriptEng.tempValue[0] += pXPos();
    scriptEng.tempValue[1] = objectEntityList[objectLoop + 2].values[6];
    scriptEng.tempValue[1] <<= 16;
    if (scriptEng.tempValue[0] > scriptEng.tempValue[1]) {
        pXVel() = 0;
        pSpeed() = 0;
        pXPos() = scriptEng.tempValue[1];
        scriptEng.tempValue[0] = pCollisionRight();
        scriptEng.tempValue[0] <<= 16;
        pXPos() -= scriptEng.tempValue[0];
    }
}

void O_R8_EggMobile::ObjectDraw()
{
    Entity *self = Self();

    scriptEng.tempValue[0] = self->values[7];
    scriptEng.tempValue[0] &= 1;
    if (scriptEng.tempValue[0] == 0) {
        switch (self->animation) {
            case 0:
            DrawSprite_Frame(0);
            EggMobile_HandleAnimations();
            if (self->values[6] != 0) {
                scriptEng.tempValue[0] = GVar("Oscillation");
                scriptEng.tempValue[0] &= 7;
                scriptEng.tempValue[0] >>= 2;
                scriptEng.tempValue[0] += 2;
                DrawSprite_Frame(scriptEng.tempValue[0]);
            }
            DrawSprite_Frame(6);
            DrawSprite_Frame(10);
            break;
            case 1:
            DrawSprite_Frame(0);
            EggMobile_HandleAnimations();
            if (self->values[6] != 0) {
                scriptEng.tempValue[0] = GVar("Oscillation");
                scriptEng.tempValue[0] &= 7;
                scriptEng.tempValue[0] >>= 2;
                scriptEng.tempValue[0] += 2;
                DrawSprite_Frame(scriptEng.tempValue[0]);
            }
            DrawSprite_Frame(9);
            DrawSprite_Frame(10);
            if (self->animationTimer < 120) {
                self->animationTimer++;
            } else {
                self->animationTimer = 0;
                self->animation = 0;
            }
            break;
            case 2:
            DrawSprite_Frame(0);
            EggMobile_HandleAnimations();
            if (self->values[6] != 0) {
                scriptEng.tempValue[0] = GVar("Oscillation");
                scriptEng.tempValue[0] &= 7;
                scriptEng.tempValue[0] >>= 2;
                scriptEng.tempValue[0] += 2;
                DrawSprite_Frame(scriptEng.tempValue[0]);
            }
            scriptEng.tempValue[0] = self->animationTimer;
            scriptEng.tempValue[0] &= 15;
            scriptEng.tempValue[0] >>= 3;
            scriptEng.tempValue[0] += 6;
            DrawSprite_Frame(scriptEng.tempValue[0]);
            if (self->animationTimer < 120) {
                self->animationTimer++;
            } else {
                self->animationTimer = 0;
                self->animation = 0;
            }
            DrawSprite_Frame(10);
            break;
            case 3:
            DrawSprite_Frame(1);
            DrawSprite_Frame(8);
            break;
        }
    }
}

void O_R8_EggMobile::EggMobile_StopMovement()
{
    Entity *self = Self();

    self->values[0]++;
    if (self->values[0] == objectEntityList[objectLoop + 2].values[1]) {
        self->values[0] = 0;
        objectEntityList[objectLoop + 1].values[3] = 0;
    }
}

void O_R8_EggMobile::EggMobile_MoveToLeft()
{
    Entity *self = Self();

    self->XPos -= self->values[1];
    if (self->XPos <= objectEntityList[objectLoop + 1].values[4]) {
        objectEntityList[objectLoop + 1].values[3] = 0;
    }
}

void O_R8_EggMobile::EggMobile_MoveToRight()
{
    Entity *self = Self();

    self->XPos += self->values[1];
    if (self->XPos >= objectEntityList[objectLoop + 1].values[5]) {
        objectEntityList[objectLoop + 1].values[3] = 0;
    }
}

void O_R8_EggMobile::EggMobile_GroundSpinAscend()
{
    Entity *self = Self();

    self->YPos -= self->values[2];
    if (self->YPos <= objectEntityList[objectLoop + 1].values[7]) {
        self->YPos = objectEntityList[objectLoop + 1].values[7];
        objectEntityList[objectLoop + 1].values[3] = 0;
    }
}

void O_R8_EggMobile::EggMobile_GroundSpinDescend()
{
    Entity *self = Self();

    self->YPos += self->values[2];
    if (self->YPos >= objectEntityList[objectLoop + 1].values[7]) {
        self->YPos = objectEntityList[objectLoop + 1].values[7];
        objectEntityList[objectLoop + 1].values[3] = 0;
    }
    if (self->values[6] != 0) {
        if (objectEntityList[objectLoop + 1].values[0] < 4) {
            scriptEng.tempValue[0] = self->values[3];
            scriptEng.tempValue[0] >>= 6;
            if (scriptEng.tempValue[0] == objectEntityList[objectLoop + 2].values[4]) {
                self->values[6] = 0;
                self->values[3] = scriptEng.tempValue[0];
                self->values[3] <<= 6;
            }
        } else {
            scriptEng.tempValue[0] = self->values[3];
            scriptEng.tempValue[0] %= 1280;
            if (scriptEng.tempValue[0] == 0) {
                self->values[6] = 0;
            }
        }
    }
}

void O_R8_EggMobile::EggMobile_MoveLeftToCenter()
{
    Entity *self = Self();

    self->XPos -= self->values[1];
    if (self->XPos <= objectEntityList[objectLoop + 1].values[6]) {
        self->XPos = objectEntityList[objectLoop + 1].values[6];
        objectEntityList[objectLoop + 1].values[3] = 0;
    }
}

void O_R8_EggMobile::EggMobile_MoveRightToCenter()
{
    Entity *self = Self();

    self->XPos += self->values[1];
    if (self->XPos >= objectEntityList[objectLoop + 1].values[6]) {
        self->XPos = objectEntityList[objectLoop + 1].values[6];
        objectEntityList[objectLoop + 1].values[3] = 0;
    }
}

void O_R8_EggMobile::EggMobile_GroundSpinLeft()
{
    Entity *self = Self();

    self->XPos -= 0x14CCC;
    if (self->XPos <= objectEntityList[objectLoop + 1].values[7]) {
        self->XPos = objectEntityList[objectLoop + 1].values[7];
        self->values[6] = 0;
        objectEntityList[objectLoop + 1].values[3] = 0;
    }
    scriptEng.tempValue[0] = self->rotation;
    scriptEng.tempValue[0] <<= 1;
    scriptEng.tempValue[0] &= 511;
    scriptEng.tempValue[1] = Sin512(scriptEng.tempValue[0]);
    if (scriptEng.tempValue[1] < 0) {
        scriptEng.tempValue[1] = -scriptEng.tempValue[1];
    }
    scriptEng.tempValue[1] >>= 7;
    scriptEng.tempValue[1] += 64;
    ObjectTileGrip_Script(0, 0, scriptEng.tempValue[1], 0);
}

void O_R8_EggMobile::EggMobile_GroundSpinRight()
{
    Entity *self = Self();

    self->XPos += 0x14CCC;
    if (self->XPos >= objectEntityList[objectLoop + 1].values[7]) {
        self->XPos = objectEntityList[objectLoop + 1].values[7];
        self->values[6] = 0;
        objectEntityList[objectLoop + 1].values[3] = 0;
    }
    scriptEng.tempValue[0] = self->rotation;
    scriptEng.tempValue[0] <<= 1;
    scriptEng.tempValue[0] &= 511;
    scriptEng.tempValue[1] = Sin512(scriptEng.tempValue[0]);
    if (scriptEng.tempValue[1] < 0) {
        scriptEng.tempValue[1] = -scriptEng.tempValue[1];
    }
    scriptEng.tempValue[1] >>= 7;
    scriptEng.tempValue[1] += 64;
    ObjectTileGrip_Script(0, 0, scriptEng.tempValue[1], 0);
}

void O_R8_EggMobile::EggMobile_HandleWingThrowATK()
{
    Entity *self = Self();

    switch (objectEntityList[objectLoop + 2].values[0]) {
        case 0:
        self->values[0]++;
        if (self->values[0] == 20) {
            self->values[0] = 0;
            objectEntityList[objectLoop + 2].values[0]++;
        }
        break;
        case 1:
        if (self->values[6] != 0) {
            scriptEng.tempValue[0] = self->values[3];
            scriptEng.tempValue[0] >>= 7;
            if (scriptEng.tempValue[0] == 0) {
                scriptEng.tempValue[0] <<= 7;
                self->values[3] = scriptEng.tempValue[0];
                self->values[6] = 0;
                objectEntityList[objectLoop + 2].values[0]++;
            }
        }
        break;
        case 2:
        self->values[0]++;
        self->values[4] += 0x80;
        if (self->values[0] == 22) {
            objectEntityList[objectLoop - 4].frame = 1;
            objectEntityList[objectLoop - 3].frame = 1;
            objectEntityList[objectLoop - 2].frame = 1;
            objectEntityList[objectLoop - 1].frame = 1;
        }
        if (self->values[0] == 26) {
            objectEntityList[objectLoop - 4].frame = 2;
            objectEntityList[objectLoop - 3].frame = 2;
            objectEntityList[objectLoop - 2].frame = 2;
            objectEntityList[objectLoop - 1].frame = 2;
        }
        if (self->values[0] == 36) {
            self->values[0] = 0;
            objectEntityList[objectLoop + 2].values[0]++;
        }
        break;
        case 3:
        self->values[0]++;
        if (self->values[0] == 10) {
            self->values[0] = 0;
            objectEntityList[objectLoop + 2].values[0]++;
            self->values[6] = -64;
            objectEntityList[objectLoop + 1].values[7] = objectEntityList[objectLoop + 3].YPos;
            objectEntityList[objectLoop + 1].values[7] -= 0x440000;
        }
        break;
        case 4:
        scriptEng.tempValue[0] = 0;
        scriptEng.arrayPosition[0] = objectLoop;
        scriptEng.arrayPosition[0] -= 4;
        while (scriptEng.tempValue[0] < 4) {
            if (objectEntityList[scriptEng.arrayPosition[0]].values[5] == 1) {
                scriptEng.tempValue[0] = objectEntityList[scriptEng.arrayPosition[0]].rotation;
                scriptEng.tempValue[0] >>= 4;
                if (scriptEng.tempValue[0] == 0) {
                    objectEntityList[scriptEng.arrayPosition[0]].rotation = 0;
                    objectEntityList[scriptEng.arrayPosition[0]].values[5] = 0;
                    objectEntityList[scriptEng.arrayPosition[0]].state = 1;
                    objectEntityList[scriptEng.arrayPosition[0]].values[2] = 0x28000;
                }
            }
            scriptEng.arrayPosition[0]++;
            scriptEng.tempValue[0]++;
        }
        if (self->YPos <= objectEntityList[objectLoop + 1].values[7]) {
            self->YPos = objectEntityList[objectLoop + 1].values[7];
            self->values[0]++;
            if (self->values[0] == 60) {
                self->values[0] = 0;
                self->values[6] = 0;
                self->values[3] = 0;
                objectEntityList[objectLoop + 1].values[3] = 0;
            }
        } else {
            self->YPos -= 0x14000;
        }
        break;
    }
}

void O_R8_EggMobile::EggMobile_WingThrowVertical()
{
    Entity *self = Self();

    if (objectEntityList[objectLoop + 2].values[2] < objectEntityList[objectLoop + 1].values[0]) {
        if (self->values[0] == 0) {
            scriptEng.arrayPosition[0] = objectLoop;
            scriptEng.arrayPosition[0] -= 4;
            scriptEng.arrayPosition[0] += objectEntityList[objectLoop + 2].values[2];
            objectEntityList[scriptEng.arrayPosition[0]].type = TypeNameID("Boss Wing");
            objectEntityList[scriptEng.arrayPosition[0]].state = 2;
            objectEntityList[scriptEng.arrayPosition[0]].rotation = 0;
            objectEntityList[scriptEng.arrayPosition[0]].values[0] = 0;
            if (objectEntityList[objectLoop + 1].values[0] > 2) {
                objectEntityList[scriptEng.arrayPosition[0]].frame = 4;
            } else {
                objectEntityList[scriptEng.arrayPosition[0]].frame = 3;
            }
            objectEntityList[scriptEng.arrayPosition[0]].YPos = objectEntityList[objectLoop + 3].YPos;
            objectEntityList[scriptEng.arrayPosition[0]].YPos -= 0x800000;
            objectEntityList[scriptEng.arrayPosition[0]].values[1] = 0;
            objectEntityList[scriptEng.arrayPosition[0]].values[2] = 0x38000;
            switch (objectEntityList[objectLoop + 2].values[3]) {
                case 0:
                objectEntityList[scriptEng.arrayPosition[0]].XPos = -0x400000;
                break;
                case 1:
                objectEntityList[scriptEng.arrayPosition[0]].XPos = 0x400000;
                break;
                case 2:
                objectEntityList[scriptEng.arrayPosition[0]].XPos = 0x800000;
                break;
                case 3:
                objectEntityList[scriptEng.arrayPosition[0]].XPos = -0x800000;
                break;
                case 4:
                objectEntityList[scriptEng.arrayPosition[0]].XPos = -0x800000;
                break;
                case 5:
                objectEntityList[scriptEng.arrayPosition[0]].XPos = -0x400000;
                break;
                case 6:
                objectEntityList[scriptEng.arrayPosition[0]].XPos = 0;
                break;
                case 7:
                objectEntityList[scriptEng.arrayPosition[0]].XPos = 0x400000;
                break;
                case 8:
                objectEntityList[scriptEng.arrayPosition[0]].XPos = 0x800000;
                break;
                case 9:
                objectEntityList[scriptEng.arrayPosition[0]].XPos = 0x400000;
                break;
                case 10:
                objectEntityList[scriptEng.arrayPosition[0]].XPos = 0;
                break;
                case 11:
                objectEntityList[scriptEng.arrayPosition[0]].XPos = -0x800000;
                break;
                case 12:
                objectEntityList[scriptEng.arrayPosition[0]].XPos = -0x500000;
                break;
                case 13:
                objectEntityList[scriptEng.arrayPosition[0]].XPos = 0x500000;
                break;
                case 14:
                objectEntityList[scriptEng.arrayPosition[0]].XPos = -0x300000;
                break;
                case 15:
                objectEntityList[scriptEng.arrayPosition[0]].XPos = 0xA0000;
                break;
            }
            objectEntityList[scriptEng.arrayPosition[0]].XPos += objectEntityList[objectLoop + 3].XPos;
            self->values[0]++;
        } else {
            if (self->values[0] < 30) {
                self->values[0]++;
            } else {
                self->values[0] = 0;
                objectEntityList[objectLoop + 2].values[2]++;
                objectEntityList[objectLoop + 2].values[3]++;
            }
        }
    } else {
        if (objectEntityList[objectLoop - 4].type == TypeNameID("Blank Object")) {
            if (objectEntityList[objectLoop - 3].type == TypeNameID("Blank Object")) {
                if (objectEntityList[objectLoop - 2].type == TypeNameID("Blank Object")) {
                    if (objectEntityList[objectLoop - 1].type == TypeNameID("Blank Object")) {
                        objectEntityList[objectLoop + 1].values[3] = 0;
                    }
                }
            }
        }
    }
}

void O_R8_EggMobile::EggMobile_WingThrowDiagonal()
{
    if (objectEntityList[objectLoop + 2].values[2] < 1) {
        objectEntityList[objectLoop - 1].type = TypeNameID("Boss Wing");
        objectEntityList[objectLoop - 1].state = 2;
        objectEntityList[objectLoop - 1].values[0] = 0;
        objectEntityList[objectLoop - 1].frame = 3;
        if (pXPos() < objectEntityList[objectLoop + 3].XPos) {
            objectEntityList[objectLoop - 1].YPos = (objectEntityList[objectLoop + 3].XPos >> 16);
            objectEntityList[objectLoop - 1].YPos += 248;
            scriptEng.tempValue[0] = pXPos();
            scriptEng.tempValue[0] >>= 16;
            objectEntityList[objectLoop - 1].YPos -= scriptEng.tempValue[0];
            objectEntityList[objectLoop - 1].YPos *= -0x6A0A;
            objectEntityList[objectLoop - 1].YPos >>= 16;
            objectEntityList[objectLoop - 1].YPos &= 0xFFFF;
            objectEntityList[objectLoop - 1].YPos <<= 16;
            objectEntityList[objectLoop - 1].YPos += objectEntityList[objectLoop + 3].YPos;
            objectEntityList[objectLoop - 1].YPos += 0x600000;
            objectEntityList[objectLoop - 1].XPos = objectEntityList[objectLoop + 3].XPos;
            objectEntityList[objectLoop - 1].XPos += 0xC80000;
            objectEntityList[objectLoop - 1].rotation = 96;
            objectEntityList[objectLoop - 1].values[1] = -0x33BBA;
            objectEntityList[objectLoop - 1].values[2] = 0x156CF;
        } else {
            objectEntityList[objectLoop - 1].YPos = pXPos();
            objectEntityList[objectLoop - 1].YPos >>= 16;
            scriptEng.tempValue[0] = (objectEntityList[objectLoop + 3].XPos >> 16);
            scriptEng.tempValue[0] -= 248;
            objectEntityList[objectLoop - 1].YPos -= scriptEng.tempValue[0];
            objectEntityList[objectLoop - 1].YPos *= -0x6A0A;
            objectEntityList[objectLoop - 1].YPos >>= 16;
            objectEntityList[objectLoop - 1].YPos &= 0xFFFF;
            objectEntityList[objectLoop - 1].YPos <<= 16;
            objectEntityList[objectLoop - 1].YPos += objectEntityList[objectLoop + 3].YPos;
            objectEntityList[objectLoop - 1].YPos += 0x600000;
            objectEntityList[objectLoop - 1].XPos = objectEntityList[objectLoop + 3].XPos;
            objectEntityList[objectLoop - 1].XPos -= 0xC80000;
            objectEntityList[objectLoop - 1].rotation = 416;
            objectEntityList[objectLoop - 1].values[1] = 0x33BBA;
            objectEntityList[objectLoop - 1].values[2] = 0x156CF;
        }
        objectEntityList[objectLoop + 2].values[2]++;
    } else {
        if (objectEntityList[objectLoop - 4].type == TypeNameID("Blank Object")) {
            if (objectEntityList[objectLoop - 3].type == TypeNameID("Blank Object")) {
                if (objectEntityList[objectLoop - 2].type == TypeNameID("Blank Object")) {
                    if (objectEntityList[objectLoop - 1].type == TypeNameID("Blank Object")) {
                        objectEntityList[objectLoop + 1].values[3] = 0;
                    }
                }
            }
        }
    }
}

void O_R8_EggMobile::EggMobile_RestoreWings()
{
    Entity *self = Self();

    if (self->values[0] == 0) {
        switch (objectEntityList[objectLoop + 1].values[0]) {
            case 1:
            objectEntityList[objectLoop - 2].type = TypeNameID("Boss Wing");
            objectEntityList[objectLoop - 2].frame = 0;
            objectEntityList[objectLoop - 2].values[5] = 1;
            break;
            case 2:
            objectEntityList[objectLoop - 2].type = TypeNameID("Boss Wing");
            objectEntityList[objectLoop - 2].frame = 0;
            objectEntityList[objectLoop - 2].values[5] = 1;
            objectEntityList[objectLoop - 1].type = TypeNameID("Boss Wing");
            objectEntityList[objectLoop - 1].frame = 0;
            objectEntityList[objectLoop - 1].values[5] = 1;
            break;
            case 3:
            objectEntityList[objectLoop - 3].type = TypeNameID("Boss Wing");
            objectEntityList[objectLoop - 3].frame = 0;
            objectEntityList[objectLoop - 3].values[5] = 1;
            objectEntityList[objectLoop - 2].type = TypeNameID("Boss Wing");
            objectEntityList[objectLoop - 2].frame = 0;
            objectEntityList[objectLoop - 2].values[5] = 1;
            objectEntityList[objectLoop - 1].type = TypeNameID("Boss Wing");
            objectEntityList[objectLoop - 1].frame = 0;
            objectEntityList[objectLoop - 1].values[5] = 1;
            break;
            case 4:
            objectEntityList[objectLoop - 4].type = TypeNameID("Boss Wing");
            objectEntityList[objectLoop - 4].frame = 0;
            objectEntityList[objectLoop - 4].values[5] = 1;
            objectEntityList[objectLoop - 3].type = TypeNameID("Boss Wing");
            objectEntityList[objectLoop - 3].frame = 0;
            objectEntityList[objectLoop - 3].values[5] = 1;
            objectEntityList[objectLoop - 2].type = TypeNameID("Boss Wing");
            objectEntityList[objectLoop - 2].frame = 0;
            objectEntityList[objectLoop - 2].values[5] = 1;
            objectEntityList[objectLoop - 1].type = TypeNameID("Boss Wing");
            objectEntityList[objectLoop - 1].frame = 0;
            objectEntityList[objectLoop - 1].values[5] = 1;
            break;
        }
        self->values[4] = 0;
        self->values[0]++;
    } else {
        self->values[0]++;
        if (self->values[0] < 120) {
            self->values[4] += 0x70;
            if (self->values[4] >= 0x1000) {
                self->values[4] = 0x1000;
            }
        } else {
            self->values[0] = 0;
            objectEntityList[objectLoop + 1].values[3] = 0;
        }
    }
}

void O_R8_EggMobile::EggMobile_SetTargetDestiny()
{
    Entity *self = Self();

    self->values[1] = pXPos();
    self->values[1] -= self->XPos;
    self->values[1] >>= 16;
    scriptEng.tempValue[0] = self->values[1];
    if (scriptEng.tempValue[0] < 0) {
        scriptEng.tempValue[0] = -scriptEng.tempValue[0];
    }
    if (scriptEng.tempValue[0] < 64) {
        self->values[1] <<= 4;
        self->values[1] /= 90;
        self->values[1] <<= 12;
        self->values[2] = objectEntityList[objectLoop + 3].YPos;
        self->values[2] -= 0x40000;
        objectEntityList[objectLoop + 1].values[7] = self->values[2];
        self->values[2] -= self->YPos;
        self->values[2] >>= 16;
        self->values[2] <<= 4;
        self->values[2] /= 90;
        self->values[2] <<= 12;
        if (objectEntityList[objectLoop + 1].values[0] == 2) {
            objectEntityList[objectLoop + 2].values[4] = 4480;
        } else {
            objectEntityList[objectLoop + 2].values[4] = 3840;
        }
    } else {
        if (self->values[1] >= 0) {
            self->values[1] -= 16;
        } else {
            self->values[1] += 16;
        }
        self->values[1] <<= 4;
        self->values[1] /= 90;
        self->values[1] <<= 12;
        self->values[2] = objectEntityList[objectLoop + 3].YPos;
        self->values[2] += 0xA0000;
        objectEntityList[objectLoop + 1].values[7] = self->values[2];
        self->values[2] -= self->YPos;
        self->values[2] >>= 16;
        self->values[2] <<= 4;
        self->values[2] /= 90;
        self->values[2] <<= 12;
        if (objectEntityList[objectLoop + 1].values[0] == 2) {
            objectEntityList[objectLoop + 2].values[4] = 4480;
        } else {
            objectEntityList[objectLoop + 2].values[4] = 3200;
        }
    }
}

void O_R8_EggMobile::EggMobile_ApproachPlayer()
{
    Entity *self = Self();

    self->XPos += self->values[1];
    self->YPos += self->values[2];
    if (self->values[0] > 10) {
        if (self->values[3] == objectEntityList[objectLoop + 2].values[4]) {
            self->values[6] = 0;
        }
    } else {
        self->values[0]++;
    }
    if (self->YPos >= objectEntityList[objectLoop + 1].values[7]) {
        self->values[0] = 0;
        self->YPos = objectEntityList[objectLoop + 1].values[7];
        objectEntityList[objectLoop + 1].values[7] = objectEntityList[objectLoop + 3].YPos;
        objectEntityList[objectLoop + 1].values[7] -= 0x440000;
        self->values[1] = -self->values[1];
        self->values[2] = -self->values[2];
        objectEntityList[objectLoop + 1].values[3] = 0;
        PlaySfx(globalSFXCount + 9, 0);
    }
}

void O_R8_EggMobile::EggMobile_ExtendWings()
{
    Entity *self = Self();

    self->values[4] += 0x120;
    if (self->values[4] > 0x2200) {
        self->values[4] = 0x2200;
    }
    self->values[0]++;
    if (self->values[0] == 120) {
        self->values[0] = 0;
        objectEntityList[objectLoop + 1].values[3] = 0;
    }
}

void O_R8_EggMobile::EggMobile_RetractWings()
{
    Entity *self = Self();

    self->XPos += self->values[1];
    self->YPos += self->values[2];
    self->values[4] -= 0x80;
    if (self->values[4] < 0x1000) {
        self->values[4] = 0x1000;
    }
    if (self->YPos <= objectEntityList[objectLoop + 1].values[7]) {
        self->YPos = objectEntityList[objectLoop + 1].values[7];
        objectEntityList[objectLoop + 1].values[3] = 0;
    }
}

void O_R8_EggMobile::EggMobile_Hit()
{
    Entity *self = Self();

    self->values[4] -= 0x80;
    if (self->values[4] < 0x1000) {
        self->values[4] = 0x1000;
    }
    self->YPos -= self->values[2];
    scriptEng.tempValue[0] = objectEntityList[objectLoop + 3].YPos;
    scriptEng.tempValue[0] -= 0x440000;
    if (self->YPos <= scriptEng.tempValue[0]) {
        self->YPos = scriptEng.tempValue[0];
        objectEntityList[objectLoop + 1].values[3] = 0;
    }
}

void O_R8_EggMobile::EggMobile_PreparePogoAttack()
{
    Entity *self = Self();

    if (self->values[0] < 20) {
        self->values[0]++;
    } else {
        scriptEng.tempValue[0] = self->values[3];
        scriptEng.tempValue[0] >>= 7;
        if (scriptEng.tempValue[0] == 0) {
            self->values[0] = 0;
            objectEntityList[objectLoop - 2].rotation = 256;
            self->values[3] = 0;
            self->values[6] = 0;
            objectEntityList[objectLoop + 1].values[3] = 0;
        }
    }
}

void O_R8_EggMobile::EggMobile_PogoAttackDescend()
{
    Entity *self = Self();

    scriptEng.tempValue[0] = self->values[0];
    scriptEng.tempValue[0] <<= 8;
    scriptEng.tempValue[0] /= 60;
    self->YPos = Sin512(scriptEng.tempValue[0]);
    self->YPos *= -0x3200;
    self->YPos += objectEntityList[objectLoop + 3].YPos;
    self->YPos += 0x200000;
    self->values[0]++;
    if (self->values[0] > 29) {
        self->values[0] = 0;
        self->YPos = objectEntityList[objectLoop + 3].YPos;
        self->YPos -= 0x440000;
        objectEntityList[objectLoop + 1].values[3] = 0;
    }
}

void O_R8_EggMobile::EggMobile_PogoAttackAscend()
{
    Entity *self = Self();

    scriptEng.tempValue[0] = self->values[0];
    scriptEng.tempValue[0] += 30;
    scriptEng.tempValue[0] <<= 8;
    scriptEng.tempValue[0] /= 60;
    self->YPos = Sin512(scriptEng.tempValue[0]);
    self->YPos *= -0x3200;
    self->YPos += objectEntityList[objectLoop + 3].YPos;
    self->YPos += 0x200000;
    self->values[0]++;
    if (self->values[0] > 29) {
        self->values[0] = 0;
        objectEntityList[objectLoop + 1].values[3] = 0;
        PlaySfx(globalSFXCount + 8, 0);
    }
}

void O_R8_EggMobile::EggMobile_PogoAttackMoveLeft()
{
    Entity *self = Self();

    scriptEng.tempValue[0] = self->values[0];
    scriptEng.tempValue[0] <<= 8;
    scriptEng.tempValue[0] /= 60;
    self->XPos = Cos512(scriptEng.tempValue[0]);
    self->XPos *= 0x1480;
    self->XPos += objectEntityList[objectLoop + 1].values[7];
    self->YPos = Sin512(scriptEng.tempValue[0]);
    self->YPos *= -0x3400;
    self->YPos += objectEntityList[objectLoop + 3].YPos;
    self->YPos += 0x200000;
    scriptEng.tempValue[0] = objectEntityList[objectLoop + 3].YPos;
    scriptEng.tempValue[0] += 0x200000;
    scriptEng.tempValue[0] -= self->YPos;
    scriptEng.tempValue[0] >>= 9;
    self->values[4] = 0x1000;
    self->values[4] += scriptEng.tempValue[0];
    if (self->values[4] > 0x2200) {
        self->values[4] = 0x2200;
    }
    self->values[0]++;
    if (self->values[0] > 59) {
        self->values[0] = 0;
        objectEntityList[objectLoop + 1].values[3] = 0;
        PlaySfx(globalSFXCount + 8, 0);
    }
}

void O_R8_EggMobile::EggMobile_PogoAttackMoveRight()
{
    Entity *self = Self();

    scriptEng.tempValue[0] = self->values[0];
    scriptEng.tempValue[0] <<= 8;
    scriptEng.tempValue[0] /= 60;
    self->XPos = Cos512(scriptEng.tempValue[0]);
    self->XPos *= -0x1480;
    self->XPos += objectEntityList[objectLoop + 1].values[7];
    self->YPos = Sin512(scriptEng.tempValue[0]);
    self->YPos *= -0x3400;
    self->YPos += objectEntityList[objectLoop + 3].YPos;
    self->YPos += 0x200000;
    scriptEng.tempValue[0] = objectEntityList[objectLoop + 3].YPos;
    scriptEng.tempValue[0] += 0x200000;
    scriptEng.tempValue[0] -= self->YPos;
    scriptEng.tempValue[0] >>= 9;
    self->values[4] = 0x1000;
    self->values[4] += scriptEng.tempValue[0];
    if (self->values[4] > 0x2200) {
        self->values[4] = 0x2200;
    }
    self->values[0]++;
    if (self->values[0] > 59) {
        self->values[0] = 0;
        objectEntityList[objectLoop + 1].values[3] = 0;
        PlaySfx(globalSFXCount + 8, 0);
    }
}

void O_R8_EggMobile::Helper1Controller_FourWings()
{
    Entity *self = Self();

    switch (objectEntityList[objectLoop + 1].values[2]) {
        case 0:
        self->state = ScriptFuncID("EggMobile_StopMovement");
        objectEntityList[objectLoop + 2].values[1] = 120;
        objectEntityList[objectLoop + 2].state = 1;
        break;
        case 1:
        self->state = ScriptFuncID("EggMobile_MoveToRight");
        self->values[6] = -64;
        self->values[1] = 0x16000;
        objectEntityList[objectLoop + 2].state = 1;
        break;
        case 2:
        self->state = ScriptFuncID("EggMobile_MoveToLeft");
        break;
        case 3:
        self->state = ScriptFuncID("EggMobile_MoveRightToCenter");
        break;
        case 4:
        self->state = ScriptFuncID("EggMobile_GroundSpinDescend");
        self->values[2] = 0xA000;
        objectEntityList[objectLoop + 1].values[7] = objectEntityList[objectLoop + 3].YPos;
        objectEntityList[objectLoop + 1].values[7] += 0x200000;
        objectEntityList[objectLoop + 2].state = 0;
        break;
        case 5:
        self->state = ScriptFuncID("EggMobile_StopMovement");
        objectEntityList[objectLoop + 2].values[1] = 20;
        break;
        case 6:
        if (pXPos() > self->XPos) {
            self->direction = 1;
            self->state = ScriptFuncID("EggMobile_GroundSpinRight");
            objectEntityList[objectLoop + 1].values[7] = objectEntityList[objectLoop + 1].values[6];
            objectEntityList[objectLoop + 1].values[7] += 0x680000;
            self->values[6] = 16;
        } else {
            self->direction = 0;
            self->state = ScriptFuncID("EggMobile_GroundSpinLeft");
            objectEntityList[objectLoop + 1].values[7] = objectEntityList[objectLoop + 1].values[6];
            objectEntityList[objectLoop + 1].values[7] -= 0x680000;
            self->values[6] = -16;
        }
        objectEntityList[objectLoop + 2].values[7] = 1;
        objectEntityList[objectLoop + 2].animationSpeed = 0;
        objectEntityList[objectLoop + 2].animationTimer = 0;
        break;
        case 7:
        self->state = ScriptFuncID("EggMobile_StopMovement");
        objectEntityList[objectLoop + 2].values[1] = 60;
        self->values[6] = 0;
        break;
        case 8:
        if (self->XPos < objectEntityList[objectLoop + 3].XPos) {
            self->state = ScriptFuncID("EggMobile_GroundSpinRight");
            objectEntityList[objectLoop + 1].values[7] = objectEntityList[objectLoop + 1].values[6];
            objectEntityList[objectLoop + 1].values[7] += 0x680000;
            self->values[6] = 16;
        } else {
            self->state = ScriptFuncID("EggMobile_GroundSpinLeft");
            objectEntityList[objectLoop + 1].values[7] = objectEntityList[objectLoop + 1].values[6];
            objectEntityList[objectLoop + 1].values[7] -= 0x680000;
            self->values[6] = -16;
        }
        objectEntityList[objectLoop + 2].animationTimer = 0;
        break;
        case 9:
        self->state = ScriptFuncID("EggMobile_StopMovement");
        objectEntityList[objectLoop + 2].values[1] = 60;
        self->values[6] = 0;
        objectEntityList[objectLoop + 2].values[7] = 0;
        objectEntityList[objectLoop + 2].animationTimer = 0;
        break;
        case 10:
        self->state = ScriptFuncID("EggMobile_GroundSpinAscend");
        self->values[6] = -64;
        objectEntityList[objectLoop + 1].values[7] = objectEntityList[objectLoop + 3].YPos;
        objectEntityList[objectLoop + 1].values[7] -= 0x240000;
        break;
        case 11:
        self->state = ScriptFuncID("EggMobile_StopMovement");
        objectEntityList[objectLoop + 2].values[1] = 90;
        break;
        case 12:
        if (self->direction == 0) {
            self->state = ScriptFuncID("EggMobile_MoveToLeft");
        } else {
            self->state = ScriptFuncID("EggMobile_MoveToRight");
        }
        break;
        case 13:
        if (self->direction == 0) {
            self->state = ScriptFuncID("EggMobile_MoveToRight");
        } else {
            self->state = ScriptFuncID("EggMobile_MoveToLeft");
        }
        break;
        case 14:
        if (self->direction == 0) {
            self->state = ScriptFuncID("EggMobile_MoveLeftToCenter");
        } else {
            self->state = ScriptFuncID("EggMobile_MoveRightToCenter");
        }
        break;
        case 15:
        self->state = ScriptFuncID("EggMobile_HandleWingThrowATK");
        objectEntityList[objectLoop + 2].values[0] = 0;
        objectEntityList[objectLoop + 2].state = 1;
        break;
        case 16:
        self->state = ScriptFuncID("EggMobile_WingThrowVertical");
        objectEntityList[objectLoop + 2].values[2] = 0;
        objectEntityList[objectLoop + 2].values[3] = pXPos();
        objectEntityList[objectLoop + 2].values[3] >>= 16;
        objectEntityList[objectLoop + 2].values[3] &= 3;
        objectEntityList[objectLoop + 2].values[3] <<= 2;
        objectEntityList[objectLoop - 4].type = TypeNameID("Blank Object");
        objectEntityList[objectLoop - 3].type = TypeNameID("Blank Object");
        objectEntityList[objectLoop - 2].type = TypeNameID("Blank Object");
        objectEntityList[objectLoop - 1].type = TypeNameID("Blank Object");
        objectEntityList[objectLoop + 2].state = 1;
        break;
        case 17:
        self->state = ScriptFuncID("EggMobile_RestoreWings");
        objectEntityList[objectLoop + 2].state = 1;
        break;
        case 18:
        EggMobile_SetTargetDestiny();
        self->state = ScriptFuncID("EggMobile_ApproachPlayer");
        self->values[6] = -64;
        objectEntityList[objectLoop + 2].state = 0;
        break;
        case 19:
        self->state = ScriptFuncID("EggMobile_ExtendWings");
        break;
        case 20:
        self->state = ScriptFuncID("EggMobile_RetractWings");
        break;
        case 21:
        EggMobile_SetTargetDestiny();
        self->state = ScriptFuncID("EggMobile_ApproachPlayer");
        self->values[6] = -64;
        break;
        case 22:
        self->state = ScriptFuncID("EggMobile_ExtendWings");
        break;
        case 23:
        self->state = ScriptFuncID("EggMobile_RetractWings");
        break;
    }
    if (objectEntityList[objectLoop + 1].values[2] < 23) {
        objectEntityList[objectLoop + 1].values[2]++;
    } else {
        objectEntityList[objectLoop + 1].values[2] = 1;
    }
    objectEntityList[objectLoop + 1].values[3] = 1;
}

void O_R8_EggMobile::Helper1Controller_ThreeWings()
{
    Entity *self = Self();

    switch (objectEntityList[objectLoop + 1].values[2]) {
        case 0:
        self->state = ScriptFuncID("EggMobile_MoveToRight");
        self->values[6] = -80;
        self->values[1] = 0x18000;
        objectEntityList[objectLoop + 2].state = 1;
        break;
        case 1:
        self->state = ScriptFuncID("EggMobile_MoveToLeft");
        break;
        case 2:
        self->state = ScriptFuncID("EggMobile_MoveRightToCenter");
        break;
        case 3:
        if (pXPos() > self->XPos) {
            self->state = ScriptFuncID("EggMobile_MoveToLeft");
            self->direction = 1;
        } else {
            self->state = ScriptFuncID("EggMobile_MoveToRight");
            self->direction = 0;
        }
        break;
        case 4:
        self->values[3] /= 160;
        self->values[3] *= 160;
        self->state = ScriptFuncID("EggMobile_GroundSpinDescend");
        self->values[2] = 0xC000;
        objectEntityList[objectLoop + 1].values[7] = objectEntityList[objectLoop + 3].YPos;
        objectEntityList[objectLoop + 1].values[7] += 0x200000;
        objectEntityList[objectLoop + 2].state = 0;
        scriptEng.tempValue[0] = 4;
        scriptEng.arrayPosition[0] = objectLoop;
        scriptEng.arrayPosition[0] -= 4;
        while (scriptEng.tempValue[0] > 0) {
            if (objectEntityList[scriptEng.arrayPosition[0]].values[5] == 0) {
                objectEntityList[objectLoop + 2].values[4] = scriptEng.tempValue[0];
                if (self->direction == 1) {
                    objectEntityList[objectLoop + 2].values[4] += 3;
                } else {
                    objectEntityList[objectLoop + 2].values[4]++;
                }
                objectEntityList[objectLoop + 2].values[4] *= 20;
                objectEntityList[objectLoop + 2].values[4] %= 80;
                scriptEng.tempValue[0] = 0;
            }
            scriptEng.arrayPosition[0]++;
            scriptEng.tempValue[0]--;
        }
        break;
        case 5:
        self->state = ScriptFuncID("EggMobile_StopMovement");
        objectEntityList[objectLoop + 2].values[1] = 20;
        break;
        case 6:
        if (self->XPos < objectEntityList[objectLoop + 3].XPos) {
            self->state = ScriptFuncID("EggMobile_GroundSpinRight");
            objectEntityList[objectLoop + 1].values[7] = objectEntityList[objectLoop + 3].XPos;
            objectEntityList[objectLoop + 1].values[7] -= 0x140000;
            self->values[6] = 16;
        } else {
            self->state = ScriptFuncID("EggMobile_GroundSpinLeft");
            objectEntityList[objectLoop + 1].values[7] = objectEntityList[objectLoop + 3].XPos;
            objectEntityList[objectLoop + 1].values[7] += 0x140000;
            self->values[6] = -16;
        }
        objectEntityList[objectLoop + 2].values[7] = 1;
        objectEntityList[objectLoop + 2].animationSpeed = 0;
        objectEntityList[objectLoop + 2].animationTimer = 0;
        break;
        case 7:
        self->state = ScriptFuncID("EggMobile_StopMovement");
        objectEntityList[objectLoop + 2].values[1] = 60;
        self->values[6] = 0;
        break;
        case 8:
        if (self->XPos < objectEntityList[objectLoop + 1].values[6]) {
            self->direction = 1;
            self->state = ScriptFuncID("EggMobile_GroundSpinLeft");
            objectEntityList[objectLoop + 1].values[7] = objectEntityList[objectLoop + 1].values[4];
            self->values[6] = -16;
        } else {
            self->direction = 0;
            self->state = ScriptFuncID("EggMobile_GroundSpinRight");
            objectEntityList[objectLoop + 1].values[7] = objectEntityList[objectLoop + 1].values[5];
            self->values[6] = 16;
        }
        objectEntityList[objectLoop + 2].animationTimer = 0;
        break;
        case 9:
        self->state = ScriptFuncID("EggMobile_StopMovement");
        objectEntityList[objectLoop + 2].values[1] = 60;
        self->values[6] = 0;
        objectEntityList[objectLoop + 2].values[7] = 2;
        objectEntityList[objectLoop + 2].animationTimer = 0;
        break;
        case 10:
        self->state = ScriptFuncID("EggMobile_GroundSpinAscend");
        self->values[6] = -80;
        objectEntityList[objectLoop + 1].values[7] = objectEntityList[objectLoop + 3].YPos;
        objectEntityList[objectLoop + 1].values[7] -= 0x240000;
        break;
        case 11:
        self->state = ScriptFuncID("EggMobile_StopMovement");
        objectEntityList[objectLoop + 2].values[1] = 90;
        break;
        case 12:
        if (self->direction == 0) {
            self->state = ScriptFuncID("EggMobile_MoveToLeft");
        } else {
            self->state = ScriptFuncID("EggMobile_MoveToRight");
        }
        break;
        case 13:
        if (self->direction == 0) {
            self->state = ScriptFuncID("EggMobile_MoveToRight");
        } else {
            self->state = ScriptFuncID("EggMobile_MoveToLeft");
        }
        break;
        case 14:
        if (self->direction == 0) {
            self->state = ScriptFuncID("EggMobile_MoveLeftToCenter");
        } else {
            self->state = ScriptFuncID("EggMobile_MoveRightToCenter");
        }
        break;
        case 15:
        self->state = ScriptFuncID("EggMobile_HandleWingThrowATK");
        objectEntityList[objectLoop + 2].values[0] = 0;
        objectEntityList[objectLoop + 2].state = 1;
        break;
        case 16:
        self->state = ScriptFuncID("EggMobile_WingThrowVertical");
        objectEntityList[objectLoop + 2].values[2] = 0;
        objectEntityList[objectLoop + 2].values[3] = pXPos();
        objectEntityList[objectLoop + 2].values[3] >>= 16;
        objectEntityList[objectLoop + 2].values[3] &= 3;
        objectEntityList[objectLoop + 2].values[3] <<= 2;
        objectEntityList[objectLoop - 4].type = TypeNameID("Blank Object");
        objectEntityList[objectLoop - 3].type = TypeNameID("Blank Object");
        objectEntityList[objectLoop - 2].type = TypeNameID("Blank Object");
        objectEntityList[objectLoop - 1].type = TypeNameID("Blank Object");
        objectEntityList[objectLoop + 2].state = 1;
        break;
        case 17:
        self->state = ScriptFuncID("EggMobile_RestoreWings");
        objectEntityList[objectLoop + 2].state = 1;
        break;
        case 18:
        EggMobile_SetTargetDestiny();
        self->state = ScriptFuncID("EggMobile_ApproachPlayer");
        self->values[6] = -64;
        objectEntityList[objectLoop + 2].state = 0;
        break;
        case 19:
        self->state = ScriptFuncID("EggMobile_ExtendWings");
        break;
        case 20:
        self->state = ScriptFuncID("EggMobile_RetractWings");
        break;
        case 21:
        EggMobile_SetTargetDestiny();
        self->state = ScriptFuncID("EggMobile_ApproachPlayer");
        self->values[6] = -64;
        break;
        case 22:
        self->state = ScriptFuncID("EggMobile_ExtendWings");
        break;
        case 23:
        self->state = ScriptFuncID("EggMobile_RetractWings");
        break;
    }
    if (objectEntityList[objectLoop + 1].values[2] < 23) {
        objectEntityList[objectLoop + 1].values[2]++;
    } else {
        objectEntityList[objectLoop + 1].values[2] = 0;
    }
    objectEntityList[objectLoop + 1].values[3] = 1;
}

void O_R8_EggMobile::Helper1Controller_TwoWings()
{
    Entity *self = Self();

    switch (objectEntityList[objectLoop + 1].values[2]) {
        case 0:
        self->state = ScriptFuncID("EggMobile_MoveToRight");
        self->values[6] = -106;
        self->values[1] = 0x1A000;
        objectEntityList[objectLoop + 2].state = 1;
        break;
        case 1:
        self->state = ScriptFuncID("EggMobile_MoveToLeft");
        break;
        case 2:
        self->state = ScriptFuncID("EggMobile_MoveRightToCenter");
        break;
        case 3:
        self->state = ScriptFuncID("EggMobile_HandleWingThrowATK");
        objectEntityList[objectLoop + 2].values[0] = 0;
        break;
        case 4:
        self->state = ScriptFuncID("EggMobile_WingThrowVertical");
        objectEntityList[objectLoop + 2].values[2] = 0;
        objectEntityList[objectLoop + 2].values[3] = pXPos();
        objectEntityList[objectLoop + 2].values[3] >>= 16;
        objectEntityList[objectLoop + 2].values[3] &= 3;
        objectEntityList[objectLoop + 2].values[3] <<= 2;
        objectEntityList[objectLoop - 4].type = TypeNameID("Blank Object");
        objectEntityList[objectLoop - 3].type = TypeNameID("Blank Object");
        objectEntityList[objectLoop - 2].type = TypeNameID("Blank Object");
        objectEntityList[objectLoop - 1].type = TypeNameID("Blank Object");
        objectEntityList[objectLoop + 2].state = 1;
        break;
        case 5:
        self->state = ScriptFuncID("EggMobile_RestoreWings");
        objectEntityList[objectLoop + 2].state = 1;
        break;
        case 6:
        EggMobile_SetTargetDestiny();
        self->state = ScriptFuncID("EggMobile_ApproachPlayer");
        self->values[6] = -64;
        objectEntityList[objectLoop + 2].state = 0;
        break;
        case 7:
        self->state = ScriptFuncID("EggMobile_ExtendWings");
        break;
        case 8:
        self->state = ScriptFuncID("EggMobile_RetractWings");
        break;
        case 9:
        EggMobile_SetTargetDestiny();
        self->state = ScriptFuncID("EggMobile_ApproachPlayer");
        self->values[6] = -64;
        break;
        case 10:
        self->state = ScriptFuncID("EggMobile_ExtendWings");
        break;
        case 11:
        self->state = ScriptFuncID("EggMobile_RetractWings");
        break;
    }
    if (objectEntityList[objectLoop + 1].values[2] < 11) {
        objectEntityList[objectLoop + 1].values[2]++;
    } else {
        objectEntityList[objectLoop + 1].values[2] = 0;
    }
    objectEntityList[objectLoop + 1].values[3] = 1;
}

void O_R8_EggMobile::Helper1Controller_OneWing()
{
    Entity *self = Self();

    switch (objectEntityList[objectLoop + 1].values[2]) {
        case 0:
        self->state = ScriptFuncID("EggMobile_MoveToRight");
        self->values[6] = -160;
        self->values[1] = 0x1A000;
        objectEntityList[objectLoop + 2].state = 1;
        break;
        case 1:
        self->state = ScriptFuncID("EggMobile_MoveToLeft");
        break;
        case 2:
        self->state = ScriptFuncID("EggMobile_MoveRightToCenter");
        break;
        case 3:
        self->state = ScriptFuncID("EggMobile_HandleWingThrowATK");
        objectEntityList[objectLoop + 2].values[0] = 4;
        self->values[3] >>= 6;
        self->values[3] <<= 6;
        self->values[0] = 0;
        objectEntityList[objectLoop + 1].values[7] = objectEntityList[objectLoop + 3].YPos;
        objectEntityList[objectLoop + 1].values[7] -= 0x440000;
        break;
        case 4:
        self->state = ScriptFuncID("EggMobile_WingThrowDiagonal");
        objectEntityList[objectLoop + 2].values[2] = 0;
        objectEntityList[objectLoop - 4].type = TypeNameID("Blank Object");
        objectEntityList[objectLoop - 3].type = TypeNameID("Blank Object");
        objectEntityList[objectLoop - 2].type = TypeNameID("Blank Object");
        objectEntityList[objectLoop - 1].type = TypeNameID("Blank Object");
        self->values[0] = 0;
        self->values[4] = 0;
        break;
        case 5:
        self->state = ScriptFuncID("EggMobile_RestoreWings");
        break;
        case 6:
        self->state = ScriptFuncID("EggMobile_MoveToRight");
        self->values[6] = -160;
        break;
        case 7:
        self->state = ScriptFuncID("EggMobile_MoveToLeft");
        break;
        case 8:
        self->state = ScriptFuncID("EggMobile_MoveRightToCenter");
        break;
        case 9:
        if (pXPos() > self->XPos) {
            self->state = ScriptFuncID("EggMobile_MoveToLeft");
            self->direction = 1;
        } else {
            self->state = ScriptFuncID("EggMobile_MoveToRight");
            self->direction = 0;
        }
        break;
        case 10:
        self->state = ScriptFuncID("EggMobile_PreparePogoAttack");
        break;
        case 11:
        self->state = ScriptFuncID("EggMobile_PogoAttackAscend");
        objectEntityList[objectLoop + 2].state = 0;
        break;
        case 12:
        if (self->direction == 0) {
            self->state = ScriptFuncID("EggMobile_PogoAttackMoveLeft");
            objectEntityList[objectLoop + 1].values[7] = self->XPos;
            objectEntityList[objectLoop + 1].values[7] -= 0x290000;
        } else {
            self->state = ScriptFuncID("EggMobile_PogoAttackMoveRight");
            objectEntityList[objectLoop + 1].values[7] = self->XPos;
            objectEntityList[objectLoop + 1].values[7] += 0x290000;
        }
        break;
        case 13:
        if (self->direction == 0) {
            self->state = ScriptFuncID("EggMobile_PogoAttackMoveLeft");
            objectEntityList[objectLoop + 1].values[7] -= 0x520000;
        } else {
            self->state = ScriptFuncID("EggMobile_PogoAttackMoveRight");
            objectEntityList[objectLoop + 1].values[7] += 0x520000;
        }
        break;
        case 14:
        if (self->direction == 0) {
            self->state = ScriptFuncID("EggMobile_PogoAttackMoveLeft");
            objectEntityList[objectLoop + 1].values[7] -= 0x520000;
        } else {
            self->state = ScriptFuncID("EggMobile_PogoAttackMoveRight");
            objectEntityList[objectLoop + 1].values[7] += 0x520000;
        }
        break;
        case 15:
        if (self->direction == 0) {
            self->state = ScriptFuncID("EggMobile_PogoAttackMoveRight");
        } else {
            self->state = ScriptFuncID("EggMobile_PogoAttackMoveLeft");
        }
        break;
        case 16:
        if (self->direction == 0) {
            self->state = ScriptFuncID("EggMobile_PogoAttackMoveRight");
            objectEntityList[objectLoop + 1].values[7] += 0x520000;
        } else {
            self->state = ScriptFuncID("EggMobile_PogoAttackMoveLeft");
            objectEntityList[objectLoop + 1].values[7] -= 0x520000;
        }
        break;
        case 17:
        if (self->direction == 0) {
            self->state = ScriptFuncID("EggMobile_PogoAttackMoveRight");
            objectEntityList[objectLoop + 1].values[7] += 0x520000;
        } else {
            self->state = ScriptFuncID("EggMobile_PogoAttackMoveLeft");
            objectEntityList[objectLoop + 1].values[7] -= 0x520000;
        }
        break;
        case 18:
        self->state = ScriptFuncID("EggMobile_PogoAttackDescend");
        break;
    }
    if (objectEntityList[objectLoop + 1].values[2] < 18) {
        objectEntityList[objectLoop + 1].values[2]++;
    } else {
        objectEntityList[objectLoop + 1].values[2] = 0;
    }
    objectEntityList[objectLoop + 1].values[3] = 1;
}

void O_R8_EggMobile::EggMobile_Destroyed()
{
    Entity *self = Self();

    switch (objectEntityList[objectLoop + 2].values[0]) {
        case 0:
        self->values[0]++;
        if (self->values[0] == 90) {
            self->values[0] = 0;
            self->values[1] = 0x14000;
            objectEntityList[objectLoop + 1].values[7] = self->YPos;
            pControlMode() = -1;
            pJumpHold() = 0;
            pRight() = 1;
            pLeft() = 0;
            pUp() = 0;
            pDown() = 0;
            objectEntityList[objectLoop + 2].values[0]++;
            if (playerListPos == 0) {
                if (debugMode == 0) {
                    SetAchievement(9, 100);
                }
            }
        }
        break;
        case 1:
        self->XPos += self->values[1];
        self->YPos = Sin512(self->values[0]);
        self->YPos <<= 9;
        self->YPos += objectEntityList[objectLoop + 1].values[7];
        objectEntityList[objectLoop + 1].values[7] += 0x4000;
        self->values[0] += 4;
        self->values[0] &= 511;
        scriptEng.tempValue[0] = objectEntityList[objectLoop + 1].values[5];
        scriptEng.tempValue[0] += 0x800000;
        if (self->XPos > scriptEng.tempValue[0]) {
            self->values[0] = 0;
            objectEntityList[objectLoop + 4].type = TypeNameID("Amy Rose");
            objectEntityList[objectLoop + 2].values[0]++;
        }
        if (pRight() == 1) {
            scriptEng.tempValue[0] = pCollisionRight();
            scriptEng.tempValue[0] <<= 16;
            scriptEng.tempValue[0] += pXPos();
            scriptEng.tempValue[1] = objectEntityList[objectLoop + 2].values[6];
            scriptEng.tempValue[1] <<= 16;
            if (scriptEng.tempValue[0] > scriptEng.tempValue[1]) {
                pLeft() = 1;
                pRight() = 0;
            }
        } else {
            scriptEng.tempValue[0] = objectEntityList[objectLoop + 1].values[6];
            scriptEng.tempValue[0] += 0x400000;
            if (pXPos() < scriptEng.tempValue[0]) {
                pXPos() = scriptEng.tempValue[0];
                pSpeed() = 0;
                pLeft() = 0;
            }
        }
        break;
        case 2:
        scriptEng.tempValue[0] = objectEntityList[objectLoop + 1].values[6];
        scriptEng.tempValue[0] += 0x400000;
        if (pXPos() < scriptEng.tempValue[0]) {
            pXPos() = scriptEng.tempValue[0];
            pSpeed() = 0;
            pLeft() = 0;
        }
        break;
    }
    scriptEng.tempValue[0] = self->animationTimer;
    scriptEng.tempValue[0] &= 1;
    if (scriptEng.tempValue[0] == 0) {
        if (objectEntityList[objectLoop + 2].values[0] > 0) {
            cameraShakeY = 2;
        }
        scriptEng.tempValue[0] = rand() % 300;
        scriptEng.tempValue[0] -= 150;
        scriptEng.tempValue[0] <<= 16;
        scriptEng.tempValue[0] += objectEntityList[objectLoop + 3].XPos;
        scriptEng.tempValue[1] = rand() % 200;
        scriptEng.tempValue[1] -= 100;
        scriptEng.tempValue[1] <<= 16;
        scriptEng.tempValue[1] += objectEntityList[objectLoop + 3].YPos;
        CreateTempObject(TypeNameID("Explosion"), 0, scriptEng.tempValue[0], scriptEng.tempValue[1]);
        if (self->animationTimer == 0) {
            if (objectEntityList[objectLoop + 5].type == TypeNameID("Blank Object")) {
                PlaySfx(22, 0);
            }
        }
    }
    self->animationTimer++;
    self->animationTimer &= 7;
}

void O_R8_EggMobile::EggMobile_Destroyed_FinalFever()
{
    Entity *self = Self();

    switch (objectEntityList[objectLoop + 2].values[0]) {
        case 0:
        self->values[0]++;
        if (self->values[0] == 30) {
            self->values[0] = 0;
            self->values[1] = 0x20000;
            objectEntityList[objectLoop + 1].values[7] = self->YPos;
            objectEntityList[objectLoop + 2].values[0]++;
        }
        break;
        case 1:
        self->XPos += self->values[1];
        self->YPos = Sin512(self->values[0]);
        self->YPos <<= 9;
        self->YPos += objectEntityList[objectLoop + 1].values[7];
        objectEntityList[objectLoop + 1].values[7] += 0x4000;
        self->values[0] += 4;
        self->values[0] &= 511;
        scriptEng.tempValue[0] = objectEntityList[objectLoop + 1].values[5];
        scriptEng.tempValue[0] += 0x580000;
        if (self->XPos > scriptEng.tempValue[0]) {
            objectEntityList[objectLoop + 2].values[0]++;
            self->values[0] = 0;
            objectEntityList[objectLoop + 2].values[6] += 64;
            pControlMode() = -1;
            pJumpHold() = 0;
            pRight() = 1;
            pLeft() = 0;
            pUp() = 0;
            pDown() = 0;
        }
        break;
        case 2:
        pRight() = 1;
        self->values[0]++;
        if (self->values[0] == 120) {
            objectEntityList[objectLoop + 5].type = TypeNameID("Fade Screen");
            objectEntityList[objectLoop + 5].propertyValue = 1;
        }
        break;
    }
    scriptEng.tempValue[0] = self->animationTimer;
    scriptEng.tempValue[0] &= 3;
    if (scriptEng.tempValue[0] == 0) {
        scriptEng.tempValue[0] = rand() % 64;
        scriptEng.tempValue[0] -= 32;
        scriptEng.tempValue[0] <<= 16;
        scriptEng.tempValue[0] += self->XPos;
        scriptEng.tempValue[1] = rand() % 64;
        scriptEng.tempValue[1] -= 32;
        scriptEng.tempValue[1] <<= 16;
        scriptEng.tempValue[1] += self->YPos;
        CreateTempObject(TypeNameID("Explosion"), 0, scriptEng.tempValue[0], scriptEng.tempValue[1]);
        if (self->animationTimer == 0) {
            if (objectEntityList[objectLoop + 5].type == TypeNameID("Blank Object")) {
                PlaySfx(22, 0);
            }
        }
    }
    self->animationTimer++;
    self->animationTimer &= 7;
}

void O_R8_EggMobile::EggMobile_HandleWingRotation()
{
    Entity *self = Self();

    scriptEng.arrayPosition[0] = objectLoop;
    scriptEng.arrayPosition[0] -= 4;
    scriptEng.tempValue[0] = 0;
    scriptEng.tempValue[1] = self->rotation;
    while (scriptEng.tempValue[0] < 4) {
        if (objectEntityList[scriptEng.arrayPosition[0]].values[5] == 1) {
            objectEntityList[scriptEng.arrayPosition[0]].rotation = scriptEng.tempValue[1];
            objectEntityList[scriptEng.arrayPosition[0]].XPos = Sin512(scriptEng.tempValue[1]);
            objectEntityList[scriptEng.arrayPosition[0]].XPos *= self->values[4];
            objectEntityList[scriptEng.arrayPosition[0]].XPos &= 0xFFFF0000;
            objectEntityList[scriptEng.arrayPosition[0]].XPos += self->XPos;
            objectEntityList[scriptEng.arrayPosition[0]].YPos = Cos512(scriptEng.tempValue[1]);
            scriptEng.tempValue[2] = self->values[4];
            scriptEng.tempValue[2] = -scriptEng.tempValue[2];
            objectEntityList[scriptEng.arrayPosition[0]].YPos *= scriptEng.tempValue[2];
            objectEntityList[scriptEng.arrayPosition[0]].YPos &= 0xFFFF0000;
            objectEntityList[scriptEng.arrayPosition[0]].YPos += self->YPos;
        }
        scriptEng.tempValue[1] += 128;
        scriptEng.tempValue[1] &= 511;
        scriptEng.arrayPosition[0]++;
        scriptEng.tempValue[0]++;
    }
}

void O_R8_EggMobile::EggMobile_DropDamagedWing()
{
    Entity *self = Self();

    scriptEng.tempValue[6] = objectEntityList[scriptEng.arrayPosition[0]].XPos;
    scriptEng.tempValue[6] -= self->XPos;
    scriptEng.tempValue[6] -= 0x180000;
    if (scriptEng.tempValue[0] < 0) {
        scriptEng.tempValue[6] = -scriptEng.tempValue[6];
    }
    scriptEng.tempValue[7] = objectEntityList[scriptEng.arrayPosition[0]].YPos;
    scriptEng.tempValue[7] -= self->YPos;
    scriptEng.tempValue[7] -= 0x440000;
    if (scriptEng.tempValue[7] < 0) {
        scriptEng.tempValue[7] = -scriptEng.tempValue[7];
    }
    scriptEng.tempValue[6] += scriptEng.tempValue[7];
    scriptEng.tempValue[6] >>= 16;
}

void O_R8_EggMobile::EggMobile_HandleAnimations()
{
    scriptEng.tempValue[0] = objectEntityList[objectLoop + 1].animationTimer;
    scriptEng.tempValue[0] >>= 2;
    scriptEng.tempValue[0] &= 1;
    if (scriptEng.tempValue[0] == 1) {
        scriptEng.tempValue[0] = objectEntityList[objectLoop + 1].animationTimer;
        scriptEng.tempValue[0] >>= 3;
        scriptEng.tempValue[0] += 11;
        DrawSprite_Frame(scriptEng.tempValue[0]);
        scriptEng.tempValue[0] += 5;
        DrawSprite_Frame(scriptEng.tempValue[0]);
        scriptEng.tempValue[0] += 5;
        DrawSprite_Frame(scriptEng.tempValue[0]);
        scriptEng.tempValue[0] += 5;
        DrawSprite_Frame(scriptEng.tempValue[0]);
        scriptEng.tempValue[0] += 5;
        DrawSprite_Frame(scriptEng.tempValue[0]);
        scriptEng.tempValue[0] += 5;
        DrawSprite_Frame(scriptEng.tempValue[0]);
        scriptEng.tempValue[0] += 5;
        DrawSprite_Frame(scriptEng.tempValue[0]);
    }
    objectEntityList[objectLoop + 1].animationTimer++;
    objectEntityList[objectLoop + 1].animationTimer %= 40;
}

const Native::NativeFunctionDef O_R8_EggMobile::funcs[32] = {
    { "EggMobile_StopMovement", O_R8_EggMobile::EggMobile_StopMovement },
    { "EggMobile_MoveToLeft", O_R8_EggMobile::EggMobile_MoveToLeft },
    { "EggMobile_MoveToRight", O_R8_EggMobile::EggMobile_MoveToRight },
    { "EggMobile_GroundSpinAscend", O_R8_EggMobile::EggMobile_GroundSpinAscend },
    { "EggMobile_GroundSpinDescend", O_R8_EggMobile::EggMobile_GroundSpinDescend },
    { "EggMobile_MoveLeftToCenter", O_R8_EggMobile::EggMobile_MoveLeftToCenter },
    { "EggMobile_MoveRightToCenter", O_R8_EggMobile::EggMobile_MoveRightToCenter },
    { "EggMobile_GroundSpinLeft", O_R8_EggMobile::EggMobile_GroundSpinLeft },
    { "EggMobile_GroundSpinRight", O_R8_EggMobile::EggMobile_GroundSpinRight },
    { "EggMobile_HandleWingThrowATK", O_R8_EggMobile::EggMobile_HandleWingThrowATK },
    { "EggMobile_WingThrowVertical", O_R8_EggMobile::EggMobile_WingThrowVertical },
    { "EggMobile_WingThrowDiagonal", O_R8_EggMobile::EggMobile_WingThrowDiagonal },
    { "EggMobile_RestoreWings", O_R8_EggMobile::EggMobile_RestoreWings },
    { "EggMobile_SetTargetDestiny", O_R8_EggMobile::EggMobile_SetTargetDestiny },
    { "EggMobile_ApproachPlayer", O_R8_EggMobile::EggMobile_ApproachPlayer },
    { "EggMobile_ExtendWings", O_R8_EggMobile::EggMobile_ExtendWings },
    { "EggMobile_RetractWings", O_R8_EggMobile::EggMobile_RetractWings },
    { "EggMobile_Hit", O_R8_EggMobile::EggMobile_Hit },
    { "EggMobile_PreparePogoAttack", O_R8_EggMobile::EggMobile_PreparePogoAttack },
    { "EggMobile_PogoAttackDescend", O_R8_EggMobile::EggMobile_PogoAttackDescend },
    { "EggMobile_PogoAttackAscend", O_R8_EggMobile::EggMobile_PogoAttackAscend },
    { "EggMobile_PogoAttackMoveLeft", O_R8_EggMobile::EggMobile_PogoAttackMoveLeft },
    { "EggMobile_PogoAttackMoveRight", O_R8_EggMobile::EggMobile_PogoAttackMoveRight },
    { "Helper1Controller_FourWings", O_R8_EggMobile::Helper1Controller_FourWings },
    { "Helper1Controller_ThreeWings", O_R8_EggMobile::Helper1Controller_ThreeWings },
    { "Helper1Controller_TwoWings", O_R8_EggMobile::Helper1Controller_TwoWings },
    { "Helper1Controller_OneWing", O_R8_EggMobile::Helper1Controller_OneWing },
    { "EggMobile_Destroyed", O_R8_EggMobile::EggMobile_Destroyed },
    { "EggMobile_Destroyed_FinalFever", O_R8_EggMobile::EggMobile_Destroyed_FinalFever },
    { "EggMobile_HandleWingRotation", O_R8_EggMobile::EggMobile_HandleWingRotation },
    { "EggMobile_DropDamagedWing", O_R8_EggMobile::EggMobile_DropDamagedWing },
    { "EggMobile_HandleAnimations", O_R8_EggMobile::EggMobile_HandleAnimations },
};

#endif // RETRO_USE_NATIVE_OBJECTS

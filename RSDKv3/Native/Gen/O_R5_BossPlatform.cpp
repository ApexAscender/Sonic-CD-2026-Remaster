#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R5_BossPlatform.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from BossPlatform.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R5_BossPlatform::ObjectStartup()
{
    LoadSpriteSheet("R5/Objects2.gif");
    AddSpriteFrame(-32, -48, 64, 48, 1, 50);
    AddSpriteFrame(-32, 0, 64, 32, 1, 98);
    AddSpriteFrame(-32, 0, 64, 32, 1, 131);
    AddSpriteFrame(-32, 0, 64, 24, 1, 164);
    AddSpriteFrame(-32, 0, 64, 16, 1, 189);
    AddSpriteFrame(-32, 0, 64, 8, 1, 206);
    AddSpriteFrame(-32, -48, 26, 24, 1, 215);
    AddSpriteFrame(-32, -48, 64, 56, 75, 50);
}

void O_R5_BossPlatform::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 1:
        if (self->values[0] < 60) {
            self->values[0]++;
            scriptEng.tempValue[0] = self->values[0];
            scriptEng.tempValue[0] &= 1;
            if (scriptEng.tempValue[0] == 1) {
                self->YPos += 0x20000;
            } else {
                self->YPos -= 0x20000;
            }
        } else {
            self->values[0] = 0;
            self->state = 2;
            objectEntityList[objectLoop - 1].state = 2;
            objectEntityList[objectLoop - 1].frame = 0;
            objectEntityList[objectLoop - 1].values[0] = 0;
        }
        objectEntityList[objectLoop - 1].YPos = self->YPos;
        objectEntityList[objectLoop - 1].YPos -= 0x1C0000;
        objectEntityList[objectLoop - 2].YPos = self->YPos;
        BossPlatform_Conveyor_Update();
        self->XPos = self->values[1];
        objectEntityList[objectLoop - 2].XPos = self->values[1];
        break;
        case 2:
        self->values[2] += 0x1800;
        self->YPos += self->values[2];
        ObjectTileCollision_Script(0, 0, 31, 0);
        if (CheckResult() == 1) {
            cameraShakeY = 4;
            PlaySfx(globalSFXCount + 4, 0);
            if (self->values[0] < 1) {
                self->values[0]++;
                self->values[2] >>= 1;
                self->values[2] = -self->values[2];
            } else {
                self->state = 3;
                objectEntityList[objectLoop - 1].state = 0;
                self->values[0] = 0;
                self->values[5] = 0;
            }
            scriptEng.tempValue[0] = 0x130000;
            BossPlatform_SpawnLandingSparks();
            HapticEffect_Script(97, 0, 0, 0);
        }
        objectEntityList[objectLoop - 1].YPos = self->YPos;
        objectEntityList[objectLoop - 1].YPos -= 0x1C0000;
        objectEntityList[objectLoop - 2].YPos = self->YPos;
        BossPlatform_Conveyor_Update();
        self->XPos = self->values[1];
        objectEntityList[objectLoop - 2].XPos = self->values[1];
        break;
        case 3:
        BossPlatform_Conveyor_Update();
        if (self->values[5] > 2399) {
            self->state++;
        }
        if (self->values[6] > 47) {
            self->values[6] %= 48;
            CreateTempObject(TypeNameID("Boss Spark"), 0, self->XPos, self->YPos);
            objectEntityList[scriptEng.arrayPosition[2]].XPos += 0x180000;
            objectEntityList[scriptEng.arrayPosition[2]].YPos += 0x1B0000;
            objectEntityList[scriptEng.arrayPosition[2]].values[1] = -0x10000;
        }
        break;
        case 4:
        self->values[2] += 0x1800;
        self->YPos += self->values[2];
        ObjectTileCollision_Script(0, 0, 23, 0);
        if (CheckResult() == 1) {
            cameraShakeY = 4;
            PlaySfx(globalSFXCount + 4, 0);
            if (self->values[0] < 1) {
                self->values[0]++;
                self->values[2] >>= 1;
                self->values[2] = -self->values[2];
            } else {
                self->state = 5;
                self->values[0] = 0;
                self->values[5] = 0;
            }
            scriptEng.tempValue[0] = 0xB0000;
            BossPlatform_SpawnLandingSparks();
            HapticEffect_Script(97, 0, 0, 0);
        }
        objectEntityList[objectLoop - 1].YPos = self->YPos;
        objectEntityList[objectLoop - 1].YPos -= 0x1C0000;
        objectEntityList[objectLoop - 2].YPos = self->YPos;
        BossPlatform_Conveyor_Update();
        break;
        case 5:
        BossPlatform_Conveyor_Update();
        if (self->values[5] > 2399) {
            self->state++;
        }
        if (self->values[6] > 47) {
            self->values[6] %= 48;
            CreateTempObject(TypeNameID("Boss Spark"), 0, self->XPos, self->YPos);
            objectEntityList[scriptEng.arrayPosition[2]].XPos += 0x180000;
            objectEntityList[scriptEng.arrayPosition[2]].YPos += 0x130000;
            objectEntityList[scriptEng.arrayPosition[2]].values[1] = -0x10000;
        }
        break;
        case 6:
        self->values[2] += 0x1800;
        self->YPos += self->values[2];
        ObjectTileCollision_Script(0, 0, 15, 0);
        if (CheckResult() == 1) {
            cameraShakeY = 4;
            PlaySfx(globalSFXCount + 4, 0);
            if (self->values[0] < 1) {
                self->values[0]++;
                self->values[2] >>= 1;
                self->values[2] = -self->values[2];
            } else {
                self->state = 7;
                self->values[0] = 0;
                self->values[5] = 0;
            }
            scriptEng.tempValue[0] = 0x30000;
            BossPlatform_SpawnLandingSparks();
            HapticEffect_Script(97, 0, 0, 0);
        }
        objectEntityList[objectLoop - 1].YPos = self->YPos;
        objectEntityList[objectLoop - 1].YPos -= 0x1C0000;
        objectEntityList[objectLoop - 2].YPos = self->YPos;
        BossPlatform_Conveyor_Update();
        break;
        case 7:
        BossPlatform_Conveyor_Update();
        if (self->values[5] > 2399) {
            self->state++;
            objectEntityList[objectLoop - 1].state = 3;
            objectEntityList[objectLoop - 1].frame = 0;
            objectEntityList[objectLoop - 1].values[0] = 0;
        }
        if (self->values[6] > 47) {
            self->values[6] %= 48;
            CreateTempObject(TypeNameID("Boss Spark"), 0, self->XPos, self->YPos);
            objectEntityList[scriptEng.arrayPosition[2]].XPos += 0x180000;
            objectEntityList[scriptEng.arrayPosition[2]].YPos += 0xB0000;
            objectEntityList[scriptEng.arrayPosition[2]].values[1] = -0x10000;
        }
        break;
        case 8:
        self->values[2] += 0x1800;
        self->YPos += self->values[2];
        ObjectTileCollision_Script(0, 0, 7, 0);
        if (CheckResult() == 1) {
            cameraShakeY = 4;
            PlaySfx(globalSFXCount + 4, 0);
            if (self->values[0] < 1) {
                self->values[0]++;
                self->values[2] >>= 1;
                self->values[2] = -self->values[2];
            } else {
                self->state = 9;
                self->values[0] = 0;
                self->values[5] = 0;
            }
            scriptEng.tempValue[0] = -0x30000;
            BossPlatform_SpawnLandingSparks();
            HapticEffect_Script(97, 0, 0, 0);
        }
        objectEntityList[objectLoop - 1].YPos = self->YPos;
        objectEntityList[objectLoop - 1].YPos -= 0x1C0000;
        objectEntityList[objectLoop - 2].YPos = self->YPos;
        BossPlatform_Conveyor_Update();
        break;
        case 9:
        BossPlatform_Conveyor_Update();
        if (self->values[5] > 2399) {
            self->state++;
            objectEntityList[objectLoop - 1].state = 6;
            objectEntityList[objectLoop - 1].frame = 0;
            objectEntityList[objectLoop - 1].values[0] = 0;
            objectEntityList[objectLoop - 1].drawOrder = 4;
            self->XPos = self->values[1];
            objectEntityList[objectLoop - 2].XPos = self->XPos;
            self->values[0] = 0;
        }
        if (self->values[6] > 47) {
            self->values[6] %= 48;
            CreateTempObject(TypeNameID("Boss Spark"), 0, self->XPos, self->YPos);
            objectEntityList[scriptEng.arrayPosition[2]].XPos += 0x180000;
            objectEntityList[scriptEng.arrayPosition[2]].YPos += 0x30000;
            objectEntityList[scriptEng.arrayPosition[2]].values[1] = -0x10000;
        }
        break;
        case 10:
        if (self->values[0] == 19) {
            self->values[0] = 0;
            scriptEng.tempValue[0] = -0x30000;
            BossPlatform_SpawnLandingSparks();
        }
        self->values[0]++;
        if (self->values[3] > 0) {
            BossPlatform_Conveyor_WindDown();
            xBoundary2 += 4;
        } else {
            newXBoundary2 = objectEntityList[objectLoop - 3].values[2];
            self->state++;
            self->values[0] = 0;
            self->inkEffect = 2;
            objectEntityList[objectLoop - 3].inkEffect = 2;
            HapticEffect_Script(97, 0, 0, 0);
        }
        break;
        case 11:
        scriptEng.tempValue[0] = Sin512(self->values[0]);
        scriptEng.tempValue[0] /= 3;
        if (scriptEng.tempValue[0] < 0) {
            scriptEng.tempValue[0] = -scriptEng.tempValue[0];
        }
        if (scriptEng.tempValue[0] > 255) {
            scriptEng.tempValue[0] = 255;
        }
        self->alpha = scriptEng.tempValue[0];
        objectEntityList[objectLoop - 3].alpha = scriptEng.tempValue[0];
        scriptEng.tempValue[0] = self->values[0];
        scriptEng.tempValue[0] &= 127;
        if (scriptEng.tempValue[0] == 0) {
            CreateTempObject(TypeNameID("Boss Explosion"), 0, self->XPos, self->YPos);
            objectEntityList[scriptEng.arrayPosition[2]].XPos -= 0x200000;
            objectEntityList[scriptEng.arrayPosition[2]].YPos -= 0x100000;
        }
        if (scriptEng.tempValue[0] == 32) {
            CreateTempObject(TypeNameID("Boss Explosion"), 0, self->XPos, self->YPos);
            objectEntityList[scriptEng.arrayPosition[2]].XPos -= 0x100000;
        }
        if (scriptEng.tempValue[0] == 64) {
            CreateTempObject(TypeNameID("Boss Explosion"), 0, self->XPos, self->YPos);
            objectEntityList[scriptEng.arrayPosition[2]].XPos += 0x200000;
            objectEntityList[scriptEng.arrayPosition[2]].YPos -= 0x100000;
        }
        scriptEng.tempValue[0] = self->values[0];
        scriptEng.tempValue[0] &= 31;
        if (scriptEng.tempValue[0] == 0) {
            PlaySfx(22, 0);
        }
        self->values[0] += 8;
        if (self->values[0] > 960) {
            GVar("Player.Score") += 1000;
            CreateTempObject(TypeNameID("Fade Music"), 1, 0, 0);
            scriptEng.tempValue[0] = objectLoop;
            ResetObjectEntity(scriptEng.tempValue[0], TypeNameID("Blank Object"), 0, 0, 0);
            scriptEng.tempValue[0]--;
            ResetObjectEntity(scriptEng.tempValue[0], TypeNameID("Blank Object"), 0, 0, 0);
            scriptEng.tempValue[0]--;
            ResetObjectEntity(scriptEng.tempValue[0], TypeNameID("Blank Object"), 0, 0, 0);
            scriptEng.tempValue[0]--;
            ResetObjectEntity(scriptEng.tempValue[0], TypeNameID("Blank Object"), 0, 0, 0);
            scriptEng.tempValue[0]--;
            ResetObjectEntity(scriptEng.tempValue[0], TypeNameID("Blank Object"), 0, 0, 0);
            scriptEng.tempValue[0]--;
            ResetObjectEntity(scriptEng.tempValue[0], TypeNameID("Blank Object"), 0, 0, 0);
        }
        break;
    }
}

void O_R5_BossPlatform::ObjectPlayerInteraction()
{
    Entity *self = Self();

    if (self->state == 0) {
        PlayerObjectCollision(C_TOUCH, -32, -48, 32, 32);
        if (CheckResult() == 1) {
            pXVel() = -pXVel();
            pYVel() = -pYVel();
            scriptEng.tempValue[0] = pXVel();
            scriptEng.tempValue[1] = pYVel();
            pSpeed() = scriptEng.tempValue[0];
            pXVel() = scriptEng.tempValue[0];
            pYVel() = scriptEng.tempValue[1];
            self->state = 1;
            self->values[1] = self->XPos;
            objectEntityList[objectLoop - 3].state = 1;
            objectEntityList[objectLoop - 4].state = 3;
            PlaySfx(globalSFXCount + 3, 0);
            HapticEffect_Script(97, 0, 0, 0);
        }
    } else {
        PlayerObjectCollision(C_BOX, -32, -256, 32, 24);
    }
}

void O_R5_BossPlatform::ObjectDraw()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        case 1:
        case 2:
        DrawSprite_Frame(0);
        DrawSprite_Frame(1);
        break;
        case 3:
        DrawSprite_Frame(0);
        DrawSprite_Frame(2);
        break;
        case 4:
        case 5:
        DrawSprite_Frame(0);
        DrawSprite_Frame(3);
        break;
        case 6:
        case 7:
        DrawSprite_Frame(0);
        DrawSprite_Frame(4);
        break;
        case 8:
        case 9:
        DrawSprite_Frame(0);
        DrawSprite_Frame(5);
        break;
        case 10:
        DrawSprite_Frame(0);
        DrawSprite_Frame(5);
        DrawSprite_Frame(6);
        break;
        case 11:
        DrawSprite_Frame(0);
        DrawSprite_Frame(5);
        DrawSprite_Frame(6);
        DrawSpriteFX_Script(7, FX_INK, self->XPos, self->YPos);
        break;
    }
}

void O_R5_BossPlatform::BossPlatform_Conveyor_Update()
{
    Entity *self = Self();

    if (pGravity() == 0) {
        if (pObjectInteractions() == 1) {
            if (pSpeed() > self->values[3]) {
                self->values[3] += 0x600;
                if (self->values[3] > 0x5D000) {
                    self->values[3] = 0x5D000;
                }
            } else {
                self->values[3] -= 0x600;
                if (self->values[3] < 0xC000) {
                    self->values[3] = 0xC000;
                }
            }
            scriptEng.tempValue[0] = -0x20000;
            scriptEng.tempValue[0] += self->values[3];
            if (scriptEng.tempValue[0] > 0) {
                scriptEng.tempValue[0] = 0;
            }
            if (pSpeed() < scriptEng.tempValue[0]) {
                pSpeed() = scriptEng.tempValue[0];
                pXVel() = scriptEng.tempValue[0];
            }
            pXPos() -= self->values[3];
        }
    } else {
        if (pState() == PlayerStateID("Player_State_Fly")) {
            self->values[3] -= 0x800;
        } else {
            self->values[3] -= 0x100;
        }
        if (self->values[3] < 0xC000) {
            self->values[3] = 0xC000;
        }
        if (pJumpPress() == 1) {
            scriptEng.tempValue[0] = pJumpStrength();
            scriptEng.tempValue[0] = -scriptEng.tempValue[0];
            if (pYVel() == scriptEng.tempValue[0]) {
                pXVel() = 0;
                pSpeed() = 0;
            }
        }
    }
    scriptEng.tempValue[0] = self->values[3];
    scriptEng.tempValue[0] -= 0xC000;
    scriptEng.tempValue[0] /= 0x1B000;
    switch (scriptEng.tempValue[0]) {
        case 0:
        self->values[4]++;
        self->values[5]++;
        self->values[6]++;
        self->XPos = self->values[1];
        objectEntityList[objectLoop - 2].XPos = self->XPos;
        break;
        case 1:
        self->values[4] += 2;
        self->values[5] += 2;
        self->values[6] += 4;
        scriptEng.tempValue[1] = GVar("Oscillation");
        scriptEng.tempValue[1] &= 1;
        if (scriptEng.tempValue[1] == 1) {
            self->XPos = self->values[1];
            self->XPos -= 0x10000;
        } else {
            self->XPos = self->values[1];
        }
        objectEntityList[objectLoop - 2].XPos = self->XPos;
        break;
        case 2:
        case 3:
        self->values[4] += 4;
        self->values[5] += 4;
        self->values[6] += 8;
        scriptEng.tempValue[1] = GVar("Oscillation");
        scriptEng.tempValue[1] &= 1;
        if (scriptEng.tempValue[1] == 1) {
            self->XPos = self->values[1];
            self->XPos -= 0x10000;
        } else {
            self->XPos = self->values[1];
            self->XPos += 0x10000;
        }
        objectEntityList[objectLoop - 2].XPos = self->XPos;
        break;
    }
    if (self->values[4] > 3) {
        self->values[4] = 0;
        self->values[7]--;
        if (self->values[7] < 0) {
            self->values[7] = 2;
        }
        SetActivePalette(self->values[7], 0, SCREEN_YSIZE);
    }
    scriptEng.tempValue[0] = pCollisionLeft();
    scriptEng.tempValue[0] <<= 16;
    scriptEng.tempValue[0] += pXPos();
    if (scriptEng.tempValue[0] < objectEntityList[objectLoop - 6].XPos) {
        pXPos() = objectEntityList[objectLoop - 6].XPos;
        scriptEng.tempValue[0] = pCollisionLeft();
        scriptEng.tempValue[0] <<= 16;
        pXPos() -= scriptEng.tempValue[0];
    }
    scriptEng.tempValue[0] = pCollisionRight();
    scriptEng.tempValue[0] <<= 16;
    scriptEng.tempValue[0] += pXPos();
    scriptEng.tempValue[1] = objectEntityList[objectLoop - 3].values[1];
    if (scriptEng.tempValue[0] > scriptEng.tempValue[1]) {
        pXPos() = scriptEng.tempValue[1];
        scriptEng.tempValue[0] = pCollisionRight();
        scriptEng.tempValue[0] <<= 16;
        pXPos() -= scriptEng.tempValue[0];
        if (pState() == PlayerStateID("Player_State_Fly")) {
            pSpeed() = 0;
            pXVel() = 0;
        }
    }
}

void O_R5_BossPlatform::BossPlatform_Conveyor_WindDown()
{
    Entity *self = Self();

    self->values[3] -= 0x1000;
    if (self->values[3] < 0) {
        self->values[3] = 0;
    }
    if (pGravity() == 0) {
        if (pObjectInteractions() == 1) {
            scriptEng.tempValue[0] = -0x20000;
            scriptEng.tempValue[0] += self->values[3];
            if (scriptEng.tempValue[0] > 0) {
                scriptEng.tempValue[0] = 0;
            }
            if (pSpeed() < scriptEng.tempValue[0]) {
                pSpeed() = scriptEng.tempValue[0];
                pXVel() = scriptEng.tempValue[0];
            }
            pXPos() -= self->values[3];
        }
    } else {
        if (pJumpPress() == 1) {
            scriptEng.tempValue[0] = pJumpStrength();
            scriptEng.tempValue[0] = -scriptEng.tempValue[0];
            if (pYVel() == scriptEng.tempValue[0]) {
                pXVel() = 0;
                pSpeed() = 0;
            }
        }
    }
    scriptEng.tempValue[0] = self->values[3];
    scriptEng.tempValue[0] /= 0x1B000;
    switch (scriptEng.tempValue[0]) {
        case 0:
        self->values[4]++;
        self->values[5]++;
        self->values[6]++;
        break;
        case 1:
        self->values[4] += 2;
        self->values[5] += 2;
        self->values[6] += 4;
        break;
        case 2:
        case 3:
        self->values[4] += 4;
        self->values[5] += 4;
        self->values[6] += 8;
        break;
    }
    if (self->values[4] > 3) {
        self->values[4] = 0;
        self->values[7]--;
        if (self->values[7] < 0) {
            self->values[7] = 2;
        }
        SetActivePalette(self->values[7], 0, SCREEN_YSIZE);
    }
    scriptEng.tempValue[0] = pCollisionLeft();
    scriptEng.tempValue[0] <<= 16;
    scriptEng.tempValue[0] += pXPos();
    if (scriptEng.tempValue[0] < objectEntityList[objectLoop - 6].XPos) {
        pXPos() = objectEntityList[objectLoop - 6].XPos;
        scriptEng.tempValue[0] = pCollisionLeft();
        scriptEng.tempValue[0] <<= 16;
        pXPos() -= scriptEng.tempValue[0];
    }
}

void O_R5_BossPlatform::BossPlatform_SpawnLandingSparks()
{
    Entity *self = Self();

    CreateTempObject(TypeNameID("Boss Spark"), 1, self->XPos, self->YPos);
    objectEntityList[scriptEng.arrayPosition[2]].XPos -= 0x100000;
    objectEntityList[scriptEng.arrayPosition[2]].YPos += scriptEng.tempValue[0];
    objectEntityList[scriptEng.arrayPosition[2]].values[1] = -0x10000;
    objectEntityList[scriptEng.arrayPosition[2]].values[2] = -0x18000;
    CreateTempObject(TypeNameID("Boss Spark"), 1, self->XPos, self->YPos);
    objectEntityList[scriptEng.arrayPosition[2]].XPos += 0x100000;
    objectEntityList[scriptEng.arrayPosition[2]].YPos += scriptEng.tempValue[0];
    objectEntityList[scriptEng.arrayPosition[2]].values[1] = -0x10000;
    objectEntityList[scriptEng.arrayPosition[2]].values[2] = -0x18000;
    scriptEng.tempValue[0] += 0x80000;
    CreateTempObject(TypeNameID("Boss Spark"), 1, self->XPos, self->YPos);
    objectEntityList[scriptEng.arrayPosition[2]].XPos -= 0x180000;
    objectEntityList[scriptEng.arrayPosition[2]].YPos += scriptEng.tempValue[0];
    objectEntityList[scriptEng.arrayPosition[2]].values[1] = -0x10000;
    objectEntityList[scriptEng.arrayPosition[2]].values[2] = -0x18000;
    CreateTempObject(TypeNameID("Boss Spark"), 1, self->XPos, self->YPos);
    objectEntityList[scriptEng.arrayPosition[2]].XPos -= 0x40000;
    objectEntityList[scriptEng.arrayPosition[2]].YPos += scriptEng.tempValue[0];
    objectEntityList[scriptEng.arrayPosition[2]].values[1] = -0x10000;
    objectEntityList[scriptEng.arrayPosition[2]].values[2] = -0x18000;
    CreateTempObject(TypeNameID("Boss Spark"), 1, self->XPos, self->YPos);
    objectEntityList[scriptEng.arrayPosition[2]].XPos += 0x180000;
    objectEntityList[scriptEng.arrayPosition[2]].YPos += scriptEng.tempValue[0];
    objectEntityList[scriptEng.arrayPosition[2]].values[1] = -0x10000;
    objectEntityList[scriptEng.arrayPosition[2]].values[2] = -0x18000;
    CreateTempObject(TypeNameID("Boss Spark"), 1, self->XPos, self->YPos);
    objectEntityList[scriptEng.arrayPosition[2]].XPos += 0x40000;
    objectEntityList[scriptEng.arrayPosition[2]].YPos += scriptEng.tempValue[0];
    objectEntityList[scriptEng.arrayPosition[2]].values[1] = -0x10000;
    objectEntityList[scriptEng.arrayPosition[2]].values[2] = -0x18000;
    scriptEng.tempValue[0] += 0x80000;
    CreateTempObject(TypeNameID("Boss Spark"), 1, self->XPos, self->YPos);
    objectEntityList[scriptEng.arrayPosition[2]].XPos -= 0x100000;
    objectEntityList[scriptEng.arrayPosition[2]].YPos += scriptEng.tempValue[0];
    objectEntityList[scriptEng.arrayPosition[2]].values[1] = -0x10000;
    objectEntityList[scriptEng.arrayPosition[2]].values[2] = -0x18000;
    CreateTempObject(TypeNameID("Boss Spark"), 1, self->XPos, self->YPos);
    objectEntityList[scriptEng.arrayPosition[2]].XPos += 0x100000;
    objectEntityList[scriptEng.arrayPosition[2]].YPos += scriptEng.tempValue[0];
    objectEntityList[scriptEng.arrayPosition[2]].values[1] = -0x10000;
    objectEntityList[scriptEng.arrayPosition[2]].values[2] = -0x18000;
}

const Native::NativeFunctionDef O_R5_BossPlatform::funcs[3] = {
    { "BossPlatform_Conveyor_Update", O_R5_BossPlatform::BossPlatform_Conveyor_Update },
    { "BossPlatform_Conveyor_WindDown", O_R5_BossPlatform::BossPlatform_Conveyor_WindDown },
    { "BossPlatform_SpawnLandingSparks", O_R5_BossPlatform::BossPlatform_SpawnLandingSparks },
};

#endif // RETRO_USE_NATIVE_OBJECTS

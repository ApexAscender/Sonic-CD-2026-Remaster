#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R7_MetalSonic.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from MetalSonic.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R7_MetalSonic::ObjectStartup()
{
    LoadSpriteSheet("R7/Objects3.gif");
    LoadAnimation_Script("MetalSonic.Ani");
    AddSpriteFrame(0, 0, 0, 0, 1, 83);
    AddSpriteFrame(-12, 3, 16, 16, 1, 83);
    AddSpriteFrame(0, 0, 0, 0, 1, 83);
    AddSpriteFrame(-12, 3, 16, 16, 18, 83);
    AddSpriteFrame(0, 0, 0, 0, 1, 83);
    AddSpriteFrame(-14, -8, 16, 16, 18, 83);
    AddSpriteFrame(0, 0, 0, 0, 1, 83);
    AddSpriteFrame(-18, -12, 24, 24, 1, 100);
    AddSpriteFrame(0, 0, 0, 0, 1, 83);
    AddSpriteFrame(-18, -12, 24, 24, 1, 100);
    AddSpriteFrame(0, 0, 0, 0, 1, 83);
    AddSpriteFrame(-22, -16, 32, 32, 1, 125);
    AddSpriteFrame(-24, -28, 48, 48, 150, 75);
    AddSpriteFrame(-24, -28, 48, 48, 150, 75);
    AddSpriteFrame(-24, -28, 48, 48, 150, 75);
    AddSpriteFrame(-24, -28, 48, 48, 150, 75);
    AddSpriteFrame(0, 0, 0, 0, 1, 83);
    AddSpriteFrame(-24, -28, 48, 48, 199, 75);
    AddSpriteFrame(-24, -28, 48, 48, 199, 75);
    AddSpriteFrame(-24, -28, 48, 48, 199, 75);
    AddSpriteFrame(-24, -28, 48, 48, 199, 75);
    AddSpriteFrame(0, 0, 0, 0, 1, 83);
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Metal Sonic")) {
            GVar("MetalSonic_EntityNo") = scriptEng.arrayPosition[0];
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_R7_MetalSonic::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        if (self->animation == 0) {
            if (pJumpPress() == 1) {
                self->values[0] = 120;
                self->animation = 1;
            }
        } else {
            if (self->values[0] > 0) {
                self->values[0]--;
            } else {
                self->animation = 0;
            }
        }
        break;
        case 1:
        if (self->values[0] < 140) {
            self->values[0]++;
        } else {
            self->priority = 1;
            self->values[0] = 0;
            self->values[3] = 1;
            self->values[4] = 0;
            self->state++;
        }
        break;
        case 2:
        if (self->values[0] < 204) {
            self->values[0]++;
        } else {
            self->values[0] = 0;
            self->values[3] = 2;
            self->animation = 4;
            self->values[1] = 0x40000;
            GVar("Player.HeavyMetalFlag") = 1;
            self->state++;
        }
        break;
        case 3:
        scriptEng.tempValue[0] = objectEntityList[objectLoop - 2].XPos;
        scriptEng.tempValue[0] -= 0x7000000;
        if (self->XPos < scriptEng.tempValue[0]) {
            scriptEng.tempValue[0] = self->XPos;
            scriptEng.tempValue[0] -= pXPos();
            scriptEng.tempValue[0] >>= 6;
            self->values[1] = 0x40000;
            self->values[1] -= scriptEng.tempValue[0];
            if (self->values[1] < 0x20000) {
                self->values[1] = 0x20000;
            }
            if (self->values[1] > 0x60000) {
                self->values[1] = 0x60000;
            }
            if (self->values[1] < 0x3C000) {
                self->values[3] = 2;
                self->animation = 3;
            } else {
                self->values[3] = 3;
                self->animation = 4;
            }
            if (self->values[0] < 180) {
                self->values[0]++;
            } else {
                self->animation = 9;
                self->values[0] = 0;
                self->values[3] = 1;
                self->state++;
                PlaySfx(globalSFXCount + 4, 0);
            }
        } else {
            scriptEng.tempValue[0] = self->XPos;
            scriptEng.tempValue[0] -= pXPos();
            scriptEng.tempValue[0] >>= 6;
            self->values[1] = 0x40000;
            self->values[1] -= scriptEng.tempValue[0];
            if (self->values[1] < 0x20000) {
                self->values[1] = 0x20000;
            }
            if (self->values[1] > 0x60000) {
                self->values[1] = 0x60000;
            }
            if (self->values[1] < 0x3C000) {
                self->values[3] = 2;
                self->animation = 3;
            } else {
                self->values[3] = 3;
                self->animation = 4;
            }
        }
        break;
        case 4:
        if (self->values[0] < 60) {
            self->values[0]++;
        } else {
            self->values[0] = 0;
            if (pXPos() > self->XPos) {
                self->state = 6;
                self->animation = 6;
                self->values[3] = 0;
                self->values[4] = 0;
                PlaySfx(globalSFXCount + 6, 0);
                HapticEffect_Script(55, 0, 0, 0);
            } else {
                self->state = 5;
                self->values[1] = 0x20000;
                self->animation = 5;
                self->values[3] = 4;
                self->values[4] = 0;
                PlaySfx(globalSFXCount + 5, 0);
                HapticEffect_Script(60, 0, 0, 0);
            }
        }
        break;
        case 5:
        if (self->values[0] < 180) {
            self->values[0]++;
            scriptEng.tempValue[0] = objectEntityList[objectLoop - 1].XPos;
            scriptEng.tempValue[0] += 0x400000;
            if (self->XPos < scriptEng.tempValue[0]) {
                self->state = 6;
                self->values[0] = 60;
                self->animation = 7;
                self->values[3] = 0;
                self->values[4] = 0;
                PlaySfx(globalSFXCount + 6, 0);
                HapticEffect_Script(55, 0, 0, 0);
            }
        } else {
            self->values[0] = 0;
            self->state = 3;
            self->values[4] = 0;
        }
        break;
        case 6:
        self->values[1] += 0x800;
        if (self->values[1] > 0x80000) {
            self->values[1] = 0x80000;
        }
        if (self->values[0] < 180) {
            self->values[0]++;
            if (self->values[0] == 10) {
                self->animation = 7;
            }
        } else {
            self->values[0] = 0;
            self->state = 3;
        }
        break;
        case 7:
        if (pAnimation() == GVar("ANI_DYING")) {
            self->animation = 1;
        }
        break;
        case 8:
        self->values[2] += 0x3800;
        self->YPos += self->values[2];
        if (self->values[2] > 0x100000) {
            ResetObjectEntity(objectLoop, TypeNameID("Blank Object"), 0, 0, 0);
        }
        break;
    }
    if (self->values[1] > 0) {
        scriptEng.tempValue[0] = objectEntityList[objectLoop - 1].XPos;
        scriptEng.tempValue[0] += 0x400000;
        if (self->XPos < scriptEng.tempValue[0]) {
            self->XPos = scriptEng.tempValue[0];
        }
        if (self->values[1] > 0x30000) {
            scriptEng.tempValue[0] = self->values[1];
            scriptEng.tempValue[0] -= 0x30000;
            self->XPos += 0x30000;
            MetalSonic_FollowGround();
            self->XPos += scriptEng.tempValue[0];
            MetalSonic_FollowGround();
        } else {
            self->XPos += self->values[1];
            MetalSonic_FollowGround();
        }
        if (CheckResult() == 1) {
            self->values[2] = 0;
        } else {
            self->values[2] += 0x3800;
            self->YPos += self->values[2];
        }
        switch (objectEntityList[objectLoop - 2].state) {
            case 2:
            case 6:
            if (GVar("Player.HeavyMetalFlag") == 1) {
                if (playerListPos == 0) {
                    SetAchievement(6, 100);
                }
            }
            scriptEng.tempValue[0] = objectEntityList[objectLoop - 2].XPos;
            scriptEng.tempValue[0] -= 0x1E0000;
            if (self->XPos > scriptEng.tempValue[0]) {
                self->XPos = scriptEng.tempValue[0];
                self->values[1] = 0;
                self->values[2] = -0x68000;
                self->values[3] = 0;
                self->animation = 8;
                self->state = 8;
                CreateTempObject(TypeNameID("Explosion"), 0, self->XPos, self->YPos);
                scriptEng.tempValue[0] = 0;
                scriptEng.tempValue[1] = 4;
                while (scriptEng.tempValue[0] < 8) {
                    CreateTempObject(TypeNameID("Debris"), scriptEng.tempValue[1], self->XPos, self->YPos);
                    objectEntityList[scriptEng.arrayPosition[2]].values[1] = rand() % 4;
                    objectEntityList[scriptEng.arrayPosition[2]].values[2]++;
                    objectEntityList[scriptEng.arrayPosition[2]].values[1] <<= 16;
                    objectEntityList[scriptEng.arrayPosition[2]].values[1] = -objectEntityList[scriptEng.arrayPosition[2]].values[1];
                    objectEntityList[scriptEng.arrayPosition[2]].values[2] = rand() % 3;
                    objectEntityList[scriptEng.arrayPosition[2]].values[2] += 2;
                    objectEntityList[scriptEng.arrayPosition[2]].values[2] <<= 16;
                    objectEntityList[scriptEng.arrayPosition[2]].values[2] = -objectEntityList[scriptEng.arrayPosition[2]].values[2];
                    scriptEng.tempValue[0]++;
                    scriptEng.tempValue[1]++;
                    if (scriptEng.tempValue[1] > 8) {
                        scriptEng.tempValue[1] = 4;
                    }
                }
                PlaySfx(22, 0);
                HapticEffect_Script(90, 0, 0, 0);
            }
            break;
            case 4:
            scriptEng.tempValue[0] = objectEntityList[objectLoop - 2].XPos;
            scriptEng.tempValue[0] += 0x240000;
            if (self->XPos > scriptEng.tempValue[0]) {
                self->XPos = scriptEng.tempValue[0];
                self->values[1] = 0;
                self->values[3] = 0;
                self->animation = 0;
                self->state = 7;
            }
            break;
        }
    }
    ProcessAnimation_Script();
}

void O_R7_MetalSonic::ObjectPlayerInteraction()
{
    Entity *self = Self();

    switch (self->animation) {
        case 5:
        case 7:
        PlayerObjectCollision(C_TOUCH, -16, -12, 16, 12);
        if (CheckResult() == 1) {
            CallScriptFunctionNamed("Player_Hit", scriptSub);
            GVar("Player.HeavyMetalFlag") = 0;
        }
    }
}

void O_R7_MetalSonic::ObjectDraw()
{
    Entity *self = Self();

    switch (self->values[3]) {
        case 1:
        scriptEng.tempValue[0] = self->values[4];
        scriptEng.tempValue[0] >>= 1;
        DrawSprite_Frame(scriptEng.tempValue[0]);
        self->values[4]++;
        self->values[4] &= 7;
        break;
        case 2:
        scriptEng.tempValue[0] = self->values[4];
        scriptEng.tempValue[0] >>= 1;
        scriptEng.tempValue[0] += 4;
        DrawSprite_Frame(scriptEng.tempValue[0]);
        self->values[4]++;
        self->values[4] &= 7;
        break;
        case 3:
        scriptEng.tempValue[0] = self->values[4];
        scriptEng.tempValue[0] >>= 1;
        scriptEng.tempValue[0] += 8;
        DrawSprite_Frame(scriptEng.tempValue[0]);
        self->values[4]++;
        self->values[4] &= 7;
        break;
        case 4:
        scriptEng.tempValue[0] = self->values[4];
        scriptEng.tempValue[0] += 12;
        DrawSprite_Frame(scriptEng.tempValue[0]);
        self->values[4]++;
        self->values[4] %= 10;
        break;
    }
    DrawObjectAnimation_Script();
}

void O_R7_MetalSonic::MetalSonic_FollowGround()
{
    Entity *self = Self();

    self->YPos -= 0x200000;
    ObjectTileGrip_Script(0, 0, 20, 0);
    if (CheckResult() == 0) {
        self->YPos += 0x100000;
        ObjectTileGrip_Script(0, 0, 20, 0);
        if (CheckResult() == 0) {
            self->YPos += 0x100000;
            ObjectTileGrip_Script(0, 0, 20, 0);
        }
    }
}

const Native::NativeFunctionDef O_R7_MetalSonic::funcs[1] = {
    { "MetalSonic_FollowGround", O_R7_MetalSonic::MetalSonic_FollowGround },
};

#endif // RETRO_USE_NATIVE_OBJECTS

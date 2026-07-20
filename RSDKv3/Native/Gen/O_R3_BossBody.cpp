#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R3_BossBody.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from BossBody.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R3_BossBody::ObjectStartup()
{
    LoadSpriteSheet("R3/Objects2.gif");
    AddSpriteFrame(-80, -16, 32, 32, 134, 0);
    AddSpriteFrame(-80, -16, 32, 32, 167, 0);
    AddSpriteFrame(-80, -16, 32, 32, 200, 0);
    AddSpriteFrame(-64, -16, 128, 32, 1, 67);
    AddSpriteFrame(-48, -32, 32, 32, 1, 100);
    AddSpriteFrame(16, -32, 32, 32, 34, 100);
    AddSpriteFrame(-24, 16, 48, 8, 148, 141);
    AddSpriteFrame(-24, 24, 24, 24, 148, 149);
    AddSpriteFrame(-24, 16, 24, 24, 148, 149);
    AddSpriteFrame(-24, 8, 24, 24, 148, 149);
    AddSpriteFrame(-24, 16, 24, 24, 148, 149);
    AddSpriteFrame(0, 24, 24, 24, 172, 149);
    AddSpriteFrame(0, 16, 24, 24, 172, 149);
    AddSpriteFrame(0, 8, 24, 24, 172, 149);
    AddSpriteFrame(0, 16, 24, 24, 172, 149);
    AddSpriteFrame(-64, -16, 128, 32, 117, 33);
    AddSpriteFrame(-48, -32, 32, 32, 1, 133);
    AddSpriteFrame(16, -32, 32, 32, 34, 133);
    AddSpriteFrame(-24, -32, 48, 16, 148, 107);
    AddSpriteFrame(-24, -32, 48, 16, 148, 124);
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Boss Body")) {
            objectEntityList[scriptEng.arrayPosition[0]].values[1] = objectEntityList[scriptEng.arrayPosition[0]].YPos;
            objectEntityList[scriptEng.arrayPosition[0]].values[3] = objectEntityList[scriptEng.arrayPosition[0]].YPos;
            objectEntityList[scriptEng.arrayPosition[0]].values[2] = objectEntityList[scriptEng.arrayPosition[0]].YPos;
            objectEntityList[scriptEng.arrayPosition[0]].values[2] += 0xE40000;
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_R3_BossBody::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        self->YPos = pYPos();
        self->YPos &= 0xFFFF0000;
        if (self->YPos < self->values[1]) {
            self->YPos = self->values[1];
            self->frame = 0;
        }
        if (self->YPos > self->values[2]) {
            self->YPos = self->values[2];
            self->frame = 0;
            self->state = 1;
            self->priority = 1;
        }
        if (self->YPos != self->values[3]) {
            self->values[3] = self->YPos;
            self->frame++;
            self->frame %= 9;
        }
        objectEntityList[objectLoop - 1].YPos = self->YPos;
        self->values[4]++;
        self->values[4] &= 255;
        if (self->values[4] == 0) {
            BossBody_LaunchBomb();
        }
        if (self->values[4] == 128) {
            BossBody_LaunchBomb();
        }
        break;
        case 1:
        objectEntityList[objectLoop - 1].YPos = self->YPos;
        if (objectEntityList[objectLoop + 1].values[2] < 8) {
            self->values[4]++;
            self->values[4] &= 255;
        } else {
            self->values[4] = 32;
        }
        if (self->values[4] == 0) {
            BossBody_LaunchBomb();
        }
        if (self->values[4] == 128) {
            BossBody_LaunchBomb();
        }
        break;
        case 2:
        if (self->YPos > self->values[2]) {
            self->YPos -= 0x28000;
            self->frame++;
            self->frame %= 9;
        } else {
            self->YPos = self->values[2];
            self->frame = 0;
            self->state = 3;
        }
        objectEntityList[objectLoop - 1].YPos = self->YPos;
        if (self->values[5] == 2) {
            CreateTempObject(TypeNameID("Explosion"), 0, self->XPos, self->YPos);
            objectEntityList[scriptEng.arrayPosition[2]].XPos = ((objectEntityList[scriptEng.arrayPosition[2]].XPos >> 16) - (32)) << 16;
            objectEntityList[scriptEng.arrayPosition[2]].YPos = ((objectEntityList[scriptEng.arrayPosition[2]].YPos >> 16) + (10)) << 16;
        }
        if (self->values[5] == 3) {
            CreateTempObject(TypeNameID("Explosion"), 0, self->XPos, self->YPos);
            objectEntityList[scriptEng.arrayPosition[2]].XPos = ((objectEntityList[scriptEng.arrayPosition[2]].XPos >> 16) + (32)) << 16;
            objectEntityList[scriptEng.arrayPosition[2]].YPos = ((objectEntityList[scriptEng.arrayPosition[2]].YPos >> 16) + (6)) << 16;
        }
        if (self->values[5] == 4) {
            CreateTempObject(TypeNameID("Explosion"), 0, self->XPos, self->YPos);
            objectEntityList[scriptEng.arrayPosition[2]].YPos = ((objectEntityList[scriptEng.arrayPosition[2]].YPos >> 16) + (4)) << 16;
        }
        break;
        case 3:
        objectEntityList[objectLoop - 1].YPos = self->YPos;
        break;
        case 4:
        if (self->YPos > self->values[2]) {
            self->YPos -= 0x28000;
            self->frame++;
            self->frame %= 9;
        } else {
            self->YPos = self->values[2];
            self->frame = 0;
            self->state = 5;
        }
        objectEntityList[objectLoop - 1].YPos = self->YPos;
        if (self->values[5] == 2) {
            CreateTempObject(TypeNameID("Explosion"), 0, self->XPos, self->YPos);
            objectEntityList[scriptEng.arrayPosition[2]].XPos = ((objectEntityList[scriptEng.arrayPosition[2]].XPos >> 16) - (32)) << 16;
            objectEntityList[scriptEng.arrayPosition[2]].YPos = ((objectEntityList[scriptEng.arrayPosition[2]].YPos >> 16) - (48)) << 16;
        }
        if (self->values[5] == 3) {
            CreateTempObject(TypeNameID("Explosion"), 0, self->XPos, self->YPos);
            objectEntityList[scriptEng.arrayPosition[2]].XPos = ((objectEntityList[scriptEng.arrayPosition[2]].XPos >> 16) + (32)) << 16;
            objectEntityList[scriptEng.arrayPosition[2]].YPos = ((objectEntityList[scriptEng.arrayPosition[2]].YPos >> 16) - (52)) << 16;
        }
        if (self->values[5] == 4) {
            CreateTempObject(TypeNameID("Explosion"), 0, self->XPos, self->YPos);
            objectEntityList[scriptEng.arrayPosition[2]].YPos = ((objectEntityList[scriptEng.arrayPosition[2]].YPos >> 16) - (56)) << 16;
        }
        break;
        case 5:
        objectEntityList[objectLoop - 1].YPos = self->YPos;
        break;
        case 6:
        if (self->YPos > self->values[2]) {
            self->YPos -= 0x28000;
            self->frame++;
            self->frame %= 9;
            masterVolume--;
        } else {
            self->YPos = self->values[2];
            self->frame = 0;
            self->state = 7;
            self->values[0] = 0;
            self->priority = 1;
            HapticEffect_Script(76, 0, 0, 0);
        }
        if (self->values[5] > 0) {
            objectEntityList[objectLoop - 1].YPos = self->values[5];
            objectEntityList[objectLoop - 1].YPos <<= 17;
            objectEntityList[objectLoop - 1].YPos = -objectEntityList[objectLoop - 1].YPos;
            objectEntityList[objectLoop - 1].YPos += self->YPos;
        } else {
            if (objectEntityList[objectLoop - 1].state == 0) {
                objectEntityList[objectLoop - 1].state = 3;
                objectEntityList[objectLoop - 1].priority = 1;
                objectEntityList[objectLoop - 1].values[0] &= 7;
            }
            if (objectEntityList[objectLoop - 1].state == 2) {
                objectEntityList[objectLoop - 1].state = 3;
                objectEntityList[objectLoop - 1].priority = 1;
                objectEntityList[objectLoop - 1].values[0] &= 7;
            }
        }
        if (self->values[5] == 2) {
            CreateTempObject(TypeNameID("Explosion"), 0, self->XPos, self->YPos);
            objectEntityList[scriptEng.arrayPosition[2]].XPos = ((objectEntityList[scriptEng.arrayPosition[2]].XPos >> 16) - (16)) << 16;
            objectEntityList[scriptEng.arrayPosition[2]].YPos = ((objectEntityList[scriptEng.arrayPosition[2]].YPos >> 16) - (52)) << 16;
        }
        if (self->values[5] == 3) {
            CreateTempObject(TypeNameID("Explosion"), 0, self->XPos, self->YPos);
            objectEntityList[scriptEng.arrayPosition[2]].XPos = ((objectEntityList[scriptEng.arrayPosition[2]].XPos >> 16) + (16)) << 16;
            objectEntityList[scriptEng.arrayPosition[2]].YPos = ((objectEntityList[scriptEng.arrayPosition[2]].YPos >> 16) - (56)) << 16;
        }
        break;
        case 7:
        scriptEng.tempValue[0] = self->values[0];
        scriptEng.tempValue[0] &= 3;
        if (scriptEng.tempValue[0] == 0) {
            scriptEng.tempValue[0] = rand() % 128;
            scriptEng.tempValue[0] -= 64;
            scriptEng.tempValue[0] <<= 16;
            scriptEng.tempValue[0] += self->XPos;
            scriptEng.tempValue[1] = rand() % 48;
            scriptEng.tempValue[1] -= 24;
            scriptEng.tempValue[1] <<= 16;
            scriptEng.tempValue[1] += self->YPos;
            CreateTempObject(TypeNameID("Explosion"), 0, scriptEng.tempValue[0], scriptEng.tempValue[1]);
            PlaySfx(22, 0);
        }
        self->values[0]++;
        if (self->values[0] == 80) {
            GVar("Player.Score") += 1000;
            ResetObjectEntity(objectLoop, TypeNameID("Blank Object"), 0, 0, 0);
            PlayMusic(0);
        }
        break;
    }
}

void O_R3_BossBody::ObjectPlayerInteraction()
{
    Entity *self = Self();

    switch (self->state) {
        case 1:
        case 3:
        PlayerObjectCollision(C_TOUCH, -64, -16, 64, 16);
        if (CheckResult() == 1) {
            pYVel() = 0;
            self->values[2] -= 0x480000;
            self->values[5] = 1;
            self->state++;
            objectEntityList[objectLoop - 1].state = 1;
            PlaySfx(22, 0);
            HapticEffect_Script(75, 0, 0, 0);
        }
        break;
        case 5:
        PlayerObjectCollision(C_TOUCH, -64, -16, 64, 16);
        if (CheckResult() == 1) {
            pYVel() = 0;
            self->values[2] -= 0x800000;
            self->values[5] = 1;
            self->state++;
            PlaySfx(22, 0);
            HapticEffect_Script(75, 0, 0, 0);
        }
        break;
    }
}

void O_R3_BossBody::ObjectDraw()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        case 1:
        DrawSprite_Frame(4);
        DrawSprite_Frame(5);
        if (self->values[4] < 128) {
            if (self->values[4] < 8) {
                scriptEng.tempValue[0] = self->values[4];
                scriptEng.tempValue[0] >>= 1;
                scriptEng.tempValue[0] += 7;
            } else {
                scriptEng.tempValue[0] = 8;
            }
            DrawSprite_Frame(scriptEng.tempValue[0]);
            DrawSprite_Frame(12);
        } else {
            if (self->values[4] < 136) {
                scriptEng.tempValue[0] = self->values[4];
                scriptEng.tempValue[0] -= 128;
                scriptEng.tempValue[0] >>= 1;
                scriptEng.tempValue[0] += 11;
            } else {
                scriptEng.tempValue[0] = 12;
            }
            DrawSprite_Frame(8);
            DrawSprite_Frame(scriptEng.tempValue[0]);
        }
        DrawSprite_Frame(6);
        DrawSprite_Frame(3);
        scriptEng.tempValue[0] = self->frame;
        scriptEng.tempValue[0] /= 3;
        DrawSprite_Frame(scriptEng.tempValue[0]);
        break;
        case 2:
        case 3:
        case 4:
        scriptEng.tempValue[0] = self->values[5];
        scriptEng.tempValue[0] &= 1;
        if (scriptEng.tempValue[0] == 0) {
            DrawSprite_Frame(4);
            DrawSprite_Frame(5);
            DrawSprite_Frame(3);
        } else {
            DrawSprite_Frame(16);
            DrawSprite_Frame(17);
            DrawSprite_Frame(15);
        }
        if (self->values[5] > 0) {
            self->values[5]++;
            self->values[5] &= 15;
        }
        scriptEng.tempValue[0] = self->frame;
        scriptEng.tempValue[0] /= 3;
        DrawSprite_Frame(scriptEng.tempValue[0]);
        break;
        case 5:
        scriptEng.tempValue[1] = self->YPos;
        scriptEng.tempValue[1] += self->values[6];
        scriptEng.tempValue[0] = self->values[5];
        scriptEng.tempValue[0] &= 1;
        if (scriptEng.tempValue[0] == 0) {
            DrawSprite_Frame(4);
            DrawSprite_Frame(5);
            DrawSprite_FrameXY(18, self->XPos, scriptEng.tempValue[1]);
            DrawSprite_Frame(3);
        } else {
            DrawSprite_Frame(16);
            DrawSprite_Frame(17);
            DrawSprite_FrameXY(19, self->XPos, scriptEng.tempValue[1]);
            DrawSprite_Frame(15);
        }
        if (objectEntityList[objectLoop - 1].state == 2) {
            if (self->values[6] < 0x100000) {
                self->values[6] += 0x8000;
            }
        }
        if (self->values[5] > 0) {
            self->values[5]++;
            self->values[5] &= 15;
        }
        scriptEng.tempValue[0] = self->frame;
        scriptEng.tempValue[0] /= 3;
        DrawSprite_Frame(scriptEng.tempValue[0]);
        break;
        case 6:
        scriptEng.tempValue[0] = self->YPos;
        scriptEng.tempValue[0] -= 0x200000;
        if (scriptEng.tempValue[0] < self->values[2]) {
            DrawSprite_Frame(16);
            DrawSprite_Frame(17);
            DrawSprite_Frame(3);
        } else {
            scriptEng.tempValue[1] = self->YPos;
            scriptEng.tempValue[1] += self->values[6];
            scriptEng.tempValue[0] = self->values[5];
            scriptEng.tempValue[0] &= 1;
            if (scriptEng.tempValue[0] == 0) {
                DrawSprite_Frame(4);
                DrawSprite_Frame(5);
                DrawSprite_Frame(3);
            } else {
                DrawSprite_Frame(16);
                DrawSprite_Frame(17);
                DrawSprite_Frame(15);
            }
            if (self->values[6] < 0x100000) {
                self->values[6] += 0x8000;
            }
        }
        if (self->values[5] > 0) {
            self->values[5]++;
            self->values[5] &= 15;
        }
        scriptEng.tempValue[0] = self->frame;
        scriptEng.tempValue[0] /= 3;
        DrawSprite_Frame(scriptEng.tempValue[0]);
        break;
        case 7:
        DrawSprite_Frame(3);
        DrawSprite_Frame(0);
        break;
    }
}

void O_R3_BossBody::BossBody_LaunchBomb()
{
    Entity *self = Self();

    scriptEng.tempValue[0] = pYPos();
    scriptEng.tempValue[0] -= self->YPos;
    if (scriptEng.tempValue[0] < 0x2400000) {
        CreateTempObject(TypeNameID("Pinball Bomb"), 0, self->XPos, self->YPos);
        objectEntityList[scriptEng.arrayPosition[2]].values[1] = rand() % 0x400;
        objectEntityList[scriptEng.arrayPosition[2]].values[1] <<= 8;
        if (self->values[4] < 128) {
            objectEntityList[scriptEng.arrayPosition[2]].values[1] = -objectEntityList[scriptEng.arrayPosition[2]].values[1];
            objectEntityList[scriptEng.arrayPosition[2]].XPos -= 0x80000;
        } else {
            objectEntityList[scriptEng.arrayPosition[2]].XPos += 0x80000;
        }
        objectEntityList[scriptEng.arrayPosition[2]].YPos += 0x180000;
        objectEntityList[scriptEng.arrayPosition[2]].values[2] = 0x30000;
        objectEntityList[scriptEng.arrayPosition[2]].drawOrder = 2;
    }
}

const Native::NativeFunctionDef O_R3_BossBody::funcs[1] = {
    { "BossBody_LaunchBomb", O_R3_BossBody::BossBody_LaunchBomb },
};

#endif // RETRO_USE_NATIVE_OBJECTS

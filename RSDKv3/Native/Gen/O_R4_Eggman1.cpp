#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R4_Eggman1.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from Eggman1.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R4_Eggman1::ObjectStartup()
{
    LoadSpriteSheet("R4/Objects2.gif");
    AddSpriteFrame(-36, -28, 72, 56, 61, 1);
    AddSpriteFrame(-36, -28, 72, 56, 134, 1);
    AddSpriteFrame(-12, -28, 32, 16, 207, 1);
    AddSpriteFrame(-12, -28, 32, 16, 207, 18);
    AddSpriteFrame(-36, 28, 72, 16, 116, 58);
    AddSpriteFrame(-36, 28, 72, 16, 116, 75);
    AddSpriteFrame(-36, 20, 72, 16, 116, 92);
    AddSpriteFrame(-36, 20, 72, 16, 116, 109);
    AddSpriteFrame(-12, -44, 16, 16, 1, 135);
    AddSpriteFrame(-12, -44, 1, 1, 1, 135);
    AddSpriteFrame(-12, -44, 16, 16, 18, 135);
    AddSpriteFrame(-12, -44, 1, 1, 1, 135);
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Eggman Part 1")) {
            objectEntityList[scriptEng.arrayPosition[0]].direction = 1;
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_R4_Eggman1::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        PlayerObjectCollision(C_TOUCH, -64, -256, 64, 256);
        if (CheckResult() == 1) {
            self->state = 1;
            self->priority = 1;
            self->values[1] = 0x1C000;
        }
        break;
        case 1:
        self->YPos += self->values[1];
        if (self->YPos > 0x41E0000) {
            self->state++;
            self->direction = 0;
            self->values[4] = 2;
        }
        break;
        case 2:
        self->XPos += self->values[1];
        self->YPos += self->values[1];
        if (self->XPos > 0x4E00000) {
            self->XPos = 0x4E00000;
            self->state++;
            self->values[4] = 0;
        }
        break;
        case 3:
        self->YPos += self->values[1];
        if (self->YPos > 0x4600000) {
            self->YPos = 0x4600000;
            self->state++;
            self->values[2] = 0;
            self->values[3] = self->YPos;
            self->values[4] = 1;
        }
        break;
        case 4:
        self->XPos += self->values[1];
        ChaseEggman_Oscillation();
        self->YPos += self->values[3];
        if (self->XPos > 0x63C0000) {
            self->XPos = 0x63C0000;
            self->values[4] = 0;
            if (self->values[5] < 4) {
                self->state++;
            } else {
                self->state = 23;
                objectEntityList[objectLoop + 2].propertyValue = 3;
            }
        }
        break;
        case 5:
        self->YPos += self->values[1];
        if (self->YPos > 0x5200000) {
            self->YPos = 0x5200000;
            self->state++;
            self->direction = 1;
            self->values[2] = 0;
            self->values[3] = self->YPos;
            self->values[4] = 1;
        }
        break;
        case 6:
        self->XPos -= self->values[1];
        ChaseEggman_Oscillation();
        self->YPos = -self->YPos;
        self->YPos += self->values[3];
        if (self->XPos < 0x5600000) {
            self->XPos = 0x5600000;
            self->state++;
            self->values[4] = 0;
        }
        break;
        case 7:
        self->YPos += self->values[1];
        if (self->YPos > 0x5DA0000) {
            self->state++;
            self->direction = 0;
            self->values[4] = 2;
        }
        break;
        case 8:
        self->XPos += self->values[1];
        self->YPos += self->values[1];
        if (self->XPos > 0x5740000) {
            self->XPos = 0x5740000;
            self->state++;
            self->values[4] = 0;
        }
        break;
        case 9:
        self->YPos += self->values[1];
        if (self->YPos > 0x8E00000) {
            self->YPos -= 0x8000000;
            self->state++;
        } else {
            if (pYPos() < 0x1400000) {
                self->YPos -= 0x8000000;
                self->state++;
            }
        }
        break;
        case 10:
        self->YPos += self->values[1];
        if (self->YPos > 0x12C0000) {
            self->YPos = 0x12C0000;
            self->state++;
            self->values[4] = 2;
        }
        break;
        case 11:
        self->XPos += self->values[1];
        self->YPos += self->values[1];
        if (self->XPos > 0x5FC0000) {
            self->XPos = 0x5FC0000;
            self->state++;
            self->values[2] = 0;
            self->values[3] = self->YPos;
            self->values[4] = 1;
        }
        break;
        case 12:
        self->XPos += self->values[1];
        ChaseEggman_Oscillation();
        self->YPos += self->values[3];
        if (self->XPos > 0x6760000) {
            self->state++;
            self->values[4] = 2;
        }
        break;
        case 13:
        self->XPos += self->values[1];
        self->YPos += self->values[1];
        if (self->XPos > 0x6C40000) {
            self->XPos = 0x6C40000;
            self->state++;
            self->values[4] = 0;
        }
        break;
        case 14:
        self->YPos += self->values[1];
        if (self->YPos > 0x2720000) {
            self->state++;
            self->values[4] = 2;
        }
        break;
        case 15:
        self->XPos += self->values[1];
        self->YPos += self->values[1];
        if (self->XPos > 0x6E40000) {
            self->XPos = 0x6E40000;
            self->state++;
            self->values[4] = 0;
        }
        break;
        case 16:
        self->YPos += self->values[1];
        if (self->values[5] < 4) {
            if (self->YPos > 0x2EC0000) {
                self->state++;
                self->direction = 1;
                self->values[4] = 2;
            }
        } else {
            if (self->YPos > 0x2B00000) {
                self->state = 19;
                self->values[4] = 1;
                self->values[2] = 0;
                self->values[3] = self->YPos;
                objectEntityList[objectLoop + 1].propertyValue = 3;
            }
        }
        break;
        case 17:
        self->XPos -= self->values[1];
        self->YPos += self->values[1];
        if (self->YPos > 0x3300000) {
            self->YPos = 0x3300000;
            self->state++;
            self->values[2] = 0;
            self->values[3] = self->YPos;
            self->values[4] = 1;
        }
        break;
        case 18:
        self->XPos -= self->values[1];
        ChaseEggman_Oscillation();
        self->YPos = -self->YPos;
        self->YPos += self->values[3];
        if (self->XPos < 0x4D00000) {
            self->XPos = 0x4D00000;
            self->state = 1;
            self->values[4] = 0;
        }
        break;
        case 19:
        self->XPos += self->values[1];
        ChaseEggman_Oscillation();
        self->YPos += self->values[3];
        if (self->XPos > 0x7A40000) {
            self->state++;
            self->values[4] = 2;
        }
        break;
        case 20:
        self->XPos += self->values[1];
        self->YPos += self->values[1];
        if (self->YPos > 0x2E00000) {
            self->YPos = 0x2E00000;
            self->state++;
            self->values[4] = 1;
            self->values[2] = 0;
            self->values[3] = self->YPos;
        }
        break;
        case 21:
        self->XPos += self->values[1];
        ChaseEggman_Oscillation();
        self->YPos += self->values[3];
        if (self->XPos > 0x8780000) {
            self->XPos = 0x8780000;
            self->state++;
            self->values[4] = 0;
        }
        break;
        case 22:
        if (self->values[1] < 0x40000) {
            self->YPos += 0x40000;
        } else {
            self->YPos += self->values[1];
        }
        scriptEng.tempValue[0] = yScrollOffset;
        scriptEng.tempValue[0] += 288;
        scriptEng.tempValue[0] <<= 16;
        if (self->YPos > scriptEng.tempValue[0]) {
            ResetObjectEntity(objectLoop, TypeNameID("Blank Object"), 0, 0, 0);
        }
        break;
        case 23:
        self->YPos -= self->values[1];
        if (self->YPos < 0x4400000) {
            self->YPos = 0x4400000;
            self->state++;
            self->values[4] = 1;
            self->values[2] = 0;
            self->values[3] = self->YPos;
        }
        break;
        case 24:
        self->XPos += self->values[1];
        ChaseEggman_Oscillation();
        self->YPos += self->values[3];
        if (self->XPos > 0x7400000) {
            self->state++;
            self->values[4] = 2;
        }
        break;
        case 25:
        self->XPos += self->values[1];
        self->YPos -= self->values[1];
        if (self->YPos < 0x3DC0000) {
            self->YPos = 0x3DC0000;
            self->state = 21;
            self->values[4] = 1;
            self->values[2] = 0;
            self->values[3] = self->YPos;
        }
        break;
    }
    if (self->values[7] == 1) {
        CreateTempObject(TypeNameID("Explosion"), 0, self->XPos, self->YPos);
        if (self->direction == 0) {
            objectEntityList[scriptEng.arrayPosition[2]].XPos -= 0x80000;
        } else {
            objectEntityList[scriptEng.arrayPosition[2]].XPos += 0x80000;
        }
        PlaySfx(22, 0);
        self->values[7] = 34;
    } else {
        if (self->values[7] > 0) {
            self->values[7]--;
        }
    }
}

void O_R4_Eggman1::ObjectPlayerInteraction()
{
    Entity *self = Self();

    if (self->values[6] == 0) {
        PlayerObjectCollision(C_TOUCH, -32, -24, 32, 24);
        if (CheckResult() == 1) {
            CheckResult() = (pAnimation() == GVar("ANI_JUMPING"));
            scriptEng.tempValue[0] = CheckResult();
            CheckResult() = (pAnimation() == GVar("ANI_SPINDASH"));
            scriptEng.tempValue[0] |= CheckResult();
            if (pAnimation() == GVar("ANI_FLYING")) {
                CheckResult() = (pYPos() > self->YPos);
                scriptEng.tempValue[0] |= CheckResult();
            }
            scriptEng.arrayPosition[0] = Plr()->entityNo;
            scriptEng.arrayPosition[0] += 2;
            if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Invincibility")) {
                scriptEng.tempValue[0] = 1;
            }
            if (scriptEng.tempValue[0] == 1) {
                pXVel() = -pXVel();
                pSpeed() = -pSpeed();
                pXVel() >>= 1;
                pSpeed() >>= 1;
                pYVel() = pYPos();
                pYVel() -= self->YPos;
                pYVel() >>= 3;
                self->values[5]++;
                if (self->values[5] == 4) {
                    self->values[6] = 16;
                    self->values[7] = 1;
                } else {
                    self->values[6] = 1;
                    PlaySfx(globalSFXCount + 5, 0);
                    self->values[1] = 0x48000;
                }
            } else {
                if (PlayerValue(4) == 0) {
                    pState() = PlayerStateID("Player_State_GotHit");
                    if (pXPos() > self->XPos) {
                        pSpeed() = 0x20000;
                    } else {
                        pSpeed() = -0x20000;
                    }
                }
            }
        }
    } else {
        if (self->values[5] == 4) {
            PlayerObjectCollision(C_TOUCH, -64, -80, 64, 80);
            if (CheckResult() == 1) {
                switch (self->values[4]) {
                    case 0:
                    self->values[1] += 0x8000;
                    break;
                    case 1:
                    self->values[1] += 0x8000;
                    if (self->values[1] > 0x60000) {
                        self->values[1] = 0x60000;
                    }
                    break;
                    case 2:
                    self->values[1] -= 0x2000;
                    if (self->values[1] > 0x60000) {
                        self->values[1] = 0x60000;
                    }
                    if (self->values[1] < 0x20000) {
                        self->values[1] = 0x20000;
                    }
                    break;
                }
            } else {
                self->values[1] -= 0x2000;
                if (self->values[1] < 0x1C000) {
                    self->values[1] = 0x1C000;
                }
            }
            PlayerObjectCollision(C_TOUCH, -320, -240, 320, 240);
            if (CheckResult() == 0) {
                self->values[1] = 0;
            }
        }
    }
}

void O_R4_Eggman1::ObjectDraw()
{
    Entity *self = Self();

    if (self->values[6] == 0) {
        DrawSpriteFX_Script(0, FX_FLIP, self->XPos, self->YPos);
        DrawSpriteFX_Script(2, FX_FLIP, self->XPos, self->YPos);
    } else {
        if (self->values[6] < 16) {
            scriptEng.tempValue[0] = self->values[6];
            scriptEng.tempValue[0] &= 1;
            DrawSpriteFX_Script(scriptEng.tempValue[0], FX_FLIP, self->XPos, self->YPos);
            if (scriptEng.tempValue[0] == 0) {
                DrawSpriteFX_Script(3, FX_FLIP, self->XPos, self->YPos);
            }
            scriptEng.tempValue[0] = self->values[6];
            scriptEng.tempValue[0] &= 15;
            scriptEng.tempValue[0] >>= 2;
            scriptEng.tempValue[0] += 8;
            DrawSpriteFX_Script(scriptEng.tempValue[0], FX_FLIP, self->XPos, self->YPos);
        } else {
            if (self->values[0] < 32) {
                DrawSpriteFX_Script(0, FX_FLIP, self->XPos, self->YPos);
                DrawSpriteFX_Script(3, FX_FLIP, self->XPos, self->YPos);
            } else {
                DrawSpriteFX_Script(0, FX_FLIP, self->XPos, self->YPos);
                DrawSpriteFX_Script(2, FX_FLIP, self->XPos, self->YPos);
            }
            scriptEng.tempValue[0] = self->values[6];
            scriptEng.tempValue[0] &= 15;
            scriptEng.tempValue[0] >>= 2;
            scriptEng.tempValue[0] += 8;
            DrawSpriteFX_Script(scriptEng.tempValue[0], FX_FLIP, self->XPos, self->YPos);
        }
        self->values[6]++;
        if (self->values[5] < 4) {
            if (self->values[6] == 80) {
                self->values[6] = 0;
                self->values[1] = 0x1C000;
            }
        } else {
            if (self->values[6] == 32) {
                self->values[6] = 16;
            }
        }
    }
    scriptEng.tempValue[0] = self->frame;
    scriptEng.tempValue[0] >>= 2;
    switch (self->values[4]) {
        case 0:
        scriptEng.tempValue[0] += 4;
        DrawSpriteFX_Script(scriptEng.tempValue[0], FX_FLIP, self->XPos, self->YPos);
        break;
        case 1:
        scriptEng.tempValue[0] += 6;
        DrawSpriteFX_Script(scriptEng.tempValue[0], FX_FLIP, self->XPos, self->YPos);
        break;
        case 2:
        scriptEng.tempValue[0] += 4;
        DrawSpriteFX_Script(scriptEng.tempValue[0], FX_FLIP, self->XPos, self->YPos);
        scriptEng.tempValue[0] += 2;
        DrawSpriteFX_Script(scriptEng.tempValue[0], FX_FLIP, self->XPos, self->YPos);
        break;
    }
    self->frame++;
    self->frame &= 7;
}

void O_R4_Eggman1::ChaseEggman_Oscillation()
{
    Entity *self = Self();

    self->YPos = Sin512(self->values[2]);
    self->YPos <<= 10;
    self->values[2] += 4;
    self->values[2] &= 511;
}

const Native::NativeFunctionDef O_R4_Eggman1::funcs[1] = {
    { "ChaseEggman_Oscillation", O_R4_Eggman1::ChaseEggman_Oscillation },
};

#endif // RETRO_USE_NATIVE_OBJECTS

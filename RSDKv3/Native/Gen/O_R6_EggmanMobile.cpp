#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R6_EggmanMobile.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from EggmanMobile.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R6_EggmanMobile::ObjectStartup()
{
    LoadSpriteSheet("R6/Objects2.gif");
    AddSpriteFrame(-64, -48, 128, 96, 66, 1);
    AddSpriteFrame(-64, -16, 128, 32, 66, 98);
    AddSpriteFrame(-24, -21, 48, 24, 116, 131);
    AddSpriteFrame(-24, -21, 48, 24, 116, 156);
    AddSpriteFrame(-24, -21, 48, 24, 116, 181);
    AddSpriteFrame(-28, -37, 48, 40, 124, 215);
    AddSpriteFrame(-24, -29, 48, 32, 1, 219);
    AddSpriteFrame(-16, -80, 32, 32, 195, 1);
    AddSpriteFrame(-16, -80, 32, 32, 195, 34);
    AddSpriteFrame(-16, -80, 32, 32, 195, 67);
    AddSpriteFrame(-16, -80, 32, 32, 195, 100);
    AddSpriteFrame(-12, -80, 24, 32, 228, 51);
    AddSpriteFrame(-12, -80, 24, 32, 228, 84);
    AddSpriteFrame(-12, -80, 24, 32, 231, 117);
    AddSpriteFrame(-12, -80, 24, 32, 231, 150);
    AddSpriteFrame(-16, 48, 32, 32, 198, 133);
    AddSpriteFrame(-16, 48, 32, 24, 206, 199);
    AddSpriteFrame(-16, 48, 32, 32, 198, 166);
    AddSpriteFrame(-16, 48, 32, 24, 206, 224);
    AddSpriteFrame(-16, 48, 32, 24, 206, 199);
    AddSpriteFrame(-16, 48, 32, 24, 206, 224);
}

void O_R6_EggmanMobile::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        if (pXPos() > self->XPos) {
            self->state++;
            self->scale = 0;
        }
        break;
        case 1:
        self->values[0]++;
        if (self->values[0] == 120) {
            self->values[0] = 0;
            self->values[2] = 0x30000;
            self->values[1] = 0x6200000;
            self->values[3] = 1;
            self->values[4] = 0;
            self->state++;
        }
        break;
        case 2:
        R6_EGG_DESCEND();
        break;
        case 3:
        R6_EGG_ROUTE_1ST_FLOOR();
        if (self->state > 3) {
            self->values[1] = 0x4280000;
        }
        break;
        case 4:
        R6_EGG_MOVE();
        break;
        case 5:
        R6_EGG_ROUTE_2ST_FLOOR();
        if (self->state > 5) {
            self->values[1] = 0x2280000;
        }
        break;
        case 6:
        R6_EGG_MOVE();
        break;
        case 7:
        R6_EGG_ROUTE_2ST_FLOOR();
        if (self->state > 7) {
            self->values[1] = 0x1300000;
        }
        break;
        case 8:
        R6_EGG_MOVE();
        break;
        case 9:
        if (self->values[0] == 0) {
            self->XPos += 0x20000;
        } else {
            self->XPos -= 0x20000;
        }
        self->values[0]++;
        self->values[0] &= 1;
        break;
        case 10:
        self->YPos += self->values[2];
        self->values[2] += 0x1000;
        pSpeed() = 0;
        if (self->values[0] == 0) {
            self->XPos += 0x20000;
        } else {
            self->XPos -= 0x20000;
        }
        self->values[0]++;
        self->values[0] &= 1;
        if (self->YPos >= 0x2A00000) {
            self->YPos = 0x2A00000;
            self->values[0] = 0;
            self->values[2] = 0;
            self->values[6] = 3;
            stageLayouts[0].tiles[20 + 0x100 * 5] = 500;
            stageLayouts[0].tiles[21 + 0x100 * 5] = 501;
            stageLayouts[0].tiles[22 + 0x100 * 5] = 506;
            self->state++;
        }
        if (pXPos() > self->values[1]) {
            pXPos() = self->values[1];
            pXPos() += 0x500000;
        } else {
            pXPos() = self->values[1];
            pXPos() -= 0x500000;
        }
        R6_EGG_STEAM();
        break;
        case 11:
        pSpeed() = 0;
        if (pXPos() > self->XPos) {
            pXPos() = self->XPos;
            pXPos() += 0x500000;
        } else {
            pXPos() = self->XPos;
            pXPos() -= 0x500000;
        }
        R6_EGG_STEAM();
        self->values[0]++;
        if (self->values[0] == 180) {
            objectEntityList[objectLoop - 1].state = 2;
        }
        if (self->values[0] == 240) {
            self->state++;
            self->values[5] = 3;
            CreateTempObject(TypeNameID("Fade Screen"), 0, self->XPos, self->YPos);
            objectEntityList[scriptEng.arrayPosition[2]].values[1] = objectLoop;
        }
        break;
        case 12:
        pSpeed() = 0;
        if (pXPos() > self->XPos) {
            pXPos() = self->XPos;
            pXPos() += 0x500000;
        } else {
            pXPos() = self->XPos;
            pXPos() -= 0x500000;
        }
        break;
    }
}

void O_R6_EggmanMobile::ObjectPlayerInteraction()
{
    Entity *self = Self();

    PlayerObjectCollision(C_TOUCH, -22, 40, 22, 64);
    if (CheckResult() == 1) {
        CallScriptFunctionNamed("Player_Hit", scriptSub);
    }
    if (pAnimation() != GVar("ANI_HURT")) {
        if (self->propertyValue == 0) {
            PlayerObjectCollision(C_TOUCH, -64, -48, 64, 16);
            scriptEng.tempValue[0] = CheckResult();
            PlayerObjectCollision(C_TOUCH, -32, 16, 32, 32);
            scriptEng.tempValue[0] |= CheckResult();
            if (scriptEng.tempValue[0] == 1) {
                scriptEng.tempValue[0] = 0;
                if (pAnimation() == GVar("ANI_JUMPING")) {
                    scriptEng.tempValue[0] = 1;
                }
                if (scriptEng.tempValue[0] == 1) {
                    HapticEffect_Script(75, 0, 0, 0);
                    self->propertyValue = 120;
                    pSpeed() = -pSpeed();
                    pSpeed() >>= 1;
                    pYVel() = -pYVel();
                    pYVel() >>= 1;
                    pXVel() = pSpeed();
                    if (self->state < 9) {
                        PlaySfx(globalSFXCount + 11, 0);
                        self->values[6] = 1;
                        self->frame = 0;
                    } else {
                        self->state = 10;
                        self->values[5] = 2;
                        self->animationTimer = 0;
                        self->values[6] = 2;
                        self->values[7] = 0;
                        self->frame = 0;
                        self->values[1] = self->XPos;
                        objectEntityList[objectLoop + 1].type = TypeNameID("Blank Object");
                        Copy16x16Tile(810, 863);
                        PlaySfx(22, 0);
                    }
                } else {
                    CallScriptFunctionNamed("Player_Hit", scriptSub);
                }
            }
        }
    }
}

void O_R6_EggmanMobile::ObjectDraw()
{
    Entity *self = Self();

    DrawSprite_Frame(0);
    switch (self->values[6]) {
        case 0:
        scriptEng.tempValue[0] = self->values[7];
        scriptEng.tempValue[0] /= 10;
        scriptEng.tempValue[0] += 2;
        self->values[7]++;
        self->values[7] %= 20;
        self->direction = self->frame;
        self->direction /= 25;
        self->frame++;
        self->frame %= 50;
        DrawSpriteFX_Script(scriptEng.tempValue[0], FX_FLIP, self->XPos, self->YPos);
        break;
        case 1:
        self->direction = self->frame;
        self->direction /= 10;
        self->frame++;
        self->frame %= 20;
        DrawSpriteFX_Script(4, FX_FLIP, self->XPos, self->YPos);
        if (self->propertyValue > 0) {
            self->propertyValue--;
        } else {
            self->values[6] = 0;
            self->values[7] = 0;
            self->frame = 0;
        }
        break;
        case 2:
        DrawSprite_Frame(5);
        break;
        case 3:
        self->direction = self->frame;
        self->direction /= 25;
        self->frame++;
        self->frame %= 50;
        DrawSpriteFX_Script(6, FX_FLIP, self->XPos, self->YPos);
        break;
    }
    switch (self->values[5]) {
        case 0:
        DrawSprite_Frame(7);
        break;
        case 1:
        scriptEng.tempValue[0] = self->animationTimer;
        scriptEng.tempValue[0] >>= 7;
        scriptEng.tempValue[0] += 7;
        DrawSprite_Frame(scriptEng.tempValue[0]);
        self->animationTimer += self->animationSpeed;
        self->animationTimer &= 511;
        if (self->animationSpeed < 128) {
            self->animationSpeed++;
        }
        break;
        case 2:
        scriptEng.tempValue[0] = self->animationTimer;
        scriptEng.tempValue[0] /= 3;
        if (scriptEng.tempValue[0] < 4) {
            scriptEng.tempValue[0] += 11;
            DrawSprite_Frame(scriptEng.tempValue[0]);
        }
        self->animationTimer++;
        self->animationTimer %= 30;
        break;
    }
    switch (self->values[3]) {
        case 0:
        scriptEng.tempValue[0] = self->values[4];
        scriptEng.tempValue[0] >>= 1;
        scriptEng.tempValue[0] += 19;
        DrawSprite_Frame(scriptEng.tempValue[0]);
        self->values[4]++;
        self->values[4] &= 3;
        break;
        case 1:
        scriptEng.tempValue[0] = self->values[4];
        scriptEng.tempValue[0] /= 3;
        scriptEng.tempValue[0] += 15;
        DrawSprite_Frame(scriptEng.tempValue[0]);
        self->values[4]++;
        self->values[4] %= 12;
        break;
    }
}

void O_R6_EggmanMobile::R6_EGG_DESCEND()
{
    Entity *self = Self();

    self->YPos += self->values[2];
    self->values[2] -= 256;
    if (self->YPos >= self->values[1]) {
        self->YPos = self->values[1];
        self->values[2] = 0;
        self->values[3] = 0;
        self->values[4] = 0;
        self->state++;
    }
}

void O_R6_EggmanMobile::R6_EGG_MOVE()
{
    Entity *self = Self();

    self->YPos += self->values[2];
    self->values[2] -= 0x1000;
    if (self->YPos <= self->values[1]) {
        self->YPos = self->values[1];
        self->values[2] = 0;
        self->values[3] = 0;
        self->values[4] = 0;
        self->values[5] = 0;
        self->animationTimer = 0;
        self->animationSpeed = 0;
        self->state++;
    }
}

void O_R6_EggmanMobile::R6_EGG_ROUTE_1ST_FLOOR()
{
    Entity *self = Self();

    scriptEng.tempValue[0] = self->YPos;
    scriptEng.tempValue[0] += 0x780000;
    if (pYPos() < scriptEng.tempValue[0]) {
        if (objectEntityList[objectLoop + 1].state < 4) {
            objectEntityList[objectLoop + 1].state = 0;
            objectEntityList[objectLoop + 1].values[0] = 0;
            if (self->propertyValue > 0) {
                self->values[0] = 1200;
            }
        } else {
            if (objectEntityList[objectLoop + 1].values[0] > 270) {
                objectEntityList[objectLoop + 1].state = 0;
                objectEntityList[objectLoop + 1].values[0] = 0;
            } else {
                self->values[0] &= 511;
            }
        }
        if (self->values[0] < 1200) {
            if (self->values[0] == 0) {
                self->values[5] = 1;
                PlaySfx(globalSFXCount + 10, 0);
            }
            self->values[0] += 4;
            scriptEng.tempValue[0] = self->values[0];
            scriptEng.tempValue[0] &= 511;
            self->YPos = Sin512(scriptEng.tempValue[0]);
            self->YPos <<= 9;
            self->YPos += self->values[1];
        } else {
            self->values[0] = 0;
            self->values[2] = -0x10000;
            self->values[3] = 1;
            self->values[4] = 0;
            objectEntityList[objectLoop + 1].state = 1;
            self->state++;
        }
    }
}

void O_R6_EggmanMobile::R6_EGG_ROUTE_2ST_FLOOR()
{
    Entity *self = Self();

    scriptEng.tempValue[0] = self->YPos;
    scriptEng.tempValue[0] += 0x780000;
    if (pYPos() < scriptEng.tempValue[0]) {
        self->scale = 1;
        if (objectEntityList[objectLoop + 1].state < 4) {
            objectEntityList[objectLoop + 1].state = 0;
            objectEntityList[objectLoop + 1].values[0] = 0;
            if (self->propertyValue > 0) {
                self->values[0] = 1200;
            }
        } else {
            if (objectEntityList[objectLoop + 1].values[0] > 270) {
                objectEntityList[objectLoop + 1].state = 0;
                objectEntityList[objectLoop + 1].values[0] = 0;
            } else {
                self->values[0] &= 511;
            }
        }
        if (self->values[0] < 1200) {
            if (self->values[0] == 0) {
                self->values[5] = 1;
                PlaySfx(globalSFXCount + 10, 0);
            }
            self->values[0] += 4;
            scriptEng.tempValue[0] = self->values[0];
            scriptEng.tempValue[0] &= 511;
            self->YPos = Sin512(scriptEng.tempValue[0]);
            self->YPos <<= 9;
            self->YPos += self->values[1];
        } else {
            self->values[0] = 0;
            self->values[2] = -0x10000;
            self->values[3] = 1;
            self->values[4] = 0;
            objectEntityList[objectLoop + 1].state = 1;
            self->scale = 0;
            self->state++;
        }
    } else {
        if (GetObjectOutOfBounds(objectLoop) == 1) {
            self->values[5] = 0;
            self->animationTimer = 0;
            self->animationSpeed = 0;
        }
        if (objectEntityList[objectLoop + 1].state < 3) {
            if (self->scale == 1) {
                objectEntityList[objectLoop + 1].state = 3;
                objectEntityList[objectLoop + 1].values[0] = 0;
            }
        }
    }
}

void O_R6_EggmanMobile::R6_EGG_STEAM()
{
    Entity *self = Self();

    if (self->animationTimer == 0) {
        PlaySfx(22, 0);
    }
    if (self->animationTimer < 12) {
        CreateTempObject(TypeNameID("Steam Cloud"), 0, self->XPos, self->YPos);
        objectEntityList[scriptEng.arrayPosition[2]].YPos -= 0x480000;
        objectEntityList[scriptEng.arrayPosition[2]].values[1] = rand() % 0x200;
        objectEntityList[scriptEng.arrayPosition[2]].values[1] -= 0x100;
        objectEntityList[scriptEng.arrayPosition[2]].values[1] <<= 10;
        objectEntityList[scriptEng.arrayPosition[2]].values[2] = rand() % 0x100;
        objectEntityList[scriptEng.arrayPosition[2]].values[2] *= -0x400;
    }
}

const Native::NativeFunctionDef O_R6_EggmanMobile::funcs[5] = {
    { "R6_EGG_DESCEND", O_R6_EggmanMobile::R6_EGG_DESCEND },
    { "R6_EGG_MOVE", O_R6_EggmanMobile::R6_EGG_MOVE },
    { "R6_EGG_ROUTE_1ST_FLOOR", O_R6_EggmanMobile::R6_EGG_ROUTE_1ST_FLOOR },
    { "R6_EGG_ROUTE_2ST_FLOOR", O_R6_EggmanMobile::R6_EGG_ROUTE_2ST_FLOOR },
    { "R6_EGG_STEAM", O_R6_EggmanMobile::R6_EGG_STEAM },
};

#endif // RETRO_USE_NATIVE_OBJECTS

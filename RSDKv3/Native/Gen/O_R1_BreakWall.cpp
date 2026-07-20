#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R1_BreakWall.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from BreakWall.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R1_BreakWall::ObjectStartup()
{
    LoadSpriteSheet("R1/Objects2.gif");
    AddSpriteFrame(-16, -24, 32, 48, 190, 1);
    AddSpriteFrame(-16, -24, 32, 48, 223, 1);
    AddSpriteFrame(-16, -24, 32, 48, 190, 50);
    AddSpriteFrame(-16, -24, 32, 48, 223, 50);
    AddSpriteFrame(-16, -24, 32, 48, 190, 99);
    AddSpriteFrame(-16, -24, 32, 48, 223, 99);
    AddSpriteFrame(-16, -24, 32, 48, 190, 148);
    AddSpriteFrame(-16, -24, 32, 48, 223, 148);
    scriptEng.tempValue[0] = 0;
    scriptEng.tempValue[3] = 1;
    while (scriptEng.tempValue[0] < 3) {
        scriptEng.tempValue[1] = 0;
        scriptEng.tempValue[2] = 190;
        while (scriptEng.tempValue[1] < 2) {
            AddSpriteFrame(-8, -8, 16, 16, scriptEng.tempValue[2], scriptEng.tempValue[3]);
            scriptEng.tempValue[1]++;
            scriptEng.tempValue[2] += 16;
        }
        scriptEng.tempValue[0]++;
        scriptEng.tempValue[3] += 16;
    }
    scriptEng.tempValue[0] = 0;
    scriptEng.tempValue[3] = 1;
    while (scriptEng.tempValue[0] < 3) {
        scriptEng.tempValue[1] = 0;
        scriptEng.tempValue[2] = 223;
        while (scriptEng.tempValue[1] < 2) {
            AddSpriteFrame(-8, -8, 16, 16, scriptEng.tempValue[2], scriptEng.tempValue[3]);
            scriptEng.tempValue[1]++;
            scriptEng.tempValue[2] += 16;
        }
        scriptEng.tempValue[0]++;
        scriptEng.tempValue[3] += 16;
    }
    scriptEng.tempValue[0] = 0;
    scriptEng.tempValue[3] = 50;
    while (scriptEng.tempValue[0] < 3) {
        scriptEng.tempValue[1] = 0;
        scriptEng.tempValue[2] = 190;
        while (scriptEng.tempValue[1] < 2) {
            AddSpriteFrame(-8, -8, 16, 16, scriptEng.tempValue[2], scriptEng.tempValue[3]);
            scriptEng.tempValue[1]++;
            scriptEng.tempValue[2] += 16;
        }
        scriptEng.tempValue[0]++;
        scriptEng.tempValue[3] += 16;
    }
    scriptEng.tempValue[0] = 0;
    scriptEng.tempValue[3] = 50;
    while (scriptEng.tempValue[0] < 3) {
        scriptEng.tempValue[1] = 0;
        scriptEng.tempValue[2] = 223;
        while (scriptEng.tempValue[1] < 2) {
            AddSpriteFrame(-8, -8, 16, 16, scriptEng.tempValue[2], scriptEng.tempValue[3]);
            scriptEng.tempValue[1]++;
            scriptEng.tempValue[2] += 16;
        }
        scriptEng.tempValue[0]++;
        scriptEng.tempValue[3] += 16;
    }
    scriptEng.tempValue[0] = 0;
    scriptEng.tempValue[3] = 99;
    while (scriptEng.tempValue[0] < 3) {
        scriptEng.tempValue[1] = 0;
        scriptEng.tempValue[2] = 190;
        while (scriptEng.tempValue[1] < 2) {
            AddSpriteFrame(-8, -8, 16, 16, scriptEng.tempValue[2], scriptEng.tempValue[3]);
            scriptEng.tempValue[1]++;
            scriptEng.tempValue[2] += 16;
        }
        scriptEng.tempValue[0]++;
        scriptEng.tempValue[3] += 16;
    }
    scriptEng.tempValue[0] = 0;
    scriptEng.tempValue[3] = 99;
    while (scriptEng.tempValue[0] < 3) {
        scriptEng.tempValue[1] = 0;
        scriptEng.tempValue[2] = 223;
        while (scriptEng.tempValue[1] < 2) {
            AddSpriteFrame(-8, -8, 16, 16, scriptEng.tempValue[2], scriptEng.tempValue[3]);
            scriptEng.tempValue[1]++;
            scriptEng.tempValue[2] += 16;
        }
        scriptEng.tempValue[0]++;
        scriptEng.tempValue[3] += 16;
    }
    scriptEng.tempValue[0] = 0;
    scriptEng.tempValue[3] = 148;
    while (scriptEng.tempValue[0] < 3) {
        scriptEng.tempValue[1] = 0;
        scriptEng.tempValue[2] = 190;
        while (scriptEng.tempValue[1] < 2) {
            AddSpriteFrame(-8, -8, 16, 16, scriptEng.tempValue[2], scriptEng.tempValue[3]);
            scriptEng.tempValue[1]++;
            scriptEng.tempValue[2] += 16;
        }
        scriptEng.tempValue[0]++;
        scriptEng.tempValue[3] += 16;
    }
    scriptEng.tempValue[0] = 0;
    scriptEng.tempValue[3] = 148;
    while (scriptEng.tempValue[0] < 3) {
        scriptEng.tempValue[1] = 0;
        scriptEng.tempValue[2] = 223;
        while (scriptEng.tempValue[1] < 2) {
            AddSpriteFrame(-8, -8, 16, 16, scriptEng.tempValue[2], scriptEng.tempValue[3]);
            scriptEng.tempValue[1]++;
            scriptEng.tempValue[2] += 16;
        }
        scriptEng.tempValue[0]++;
        scriptEng.tempValue[3] += 16;
    }
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Breakable Wall")) {
            objectEntityList[scriptEng.arrayPosition[0]].drawOrder = 4;
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_R1_BreakWall::ObjectMain()
{
    Entity *self = Self();

    if (self->propertyValue > 7) {
        self->XPos += self->values[0];
        self->YPos += self->values[1];
        self->values[1] += 0x4000;
        if (GetObjectOutOfBounds(objectLoop) == 1) {
            self->type = TypeNameID("Blank Object");
        }
    }
}

void O_R1_BreakWall::ObjectPlayerInteraction()
{
    Entity *self = Self();

    if (self->propertyValue < 8) {
        CheckResult() = 0;
        if (pAnimation() == GVar("ANI_JUMPING")) {
            CheckResult() = 1;
        }
        if (CheckResult() == 1) {
            PlayerObjectCollision(C_TOUCH, -17, -24, 17, 24);
            if (CheckResult() == 1) {
                self->type = TypeNameID("Blank Object");
                PlaySfx(22, 0);
                scriptEng.tempValue[0] = self->propertyValue;
                scriptEng.tempValue[0] *= 6;
                scriptEng.tempValue[0] += 8;
                scriptEng.tempValue[1] = self->XPos;
                scriptEng.tempValue[1] -= 0x80000;
                scriptEng.tempValue[2] = self->XPos;
                scriptEng.tempValue[2] += 0x80000;
                scriptEng.tempValue[3] = self->YPos;
                scriptEng.tempValue[3] -= 0x100000;
                if (pXPos() < self->XPos) {
                    CreateTempObject(TypeNameID("Breakable Wall"), scriptEng.tempValue[0], scriptEng.tempValue[1], scriptEng.tempValue[3]);
                    objectEntityList[scriptEng.arrayPosition[2]].values[0] = -0x30000;
                    objectEntityList[scriptEng.arrayPosition[2]].values[1] = -0x20000;
                    objectEntityList[scriptEng.arrayPosition[2]].drawOrder = 4;
                    scriptEng.tempValue[0]++;
                    CreateTempObject(TypeNameID("Breakable Wall"), scriptEng.tempValue[0], scriptEng.tempValue[2], scriptEng.tempValue[3]);
                    objectEntityList[scriptEng.arrayPosition[2]].values[0] = -0x20000;
                    objectEntityList[scriptEng.arrayPosition[2]].values[1] = -0x20000;
                    objectEntityList[scriptEng.arrayPosition[2]].drawOrder = 4;
                    scriptEng.tempValue[0]++;
                    scriptEng.tempValue[3] += 0x100000;
                    CreateTempObject(TypeNameID("Breakable Wall"), scriptEng.tempValue[0], scriptEng.tempValue[1], scriptEng.tempValue[3]);
                    objectEntityList[scriptEng.arrayPosition[2]].values[0] = -0x40000;
                    objectEntityList[scriptEng.arrayPosition[2]].values[1] = -0x10000;
                    objectEntityList[scriptEng.arrayPosition[2]].drawOrder = 4;
                    scriptEng.tempValue[0]++;
                    CreateTempObject(TypeNameID("Breakable Wall"), scriptEng.tempValue[0], scriptEng.tempValue[2], scriptEng.tempValue[3]);
                    objectEntityList[scriptEng.arrayPosition[2]].values[0] = -0x30000;
                    objectEntityList[scriptEng.arrayPosition[2]].values[1] = -0x10000;
                    objectEntityList[scriptEng.arrayPosition[2]].drawOrder = 4;
                    scriptEng.tempValue[0]++;
                    scriptEng.tempValue[3] += 0x100000;
                    CreateTempObject(TypeNameID("Breakable Wall"), scriptEng.tempValue[0], scriptEng.tempValue[1], scriptEng.tempValue[3]);
                    objectEntityList[scriptEng.arrayPosition[2]].values[0] = -0x30000;
                    objectEntityList[scriptEng.arrayPosition[2]].values[1] = 0x10000;
                    objectEntityList[scriptEng.arrayPosition[2]].drawOrder = 4;
                    scriptEng.tempValue[0]++;
                    CreateTempObject(TypeNameID("Breakable Wall"), scriptEng.tempValue[0], scriptEng.tempValue[2], scriptEng.tempValue[3]);
                    objectEntityList[scriptEng.arrayPosition[2]].values[0] = -0x20000;
                    objectEntityList[scriptEng.arrayPosition[2]].values[1] = 0x10000;
                    objectEntityList[scriptEng.arrayPosition[2]].drawOrder = 4;
                    scriptEng.tempValue[0]++;
                    scriptEng.tempValue[3] += 0x100000;
                } else {
                    CreateTempObject(TypeNameID("Breakable Wall"), scriptEng.tempValue[0], scriptEng.tempValue[1], scriptEng.tempValue[3]);
                    objectEntityList[scriptEng.arrayPosition[2]].values[0] = 0x20000;
                    objectEntityList[scriptEng.arrayPosition[2]].values[1] = -0x20000;
                    objectEntityList[scriptEng.arrayPosition[2]].drawOrder = 4;
                    scriptEng.tempValue[0]++;
                    CreateTempObject(TypeNameID("Breakable Wall"), scriptEng.tempValue[0], scriptEng.tempValue[2], scriptEng.tempValue[3]);
                    objectEntityList[scriptEng.arrayPosition[2]].values[0] = 0x30000;
                    objectEntityList[scriptEng.arrayPosition[2]].values[1] = -0x20000;
                    objectEntityList[scriptEng.arrayPosition[2]].drawOrder = 4;
                    scriptEng.tempValue[0]++;
                    scriptEng.tempValue[3] += 0x100000;
                    CreateTempObject(TypeNameID("Breakable Wall"), scriptEng.tempValue[0], scriptEng.tempValue[1], scriptEng.tempValue[3]);
                    objectEntityList[scriptEng.arrayPosition[2]].values[0] = 0x30000;
                    objectEntityList[scriptEng.arrayPosition[2]].values[1] = -0x10000;
                    objectEntityList[scriptEng.arrayPosition[2]].drawOrder = 4;
                    scriptEng.tempValue[0]++;
                    CreateTempObject(TypeNameID("Breakable Wall"), scriptEng.tempValue[0], scriptEng.tempValue[2], scriptEng.tempValue[3]);
                    objectEntityList[scriptEng.arrayPosition[2]].values[0] = 0x40000;
                    objectEntityList[scriptEng.arrayPosition[2]].values[1] = -0x10000;
                    objectEntityList[scriptEng.arrayPosition[2]].drawOrder = 4;
                    scriptEng.tempValue[0]++;
                    scriptEng.tempValue[3] += 0x100000;
                    CreateTempObject(TypeNameID("Breakable Wall"), scriptEng.tempValue[0], scriptEng.tempValue[1], scriptEng.tempValue[3]);
                    objectEntityList[scriptEng.arrayPosition[2]].values[0] = 0x20000;
                    objectEntityList[scriptEng.arrayPosition[2]].values[1] = 0x10000;
                    objectEntityList[scriptEng.arrayPosition[2]].drawOrder = 4;
                    scriptEng.tempValue[0]++;
                    CreateTempObject(TypeNameID("Breakable Wall"), scriptEng.tempValue[0], scriptEng.tempValue[2], scriptEng.tempValue[3]);
                    objectEntityList[scriptEng.arrayPosition[2]].values[0] = 0x30000;
                    objectEntityList[scriptEng.arrayPosition[2]].values[1] = 0x10000;
                    objectEntityList[scriptEng.arrayPosition[2]].drawOrder = 4;
                    scriptEng.tempValue[0]++;
                    scriptEng.tempValue[3] += 0x100000;
                }
            }
        } else {
            PlayerObjectCollision(C_TOUCH, -17, -24, 16, 24);
            if (CheckResult() == 1) {
                if (pXPos() < self->XPos) {
                    pXPos() = pCollisionLeft();
                    pXPos() <<= 16;
                    pXPos() += self->XPos;
                    pXPos() -= 0x100000;
                    pSpeed() = 0;
                    pXVel() = 0;
                    if (pRight() == 1) {
                        if (pDirection() == 0) {
                            pPushing() = 2;
                        }
                    }
                } else {
                    pXPos() = pCollisionRight();
                    pXPos() <<= 16;
                    pXPos() += self->XPos;
                    pXPos() += 0x100000;
                    pSpeed() = 0;
                    pXVel() = 0;
                    if (pDirection() == 1) {
                        pPushing() = 2;
                    }
                }
            }
        }
    }
}

void O_R1_BreakWall::ObjectDraw()
{
    Entity *self = Self();

    DrawSprite_Frame(self->propertyValue);
}

#endif // RETRO_USE_NATIVE_OBJECTS

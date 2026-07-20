#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R5_BreakWall.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from BreakWall.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R5_BreakWall::ObjectStartup()
{
    switch (objectEntityList[24].propertyValue) {
        case 0:
        LoadSpriteSheet("R5/Objects.gif");
        AddSpriteFrame(-16, -48, 32, 96, 223, 141);
        scriptEng.tempValue[0] = 223;
        scriptEng.tempValue[1] = 239;
        scriptEng.tempValue[2] = 141;
        break;
        case 1:
        LoadSpriteSheet("R5/Objects3.gif");
        AddSpriteFrame(-16, -48, 32, 96, 132, 1);
        scriptEng.tempValue[0] = 132;
        scriptEng.tempValue[1] = 148;
        scriptEng.tempValue[2] = 1;
        break;
        case 2:
        LoadSpriteSheet("R5/Objects3.gif");
        AddSpriteFrame(-16, -48, 32, 96, 66, 1);
        scriptEng.tempValue[0] = 66;
        scriptEng.tempValue[1] = 82;
        scriptEng.tempValue[2] = 1;
        break;
        case 3:
        LoadSpriteSheet("R5/Objects3.gif");
        AddSpriteFrame(-16, -48, 32, 96, 99, 1);
        scriptEng.tempValue[0] = 99;
        scriptEng.tempValue[1] = 115;
        scriptEng.tempValue[2] = 1;
        break;
    }
    scriptEng.tempValue[2] += 16;
    AddSpriteFrame(-8, -8, 16, 16, scriptEng.tempValue[0], scriptEng.tempValue[2]);
    AddSpriteFrame(-8, -8, 16, 16, scriptEng.tempValue[1], scriptEng.tempValue[2]);
    scriptEng.tempValue[2] += 16;
    AddSpriteFrame(-8, -8, 16, 16, scriptEng.tempValue[0], scriptEng.tempValue[2]);
    AddSpriteFrame(-8, -8, 16, 16, scriptEng.tempValue[1], scriptEng.tempValue[2]);
    scriptEng.tempValue[2] += 16;
    AddSpriteFrame(-8, -8, 16, 16, scriptEng.tempValue[0], scriptEng.tempValue[2]);
    AddSpriteFrame(-8, -8, 16, 16, scriptEng.tempValue[1], scriptEng.tempValue[2]);
    scriptEng.tempValue[2] += 16;
    AddSpriteFrame(-8, -8, 16, 16, scriptEng.tempValue[0], scriptEng.tempValue[2]);
    AddSpriteFrame(-8, -8, 16, 16, scriptEng.tempValue[1], scriptEng.tempValue[2]);
}

void O_R5_BreakWall::ObjectMain()
{
    Entity *self = Self();

    if (self->propertyValue > 0) {
        self->XPos += self->values[0];
        self->YPos += self->values[1];
        self->values[1] += 0x4000;
        if (GetObjectOutOfBounds(objectLoop) == 1) {
            self->type = TypeNameID("Blank Object");
        }
    } else {
        if (self->state == 1) {
            PlayerObjectCollision(C_TOUCH, -384, -256, 384, 256);
            if (CheckResult() == 0) {
                self->state = 0;
                self->priority = 0;
            }
        }
    }
}

void O_R5_BreakWall::ObjectPlayerInteraction()
{
    Entity *self = Self();

    if (self->propertyValue < 1) {
        if (self->state == 0) {
            CheckResult() = 0;
            if (pAnimation() == GVar("ANI_JUMPING")) {
                CheckResult() = 1;
            }
            if (CheckResult() == 1) {
                PlayerObjectCollision(C_TOUCH, -18, -48, 18, 48);
                if (CheckResult() == 1) {
                    self->state = 1;
                    self->priority = 1;
                    PlaySfx(22, 0);
                    scriptEng.tempValue[1] = self->XPos;
                    scriptEng.tempValue[1] -= 0x80000;
                    scriptEng.tempValue[2] = self->XPos;
                    scriptEng.tempValue[2] += 0x80000;
                    scriptEng.tempValue[3] = self->YPos;
                    scriptEng.tempValue[3] -= 0x180000;
                    CreateTempObject(TypeNameID("Breakable Wall"), 1, scriptEng.tempValue[1], scriptEng.tempValue[3]);
                    objectEntityList[scriptEng.arrayPosition[2]].values[0] = -0x10000;
                    objectEntityList[scriptEng.arrayPosition[2]].values[1] = -0x20000;
                    objectEntityList[scriptEng.arrayPosition[2]].drawOrder = 5;
                    CreateTempObject(TypeNameID("Breakable Wall"), 2, scriptEng.tempValue[2], scriptEng.tempValue[3]);
                    objectEntityList[scriptEng.arrayPosition[2]].values[0] = 0x10000;
                    objectEntityList[scriptEng.arrayPosition[2]].values[1] = -0x20000;
                    objectEntityList[scriptEng.arrayPosition[2]].drawOrder = 5;
                    scriptEng.tempValue[3] += 0x100000;
                    CreateTempObject(TypeNameID("Breakable Wall"), 3, scriptEng.tempValue[1], scriptEng.tempValue[3]);
                    objectEntityList[scriptEng.arrayPosition[2]].values[0] = -0x20000;
                    objectEntityList[scriptEng.arrayPosition[2]].values[1] = -0x10000;
                    objectEntityList[scriptEng.arrayPosition[2]].drawOrder = 5;
                    CreateTempObject(TypeNameID("Breakable Wall"), 4, scriptEng.tempValue[2], scriptEng.tempValue[3]);
                    objectEntityList[scriptEng.arrayPosition[2]].values[0] = 0x20000;
                    objectEntityList[scriptEng.arrayPosition[2]].values[1] = -0x10000;
                    objectEntityList[scriptEng.arrayPosition[2]].drawOrder = 5;
                    scriptEng.tempValue[3] += 0x100000;
                    CreateTempObject(TypeNameID("Breakable Wall"), 5, scriptEng.tempValue[1], scriptEng.tempValue[3]);
                    objectEntityList[scriptEng.arrayPosition[2]].values[0] = -0x40000;
                    objectEntityList[scriptEng.arrayPosition[2]].values[1] = 0;
                    objectEntityList[scriptEng.arrayPosition[2]].drawOrder = 5;
                    CreateTempObject(TypeNameID("Breakable Wall"), 6, scriptEng.tempValue[2], scriptEng.tempValue[3]);
                    objectEntityList[scriptEng.arrayPosition[2]].values[0] = 0x40000;
                    objectEntityList[scriptEng.arrayPosition[2]].values[1] = 0;
                    objectEntityList[scriptEng.arrayPosition[2]].drawOrder = 5;
                    scriptEng.tempValue[3] += 0x100000;
                    CreateTempObject(TypeNameID("Breakable Wall"), 7, scriptEng.tempValue[1], scriptEng.tempValue[3]);
                    objectEntityList[scriptEng.arrayPosition[2]].values[0] = -0x20000;
                    objectEntityList[scriptEng.arrayPosition[2]].values[1] = 0x10000;
                    objectEntityList[scriptEng.arrayPosition[2]].drawOrder = 5;
                    CreateTempObject(TypeNameID("Breakable Wall"), 8, scriptEng.tempValue[2], scriptEng.tempValue[3]);
                    objectEntityList[scriptEng.arrayPosition[2]].values[0] = 0x20000;
                    objectEntityList[scriptEng.arrayPosition[2]].values[1] = 0x10000;
                    objectEntityList[scriptEng.arrayPosition[2]].drawOrder = 5;
                }
            } else {
                PlayerObjectCollision(C_BOX, -16, -48, 16, 48);
                PlayerObjectCollision(C_TOUCH, -16, -48, 16, 48);
                if (CheckResult() == 1) {
                    if (pXPos() < self->XPos) {
                        pXPos() = pCollisionLeft();
                        pXPos() <<= 16;
                        pXPos() += self->XPos;
                        pXPos() -= 0x100000;
                    } else {
                        pXPos() = pCollisionRight();
                        pXPos() <<= 16;
                        pXPos() += self->XPos;
                        pXPos() += 0x100000;
                    }
                }
            }
        }
    }
}

void O_R5_BreakWall::ObjectDraw()
{
    Entity *self = Self();

    if (self->state == 0) {
        DrawSprite_Frame(self->propertyValue);
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS

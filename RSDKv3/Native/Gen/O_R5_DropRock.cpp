#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R5_DropRock.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from DropRock.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R5_DropRock::ObjectStartup()
{
    LoadSpriteSheet("R5/Objects.gif");
    AddSpriteFrame(-16, -16, 32, 32, 92, 18);
    AddSpriteFrame(-8, -8, 16, 16, 92, 18);
    AddSpriteFrame(-8, -8, 16, 16, 108, 18);
    AddSpriteFrame(-8, -8, 16, 16, 92, 34);
    AddSpriteFrame(-8, -8, 16, 16, 108, 34);
}

void O_R5_DropRock::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 1:
        if (self->values[1] < 0x80000) {
            self->values[1] += 0x4000;
        }
        self->YPos += self->values[1];
        if (self->values[1] > 0x20000) {
            ObjectTileCollision_Script(0, 0, 12, 0);
            if (CheckResult() == 1) {
                PlaySfx(22, 0);
                self->state = 2;
                CreateTempObject(TypeNameID("Drop Rock"), 1, self->XPos, self->YPos);
                objectEntityList[scriptEng.arrayPosition[2]].state = 3;
                objectEntityList[scriptEng.arrayPosition[2]].XPos -= 0x80000;
                objectEntityList[scriptEng.arrayPosition[2]].YPos -= 0x80000;
                objectEntityList[scriptEng.arrayPosition[2]].values[0] = -0x10000;
                objectEntityList[scriptEng.arrayPosition[2]].values[1] = -0x40000;
                objectEntityList[scriptEng.arrayPosition[2]].drawOrder = 5;
                CreateTempObject(TypeNameID("Drop Rock"), 2, self->XPos, self->YPos);
                objectEntityList[scriptEng.arrayPosition[2]].state = 3;
                objectEntityList[scriptEng.arrayPosition[2]].XPos += 0x80000;
                objectEntityList[scriptEng.arrayPosition[2]].YPos -= 0x80000;
                objectEntityList[scriptEng.arrayPosition[2]].values[0] = 0x10000;
                objectEntityList[scriptEng.arrayPosition[2]].values[1] = -0x40000;
                objectEntityList[scriptEng.arrayPosition[2]].drawOrder = 5;
                CreateTempObject(TypeNameID("Drop Rock"), 3, self->XPos, self->YPos);
                objectEntityList[scriptEng.arrayPosition[2]].state = 3;
                objectEntityList[scriptEng.arrayPosition[2]].XPos -= 0x80000;
                objectEntityList[scriptEng.arrayPosition[2]].YPos += 0x80000;
                objectEntityList[scriptEng.arrayPosition[2]].values[0] = -0x20000;
                objectEntityList[scriptEng.arrayPosition[2]].values[1] = -0x20000;
                objectEntityList[scriptEng.arrayPosition[2]].drawOrder = 5;
                CreateTempObject(TypeNameID("Drop Rock"), 4, self->XPos, self->YPos);
                objectEntityList[scriptEng.arrayPosition[2]].state = 3;
                objectEntityList[scriptEng.arrayPosition[2]].XPos += 0x80000;
                objectEntityList[scriptEng.arrayPosition[2]].YPos += 0x80000;
                objectEntityList[scriptEng.arrayPosition[2]].values[0] = 0x20000;
                objectEntityList[scriptEng.arrayPosition[2]].values[1] = -0x20000;
                objectEntityList[scriptEng.arrayPosition[2]].drawOrder = 5;
                CreateTempObject(TypeNameID("Explosion"), 0, self->XPos, self->YPos);
                objectEntityList[scriptEng.arrayPosition[2]].drawOrder = 5;
            }
        }
        break;
        case 2:
        if (GetObjectOutOfBounds(objectLoop) == 1) {
            self->YPos = self->values[2];
            self->priority = 0;
            self->state = 0;
        }
        break;
        case 3:
        self->XPos += self->values[0];
        self->values[1] += 0x4000;
        self->YPos += self->values[1];
        if (GetObjectOutOfBounds(objectLoop) == 1) {
            self->type = TypeNameID("Blank Object");
        }
        break;
    }
}

void O_R5_DropRock::ObjectPlayerInteraction()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        PlayerObjectCollision(C_BOX, -16, -16, 16, 16);
        PlayerObjectCollision(C_TOUCH, -4, 0, 4, 96);
        if (CheckResult() == 1) {
            self->values[2] = self->YPos;
            self->priority = 1;
            self->values[1] = 0;
            self->state = 1;
        }
        case 1:
        PlayerObjectCollision(C_BOX, -16, -16, 12, 16);
        if (CheckResult() == 4) {
            PlaySfx(22, 0);
            self->state = 2;
            CallScriptFunctionNamed("Player_Hit", scriptSub);
            CreateTempObject(TypeNameID("Drop Rock"), 1, self->XPos, self->YPos);
            objectEntityList[scriptEng.arrayPosition[2]].state = 3;
            objectEntityList[scriptEng.arrayPosition[2]].XPos -= 0x80000;
            objectEntityList[scriptEng.arrayPosition[2]].YPos -= 0x80000;
            objectEntityList[scriptEng.arrayPosition[2]].values[0] = -0x10000;
            objectEntityList[scriptEng.arrayPosition[2]].values[1] = -0x40000;
            objectEntityList[scriptEng.arrayPosition[2]].drawOrder = 5;
            CreateTempObject(TypeNameID("Drop Rock"), 2, self->XPos, self->YPos);
            objectEntityList[scriptEng.arrayPosition[2]].state = 3;
            objectEntityList[scriptEng.arrayPosition[2]].XPos += 0x80000;
            objectEntityList[scriptEng.arrayPosition[2]].YPos -= 0x80000;
            objectEntityList[scriptEng.arrayPosition[2]].values[0] = 0x10000;
            objectEntityList[scriptEng.arrayPosition[2]].values[1] = -0x40000;
            objectEntityList[scriptEng.arrayPosition[2]].drawOrder = 5;
            CreateTempObject(TypeNameID("Drop Rock"), 3, self->XPos, self->YPos);
            objectEntityList[scriptEng.arrayPosition[2]].state = 3;
            objectEntityList[scriptEng.arrayPosition[2]].XPos -= 0x80000;
            objectEntityList[scriptEng.arrayPosition[2]].YPos += 0x80000;
            objectEntityList[scriptEng.arrayPosition[2]].values[0] = -0x20000;
            objectEntityList[scriptEng.arrayPosition[2]].values[1] = -0x30000;
            objectEntityList[scriptEng.arrayPosition[2]].drawOrder = 5;
            CreateTempObject(TypeNameID("Drop Rock"), 4, self->XPos, self->YPos);
            objectEntityList[scriptEng.arrayPosition[2]].state = 3;
            objectEntityList[scriptEng.arrayPosition[2]].XPos += 0x80000;
            objectEntityList[scriptEng.arrayPosition[2]].YPos += 0x80000;
            objectEntityList[scriptEng.arrayPosition[2]].values[0] = 0x20000;
            objectEntityList[scriptEng.arrayPosition[2]].values[1] = -0x30000;
            objectEntityList[scriptEng.arrayPosition[2]].drawOrder = 5;
            CreateTempObject(TypeNameID("Explosion"), 0, self->XPos, self->YPos);
            objectEntityList[scriptEng.arrayPosition[2]].drawOrder = 5;
        }
        break;
    }
}

void O_R5_DropRock::ObjectDraw()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        case 1:
        DrawSprite_Frame(0);
        break;
        case 3:
        DrawSprite_Frame(self->propertyValue);
        break;
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R8_SpikePuzzle.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from SpikePuzzle.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R8_SpikePuzzle::ObjectStartup()
{
    LoadSpriteSheet("R8/Objects2.gif");
    AddSpriteFrame(-80, -8, 24, 24, 133, 1);
    AddSpriteFrame(-56, -8, 32, 24, 100, 1);
    AddSpriteFrame(-24, -8, 24, 16, 158, 1);
    AddSpriteFrame(0, -8, 24, 16, 158, 1);
    AddSpriteFrame(24, -8, 32, 24, 100, 1);
    AddSpriteFrame(56, -8, 24, 24, 133, 1);
    AddSpriteFrame(-80, -8, 24, 24, 133, 1);
    AddSpriteFrame(-56, -8, 24, 16, 158, 1);
    AddSpriteFrame(-32, -8, 24, 16, 158, 1);
    AddSpriteFrame(-8, -8, 32, 24, 100, 1);
    AddSpriteFrame(24, -8, 32, 24, 100, 1);
    AddSpriteFrame(56, -8, 24, 24, 133, 1);
    AddSpriteFrame(-80, -8, 32, 24, 100, 1);
    AddSpriteFrame(-48, -8, 32, 24, 100, 1);
    AddSpriteFrame(-16, -8, 24, 24, 133, 1);
    AddSpriteFrame(8, -8, 24, 16, 158, 1);
    AddSpriteFrame(32, -8, 24, 16, 158, 1);
    AddSpriteFrame(56, -8, 24, 24, 133, 1);
}

void O_R8_SpikePuzzle::ObjectMain()
{
    Entity *self = Self();

    if (self->values[2] == 0) {
        if (GetObjectOutOfBounds(objectLoop) == 1) {
            SpikePuzzle_Reset();
            self->state = 1;
            self->priority = 0;
        }
        switch (self->state) {
            case 0:
            SpikePuzzle_Reset();
            self->state++;
            break;
            case 1:
            PlayerObjectCollision(C_TOUCH, -80, -8, 80, 224);
            if (CheckResult() == 1) {
                self->priority = 1;
                self->state++;
                objectEntityList[objectLoop + 1].values[1] = 0x8000;
            }
            break;
            case 2:
            if (self->values[0] < 284) {
                self->values[0]++;
            } else {
                scriptEng.tempValue[0] = self->YPos;
                scriptEng.tempValue[0] += 0x400000;
                if (pYPos() > scriptEng.tempValue[0]) {
                    self->values[0] = 0;
                    self->values[4]++;
                    if (self->values[4] < 6) {
                        scriptEng.arrayPosition[0] = objectLoop;
                        scriptEng.arrayPosition[0] += self->values[4];
                        objectEntityList[scriptEng.arrayPosition[0]].type = TypeNameID("Spike Puzzle");
                        objectEntityList[scriptEng.arrayPosition[0]].XPos = self->XPos;
                        objectEntityList[scriptEng.arrayPosition[0]].YPos = self->YPos;
                        objectEntityList[scriptEng.arrayPosition[0]].YPos -= 0x200000;
                        objectEntityList[scriptEng.arrayPosition[0]].values[1] = 0x8000;
                    } else {
                        self->state++;
                    }
                }
            }
            break;
        }
    } else {
        self->YPos += self->values[1];
        ObjectTileCollision_Script(0, 0, self->values[3], 0);
        if (CheckResult() == 1) {
            self->values[1] = 0;
        }
    }
}

void O_R8_SpikePuzzle::ObjectPlayerInteraction()
{
    Entity *self = Self();

    switch (self->values[2]) {
        case 1:
        PlayerObjectCollision(C_BOX, -80, -9, -24, 16);
        scriptEng.tempValue[0] = CheckResult();
        PlayerObjectCollision(C_BOX, 24, -9, 80, 16);
        scriptEng.tempValue[0] += CheckResult();
        if (scriptEng.tempValue[0] == 1) {
            pYPos() += 0x10000;
        }
        if (scriptEng.tempValue[0] == 4) {
            if (pGravity() == 0) {
                CallScriptFunctionNamed("Player_Kill", scriptSub);
            } else {
                CallScriptFunctionNamed("Player_Hit", scriptSub);
            }
        }
        break;
        case 2:
        PlayerObjectCollision(C_BOX, -80, -9, -56, 16);
        scriptEng.tempValue[0] = CheckResult();
        PlayerObjectCollision(C_BOX, -8, -9, 80, 16);
        scriptEng.tempValue[0] += CheckResult();
        if (scriptEng.tempValue[0] == 1) {
            pYPos() += 0x10000;
        }
        if (scriptEng.tempValue[0] == 4) {
            if (pGravity() == 0) {
                CallScriptFunctionNamed("Player_Kill", scriptSub);
            } else {
                CallScriptFunctionNamed("Player_Hit", scriptSub);
            }
        }
        break;
        case 3:
        PlayerObjectCollision(C_BOX, -80, -9, 8, 16);
        scriptEng.tempValue[0] = CheckResult();
        PlayerObjectCollision(C_BOX, 56, -9, 80, 16);
        scriptEng.tempValue[0] += CheckResult();
        if (scriptEng.tempValue[0] == 1) {
            pYPos() += 0x10000;
        }
        if (scriptEng.tempValue[0] == 4) {
            if (pGravity() == 0) {
                CallScriptFunctionNamed("Player_Kill", scriptSub);
            } else {
                CallScriptFunctionNamed("Player_Hit", scriptSub);
            }
        }
        break;
    }
}

void O_R8_SpikePuzzle::ObjectDraw()
{
    Entity *self = Self();

    switch (self->values[2]) {
        case 1:
        DrawSprite_Frame(0);
        DrawSprite_Frame(1);
        DrawSprite_Frame(2);
        DrawSprite_Frame(3);
        DrawSprite_Frame(4);
        DrawSprite_Frame(5);
        break;
        case 2:
        DrawSprite_Frame(6);
        DrawSprite_Frame(7);
        DrawSprite_Frame(8);
        DrawSprite_Frame(9);
        DrawSprite_Frame(10);
        DrawSprite_Frame(11);
        break;
        case 3:
        DrawSprite_Frame(12);
        DrawSprite_Frame(13);
        DrawSprite_Frame(14);
        DrawSprite_Frame(15);
        DrawSprite_Frame(16);
        DrawSprite_Frame(17);
        break;
    }
}

void O_R8_SpikePuzzle::SpikePuzzle_Reset()
{
    Entity *self = Self();

    self->values[0] = 0;
    self->values[4] = 1;
    objectEntityList[objectLoop + 1].type = TypeNameID("Spike Puzzle");
    objectEntityList[objectLoop + 1].XPos = self->XPos;
    objectEntityList[objectLoop + 1].YPos = self->YPos;
    objectEntityList[objectLoop + 1].values[1] = 0;
    objectEntityList[objectLoop + 1].values[3] = 16;
    objectEntityList[objectLoop + 2].type = TypeNameID("Blank Object");
    objectEntityList[objectLoop + 2].values[1] = 0;
    objectEntityList[objectLoop + 2].values[3] = 40;
    objectEntityList[objectLoop + 3].type = TypeNameID("Blank Object");
    objectEntityList[objectLoop + 3].values[1] = 0;
    objectEntityList[objectLoop + 3].values[3] = 64;
    objectEntityList[objectLoop + 4].type = TypeNameID("Blank Object");
    objectEntityList[objectLoop + 4].values[1] = 0;
    objectEntityList[objectLoop + 4].values[3] = 88;
    objectEntityList[objectLoop + 5].type = TypeNameID("Blank Object");
    objectEntityList[objectLoop + 5].values[1] = 0;
    objectEntityList[objectLoop + 5].values[3] = 112;
    if (self->propertyValue == 0) {
        objectEntityList[objectLoop + 1].values[2] = 1;
        objectEntityList[objectLoop + 2].values[2] = 2;
        objectEntityList[objectLoop + 3].values[2] = 1;
        objectEntityList[objectLoop + 4].values[2] = 3;
        objectEntityList[objectLoop + 5].values[2] = 1;
    } else {
        objectEntityList[objectLoop + 1].values[2] = 1;
        objectEntityList[objectLoop + 2].values[2] = 3;
        objectEntityList[objectLoop + 3].values[2] = 1;
        objectEntityList[objectLoop + 4].values[2] = 2;
        objectEntityList[objectLoop + 5].values[2] = 1;
    }
}

const Native::NativeFunctionDef O_R8_SpikePuzzle::funcs[1] = {
    { "SpikePuzzle_Reset", O_R8_SpikePuzzle::SpikePuzzle_Reset },
};

#endif // RETRO_USE_NATIVE_OBJECTS

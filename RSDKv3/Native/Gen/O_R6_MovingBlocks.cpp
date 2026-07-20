#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R6_MovingBlocks.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from MovingBlocks.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R6_MovingBlocks::ObjectStartup()
{
    LoadSpriteSheet("R6/Objects.gif");
    AddSpriteFrame(-16, -16, 32, 32, 173, 1);
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Moving Blocks")) {
            objectEntityList[scriptEng.arrayPosition[0]].values[0] = objectEntityList[scriptEng.arrayPosition[0]].XPos;
            objectEntityList[scriptEng.arrayPosition[0]].values[1] = objectEntityList[scriptEng.arrayPosition[0]].YPos;
            objectEntityList[scriptEng.arrayPosition[0]].values[2] = objectEntityList[scriptEng.arrayPosition[0]].XPos;
            objectEntityList[scriptEng.arrayPosition[0]].values[3] = objectEntityList[scriptEng.arrayPosition[0]].YPos;
            objectEntityList[scriptEng.arrayPosition[0]].values[4] = objectEntityList[scriptEng.arrayPosition[0]].XPos;
            objectEntityList[scriptEng.arrayPosition[0]].values[5] = objectEntityList[scriptEng.arrayPosition[0]].YPos;
            objectEntityList[scriptEng.arrayPosition[0]].values[6] = objectEntityList[scriptEng.arrayPosition[0]].XPos;
            objectEntityList[scriptEng.arrayPosition[0]].values[7] = objectEntityList[scriptEng.arrayPosition[0]].YPos;
            switch (objectEntityList[scriptEng.arrayPosition[0]].propertyValue) {
                case 0:
                objectEntityList[scriptEng.arrayPosition[0]].rotation = ScriptFuncID("MovingBlocks_MoveType_1");
                break;
                case 1:
                objectEntityList[scriptEng.arrayPosition[0]].rotation = ScriptFuncID("MovingBlocks_MoveType_4");
                break;
                case 3:
                objectEntityList[scriptEng.arrayPosition[0]].rotation = ScriptFuncID("MovingBlocks_MoveType_2");
                break;
                case 4:
                objectEntityList[scriptEng.arrayPosition[0]].rotation = ScriptFuncID("MovingBlocks_MoveType_3");
                break;
            }
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_R6_MovingBlocks::ObjectMain()
{
    Entity *self = Self();

    if (self->state == 0) {
        if (self->animationTimer < 64) {
            self->animationTimer++;
            CallScriptFunction(self->rotation, scriptSub);
        } else {
            self->animationTimer = 0;
            self->state = 1;
            self->direction++;
            if (self->direction > 14) {
                self->direction = 3;
            }
        }
    } else {
        if (self->animationTimer < 30) {
            self->animationTimer++;
        } else {
            self->animationTimer = 0;
            self->state = 0;
        }
    }
}

void O_R6_MovingBlocks::ObjectPlayerInteraction()
{
    Entity *self = Self();

    scriptEng.tempValue[0] = self->XPos;
    scriptEng.tempValue[1] = self->YPos;
    self->XPos = self->values[0];
    self->YPos = self->values[1];
    PlayerObjectCollision(C_BOX, -16, -17, 16, 16);
    if (CheckResult() == 1) {
        pYPos() += 0x10000;
    }
    self->XPos = self->values[2];
    self->YPos = self->values[3];
    PlayerObjectCollision(C_BOX, -16, -17, 16, 16);
    if (CheckResult() == 1) {
        pYPos() += 0x10000;
    }
    self->XPos = self->values[4];
    self->YPos = self->values[5];
    PlayerObjectCollision(C_BOX, -16, -17, 16, 16);
    if (CheckResult() == 1) {
        pYPos() += 0x10000;
    }
    self->XPos = self->values[6];
    self->YPos = self->values[7];
    PlayerObjectCollision(C_BOX, -16, -17, 16, 16);
    if (CheckResult() == 1) {
        pYPos() += 0x10000;
    }
    self->XPos = scriptEng.tempValue[0];
    self->YPos = scriptEng.tempValue[1];
    PlayerObjectCollision(C_BOX, -16, -16, 16, 16);
}

void O_R6_MovingBlocks::ObjectDraw()
{
    Entity *self = Self();

    DrawSprite_FrameXY(0, self->values[0], self->values[1]);
    DrawSprite_FrameXY(0, self->values[6], self->values[7]);
    DrawSprite_FrameXY(0, self->values[2], self->values[3]);
    DrawSprite_FrameXY(0, self->values[4], self->values[5]);
    DrawSprite_Frame(0);
}

void O_R6_MovingBlocks::MovingBlocks_MoveType_1()
{
    Entity *self = Self();

    switch (self->direction) {
        case 0:
        self->values[1] -= 0x8000;
        if (self->animationTimer == 64) {
            self->values[3] = self->values[1];
        }
        break;
        case 1:
        self->values[1] -= 0x8000;
        if (self->animationTimer == 64) {
            self->values[5] = self->values[1];
        }
        break;
        case 2:
        self->values[1] -= 0x8000;
        if (self->animationTimer == 64) {
            self->values[7] = self->values[1];
            self->values[1] = self->YPos;
        }
        break;
        case 3:
        self->values[0] += 0x8000;
        self->values[7] += 0x8000;
        if (self->animationTimer == 64) {
            self->values[4] = self->values[0];
            self->values[5] = self->values[1];
        }
        break;
        case 4:
        self->values[0] += 0x8000;
        self->values[7] += 0x8000;
        if (self->animationTimer == 64) {
            self->values[2] = self->values[0];
            self->values[3] = self->values[1];
        }
        break;
        case 5:
        self->values[0] += 0x8000;
        self->values[7] += 0x8000;
        if (self->animationTimer == 64) {
            self->values[6] = self->values[0];
            self->values[0] = self->XPos;
        }
        break;
        case 6:
        self->values[1] += 0x8000;
        self->values[6] -= 0x8000;
        if (self->animationTimer == 64) {
            self->values[2] = self->values[0];
            self->values[3] = self->values[1];
        }
        break;
        case 7:
        self->values[1] += 0x8000;
        self->values[6] -= 0x8000;
        if (self->animationTimer == 64) {
            self->values[4] = self->values[0];
            self->values[5] = self->values[1];
        }
        break;
        case 8:
        self->values[1] += 0x8000;
        self->values[6] -= 0x8000;
        if (self->animationTimer == 64) {
            self->values[7] = self->values[1];
            self->values[1] = self->YPos;
        }
        break;
        case 9:
        self->values[0] -= 0x8000;
        self->values[7] -= 0x8000;
        if (self->animationTimer == 64) {
            self->values[4] = self->values[0];
            self->values[5] = self->values[1];
        }
        break;
        case 10:
        self->values[0] -= 0x8000;
        self->values[7] -= 0x8000;
        if (self->animationTimer == 64) {
            self->values[2] = self->values[0];
            self->values[3] = self->values[1];
        }
        break;
        case 11:
        self->values[0] -= 0x8000;
        self->values[7] -= 0x8000;
        if (self->animationTimer == 64) {
            self->values[6] = self->values[0];
            self->values[7] = self->values[1];
            self->values[0] = self->XPos;
        }
        break;
        case 12:
        self->values[1] -= 0x8000;
        self->values[6] += 0x8000;
        if (self->animationTimer == 64) {
            self->values[2] = self->values[0];
            self->values[3] = self->values[1];
        }
        break;
        case 13:
        self->values[1] -= 0x8000;
        self->values[6] += 0x8000;
        if (self->animationTimer == 64) {
            self->values[4] = self->values[0];
            self->values[5] = self->values[1];
        }
        break;
        case 14:
        self->values[1] -= 0x8000;
        self->values[6] += 0x8000;
        if (self->animationTimer == 64) {
            self->values[7] = self->values[1];
            self->values[1] = self->YPos;
        }
        break;
    }
}

void O_R6_MovingBlocks::MovingBlocks_MoveType_2()
{
    Entity *self = Self();

    switch (self->direction) {
        case 0:
        self->values[1] -= 0x8000;
        if (self->animationTimer == 64) {
            self->values[3] = self->values[1];
        }
        break;
        case 1:
        self->values[1] -= 0x8000;
        if (self->animationTimer == 64) {
            self->values[5] = self->values[1];
        }
        break;
        case 2:
        self->values[1] -= 0x8000;
        if (self->animationTimer == 64) {
            self->values[7] = self->values[1];
            self->values[1] = self->YPos;
        }
        break;
        case 3:
        self->values[0] -= 0x8000;
        self->values[7] += 0x8000;
        if (self->animationTimer == 64) {
            self->values[4] = self->values[0];
            self->values[5] = self->values[1];
        }
        break;
        case 4:
        self->values[0] -= 0x8000;
        self->values[7] += 0x8000;
        if (self->animationTimer == 64) {
            self->values[2] = self->values[0];
            self->values[3] = self->values[1];
        }
        break;
        case 5:
        self->values[0] -= 0x8000;
        self->values[7] += 0x8000;
        if (self->animationTimer == 64) {
            self->values[6] = self->values[0];
            self->values[7] = self->values[1];
            self->values[0] = self->XPos;
        }
        break;
        case 6:
        self->values[1] += 0x8000;
        self->values[6] += 0x8000;
        if (self->animationTimer == 64) {
            self->values[2] = self->values[0];
            self->values[3] = self->values[1];
        }
        break;
        case 7:
        self->values[1] += 0x8000;
        self->values[6] += 0x8000;
        if (self->animationTimer == 64) {
            self->values[4] = self->values[0];
            self->values[5] = self->values[1];
        }
        break;
        case 8:
        self->values[1] += 0x8000;
        self->values[6] += 0x8000;
        if (self->animationTimer == 64) {
            self->values[7] = self->values[1];
            self->values[1] = self->YPos;
        }
        break;
        case 9:
        self->values[0] += 0x8000;
        self->values[7] -= 0x8000;
        if (self->animationTimer == 64) {
            self->values[4] = self->values[0];
            self->values[5] = self->values[1];
        }
        break;
        case 10:
        self->values[0] += 0x8000;
        self->values[7] -= 0x8000;
        if (self->animationTimer == 64) {
            self->values[2] = self->values[0];
            self->values[3] = self->values[1];
        }
        break;
        case 11:
        self->values[0] += 0x8000;
        self->values[7] -= 0x8000;
        if (self->animationTimer == 64) {
            self->values[6] = self->values[0];
            self->values[0] = self->XPos;
        }
        break;
        case 12:
        self->values[1] -= 0x8000;
        self->values[6] -= 0x8000;
        if (self->animationTimer == 64) {
            self->values[2] = self->values[0];
            self->values[3] = self->values[1];
        }
        break;
        case 13:
        self->values[1] -= 0x8000;
        self->values[6] -= 0x8000;
        if (self->animationTimer == 64) {
            self->values[4] = self->values[0];
            self->values[5] = self->values[1];
        }
        break;
        case 14:
        self->values[1] -= 0x8000;
        self->values[6] -= 0x8000;
        if (self->animationTimer == 64) {
            self->values[7] = self->values[1];
            self->values[1] = self->YPos;
        }
        break;
    }
}

void O_R6_MovingBlocks::MovingBlocks_MoveType_3()
{
    Entity *self = Self();

    switch (self->direction) {
        case 0:
        self->values[1] -= 0x8000;
        if (self->animationTimer == 64) {
            self->values[3] = self->values[1];
        }
        break;
        case 1:
        self->values[1] -= 0x8000;
        if (self->animationTimer == 64) {
            self->values[5] = self->values[1];
        }
        break;
        case 2:
        self->values[0] += 0x8000;
        break;
        case 3:
        self->values[0] -= 0x8000;
        self->values[6] += 0x8000;
        if (self->animationTimer == 64) {
            self->values[4] = self->values[6];
            self->values[5] = self->values[7];
        }
        break;
        case 4:
        self->values[1] += 0x8000;
        self->values[7] -= 0x8000;
        if (self->animationTimer == 64) {
            self->values[2] = self->values[6];
            self->values[3] = self->values[7];
        }
        break;
        case 5:
        self->values[1] += 0x8000;
        self->values[6] += 0x8000;
        break;
        case 6:
        self->values[1] += 0x8000;
        self->values[6] -= 0x8000;
        if (self->animationTimer == 64) {
            self->values[2] = self->values[0];
            self->values[3] = self->values[1];
        }
        break;
        case 7:
        self->values[1] += 0x8000;
        self->values[7] += 0x8000;
        if (self->animationTimer == 64) {
            self->values[4] = self->values[0];
            self->values[5] = self->values[1];
        }
        break;
        case 8:
        self->values[0] += 0x8000;
        self->values[6] -= 0x8000;
        break;
        case 9:
        self->values[0] -= 0x8000;
        self->values[6] -= 0x8000;
        if (self->animationTimer == 64) {
            self->values[4] = self->values[6];
            self->values[5] = self->values[7];
        }
        break;
        case 10:
        self->values[1] -= 0x8000;
        self->values[6] -= 0x8000;
        if (self->animationTimer == 64) {
            self->values[2] = self->values[6];
            self->values[3] = self->values[7];
        }
        break;
        case 11:
        self->values[1] -= 0x8000;
        self->values[6] -= 0x8000;
        break;
        case 12:
        self->values[1] -= 0x8000;
        self->values[6] += 0x8000;
        if (self->animationTimer == 64) {
            self->values[2] = self->values[0];
            self->values[3] = self->values[1];
        }
        break;
        case 13:
        self->values[1] -= 0x8000;
        self->values[6] += 0x8000;
        if (self->animationTimer == 64) {
            self->values[4] = self->values[0];
            self->values[5] = self->values[1];
        }
        break;
        case 14:
        self->values[0] += 0x8000;
        self->values[6] += 0x8000;
        break;
    }
}

void O_R6_MovingBlocks::MovingBlocks_MoveType_4()
{
    Entity *self = Self();

    switch (self->direction) {
        case 0:
        self->values[0] += 0x8000;
        if (self->animationTimer == 64) {
            self->values[2] = self->values[0];
        }
        break;
        case 1:
        self->values[0] += 0x8000;
        if (self->animationTimer == 64) {
            self->values[4] = self->values[0];
        }
        break;
        case 2:
        self->values[1] -= 0x8000;
        break;
        case 3:
        self->values[1] += 0x8000;
        self->values[7] += 0x8000;
        if (self->animationTimer == 64) {
            self->values[4] = self->values[6];
            self->values[5] = self->values[7];
        }
        break;
        case 4:
        self->values[0] -= 0x8000;
        self->values[6] -= 0x8000;
        if (self->animationTimer == 64) {
            self->values[2] = self->values[6];
            self->values[3] = self->values[7];
        }
        break;
        case 5:
        self->values[0] -= 0x8000;
        self->values[6] -= 0x8000;
        break;
        case 6:
        self->values[0] -= 0x8000;
        self->values[6] += 0x8000;
        if (self->animationTimer == 64) {
            self->values[2] = self->values[0];
            self->values[3] = self->values[1];
        }
        break;
        case 7:
        self->values[1] -= 0x8000;
        self->values[6] += 0x8000;
        if (self->animationTimer == 64) {
            self->values[4] = self->values[0];
            self->values[5] = self->values[1];
        }
        break;
        case 8:
        self->values[0] -= 0x8000;
        self->values[7] -= 0x8000;
        break;
        case 9:
        self->values[0] += 0x8000;
        self->values[7] -= 0x8000;
        if (self->animationTimer == 64) {
            self->values[4] = self->values[6];
            self->values[5] = self->values[7];
        }
        break;
        case 10:
        self->values[1] += 0x8000;
        self->values[6] += 0x8000;
        if (self->animationTimer == 64) {
            self->values[2] = self->values[6];
            self->values[3] = self->values[7];
        }
        break;
        case 11:
        self->values[0] += 0x8000;
        self->values[7] -= 0x8000;
        break;
        case 12:
        self->values[0] += 0x8000;
        self->values[7] += 0x8000;
        if (self->animationTimer == 64) {
            self->values[2] = self->values[0];
            self->values[3] = self->values[1];
        }
        break;
        case 13:
        self->values[0] += 0x8000;
        self->values[6] -= 0x8000;
        if (self->animationTimer == 64) {
            self->values[4] = self->values[0];
            self->values[5] = self->values[1];
        }
        break;
        case 14:
        self->values[1] -= 0x8000;
        self->values[7] += 0x8000;
        break;
    }
}

void O_R6_MovingBlocks::MovingBlocks_CrushCheck()
{
}

void O_R6_MovingBlocks::MovingBlocks_CrushCheckTop()
{
}

const Native::NativeFunctionDef O_R6_MovingBlocks::funcs[6] = {
    { "MovingBlocks_MoveType_1", O_R6_MovingBlocks::MovingBlocks_MoveType_1 },
    { "MovingBlocks_MoveType_2", O_R6_MovingBlocks::MovingBlocks_MoveType_2 },
    { "MovingBlocks_MoveType_3", O_R6_MovingBlocks::MovingBlocks_MoveType_3 },
    { "MovingBlocks_MoveType_4", O_R6_MovingBlocks::MovingBlocks_MoveType_4 },
    { "MovingBlocks_CrushCheck", O_R6_MovingBlocks::MovingBlocks_CrushCheck },
    { "MovingBlocks_CrushCheckTop", O_R6_MovingBlocks::MovingBlocks_CrushCheckTop },
};

#endif // RETRO_USE_NATIVE_OBJECTS

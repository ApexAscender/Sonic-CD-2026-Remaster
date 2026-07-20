#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R6_MovingBlocks2.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from MovingBlocks2.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R6_MovingBlocks2::ObjectStartup()
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
            objectEntityList[scriptEng.arrayPosition[0]].rotation = 480;
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_R6_MovingBlocks2::ObjectMain()
{
    Entity *self = Self();

    self->rotation -= 2;
    if (self->rotation < 0) {
        self->rotation += 512;
    }
    self->animationTimer++;
    MovingBlocks_HandleMovement();
    if (self->animationTimer == 64) {
        self->animationTimer = 0;
        self->values[6]++;
        if (self->values[6] > 5) {
            self->values[6] = 2;
        }
    }
}

void O_R6_MovingBlocks2::ObjectPlayerInteraction()
{
    Entity *self = Self();

    scriptEng.tempValue[0] = self->XPos;
    scriptEng.tempValue[1] = self->YPos;
    switch (self->values[6]) {
        case 0:
        case 1:
        self->XPos = self->values[2];
        self->YPos = self->values[3];
        PlayerObjectCollision(C_BOX, -16, -17, 16, 16);
        if (CheckResult() == 1) {
            pYPos() += 0x10000;
        }
        break;
        case 2:
        self->XPos = self->values[2];
        self->YPos = self->values[3];
        PlayerObjectCollision(C_BOX, -16, -17, 16, 16);
        if (CheckResult() == 1) {
            pYPos() += 0x10000;
        }
        self->XPos = self->values[4];
        self->YPos = self->values[5];
        PlayerObjectCollision(C_BOX, -16, -16, 16, 16);
        if (CheckResult() == 4) {
            if (pGravity() == 0) {
                PlaySfx(5, 0);
                PlrEntity()->drawOrder = 5;
                pSpeed() = 0;
                pXVel() = 0;
                pYVel() = -0x68000;
                pState() = PlayerStateID("Player_State_Death");
                pAnimation() = GVar("ANI_DYING");
                pTileCollisions() = 0;
                pObjectInteractions() = 0;
                cameraEnabled = 0;
            }
        }
        break;
        case 3:
        case 4:
        self->XPos = self->values[2];
        self->YPos = self->values[3];
        PlayerObjectCollision(C_BOX, -16, -17, 16, 16);
        if (CheckResult() == 1) {
            pYPos() += 0x10000;
        }
        self->XPos = self->values[4];
        self->YPos = self->values[5];
        PlayerObjectCollision(C_TOUCH, -12, -16, 12, 32);
        if (CheckResult() == 1) {
            PlayerObjectCollision(C_BOX, -16, -16, 16, 16);
            self->XPos = self->values[0];
            self->YPos = self->values[1];
            PlayerObjectCollision(C_BOX, -16, -16, 16, 16);
            if (CheckResult() == 4) {
                if (pGravity() == 0) {
                    PlaySfx(5, 0);
                    PlrEntity()->drawOrder = 5;
                    pSpeed() = 0;
                    pXVel() = 0;
                    pYVel() = -0x68000;
                    pState() = PlayerStateID("Player_State_Death");
                    pAnimation() = GVar("ANI_DYING");
                    pTileCollisions() = 0;
                    pObjectInteractions() = 0;
                    cameraEnabled = 0;
                }
            }
        } else {
            PlayerObjectCollision(C_BOX, -16, -16, 16, 32);
        }
        break;
        case 5:
        self->XPos = self->values[2];
        self->YPos = self->values[3];
        PlayerObjectCollision(C_BOX, -16, -17, 16, 16);
        if (CheckResult() == 1) {
            pYPos() += 0x10000;
        }
        self->XPos = self->values[0];
        self->YPos = self->values[1];
        PlayerObjectCollision(C_BOX, -16, -17, 16, 16);
        if (CheckResult() == 1) {
            pYPos() += 0x10000;
        }
        break;
    }
    self->XPos = scriptEng.tempValue[0];
    self->YPos = scriptEng.tempValue[1];
    PlayerObjectCollision(C_BOX, -16, -16, 16, 16);
}

void O_R6_MovingBlocks2::ObjectDraw()
{
    Entity *self = Self();

    DrawSprite_FrameXY(0, self->values[0], self->values[1]);
    DrawSprite_FrameXY(0, self->values[2], self->values[3]);
    DrawSprite_FrameXY(0, self->values[4], self->values[5]);
    DrawSprite_Frame(0);
}

void O_R6_MovingBlocks2::MovingBlocks_HandleMovement()
{
    Entity *self = Self();

    switch (self->values[6]) {
        case 0:
        self->values[1] -= 0x8000;
        if (self->animationTimer == 64) {
            self->values[3] = self->values[1];
        }
        break;
        case 1:
        self->values[1] -= 0x8000;
        break;
        case 2:
        self->values[1] += 0x8000;
        self->values[5] += 0x8000;
        if (self->animationTimer == 64) {
            self->values[1] = self->values[5];
        }
        break;
        case 3:
        self->values[1] += 0x8000;
        self->values[3] += 0x8000;
        break;
        case 4:
        self->values[1] -= 0x8000;
        self->values[3] -= 0x8000;
        if (self->animationTimer == 64) {
            self->values[1] = self->values[3];
        }
        break;
        case 5:
        self->values[1] -= 0x8000;
        self->values[5] -= 0x8000;
        break;
    }
}

const Native::NativeFunctionDef O_R6_MovingBlocks2::funcs[1] = {
    { "MovingBlocks_HandleMovement", O_R6_MovingBlocks2::MovingBlocks_HandleMovement },
};

#endif // RETRO_USE_NATIVE_OBJECTS

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R4_CrushBlocks.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from CrushBlocks.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R4_CrushBlocks::ObjectStartup()
{
    switch (objectEntityList[24].propertyValue) {
        case 0:
        LoadSpriteSheet("R4/Objects.gif");
        scriptEng.tempValue[0] = 163;
        scriptEng.tempValue[1] = 1;
        scriptEng.tempValue[2] = 196;
        break;
        case 1:
        LoadSpriteSheet("R4/Objects2.gif");
        scriptEng.tempValue[0] = 1;
        scriptEng.tempValue[1] = 157;
        scriptEng.tempValue[2] = 34;
        break;
        case 2:
        LoadSpriteSheet("R4/Objects2.gif");
        scriptEng.tempValue[0] = 1;
        scriptEng.tempValue[1] = 190;
        scriptEng.tempValue[2] = 34;
        break;
        case 3:
        LoadSpriteSheet("R4/Objects2.gif");
        scriptEng.tempValue[0] = 1;
        scriptEng.tempValue[1] = 223;
        scriptEng.tempValue[2] = 34;
        break;
    }
    AddSpriteFrame(-80, -16, 32, 32, scriptEng.tempValue[0], scriptEng.tempValue[1]);
    AddSpriteFrame(-48, -16, 32, 32, scriptEng.tempValue[0], scriptEng.tempValue[1]);
    AddSpriteFrame(-16, -16, 32, 32, scriptEng.tempValue[0], scriptEng.tempValue[1]);
    AddSpriteFrame(16, -16, 32, 32, scriptEng.tempValue[0], scriptEng.tempValue[1]);
    AddSpriteFrame(48, -16, 32, 32, scriptEng.tempValue[0], scriptEng.tempValue[1]);
}

void O_R4_CrushBlocks::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        if (self->values[0] < 60) {
            self->values[0]++;
        } else {
            self->values[0] = 0;
            self->values[2] = 0x8000;
            self->state++;
        }
        break;
        case 1:
        if (self->values[1] < 0x600000) {
            self->values[1] += 0x8000;
        } else {
            self->values[2] = 0;
            self->state++;
        }
        break;
        case 2:
        if (self->values[0] < 120) {
            self->values[0]++;
        } else {
            self->values[0] = 0;
            self->values[2] = -0x20000;
            self->state++;
        }
        break;
        case 3:
        if (self->values[1] > 0) {
            self->values[1] -= 0x20000;
        } else {
            self->values[2] = 0;
            self->state = 0;
        }
        break;
    }
}

void O_R4_CrushBlocks::ObjectPlayerInteraction()
{
    Entity *self = Self();

    scriptEng.tempValue[0] = self->XPos;
    scriptEng.tempValue[1] = 0;
    scriptEng.tempValue[2] = 0;
    self->XPos -= self->values[1];
    PlayerObjectCollision(C_BOX, -80, -64, -48, -32);
    switch (CheckResult()) {
        case 1:
        pXPos() -= self->values[2];
        if (pSpeed() == 0) {
            if (self->values[3] == 0) {
                self->values[3] = 1;
                pXPos() &= 0xFFFF0000;
                self->values[1] &= 0xFFFF0000;
            }
        } else {
            self->values[3] = 0;
        }
        break;
        case 3:
        scriptEng.tempValue[1] = 1;
        break;
    }
    PlayerObjectCollision(C_BOX, -80, -32, -16, 0);
    switch (CheckResult()) {
        case 1:
        pXPos() -= self->values[2];
        if (pSpeed() == 0) {
            if (self->values[3] == 0) {
                self->values[3] = 1;
                pXPos() &= 0xFFFF0000;
                self->values[1] &= 0xFFFF0000;
            }
        } else {
            self->values[3] = 0;
        }
        break;
        case 3:
        scriptEng.tempValue[1] = 1;
        break;
    }
    PlayerObjectCollision(C_BOX, -80, 0, 16, 32);
    switch (CheckResult()) {
        case 1:
        pXPos() -= self->values[2];
        if (pSpeed() == 0) {
            if (self->values[3] == 0) {
                self->values[3] = 1;
                pXPos() &= 0xFFFF0000;
                self->values[1] &= 0xFFFF0000;
            }
        } else {
            self->values[3] = 0;
        }
        break;
        case 3:
        scriptEng.tempValue[1] = 1;
        break;
    }
    PlayerObjectCollision(C_BOX, -80, 32, 48, 64);
    switch (CheckResult()) {
        case 1:
        pXPos() -= self->values[2];
        if (pSpeed() == 0) {
            if (self->values[3] == 0) {
                self->values[3] = 1;
                pXPos() &= 0xFFFF0000;
                self->values[1] &= 0xFFFF0000;
            }
        } else {
            self->values[3] = 0;
        }
        break;
        case 3:
        scriptEng.tempValue[1] = 1;
        break;
    }
    self->XPos = scriptEng.tempValue[0];
    self->XPos += self->values[1];
    PlayerObjectCollision(C_BOX, -48, -64, 80, -32);
    switch (CheckResult()) {
        case 1:
        pXPos() += self->values[2];
        if (pSpeed() == 0) {
            if (self->values[3] == 0) {
                self->values[3] = 1;
                pXPos() &= 0xFFFF0000;
                self->values[1] &= 0xFFFF0000;
            }
        } else {
            self->values[3] = 0;
        }
        break;
        case 2:
        scriptEng.tempValue[2] = 1;
        break;
    }
    PlayerObjectCollision(C_BOX, -16, -32, 80, 0);
    switch (CheckResult()) {
        case 1:
        pXPos() += self->values[2];
        if (pSpeed() == 0) {
            if (self->values[3] == 0) {
                self->values[3] = 1;
                pXPos() &= 0xFFFF0000;
                self->values[1] &= 0xFFFF0000;
            }
        } else {
            self->values[3] = 0;
        }
        break;
        case 2:
        scriptEng.tempValue[2] = 1;
        break;
    }
    PlayerObjectCollision(C_BOX, 16, 0, 80, 32);
    switch (CheckResult()) {
        case 1:
        pXPos() += self->values[2];
        if (pSpeed() == 0) {
            if (self->values[3] == 0) {
                self->values[3] = 1;
                pXPos() &= 0xFFFF0000;
                self->values[1] &= 0xFFFF0000;
            }
        } else {
            self->values[3] = 0;
        }
        break;
        case 2:
        scriptEng.tempValue[2] = 1;
        break;
    }
    PlayerObjectCollision(C_BOX, 48, 32, 80, 64);
    switch (CheckResult()) {
        case 1:
        pXPos() += self->values[2];
        if (pSpeed() == 0) {
            if (self->values[3] == 0) {
                self->values[3] = 1;
                pXPos() &= 0xFFFF0000;
                self->values[1] &= 0xFFFF0000;
            }
        } else {
            self->values[3] = 0;
        }
        break;
        case 2:
        scriptEng.tempValue[2] = 1;
        break;
    }
    self->XPos = scriptEng.tempValue[0];
    if (scriptEng.tempValue[1] == 1) {
        if (scriptEng.tempValue[2] == 1) {
            CallScriptFunctionNamed("Player_Kill", scriptSub);
        }
    }
    if (pGravity() == 1) {
        self->values[3] = 0;
    }
}

void O_R4_CrushBlocks::ObjectDraw()
{
    Entity *self = Self();

    scriptEng.tempValue[0] = self->XPos;
    scriptEng.tempValue[0] -= self->values[1];
    scriptEng.tempValue[1] = self->XPos;
    scriptEng.tempValue[1] += self->values[1];
    scriptEng.tempValue[2] = self->YPos;
    scriptEng.tempValue[2] -= 0x300000;
    DrawSprite_FrameXY(0, scriptEng.tempValue[0], scriptEng.tempValue[2]);
    scriptEng.tempValue[2] += 0x200000;
    DrawSprite_FrameXY(0, scriptEng.tempValue[0], scriptEng.tempValue[2]);
    DrawSprite_FrameXY(1, scriptEng.tempValue[0], scriptEng.tempValue[2]);
    scriptEng.tempValue[2] += 0x200000;
    DrawSprite_FrameXY(0, scriptEng.tempValue[0], scriptEng.tempValue[2]);
    DrawSprite_FrameXY(1, scriptEng.tempValue[0], scriptEng.tempValue[2]);
    DrawSprite_FrameXY(2, scriptEng.tempValue[0], scriptEng.tempValue[2]);
    scriptEng.tempValue[2] += 0x200000;
    DrawSprite_FrameXY(0, scriptEng.tempValue[0], scriptEng.tempValue[2]);
    DrawSprite_FrameXY(1, scriptEng.tempValue[0], scriptEng.tempValue[2]);
    DrawSprite_FrameXY(2, scriptEng.tempValue[0], scriptEng.tempValue[2]);
    DrawSprite_FrameXY(3, scriptEng.tempValue[0], scriptEng.tempValue[2]);
    scriptEng.tempValue[2] -= 0x600000;
    DrawSprite_FrameXY(1, scriptEng.tempValue[1], scriptEng.tempValue[2]);
    DrawSprite_FrameXY(2, scriptEng.tempValue[1], scriptEng.tempValue[2]);
    DrawSprite_FrameXY(3, scriptEng.tempValue[1], scriptEng.tempValue[2]);
    DrawSprite_FrameXY(4, scriptEng.tempValue[1], scriptEng.tempValue[2]);
    scriptEng.tempValue[2] += 0x200000;
    DrawSprite_FrameXY(2, scriptEng.tempValue[1], scriptEng.tempValue[2]);
    DrawSprite_FrameXY(3, scriptEng.tempValue[1], scriptEng.tempValue[2]);
    DrawSprite_FrameXY(4, scriptEng.tempValue[1], scriptEng.tempValue[2]);
    scriptEng.tempValue[2] += 0x200000;
    DrawSprite_FrameXY(3, scriptEng.tempValue[1], scriptEng.tempValue[2]);
    DrawSprite_FrameXY(4, scriptEng.tempValue[1], scriptEng.tempValue[2]);
    scriptEng.tempValue[2] += 0x200000;
    DrawSprite_FrameXY(4, scriptEng.tempValue[1], scriptEng.tempValue[2]);
}

#endif // RETRO_USE_NATIVE_OBJECTS

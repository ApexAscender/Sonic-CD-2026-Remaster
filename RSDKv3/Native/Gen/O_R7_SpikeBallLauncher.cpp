#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R7_SpikeBallLauncher.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from SpikeBallLauncher.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R7_SpikeBallLauncher::ObjectStartup()
{
    LoadSpriteSheet("R7/Objects.gif");
    AddSpriteFrame(-16, -16, 32, 16, 133, 1);
    AddSpriteFrame(-16, 0, 32, 16, 166, 1);
    AddSpriteFrame(-16, -16, 16, 32, 1, 166);
    AddSpriteFrame(0, -16, 16, 32, 17, 166);
    AddSpriteFrame(-16, -16, 32, 32, 1, 199);
}

void O_R7_SpikeBallLauncher::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        self->priority = 1;
        if (self->values[0] < 150) {
            self->values[0]++;
        } else {
            self->values[0] = 0;
            self->values[1] = 0;
            self->state++;
        }
        break;
        case 1:
        if (self->values[0] < 32) {
            self->values[0]++;
            self->values[1] -= 0x8000;
        } else {
            self->values[0] = 0;
            self->state++;
        }
        break;
        case 2:
        if (self->values[0] < 30) {
            self->values[0]++;
        } else {
            self->values[0] = 0;
            self->values[2] = -0x60000;
            self->state++;
        }
        break;
        case 3:
        if (self->values[1] < 0) {
            self->values[2] += 0x4000;
            self->values[1] += self->values[2];
        } else {
            self->state++;
        }
        break;
        case 4:
        if (self->values[0] < 40) {
            self->values[0]++;
        } else {
            self->values[0] = 0;
            self->values[1] = 0;
            self->state = 1;
        }
        break;
    }
    if (GetObjectOutOfBounds(objectLoop) == 1) {
        self->state = 0;
        self->values[0] = 0;
        self->priority = 0;
    }
}

void O_R7_SpikeBallLauncher::ObjectPlayerInteraction()
{
    Entity *self = Self();

    switch (self->state) {
        case 1:
        case 2:
        case 3:
        scriptEng.tempValue[0] = self->XPos;
        scriptEng.tempValue[1] = self->YPos;
        switch (self->propertyValue) {
            case 0:
            self->YPos += self->values[1];
            break;
            case 1:
            self->YPos -= self->values[1];
            break;
            case 2:
            self->XPos += self->values[1];
            break;
            case 3:
            self->XPos -= self->values[1];
            break;
        }
        PlayerObjectCollision(C_TOUCH, -12, -12, 12, 12);
        if (CheckResult() == 1) {
            CallScriptFunctionNamed("Player_Hit", scriptSub);
        }
        self->XPos = scriptEng.tempValue[0];
        self->YPos = scriptEng.tempValue[1];
    }
}

void O_R7_SpikeBallLauncher::ObjectDraw()
{
    Entity *self = Self();

    if (self->drawOrder == 3) {
        switch (self->state) {
            case 1:
            case 2:
            case 3:
            switch (self->propertyValue) {
                case 0:
                scriptEng.tempValue[0] = self->YPos;
                scriptEng.tempValue[0] += self->values[1];
                DrawSprite_FrameXY(4, self->XPos, scriptEng.tempValue[0]);
                break;
                case 1:
                scriptEng.tempValue[0] = self->YPos;
                scriptEng.tempValue[0] -= self->values[1];
                DrawSprite_FrameXY(4, self->XPos, scriptEng.tempValue[0]);
                break;
                case 2:
                scriptEng.tempValue[0] = self->XPos;
                scriptEng.tempValue[0] += self->values[1];
                DrawSprite_FrameXY(4, scriptEng.tempValue[0], self->YPos);
                break;
                case 3:
                scriptEng.tempValue[0] = self->XPos;
                scriptEng.tempValue[0] -= self->values[1];
                DrawSprite_FrameXY(4, scriptEng.tempValue[0], self->YPos);
                break;
            }
        }
        drawListEntries[4].entityRefs[drawListEntries[4].listSize] = objectLoop;
        drawListEntries[4].listSize++;
        self->drawOrder = 4;
    } else {
        DrawSprite_Frame(self->propertyValue);
        self->drawOrder = 3;
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS

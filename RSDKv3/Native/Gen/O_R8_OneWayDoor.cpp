#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R8_OneWayDoor.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from OneWayDoor.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R8_OneWayDoor::ObjectStartup()
{
    LoadSpriteSheet("R8/Objects.gif");
    AddSpriteFrame(-8, -48, 16, 32, 58, 131);
    AddSpriteFrame(-8, -16, 16, 32, 58, 131);
    AddSpriteFrame(-16, -36, 8, 8, 50, 173);
    AddSpriteFrame(-16, -36, 8, 8, 59, 173);
    AddSpriteFrame(-16, -4, 8, 8, 50, 173);
    AddSpriteFrame(-16, -4, 8, 8, 59, 173);
    AddSpriteFrame(8, -36, 8, 8, 50, 164);
    AddSpriteFrame(8, -36, 8, 8, 59, 164);
    AddSpriteFrame(8, -4, 8, 8, 50, 164);
    AddSpriteFrame(8, -4, 8, 8, 59, 164);
}

void O_R8_OneWayDoor::ObjectMain()
{
    Entity *self = Self();

    if (self->state == 0) {
        if (self->values[1] > 0) {
            self->values[1] -= 0x20000;
        }
    } else {
        if (self->values[1] < 0x200000) {
            self->values[1] += 0x20000;
        }
    }
}

void O_R8_OneWayDoor::ObjectPlayerInteraction()
{
    Entity *self = Self();

    scriptEng.tempValue[0] = self->YPos;
    scriptEng.tempValue[1] = pYPos();
    self->YPos -= self->values[1];
    PlayerObjectCollision(C_BOX, -8, -48, 8, -16);
    if (CheckResult() > 1) {
        pYPos() = scriptEng.tempValue[1];
    }
    self->YPos = scriptEng.tempValue[0];
    self->YPos += self->values[1];
    PlayerObjectCollision(C_BOX, -8, -16, 8, 16);
    if (CheckResult() > 1) {
        pYPos() = scriptEng.tempValue[1];
    }
    self->YPos = scriptEng.tempValue[0];
    if (self->propertyValue == 2) {
        PlayerObjectCollision(C_TOUCH, -96, -48, 8, 16);
    } else {
        PlayerObjectCollision(C_TOUCH, -8, -48, 96, 16);
    }
    self->state = CheckResult();
}

void O_R8_OneWayDoor::ObjectDraw()
{
    Entity *self = Self();

    self->frame = self->animationTimer;
    self->frame /= 3;
    switch (self->propertyValue) {
        case 1:
        scriptEng.tempValue[0] = self->values[1];
        scriptEng.tempValue[0] = -scriptEng.tempValue[0];
        scriptEng.tempValue[0] += self->YPos;
        DrawSprite_FrameXY(0, self->XPos, scriptEng.tempValue[0]);
        self->frame += 6;
        DrawSprite_FrameXY(self->frame, self->XPos, scriptEng.tempValue[0]);
        scriptEng.tempValue[0] = self->values[1];
        scriptEng.tempValue[0] += self->YPos;
        DrawSprite_FrameXY(1, self->XPos, scriptEng.tempValue[0]);
        self->frame += 2;
        DrawSprite_FrameXY(self->frame, self->XPos, scriptEng.tempValue[0]);
        break;
        case 2:
        scriptEng.tempValue[0] = self->values[1];
        scriptEng.tempValue[0] = -scriptEng.tempValue[0];
        scriptEng.tempValue[0] += self->YPos;
        DrawSprite_FrameXY(0, self->XPos, scriptEng.tempValue[0]);
        self->frame += 2;
        DrawSprite_FrameXY(self->frame, self->XPos, scriptEng.tempValue[0]);
        scriptEng.tempValue[0] = self->values[1];
        scriptEng.tempValue[0] += self->YPos;
        DrawSprite_FrameXY(1, self->XPos, scriptEng.tempValue[0]);
        self->frame += 2;
        DrawSprite_FrameXY(self->frame, self->XPos, scriptEng.tempValue[0]);
        break;
        case 3:
        scriptEng.tempValue[0] = self->values[1];
        scriptEng.tempValue[0] = -scriptEng.tempValue[0];
        scriptEng.tempValue[0] += self->YPos;
        DrawSprite_FrameXY(0, self->XPos, scriptEng.tempValue[0]);
        scriptEng.tempValue[0] = self->values[1];
        scriptEng.tempValue[0] += self->YPos;
        DrawSprite_FrameXY(1, self->XPos, scriptEng.tempValue[0]);
        break;
    }
    self->animationTimer++;
    self->animationTimer %= 6;
}

#endif // RETRO_USE_NATIVE_OBJECTS

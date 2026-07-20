#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R7_SolidBlock.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from SolidBlock.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R7_SolidBlock::ObjectStartup()
{
    LoadSpriteSheet("R7/Objects.gif");
    switch (objectEntityList[24].propertyValue) {
        case 0:
        case 1:
        case 3:
        AddSpriteFrame(-16, -16, 32, 32, 1, 1);
        break;
        case 2:
        AddSpriteFrame(-16, -16, 32, 32, 117, 219);
        break;
    }
}

void O_R7_SolidBlock::ObjectPlayerInteraction()
{
    Entity *self = Self();

    scriptEng.tempValue[0] = pYPos();
    switch (self->propertyValue) {
        case 0:
        case 7:
        PlayerObjectCollision(C_BOX, -16, -16, 16, 16);
        break;
        case 1:
        PlayerObjectCollision(C_BOX, -32, -16, 32, 16);
        break;
        case 2:
        PlayerObjectCollision(C_BOX, -48, -16, 48, 16);
        break;
        case 3:
        PlayerObjectCollision(C_BOX, -64, -16, 64, 16);
        break;
        case 4:
        PlayerObjectCollision(C_BOX, -16, -32, 16, 32);
        break;
        case 5:
        PlayerObjectCollision(C_BOX, -16, -48, 16, 48);
        break;
        case 6:
        PlayerObjectCollision(C_BOX, -16, -64, 16, 64);
        break;
    }
    if (CheckResult() == 2) {
        GVar("Player.RCollisionFlag") = 1;
    }
    if (pGravity() == 0) {
        if (CheckResult() == 4) {
            pYPos() = scriptEng.tempValue[0];
        }
    }
}

void O_R7_SolidBlock::ObjectDraw()
{
    Entity *self = Self();

    switch (self->propertyValue) {
        case 0:
        DrawSprite_Frame(0);
        break;
        case 1:
        scriptEng.tempValue[0] = self->XPos;
        scriptEng.tempValue[0] -= 0x100000;
        DrawSprite_FrameXY(0, scriptEng.tempValue[0], self->YPos);
        scriptEng.tempValue[0] += 0x200000;
        DrawSprite_FrameXY(0, scriptEng.tempValue[0], self->YPos);
        break;
        case 2:
        scriptEng.tempValue[0] = self->XPos;
        scriptEng.tempValue[0] -= 0x200000;
        DrawSprite_FrameXY(0, scriptEng.tempValue[0], self->YPos);
        scriptEng.tempValue[0] += 0x200000;
        DrawSprite_FrameXY(0, scriptEng.tempValue[0], self->YPos);
        scriptEng.tempValue[0] += 0x200000;
        DrawSprite_FrameXY(0, scriptEng.tempValue[0], self->YPos);
        break;
        case 3:
        scriptEng.tempValue[0] = self->XPos;
        scriptEng.tempValue[0] -= 0x300000;
        DrawSprite_FrameXY(0, scriptEng.tempValue[0], self->YPos);
        scriptEng.tempValue[0] += 0x200000;
        DrawSprite_FrameXY(0, scriptEng.tempValue[0], self->YPos);
        scriptEng.tempValue[0] += 0x200000;
        DrawSprite_FrameXY(0, scriptEng.tempValue[0], self->YPos);
        scriptEng.tempValue[0] += 0x200000;
        DrawSprite_FrameXY(0, scriptEng.tempValue[0], self->YPos);
        break;
        case 4:
        scriptEng.tempValue[0] = self->YPos;
        scriptEng.tempValue[0] -= 0x100000;
        DrawSprite_FrameXY(0, self->XPos, scriptEng.tempValue[0]);
        scriptEng.tempValue[0] += 0x200000;
        DrawSprite_FrameXY(0, self->XPos, scriptEng.tempValue[0]);
        break;
        case 5:
        scriptEng.tempValue[0] = self->YPos;
        scriptEng.tempValue[0] -= 0x200000;
        DrawSprite_FrameXY(0, self->XPos, scriptEng.tempValue[0]);
        scriptEng.tempValue[0] += 0x200000;
        DrawSprite_FrameXY(0, self->XPos, scriptEng.tempValue[0]);
        scriptEng.tempValue[0] += 0x200000;
        DrawSprite_FrameXY(0, self->XPos, scriptEng.tempValue[0]);
        break;
        case 6:
        scriptEng.tempValue[0] = self->YPos;
        scriptEng.tempValue[0] -= 0x300000;
        DrawSprite_FrameXY(0, self->XPos, scriptEng.tempValue[0]);
        scriptEng.tempValue[0] += 0x200000;
        DrawSprite_FrameXY(0, self->XPos, scriptEng.tempValue[0]);
        scriptEng.tempValue[0] += 0x200000;
        DrawSprite_FrameXY(0, self->XPos, scriptEng.tempValue[0]);
        scriptEng.tempValue[0] += 0x200000;
        DrawSprite_FrameXY(0, self->XPos, scriptEng.tempValue[0]);
        break;
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS

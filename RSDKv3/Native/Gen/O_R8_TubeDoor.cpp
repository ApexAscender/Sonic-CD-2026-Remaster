#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R8_TubeDoor.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from TubeDoor.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R8_TubeDoor::ObjectStartup()
{
    LoadSpriteSheet("R8/Objects2.gif");
    AddSpriteFrame(-8, -4, 16, 8, 19, 75);
    AddSpriteFrame(40, -4, 16, 8, 133, 26);
    AddSpriteFrame(8, -4, 16, 8, 100, 26);
    AddSpriteFrame(24, -4, 16, 8, 116, 26);
}

void O_R8_TubeDoor::ObjectMain()
{
    Entity *self = Self();

    if (GetObjectOutOfBounds(objectLoop) == 1) {
        self->state = 0;
        self->values[1] = 0;
        self->priority = 0;
    }
    switch (self->state) {
        case 0:
        self->priority = 1;
        if (objectEntityList[objectLoop - 1].propertyValue == 1) {
            if (self->propertyValue == 0) {
                self->state = 1;
            }
        } else {
            if (pState() == PlayerStateID("Player_State_Static")) {
                if (pAnimation() == GVar("ANI_JUMPING")) {
                    self->state = 3;
                    self->values[1] = 0x100000;
                }
            }
        }
        break;
        case 1:
        if (self->values[1] < 0x100000) {
            self->values[1] += 0x20000;
        }
        if (pState() == PlayerStateID("Player_State_Static")) {
            if (pAnimation() == GVar("ANI_JUMPING")) {
                if (pYPos() > self->YPos) {
                    self->state = 3;
                }
            }
        }
        break;
        case 2:
        if (self->values[1] > 0) {
            self->values[1] -= 0x20000;
        } else {
            self->state = 0;
        }
        break;
        case 3:
        scriptEng.tempValue[0] = self->YPos;
        scriptEng.tempValue[0] -= pYPos();
        if (scriptEng.tempValue[0] > 0x100000) {
            self->state = 2;
        }
        break;
    }
}

void O_R8_TubeDoor::ObjectPlayerInteraction()
{
    Entity *self = Self();

    if (self->state == 0) {
        PlayerObjectCollision(C_PLATFORM, -8, -4, 56, 32);
    } else {
        PlayerObjectCollision(C_PLATFORM, -8, -4, 4, 32);
        PlayerObjectCollision(C_PLATFORM, 44, -4, 56, 32);
    }
}

void O_R8_TubeDoor::ObjectDraw()
{
    Entity *self = Self();

    scriptEng.tempValue[0] = self->values[1];
    scriptEng.tempValue[0] = -scriptEng.tempValue[0];
    scriptEng.tempValue[0] += self->XPos;
    DrawSprite_FrameXY(2, scriptEng.tempValue[0], self->YPos);
    scriptEng.tempValue[0] = self->values[1];
    scriptEng.tempValue[0] += self->XPos;
    DrawSprite_FrameXY(3, scriptEng.tempValue[0], self->YPos);
    DrawSprite_Frame(0);
    DrawSprite_Frame(1);
}

#endif // RETRO_USE_NATIVE_OBJECTS

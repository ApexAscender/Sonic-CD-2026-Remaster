#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R4_BossBullet.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from BossBullet.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R4_BossBullet::ObjectStartup()
{
    LoadSpriteSheet("R4/Objects2.gif");
    AddSpriteFrame(-4, -4, 8, 8, 52, 35);
    AddSpriteFrame(-4, -4, 8, 8, 52, 44);
}

void O_R4_BossBullet::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        if (self->values[0] < 56) {
            self->values[0]++;
        } else {
            switch (self->propertyValue) {
                case 0:
                self->values[1] = -0x14000;
                self->values[2] = 0x14000;
                break;
                case 1:
                self->values[1] = 0;
                self->values[2] = 0x1C000;
                break;
                case 2:
                self->values[1] = 0x10000;
                self->values[2] = 0x18000;
                break;
                case 3:
                self->values[1] = 0x14000;
                self->values[2] = 0x14000;
                break;
                case 4:
                self->values[1] = 0x14000;
                self->values[2] = 0x14000;
                break;
                case 5:
                self->values[1] = 0;
                self->values[2] = 0x1C000;
                break;
                case 6:
                self->values[1] = -0x10000;
                self->values[2] = 0x18000;
                break;
                case 7:
                self->values[1] = -0x14000;
                self->values[2] = 0x14000;
                break;
            }
            self->values[0] = 0;
            self->state++;
        }
        scriptEng.arrayPosition[0] = self->values[5];
        self->XPos = objectEntityList[scriptEng.arrayPosition[0]].XPos;
        self->YPos = objectEntityList[scriptEng.arrayPosition[0]].YPos;
        switch (self->propertyValue) {
            case 0:
            self->XPos -= 0x1D0000;
            self->YPos += 0x170000;
            break;
            case 1:
            self->XPos -= 0x60000;
            self->YPos += 0x200000;
            break;
            case 2:
            self->XPos += 0x110000;
            self->YPos += 0x1D0000;
            break;
            case 3:
            self->XPos += 0x1D0000;
            self->YPos += 0x110000;
            break;
            case 4:
            self->XPos += 0x1D0000;
            self->YPos += 0x170000;
            break;
            case 5:
            self->XPos += 0x60000;
            self->YPos += 0x200000;
            break;
            case 6:
            self->XPos -= 0x110000;
            self->YPos += 0x1D0000;
            break;
            case 7:
            self->XPos -= 0x1D0000;
            self->YPos += 0x110000;
            break;
        }
        break;
        case 1:
        self->XPos += self->values[1];
        self->YPos += self->values[2];
        if (self->values[0] < 60) {
            self->values[0]++;
        } else {
            self->values[0] = 0;
            self->drawOrder = 3;
            self->state++;
        }
        break;
        case 2:
        self->XPos += self->values[1];
        self->YPos += self->values[2];
        break;
    }
    if (GetObjectOutOfBounds(objectLoop) == 1) {
        self->type = TypeNameID("Blank Object");
    }
    scriptEng.arrayPosition[0] = self->values[5];
    if (objectEntityList[scriptEng.arrayPosition[0]].state > 13) {
        self->type = TypeNameID("Blank Object");
    }
}

void O_R4_BossBullet::ObjectPlayerInteraction()
{
    Entity *self = Self();

    if (self->state > 0) {
        PlayerObjectCollision(C_TOUCH, -4, -4, 4, 4);
        if (CheckResult() == 1) {
            CallScriptFunctionNamed("Player_Hit", scriptSub);
            if (pState() == PlayerStateID("Player_State_GotHit")) {
                scriptEng.arrayPosition[0] = self->values[5];
                objectEntityList[scriptEng.arrayPosition[0]].values[7] = 1;
            }
        }
    }
}

void O_R4_BossBullet::ObjectDraw()
{
    Entity *self = Self();

    scriptEng.tempValue[0] = self->frame;
    scriptEng.tempValue[0] >>= 1;
    DrawSprite_Frame(scriptEng.tempValue[0]);
    self->frame++;
    self->frame &= 3;
}

#endif // RETRO_USE_NATIVE_OBJECTS

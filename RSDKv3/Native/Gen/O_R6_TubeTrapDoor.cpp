#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R6_TubeTrapDoor.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from TubeTrapDoor.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R6_TubeTrapDoor::ObjectStartup()
{
    LoadSpriteSheet("R6/Objects.gif");
    AddSpriteFrame(-32, -40, 64, 80, 191, 175);
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Tube Trap Door")) {
            objectEntityList[scriptEng.arrayPosition[0]].drawOrder = 4;
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_R6_TubeTrapDoor::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        if (self->values[0] < 8) {
            self->values[0]++;
            self->YPos -= 0xA0000;
        } else {
            self->values[0] = 0;
            self->state++;
            HapticEffect_Script(100, 0, 0, 0);
        }
        break;
        case 1:
        if (self->values[0] < 60) {
            self->values[0]++;
        } else {
            self->values[0] = 0;
            self->state++;
        }
        break;
        case 2:
        if (self->values[0] < 80) {
            self->values[0]++;
            self->YPos += 0x10000;
        } else {
            self->values[0] = 0;
            self->state++;
        }
        break;
        case 3:
        if (self->values[0] < 60) {
            self->values[0]++;
        } else {
            self->values[0] = 0;
            self->state = 0;
        }
        break;
    }
}

void O_R6_TubeTrapDoor::ObjectPlayerInteraction()
{
    Entity *self = Self();

    PlayerObjectCollision(C_TOUCH, -33, -40, 33, 20);
    if (CheckResult() == 1) {
        if (pXPos() < self->XPos) {
            scriptEng.tempValue[0] = self->XPos;
            scriptEng.tempValue[0] -= pXPos();
            scriptEng.tempValue[1] = 0x240000;
            scriptEng.tempValue[1] -= pXVel();
            if (scriptEng.tempValue[0] > scriptEng.tempValue[1]) {
                if (pSpeed() > -1) {
                    pXPos() = -32;
                    pXPos() -= pCollisionRight();
                    pXPos() <<= 16;
                    pXPos() += self->XPos;
                }
                if (pSpeed() > 0) {
                    if (pDirection() == 0) {
                        pPushing() = 2;
                    }
                    pSpeed() = 0;
                    pXVel() = 0;
                }
            } else {
                if (self->state < 2) {
                    if (scriptEng.tempValue[0] > 0x180000) {
                        pXPos() += 0x140000;
                        pSpeed() = 0;
                        pXVel() = 0;
                    }
                }
            }
        } else {
            scriptEng.tempValue[0] = pXPos();
            scriptEng.tempValue[0] -= self->XPos;
            scriptEng.tempValue[1] = 0x240000;
            scriptEng.tempValue[1] += pXVel();
            if (scriptEng.tempValue[0] > scriptEng.tempValue[1]) {
                if (pSpeed() < 1) {
                    pXPos() = 32;
                    pXPos() -= pCollisionLeft();
                    pXPos() <<= 16;
                    pXPos() += self->XPos;
                }
                if (pSpeed() < 0) {
                    if (pDirection() == 1) {
                        pPushing() = 2;
                    }
                    pSpeed() = 0;
                    pXVel() = 0;
                }
            } else {
                if (self->state < 2) {
                    if (scriptEng.tempValue[0] > 0x180000) {
                        pXPos() -= 0x140000;
                        pSpeed() = 0;
                        pXVel() = 0;
                    }
                }
            }
        }
    }
    switch (self->state) {
        case 0:
        if (self->values[0] < 4) {
            PlayerObjectCollision(C_PLATFORM, -30, -40, 30, -20);
        } else {
            PlayerObjectCollision(C_TOUCH, -16, -40, 16, 20);
            if (CheckResult() == 1) {
                pSpeed() >>= 1;
                pXVel() >>= 1;
                PlayerObjectCollision(C_BOX, -48, -80, -32, 20);
                PlayerObjectCollision(C_BOX, 32, -80, 48, 20);
                if (pState() == PlayerStateID("Player_State_Fly")) {
                    pState() = PlayerStateID("Player_State_Air");
                    pAnimation() = GVar("ANI_WALKING");
                }
            }
        }
        break;
        case 2:
        PlayerObjectCollision(C_PLATFORM, -30, -41, 30, -20);
        if (CheckResult() == 1) {
            pYPos() += 0x10000;
        }
        break;
        case 3:
        PlayerObjectCollision(C_PLATFORM, -30, -40, 30, -20);
        break;
    }
}

void O_R6_TubeTrapDoor::ObjectDraw()
{
    DrawSprite_Frame(0);
}

#endif // RETRO_USE_NATIVE_OBJECTS

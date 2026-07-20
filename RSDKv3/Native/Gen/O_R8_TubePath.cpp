#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R8_TubePath.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from TubePath.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R8_TubePath::ObjectPlayerInteraction()
{
    Entity *self = Self();

    PlayerObjectCollision(C_TOUCH, -4, -4, 4, 4);
    if (CheckResult() == 1) {
        switch (self->propertyValue) {
            case 0:
            if (self->values[0] == 0) {
                pXPos() = self->XPos;
                pYPos() = self->YPos;
                pXVel() = 0;
                pYVel() = 0;
            }
            if (pXVel() == 0) {
                if (pYVel() == 0) {
                    if (pUp() == 1) {
                        pXVel() = 0;
                        pYVel() = -0x100000;
                        PlaySfx(7, 0);
                    }
                    if (pDown() == 1) {
                        pXVel() = 0;
                        pYVel() = 0x100000;
                        PlaySfx(7, 0);
                    }
                    if (pLeft() == 1) {
                        pXVel() = -0x100000;
                        pYVel() = 0;
                        PlaySfx(7, 0);
                    }
                    if (pRight() == 1) {
                        pXVel() = 0x100000;
                        pYVel() = 0;
                        PlaySfx(7, 0);
                    }
                }
            }
            break;
            case 1:
            if (self->values[0] == 0) {
                pAnimationSpeed() = 240;
                if (pYVel() > 0) {
                    pXPos() = self->XPos;
                    pYPos() = self->YPos;
                    pTimer() = 0;
                    pState() = PlayerStateID("Player_State_Static");
                    pAnimation() = GVar("ANI_JUMPING");
                    pSpeed() = 0;
                    pTileCollisions() = 0;
                    pCollisionPlane() = 1;
                    pXVel() = 0;
                    pYVel() = 0x100000;
                    PlaySfx(7, 0);
                } else {
                    pState() = PlayerStateID("Player_State_Air");
                    pTileCollisions() = 1;
                    pCollisionPlane() = 0;
                    pYVel() = -0x80000;
                }
            }
            break;
            case 2:
            if (self->values[0] == 0) {
                pAnimationSpeed() = 240;
                pXPos() = self->XPos;
                pYPos() = self->YPos;
                if (pYVel() > 0) {
                    pXVel() = 0x100000;
                    pYVel() = 0;
                } else {
                    pXVel() = 0;
                    pYVel() = -0x100000;
                }
            }
            break;
            case 3:
            if (self->values[0] == 0) {
                pAnimationSpeed() = 240;
                pXPos() = self->XPos;
                pYPos() = self->YPos;
                if (pYVel() < 0) {
                    pXVel() = -0x100000;
                    pYVel() = 0;
                } else {
                    pXVel() = 0;
                    pYVel() = 0x100000;
                }
            }
            break;
            case 4:
            if (self->values[0] == 0) {
                pAnimationSpeed() = 240;
                pXPos() = self->XPos;
                pYPos() = self->YPos;
                if (pYVel() > 0) {
                    pXVel() = -0x100000;
                    pYVel() = 0;
                } else {
                    pXVel() = 0;
                    pYVel() = -0x100000;
                }
            }
            break;
            case 5:
            if (self->values[0] == 0) {
                pAnimationSpeed() = 240;
                pXPos() = self->XPos;
                pYPos() = self->YPos;
                if (pYVel() < 0) {
                    pXVel() = 0x100000;
                    pYVel() = 0;
                } else {
                    pXVel() = 0;
                    pYVel() = 0x100000;
                }
            }
            break;
            case 6:
            if (self->values[0] == 0) {
                if (pState() == PlayerStateID("Player_State_Static")) {
                    pAnimationSpeed() = 240;
                    pXPos() = self->XPos;
                    pYPos() = self->YPos;
                    if (pXVel() > 0) {
                        pXVel() = 0xC0000;
                        pYVel() = 0xC0000;
                    } else {
                        pXVel() = -0x100000;
                        pYVel() = 0;
                    }
                }
            }
            break;
            case 7:
            if (self->values[0] == 0) {
                if (pState() == PlayerStateID("Player_State_Static")) {
                    pAnimationSpeed() = 240;
                    pXPos() = self->XPos;
                    pYPos() = self->YPos;
                    if (pXVel() > 0) {
                        pXVel() = 0x100000;
                        pYVel() = 0;
                    } else {
                        pXVel() = -0xC0000;
                        pYVel() = -0xC0000;
                    }
                }
            }
            break;
            case 8:
            if (self->values[0] == 0) {
                if (pState() == PlayerStateID("Player_State_Static")) {
                    pAnimationSpeed() = 240;
                    pXPos() = self->XPos;
                    pYPos() = self->YPos;
                    if (pXVel() > 0) {
                        pXVel() = 0xC0000;
                        pYVel() = -0xC0000;
                    } else {
                        pXVel() = -0x100000;
                        pYVel() = 0;
                    }
                }
            }
            break;
            case 9:
            if (self->values[0] == 0) {
                if (pState() == PlayerStateID("Player_State_Static")) {
                    pAnimationSpeed() = 240;
                    pXPos() = self->XPos;
                    pYPos() = self->YPos;
                    if (pXVel() > 0) {
                        pXVel() = 0x100000;
                        pYVel() = 0;
                    } else {
                        pXVel() = -0xC0000;
                        pYVel() = 0xC0000;
                    }
                }
            }
            break;
            case 10:
            if (pGravity() == 0) {
                pGravity() = 1;
                pAnimation() = GVar("ANI_JUMPING");
            }
            break;
            case 11:
            if (self->values[0] == 0) {
                if (pState() == PlayerStateID("Player_State_Static")) {
                    pAnimationSpeed() = 240;
                    pXPos() = self->XPos;
                    pYPos() = self->YPos;
                    if (pXVel() > 0) {
                        pXVel() = 0xC0000;
                        pYVel() = -0xC0000;
                    } else {
                        pXVel() = -0xC0000;
                        pYVel() = -0xC0000;
                    }
                }
            }
            break;
            case 12:
            if (self->values[0] == 0) {
                if (pState() == PlayerStateID("Player_State_Static")) {
                    pAnimationSpeed() = 240;
                    pXPos() = self->XPos;
                    pYPos() = self->YPos;
                    if (pXVel() > 0) {
                        pXVel() = 0xC0000;
                        pYVel() = 0xC0000;
                    } else {
                        pXVel() = -0xC0000;
                        pYVel() = 0xC0000;
                    }
                }
            }
            break;
        }
        self->values[0] = 1;
    } else {
        self->values[0] = 0;
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS

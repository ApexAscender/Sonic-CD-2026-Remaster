#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R6_R6BossCSetup.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from R6BossCSetup.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R6_R6BossCSetup::ObjectStartup()
{
    objectEntityList[19].type = TypeNameID("R6 Setup");
    objectEntityList[19].priority = 1;
    objectEntityList[19].drawOrder = 2;
    scriptEng.tempValue[0] = 1;
    while (scriptEng.tempValue[0] < 3) {
        RotatePalette(161, 163, 0);
        CopyPalette(0, scriptEng.tempValue[0]);
        scriptEng.tempValue[0]++;
    }
    RotatePalette(161, 163, 0);
}

void O_R6_R6BossCSetup::ObjectMain()
{
    Entity *self = Self();

    scriptEng.tempValue[0] = self->values[4];
    scriptEng.tempValue[0] &= 1;
    if (scriptEng.tempValue[0] == 0) {
        scriptEng.tempValue[0] = self->values[4];
        scriptEng.tempValue[0] >>= 1;
        scriptEng.tempValue[0] += 808;
        Copy16x16Tile(579, scriptEng.tempValue[0]);
    }
    self->values[4]++;
    self->values[4] %= 24;
    scriptEng.tempValue[0] = self->values[5];
    scriptEng.tempValue[0] %= 5;
    if (scriptEng.tempValue[0] == 0) {
        scriptEng.tempValue[0] = self->values[5];
        scriptEng.tempValue[0] /= 5;
        scriptEng.tempValue[0] += 820;
        Copy16x16Tile(580, scriptEng.tempValue[0]);
        scriptEng.tempValue[0] += 3;
        Copy16x16Tile(581, scriptEng.tempValue[0]);
    }
    self->values[5]++;
    self->values[5] %= 15;
    scriptEng.tempValue[0] = self->values[6];
    scriptEng.tempValue[0] &= 1;
    if (scriptEng.tempValue[0] == 0) {
        scriptEng.tempValue[0] = self->values[7];
        scriptEng.tempValue[0] += 826;
        self->values[7]++;
        self->values[7] %= 6;
        Copy16x16Tile(543, scriptEng.tempValue[0]);
    }
    self->values[6]++;
    self->values[6] &= 511;
    self->scale = 1;
    scriptEng.tempValue[0] = self->values[1];
    scriptEng.tempValue[0] >>= 1;
    SetActivePalette(scriptEng.tempValue[0], 0, SCREEN_YSIZE);
    self->values[1]++;
    self->values[1] %= 6;
}

void O_R6_R6BossCSetup::ObjectPlayerInteraction()
{
    Entity *self = Self();

    scriptEng.tempValue[2] = pXPos();
    scriptEng.tempValue[2] >>= 16;
    scriptEng.tempValue[2] += pCollisionRight();
    scriptEng.tempValue[3] = pYPos();
    scriptEng.tempValue[3] >>= 16;
    scriptEng.tempValue[3] += pCollisionBottom();
    scriptEng.tempValue[3] += 2;
    scriptEng.tempValue[0] = Get16x16TileInfo_Script(scriptEng.tempValue[2], scriptEng.tempValue[3], 8);
    scriptEng.tempValue[2] = pXPos();
    scriptEng.tempValue[2] >>= 16;
    scriptEng.tempValue[2] += pCollisionLeft();
    scriptEng.tempValue[1] = Get16x16TileInfo_Script(scriptEng.tempValue[2], scriptEng.tempValue[3], 8);
    scriptEng.tempValue[0] |= scriptEng.tempValue[1];
    if (scriptEng.tempValue[0] == 1) {
        if (self->scale == 1) {
            if (pYVel() > -1) {
                pAnimation() = GVar("ANI_JUMPING");
                pGravity() = 1;
                pTimer() = 0;
                pYVel() = -0x160000;
                pState() = PlayerStateID("Player_State_Air");
                PlaySfx(globalSFXCount + 0, 0);
                HapticEffect_Script(60, 0, 0, 0);
            }
        }
    }
    scriptEng.tempValue[2] -= pCollisionLeft();
    scriptEng.tempValue[3] -= pCollisionBottom();
    scriptEng.tempValue[3] -= 2;
    scriptEng.tempValue[0] = Get16x16TileInfo_Script(scriptEng.tempValue[2], scriptEng.tempValue[3], 8);
    switch (scriptEng.tempValue[0]) {
        case 2:
        if (PlayerValue(4) == 0) {
            pState() = PlayerStateID("Player_State_GotHit");
            if (pDirection() == 1) {
                pSpeed() = 0x20000;
            } else {
                pSpeed() = -0x20000;
            }
        }
        break;
        case 5:
        if (self->state == 2) {
            if (PlayerValue(4) == 0) {
                pState() = PlayerStateID("Player_State_GotHit");
                if (pDirection() == 1) {
                    pSpeed() = 0x20000;
                } else {
                    pSpeed() = -0x20000;
                }
            }
        }
        break;
        case 6:
        if (self->state == 2) {
            if (self->direction == 0) {
                if (PlayerValue(4) == 0) {
                    pState() = PlayerStateID("Player_State_GotHit");
                    if (pDirection() == 1) {
                        pSpeed() = 0x20000;
                    } else {
                        pSpeed() = -0x20000;
                    }
                }
            }
        }
        break;
        case 7:
        if (self->state == 2) {
            if (self->direction == 1) {
                if (PlayerValue(4) == 0) {
                    pState() = PlayerStateID("Player_State_GotHit");
                    if (pDirection() == 1) {
                        pSpeed() = 0x20000;
                    } else {
                        pSpeed() = -0x20000;
                    }
                }
            }
        }
        break;
        case 8:
        if (self->state == 2) {
            if (self->direction == 2) {
                if (PlayerValue(4) == 0) {
                    pState() = PlayerStateID("Player_State_GotHit");
                    if (pDirection() == 1) {
                        pSpeed() = 0x20000;
                    } else {
                        pSpeed() = -0x20000;
                    }
                }
            }
        }
        break;
    }
    scriptEng.tempValue[3] -= 4;
    scriptEng.tempValue[0] = Get16x16TileInfo_Script(scriptEng.tempValue[2], scriptEng.tempValue[3], 8);
    switch (scriptEng.tempValue[0]) {
        case 2:
        if (PlayerValue(4) == 0) {
            pState() = PlayerStateID("Player_State_GotHit");
            if (pDirection() == 1) {
                pSpeed() = 0x20000;
            } else {
                pSpeed() = -0x20000;
            }
        }
        break;
        case 5:
        if (self->state == 2) {
            if (PlayerValue(4) == 0) {
                pState() = PlayerStateID("Player_State_GotHit");
                if (pDirection() == 1) {
                    pSpeed() = 0x20000;
                } else {
                    pSpeed() = -0x20000;
                }
            }
        }
        break;
        case 6:
        if (self->state == 2) {
            if (self->direction == 0) {
                if (PlayerValue(4) == 0) {
                    pState() = PlayerStateID("Player_State_GotHit");
                    if (pDirection() == 1) {
                        pSpeed() = 0x20000;
                    } else {
                        pSpeed() = -0x20000;
                    }
                }
            }
        }
        break;
        case 7:
        if (self->state == 2) {
            if (self->direction == 1) {
                if (PlayerValue(4) == 0) {
                    pState() = PlayerStateID("Player_State_GotHit");
                    if (pDirection() == 1) {
                        pSpeed() = 0x20000;
                    } else {
                        pSpeed() = -0x20000;
                    }
                }
            }
        }
        break;
        case 8:
        if (self->state == 2) {
            if (self->direction == 2) {
                if (PlayerValue(4) == 0) {
                    pState() = PlayerStateID("Player_State_GotHit");
                    if (pDirection() == 1) {
                        pSpeed() = 0x20000;
                    } else {
                        pSpeed() = -0x20000;
                    }
                }
            }
        }
        break;
    }
    scriptEng.tempValue[3] += 4;
    scriptEng.tempValue[3] += pCollisionTop();
    scriptEng.tempValue[0] = Get16x16TileInfo_Script(scriptEng.tempValue[2], scriptEng.tempValue[3], 8);
    if (scriptEng.tempValue[0] == 3) {
        scriptEng.tempValue[4] = scriptEng.tempValue[3];
        scriptEng.tempValue[4] &= 15;
        if (scriptEng.tempValue[4] < 8) {
            if (pState() != PlayerStateID("Player_State_HangBar")) {
                pState() = PlayerStateID("Player_State_HangBar");
                pYVel() = 0;
                pAnimation() = GVar("ANI_HANGING");
                scriptEng.tempValue[3] &= 0x7FF0;
                scriptEng.tempValue[3] += 4;
                scriptEng.tempValue[3] -= pCollisionTop();
                pYPos() = (scriptEng.tempValue[3]) << 16;
                PlaySfx(globalSFXCount + 2, 0);
                cameraAdjustY = 0;
            }
        }
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS

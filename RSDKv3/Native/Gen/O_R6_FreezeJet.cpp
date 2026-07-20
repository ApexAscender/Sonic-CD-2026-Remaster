#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R6_FreezeJet.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from FreezeJet.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R6_FreezeJet::ObjectStartup()
{
    LoadSpriteSheet("R6/Objects.gif");
    AddSpriteFrame(-32, -8, 64, 16, 1, 1);
    AddSpriteFrame(-16, 0, 32, 36, 1, 46);
    AddSpriteFrame(-16, 0, 0, 0, 1, 46);
    AddSpriteFrame(-16, 0, 0, 0, 1, 46);
    AddSpriteFrame(-16, 0, 32, 60, 1, 22);
    AddSpriteFrame(-16, 0, 0, 0, 1, 46);
    AddSpriteFrame(-16, 4, 32, 64, 1, 18);
    AddSpriteFrame(-16, 0, 0, 0, 1, 46);
    AddSpriteFrame(-16, 0, 0, 0, 1, 46);
    AddSpriteFrame(-16, 0, 32, 60, 1, 22);
    AddSpriteFrame(-16, 0, 0, 0, 1, 46);
    AddSpriteFrame(-16, 0, 0, 0, 1, 46);
    AddSpriteFrame(-16, 4, 32, 64, 1, 18);
}

void O_R6_FreezeJet::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        if (self->values[0] < 120) {
            self->values[0]++;
            self->frame = 2;
        } else {
            self->values[0] = 0;
            self->state++;
            self->frame = 1;
        }
        break;
        case 1:
        if (self->values[0] < 160) {
            scriptEng.tempValue[0] = self->values[0];
            scriptEng.tempValue[0] &= 1;
            if (scriptEng.tempValue[0] == 0) {
                self->frame++;
            }
            if (self->frame > 6) {
                self->frame = 3;
                self->direction++;
                self->direction &= 1;
            }
            self->values[0]++;
        } else {
            self->values[0] = 0;
            self->state++;
            self->frame = 7;
        }
        break;
        case 2:
        if (self->values[0] < 24) {
            scriptEng.tempValue[0] = self->values[0];
            scriptEng.tempValue[0] &= 3;
            if (scriptEng.tempValue[0] == 0) {
                self->frame++;
            }
            if (self->frame > 12) {
                self->frame = 7;
                self->direction++;
                self->direction &= 1;
            }
            self->values[0]++;
        } else {
            self->values[0] = 0;
            self->values[1] = 7;
            self->state++;
        }
        break;
        case 3:
        if (self->values[0] < 120) {
            scriptEng.tempValue[0] = self->values[0];
            scriptEng.tempValue[0] &= self->values[1];
            if (scriptEng.tempValue[0] == 0) {
                self->frame++;
                self->values[1]++;
                self->values[1] <<= 1;
                self->values[1]--;
            }
            if (self->frame > 12) {
                self->frame = 7;
                self->direction++;
                self->direction &= 1;
            }
            self->values[0]++;
        } else {
            self->values[0] = 0;
            self->state = 1;
            self->frame = 1;
        }
        break;
    }
}

void O_R6_FreezeJet::ObjectPlayerInteraction()
{
    Entity *self = Self();

    if (self->state == 1) {
        PlayerObjectCollision(C_TOUCH, -16, 0, 16, 60);
        if (CheckResult() == 1) {
            if (PlayerValue(4) == 0) {
                if (GVar("Warp.Destination") > 0) {
                    if (GVar("Warp.Timer") > 99) {
                        if (GVar("Warp.Timer") < 220) {
                            GVar("Warp.Destination") = 0;
                        }
                    }
                    GVar("Warp.Timer") = 0;
                }
                pState() = PlayerStateID("Player_State_Static");
                pVisible() = 0;
                pObjectInteractions() = 0;
                pSpeed() = 0;
                pXVel() = 0;
                pYVel() = 0;
                CreateTempObject(TypeNameID("Ice Block"), 0, pXPos(), pYPos());
                objectEntityList[scriptEng.arrayPosition[2]].drawOrder = 4;
            }
        }
    }
}

void O_R6_FreezeJet::ObjectDraw()
{
    Entity *self = Self();

    DrawSpriteFX_Script(self->frame, FX_FLIP, self->XPos, self->YPos);
    DrawSprite_Frame(0);
}

#endif // RETRO_USE_NATIVE_OBJECTS

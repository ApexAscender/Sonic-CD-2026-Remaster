#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_LoseRing.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from LoseRing.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_LoseRing::ObjectStartup()
{
    LoadSpriteSheet("Global/Items.gif");
    AddSpriteFrame(-8, -8, 16, 16, 1, 1);
    AddSpriteFrame(-8, -8, 16, 16, 1, 18);
    AddSpriteFrame(-8, -8, 16, 16, 1, 35);
    AddSpriteFrame(-8, -8, 16, 16, 1, 52);
    AddSpriteFrame(-8, -8, 16, 16, 1, 69);
    AddSpriteFrame(-8, -8, 16, 16, 1, 86);
    AddSpriteFrame(-8, -8, 16, 16, 1, 103);
    AddSpriteFrame(-8, -8, 16, 16, 1, 120);
}

void O_LoseRing::ObjectMain()
{
    Entity *self = Self();

    self->values[1] += 0x1800;
    self->XPos += self->values[0];
    self->YPos += self->values[1];
    if (self->values[1] >= 0) {
        ObjectTileCollision_Script(0, 0, 8, 0);
        if (CheckResult() == 1) {
            scriptEng.tempValue[0] = self->values[1];
            scriptEng.tempValue[0] >>= 2;
            self->values[1] -= scriptEng.tempValue[0];
            self->values[1] = -self->values[1];
            if (self->values[1] > -0x10000) {
                self->values[1] = -0x10000;
            }
        }
    }
    self->values[2]++;
    if (self->values[2] == 256) {
        self->type = TypeNameID("Blank Object");
        self->values[0] = 0;
        self->values[1] = 0;
        self->values[2] = 0;
    } else {
        self->animationTimer += self->animationSpeed;
        if (self->animationTimer > 255) {
            self->animationTimer -= 256;
            self->frame++;
            if (self->frame == 8) {
                self->frame = 0;
                if (self->animationSpeed > 16) {
                    self->animationSpeed -= 16;
                }
            }
        }
    }
}

void O_LoseRing::ObjectPlayerInteraction()
{
    Entity *self = Self();

    if (pState() != PlayerStateID("Player_State_Hurt")) {
        if (pCollisionPlane() == self->propertyValue) {
            PlayerObjectCollision(C_TOUCH, -8, -8, 8, 8);
            if (CheckResult() == 1) {
                self->type = TypeNameID("Ring Sparkle");
                if (self->propertyValue == 0) {
                    self->drawOrder = 4;
                } else {
                    self->drawOrder = 2;
                }
                self->values[0] = 0;
                self->values[1] = 0;
                self->values[2] = 0;
                self->frame = 0;
                PlayerValue(0)++;
                if (PlayerValue(0) > 999) {
                    PlayerValue(0) = 999;
                }
                if (PlayerValue(0) >= GVar("Ring.ExtraLife")) {
                    if (GVar("Options.GameMode") != 2) {
                        GVar("Player.Lives")++;
                        GVar("Ring.ExtraLife") += 100;
                        if (GVar("Ring.ExtraLife") > 300) {
                            GVar("Ring.ExtraLife") = 1000;
                        }
                    }
                    if (PlayerValue(0) >= 200) {
                        if (playerListPos == 0) {
                            if (debugMode == 0) {
                                SetAchievement(4, 100);
                            }
                        }
                    }
                }
                if (GVar("Ring.Pan") == 0) {
                    SetSfxAttributes(1, -1, -100);
                    GVar("Ring.Pan") = 1;
                } else {
                    SetSfxAttributes(2, -1, 100);
                    GVar("Ring.Pan") = 0;
                }
            }
        }
    }
}

void O_LoseRing::ObjectDraw()
{
    Entity *self = Self();

    DrawSprite_Frame(self->frame);
}

#endif // RETRO_USE_NATIVE_OBJECTS

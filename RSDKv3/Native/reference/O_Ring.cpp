#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_Ring.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"

using namespace Native;

// AUTO-GENERATED from Ring.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_Ring::ObjectStartup()
{
    int arrayPos0 = 0;

    LoadSpriteSheet("Global/Items.gif");
    AddSpriteFrame(-8, -8, 16, 16, 1, 1);
    AddSpriteFrame(-8, -8, 16, 16, 1, 18);
    AddSpriteFrame(-8, -8, 16, 16, 1, 35);
    AddSpriteFrame(-8, -8, 16, 16, 1, 52);
    AddSpriteFrame(-8, -8, 16, 16, 1, 69);
    AddSpriteFrame(-8, -8, 16, 16, 1, 86);
    AddSpriteFrame(-8, -8, 16, 16, 1, 103);
    AddSpriteFrame(-8, -8, 16, 16, 1, 120);
    arrayPos0 = 32;
    while (arrayPos0 < 1056) {
        if (objectEntityList[arrayPos0].type == TypeNameID("Ring")) {
            if (objectEntityList[arrayPos0].propertyValue == 0) {
                objectEntityList[arrayPos0].drawOrder = 4;
            } else {
                objectEntityList[arrayPos0].drawOrder = 2;
            }
        }
        arrayPos0++;
    }
}

void O_Ring::ObjectPlayerInteraction()
{
    Entity *self = Self();

    if (pState() != PlayerStateID("Player_State_Hurt")) {
        if (pCollisionPlane() == self->propertyValue) {
            PlayerObjectCollision(C_TOUCH, -8, -8, 8, 8);
            if (CheckResult() == true) {
                self->type = TypeNameID("Ring Sparkle");
                PlayerValue(0)++;
                if (PlayerValue(0) > 999) {
                    PlayerValue(0) = 999;
                }
                if (PlayerValue(0) >= GVar("Ring.ExtraLife")) {
                    if (GVar("Options.GameMode") != 2) {
                        GVar("Player.Lives")++;
                        if (playerListPos == 0) {
                            PlaySfx(20, false);
                        } else {
                            PlaySfx(21, false);
                        }
                    }
                    GVar("Ring.ExtraLife") += 100;
                    if (GVar("Ring.ExtraLife") > 300) {
                        GVar("Ring.ExtraLife") = 1000;
                    }
                    if (PlayerValue(0) >= 200) {
                        if (playerListPos == 0) {
                            if (GVar("Stage.DebugMode") == false) {
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

void O_Ring::ObjectDraw()
{
    DrawSprite_Frame(GVar("Ring.Frame"));
}

#endif // RETRO_USE_NATIVE_OBJECTS

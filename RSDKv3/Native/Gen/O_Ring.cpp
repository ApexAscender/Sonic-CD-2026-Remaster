#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_Ring.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from Ring.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_Ring::ObjectStartup()
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
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Ring")) {
            if (objectEntityList[scriptEng.arrayPosition[0]].propertyValue == 0) {
                objectEntityList[scriptEng.arrayPosition[0]].drawOrder = 4;
            } else {
                objectEntityList[scriptEng.arrayPosition[0]].drawOrder = 2;
            }
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_Ring::ObjectPlayerInteraction()
{
    Entity *self = Self();

    if (pState() != PlayerStateID("Player_State_Hurt")) {
        if (pCollisionPlane() == self->propertyValue) {
            PlayerObjectCollision(C_TOUCH, -8, -8, 8, 8);
            if (CheckResult() == 1) {
                self->type = TypeNameID("Ring Sparkle");
                PlayerValue(0)++;
                if (PlayerValue(0) > 999) {
                    PlayerValue(0) = 999;
                }
                if (PlayerValue(0) >= GVar("Ring.ExtraLife")) {
                    if (GVar("Options.GameMode") != 2) {
                        GVar("Player.Lives")++;
                        if (playerListPos == 0) {
                            PlaySfx(20, 0);
                        } else {
                            PlaySfx(21, 0);
                        }
                    }
                    GVar("Ring.ExtraLife") += 100;
                    if (GVar("Ring.ExtraLife") > 300) {
                        GVar("Ring.ExtraLife") = 1000;
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

void O_Ring::ObjectDraw()
{
    DrawSprite_Frame(GVar("Ring.Frame"));
}

#endif // RETRO_USE_NATIVE_OBJECTS

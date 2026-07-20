#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_GoalPost.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from GoalPost.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_GoalPost::ObjectStartup()
{
    if (playerListPos == 0) {
        LoadSpriteSheet("Global/Items2.gif");
    }
    if (playerListPos == 1) {
        LoadSpriteSheet("Global/Items2_t.gif");
    }
    AddSpriteFrame(-20, -44, 40, 56, 34, 165);
}

void O_GoalPost::ObjectMain()
{
    Entity *self = Self();

    if (self->state == 0) {
        scriptEng.tempValue[0] = self->YPos;
        scriptEng.tempValue[0] += 0x600000;
        if (pYPos() < scriptEng.tempValue[0]) {
            if (pXPos() > self->XPos) {
                newXBoundary1 = self->XPos;
                newXBoundary1 >>= 16;
                newXBoundary1 -= 160;
                GVar("Warp.Destination") = 0;
                GVar("Warp.Timer") = 0;
                self->state = 1;
                if (self->propertyValue == 1) {
                    PlayerObjectCollision(C_TOUCH, -32, -256, 32, 16);
                    if (CheckResult() == 1) {
                        if (playerListPos == 0) {
                            if (debugMode == 0) {
                                SetAchievement(3, 100);
                            }
                        }
                    }
                }
            }
        }
    }
}

void O_GoalPost::ObjectDraw()
{
    DrawSprite_Frame(0);
}

#endif // RETRO_USE_NATIVE_OBJECTS

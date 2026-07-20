#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R1_FlipDoor.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from FlipDoor.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R1_FlipDoor::ObjectStartup()
{
    LoadSpriteSheet("R1/Objects.gif");
    AddSpriteFrame(-24, -4, 48, 8, 117, 34);
    AddSpriteFrame(-24, -44, 8, 48, 167, 43);
    AddSpriteFrame(-4, -24, 8, 48, 176, 43);
    AddSpriteFrame(-4, -24, 48, 8, 117, 34);
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Flip Door")) {
            objectEntityList[scriptEng.arrayPosition[0]].drawOrder = 5;
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_R1_FlipDoor::ObjectPlayerInteraction()
{
    Entity *self = Self();

    if (self->propertyValue == 0) {
        PlayerObjectCollision(C_PLATFORM, -24, -4, 24, 32);
        PlayerObjectCollision(C_TOUCH, -24, -8, 24, 8);
        if (CheckResult() == 1) {
            if (pYPos() > self->YPos) {
                if (self->values[0] == 0) {
                    PlaySfx(globalSFXCount + 4, 0);
                }
                self->values[0] = 10;
            }
        }
    } else {
        if (pXPos() < self->XPos) {
            PlayerObjectCollision(C_TOUCH, -16, -24, 0, 24);
            if (CheckResult() == 1) {
                if (self->values[0] == 0) {
                    PlaySfx(globalSFXCount + 4, 0);
                }
                self->values[0] = 10;
            }
        } else {
            if (self->values[0] == 0) {
                PlayerObjectCollision(C_BOX, -24, -24, 4, 24);
            }
        }
    }
}

void O_R1_FlipDoor::ObjectDraw()
{
    Entity *self = Self();

    if (self->propertyValue == 0) {
        if (self->values[0] > 0) {
            DrawSprite_Frame(1);
            self->values[0]--;
        } else {
            DrawSprite_Frame(0);
        }
    } else {
        if (self->values[0] > 0) {
            DrawSprite_Frame(3);
            self->values[0]--;
        } else {
            DrawSprite_Frame(2);
        }
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS

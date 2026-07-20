#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R4_RisingFloat.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from RisingFloat.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R4_RisingFloat::ObjectStartup()
{
    LoadSpriteSheet("R4/Objects2.gif");
    AddSpriteFrame(-16, -8, 32, 16, 67, 235);
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Rising Float")) {
            objectEntityList[scriptEng.arrayPosition[0]].values[1] = objectEntityList[scriptEng.arrayPosition[0]].XPos;
            objectEntityList[scriptEng.arrayPosition[0]].values[2] = objectEntityList[scriptEng.arrayPosition[0]].YPos;
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_R4_RisingFloat::ObjectMain()
{
    Entity *self = Self();

    self->YPos = waterLevel;
    self->YPos <<= 16;
    if (self->state == 1) {
        self->XPos = pXPos();
        if (self->XPos < 0x10100000) {
            self->XPos = 0x10100000;
        }
        if (self->XPos > 0x10F20000) {
            self->XPos = 0x10F20000;
        } else {
            if (pYPos() > 0x5BE0000) {
                if (pYPos() < self->YPos) {
                    ObjectTileCollision_Script(1, 16, 6, 0);
                    if (CheckResult() == 1) {
                        if (pSpeed() > 0x10000) {
                            pSpeed() = 0x10000;
                            pXVel() = 0x10000;
                        }
                    }
                    ObjectTileCollision_Script(2, -16, 6, 0);
                    if (CheckResult() == 1) {
                        if (pSpeed() < -0x10000) {
                            pSpeed() = -0x10000;
                            pXVel() = -0x10000;
                        }
                    }
                    pXPos() = self->XPos;
                }
            } else {
                ObjectTileCollision_Script(1, 16, 0, 0);
                ObjectTileCollision_Script(2, -16, 0, 0);
            }
        }
    }
    if (GetObjectOutOfBounds(objectLoop) == 1) {
        scriptEng.tempValue[0] = self->XPos;
        scriptEng.tempValue[1] = self->YPos;
        self->XPos = self->values[1];
        self->YPos = self->values[2];
        if (GetObjectOutOfBounds(objectLoop) == 1) {
            self->state = 0;
            self->priority = 0;
        } else {
            self->XPos = scriptEng.tempValue[0];
            self->YPos = scriptEng.tempValue[1];
        }
    }
}

void O_R4_RisingFloat::ObjectPlayerInteraction()
{
    Entity *self = Self();

    PlayerObjectCollision(C_PLATFORM, -16, -10, 16, 8);
    if (CheckResult() == 1) {
        pYPos() += 0x20000;
        if (self->state == 0) {
            pSpeed() = 0;
            pXVel() = 0;
            GVar("Stage.NewWaterLevel") = 0x5E40000;
            self->state = 1;
            self->priority = 1;
        }
    }
}

void O_R4_RisingFloat::ObjectDraw()
{
    DrawSprite_Frame(0);
}

#endif // RETRO_USE_NATIVE_OBJECTS

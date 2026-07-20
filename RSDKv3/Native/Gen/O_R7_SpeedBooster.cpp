#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R7_SpeedBooster.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from SpeedBooster.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R7_SpeedBooster::ObjectStartup()
{
    LoadSpriteSheet("R7/Objects.gif");
    AddSpriteFrame(-32, -12, 64, 24, 34, 96);
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Speed Booster")) {
            objectEntityList[scriptEng.arrayPosition[0]].drawOrder = 4;
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_R7_SpeedBooster::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 1:
        if (self->values[0] < 6) {
            self->values[1] -= 0x80000;
            self->values[0]++;
        } else {
            self->values[0] = 0;
            self->state++;
        }
        break;
        case 2:
        if (self->values[0] < 6) {
            self->values[1] += 0x80000;
            self->values[0]++;
        } else {
            self->values[0] = 0;
            self->state = 0;
            self->priority = 0;
        }
        break;
        case 3:
        if (self->values[0] < 6) {
            self->values[1] += 0x80000;
            self->values[0]++;
        } else {
            self->values[0] = 0;
            self->state++;
        }
        break;
        case 4:
        if (self->values[0] < 6) {
            self->values[1] -= 0x80000;
            self->values[0]++;
        } else {
            self->values[0] = 0;
            self->state = 0;
            self->priority = 0;
        }
        break;
    }
}

void O_R7_SpeedBooster::ObjectPlayerInteraction()
{
    Entity *self = Self();

    if (self->state == 0) {
        if (pState() != PlayerStateID("Player_State_Air")) {
            PlayerObjectCollision(C_TOUCH, -32, -12, 32, 4);
            if (CheckResult() == 1) {
                self->priority = 1;
                PlaySfx(globalSFXCount + 0, 0);
                HapticEffect_Script(30, 0, 0, 0);
                if (pSpeed() > 0) {
                    self->state = 1;
                    pSpeed() = 0x100000;
                    pDirection() = 0;
                    CreateTempObject(TypeNameID("Fire Trail"), 0, self->XPos, self->YPos);
                    objectEntityList[scriptEng.arrayPosition[2]].XPos -= 0x180000;
                    objectEntityList[scriptEng.arrayPosition[2]].YPos -= 0x60000;
                    CreateTempObject(TypeNameID("BoosterCartridge"), 0, self->XPos, self->YPos);
                    objectEntityList[scriptEng.arrayPosition[2]].values[1] = -0x20000;
                    objectEntityList[scriptEng.arrayPosition[2]].values[2] = -0x70000;
                } else {
                    self->state = 3;
                    pSpeed() = -0x100000;
                    pDirection() = 1;
                    CreateTempObject(TypeNameID("Fire Trail"), 0, self->XPos, self->YPos);
                    objectEntityList[scriptEng.arrayPosition[2]].XPos += 0x180000;
                    objectEntityList[scriptEng.arrayPosition[2]].YPos -= 0x60000;
                    objectEntityList[scriptEng.arrayPosition[2]].direction = 1;
                    CreateTempObject(TypeNameID("BoosterCartridge"), 0, self->XPos, self->YPos);
                    objectEntityList[scriptEng.arrayPosition[2]].values[1] = 0x20000;
                    objectEntityList[scriptEng.arrayPosition[2]].values[2] = -0x70000;
                    objectEntityList[scriptEng.arrayPosition[2]].direction = 1;
                }
            }
        }
    }
}

void O_R7_SpeedBooster::ObjectDraw()
{
    Entity *self = Self();

    scriptEng.tempValue[0] = self->values[1];
    scriptEng.tempValue[0] += self->XPos;
    DrawSprite_FrameXY(0, scriptEng.tempValue[0], self->YPos);
}

#endif // RETRO_USE_NATIVE_OBJECTS

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R6_BigPlatform.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from BigPlatform.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R6_BigPlatform::ObjectStartup()
{
    LoadSpriteSheet("R6/Objects4.gif");
    if (objectEntityList[24].propertyValue == 2) {
        AddSpriteFrame(-48, -80, 96, 192, 98, 1);
    } else {
        AddSpriteFrame(-48, -80, 96, 192, 1, 1);
    }
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Big Platform")) {
            objectEntityList[scriptEng.arrayPosition[0]].values[3] = 256;
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_R6_BigPlatform::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        PlayerObjectCollision(C_TOUCH, -96, -160, 128, 160);
        if (CheckResult() == 1) {
            scriptEng.tempValue[0] = pXPos();
            scriptEng.tempValue[0] -= self->XPos;
            if (scriptEng.tempValue[0] > 0x800000) {
                self->state = 2;
                self->priority = 1;
            } else {
                self->state = 1;
                self->priority = 1;
            }
        }
        break;
        case 1:
        scriptEng.tempValue[0] = pXPos();
        scriptEng.tempValue[0] -= self->XPos;
        if (scriptEng.tempValue[0] > 0x800000) {
            self->state = 2;
        }
        if (self->values[3] > 0) {
            self->values[3] -= 2;
        }
        break;
        case 2:
        if (pXPos() < self->XPos) {
            self->state = 1;
        }
        if (self->values[3] < 256) {
            self->values[3] += 2;
        }
        break;
    }
    self->values[2] = Cos512(self->values[3]);
    self->values[2] <<= 13;
    self->values[2] += 0x400000;
    self->values[2] += self->YPos;
    self->values[2] &= 0xFFFF0000;
    self->values[2] -= self->values[1];
    PlayerObjectCollision(C_TOUCH, -328, -256, 328, 256);
    if (CheckResult() == 0) {
        self->state = 0;
        self->priority = 0;
        self->values[3] = 256;
    }
}

void O_R6_BigPlatform::ObjectPlayerInteraction()
{
    Entity *self = Self();

    scriptEng.tempValue[0] = self->YPos;
    self->YPos = self->values[1];
    PlayerObjectCollision(C_BOX, -48, -81, 48, 80);
    if (CheckResult() == 1) {
        pYPos() += self->values[2];
        pYPos() += 0x10000;
    }
    self->YPos = scriptEng.tempValue[0];
}

void O_R6_BigPlatform::ObjectDraw()
{
    Entity *self = Self();

    self->values[1] = Cos512(self->values[3]);
    self->values[1] <<= 13;
    self->values[1] += 0x400000;
    self->values[1] += self->YPos;
    self->values[1] &= 0xFFFF0000;
    DrawSprite_FrameXY(0, self->XPos, self->values[1]);
}

#endif // RETRO_USE_NATIVE_OBJECTS

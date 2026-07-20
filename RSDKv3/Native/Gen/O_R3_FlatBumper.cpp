#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R3_FlatBumper.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from FlatBumper.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R3_FlatBumper::ObjectStartup()
{
    switch (objectEntityList[24].propertyValue) {
        case 0:
        case 1:
        LoadSpriteSheet("R3/Objects.gif");
        AddSpriteFrame(-32, -16, 64, 32, 1, 75);
        break;
        case 2:
        LoadSpriteSheet("R3/Objects3.gif");
        AddSpriteFrame(-32, -16, 64, 32, 132, 67);
        break;
        case 3:
        LoadSpriteSheet("R3/Objects3.gif");
        AddSpriteFrame(-32, -16, 64, 32, 132, 100);
        break;
    }
}

void O_R3_FlatBumper::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        if (self->values[0] < 96) {
            self->values[0]++;
            if (self->propertyValue == 0) {
                self->XPos += 0x10000;
            } else {
                self->YPos += 0x10000;
            }
        } else {
            self->state = 1;
        }
        break;
        case 1:
        if (self->values[0] > -96) {
            self->values[0]--;
            if (self->propertyValue == 0) {
                self->XPos -= 0x10000;
            } else {
                self->YPos -= 0x10000;
            }
        } else {
            self->state = 0;
        }
        break;
    }
}

void O_R3_FlatBumper::ObjectPlayerInteraction()
{
    scriptEng.tempValue[0] = 0;
    PlayerObjectCollision(C_TOUCH, -34, -16, -28, 16);
    scriptEng.tempValue[1] = CheckResult();
    PlayerObjectCollision(C_TOUCH, 28, -16, 34, 16);
    scriptEng.tempValue[2] = CheckResult();
    PlayerObjectCollision(C_BOX, -32, -14, 32, 14);
    switch (CheckResult()) {
        case 1:
        if (pState() == PlayerStateID("Player_State_Fly")) {
            pYVel() = -0x40000;
        } else {
            pYVel() = -0x70000;
            pTimer() = 0;
        }
        pGravity() = 1;
        scriptEng.tempValue[0] = 1;
        break;
        case 4:
        if (pState() == PlayerStateID("Player_State_Fly")) {
            pYVel() = 0x40000;
        } else {
            pYVel() = 0x70000;
            pTimer() = 0;
        }
        pTimer() = 0;
        pGravity() = 1;
        scriptEng.tempValue[0] = 1;
        break;
    }
    if (scriptEng.tempValue[1] == 1) {
        pSpeed() = -0x70000;
        pXVel() = -0x70000;
        scriptEng.tempValue[0] = 1;
    }
    if (scriptEng.tempValue[2] == 1) {
        pSpeed() = 0x70000;
        pXVel() = 0x70000;
        scriptEng.tempValue[0] = 1;
    }
    PlayerObjectCollision(C_TOUCH, -16, -14, 16, 0);
    if (CheckResult() == 1) {
        if (pState() == PlayerStateID("Player_State_Fly")) {
            pYVel() = -0x40000;
        } else {
            pYVel() = -0x70000;
            pTimer() = 0;
        }
        pGravity() = 1;
        scriptEng.tempValue[0] = 1;
    }
    PlayerObjectCollision(C_TOUCH, -16, 0, 16, 14);
    if (CheckResult() == 1) {
        if (pState() == PlayerStateID("Player_State_Fly")) {
            pYVel() = 0x40000;
        } else {
            pYVel() = 0x70000;
            pTimer() = 0;
        }
        pGravity() = 1;
        scriptEng.tempValue[0] = 1;
    }
    if (scriptEng.tempValue[0] == 1) {
        PlaySfx(globalSFXCount + 1, 0);
        HapticEffect_Script(10, 0, 0, 0);
    }
}

void O_R3_FlatBumper::ObjectDraw()
{
    DrawSprite_Frame(0);
}

#endif // RETRO_USE_NATIVE_OBJECTS

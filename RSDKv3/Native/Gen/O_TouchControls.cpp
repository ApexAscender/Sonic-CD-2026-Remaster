#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_TouchControls.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from TouchControls.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_TouchControls::ObjectStartup()
{
    LoadSpriteSheet("Global/Items.gif");
    AddSpriteFrame(-8, -8, 16, 16, 1, 1);
    AddSpriteFrame(-16, -16, 32, 32, 18, 1);
    AddSpriteFrame(-16, -16, 32, 32, 18, 34);
    AddSpriteFrame(-16, -16, 32, 32, 18, 67);
    AddSpriteFrame(-16, -16, 32, 32, 18, 100);
    CheckResult() = 1;
    if (CheckResult() == 1) {
        AddSpriteFrame(-16, -16, 32, 32, 18, 133);
        AddSpriteFrame(-16, -16, 32, 32, 18, 166);
        AddSpriteFrame(-16, -16, 32, 32, 51, 100);
        AddSpriteFrame(-16, -16, 32, 32, 51, 133);
    } else {
        AddSpriteFrame(-16, -16, 32, 32, 84, 200);
        AddSpriteFrame(-16, -16, 32, 32, 18, 166);
        AddSpriteFrame(-16, -16, 32, 32, 84, 200);
        AddSpriteFrame(-16, -16, 32, 32, 51, 133);
    }
    AddSpriteFrame(-16, -8, 32, 16, 84, 1);
    AddSpriteFrame(-8, -16, 16, 32, 117, 1);
    AddSpriteFrame(-8, -16, 16, 32, 175, 1);
    AddSpriteFrame(-16, -8, 32, 16, 84, 59);
    AddSpriteFrame(-16, -16, 32, 32, 84, 117);
    AddSpriteFrame(-16, -16, 32, 32, 117, 165);
    AddSpriteFrame(-16, -16, 32, 32, 84, 117);
    AddSpriteFrame(-16, -16, 32, 32, 117, 165);
    AddSpriteFrame(-16, -8, 32, 16, 84, 183);
    AddSpriteFrame(-8, -16, 16, 32, 215, 116);
    AddSpriteFrame(-8, -16, 16, 32, 232, 116);
    AddSpriteFrame(-16, -8, 32, 16, 184, 239);
    AddSpriteFrame(-16, -16, 32, 32, 183, 165);
    AddSpriteFrame(-16, -16, 32, 32, 216, 182);
    AddSpriteFrame(-16, -16, 32, 32, 183, 165);
    AddSpriteFrame(-16, -16, 32, 32, 216, 182);
    AddSpriteFrame(-8, -40, 16, 64, 1, 137);
    AddSpriteFrame(-8, -24, 16, 48, 35, 204);
    AddSpriteFrame(-16, -40, 32, 16, 52, 239);
    AddSpriteFrame(-8, -24, 16, 48, 35, 204);
    AddSpriteFrame(-16, -40, 32, 16, 118, 239);
}

void O_TouchControls::ObjectMain()
{
    Entity *self = Self();

    scriptEng.tempValue[0] = 0;
    if (keyDown.left == 1) {
        pXPos() -= pYVel();
        scriptEng.tempValue[0] = 1;
    }
    if (keyDown.right == 1) {
        pXPos() += pYVel();
        scriptEng.tempValue[0] = 1;
    }
    if (keyDown.up == 1) {
        pYPos() -= pYVel();
        scriptEng.tempValue[0] = 1;
    }
    if (keyDown.down == 1) {
        pYPos() += pYVel();
        scriptEng.tempValue[0] = 1;
    }
    if (scriptEng.tempValue[0] == 1) {
        pYVel() += 0xC00;
        if (pYVel() > 0x100000) {
            pYVel() = 0x100000;
        }
    } else {
        pYVel() = 0;
    }
    if (keyPress.B == 1) {
        self->values[6] = 0;
        self->type = TypeNameID("Player Object");
        if (playerListPos == 1) {
            objectEntityList[objectLoop + 1].type = TypeNameID("Tails Object");
        }
        pSpeed() = 0;
        pRotation() = 0;
        pXVel() = 0;
        pYVel() = 0;
        pState() = PlayerStateID("Player_State_Air");
        pAnimation() = GVar("ANI_WALKING");
        pAnimationSpeed() = 0;
        pFrame() = 0;
        pControlMode() = 0;
        pObjectInteractions() = 1;
    } else {
        if (keyPress.A == 1) {
            self->rotation++;
            if (self->rotation > 27) {
                self->rotation = 0;
            }
            DebugMode_ChangeItem();
        }
        if (keyDown.A == 1) {
            if (keyPress.C == 1) {
                self->rotation--;
                if (self->rotation < 0) {
                    self->rotation = 27;
                }
                DebugMode_ChangeItem();
            }
        } else {
            if (keyPress.C == 1) {
                switch (self->rotation) {
                    case 0:
                    CreateTempObject(TypeNameID("Ring"), 0, pXPos(), pYPos());
                    objectEntityList[scriptEng.arrayPosition[2]].drawOrder = 4;
                    break;
                    case 1:
                    case 2:
                    case 3:
                    case 4:
                    case 5:
                    case 6:
                    case 7:
                    case 8:
                    CreateTempObject(TypeNameID("Monitor"), self->rotation, pXPos(), pYPos());
                    break;
                    case 9:
                    case 10:
                    case 11:
                    case 12:
                    case 13:
                    case 14:
                    case 15:
                    case 16:
                    scriptEng.tempValue[0] = self->rotation;
                    scriptEng.tempValue[0] -= 9;
                    CreateTempObject(TypeNameID("Red Spring"), scriptEng.tempValue[0], pXPos(), pYPos());
                    break;
                    case 17:
                    case 18:
                    case 19:
                    case 20:
                    case 21:
                    case 22:
                    case 23:
                    case 24:
                    scriptEng.tempValue[0] = self->rotation;
                    scriptEng.tempValue[0] -= 17;
                    CreateTempObject(TypeNameID("Yellow Spring"), scriptEng.tempValue[0], pXPos(), pYPos());
                    break;
                    case 25:
                    CreateTempObject(TypeNameID("Lamp Post"), 0, pXPos(), pYPos());
                    break;
                    case 26:
                    CreateTempObject(TypeNameID("Future Post"), 0, pXPos(), pYPos());
                    break;
                    case 27:
                    CreateTempObject(TypeNameID("Past Post"), 0, pXPos(), pYPos());
                    break;
                }
                objectEntityList[scriptEng.arrayPosition[2]].priority = 4;
            }
        }
    }
}

void O_TouchControls::ObjectDraw()
{
    Entity *self = Self();

    DrawSprite_FrameXY(self->frame, pXPos(), pYPos());
    if (self->values[6] > 0) {
        DrawSprite_FrameXY(self->values[6], pXPos(), pYPos());
    }
}

void O_TouchControls::DebugMode_ChangeItem()
{
    Entity *self = Self();

    switch (self->rotation) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
        case 16:
        case 17:
        case 18:
        case 19:
        case 20:
        case 21:
        case 22:
        case 23:
        case 24:
        case 25:
        self->frame = self->rotation;
        self->values[6] = 0;
        break;
        case 26:
        self->frame = 26;
        self->values[6] = 27;
        break;
        case 27:
        self->frame = 28;
        self->values[6] = 29;
        break;
    }
}

const Native::NativeFunctionDef O_TouchControls::funcs[1] = {
    { "DebugMode_ChangeItem", O_TouchControls::DebugMode_ChangeItem },
};

#endif // RETRO_USE_NATIVE_OBJECTS

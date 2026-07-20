#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R3_Piston.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from Piston.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R3_Piston::ObjectStartup()
{
    LoadSpriteSheet("R3/Objects.gif");
    AddSpriteFrame(-16, -4, 32, 8, 214, 34);
    AddSpriteFrame(-16, -12, 32, 40, 1, 34);
    switch (objectEntityList[24].propertyValue) {
        case 0:
        case 3:
        AddSpriteFrame(-16, -12, 32, 40, 34, 34);
        AddSpriteFrame(-16, -12, 32, 40, 1, 34);
        AddSpriteFrame(-16, -12, 32, 40, 34, 34);
        AddSpriteFrame(-16, -12, 32, 40, 1, 34);
        AddSpriteFrame(-16, -12, 32, 40, 34, 34);
        AddSpriteFrame(-16, -12, 32, 40, 1, 34);
        AddSpriteFrame(-16, -12, 32, 40, 34, 34);
        AddSpriteFrame(-16, -12, 32, 40, 1, 34);
        AddSpriteFrame(-16, -12, 32, 40, 34, 34);
        AddSpriteFrame(-16, -12, 32, 40, 1, 34);
        break;
        case 1:
        case 2:
        AddSpriteFrame(-16, -12, 32, 40, 1, 34);
        AddSpriteFrame(-16, -12, 32, 40, 1, 34);
        AddSpriteFrame(-16, -12, 32, 40, 1, 34);
        AddSpriteFrame(-16, -12, 32, 40, 1, 34);
        AddSpriteFrame(-16, -12, 32, 40, 1, 34);
        AddSpriteFrame(-16, -12, 32, 40, 1, 34);
        AddSpriteFrame(-16, -12, 32, 40, 1, 34);
        AddSpriteFrame(-16, -12, 32, 40, 1, 34);
        AddSpriteFrame(-16, -12, 32, 40, 1, 34);
        AddSpriteFrame(-16, -12, 32, 40, 1, 34);
        break;
    }
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Piston")) {
            objectEntityList[scriptEng.arrayPosition[0]].frame = 1;
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_R3_Piston::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        PlayerObjectCollision(C_TOUCH, -112, -256, 112, 256);
        if (CheckResult() == 1) {
            if (self->values[0] < 80) {
                self->values[0]++;
                self->frame = 1;
            } else {
                self->values[0] = 6;
                self->state = 1;
            }
        }
        break;
        case 1:
        if (self->values[0] < 33) {
            self->values[0]++;
            self->frame = self->values[0];
            self->frame /= 3;
        } else {
            self->frame = 1;
            self->values[0] = 0;
            self->state = 2;
        }
        break;
        case 2:
        if (self->values[1] < 0x200000) {
            self->values[1] += 0x80000;
        } else {
            self->state = 3;
        }
        break;
        case 3:
        if (self->values[0] < 8) {
            if (self->values[0] == 0) {
                switch (objectEntityList[24].propertyValue) {
                    case 0:
                    case 3:
                    CreateTempObject(TypeNameID("Fireball"), 0, self->XPos, self->YPos);
                    objectEntityList[scriptEng.arrayPosition[2]].XPos -= 0x180000;
                    objectEntityList[scriptEng.arrayPosition[2]].YPos -= 0x140000;
                    objectEntityList[scriptEng.arrayPosition[2]].values[0] = 64;
                    objectEntityList[scriptEng.arrayPosition[2]].values[1] = -0x10000;
                    objectEntityList[scriptEng.arrayPosition[2]].inkEffect = 2;
                    objectEntityList[scriptEng.arrayPosition[2]].alpha = 255;
                    objectEntityList[scriptEng.arrayPosition[2]].frame = 0;
                    CreateTempObject(TypeNameID("Fireball"), 0, self->XPos, self->YPos);
                    objectEntityList[scriptEng.arrayPosition[2]].XPos += 0x180000;
                    objectEntityList[scriptEng.arrayPosition[2]].YPos -= 0x140000;
                    objectEntityList[scriptEng.arrayPosition[2]].values[0] = 64;
                    objectEntityList[scriptEng.arrayPosition[2]].values[1] = 0x10000;
                    objectEntityList[scriptEng.arrayPosition[2]].inkEffect = 2;
                    objectEntityList[scriptEng.arrayPosition[2]].alpha = 255;
                    objectEntityList[scriptEng.arrayPosition[2]].frame = 1;
                }
            }
            self->values[0]++;
        } else {
            self->values[0] = 0;
            self->state = 4;
        }
        break;
        case 4:
        if (self->values[1] > 0) {
            self->values[1] -= 0x40000;
        } else {
            self->state = 0;
        }
        break;
    }
}

void O_R3_Piston::ObjectPlayerInteraction()
{
    Entity *self = Self();

    scriptEng.tempValue[0] = -0xC0000;
    scriptEng.tempValue[0] -= self->values[1];
    scriptEng.tempValue[0] >>= 16;
    PlayerObjectCollision(C_BOX, -16, -12, 16, 16);
    PlayerObjectCollision(C_PLATFORM, -16, scriptEng.tempValue[0], 16, 16);
    if (CheckResult() == 1) {
        if (self->values[1] == 0x200000) {
            if (self->state == 2) {
                pYVel() = -0x70000;
                pTimer() = 0;
                pGravity() = 1;
                pAnimation() = GVar("ANI_BOUNCING");
                pState() = PlayerStateID("Player_State_Air");
            }
        }
    }
}

void O_R3_Piston::ObjectDraw()
{
    Entity *self = Self();

    scriptEng.tempValue[0] = self->YPos;
    scriptEng.tempValue[0] -= self->values[1];
    DrawSprite_FrameXY(self->frame, self->XPos, scriptEng.tempValue[0]);
    DrawSprite_Frame(0);
}

#endif // RETRO_USE_NATIVE_OBJECTS

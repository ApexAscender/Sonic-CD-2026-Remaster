#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R8_InvisiblePlatform.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from InvisiblePlatform.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R8_InvisiblePlatform::ObjectStartup()
{
    LoadSpriteSheet("R8/Objects2.gif");
    AddSpriteFrame(-4, -16, 0, 0, 190, 223);
    AddSpriteFrame(-4, -16, 8, 32, 190, 223);
    AddSpriteFrame(-4, -16, 8, 32, 223, 223);
    AddSpriteFrame(-4, -16, 8, 32, 190, 223);
    AddSpriteFrame(-4, -16, 8, 32, 223, 223);
    AddSpriteFrame(-8, -16, 16, 32, 190, 223);
    AddSpriteFrame(-8, -16, 16, 32, 223, 223);
    AddSpriteFrame(-8, -16, 16, 32, 190, 223);
    AddSpriteFrame(-8, -16, 16, 32, 223, 223);
    AddSpriteFrame(-16, -16, 32, 32, 190, 223);
    AddSpriteFrame(-16, -16, 32, 32, 223, 223);
    AddSpriteFrame(-16, -16, 32, 32, 190, 223);
    AddSpriteFrame(-16, -16, 32, 32, 223, 223);
    AddSpriteFrame(-16, -16, 32, 32, 223, 223);
    AddSpriteFrame(-16, -16, 32, 32, 190, 223);
    AddSpriteFrame(-16, -16, 32, 32, 223, 223);
    AddSpriteFrame(-16, -16, 32, 32, 190, 223);
    AddSpriteFrame(-16, -16, 32, 32, 223, 223);
    AddSpriteFrame(-8, -16, 16, 32, 190, 223);
    AddSpriteFrame(-8, -16, 16, 32, 223, 223);
    AddSpriteFrame(-8, -16, 16, 32, 190, 223);
    AddSpriteFrame(-8, -16, 16, 32, 223, 223);
    AddSpriteFrame(-4, -16, 8, 32, 190, 223);
    AddSpriteFrame(-4, -16, 8, 32, 223, 223);
    AddSpriteFrame(-4, -16, 8, 32, 190, 223);
    AddSpriteFrame(-4, -16, 8, 32, 223, 223);
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Inv Platform")) {
            switch (objectEntityList[scriptEng.arrayPosition[0]].propertyValue) {
                case 0:
                case 1:
                objectEntityList[scriptEng.arrayPosition[0]].values[1] = 60;
                break;
                case 2:
                objectEntityList[scriptEng.arrayPosition[0]].values[1] = 60;
                objectEntityList[scriptEng.arrayPosition[0]].values[3] = 108;
                objectEntityList[scriptEng.arrayPosition[0]].values[6] = 156;
                break;
            }
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_R8_InvisiblePlatform::ObjectMain()
{
    Entity *self = Self();

    if (self->values[0] < self->values[1]) {
        self->values[0]++;
    } else {
        self->values[0] = 0;
        self->frame++;
        self->frame %= 26;
        scriptEng.tempValue[0] = self->frame;
        InvPlatform_SetMaxTimer();
        self->values[1] = scriptEng.tempValue[1];
    }
    if (self->propertyValue == 2) {
        if (self->values[2] < self->values[3]) {
            self->values[2]++;
        } else {
            self->values[2] = 0;
            self->values[4]++;
            self->values[4] %= 26;
            scriptEng.tempValue[0] = self->values[4];
            InvPlatform_SetMaxTimer();
            self->values[3] = scriptEng.tempValue[1];
        }
        if (self->values[5] < self->values[6]) {
            self->values[5]++;
        } else {
            self->values[5] = 0;
            self->values[7]++;
            self->values[7] %= 26;
            scriptEng.tempValue[0] = self->values[7];
            InvPlatform_SetMaxTimer();
            self->values[6] = scriptEng.tempValue[1];
        }
    }
}

void O_R8_InvisiblePlatform::ObjectPlayerInteraction()
{
    Entity *self = Self();

    switch (self->propertyValue) {
        case 0:
        if (self->frame == 13) {
            PlayerObjectCollision(C_PLATFORM, -16, -16, 16, 0);
        }
        break;
        case 1:
        if (self->frame == 13) {
            PlayerObjectCollision(C_PLATFORM, -16, -16, 48, 0);
        }
        break;
        case 2:
        if (self->frame == 13) {
            PlayerObjectCollision(C_PLATFORM, -16, -16, 16, 0);
        }
        if (self->values[4] == 13) {
            PlayerObjectCollision(C_PLATFORM, 16, 0, 48, 16);
        }
        if (self->values[7] == 13) {
            PlayerObjectCollision(C_PLATFORM, 48, 16, 80, 32);
        }
        break;
    }
}

void O_R8_InvisiblePlatform::ObjectDraw()
{
    Entity *self = Self();

    switch (self->propertyValue) {
        case 0:
        DrawSprite_Frame(self->frame);
        break;
        case 1:
        scriptEng.tempValue[0] = self->XPos;
        DrawSprite_FrameXY(self->frame, scriptEng.tempValue[0], self->YPos);
        scriptEng.tempValue[0] += 0x200000;
        DrawSprite_FrameXY(self->frame, scriptEng.tempValue[0], self->YPos);
        break;
        case 2:
        scriptEng.tempValue[0] = self->XPos;
        scriptEng.tempValue[1] = self->YPos;
        DrawSprite_FrameXY(self->frame, scriptEng.tempValue[0], scriptEng.tempValue[1]);
        scriptEng.tempValue[0] += 0x200000;
        scriptEng.tempValue[1] += 0x100000;
        DrawSprite_FrameXY(self->values[4], scriptEng.tempValue[0], scriptEng.tempValue[1]);
        scriptEng.tempValue[0] += 0x200000;
        scriptEng.tempValue[1] += 0x100000;
        DrawSprite_FrameXY(self->values[7], scriptEng.tempValue[0], scriptEng.tempValue[1]);
        break;
    }
}

void O_R8_InvisiblePlatform::InvPlatform_SetMaxTimer()
{
    switch (scriptEng.tempValue[0]) {
        case 0:
        scriptEng.tempValue[1] = 60;
        break;
        case 1:
        case 3:
        case 5:
        case 7:
        case 9:
        case 11:
        case 14:
        case 16:
        case 18:
        case 20:
        case 22:
        case 24:
        scriptEng.tempValue[1] = 5;
        break;
        case 2:
        case 4:
        case 6:
        case 8:
        case 10:
        case 12:
        case 15:
        case 17:
        case 19:
        case 21:
        case 23:
        case 25:
        scriptEng.tempValue[1] = 3;
        break;
        case 13:
        scriptEng.tempValue[1] = 160;
        break;
    }
}

const Native::NativeFunctionDef O_R8_InvisiblePlatform::funcs[1] = {
    { "InvPlatform_SetMaxTimer", O_R8_InvisiblePlatform::InvPlatform_SetMaxTimer },
};

#endif // RETRO_USE_NATIVE_OBJECTS

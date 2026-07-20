#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R5_DipPlatform.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from DipPlatform.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R5_DipPlatform::ObjectStartup()
{
    LoadSpriteSheet("R5/Objects.gif");
    switch (objectEntityList[24].propertyValue) {
        case 0:
        LoadSpriteSheet("R5/Objects.gif");
        AddSpriteFrame(-16, -16, 32, 32, 1, 51);
        AddSpriteFrame(-32, -16, 64, 32, 34, 51);
        AddSpriteFrame(-48, -16, 96, 32, 1, 84);
        AddSpriteFrame(-16, -16, 32, 16, 65, 208);
        AddSpriteFrame(-32, -16, 64, 16, 1, 208);
        AddSpriteFrame(-48, -16, 96, 16, 1, 191);
        break;
        case 1:
        LoadSpriteSheet("R5/Objects3.gif");
        AddSpriteFrame(-16, -16, 32, 32, 1, 170);
        AddSpriteFrame(-32, -16, 64, 32, 34, 170);
        AddSpriteFrame(-48, -16, 96, 32, 1, 203);
        AddSpriteFrame(-16, -16, 32, 16, 223, 148);
        AddSpriteFrame(-32, -16, 64, 16, 159, 148);
        AddSpriteFrame(-48, -16, 96, 16, 159, 131);
        break;
        case 2:
        LoadSpriteSheet("R5/Objects3.gif");
        AddSpriteFrame(-16, -16, 32, 32, 1, 170);
        AddSpriteFrame(-32, -16, 64, 32, 34, 170);
        AddSpriteFrame(-48, -16, 96, 32, 1, 203);
        AddSpriteFrame(-16, -16, 32, 16, 223, 182);
        AddSpriteFrame(-32, -16, 64, 16, 159, 182);
        AddSpriteFrame(-48, -16, 96, 16, 159, 165);
        break;
        case 3:
        LoadSpriteSheet("R5/Objects3.gif");
        AddSpriteFrame(-16, -16, 32, 32, 1, 170);
        AddSpriteFrame(-32, -16, 64, 32, 34, 170);
        AddSpriteFrame(-48, -16, 96, 32, 1, 203);
        AddSpriteFrame(-16, -16, 32, 16, 223, 216);
        AddSpriteFrame(-32, -16, 64, 16, 159, 216);
        AddSpriteFrame(-48, -16, 96, 16, 159, 199);
        break;
    }
}

void O_R5_DipPlatform::ObjectMain()
{
    Entity *self = Self();

    if (self->values[0] == 1) {
        if (self->values[1] < 16) {
            self->values[1]++;
            scriptEng.tempValue[0] = self->values[1];
            scriptEng.tempValue[0] &= 3;
            if (scriptEng.tempValue[0] == 3) {
                self->values[2] = 0x10000;
            } else {
                self->values[2] = 0;
            }
        } else {
            self->values[2] = 0;
        }
    } else {
        if (self->values[1] > 0) {
            self->values[1]--;
            scriptEng.tempValue[0] = self->values[1];
            scriptEng.tempValue[0] &= 3;
            if (scriptEng.tempValue[0] == 3) {
                self->values[2] = -0x10000;
            } else {
                self->values[2] = 0;
            }
        } else {
            self->values[2] = 0;
        }
    }
    self->values[0] = 0;
}

void O_R5_DipPlatform::ObjectPlayerInteraction()
{
    Entity *self = Self();

    switch (self->propertyValue) {
        case 0:
        PlayerObjectCollision(C_PLATFORM, -16, -16, 16, 12);
        if (CheckResult() == 1) {
            self->values[0] = 1;
            pYPos() += self->values[2];
        }
        break;
        case 1:
        PlayerObjectCollision(C_PLATFORM, -32, -16, 32, 12);
        if (CheckResult() == 1) {
            self->values[0] = 1;
            pYPos() += self->values[2];
        }
        break;
        case 2:
        PlayerObjectCollision(C_PLATFORM, -48, -16, 48, 12);
        if (CheckResult() == 1) {
            self->values[0] = 1;
            pYPos() += self->values[2];
        }
        break;
        case 3:
        PlayerObjectCollision(C_PLATFORM, -16, -16, 16, 12);
        if (CheckResult() == 1) {
            self->values[0] = 1;
            pYPos() += self->values[2];
            if (GVar("ConveyorBelt_Flag") == 0) {
                pXPos() += GVar("ConveyorBelt_Speed");
            } else {
                pXPos() -= GVar("ConveyorBelt_Speed");
            }
        }
        break;
        case 4:
        PlayerObjectCollision(C_PLATFORM, -32, -16, 32, 12);
        if (CheckResult() == 1) {
            self->values[0] = 1;
            pYPos() += self->values[2];
            if (GVar("ConveyorBelt_Flag") == 0) {
                pXPos() += GVar("ConveyorBelt_Speed");
            } else {
                pXPos() -= GVar("ConveyorBelt_Speed");
            }
        }
        break;
        case 5:
        PlayerObjectCollision(C_PLATFORM, -48, -16, 48, 12);
        if (CheckResult() == 1) {
            self->values[0] = 1;
            pYPos() += self->values[2];
            if (GVar("ConveyorBelt_Flag") == 0) {
                pXPos() += GVar("ConveyorBelt_Speed");
            } else {
                pXPos() -= GVar("ConveyorBelt_Speed");
            }
        }
        break;
    }
}

void O_R5_DipPlatform::ObjectDraw()
{
    Entity *self = Self();

    self->YPos += self->values[2];
    switch (self->propertyValue) {
        case 0:
        case 1:
        case 2:
        DrawSprite_Frame(self->propertyValue);
        break;
        case 3:
        DrawSprite_Frame(0);
        DrawSprite_Frame(3);
        break;
        case 4:
        DrawSprite_Frame(1);
        DrawSprite_Frame(4);
        break;
        case 5:
        DrawSprite_Frame(2);
        DrawSprite_Frame(5);
        break;
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS

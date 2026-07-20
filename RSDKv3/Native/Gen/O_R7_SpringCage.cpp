#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R7_SpringCage.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from SpringCage.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R7_SpringCage::ObjectStartup()
{
    LoadSpriteSheet("R7/Objects.gif");
    AddSpriteFrame(-8, -8, 16, 16, 90, 52);
    AddSpriteFrame(-8, -28, 64, 24, 34, 96);
    AddSpriteFrame(-24, -56, 56, 56, 59, 121);
    AddSpriteFrame(-56, -24, 56, 56, 59, 121);
    AddSpriteFrame(-28, -56, 24, 64, 34, 121);
    AddSpriteFrame(-56, -28, 64, 24, 34, 96);
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Spring Cage")) {
            scriptEng.arrayPosition[1] = scriptEng.arrayPosition[0];
            scriptEng.arrayPosition[1]++;
            switch (objectEntityList[scriptEng.arrayPosition[0]].propertyValue) {
                case 1:
                objectEntityList[scriptEng.arrayPosition[0]].values[1] = 4;
                objectEntityList[scriptEng.arrayPosition[1]].propertyValue = 2;
                break;
                case 3:
                objectEntityList[scriptEng.arrayPosition[0]].values[1] = 1;
                objectEntityList[scriptEng.arrayPosition[1]].propertyValue = 1;
                break;
                case 4:
                objectEntityList[scriptEng.arrayPosition[0]].values[1] = 2;
                objectEntityList[scriptEng.arrayPosition[1]].propertyValue = 4;
                break;
                case 5:
                objectEntityList[scriptEng.arrayPosition[0]].values[1] = 3;
                objectEntityList[scriptEng.arrayPosition[1]].propertyValue = 5;
                break;
                case 6:
                objectEntityList[scriptEng.arrayPosition[0]].values[1] = 0;
                objectEntityList[scriptEng.arrayPosition[1]].propertyValue = 2;
                break;
            }
            objectEntityList[scriptEng.arrayPosition[0]].drawOrder = 4;
            objectEntityList[scriptEng.arrayPosition[1]].XPos = objectEntityList[scriptEng.arrayPosition[0]].XPos;
            objectEntityList[scriptEng.arrayPosition[1]].YPos = objectEntityList[scriptEng.arrayPosition[0]].YPos;
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_R7_SpringCage::ObjectMain()
{
    Entity *self = Self();

    if (self->state == 0) {
        if (self->propertyValue == 0) {
            self->values[0]++;
            self->values[0] %= 48;
            self->values[1] = self->values[0];
            self->values[1] /= 6;
        }
        switch (self->values[1]) {
            case 0:
            objectEntityList[objectLoop + 1].propertyValue = 1;
            break;
            case 1:
            case 7:
            objectEntityList[objectLoop + 1].propertyValue = 4;
            break;
            case 2:
            case 6:
            objectEntityList[objectLoop + 1].propertyValue = 0;
            break;
            case 3:
            case 5:
            objectEntityList[objectLoop + 1].propertyValue = 5;
            break;
            case 4:
            objectEntityList[objectLoop + 1].propertyValue = 2;
            break;
        }
    } else {
        if (self->values[3] < 90) {
            if (pState() != PlayerStateID("Player_State_Death")) {
                self->values[3]++;
                if (self->values[3] == 60) {
                    PlaySfx(globalSFXCount + 0, 0);
                    pState() = PlayerStateID("Player_State_Air");
                    pGravity() = 1;
                    pTimer() = 0;
                    objectEntityList[objectLoop + 1].values[0] = 1;
                    switch (self->values[1]) {
                        case 0:
                        pSpeed() = 0x100000;
                        pXVel() = 0x100000;
                        pYVel() = 0x000000;
                        break;
                        case 1:
                        case 7:
                        pSpeed() = 0x0C0000;
                        pXVel() = 0x0C0000;
                        pYVel() = -0x0B0000;
                        break;
                        case 2:
                        case 6:
                        pSpeed() = 0x000000;
                        pXVel() = 0x000000;
                        pYVel() = -0x100000;
                        break;
                        case 3:
                        case 5:
                        pSpeed() = -0x0C0000;
                        pXVel() = -0x0C0000;
                        pYVel() = -0x0B0000;
                        break;
                        case 4:
                        pSpeed() = -0x100000;
                        pXVel() = -0x100000;
                        pYVel() = 0x000000;
                        break;
                    }
                }
            } else {
                self->state = 0;
                self->values[3] = 0;
            }
        } else {
            self->state = 0;
            self->values[3] = 0;
        }
    }
}

void O_R7_SpringCage::ObjectPlayerInteraction()
{
    Entity *self = Self();

    if (self->state == 0) {
        PlayerObjectCollision(C_TOUCH, -28, -32, 28, 24);
        if (CheckResult() == 1) {
            self->state = 1;
            pXPos() = self->XPos;
            pYPos() = self->YPos;
            pState() = PlayerStateID("Player_State_Static");
            pAnimation() = GVar("ANI_JUMPING");
            pSpeed() = 0;
            pXVel() = 0;
            pYVel() = 0;
            switch (self->values[1]) {
                case 0:
                pXPos() += 0x200000;
                break;
                case 1:
                case 7:
                pXPos() += 0x180000;
                pYPos() -= 0x180000;
                break;
                case 2:
                case 6:
                pYPos() -= 0x200000;
                break;
                case 3:
                case 5:
                pXPos() -= 0x180000;
                pYPos() -= 0x180000;
                break;
                case 4:
                pXPos() -= 0x200000;
                break;
            }
        }
    }
}

void O_R7_SpringCage::ObjectDraw()
{
    Entity *self = Self();

    switch (self->values[1]) {
        case 0:
        DrawSprite_Frame(1);
        self->direction = 2;
        DrawSpriteFX_Script(1, FX_FLIP, self->XPos, self->YPos);
        break;
        case 1:
        case 7:
        DrawSprite_Frame(2);
        self->direction = 3;
        DrawSpriteFX_Script(3, FX_FLIP, self->XPos, self->YPos);
        break;
        case 2:
        case 6:
        DrawSprite_Frame(4);
        self->direction = 1;
        DrawSpriteFX_Script(4, FX_FLIP, self->XPos, self->YPos);
        break;
        case 3:
        case 5:
        self->direction = 1;
        DrawSpriteFX_Script(2, FX_FLIP, self->XPos, self->YPos);
        self->direction = 2;
        DrawSpriteFX_Script(3, FX_FLIP, self->XPos, self->YPos);
        break;
        case 4:
        DrawSprite_Frame(5);
        self->direction = 2;
        DrawSpriteFX_Script(5, FX_FLIP, self->XPos, self->YPos);
        break;
    }
    DrawSprite_Frame(0);
}

#endif // RETRO_USE_NATIVE_OBJECTS

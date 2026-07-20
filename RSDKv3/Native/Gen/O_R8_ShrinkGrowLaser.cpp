#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R8_ShrinkGrowLaser.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from ShrinkGrowLaser.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R8_ShrinkGrowLaser::ObjectStartup()
{
    LoadSpriteSheet("R8/Objects2.gif");
    GVar("Mini_PlayerFlag") = 0;
    if (playerListPos == 0) {
        LoadAnimation_Script("MiniSonic.Ani");
    } else {
        LoadAnimation_Script("MiniTails.Ani");
    }
    AddSpriteFrame(-8, -12, 16, 24, 151, 144);
    AddSpriteFrame(-8, -12, 16, 24, 168, 144);
    AddSpriteFrame(-4, -8, 8, 16, 82, 196);
    AddSpriteFrame(-4, -8, 8, 16, 91, 196);
    AddSpriteFrame(-4, -8, 8, 16, 100, 196);
    AddSpriteFrame(-8, 0, 16, 8, 169, 169);
    AddSpriteFrame(-8, 0, 16, 8, 134, 178);
    AddSpriteFrame(-8, 0, 16, 8, 152, 169);
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("S G Laser")) {
            objectEntityList[scriptEng.arrayPosition[0]].drawOrder = 4;
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_R8_ShrinkGrowLaser::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        if (self->values[0] < 24) {
            scriptEng.tempValue[0] = self->values[0];
            scriptEng.tempValue[0] &= 3;
            if (scriptEng.tempValue[0] == 0) {
                CreateTempObject(TypeNameID("S G Laser"), self->propertyValue, self->XPos, self->YPos);
                objectEntityList[scriptEng.arrayPosition[2]].state = 1;
            }
        }
        if (self->values[0] == 0) {
            PlayerObjectCollision(C_TOUCH, -96, -128, 96, 128);
            if (CheckResult() == 1) {
                if (self->propertyValue == 0) {
                    PlaySfx(globalSFXCount + 3, 0);
                } else {
                    PlaySfx(globalSFXCount + 4, 0);
                }
            }
        }
        self->values[0]++;
        self->values[0] &= 31;
        break;
        case 1:
        self->YPos += 0x40000;
        ObjectTileCollision_Script(0, 0, 8, 0);
        if (CheckResult() == 1) {
            self->values[1] = self->YPos;
            self->state++;
        }
        break;
        case 2:
        if (self->values[0] < 4) {
            self->YPos += 0x40000;
            self->values[0]++;
        } else {
            self->type = TypeNameID("Blank Object");
        }
        break;
    }
}

void O_R8_ShrinkGrowLaser::ObjectPlayerInteraction()
{
    Entity *self = Self();

    if (self->state > 0) {
        if (self->propertyValue == GVar("Mini_PlayerFlag")) {
            if (pState() != PlayerStateID("Player_State_SizeChange")) {
                PlayerObjectCollision(C_TOUCH, -4, -8, 4, 8);
                if (CheckResult() == 1) {
                    if (self->propertyValue == 0) {
                        HapticEffect_Script(39, 0, 0, 0);
                    } else {
                        HapticEffect_Script(33, 0, 0, 0);
                    }
                    pState() = PlayerStateID("Player_State_SizeChange");
                    pAnimation() = GVar("ANI_SIZE_CHANGE");
                    pYVel() = -0x40000;
                    pGravity() = 1;
                    if (pXPos() > self->XPos) {
                        pSpeed() = 0x20000;
                    } else {
                        pSpeed() = -0x20000;
                    }
                }
            }
        }
    }
}

void O_R8_ShrinkGrowLaser::ObjectDraw()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        DrawSprite_Frame(self->propertyValue);
        break;
        case 1:
        if (self->animationTimer < 2) {
            scriptEng.tempValue[0] = 2;
            scriptEng.tempValue[0] += self->propertyValue;
            DrawSprite_Frame(scriptEng.tempValue[0]);
        } else {
            DrawSprite_Frame(4);
        }
        self->animationTimer++;
        self->animationTimer &= 3;
        break;
        case 2:
        if (self->animationTimer < 2) {
            scriptEng.tempValue[0] = 2;
            scriptEng.tempValue[0] += self->propertyValue;
            DrawSprite_Frame(scriptEng.tempValue[0]);
            scriptEng.tempValue[0] += 3;
            DrawSprite_FrameXY(scriptEng.tempValue[0], self->XPos, self->values[1]);
        } else {
            DrawSprite_Frame(4);
            DrawSprite_FrameXY(7, self->XPos, self->values[1]);
        }
        self->animationTimer++;
        self->animationTimer &= 3;
        break;
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS

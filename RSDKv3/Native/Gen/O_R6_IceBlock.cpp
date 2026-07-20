#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R6_IceBlock.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from IceBlock.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R6_IceBlock::ObjectStartup()
{
    if (playerListPos == 0) {
        LoadSpriteSheet("R6/Objects.gif");
        AddSpriteFrame(-24, -24, 48, 48, 34, 18);
        AddSpriteFrame(-8, -12, 16, 24, 206, 1);
        AddSpriteFrame(-8, -8, 16, 16, 66, 1);
        AddSpriteFrame(-8, -8, 16, 16, 66, 1);
        AddSpriteFrame(-4, -4, 8, 8, 34, 67);
    }
    if (playerListPos == 1) {
        LoadSpriteSheet("R6/Objects3.gif");
        AddSpriteFrame(-24, -24, 48, 48, 1, 101);
        AddSpriteFrame(-8, -12, 16, 24, 50, 86);
        AddSpriteFrame(-8, -8, 16, 16, 50, 111);
        AddSpriteFrame(-8, -8, 16, 16, 50, 111);
        AddSpriteFrame(-4, -4, 8, 8, 50, 128);
    }
}

void O_R6_IceBlock::ObjectMain()
{
    Entity *self = Self();

    switch (self->propertyValue) {
        case 0:
        if (self->state == 0) {
            self->YPos += self->values[2];
            self->values[2] += pGravityStrength();
            if (self->values[2] > 0x140000) {
                self->values[2] = 0x140000;
            }
            ObjectTileCollision_Script(0, 0, 24, 0);
            if (CheckResult() == 1) {
                self->state = 1;
                self->values[2] = 0;
                PlaySfx(globalSFXCount + 4, 0);
            }
            pXPos() = self->XPos;
            pYPos() = self->YPos;
        } else {
            if (self->values[0] < 16) {
                self->values[0]++;
                if (objectEntityList[0].type == TypeNameID("PlayerObject")) {
                    if (pJumpPress() == 1) {
                        IceBlock_CreateIceChunks();
                        self->type = TypeNameID("Blank Object");
                        CallScriptFunctionNamed("Player_Action_Jump", scriptSub);
                        pVisible() = 1;
                        pObjectInteractions() = 1;
                    }
                }
            } else {
                IceBlock_CreateIceChunks();
                self->type = TypeNameID("Blank Object");
                pState() = PlayerStateID("Player_State_Air");
                CallScriptFunctionNamed("Player_Hit", scriptSub);
                pVisible() = 1;
                pObjectInteractions() = 1;
            }
        }
        break;
        case 1:
        if (self->values[0] < 10) {
            self->values[0]++;
            self->XPos += self->values[1];
            self->YPos += self->values[2];
        } else {
            self->type = TypeNameID("Blank Object");
            CreateTempObject(TypeNameID("Ice Block"), 4, self->XPos, self->YPos);
            objectEntityList[scriptEng.arrayPosition[2]].drawOrder = 4;
            objectEntityList[scriptEng.arrayPosition[2]].values[1] = 0;
            objectEntityList[scriptEng.arrayPosition[2]].values[2] = -0x10000;
            CreateTempObject(TypeNameID("Ice Block"), 4, self->XPos, self->YPos);
            objectEntityList[scriptEng.arrayPosition[2]].drawOrder = 4;
            objectEntityList[scriptEng.arrayPosition[2]].values[1] = -0x10000;
            objectEntityList[scriptEng.arrayPosition[2]].values[2] = 0;
            CreateTempObject(TypeNameID("Ice Block"), 4, self->XPos, self->YPos);
            objectEntityList[scriptEng.arrayPosition[2]].drawOrder = 4;
            objectEntityList[scriptEng.arrayPosition[2]].values[1] = 0x10000;
            objectEntityList[scriptEng.arrayPosition[2]].values[2] = 0;
            CreateTempObject(TypeNameID("Ice Block"), 4, self->XPos, self->YPos);
            objectEntityList[scriptEng.arrayPosition[2]].drawOrder = 4;
            objectEntityList[scriptEng.arrayPosition[2]].values[1] = 0;
            objectEntityList[scriptEng.arrayPosition[2]].values[2] = 0x10000;
        }
        break;
        case 2:
        if (self->values[0] < 16) {
            self->values[0]++;
            self->XPos += self->values[1];
            self->YPos += self->values[2];
        } else {
            self->type = TypeNameID("Blank Object");
            CreateTempObject(TypeNameID("Ice Block"), 4, self->XPos, self->YPos);
            objectEntityList[scriptEng.arrayPosition[2]].drawOrder = 4;
            objectEntityList[scriptEng.arrayPosition[2]].values[1] = 0;
            objectEntityList[scriptEng.arrayPosition[2]].values[2] = -0x10000;
            CreateTempObject(TypeNameID("Ice Block"), 4, self->XPos, self->YPos);
            objectEntityList[scriptEng.arrayPosition[2]].drawOrder = 4;
            objectEntityList[scriptEng.arrayPosition[2]].values[1] = -0x10000;
            objectEntityList[scriptEng.arrayPosition[2]].values[2] = 0x10000;
            CreateTempObject(TypeNameID("Ice Block"), 4, self->XPos, self->YPos);
            objectEntityList[scriptEng.arrayPosition[2]].drawOrder = 4;
            objectEntityList[scriptEng.arrayPosition[2]].values[1] = 0x10000;
            objectEntityList[scriptEng.arrayPosition[2]].values[2] = 0x10000;
        }
        break;
        case 3:
        if (self->values[0] < 1) {
            self->values[0]++;
        } else {
            self->type = TypeNameID("Blank Object");
        }
        break;
        case 4:
        if (self->values[0] < 12) {
            self->values[0]++;
            self->XPos += self->values[1];
            self->YPos += self->values[2];
        } else {
            self->type = TypeNameID("Blank Object");
        }
        break;
    }
}

void O_R6_IceBlock::ObjectDraw()
{
    Entity *self = Self();

    DrawSpriteFX_Script(self->propertyValue, FX_FLIP, self->XPos, self->YPos);
}

void O_R6_IceBlock::IceBlock_CreateIceChunks()
{
    Entity *self = Self();

    CreateTempObject(TypeNameID("Ice Block"), 1, self->XPos, self->YPos);
    objectEntityList[scriptEng.arrayPosition[2]].drawOrder = 4;
    objectEntityList[scriptEng.arrayPosition[2]].XPos -= 0x110000;
    objectEntityList[scriptEng.arrayPosition[2]].YPos -= 0xD0000;
    objectEntityList[scriptEng.arrayPosition[2]].values[1] = -0x10000;
    objectEntityList[scriptEng.arrayPosition[2]].values[2] = -0x10000;
    objectEntityList[scriptEng.arrayPosition[2]].direction = 0;
    CreateTempObject(TypeNameID("Ice Block"), 1, self->XPos, self->YPos);
    objectEntityList[scriptEng.arrayPosition[2]].drawOrder = 4;
    objectEntityList[scriptEng.arrayPosition[2]].XPos += 0x110000;
    objectEntityList[scriptEng.arrayPosition[2]].YPos -= 0xD0000;
    objectEntityList[scriptEng.arrayPosition[2]].values[1] = 0x10000;
    objectEntityList[scriptEng.arrayPosition[2]].values[2] = -0x10000;
    objectEntityList[scriptEng.arrayPosition[2]].direction = 1;
    CreateTempObject(TypeNameID("Ice Block"), 1, self->XPos, self->YPos);
    objectEntityList[scriptEng.arrayPosition[2]].drawOrder = 4;
    objectEntityList[scriptEng.arrayPosition[2]].XPos -= 0x110000;
    objectEntityList[scriptEng.arrayPosition[2]].YPos += 0xD0000;
    objectEntityList[scriptEng.arrayPosition[2]].values[1] = -0x10000;
    objectEntityList[scriptEng.arrayPosition[2]].values[2] = 0x10000;
    objectEntityList[scriptEng.arrayPosition[2]].direction = 2;
    CreateTempObject(TypeNameID("Ice Block"), 1, self->XPos, self->YPos);
    objectEntityList[scriptEng.arrayPosition[2]].drawOrder = 4;
    objectEntityList[scriptEng.arrayPosition[2]].XPos += 0x110000;
    objectEntityList[scriptEng.arrayPosition[2]].YPos += 0xD0000;
    objectEntityList[scriptEng.arrayPosition[2]].values[1] = 0x10000;
    objectEntityList[scriptEng.arrayPosition[2]].values[2] = 0x10000;
    objectEntityList[scriptEng.arrayPosition[2]].direction = 3;
    CreateTempObject(TypeNameID("Ice Block"), 3, self->XPos, self->YPos);
    objectEntityList[scriptEng.arrayPosition[2]].drawOrder = 4;
    objectEntityList[scriptEng.arrayPosition[2]].direction = 0;
    CreateTempObject(TypeNameID("Ice Block"), 2, self->XPos, self->YPos);
    objectEntityList[scriptEng.arrayPosition[2]].drawOrder = 4;
    objectEntityList[scriptEng.arrayPosition[2]].YPos -= 0x110000;
    objectEntityList[scriptEng.arrayPosition[2]].values[2] = -0x10000;
    objectEntityList[scriptEng.arrayPosition[2]].direction = 1;
    CreateTempObject(TypeNameID("Ice Block"), 2, self->XPos, self->YPos);
    objectEntityList[scriptEng.arrayPosition[2]].drawOrder = 4;
    objectEntityList[scriptEng.arrayPosition[2]].YPos += 0x110000;
    objectEntityList[scriptEng.arrayPosition[2]].values[2] = 0x10000;
    objectEntityList[scriptEng.arrayPosition[2]].direction = 3;
    HapticEffect_Script(11, 0, 0, 0);
}

const Native::NativeFunctionDef O_R6_IceBlock::funcs[1] = {
    { "IceBlock_CreateIceChunks", O_R6_IceBlock::IceBlock_CreateIceChunks },
};

#endif // RETRO_USE_NATIVE_OBJECTS

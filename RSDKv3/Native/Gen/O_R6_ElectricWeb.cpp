#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R6_ElectricWeb.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from ElectricWeb.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R6_ElectricWeb::ObjectStartup()
{
    LoadSpriteSheet("R6/Objects3.gif");
    AddSpriteFrame(-24, -24, 48, 48, 73, 34);
    AddSpriteFrame(-24, -24, 48, 48, 122, 34);
    AddSpriteFrame(-24, -24, 48, 48, 73, 34);
    AddSpriteFrame(-24, -24, 48, 48, 73, 83);
    AddSpriteFrame(-24, -24, 48, 48, 73, 34);
    AddSpriteFrame(-24, -24, 48, 48, 122, 83);
    AddSpriteFrame(-24, -24, 48, 48, 73, 34);
    AddSpriteFrame(-24, -24, 48, 48, 73, 34);
    AddSpriteFrame(-24, -24, 48, 48, 122, 132);
    AddSpriteFrame(-8, -104, 16, 80, 171, 119);
    AddSpriteFrame(-8, -104, 16, 80, 188, 119);
    AddSpriteFrame(-8, -104, 16, 80, 171, 119);
    AddSpriteFrame(-8, -104, 16, 80, 205, 119);
    AddSpriteFrame(-8, -104, 16, 80, 171, 119);
    AddSpriteFrame(-8, -104, 16, 80, 222, 119);
    AddSpriteFrame(-8, -104, 16, 80, 171, 119);
    AddSpriteFrame(-8, -104, 16, 80, 171, 119);
    AddSpriteFrame(-8, -104, 16, 80, 239, 119);
    AddSpriteFrame(-104, -8, 80, 16, 175, 34);
    AddSpriteFrame(-104, -8, 80, 16, 175, 51);
    AddSpriteFrame(-104, -8, 80, 16, 175, 34);
    AddSpriteFrame(-104, -8, 80, 16, 175, 68);
    AddSpriteFrame(-104, -8, 80, 16, 175, 34);
    AddSpriteFrame(-104, -8, 80, 16, 175, 85);
    AddSpriteFrame(-104, -8, 80, 16, 175, 34);
    AddSpriteFrame(-104, -8, 80, 16, 175, 34);
    AddSpriteFrame(-104, -8, 80, 16, 175, 102);
    AddSpriteFrame(-43, -116, 32, 32, 66, 1);
    AddSpriteFrame(-43, -116, 32, 32, 99, 1);
    AddSpriteFrame(-43, -116, 32, 32, 66, 1);
    AddSpriteFrame(-43, -116, 32, 32, 132, 1);
    AddSpriteFrame(-43, -116, 32, 32, 66, 1);
    AddSpriteFrame(-43, -116, 32, 32, 165, 1);
    AddSpriteFrame(-43, -116, 32, 32, 66, 1);
    AddSpriteFrame(-43, -116, 32, 32, 66, 1);
    AddSpriteFrame(-43, -116, 32, 32, 198, 1);
    AddSpriteFrame(-67, -92, 32, 32, 66, 1);
    AddSpriteFrame(-67, -92, 32, 32, 99, 1);
    AddSpriteFrame(-67, -92, 32, 32, 66, 1);
    AddSpriteFrame(-67, -92, 32, 32, 132, 1);
    AddSpriteFrame(-67, -92, 32, 32, 66, 1);
    AddSpriteFrame(-67, -92, 32, 32, 165, 1);
    AddSpriteFrame(-67, -92, 32, 32, 66, 1);
    AddSpriteFrame(-67, -92, 32, 32, 66, 1);
    AddSpriteFrame(-67, -92, 32, 32, 198, 1);
    AddSpriteFrame(-91, -68, 32, 32, 66, 1);
    AddSpriteFrame(-91, -68, 32, 32, 99, 1);
    AddSpriteFrame(-91, -68, 32, 32, 66, 1);
    AddSpriteFrame(-91, -68, 32, 32, 132, 1);
    AddSpriteFrame(-91, -68, 32, 32, 66, 1);
    AddSpriteFrame(-91, -68, 32, 32, 165, 1);
    AddSpriteFrame(-91, -68, 32, 32, 66, 1);
    AddSpriteFrame(-91, -68, 32, 32, 66, 1);
    AddSpriteFrame(-91, -68, 32, 32, 198, 1);
    AddSpriteFrame(-115, -44, 32, 32, 66, 1);
    AddSpriteFrame(-115, -44, 32, 32, 99, 1);
    AddSpriteFrame(-115, -44, 32, 32, 66, 1);
    AddSpriteFrame(-115, -44, 32, 32, 132, 1);
    AddSpriteFrame(-115, -44, 32, 32, 66, 1);
    AddSpriteFrame(-115, -44, 32, 32, 165, 1);
    AddSpriteFrame(-115, -44, 32, 32, 66, 1);
    AddSpriteFrame(-115, -44, 32, 32, 66, 1);
    AddSpriteFrame(-115, -44, 32, 32, 198, 1);
}

void O_R6_ElectricWeb::ObjectDraw()
{
    Entity *self = Self();

    switch (self->propertyValue) {
        case 0:
        DrawSprite_Frame(objectEntityList[19].frame);
        scriptEng.tempValue[0] = self->XPos;
        scriptEng.tempValue[1] = self->YPos;
        scriptEng.tempValue[1] -= 0x800000;
        DrawSprite_FrameXY(objectEntityList[19].frame, scriptEng.tempValue[0], scriptEng.tempValue[1]);
        scriptEng.tempValue[1] += 0x1000000;
        DrawSprite_FrameXY(objectEntityList[19].frame, scriptEng.tempValue[0], scriptEng.tempValue[1]);
        if (objectEntityList[19].state > 0) {
            switch (objectEntityList[19].direction) {
                case 0:
                self->values[2] = 9;
                self->values[2] += objectEntityList[19].frame;
                DrawSprite_Frame(self->values[2]);
                self->direction = 2;
                DrawSprite_FrameXY(self->values[2], self->XPos, scriptEng.tempValue[1]);
                break;
                case 1:
                self->values[1] = 18;
                self->values[1] += objectEntityList[19].frame;
                DrawSprite_Frame(self->values[1]);
                self->direction = 1;
                scriptEng.tempValue[0] += 0x800000;
                DrawSprite_FrameXY(self->values[1], scriptEng.tempValue[0], self->YPos);
                break;
                case 2:
                scriptEng.tempValue[0] += 0x800000;
                self->values[3] = 27;
                self->values[3] += objectEntityList[19].frame;
                self->direction = 1;
                scriptEng.tempValue[2] = self->XPos;
                scriptEng.tempValue[2] -= 0x800000;
                DrawSprite_Frame(self->values[3]);
                DrawSpriteFX_Script(self->values[3], FX_FLIP, self->XPos, self->YPos);
                DrawSprite_FrameXY(self->values[3], scriptEng.tempValue[0], scriptEng.tempValue[1]);
                DrawSpriteFX_Script(self->values[3], FX_FLIP, scriptEng.tempValue[2], scriptEng.tempValue[1]);
                self->values[3] += 9;
                DrawSprite_Frame(self->values[3]);
                DrawSpriteFX_Script(self->values[3], FX_FLIP, self->XPos, self->YPos);
                DrawSprite_FrameXY(self->values[3], scriptEng.tempValue[0], scriptEng.tempValue[1]);
                DrawSpriteFX_Script(self->values[3], FX_FLIP, scriptEng.tempValue[2], scriptEng.tempValue[1]);
                self->values[3] += 9;
                DrawSprite_Frame(self->values[3]);
                DrawSpriteFX_Script(self->values[3], FX_FLIP, self->XPos, self->YPos);
                DrawSprite_FrameXY(self->values[3], scriptEng.tempValue[0], scriptEng.tempValue[1]);
                DrawSpriteFX_Script(self->values[3], FX_FLIP, scriptEng.tempValue[2], scriptEng.tempValue[1]);
                self->values[3] += 9;
                DrawSprite_Frame(self->values[3]);
                DrawSpriteFX_Script(self->values[3], FX_FLIP, self->XPos, self->YPos);
                DrawSprite_FrameXY(self->values[3], scriptEng.tempValue[0], scriptEng.tempValue[1]);
                DrawSpriteFX_Script(self->values[3], FX_FLIP, scriptEng.tempValue[2], scriptEng.tempValue[1]);
                break;
            }
        }
        break;
        case 1:
        DrawSprite_Frame(objectEntityList[19].frame);
        break;
        case 2:
        if (objectEntityList[19].state == 0) {
            objectEntityList[19].values[0] = 0;
        }
        break;
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS

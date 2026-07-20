#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R6_ElectricArc.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from ElectricArc.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R6_ElectricArc::ObjectStartup()
{
    LoadSpriteSheet("R6/Objects3.gif");
    if (objectEntityList[24].propertyValue == 2) {
        AddSpriteFrame(-176, -8, 16, 16, 1, 1);
        AddSpriteFrame(-176, -8, 16, 16, 1, 18);
        AddSpriteFrame(-176, -8, 16, 16, 1, 35);
        AddSpriteFrame(-176, -8, 32, 16, 1, 1);
        AddSpriteFrame(-176, -8, 32, 16, 1, 18);
        AddSpriteFrame(-176, -8, 32, 16, 1, 35);
        AddSpriteFrame(-176, -8, 48, 16, 1, 1);
        AddSpriteFrame(-176, -8, 48, 16, 1, 18);
        AddSpriteFrame(-176, -8, 48, 16, 1, 35);
        AddSpriteFrame(-176, -8, 64, 16, 1, 1);
        AddSpriteFrame(-176, -8, 64, 16, 1, 18);
        AddSpriteFrame(-176, -8, 64, 16, 1, 35);
        AddSpriteFrame(-112, -8, 16, 16, 1, 1);
        AddSpriteFrame(-112, -8, 16, 16, 1, 18);
        AddSpriteFrame(-112, -8, 16, 16, 1, 35);
    } else {
        AddSpriteFrame(-176, -8, 16, 16, 1, 150);
        AddSpriteFrame(-176, -8, 16, 16, 1, 167);
        AddSpriteFrame(-176, -8, 16, 16, 1, 184);
        AddSpriteFrame(-176, -8, 32, 16, 1, 150);
        AddSpriteFrame(-176, -8, 32, 16, 1, 167);
        AddSpriteFrame(-176, -8, 32, 16, 1, 184);
        AddSpriteFrame(-176, -8, 48, 16, 1, 150);
        AddSpriteFrame(-176, -8, 48, 16, 1, 167);
        AddSpriteFrame(-176, -8, 48, 16, 1, 184);
        AddSpriteFrame(-176, -8, 64, 16, 1, 150);
        AddSpriteFrame(-176, -8, 64, 16, 1, 167);
        AddSpriteFrame(-176, -8, 64, 16, 1, 184);
        AddSpriteFrame(-112, -8, 16, 16, 1, 150);
        AddSpriteFrame(-112, -8, 16, 16, 1, 167);
        AddSpriteFrame(-112, -8, 16, 16, 1, 184);
    }
}

void O_R6_ElectricArc::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        self->values[0]++;
        if (self->values[0] == 30) {
            self->values[0] = 0;
            self->state++;
        }
        break;
        case 1:
        case 2:
        case 3:
        self->values[0]++;
        if (self->values[0] == 3) {
            self->values[0] = 0;
            self->state++;
        }
        break;
        case 4:
        self->values[0]++;
        if (self->values[0] == 3) {
            self->values[0] = 0;
            self->type = TypeNameID("Blank Object");
            scriptEng.tempValue[1] = self->XPos;
            scriptEng.tempValue[1] >>= 23;
            scriptEng.tempValue[1]--;
            scriptEng.tempValue[2] = self->YPos;
            scriptEng.tempValue[2] >>= 23;
            scriptEng.tempValue[0] = stageLayouts[0].tiles[scriptEng.tempValue[1] + 0x100 * scriptEng.tempValue[2]];
            scriptEng.tempValue[0] += 3;
            stageLayouts[0].tiles[scriptEng.tempValue[1] + 0x100 * scriptEng.tempValue[2]] = scriptEng.tempValue[0];
            scriptEng.tempValue[1]++;
            scriptEng.tempValue[0] = stageLayouts[0].tiles[scriptEng.tempValue[1] + 0x100 * scriptEng.tempValue[2]];
            scriptEng.tempValue[0] += 3;
            stageLayouts[0].tiles[scriptEng.tempValue[1] + 0x100 * scriptEng.tempValue[2]] = scriptEng.tempValue[0];
            scriptEng.tempValue[1]++;
            scriptEng.tempValue[0] = stageLayouts[0].tiles[scriptEng.tempValue[1] + 0x100 * scriptEng.tempValue[2]];
            scriptEng.tempValue[0] += 3;
            stageLayouts[0].tiles[scriptEng.tempValue[1] + 0x100 * scriptEng.tempValue[2]] = scriptEng.tempValue[0];
        }
        break;
    }
    self->frame++;
    self->frame %= 15;
}

void O_R6_ElectricArc::ObjectDraw()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        scriptEng.tempValue[0] = self->frame;
        scriptEng.tempValue[0] /= 5;
        DrawSprite_Frame(scriptEng.tempValue[0]);
        DrawSpriteFX_Script(scriptEng.tempValue[0], FX_FLIP, self->XPos, self->YPos);
        break;
        case 1:
        scriptEng.tempValue[0] = self->frame;
        scriptEng.tempValue[0] /= 5;
        scriptEng.tempValue[0] += 3;
        DrawSprite_Frame(scriptEng.tempValue[0]);
        DrawSpriteFX_Script(scriptEng.tempValue[0], FX_FLIP, self->XPos, self->YPos);
        break;
        case 2:
        scriptEng.tempValue[0] = self->frame;
        scriptEng.tempValue[0] /= 5;
        scriptEng.tempValue[0] += 6;
        DrawSprite_Frame(scriptEng.tempValue[0]);
        DrawSpriteFX_Script(scriptEng.tempValue[0], FX_FLIP, self->XPos, self->YPos);
        break;
        case 3:
        scriptEng.tempValue[0] = self->frame;
        scriptEng.tempValue[0] /= 5;
        scriptEng.tempValue[0] += 9;
        DrawSprite_Frame(scriptEng.tempValue[0]);
        DrawSpriteFX_Script(scriptEng.tempValue[0], FX_FLIP, self->XPos, self->YPos);
        break;
        case 4:
        scriptEng.tempValue[0] = self->frame;
        scriptEng.tempValue[0] /= 5;
        scriptEng.tempValue[0] += 9;
        DrawSprite_Frame(scriptEng.tempValue[0]);
        DrawSpriteFX_Script(scriptEng.tempValue[0], FX_FLIP, self->XPos, self->YPos);
        scriptEng.tempValue[0] += 3;
        DrawSprite_Frame(scriptEng.tempValue[0]);
        DrawSpriteFX_Script(scriptEng.tempValue[0], FX_FLIP, self->XPos, self->YPos);
        break;
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS

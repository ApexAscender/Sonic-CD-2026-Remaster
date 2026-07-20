#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R4_Fan.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from Fan.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R4_Fan::ObjectStartup()
{
    switch (objectEntityList[24].propertyValue) {
        case 0:
        case 1:
        LoadSpriteSheet("R4/Objects.gif");
        AddSpriteFrame(-16, -8, 32, 16, 163, 35);
        AddSpriteFrame(-12, -8, 24, 16, 229, 1);
        AddSpriteFrame(-8, -8, 16, 16, 229, 18);
        AddSpriteFrame(-12, -8, 24, 16, 196, 35);
        AddSpriteFrame(-16, -8, 32, 16, 221, 35);
        AddSpriteFrame(-8, -16, 16, 32, 239, 136);
        AddSpriteFrame(-8, -12, 16, 24, 222, 169);
        AddSpriteFrame(-8, -8, 16, 16, 239, 194);
        AddSpriteFrame(-8, -12, 16, 24, 239, 169);
        AddSpriteFrame(-8, -16, 16, 32, 222, 136);
        break;
        case 2:
        LoadSpriteSheet("R4/Objects3.gif");
        AddSpriteFrame(-16, -8, 32, 16, 51, 67);
        AddSpriteFrame(-16, -8, 32, 16, 51, 84);
        AddSpriteFrame(-16, -8, 32, 16, 51, 84);
        AddSpriteFrame(-16, -8, 32, 16, 51, 84);
        AddSpriteFrame(-16, -8, 32, 16, 51, 84);
        AddSpriteFrame(-8, -16, 16, 32, 50, 101);
        AddSpriteFrame(-8, -16, 16, 32, 67, 101);
        AddSpriteFrame(-8, -16, 16, 32, 67, 101);
        AddSpriteFrame(-8, -16, 16, 32, 67, 101);
        AddSpriteFrame(-8, -16, 16, 32, 67, 101);
        break;
        case 3:
        LoadSpriteSheet("R4/Objects3.gif");
        AddSpriteFrame(-16, -8, 32, 16, 62, 228);
        AddSpriteFrame(-16, -8, 32, 16, 94, 228);
        AddSpriteFrame(-16, -8, 32, 16, 94, 228);
        AddSpriteFrame(-16, -8, 32, 16, 94, 228);
        AddSpriteFrame(-16, -8, 32, 16, 94, 228);
        AddSpriteFrame(-8, -16, 16, 32, 76, 144);
        AddSpriteFrame(-8, -16, 16, 32, 93, 144);
        AddSpriteFrame(-8, -16, 16, 32, 93, 144);
        AddSpriteFrame(-8, -16, 16, 32, 93, 144);
        AddSpriteFrame(-8, -16, 16, 32, 93, 144);
        break;
    }
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Fan")) {
            objectEntityList[scriptEng.arrayPosition[0]].state = objectEntityList[scriptEng.arrayPosition[0]].propertyValue;
            if (objectEntityList[scriptEng.arrayPosition[0]].propertyValue > 3) {
                objectEntityList[scriptEng.arrayPosition[0]].state -= 2;
                objectEntityList[scriptEng.arrayPosition[0]].direction = 1;
            }
            objectEntityList[scriptEng.arrayPosition[0]].propertyValue &= 1;
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_R4_Fan::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        case 2:
        if (objectEntityList[objectLoop - 1].propertyValue == 1) {
            self->propertyValue = 1;
            self->state++;
        }
        break;
        case 1:
        case 3:
        if (objectEntityList[24].propertyValue < 2) {
            self->frame++;
            if (self->frame > 9) {
                self->frame = 0;
            }
        } else {
            self->frame = 2;
        }
        break;
    }
}

void O_R4_Fan::ObjectDraw()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        DrawSprite_Frame(0);
        break;
        case 1:
        scriptEng.tempValue[0] = self->frame;
        scriptEng.tempValue[0] >>= 1;
        DrawSprite_Frame(scriptEng.tempValue[0]);
        break;
        case 2:
        DrawSpriteFX_Script(5, FX_FLIP, self->XPos, self->YPos);
        break;
        case 3:
        scriptEng.tempValue[0] = self->frame;
        scriptEng.tempValue[0] >>= 1;
        scriptEng.tempValue[0] += 5;
        DrawSpriteFX_Script(scriptEng.tempValue[0], FX_FLIP, self->XPos, self->YPos);
        break;
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS

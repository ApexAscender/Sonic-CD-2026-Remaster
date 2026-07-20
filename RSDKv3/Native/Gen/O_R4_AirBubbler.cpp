#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R4_AirBubbler.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from AirBubbler.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R4_AirBubbler::ObjectStartup()
{
    LoadSpriteSheet("R4/Objects.gif");
    AddSpriteFrame(-8, -16, 16, 16, 165, 235);
    AddSpriteFrame(-8, -16, 16, 16, 182, 235);
    AddSpriteFrame(-8, -16, 16, 16, 199, 235);
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Air Bubbler")) {
            objectEntityList[scriptEng.arrayPosition[0]].drawOrder = 4;
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_R4_AirBubbler::ObjectMain()
{
    Entity *self = Self();

    self->frame++;
    self->frame %= 48;
    if (self->values[0] > 0) {
        self->values[0]--;
    } else {
        self->values[0] = 220;
        self->values[2] = rand() % 6;
        self->values[2]++;
        if (self->values[2] > 6) {
            self->values[2] = 6;
        }
        self->values[1] = 0;
        self->values[3] = 0;
    }
    if (self->values[1] > 0) {
        self->values[1]--;
    } else {
        if (self->values[2] > 0) {
            self->values[2]--;
            self->values[1] = rand() % 32;
            scriptEng.tempValue[0] = rand() % 3;
            if (scriptEng.tempValue[0] == 2) {
                if (self->values[3] == 0) {
                    self->values[3] = 1;
                    CreateTempObject(TypeNameID("Air Bubble"), 5, self->XPos, self->YPos);
                } else {
                    CreateTempObject(TypeNameID("Air Bubble"), 4, self->XPos, self->YPos);
                }
            } else {
                CreateTempObject(TypeNameID("Air Bubble"), 2, self->XPos, self->YPos);
            }
            scriptEng.tempValue[0] = rand() % 16;
            scriptEng.tempValue[0] -= 8;
            scriptEng.tempValue[0] <<= 16;
            objectEntityList[scriptEng.arrayPosition[2]].XPos += scriptEng.tempValue[0];
            objectEntityList[scriptEng.arrayPosition[2]].values[2] = objectEntityList[scriptEng.arrayPosition[2]].XPos;
            objectEntityList[scriptEng.arrayPosition[2]].values[1] = rand() % 256;
            objectEntityList[scriptEng.arrayPosition[2]].values[1] <<= 1;
            objectEntityList[scriptEng.arrayPosition[2]].drawOrder = 4;
            objectEntityList[scriptEng.arrayPosition[2]].values[3] = -0x8800;
        }
    }
}

void O_R4_AirBubbler::ObjectDraw()
{
    Entity *self = Self();

    scriptEng.tempValue[0] = self->frame;
    scriptEng.tempValue[0] >>= 4;
    DrawSprite_Frame(scriptEng.tempValue[0]);
}

#endif // RETRO_USE_NATIVE_OBJECTS

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_Special_UFOPowerUp.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from UFOPowerUp.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_Special_UFOPowerUp::ObjectStartup()
{
    LoadSpriteSheet("Special/Objects.gif");
    AddSpriteFrame(-8, -8, 16, 16, 1, 67);
    AddSpriteFrame(-8, -8, 16, 16, 18, 67);
    AddSpriteFrame(-8, -8, 16, 16, 35, 67);
}

void O_Special_UFOPowerUp::ObjectDraw()
{
    Entity *self = Self();

    if (self->values[4] < 0x40000) {
        DrawSprite_ScreenXY(self->propertyValue, (objectEntityList[objectLoop].XPos >> 16), (objectEntityList[objectLoop].YPos >> 16));
        self->values[4] += 0x2000;
        self->YPos += self->values[4];
    }
    self->values[6]++;
    if (self->values[6] == 6) {
        self->values[6] = 0;
        PlaySfx(22, 0);
        scriptEng.tempValue[0] = rand() % 48;
        scriptEng.tempValue[0] -= 24;
        scriptEng.tempValue[0] += xScrollOffset;
        scriptEng.tempValue[0] <<= 16;
        scriptEng.tempValue[0] += self->values[1];
        scriptEng.tempValue[1] = rand() % 48;
        scriptEng.tempValue[1] -= 24;
        scriptEng.tempValue[1] += yScrollOffset;
        scriptEng.tempValue[1] <<= 16;
        scriptEng.tempValue[1] += self->values[2];
        CreateTempObject(TypeNameID("Smoke Puff"), 0, scriptEng.tempValue[0], scriptEng.tempValue[1]);
        objectEntityList[scriptEng.arrayPosition[2]].drawOrder = 4;
    }
    if (self->values[0] > 50) {
        self->values[1] += 0x20000;
    } else {
        self->values[1] -= 0x20000;
    }
    self->values[2] += 0xC000;
    self->values[3]++;
    if (self->values[3] == 160) {
        if (self->values[7] == 1) {
            if (GVar("Options.GameMode") < 2) {
                if (actID < 8) {
                    objectEntityList[2].state = 9;
                } else {
                    objectEntityList[30].type = TypeNameID("Stage Finish");
                    objectEntityList[30].state = 9;
                    objectEntityList[30].drawOrder = 7;
                }
            } else {
                objectEntityList[30].type = TypeNameID("Stage Finish");
                objectEntityList[30].state = 8;
                objectEntityList[30].drawOrder = 0;
            }
        }
        self->type = TypeNameID("Blank Object");
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_Special_Dust.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from Dust.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_Special_Dust::ObjectStartup()
{
    LoadSpriteSheet("Special/Objects.gif");
    AddSpriteFrame(-5, -4, 10, 8, 27, 58);
    AddSpriteFrame(-5, -4, 11, 8, 10, 58);
    AddSpriteFrame(-4, -4, 8, 8, 1, 58);
}

void O_Special_Dust::ObjectMain()
{
    Entity *self = Self();

    if (self->propertyValue == 0) {
        if (pYPos() > 0) {
            ResetObjectEntity(3, TypeNameID("Blank Object"), 0, 0, 0);
        } else {
            scriptEng.tempValue[0] = pXPos();
            scriptEng.tempValue[0] >>= 16;
            scriptEng.tempValue[1] = objectEntityList[objectLoop - 1].values[0];
            scriptEng.tempValue[1] >>= 16;
            CheckResult() = Get16x16TileInfo_Script(scriptEng.tempValue[0], scriptEng.tempValue[1], 6);
            if (CheckResult() > 0) {
                self->values[0]++;
                if (self->values[0] > 2) {
                    self->values[0] = 0;
                    PlaySfx(globalSFXCount + 0, 0);
                    scriptEng.tempValue[0] = rand() % 40;
                    scriptEng.tempValue[0] -= 20;
                    scriptEng.tempValue[1] = rand() % 8;
                    scriptEng.tempValue[1] -= 8;
                    scriptEng.tempValue[0] += SCREEN_CENTERX;
                    scriptEng.tempValue[1] += 224;
                    scriptEng.tempValue[0] <<= 16;
                    scriptEng.tempValue[1] <<= 16;
                    CreateTempObject(TypeNameID("Dust Puff"), 1, scriptEng.tempValue[0], scriptEng.tempValue[1]);
                    objectEntityList[scriptEng.arrayPosition[2]].drawOrder = 4;
                }
            } else {
                self->type = TypeNameID("Blank Object");
                self->values[0] = 0;
            }
        }
    } else {
        self->values[0]++;
        if (self->values[0] == 9) {
            self->type = TypeNameID("Blank Object");
        }
        if (pLeft() == 1) {
            self->XPos += 0x10000;
        }
        if (pRight() == 1) {
            self->XPos -= 0x10000;
        }
    }
}

void O_Special_Dust::ObjectDraw()
{
    Entity *self = Self();

    if (self->propertyValue == 1) {
        self->frame = self->values[0];
        self->frame /= 3;
        DrawSprite_Frame(self->frame);
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS

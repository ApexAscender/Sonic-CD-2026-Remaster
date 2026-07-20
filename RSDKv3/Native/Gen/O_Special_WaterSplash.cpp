#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_Special_WaterSplash.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from WaterSplash.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_Special_WaterSplash::ObjectStartup()
{
    LoadSpriteSheet("Special/Objects.gif");
    AddSpriteFrame(-20, -32, 40, 32, 1, 84);
    AddSpriteFrame(-20, -32, 40, 32, 42, 84);
    AddSpriteFrame(-20, -32, 40, 32, 83, 84);
    AddSpriteFrame(-20, -48, 40, 48, 124, 58);
    AddSpriteFrame(-20, -64, 40, 64, 165, 58);
    AddSpriteFrame(-20, -8, 40, 8, 124, 107);
    AddSpriteFrame(-20, -8, 40, 8, 124, 116);
    AddSpriteFrame(-20, -32, 40, 32, 42, 84);
    AddSpriteFrame(-20, -32, 40, 32, 83, 84);
    AddSpriteFrame(-20, -32, 40, 32, 1, 84);
}

void O_Special_WaterSplash::ObjectDraw()
{
    Entity *self = Self();

    if (pYPos() > 0) {
        ResetObjectEntity(3, TypeNameID("Blank Object"), 0, 0, 0);
    } else {
        scriptEng.tempValue[0] = pXPos();
        scriptEng.tempValue[0] >>= 16;
        scriptEng.tempValue[1] = objectEntityList[objectLoop - 1].values[0];
        scriptEng.tempValue[1] >>= 16;
        CheckResult() = Get16x16TileInfo_Script(scriptEng.tempValue[0], scriptEng.tempValue[1], 6);
        if (CheckResult() == 2) {
            if (self->frame == 0) {
                PlaySfx(globalSFXCount + 1, 0);
                if (timeEnabled == 1) {
                    objectEntityList[4].values[7] = 40;
                }
            }
            self->frame++;
            if (self->frame == 40) {
                self->frame = 28;
            }
            scriptEng.tempValue[0] = self->frame;
            scriptEng.tempValue[0] >>= 2;
            DrawSprite_ScreenXY(scriptEng.tempValue[0], SCREEN_CENTERX, 224);
        } else {
            ResetObjectEntity(3, TypeNameID("Blank Object"), 0, 0, 0);
            objectEntityList[4].values[7] = 0;
        }
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS

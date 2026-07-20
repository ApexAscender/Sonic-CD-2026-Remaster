#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R6_EggmanEscape.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from EggmanEscape.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R6_EggmanEscape::ObjectStartup()
{
    LoadSpriteSheet("R6/Objects2.gif");
    AddSpriteFrame(-32, -25, 64, 48, 1, 170);
    AddSpriteFrame(-32, -23, 48, 56, 66, 131);
    AddSpriteFrame(-32, -21, 56, 56, 66, 199);
    AddSpriteFrame(-32, -23, 48, 56, 66, 131);
    AddSpriteFrame(-32, -36, 16, 16, 237, 1);
    AddSpriteFrame(-32, -36, 16, 16, 181, 207);
}

void O_R6_EggmanEscape::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        pXPos() = objectEntityList[objectLoop - 1].XPos;
        pSpeed() = 0;
        if (self->values[0] < 120) {
            self->values[0]++;
        } else {
            GVar("Player.Score") += 1000;
            self->values[0] = 0;
            self->priority = 1;
            self->values[1] = 0x8000;
            self->state++;
        }
        break;
        case 1:
        self->values[1] += 0xC00;
        self->XPos += self->values[1];
        if (GetObjectOutOfBounds(objectLoop) == 1) {
            ResetObjectEntity(objectLoop, TypeNameID("Blank Object"), 0, 0, 0);
        }
        break;
    }
}

void O_R6_EggmanEscape::ObjectDraw()
{
    Entity *self = Self();

    scriptEng.tempValue[0] = self->frame;
    scriptEng.tempValue[0] /= 6;
    DrawSprite_Frame(scriptEng.tempValue[0]);
    self->frame++;
    self->frame %= 24;
    scriptEng.tempValue[0] = self->animationTimer;
    scriptEng.tempValue[0] /= 6;
    scriptEng.tempValue[0] += 4;
    scriptEng.tempValue[1] = self->animationTimer;
    scriptEng.tempValue[1] %= 6;
    if (scriptEng.tempValue[1] < 3) {
        DrawSprite_Frame(scriptEng.tempValue[0]);
    }
    self->animationTimer++;
    self->animationTimer %= 12;
}

#endif // RETRO_USE_NATIVE_OBJECTS

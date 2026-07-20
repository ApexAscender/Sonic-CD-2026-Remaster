#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R5_BossSpark.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from BossSpark.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R5_BossSpark::ObjectStartup()
{
    LoadSpriteSheet("R5/Objects2.gif");
    AddSpriteFrame(-2, -4, 16, 8, 131, 155);
    AddSpriteFrame(-2, -4, 16, 8, 131, 164);
    AddSpriteFrame(-2, -4, 16, 8, 131, 173);
    AddSpriteFrame(-2, -4, 16, 8, 131, 182);
    AddSpriteFrame(-2, -4, 16, 8, 148, 182);
}

void O_R5_BossSpark::ObjectMain()
{
    Entity *self = Self();

    self->values[1] -= 0x2000;
    if (self->values[1] < -0x30000) {
        self->values[1] = -0x30000;
    }
    self->XPos += self->values[1];
    if (self->propertyValue == 1) {
        self->values[2] += 0x2000;
        self->YPos += self->values[2];
        if (GetObjectOutOfBounds(objectLoop) == 1) {
            self->type = TypeNameID("Blank Object");
        }
    } else {
        if (self->values[0] < 36) {
            self->values[0]++;
        } else {
            self->type = TypeNameID("Blank Object");
        }
    }
}

void O_R5_BossSpark::ObjectDraw()
{
    Entity *self = Self();

    scriptEng.tempValue[0] = self->frame;
    scriptEng.tempValue[0] >>= 2;
    DrawSprite_Frame(scriptEng.tempValue[0]);
    self->frame++;
    self->frame %= 20;
}

#endif // RETRO_USE_NATIVE_OBJECTS

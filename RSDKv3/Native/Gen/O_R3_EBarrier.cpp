#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R3_EBarrier.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from EBarrier.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R3_EBarrier::ObjectStartup()
{
    LoadSpriteSheet("R3/Objects2.gif");
    AddSpriteFrame(-64, -16, 32, 32, 134, 0);
    AddSpriteFrame(-64, -16, 32, 32, 167, 0);
    AddSpriteFrame(-64, -16, 32, 32, 200, 0);
    AddSpriteFrame(-48, -16, 96, 32, 1, 67);
}

void O_R3_EBarrier::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 1:
        if (self->YPos > 0x5100000) {
            self->YPos -= 0x28000;
        } else {
            self->YPos = 0x5100000;
            self->state = 2;
            HapticEffect_Script(76, 0, 0, 0);
        }
        self->frame++;
        self->frame %= 9;
        break;
        case 2:
        scriptEng.tempValue[0] = self->values[0];
        scriptEng.tempValue[0] &= 3;
        if (scriptEng.tempValue[0] == 0) {
            scriptEng.tempValue[0] = rand() % 96;
            scriptEng.tempValue[0] -= 48;
            scriptEng.tempValue[0] <<= 16;
            scriptEng.tempValue[0] += self->XPos;
            scriptEng.tempValue[1] = rand() % 40;
            scriptEng.tempValue[1] -= 20;
            scriptEng.tempValue[1] <<= 16;
            scriptEng.tempValue[1] += self->YPos;
            CreateTempObject(TypeNameID("Explosion"), 0, scriptEng.tempValue[0], scriptEng.tempValue[1]);
            PlaySfx(22, 0);
        }
        self->values[0]++;
        if (self->values[0] == 120) {
            self->type = TypeNameID("Blank Object");
        }
        break;
    }
}

void O_R3_EBarrier::ObjectPlayerInteraction()
{
    Entity *self = Self();

    if (self->state == 0) {
        PlayerObjectCollision(C_TOUCH, -48, -16, 48, 16);
        if (CheckResult() == 1) {
            self->state = 1;
            pYVel() = 0;
            PlaySfx(22, 0);
        }
    }
}

void O_R3_EBarrier::ObjectDraw()
{
    Entity *self = Self();

    DrawSprite_Frame(3);
    scriptEng.tempValue[0] = self->frame;
    scriptEng.tempValue[0] /= 3;
    DrawSprite_Frame(scriptEng.tempValue[0]);
}

#endif // RETRO_USE_NATIVE_OBJECTS

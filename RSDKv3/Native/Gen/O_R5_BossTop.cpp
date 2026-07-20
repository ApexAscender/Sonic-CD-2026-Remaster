#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R5_BossTop.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from BossTop.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R5_BossTop::ObjectStartup()
{
    LoadSpriteSheet("R5/Objects2.gif");
    AddSpriteFrame(-32, -24, 64, 48, 1, 1);
    AddSpriteFrame(-4, 24, 8, 88, 66, 1);
    AddSpriteFrame(-32, -24, 64, 48, 75, 1);
    AddSpriteFrame(-4, 24, 8, 88, 140, 1);
}

void O_R5_BossTop::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 1:
        if (self->values[0] < 55) {
            self->values[0]++;
            self->values[1] -= 0x20000;
        } else {
            self->state = 2;
        }
        break;
    }
}

void O_R5_BossTop::ObjectPlayerInteraction()
{
    Entity *self = Self();

    if (self->state == 0) {
        scriptEng.tempValue[0] = pCollisionRight();
        scriptEng.tempValue[0] <<= 16;
        scriptEng.tempValue[0] += pXPos();
        scriptEng.tempValue[1] = self->values[1];
        if (scriptEng.tempValue[0] > scriptEng.tempValue[1]) {
            pXVel() = 0;
            pSpeed() = 0;
            pXPos() = scriptEng.tempValue[1];
            scriptEng.tempValue[0] = pCollisionRight();
            scriptEng.tempValue[0] <<= 16;
            pXPos() -= scriptEng.tempValue[0];
        }
    }
}

void O_R5_BossTop::ObjectDraw()
{
    Entity *self = Self();

    if (self->inkEffect == 0) {
        DrawSprite_Frame(0);
        scriptEng.tempValue[0] = self->XPos;
        scriptEng.tempValue[0] -= 0x180000;
        DrawSprite_FrameXY(1, scriptEng.tempValue[0], self->YPos);
        scriptEng.tempValue[0] += 0x300000;
        DrawSprite_FrameXY(1, scriptEng.tempValue[0], self->YPos);
    } else {
        DrawSprite_Frame(0);
        DrawSpriteFX_Script(2, FX_INK, self->XPos, self->YPos);
        scriptEng.tempValue[0] = self->XPos;
        scriptEng.tempValue[0] -= 0x180000;
        DrawSprite_FrameXY(1, scriptEng.tempValue[0], self->YPos);
        DrawSpriteFX_Script(3, FX_INK, scriptEng.tempValue[0], self->YPos);
        scriptEng.tempValue[0] += 0x300000;
        DrawSprite_FrameXY(1, scriptEng.tempValue[0], self->YPos);
        DrawSpriteFX_Script(3, FX_INK, scriptEng.tempValue[0], self->YPos);
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS

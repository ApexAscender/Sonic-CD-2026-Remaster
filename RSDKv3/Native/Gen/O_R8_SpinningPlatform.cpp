#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R8_SpinningPlatform.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from SpinningPlatform.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R8_SpinningPlatform::ObjectStartup()
{
    LoadSpriteSheet("R8/Objects.gif");
    AddSpriteFrame(-16, -8, 32, 16, 107, 98);
    AddSpriteFrame(-16, -12, 32, 24, 107, 115);
    AddSpriteFrame(-12, -16, 24, 32, 230, 34);
    AddSpriteFrame(-8, -16, 16, 32, 239, 212);
    AddSpriteFrame(-12, -16, 24, 32, 230, 34);
    AddSpriteFrame(-16, -12, 32, 24, 107, 115);
}

void O_R8_SpinningPlatform::ObjectMain()
{
    Entity *self = Self();

    self->rotation = objectEntityList[19].rotation;
    self->rotation += self->propertyValue;
    self->rotation %= 144;
}

void O_R8_SpinningPlatform::ObjectPlayerInteraction()
{
    Entity *self = Self();

    if (self->rotation < 121) {
        PlayerObjectCollision(C_PLATFORM, -16, -5, 16, 11);
    }
}

void O_R8_SpinningPlatform::ObjectDraw()
{
    Entity *self = Self();

    if (self->rotation < 121) {
        DrawSprite_Frame(0);
    } else {
        scriptEng.tempValue[0] = self->rotation;
        scriptEng.tempValue[0] -= 120;
        scriptEng.tempValue[0] >>= 1;
        switch (scriptEng.tempValue[0]) {
            case 0:
            case 6:
            DrawSprite_Frame(1);
            break;
            case 1:
            case 7:
            DrawSprite_Frame(2);
            break;
            case 2:
            case 8:
            DrawSprite_Frame(3);
            break;
            case 3:
            case 9:
            self->direction = 1;
            DrawSpriteFX_Script(4, FX_FLIP, self->XPos, self->YPos);
            break;
            case 4:
            case 10:
            self->direction = 1;
            DrawSpriteFX_Script(5, FX_FLIP, self->XPos, self->YPos);
            break;
            case 5:
            case 11:
            DrawSprite_Frame(0);
            break;
        }
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS

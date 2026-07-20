#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R5_ForegroundPiece.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from ForegroundPiece.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R5_ForegroundPiece::ObjectStartup()
{
    LoadSpriteSheet("R5/Objects3.gif");
    AddSpriteFrame(-26, -4, 52, 8, 165, 1);
    AddSpriteFrame(-4, -26, 8, 52, 218, 1);
    AddSpriteFrame(-16, -4, 32, 8, 165, 10);
    AddSpriteFrame(-8, -4, 16, 8, 165, 10);
    AddSpriteFrame(-4, -16, 8, 32, 227, 1);
    AddSpriteFrame(-4, -8, 8, 16, 227, 1);
    AddSpriteFrame(-20, -4, 40, 8, 165, 19);
    AddSpriteFrame(-20, -4, 40, 8, 165, 28);
    AddSpriteFrame(-4, -20, 8, 40, 236, 1);
    AddSpriteFrame(-4, -20, 8, 40, 245, 1);
    AddSpriteFrame(-20, -4, 40, 8, 165, 37);
    AddSpriteFrame(-20, -4, 40, 8, 165, 46);
    AddSpriteFrame(-4, -20, 8, 40, 236, 42);
    AddSpriteFrame(-4, -20, 8, 40, 245, 42);
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Foreground Piece")) {
            objectEntityList[scriptEng.arrayPosition[0]].drawOrder = 4;
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_R5_ForegroundPiece::ObjectDraw()
{
    Entity *self = Self();

    DrawSprite_Frame(self->propertyValue);
}

#endif // RETRO_USE_NATIVE_OBJECTS

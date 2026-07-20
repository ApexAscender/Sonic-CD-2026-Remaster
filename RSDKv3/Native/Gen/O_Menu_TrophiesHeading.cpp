#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_Menu_TrophiesHeading.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from TrophiesHeading.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_Menu_TrophiesHeading::ObjectStartup()
{
    LoadSpriteSheet("Menu/HelpText.gif");
}

void O_Menu_TrophiesHeading::ObjectDraw()
{
    Entity *self = Self();

    scriptEng.tempValue[0] = self->XPos;
    scriptEng.tempValue[0] >>= 16;
    scriptEng.tempValue[0] -= xScrollOffset;
    scriptEng.tempValue[1] = self->YPos;
    scriptEng.tempValue[1] >>= 16;
    scriptEng.tempValue[1] -= yScrollOffset;
    DrawRectangle(0, 0, SCREEN_XSIZE, 47, 255, 255, 255, 255);
    DrawRectangle(0, 46, SCREEN_XSIZE, 1, 128, 128, 128, 128);
    DrawText_Script(0, scriptEng.tempValue[0], scriptEng.tempValue[1], 192, 0, 0, 1);
    scriptEng.tempValue[2]++;
    scriptEng.tempValue[1] += 24;
    DrawText_Script(0, scriptEng.tempValue[0], scriptEng.tempValue[1], 128, 0, 1, 1);
}

#endif // RETRO_USE_NATIVE_OBJECTS

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_Menu_HelpText.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from HelpText.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_Menu_HelpText::ObjectStartup()
{
    LoadSpriteSheet("Menu/HelpText.gif");
}

void O_Menu_HelpText::ObjectDraw()
{
    Entity *self = Self();

    self->drawOrder = 4;
    scriptEng.tempValue[0] = self->XPos;
    scriptEng.tempValue[0] >>= 16;
    scriptEng.tempValue[0] -= xScrollOffset;
    scriptEng.tempValue[1] = self->YPos;
    scriptEng.tempValue[1] >>= 16;
    scriptEng.tempValue[1] -= yScrollOffset;
    if (self->propertyValue == 0) {
        DrawText_Script(0, scriptEng.tempValue[0], scriptEng.tempValue[1], 192, 0, 0, 1);
    } else {
        DrawText_Script(0, scriptEng.tempValue[0], scriptEng.tempValue[1], 114, 41, 1, -1);
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS

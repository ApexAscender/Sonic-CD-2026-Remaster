#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R6_FadeScreen.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from FadeScreen.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R6_FadeScreen::ObjectMain()
{
    Entity *self = Self();

    if (self->state == 0) {
        if (self->values[0] < 320) {
            self->values[0] += 4;
        } else {
            self->state = 1;
            scriptEng.arrayPosition[0] = self->values[1];
            objectEntityList[scriptEng.arrayPosition[0]].type = TypeNameID("Destroyed Mobile");
            objectEntityList[scriptEng.arrayPosition[0]].priority = 0;
            pXPos() = objectEntityList[scriptEng.arrayPosition[0]].XPos;
            xBoundary2 = 3840;
            scriptEng.arrayPosition[0]++;
            ResetObjectEntity(scriptEng.arrayPosition[0], TypeNameID("Eggman Escape"), 0, objectEntityList[scriptEng.arrayPosition[0]].XPos, objectEntityList[scriptEng.arrayPosition[0]].YPos);
        }
    } else {
        if (self->values[0] > 0) {
            self->values[0] -= 4;
        } else {
            self->type = TypeNameID("Blank Object");
            CreateTempObject(TypeNameID("Fade Music"), 1, self->XPos, self->YPos);
        }
    }
    SetFade(224, 224, 224, self->values[0]);
}

#endif // RETRO_USE_NATIVE_OBJECTS

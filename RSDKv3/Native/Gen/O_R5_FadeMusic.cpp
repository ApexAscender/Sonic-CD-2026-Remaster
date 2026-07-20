#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R5_FadeMusic.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from FadeMusic.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R5_FadeMusic::ObjectMain()
{
    Entity *self = Self();

    if (self->propertyValue == 0) {
        if (self->values[0] < 100) {
            self->values[0]++;
            masterVolume--;
        } else {
            PlayMusic(4);
            self->type = TypeNameID("Blank Object");
        }
    } else {
        if (self->values[0] < 100) {
            self->values[0]++;
            masterVolume--;
        } else {
            PlayMusic(0);
            self->type = TypeNameID("Blank Object");
        }
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS

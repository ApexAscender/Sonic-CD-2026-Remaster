#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_FadeMusic.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from FadeMusic.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_FadeMusic::ObjectMain()
{
    Entity *self = Self();

    switch (self->propertyValue) {
        case 0:
        if (self->values[0] < 100) {
            self->values[0]++;
            masterVolume--;
        } else {
            PlayMusic(4);
            self->type = TypeNameID("Blank Object");
        }
        break;
        case 1:
        if (self->values[0] < 100) {
            self->values[0]++;
            masterVolume--;
        } else {
            PlayMusic(0);
            self->type = TypeNameID("Blank Object");
        }
        break;
        case 2:
        if (self->values[0] < 50) {
            self->values[0]++;
            masterVolume -= 2;
        } else {
            PlayMusic(0);
            self->type = TypeNameID("Blank Object");
        }
        break;
        case 3:
        if (self->values[0] < 100) {
            self->values[0]++;
            masterVolume--;
        } else {
            PlayMusic(1);
            self->type = TypeNameID("Blank Object");
            objectEntityList[30].type = TypeNameID("ActFinish");
            objectEntityList[30].drawOrder = 6;
            objectEntityList[30].priority = 1;
        }
        break;
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS

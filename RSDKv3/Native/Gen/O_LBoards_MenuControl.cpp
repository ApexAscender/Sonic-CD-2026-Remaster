#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_LBoards_MenuControl.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from MenuControl.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_LBoards_MenuControl::ObjectStartup()
{
    if (GVar("Options.Soundtrack") == 0) {
        SetMusicTrack_Script("JP/TimeAttack.ogg", 0, 100512);
    } else {
        SetMusicTrack_Script("US/DAGarden.ogg", 0, 117382);
    }
    objectEntityList[0].type = TypeNameID("Menu Control");
    objectEntityList[0].drawOrder = 1;
    GVar("Options.PhysicalControls") = 0;
}

void O_LBoards_MenuControl::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        self->state = 1;
        self->values[0] = 384;
        SetFade(0, 0, 0, 255);
        PlayMusic(0);
        break;
        case 1:
        if (self->values[0] > 0) {
            self->values[0] -= 8;
            self->scale -= 4096;
        } else {
            self->state = 2;
        }
        SetFade(0, 0, 0, self->values[0]);
        break;
        case 2:
        if (keyPress.left == 1) {
            self->state = 3;
            objectEntityList[32].state = 4;
            PlaySfx(23, 0);
        }
        if (keyPress.right == 1) {
            self->state = 3;
            objectEntityList[32].state = 1;
            PlaySfx(23, 0);
        }
        if (keyPress.up == 1) {
            self->state = 3;
            objectEntityList[32].state = 10;
            PlaySfx(23, 0);
        }
        if (keyPress.down == 1) {
            self->state = 3;
            objectEntityList[32].state = 7;
            PlaySfx(23, 0);
        }
        if (keyPress.B == 1) {
            self->state = 4;
            StopMusic();
            PlaySfx(27, 0);
        }
        break;
        case 3:
        break;
        case 4:
        if (self->values[0] < 384) {
            self->values[0] += 8;
            self->scale += 4096;
        } else {
            stageListPosition = 1;
            stageMode = STAGEMODE_LOAD;
        }
        SetFade(0, 0, 0, self->values[0]);
        Engine.Callback(3);
        break;
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS

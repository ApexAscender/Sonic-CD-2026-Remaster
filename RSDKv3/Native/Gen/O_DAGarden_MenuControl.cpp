#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_DAGarden_MenuControl.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from MenuControl.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_DAGarden_MenuControl::ObjectStartup()
{
    SetMusicTrack_Script("JP/DAGarden.ogg", 0, 1);
    SetMusicTrack_Script("US/DAGarden.ogg", 1, 117382);
    objectEntityList[0].type = TypeNameID("Menu Control");
    objectEntityList[0].drawOrder = 1;
    objectEntityList[0].priority = 1;
    objectEntityList[34].type = TypeNameID("Blank Object");
    objectEntityList[35].type = TypeNameID("Blank Object");
    objectEntityList[36].type = TypeNameID("Blank Object");
    objectEntityList[37].type = TypeNameID("Blank Object");
}

void O_DAGarden_MenuControl::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        self->state = 1;
        self->values[0] = 384;
        SetFade(0, 0, 0, 255);
        PlayMusic(GVar("Options.Soundtrack"));
        break;
        case 1:
        if (self->values[0] > 0) {
            self->values[0] -= 8;
        } else {
            self->state = 2;
        }
        SetFade(0, 0, 0, self->values[0]);
        break;
        case 2:
        if (keyPress.start == 1) {
            StopMusic();
            self->state = 6;
        }
        if (keyPress.A == 1) {
            self->state = 3;
            objectEntityList[33].XPos = SCREEN_XSIZE;
            objectEntityList[33].XPos += 96;
            objectEntityList[33].XPos <<= 16;
            objectEntityList[33].state = 1;
            objectEntityList[33].drawOrder = 5;
            objectEntityList[33].priority = 1;
            objectEntityList[35].propertyValue = 4;
            objectEntityList[36].propertyValue = 5;
            objectEntityList[37].propertyValue = 6;
        }
        break;
        case 3:
        if (objectEntityList[33].state == 0) {
            if (keyPress.left == 1) {
                objectEntityList[33].state = 2;
            }
            if (keyPress.right == 1) {
                objectEntityList[33].state = 4;
            }
            if (keyPress.A == 1) {
                self->state = 4;
                StopMusic();
            }
            if (keyPress.B == 1) {
                self->state = 4;
                StopMusic();
            }
            if (keyPress.C == 1) {
                self->state = 4;
                StopMusic();
            }
        }
        if (keyPress.start == 1) {
            StopMusic();
            self->state = 6;
        }
        break;
        case 4:
        if (self->values[0] < 288) {
            self->values[0] += 8;
        } else {
            objectEntityList[33].XPos = SCREEN_XSIZE;
            objectEntityList[33].XPos += 96;
            objectEntityList[33].XPos <<= 16;
            objectEntityList[33].state = 0;
            objectEntityList[33].priority = 0;
            objectEntityList[35].propertyValue = 0;
            objectEntityList[36].propertyValue = 2;
            objectEntityList[37].propertyValue = 7;
            MenuControl_ChangeTrack();
            self->state++;
        }
        SetFade(208, 255, 224, self->values[0]);
        break;
        case 5:
        if (self->values[0] > 0) {
            self->values[0] -= 8;
        } else {
            self->state = 2;
        }
        SetFade(208, 255, 224, self->values[0]);
        break;
        case 6:
        if (self->values[0] < 384) {
            self->values[0] += 8;
        } else {
            stageListPosition = 1;
            stageMode = STAGEMODE_LOAD;
        }
        SetFade(0, 0, 0, self->values[0]);
        break;
    }
}

void O_DAGarden_MenuControl::MenuControl_ChangeTrack()
{
    switch (objectEntityList[33].frame) {
        case 0:
        SetMusicTrack_Script("JP/R1A.ogg", 0, 142428);
        SetMusicTrack_Script("US/R1A.ogg", 1, 153038);
        objectEntityList[32].frame = 0;
        break;
        case 1:
        SetMusicTrack_Script("JP/R1C.ogg", 0, 142902);
        SetMusicTrack_Script("US/R1C.ogg", 1, 152346);
        objectEntityList[32].frame = 11;
        break;
        case 2:
        SetMusicTrack_Script("JP/R1D.ogg", 0, 1);
        SetMusicTrack_Script("US/R1D.ogg", 1, 774998);
        objectEntityList[32].frame = 22;
        break;
        case 3:
        SetMusicTrack_Script("JP/R3A.ogg", 0, 358725);
        SetMusicTrack_Script("US/R3A.ogg", 1, 1);
        objectEntityList[32].frame = 0;
        break;
        case 4:
        SetMusicTrack_Script("JP/R3C.ogg", 0, 1);
        SetMusicTrack_Script("US/R3C.ogg", 1, 173494);
        objectEntityList[32].frame = 11;
        break;
        case 5:
        SetMusicTrack_Script("JP/R3D.ogg", 0, 717648);
        SetMusicTrack_Script("US/R3D.ogg", 1, 1);
        objectEntityList[32].frame = 22;
        break;
        case 6:
        SetMusicTrack_Script("JP/R4A.ogg", 0, 1);
        SetMusicTrack_Script("US/R4A.ogg", 1, 415148);
        objectEntityList[32].frame = 0;
        break;
        case 7:
        SetMusicTrack_Script("JP/R4C.ogg", 0, 1);
        SetMusicTrack_Script("US/R4C.ogg", 1, 1);
        objectEntityList[32].frame = 11;
        break;
        case 8:
        SetMusicTrack_Script("JP/R4D.ogg", 0, 1);
        SetMusicTrack_Script("US/R4D.ogg", 1, 145616);
        objectEntityList[32].frame = 22;
        break;
        case 9:
        SetMusicTrack_Script("JP/R5A.ogg", 0, 1);
        SetMusicTrack_Script("US/R5A.ogg", 1, 1);
        objectEntityList[32].frame = 0;
        break;
        case 10:
        SetMusicTrack_Script("JP/R5C.ogg", 0, 367046);
        SetMusicTrack_Script("US/R5C.ogg", 1, 705830);
        objectEntityList[32].frame = 11;
        break;
        case 11:
        SetMusicTrack_Script("JP/R5D.ogg", 0, 1);
        SetMusicTrack_Script("US/R5D.ogg", 1, 93672);
        objectEntityList[32].frame = 22;
        break;
        case 12:
        SetMusicTrack_Script("JP/R6A.ogg", 0, 1);
        SetMusicTrack_Script("US/R6A.ogg", 1, 926048);
        objectEntityList[32].frame = 0;
        break;
        case 13:
        SetMusicTrack_Script("JP/R6C.ogg", 0, 1);
        SetMusicTrack_Script("US/R6C.ogg", 1, 181704);
        objectEntityList[32].frame = 11;
        break;
        case 14:
        SetMusicTrack_Script("JP/R6D.ogg", 0, 1);
        SetMusicTrack_Script("US/R6D.ogg", 1, 45355);
        objectEntityList[32].frame = 22;
        break;
        case 15:
        SetMusicTrack_Script("JP/R7A.ogg", 0, 1);
        SetMusicTrack_Script("US/R7A.ogg", 1, 617728);
        objectEntityList[32].frame = 0;
        break;
        case 16:
        SetMusicTrack_Script("JP/R7C.ogg", 0, 103060);
        SetMusicTrack_Script("US/R7C.ogg", 1, 136670);
        objectEntityList[32].frame = 11;
        break;
        case 17:
        SetMusicTrack_Script("JP/R7D.ogg", 0, 1);
        SetMusicTrack_Script("US/R7D.ogg", 1, 92324);
        objectEntityList[32].frame = 22;
        break;
        case 18:
        SetMusicTrack_Script("JP/R8A.ogg", 0, 146030);
        SetMusicTrack_Script("US/R8A.ogg", 1, 1);
        objectEntityList[32].frame = 0;
        break;
        case 19:
        SetMusicTrack_Script("JP/R8C.ogg", 0, 1);
        SetMusicTrack_Script("US/R8C.ogg", 1, 1);
        objectEntityList[32].frame = 11;
        break;
        case 20:
        SetMusicTrack_Script("JP/R8D.ogg", 0, 1);
        SetMusicTrack_Script("US/R8D.ogg", 1, 563962);
        objectEntityList[32].frame = 22;
        break;
        case 21:
        SetMusicTrack_Script("JP/FinalBoss.ogg", 0, 1);
        SetMusicTrack_Script("US/FinalBoss.ogg", 1, 1);
        objectEntityList[32].frame = 0;
        break;
        case 22:
        SetMusicTrack_Script("JP/DAGarden.ogg", 0, 1);
        SetMusicTrack_Script("US/DAGarden.ogg", 1, 117382);
        objectEntityList[32].frame = 0;
        break;
        case 23:
        SetMusicTrack_Script("JP/GameOver.ogg", 0, 0);
        SetMusicTrack_Script("US/GameOver.ogg", 1, 0);
        objectEntityList[32].frame = 0;
        break;
        case 24:
        SetMusicTrack_Script("JP/ZoneComplete.ogg", 0, 0);
        SetMusicTrack_Script("US/ZoneComplete.ogg", 1, 0);
        objectEntityList[32].frame = 0;
        break;
        case 25:
        SetMusicTrack_Script("JP/Boss.ogg", 0, 1);
        SetMusicTrack_Script("US/Boss.ogg", 1, 196526);
        objectEntityList[32].frame = 0;
        break;
        case 26:
        SetMusicTrack_Script("JP/Invincibility.ogg", 0, 0);
        SetMusicTrack_Script("US/Invincibility.ogg", 1, 0);
        objectEntityList[32].frame = 0;
        break;
        case 27:
        SetMusicTrack_Script("JP/SpeedShoes.ogg", 0, 0);
        SetMusicTrack_Script("US/SpeedShoes.ogg", 1, 0);
        objectEntityList[32].frame = 0;
        break;
        case 28:
        SetMusicTrack_Script("JP/TitleScreen.ogg", 0, 0);
        SetMusicTrack_Script("US/TitleScreen.ogg", 1, 0);
        objectEntityList[32].frame = 0;
        break;
        case 29:
        SetMusicTrack_Script("JP/SpecialStage.ogg", 0, 1);
        SetMusicTrack_Script("US/SpecialStage.ogg", 1, 270972);
        objectEntityList[32].frame = 0;
        break;
        case 30:
        SetMusicTrack_Script("JP/TimeAttack.ogg", 0, 100512);
        SetMusicTrack_Script("US/DAGarden.ogg", 1, 117382);
        objectEntityList[32].frame = 0;
        break;
    }
    PlayMusic(GVar("Options.Soundtrack"));
}

const Native::NativeFunctionDef O_DAGarden_MenuControl::funcs[1] = {
    { "MenuControl_ChangeTrack", O_DAGarden_MenuControl::MenuControl_ChangeTrack },
};

#endif // RETRO_USE_NATIVE_OBJECTS

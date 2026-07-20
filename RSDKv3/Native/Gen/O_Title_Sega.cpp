#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_Title_Sega.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from Sega.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_Title_Sega::ObjectStartup()
{
    LoadSpriteSheet("Title/Sega.gif");
    AddSpriteFrame(-255, -87, 510, 174, 1, 1);
}

void O_Title_Sega::ObjectMain()
{
    Entity *self = Self();

    // SonicCD-Native remaster: the Sega + Christian Whitehead (CWLogo) splash
    // screens are replaced by the boot video (videos/intro.mp4), so this seed
    // object skips both and hands straight to the title. It keeps the one-time
    // save/audio init the original SEGA_SETUP did, then morphs into "Sonic"
    // (which chains Sonic -> Logo and spawns Background/Clouds) exactly as the
    // original CWLogo end-state did.
    CheckResult() = ReadSaveRAMData();
    if (saveRAM[32] == 1) {
        bgmVolume = saveRAM[33];
        sfxVolume = saveRAM[34];
    }
    GVar("Options.Soundtrack") = saveRAM[38];

    self->XPos = (SCREEN_CENTERX) << 16;
    ResetObjectEntity(objectLoop, TypeNameID("Sonic"), 0, self->XPos, self->YPos);
    self->inkEffect = 2; // INK_ALPHA
    self->alpha     = 0;
    self->values[0] = 0;
    self->values[1] = 256;
    Engine.gameMode = 6; // ENGINE_EXIT_HIRESMODE: title runs in normal resolution
}

void O_Title_Sega::ObjectDraw()
{
    Entity *self = Self();

    DrawRectangle(0, 0, SCREEN_XSIZE, SCREEN_YSIZE, 0, 0, 96, 255);
    self->scale = 128;
    DrawSpriteFX_Script(0, FX_SCALE, self->XPos, self->YPos);
    DrawRectangle(0, 0, SCREEN_XSIZE, SCREEN_YSIZE, 0, 0, 96, self->values[1]);
}

#endif // RETRO_USE_NATIVE_OBJECTS

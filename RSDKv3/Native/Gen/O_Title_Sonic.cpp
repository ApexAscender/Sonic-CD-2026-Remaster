#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_Title_Sonic.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from Sonic.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_Title_Sonic::ObjectStartup()
{
    SetMusicTrack_Script("JP/TitleScreen.ogg", 0, 0);
    SetMusicTrack_Script("US/TitleScreen.ogg", 1, 0);
    LoadSpriteSheet("Title/Title.gif");
    AddSpriteFrame(-47, -89, 96, 112, 1, 203);
    AddSpriteFrame(-47, -89, 104, 120, 98, 203);
    AddSpriteFrame(-47, -96, 96, 120, 1, 316);
    AddSpriteFrame(-47, -96, 104, 120, 98, 324);
    AddSpriteFrame(-47, -96, 104, 120, 1, 1);
    AddSpriteFrame(0, 0, 45, 55, 210, 203);
}

void O_Title_Sonic::ObjectDraw()
{
    Entity *self = Self();

    DrawRectangle(0, 0, SCREEN_XSIZE, SCREEN_YSIZE, 0, 0, 96, 255);
    switch (self->state) {
        case 0:
        if (self->alpha > 8) {
            DrawSpriteFX_Script(0, FX_INK, self->XPos, self->YPos);
        }
        if (self->values[0] < 256) {
            self->values[0] += 8;
            if (self->values[0] < 256) {
                self->alpha = self->values[0];
            } else {
                self->alpha = 255;
            }
        } else {
            if (self->values[0] < 272) {
                self->values[0]++;
            } else {
                self->values[0] = 0;
                self->state = 1;
                GVar("LampPost.Check") = 0;
                pControlMode() = 0;
                playerListPos = 0;
                PlayMusic(GVar("Options.Soundtrack"));
            }
        }
        break;
        case 1:
        scriptEng.tempValue[0] = self->values[0];
        scriptEng.tempValue[0] >>= 2;
        DrawSprite_Frame(scriptEng.tempValue[0]);
        scriptEng.tempValue[0] = 11;
        scriptEng.tempValue[0] += SCREEN_CENTERX;
        if (self->values[0] > 15) {
            DrawSprite_ScreenXY(5, scriptEng.tempValue[0], 72);
        }
        self->values[0]++;
        if (self->values[0] > 19) {
            ResetObjectEntity(objectLoop, TypeNameID("Logo"), 0, self->XPos, self->YPos);
            self->values[0] = 256;
            scriptEng.arrayPosition[0] = objectLoop;
            scriptEng.arrayPosition[0] -= 2;
            objectEntityList[scriptEng.arrayPosition[0]].type = TypeNameID("Background");
            objectEntityList[scriptEng.arrayPosition[0]].drawOrder = 0;
            activeTileLayers[2] = 9;
            scriptEng.arrayPosition[0]++;
            objectEntityList[scriptEng.arrayPosition[0]].type = TypeNameID("Clouds");
        }
        break;
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS

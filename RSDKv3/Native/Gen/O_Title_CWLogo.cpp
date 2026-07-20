#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_Title_CWLogo.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from CWLogo.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_Title_CWLogo::ObjectStartup()
{
    LoadSpriteSheet("Title/CWLogo.gif");
    AddSpriteFrame(-255, -117, 510, 235, 1, 1);
    AddSpriteFrame(-32, -32, 64, 64, 1, 1);
}

void O_Title_CWLogo::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        self->rotation = 0;
        self->values[2] = 0;
        self->state++;
        break;
        case 1:
        if (self->values[2] < 2048) {
            if (self->values[2] < 2048) {
                self->values[2] += 64;
            } else {
                self->values[2] += 128;
            }
        } else {
            self->values[1] = 256;
            self->state++;
        }
        self->rotation += 8;
        self->rotation &= 511;
        break;
        case 2:
        if (self->values[2] < 4096) {
            if (self->values[2] < 2048) {
                self->values[2] += 64;
            } else {
                self->values[2] += 128;
            }
            self->rotation += 8;
            self->rotation &= 511;
        }
        if (self->values[1] > 0) {
            self->values[1] -= 8;
        } else {
            self->state++;
        }
        break;
        case 3:
        if (self->values[0] < 144) {
            self->values[0]++;
        } else {
            self->values[0] = 0;
            self->values[3] = 0;
            self->state++;
        }
        break;
        case 4:
        if (self->values[2] > 0) {
            if (self->values[2] < 2048) {
                self->values[2] -= 64;
            } else {
                self->values[2] -= 128;
            }
            self->rotation -= 8;
            if (self->rotation < 0) {
                self->rotation += 512;
            }
        }
        if (self->values[1] < 256) {
            self->values[1] += 10;
        } else {
            self->state++;
            self->values[1] = 256;
        }
        break;
        case 5:
        if (self->values[2] > 0) {
            if (self->values[2] < 2048) {
                self->values[2] -= 64;
            } else {
                self->values[2] -= 128;
            }
            self->rotation -= 8;
            if (self->rotation < 0) {
                self->rotation += 512;
            }
        } else {
            if (self->values[0] == 16) {
                ResetObjectEntity(objectLoop, TypeNameID("Sonic"), 0, self->XPos, self->YPos);
                self->inkEffect = 2;
                self->alpha = 0;
                self->values[0] = 0;
                Engine.gameMode = 6;
                self->values[1] = 256;
            } else {
                self->values[0]++;
            }
        }
        break;
    }
    if (RETRO_GAMEPLATFORMID == 6) {
        if (keyPress.B == 1) {
            Engine.Callback(7);
        }
    }
}

void O_Title_CWLogo::ObjectDraw()
{
    Entity *self = Self();

    DrawRectangle(0, 0, SCREEN_XSIZE, SCREEN_YSIZE, 0, 0, 96, 255);
    self->scale = self->values[2];
    DrawSpriteFX_Script(1, FX_ROTOZOOM, self->XPos, self->YPos);
    self->rotation += 64;
    DrawSpriteFX_Script(1, FX_ROTOZOOM, self->XPos, self->YPos);
    self->rotation -= 64;
    switch (self->state) {
        case 2:
        case 3:
        case 4:
        self->scale = 192;
        DrawSpriteFX_Script(0, FX_SCALE, self->XPos, self->YPos);
        scriptEng.tempValue[0] = SCREEN_CENTERX;
        scriptEng.tempValue[0] -= 96;
        scriptEng.tempValue[1] = SCREEN_CENTERY;
        scriptEng.tempValue[1] -= 48;
        DrawRectangle(scriptEng.tempValue[0], scriptEng.tempValue[1], 192, 96, 255, 149, 18, self->values[1]);
        break;
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS

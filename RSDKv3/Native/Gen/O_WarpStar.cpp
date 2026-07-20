#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_WarpStar.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from WarpStar.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_WarpStar::ObjectStartup()
{
    LoadSpriteSheet("Global/Items3.gif");
    AddSpriteFrame(-16, -16, 32, 32, 50, 133);
    AddSpriteFrame(-16, -16, 32, 32, 50, 166);
    AddSpriteFrame(-24, -24, 48, 48, 1, 197);
    AddSpriteFrame(-16, -16, 32, 32, 50, 199);
    AddSpriteFrame(-12, -12, 24, 24, 148, 152);
}

void O_WarpStar::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        GVar("Warp.Count")++;
        if (GVar("Warp.Count") > 2) {
            GVar("Warp.Count") = 0;
        }
        self->values[0]--;
        if (self->values[0] < 1) {
            if (GVar("Warp.Timer") > 0) {
                GVar("Warp.Frame") = self->frame;
                self->state = 1;
                self->inkEffect = 2;
                self->alpha = 255;
                CreateTempObject(TypeNameID("Warp Star"), 0, pXPos(), pYPos());
                if (pSpeed() < 0) {
                    objectEntityList[scriptEng.arrayPosition[2]].values[0] = pSpeed();
                    objectEntityList[scriptEng.arrayPosition[2]].values[0] = -objectEntityList[scriptEng.arrayPosition[2]].values[0];
                } else {
                    objectEntityList[scriptEng.arrayPosition[2]].values[0] = pSpeed();
                }
                objectEntityList[scriptEng.arrayPosition[2]].values[0] >>= 19;
                objectEntityList[scriptEng.arrayPosition[2]].values[0] += 7;
                objectEntityList[scriptEng.arrayPosition[2]].drawOrder = 4;
                objectEntityList[scriptEng.arrayPosition[2]].frame = self->frame;
            } else {
                self->type = TypeNameID("Blank Object");
            }
        } else {
            if (GVar("Warp.Timer") == 0) {
                self->type = TypeNameID("Blank Object");
            }
        }
        break;
        case 1:
        self->values[0]++;
        self->alpha -= 8;
        if (self->values[0] == 16) {
            self->type = TypeNameID("Blank Object");
        }
        break;
        case 2:
        self->values[2] += 0x3000;
        self->YPos += self->values[2];
        self->values[0]++;
        if (self->values[0] == self->values[1]) {
            self->type = TypeNameID("Blank Object");
        }
        break;
    }
}

void O_WarpStar::ObjectDraw()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        if (GVar("Warp.Timer") > 0) {
            DrawSprite_Frame(self->frame);
        }
        self->frame++;
        self->frame &= 3;
        break;
        case 1:
        if (GVar("Warp.Count") != 2) {
            if (GVar("Warp.Timer") > 0) {
                DrawSpriteFX_Script(GVar("Warp.Frame"), FX_INK, self->XPos, self->YPos);
            }
        }
        break;
        case 2:
        scriptEng.tempValue[0] = self->frame;
        scriptEng.tempValue[0] >>= 1;
        DrawSprite_Frame(scriptEng.tempValue[0]);
        self->frame++;
        self->frame &= 7;
        break;
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS

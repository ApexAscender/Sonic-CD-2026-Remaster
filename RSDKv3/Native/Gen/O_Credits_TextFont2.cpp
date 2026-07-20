#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_Credits_TextFont2.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from TextFont2.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_Credits_TextFont2::ObjectStartup()
{
    LoadSpriteSheet("Menu/CreditsText.gif");
    AddSpriteFrame(-3, -9, 8, 16, 37, 35);
    scriptEng.tempValue[1] = 52;
    while (scriptEng.tempValue[1] < 74) {
        scriptEng.tempValue[0] = 1;
        while (scriptEng.tempValue[0] < 127) {
            AddSpriteFrame(-3, -5, 8, 10, scriptEng.tempValue[0], scriptEng.tempValue[1]);
            scriptEng.tempValue[0] += 9;
        }
        scriptEng.tempValue[1] += 11;
    }
    scriptEng.tempValue[0] = 1;
    while (scriptEng.tempValue[0] < 37) {
        AddSpriteFrame(-3, -5, 8, 10, scriptEng.tempValue[0], scriptEng.tempValue[1]);
        scriptEng.tempValue[0] += 9;
    }
    AddSpriteFrame(-3, -8, 8, 13, 37, 74);
    AddSpriteFrame(-3, -8, 8, 13, 46, 74);
    AddSpriteFrame(-3, -8, 8, 13, 55, 74);
    AddSpriteFrame(-3, -8, 8, 13, 64, 74);
}

void O_Credits_TextFont2::ObjectDraw()
{
    Entity *self = Self();

    scriptEng.arrayPosition[0] = 3;
    scriptEng.tempValue[1] = GetTextInfo_Script(0, 1, self->values[1], 0);
    scriptEng.tempValue[1] -= 3;
    scriptEng.tempValue[2] = scriptEng.tempValue[1];
    scriptEng.tempValue[2] <<= 18;
    scriptEng.tempValue[2] = -scriptEng.tempValue[2];
    scriptEng.tempValue[2] += self->XPos;
    while (scriptEng.tempValue[1] > 0) {
        scriptEng.tempValue[0] = GetTextInfo_Script(0, 0, self->values[1], scriptEng.arrayPosition[0]);
        switch (scriptEng.tempValue[0]) {
            default:
            self->frame = 0;
            if (scriptEng.tempValue[0] > 64) {
                if (scriptEng.tempValue[0] < 91) {
                    self->frame = scriptEng.tempValue[0];
                    self->frame -= 64;
                }
            }
            if (scriptEng.tempValue[0] > 96) {
                if (scriptEng.tempValue[0] < 123) {
                    self->frame = scriptEng.tempValue[0];
                    self->frame -= 96;
                }
            }
            if (self->frame > 0) {
                DrawSprite_FrameXY(self->frame, scriptEng.tempValue[2], self->YPos);
            }
            break;
            case 38:
            DrawSprite_FrameXY(32, scriptEng.tempValue[2], self->YPos);
            break;
            case 39:
            DrawSprite_FrameXY(30, scriptEng.tempValue[2], self->YPos);
            break;
            case 44:
            DrawSprite_FrameXY(28, scriptEng.tempValue[2], self->YPos);
            break;
            case 46:
            DrawSprite_FrameXY(27, scriptEng.tempValue[2], self->YPos);
            break;
            case 47:
            DrawSprite_FrameXY(31, scriptEng.tempValue[2], self->YPos);
            break;
            case 58:
            DrawSprite_FrameXY(29, scriptEng.tempValue[2], self->YPos);
            break;
            case 225:
            DrawSprite_FrameXY(33, scriptEng.tempValue[2], self->YPos);
            break;
            case 233:
            DrawSprite_FrameXY(34, scriptEng.tempValue[2], self->YPos);
            break;
            case 243:
            DrawSprite_FrameXY(35, scriptEng.tempValue[2], self->YPos);
            break;
            case 250:
            DrawSprite_FrameXY(36, scriptEng.tempValue[2], self->YPos);
            break;
        }
        scriptEng.arrayPosition[0]++;
        scriptEng.tempValue[1]--;
        scriptEng.tempValue[2] += 0x80000;
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS

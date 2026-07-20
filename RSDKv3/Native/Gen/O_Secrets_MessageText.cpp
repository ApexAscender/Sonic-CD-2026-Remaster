#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_Secrets_MessageText.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from MessageText.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_Secrets_MessageText::ObjectStartup()
{
    LoadSpriteSheet("Secrets/SecretMenus.gif");
    AddSpriteFrame(0, 0, 0, 0, 0, 0);
    scriptEng.tempValue[1] = 49;
    while (scriptEng.tempValue[1] < 100) {
        scriptEng.tempValue[0] = 37;
        while (scriptEng.tempValue[0] < 136) {
            AddSpriteFrame(-3, -6, 8, 16, scriptEng.tempValue[0], scriptEng.tempValue[1]);
            scriptEng.tempValue[0] += 9;
        }
        scriptEng.tempValue[1] += 17;
    }
}

void O_Secrets_MessageText::ObjectDraw()
{
    Entity *self = Self();

    scriptEng.arrayPosition[0] = 0;
    scriptEng.tempValue[1] = GetTextInfo_Script(0, 1, self->values[1], 0);
    scriptEng.tempValue[2] = scriptEng.tempValue[1];
    scriptEng.tempValue[2] <<= 18;
    scriptEng.tempValue[2] = -scriptEng.tempValue[2];
    scriptEng.tempValue[2] += self->XPos;
    while (scriptEng.tempValue[1] > 0) {
        scriptEng.tempValue[0] = GetTextInfo_Script(0, 0, self->values[1], scriptEng.arrayPosition[0]);
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
        scriptEng.arrayPosition[0]++;
        scriptEng.tempValue[1]--;
        scriptEng.tempValue[2] += 0x80000;
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS

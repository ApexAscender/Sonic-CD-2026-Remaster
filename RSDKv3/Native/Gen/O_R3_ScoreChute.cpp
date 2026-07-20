#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R3_ScoreChute.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from ScoreChute.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R3_ScoreChute::ObjectStartup()
{
    LoadSpriteSheet("R3/Objects.gif");
    AddSpriteFrame(-24, -8, 48, 16, 117, 233);
    if (playerListPos == 0) {
        AddSpriteFrame(-16, -24, 32, 16, 2, 240);
        AddSpriteFrame(-8, -16, 16, 8, 35, 241);
    } else {
        AddSpriteFrame(-12, -20, 24, 12, 228, 244);
        AddSpriteFrame(-8, -16, 16, 8, 211, 247);
    }
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Score Chute")) {
            objectEntityList[scriptEng.arrayPosition[0]].drawOrder = 4;
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_R3_ScoreChute::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 1:
        if (self->values[0] < 8) {
            self->values[0]++;
            pXPos() = self->XPos;
            pYPos() = self->YPos;
            pYPos() -= 0x80000;
            pYVel() = 0;
            pXVel() = 0;
            pSpeed() = 0;
        } else {
            self->state = 2;
            self->values[0] = 0;
            pYVel() = 0;
            pXVel() = 0;
            pVisible() = 0;
            if (PlayerValue(5) > 0) {
                PlayerValue(4) = 0;
                PlayerValue(5) = 0;
            }
            pState() = PlayerStateID("Player_State_Static");
        }
        break;
        case 2:
        if (self->values[0] < 8) {
            self->values[0]++;
            pXPos() = self->XPos;
            pYPos() = self->YPos;
            pYPos() -= 0x80000;
        } else {
            self->state = 3;
            self->values[0] = 0;
        }
        break;
        case 3:
        if (self->values[0] < 4) {
            self->values[0]++;
        } else {
            self->state = 4;
            self->values[0] = 0;
        }
        if (pState() == PlayerStateID("Player_State_Death")) {
            self->state = 7;
            self->values[0] = 0;
            pVisible() = 1;
        }
        break;
        case 4:
        if (self->values[1] < 4) {
            if (self->values[0] == 32) {
                CreateTempObject(TypeNameID("Object Score"), 0, self->XPos, self->YPos);
                GVar("Player.Score") += 100;
            }
        }
        if (self->values[1] < 3) {
            if (self->values[0] == 64) {
                CreateTempObject(TypeNameID("Object Score"), 0, self->XPos, self->YPos);
                GVar("Player.Score") += 100;
            }
        }
        if (self->values[0] < 80) {
            self->values[0]++;
        } else {
            self->state = 5;
            self->values[0] = 0;
        }
        if (pState() == PlayerStateID("Player_State_Death")) {
            self->state = 7;
            self->values[0] = 0;
            pVisible() = 1;
        }
        break;
        case 5:
        if (self->values[0] < 4) {
            self->values[0]++;
        } else {
            self->state = 6;
            self->values[0] = 0;
        }
        if (pState() == PlayerStateID("Player_State_Death")) {
            self->state = 7;
            self->values[0] = 0;
            pVisible() = 1;
        }
        break;
        case 6:
        if (self->values[0] < 8) {
            self->values[0]++;
        } else {
            self->state = 7;
            self->values[0] = 0;
            pState() = PlayerStateID("Player_State_Air");
            pVisible() = 1;
            pAnimation() = GVar("ANI_JUMPING");
            pObjectInteractions() = 1;
            pYVel() = -0x74000;
            pTimer() = 0;
            PlaySfx(globalSFXCount + 3, 0);
        }
        break;
        case 7:
        if (self->values[0] < 120) {
            self->values[0]++;
        } else {
            self->state = 0;
            self->values[0] = 0;
            self->values[1]++;
        }
        break;
    }
    if (GetObjectOutOfBounds(objectLoop) == 1) {
        self->values[1] = 0;
        self->priority = 0;
    }
}

void O_R3_ScoreChute::ObjectPlayerInteraction()
{
    Entity *self = Self();

    if (self->state == 0) {
        if (pYVel() >= 0) {
            PlayerObjectCollision(C_TOUCH, -16, -8, 16, 16);
            if (CheckResult() == 1) {
                self->state = 1;
                self->priority = 1;
                pAnimation() = GVar("ANI_JUMPING");
                pObjectInteractions() = 0;
                PlaySfx(globalSFXCount + 2, 0);
                HapticEffect_Script(55, 0, 0, 0);
            }
        }
    }
}

void O_R3_ScoreChute::ObjectDraw()
{
    Entity *self = Self();

    switch (self->state) {
        case 1:
        DrawSprite_Frame(0);
        break;
        case 2:
        DrawSprite_Frame(0);
        DrawSprite_Frame(1);
        break;
        case 3:
        DrawSprite_Frame(0);
        DrawSprite_Frame(2);
        break;
        case 4:
        scriptEng.tempValue[0] = self->values[0];
        scriptEng.tempValue[0] &= 7;
        scriptEng.tempValue[0] >>= 2;
        if (scriptEng.tempValue[0] > 0) {
            DrawSprite_Frame(0);
        }
        break;
        case 5:
        DrawSprite_Frame(0);
        DrawSprite_Frame(2);
        break;
        case 6:
        DrawSprite_Frame(0);
        DrawSprite_Frame(1);
        break;
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS

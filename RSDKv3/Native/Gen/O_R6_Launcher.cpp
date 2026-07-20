#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R6_Launcher.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from Launcher.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R6_Launcher::ObjectStartup()
{
    LoadSpriteSheet("R6/Objects.gif");
    AddSpriteFrame(-28, -28, 56, 32, 83, 1);
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Launcher")) {
            objectEntityList[scriptEng.arrayPosition[0]].values[1] = objectEntityList[scriptEng.arrayPosition[0]].XPos;
            objectEntityList[scriptEng.arrayPosition[0]].drawOrder = 4;
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_R6_Launcher::ObjectMain()
{
    Entity *self = Self();

    if (pState() != PlayerStateID("Player_State_Static")) {
        self->state = 0;
        self->values[0] = 0;
    }
    switch (self->state) {
        case 1:
        self->XPos += 0xC0000;
        pXPos() = self->XPos;
        pYPos() = (pCollisionBottom()) << 16;
        pYPos() = -pYPos();
        pYPos() -= 0x30000;
        pYPos() += self->YPos;
        ObjectTileGrip_Script(0, 32, 4, 0);
        if (CheckResult() == 0) {
            self->state++;
        }
        break;
        case 2:
        pXPos() += 0xC0000;
        pYPos() = (pCollisionBottom()) << 16;
        pYPos() = -pYPos();
        pYPos() -= 0x30000;
        pYPos() += self->YPos;
        self->state++;
        break;
        case 3:
        if (self->values[0] == 0) {
            pXPos() += 0xC0000;
        }
        pState() = PlayerStateID("Player_State_Air");
        pAnimation() = GVar("ANI_WALKING");
        pSpeed() = 0xC2000;
        pXVel() = 0xC2000;
        pYPos() = (pCollisionBottom()) << 16;
        pYPos() = -pYPos();
        pYPos() -= 0x30000;
        pYPos() += self->YPos;
        if (self->values[0] < 2) {
            self->values[0]++;
        } else {
            self->state++;
        }
        self->XPos -= 0x40000;
        if (self->XPos < self->values[1]) {
            self->XPos = self->values[1];
            self->priority = 0;
            self->state = 0;
        }
        if (GetObjectOutOfBounds(objectLoop) == 1) {
            self->XPos = self->values[1];
            self->priority = 0;
            self->state = 0;
        }
        break;
        case 4:
        self->XPos -= 0x40000;
        if (self->XPos < self->values[1]) {
            self->XPos = self->values[1];
            self->priority = 0;
            self->state = 0;
        }
        if (GetObjectOutOfBounds(objectLoop) == 1) {
            self->XPos = self->values[1];
            self->priority = 0;
            self->state = 0;
        }
        break;
    }
}

void O_R6_Launcher::ObjectPlayerInteraction()
{
    Entity *self = Self();

    if (self->state == 0) {
        PlayerObjectCollision(C_BOX, -24, -26, -18, 4);
        PlayerObjectCollision(C_TOUCH, -20, -16, 20, 4);
        if (CheckResult() == 1) {
            self->state = 1;
            pState() = PlayerStateID("Player_State_Static");
            pAnimation() = GVar("ANI_LAUNCHER");
            pDirection() = 0;
            pXPos() = self->XPos;
            pYPos() = (pCollisionBottom()) << 16;
            pYPos() = -pYPos();
            pYPos() -= 0x30000;
            pYPos() += self->YPos;
            pYVel() = 0;
            self->priority = 1;
            pTrackScroll() = 0;
            pGravity() = 1;
            PlaySfx(globalSFXCount + 6, 0);
            HapticEffect_Script(30, 0, 0, 0);
        }
    }
}

void O_R6_Launcher::ObjectDraw()
{
    DrawSprite_Frame(0);
}

#endif // RETRO_USE_NATIVE_OBJECTS

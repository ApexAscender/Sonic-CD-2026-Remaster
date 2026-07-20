#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_BrokenMonitor.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from BrokenMonitor.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_BrokenMonitor::ObjectStartup()
{
    LoadSpriteSheet("Global/Items.gif");
    AddSpriteFrame(-16, 0, 32, 16, 51, 166);
    AddSpriteFrame(-8, -8, 16, 16, 26, 7);
    AddSpriteFrame(-8, -8, 16, 16, 26, 40);
    AddSpriteFrame(-8, -8, 16, 16, 26, 73);
    AddSpriteFrame(-8, -8, 16, 16, 26, 106);
    AddSpriteFrame(-8, -8, 16, 16, 26, 139);
    AddSpriteFrame(-8, -8, 16, 16, 26, 172);
    AddSpriteFrame(-8, -8, 16, 16, 59, 106);
    AddSpriteFrame(-8, -8, 16, 16, 59, 139);
}

void O_BrokenMonitor::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        if (self->values[1] < 0) {
            self->values[0] += self->values[1];
            self->values[1] += 0x1800;
        } else {
            self->values[1] = 0;
        }
        if (self->values[1] == 0) {
            self->state = 1;
            self->inkEffect = 2;
            switch (self->propertyValue) {
                case 1:
                PlayerValue(0) += 10;
                if (GVar("Ring.Pan") == 0) {
                    SetSfxAttributes(1, -1, -100);
                    GVar("Ring.Pan") = 1;
                } else {
                    SetSfxAttributes(2, -1, 100);
                    GVar("Ring.Pan") = 0;
                }
                if (PlayerValue(0) > 999) {
                    PlayerValue(0) = 999;
                }
                if (PlayerValue(0) >= GVar("Ring.ExtraLife")) {
                    if (GVar("Options.GameMode") != 2) {
                        GVar("Player.Lives")++;
                        if (playerListPos == 0) {
                            PlaySfx(20, 0);
                        } else {
                            PlaySfx(21, 0);
                        }
                    }
                    GVar("Ring.ExtraLife") += 100;
                    if (GVar("Ring.ExtraLife") > 300) {
                        GVar("Ring.ExtraLife") = 1000;
                    }
                    if (PlayerValue(0) >= 200) {
                        if (playerListPos == 0) {
                            if (debugMode == 0) {
                                SetAchievement(4, 100);
                            }
                        }
                    }
                }
                break;
                case 2:
                PlaySfx(10, 0);
                objectEntityList[2].propertyValue = 1;
                if (objectEntityList[2].type != TypeNameID("Invincibility")) {
                    objectEntityList[2].type = TypeNameID("Blue Shield");
                    objectEntityList[2].priority = 1;
                    objectEntityList[2].drawOrder = 4;
                    objectEntityList[2].inkEffect = 2;
                    objectEntityList[2].alpha = 160;
                    objectEntityList[2].XPos = pXPos();
                    objectEntityList[2].YPos = pYPos();
                }
                break;
                case 3:
                objectEntityList[2].type = TypeNameID("Invincibility");
                objectEntityList[2].priority = 1;
                objectEntityList[2].drawOrder = 4;
                objectEntityList[2].XPos = pXPos();
                objectEntityList[2].YPos = pYPos();
                if (GVar("Options.Soundtrack") == 0) {
                    PlayerValue(4) = 0x4EC;
                } else {
                    PlayerValue(4) = 0x528;
                }
                PlayerValue(5) = 0;
                pVisible() = 1;
                PlayMusic(2);
                break;
                case 4:
                PlayMusic(3);
                pAccel() = 0x1800;
                pAirAccel() = 0x3000;
                pTopSpeed() = 0xC0000;
                PlayerValue(3) = 0x528;
                break;
                case 5:
                GVar("Player.Lives")++;
                PlaySfx(20, 0);
                break;
                case 6:
                break;
                case 7:
                GVar("Player.Lives")++;
                PlaySfx(21, 0);
                break;
                case 8:
                objectEntityList[2].type = TypeNameID("Invincibility");
                objectEntityList[2].priority = 1;
                objectEntityList[2].drawOrder = 4;
                objectEntityList[2].XPos = pXPos();
                objectEntityList[2].YPos = pYPos();
                PlayerValue(4) = 0x528;
                PlayerValue(5) = 0;
                pVisible() = 1;
                pAccel() = 0x1800;
                pAirAccel() = 0x3000;
                pTopSpeed() = 0xC0000;
                PlayerValue(3) = 0x528;
                break;
            }
        }
        break;
        case 1:
        self->values[1]++;
        if (self->values[1] == 30) {
            self->values[1] = 0;
            self->state = 2;
            self->propertyValue = 0;
            self->priority = 0;
        } else {
            if (self->values[1] > 14) {
                self->alpha -= 16;
            }
        }
        break;
        case 2:
        break;
    }
}

void O_BrokenMonitor::ObjectDraw()
{
    Entity *self = Self();

    DrawSprite_Frame(0);
    if (self->propertyValue > 0) {
        DrawSpriteFX_Script(self->propertyValue, FX_INK, self->XPos, self->values[0]);
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS

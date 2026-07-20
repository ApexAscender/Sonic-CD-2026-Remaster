#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_Menu_TrophieList.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from TrophieList.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_Menu_TrophieList::ObjectStartup()
{
    LoadSpriteSheet("Menu/Trophies.gif");
    scriptEng.tempValue[0] = objectScriptList[objectEntityList[objectLoop].type].spriteSheetID;
    LoadSpriteSheet("Menu/HelpText.gif");
    scriptEng.tempValue[1] = objectScriptList[objectEntityList[objectLoop].type].spriteSheetID;
    AddSpriteFrame(-64, -64, 128, 128, 0, 0);
    AddSpriteFrame(-64, -64, 128, 128, 128, 0);
    AddSpriteFrame(-64, -64, 128, 128, 256, 0);
    AddSpriteFrame(-64, -64, 128, 128, 384, 0);
    AddSpriteFrame(-64, -64, 128, 128, 0, 128);
    AddSpriteFrame(-64, -64, 128, 128, 128, 128);
    AddSpriteFrame(-64, -64, 128, 128, 256, 128);
    AddSpriteFrame(-64, -64, 128, 128, 384, 128);
    AddSpriteFrame(-64, -64, 128, 128, 0, 256);
    AddSpriteFrame(-64, -64, 128, 128, 128, 256);
    AddSpriteFrame(-64, -64, 128, 128, 256, 256);
    AddSpriteFrame(-64, -64, 128, 128, 384, 256);
    AddSpriteFrame(-64, -64, 128, 128, 0, 384);
    SetupMenu_Script(1, 0, 3, 1);
    AddMenuEntry_Script(1, "88 Miles Per Hour", 0);
    AddMenuEntry_Script(1, "Travel through time.", 0);
    AddMenuEntry_Script(1, "Just One Hug is Enough", 0);
    AddMenuEntry_Script(1, "Get a hug from Amy.", 0);
    AddMenuEntry_Script(1, "Paradise Found", 0);
    AddMenuEntry_Script(1, "Complete a Zone in the Good Future.", 0);
    AddMenuEntry_Script(1, "Take the High Road", 0);
    AddMenuEntry_Script(1, "Pass the upper signpost in Collision Chaos Zone 2.", 0);
    AddMenuEntry_Script(1, "King of the Rings", 0);
    AddMenuEntry_Script(1, "Collect 200 Rings.", 0);
    AddMenuEntry_Script(1, "Statue Saviour", 0);
    AddMenuEntry_Script(1, "Find the angel statue in Wacky Workbench.", 0);
    AddMenuEntry_Script(1, "Heavy Metal", 0);
    AddMenuEntry_Script(1, "Defeat Metal Sonic without getting hurt.", 0);
    AddMenuEntry_Script(1, "All Stages Clear!", 0);
    AddMenuEntry_Script(1, "Finish the game.", 0);
    AddMenuEntry_Script(1, "Treasure Hunter", 0);
    AddMenuEntry_Script(1, "Collect all the Time Stones.", 0);
    AddMenuEntry_Script(1, "Dr. Eggman Got Served", 0);
    AddMenuEntry_Script(1, "Destroy Dr. Eggman's final machine.", 0);
    AddMenuEntry_Script(1, "Just In Time!", 0);
    AddMenuEntry_Script(1, "Complete the Time Attack mode in under 25 minutes.", 0);
    AddMenuEntry_Script(1, "Saviour of the Planet", 0);
    AddMenuEntry_Script(1, "Destroy all the robot transporters and Metal Sonic holograms in the past.", 0);
    LoadOnlineMenu_Script(0);
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Trophie List")) {
            objectEntityList[scriptEng.arrayPosition[0]].values[2] = scriptEng.tempValue[0];
            objectEntityList[scriptEng.arrayPosition[0]].values[3] = scriptEng.tempValue[1];
            objectEntityList[scriptEng.arrayPosition[0]].drawOrder = 2;
            objectEntityList[scriptEng.arrayPosition[0]].priority = 1;
            if (SCREEN_XSIZE >= 384) {
                objectEntityList[scriptEng.arrayPosition[0]].XPos -= 0x100000;
            }
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_Menu_TrophieList::ObjectDraw()
{
    Entity *self = Self();

    self->YPos = self->propertyValue;
    self->YPos *= 0x300000;
    self->YPos -= objectEntityList[0].values[2];
    self->YPos += 0x480000;
    self->scale = 128;
    objectScriptList[objectEntityList[objectLoop].type].spriteSheetID = self->values[2];
    if (self->values[1] == 1) {
        DrawSpriteFX_Script(self->frame, FX_SCALE, self->XPos, self->YPos);
    } else {
        DrawSpriteFX_Script(12, FX_SCALE, self->XPos, self->YPos);
    }
    scriptEng.tempValue[0] = self->XPos;
    scriptEng.tempValue[0] >>= 16;
    scriptEng.tempValue[0] -= xScrollOffset;
    scriptEng.tempValue[0] += 20;
    scriptEng.tempValue[1] = self->YPos;
    scriptEng.tempValue[1] >>= 16;
    scriptEng.tempValue[1] -= yScrollOffset;
    scriptEng.tempValue[1] -= 13;
    scriptEng.tempValue[2] = self->propertyValue;
    scriptEng.tempValue[2] <<= 1;
    objectScriptList[objectEntityList[objectLoop].type].spriteSheetID = self->values[3];
    DrawText_Script(1, scriptEng.tempValue[0], scriptEng.tempValue[1], 128, 41, scriptEng.tempValue[2], 1);
    scriptEng.tempValue[1] += 15;
    scriptEng.tempValue[2]++;
    DrawText_Script(1, scriptEng.tempValue[0], scriptEng.tempValue[1], 92, 41, scriptEng.tempValue[2], 1);
}

#endif // RETRO_USE_NATIVE_OBJECTS

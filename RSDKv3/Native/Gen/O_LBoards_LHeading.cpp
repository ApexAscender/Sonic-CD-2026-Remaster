#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_LBoards_LHeading.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from LHeading.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_LBoards_LHeading::ObjectStartup()
{
    LoadSpriteSheet("LBoards/Leaderboards.gif");
    AddSpriteFrame(0, 0, 144, 16, 1, 450);
    AddSpriteFrame(0, 0, 144, 16, 1, 331);
    AddSpriteFrame(0, 0, 144, 16, 1, 348);
    AddSpriteFrame(0, 0, 144, 16, 1, 365);
    AddSpriteFrame(0, 0, 144, 16, 1, 382);
    AddSpriteFrame(0, 0, 144, 16, 1, 399);
    AddSpriteFrame(0, 0, 144, 16, 1, 416);
    AddSpriteFrame(0, 0, 144, 16, 1, 433);
    AddSpriteFrame(144, 0, 8, 16, 358, 1);
    AddSpriteFrame(144, 0, 8, 16, 367, 1);
    AddSpriteFrame(144, 0, 8, 16, 376, 1);
}

void O_LBoards_LHeading::ObjectDraw()
{
    DrawRectangle(2, 0, 178, 31, 0, 128, 0, 255);
    switch (GVar("Leaderboard.ID")) {
        case 0:
        DrawSprite_Frame(0);
        break;
        case 1:
        DrawSprite_Frame(1);
        DrawSprite_Frame(8);
        break;
        case 2:
        DrawSprite_Frame(1);
        DrawSprite_Frame(9);
        break;
        case 3:
        DrawSprite_Frame(1);
        DrawSprite_Frame(10);
        break;
        case 4:
        DrawSprite_Frame(2);
        DrawSprite_Frame(8);
        break;
        case 5:
        DrawSprite_Frame(2);
        DrawSprite_Frame(9);
        break;
        case 6:
        DrawSprite_Frame(2);
        DrawSprite_Frame(10);
        break;
        case 7:
        DrawSprite_Frame(3);
        DrawSprite_Frame(8);
        break;
        case 8:
        DrawSprite_Frame(3);
        DrawSprite_Frame(9);
        break;
        case 9:
        DrawSprite_Frame(3);
        DrawSprite_Frame(10);
        break;
        case 10:
        DrawSprite_Frame(4);
        DrawSprite_Frame(8);
        break;
        case 11:
        DrawSprite_Frame(4);
        DrawSprite_Frame(9);
        break;
        case 12:
        DrawSprite_Frame(4);
        DrawSprite_Frame(10);
        break;
        case 13:
        DrawSprite_Frame(5);
        DrawSprite_Frame(8);
        break;
        case 14:
        DrawSprite_Frame(5);
        DrawSprite_Frame(9);
        break;
        case 15:
        DrawSprite_Frame(5);
        DrawSprite_Frame(10);
        break;
        case 16:
        DrawSprite_Frame(6);
        DrawSprite_Frame(8);
        break;
        case 17:
        DrawSprite_Frame(6);
        DrawSprite_Frame(9);
        break;
        case 18:
        DrawSprite_Frame(6);
        DrawSprite_Frame(10);
        break;
        case 19:
        DrawSprite_Frame(7);
        DrawSprite_Frame(8);
        break;
        case 20:
        DrawSprite_Frame(7);
        DrawSprite_Frame(9);
        break;
        case 21:
        DrawSprite_Frame(7);
        DrawSprite_Frame(10);
        break;
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS

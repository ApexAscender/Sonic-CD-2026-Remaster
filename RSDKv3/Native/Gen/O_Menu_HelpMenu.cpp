#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_Menu_HelpMenu.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from HelpMenu.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_Menu_HelpMenu::ObjectStartup()
{
    LoadSpriteSheet("Menu/HelpBG.gif");
    AddSpriteFrame(0, 0, 128, 128, 1, 1);
    if (Engine.language == 5) {
        objectEntityList[59].XPos -= 0x100000;
        objectEntityList[60].XPos -= 0x100000;
        objectEntityList[61].XPos -= 0x100000;
        objectEntityList[62].XPos -= 0x100000;
        objectEntityList[63].XPos -= 0x100000;
        objectEntityList[64].XPos += 0x500000;
        objectEntityList[59].YPos += 0x180000;
        objectEntityList[60].YPos += 0x180000;
        objectEntityList[61].YPos += 0x180000;
        objectEntityList[62].YPos += 0x180000;
        objectEntityList[63].YPos += 0x180000;
        objectEntityList[64].YPos -= 0x2F0000;
    }
    LoadPalette("HelpPal1.act", 0, 0, 0, 256);
    LoadPalette("HelpPal2.act", 1, 0, 0, 256);
    LoadFontFile("Data/Game/HelpText.bin");
    if (GVar("Options.Soundtrack") == 0) {
        SetMusicTrack_Script("JP/DAGarden.ogg", 1, 1);
    } else {
        SetMusicTrack_Script("US/DAGarden.ogg", 1, 117382);
    }
    Engine.gameMode = 5;
    cameraEnabled = 0;
    objectEntityList[0].type = TypeNameID("Help Menu");
    objectEntityList[0].priority = 1;
    objectEntityList[0].drawOrder = 0;
}

void O_Menu_HelpMenu::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        scriptEng.tempValue[0] = 256;
        scriptEng.tempValue[0] -= SCREEN_CENTERX;
        xScrollOffset = scriptEng.tempValue[0];
        self->values[3] = 0;
        HelpMenu_PageLoad();
        PlayMusic(1);
        self->values[0] = 384;
        self->state++;
        SetFade(0, 0, 0, 255);
        break;
        case 1:
        if (self->values[0] > 0) {
            self->values[0] -= 8;
        } else {
            self->state++;
        }
        SetFade(0, 0, 0, self->values[0]);
        break;
        case 2:
        if (keyPress.down == 1) {
            if (self->values[3] < 8) {
                PlaySfx(27, 0);
                self->values[0] = 256;
                self->state = 3;
            }
        }
        if (keyPress.up == 1) {
            if (self->values[3] > 0) {
                PlaySfx(27, 0);
                self->state = 4;
            }
        }
        if (keyPress.B == 1) {
            PlaySfx(26, 0);
            self->state = 5;
        }
        break;
        case 3:
        if (self->values[0] > 0) {
            scriptEng.tempValue[0] = Cos512(self->values[0]);
            scriptEng.tempValue[0] >>= 1;
            scriptEng.tempValue[0] += 256;
            scriptEng.tempValue[1] = self->values[2];
            scriptEng.tempValue[1] += scriptEng.tempValue[0];
            yScrollOffset = scriptEng.tempValue[1];
            scriptEng.tempValue[1] += 256;
            scriptEng.tempValue[1] >>= 9;
            if (scriptEng.tempValue[1] > self->values[3]) {
                self->values[3]++;
                if (self->values[3] == 2) {
                    SetActivePalette(1, 0, SCREEN_YSIZE);
                } else {
                    SetActivePalette(0, 0, SCREEN_YSIZE);
                }
                HelpMenu_PageLoad();
            }
            self->values[0] -= 3;
            if (self->values[0] < 0) {
                self->values[0] = 0;
            }
        } else {
            self->values[2] += 512;
            yScrollOffset = self->values[2];
            self->state = 2;
        }
        break;
        case 4:
        if (self->values[0] < 256) {
            scriptEng.tempValue[0] = Cos512(self->values[0]);
            scriptEng.tempValue[0] >>= 1;
            scriptEng.tempValue[0] -= 256;
            scriptEng.tempValue[1] = self->values[2];
            scriptEng.tempValue[1] += scriptEng.tempValue[0];
            yScrollOffset = scriptEng.tempValue[1];
            scriptEng.tempValue[1] += 256;
            scriptEng.tempValue[1] >>= 9;
            if (scriptEng.tempValue[1] < self->values[3]) {
                self->values[3]--;
                if (self->values[3] == 2) {
                    SetActivePalette(1, 0, SCREEN_YSIZE);
                } else {
                    SetActivePalette(0, 0, SCREEN_YSIZE);
                }
                HelpMenu_PageLoad();
            }
            self->values[0] += 3;
            if (self->values[0] > 256) {
                self->values[0] = 256;
            }
        } else {
            self->values[2] -= 512;
            yScrollOffset = self->values[2];
            self->values[0] = 0;
            self->state = 2;
        }
        break;
        case 5:
        if (self->values[0] < 348) {
            self->values[0] += 8;
        } else {
            stageListPosition = 1;
            Engine.gameMode = 6;
            stageMode = STAGEMODE_LOAD;
        }
        SetFade(0, 0, 0, self->values[0]);
        break;
    }
}

void O_Menu_HelpMenu::ObjectDraw()
{
    Entity *self = Self();

    self->values[4]--;
    if (self->values[4] < -31) {
        self->values[4] += 32;
    }
    scriptEng.tempValue[1] = self->values[4];
    scriptEng.tempValue[1] >>= 1;
    while (scriptEng.tempValue[1] < SCREEN_YSIZE) {
        scriptEng.tempValue[0] = self->values[4];
        scriptEng.tempValue[0] >>= 1;
        while (scriptEng.tempValue[0] < SCREEN_XSIZE) {
            DrawSprite_ScreenXY(0, scriptEng.tempValue[0], scriptEng.tempValue[1]);
            scriptEng.tempValue[0] += 128;
        }
        scriptEng.tempValue[1] += 128;
    }
}

void O_Menu_HelpMenu::HelpMenu_PageLoad()
{
    Entity *self = Self();

    switch (self->values[3]) {
        case 0:
        switch (Engine.language) {
            case 0:
            LoadTextFile_Script(0, "Data/Game/EN_Help/SCD_Pg1_EN.txt", 1);
            break;
            case 1:
            LoadTextFile_Script(0, "Data/Game/FR_Help/SCD_Pg1_FR.txt", 1);
            break;
            case 2:
            LoadTextFile_Script(0, "Data/Game/IT_Help/SCD_Pg1_IT.txt", 1);
            break;
            case 3:
            LoadTextFile_Script(0, "Data/Game/DE_Help/SCD_Pg1_DE.txt", 1);
            break;
            case 4:
            LoadTextFile_Script(0, "Data/Game/ES_Help/SCD_Pg1_ES.txt", 1);
            break;
            case 5:
            LoadTextFile_Script(0, "Data/Game/JP_Help/SCD_Pg1_JP.txt", 1);
            break;
        }
        break;
        case 1:
        switch (Engine.language) {
            case 0:
            LoadTextFile_Script(0, "Data/Game/EN_Help/SCD_Pg2_EN.txt", 1);
            break;
            case 1:
            LoadTextFile_Script(0, "Data/Game/FR_Help/SCD_Pg2_FR.txt", 1);
            break;
            case 2:
            LoadTextFile_Script(0, "Data/Game/IT_Help/SCD_Pg2_IT.txt", 1);
            break;
            case 3:
            LoadTextFile_Script(0, "Data/Game/DE_Help/SCD_Pg2_DE.txt", 1);
            break;
            case 4:
            LoadTextFile_Script(0, "Data/Game/ES_Help/SCD_Pg2_ES.txt", 1);
            break;
            case 5:
            LoadTextFile_Script(0, "Data/Game/JP_Help/SCD_Pg2_JP.txt", 1);
            break;
        }
        break;
        case 2:
        switch (Engine.language) {
            case 0:
            LoadTextFile_Script(0, "Data/Game/EN_Help/SCD_Pg3_EN.txt", 1);
            break;
            case 1:
            LoadTextFile_Script(0, "Data/Game/FR_Help/SCD_Pg3_FR.txt", 1);
            break;
            case 2:
            LoadTextFile_Script(0, "Data/Game/IT_Help/SCD_Pg3_IT.txt", 1);
            break;
            case 3:
            LoadTextFile_Script(0, "Data/Game/DE_Help/SCD_Pg3_DE.txt", 1);
            break;
            case 4:
            LoadTextFile_Script(0, "Data/Game/ES_Help/SCD_Pg3_ES.txt", 1);
            break;
            case 5:
            LoadTextFile_Script(0, "Data/Game/JP_Help/SCD_Pg3_JP.txt", 1);
            break;
        }
        break;
        case 3:
        switch (Engine.language) {
            case 0:
            LoadTextFile_Script(0, "Data/Game/EN_Help/SCD_Pg4_EN.txt", 1);
            break;
            case 1:
            LoadTextFile_Script(0, "Data/Game/FR_Help/SCD_Pg4_FR.txt", 1);
            break;
            case 2:
            LoadTextFile_Script(0, "Data/Game/IT_Help/SCD_Pg4_IT.txt", 1);
            break;
            case 3:
            LoadTextFile_Script(0, "Data/Game/DE_Help/SCD_Pg4_DE.txt", 1);
            break;
            case 4:
            LoadTextFile_Script(0, "Data/Game/ES_Help/SCD_Pg4_ES.txt", 1);
            break;
            case 5:
            LoadTextFile_Script(0, "Data/Game/JP_Help/SCD_Pg4_JP.txt", 1);
            break;
        }
        break;
        case 4:
        switch (Engine.language) {
            case 0:
            LoadTextFile_Script(0, "Data/Game/EN_Help/SCD_Pg5_EN.txt", 1);
            break;
            case 1:
            LoadTextFile_Script(0, "Data/Game/FR_Help/SCD_Pg5_FR.txt", 1);
            break;
            case 2:
            LoadTextFile_Script(0, "Data/Game/IT_Help/SCD_Pg5_IT.txt", 1);
            break;
            case 3:
            LoadTextFile_Script(0, "Data/Game/DE_Help/SCD_Pg5_DE.txt", 1);
            break;
            case 4:
            LoadTextFile_Script(0, "Data/Game/ES_Help/SCD_Pg5_ES.txt", 1);
            break;
            case 5:
            LoadTextFile_Script(0, "Data/Game/JP_Help/SCD_Pg5_JP.txt", 1);
            break;
        }
        break;
        case 5:
        switch (Engine.language) {
            case 0:
            LoadTextFile_Script(0, "Data/Game/EN_Help/SCD_Pg6_EN.txt", 1);
            break;
            case 1:
            LoadTextFile_Script(0, "Data/Game/FR_Help/SCD_Pg6_FR.txt", 1);
            break;
            case 2:
            LoadTextFile_Script(0, "Data/Game/IT_Help/SCD_Pg6_IT.txt", 1);
            break;
            case 3:
            LoadTextFile_Script(0, "Data/Game/DE_Help/SCD_Pg6_DE.txt", 1);
            break;
            case 4:
            LoadTextFile_Script(0, "Data/Game/ES_Help/SCD_Pg6_ES.txt", 1);
            break;
            case 5:
            LoadTextFile_Script(0, "Data/Game/JP_Help/SCD_Pg6_JP.txt", 1);
            break;
        }
        break;
        case 6:
        switch (Engine.language) {
            case 0:
            LoadTextFile_Script(0, "Data/Game/EN_Help/SCD_Pg7_EN.txt", 1);
            break;
            case 1:
            LoadTextFile_Script(0, "Data/Game/FR_Help/SCD_Pg7_FR.txt", 1);
            break;
            case 2:
            LoadTextFile_Script(0, "Data/Game/IT_Help/SCD_Pg7_IT.txt", 1);
            break;
            case 3:
            LoadTextFile_Script(0, "Data/Game/DE_Help/SCD_Pg7_DE.txt", 1);
            break;
            case 4:
            LoadTextFile_Script(0, "Data/Game/ES_Help/SCD_Pg7_ES.txt", 1);
            break;
            case 5:
            LoadTextFile_Script(0, "Data/Game/JP_Help/SCD_Pg7_JP.txt", 1);
            break;
        }
        break;
        case 7:
        switch (Engine.language) {
            case 0:
            LoadTextFile_Script(0, "Data/Game/EN_Help/SCD_Pg8_EN.txt", 1);
            break;
            case 1:
            LoadTextFile_Script(0, "Data/Game/FR_Help/SCD_Pg8_FR.txt", 1);
            break;
            case 2:
            LoadTextFile_Script(0, "Data/Game/IT_Help/SCD_Pg8_IT.txt", 1);
            break;
            case 3:
            LoadTextFile_Script(0, "Data/Game/DE_Help/SCD_Pg8_DE.txt", 1);
            break;
            case 4:
            LoadTextFile_Script(0, "Data/Game/ES_Help/SCD_Pg8_ES.txt", 1);
            break;
            case 5:
            LoadTextFile_Script(0, "Data/Game/JP_Help/SCD_Pg8_JP.txt", 1);
            break;
        }
        break;
        case 8:
        switch (Engine.language) {
            case 0:
            LoadTextFile_Script(0, "Data/Game/EN_Help/SCD_Pg9_EN.txt", 1);
            break;
            case 1:
            LoadTextFile_Script(0, "Data/Game/FR_Help/SCD_Pg9_FR.txt", 1);
            break;
            case 2:
            LoadTextFile_Script(0, "Data/Game/IT_Help/SCD_Pg9_IT.txt", 1);
            break;
            case 3:
            LoadTextFile_Script(0, "Data/Game/DE_Help/SCD_Pg9_DE.txt", 1);
            break;
            case 4:
            LoadTextFile_Script(0, "Data/Game/ES_Help/SCD_Pg9_ES.txt", 1);
            break;
            case 5:
            LoadTextFile_Script(0, "Data/Game/JP_Help/SCD_Pg9_JP.txt", 1);
            break;
        }
        break;
    }
}

const Native::NativeFunctionDef O_Menu_HelpMenu::funcs[1] = {
    { "HelpMenu_PageLoad", O_Menu_HelpMenu::HelpMenu_PageLoad },
};

#endif // RETRO_USE_NATIVE_OBJECTS

#!/usr/bin/env python3
"""
RetroScript (RSDKv3) -> C++ transpiler for the SonicCD-Native migration.

Goal: mechanically convert Data/Scripts/*.txt into faithful native C++ that plugs
into the Native object layer, so we can retire the interpreter object-by-object.
The output is a direct, behaviour-preserving translation (not hand-polished): it
uses the Native accessor helpers, preserves the exact integer/fixed-point math and
control flow, and flags anything it can't map.

v3 — grounded in Script.cpp's variableNames[]/functions[] tables, the
interpreter's get/set switches, and the text compiler's parse rules:
  * All name resolution is case-insensitive (the engine's StrComp folds case;
    the decompiled scripts rely on it: `object.value2`, `Xpos`, `TImer`).
  * #platform keeps a block if the line has ANY of the engine's active tokens
    (gamePlatform/gameRenderType/gameHapticSetting/releaseType/Use_Decomp/
    Use_Mod_Loader) — mirrors Script.cpp PARSEMODE_PLATFORMSKIP.
  * TempValue/ArrayPos/TempObjectPos map to scriptEng (engine-global, shared
    across subs and CallFunction — locals would break cross-function passing).
  * Aliases can point at indexed entity fields (#alias Object[24].PropertyValue
    : HUD.CurrentTimePeriod) — resolution recurses.
  * Label arrays (Face[ArrayPos0].YPos, Bomb[TempObjectPos].XPos) resolve
    through per-script field aliases onto objectEntityList.
  * Relative entity indexing: Object[+1] / Object[+ArrayPos0] add to
    objectLoop, Object[-1] subtracts (VARARR_ENTNOPLUS1/MINUS1).
  * Engine struct arrays (TileLayer/HParallax/VertexBuffer/SaveRAM/...) map to
    the exact storage from Script.cpp's VAR_* switch.
  * iXPos/iYPos get/set asymmetry handled at assignment level (write truncates
    subpixels, same as the interpreter's store).
  * CallFunction: in-file -> direct native call; variable -> dynamic
    CallScriptFunction(id); cross-file #function -> CallScriptFunctionNamed.
  * GVar() only for names verified against GameConfig.bin globals (plus the
    decomp's runtime-registered game.* names); anything else warns.
"""
import re, sys, os

# Tokens that keep a #platform block under our engine configuration
# (Platform=0 Standard, software renderer, haptics compiled in, GameType=0
# standalone, decomp, mod loader ON). Mirrors Script.cpp:1817.
PLATFORM_KEEP = ("standard", "sw_rendering", "use_haptics", "use_standalone",
                 "use_decomp", "use_mod_loader")

# ---------------------------------------------------------------------------
# GameConfig.bin — global variable names, object names + script paths.
# ---------------------------------------------------------------------------
def load_gameconfig(path):
    with open(path, "rb") as f:
        data = f.read()
    pos = [0]
    def u8():
        v = data[pos[0]]; pos[0] += 1; return v
    def pstr():
        n = u8(); s = data[pos[0]:pos[0]+n].decode("ascii", "replace"); pos[0] += n; return s
    pstr(); pstr(); pstr()                       # title, "Data", description
    objcount = u8()
    obj_names = [pstr() for _ in range(objcount)]
    obj_paths = [pstr() for _ in range(objcount)]
    varcount = u8()
    global_vars = []
    for _ in range(varcount):
        global_vars.append(pstr()); pos[0] += 4  # skip value
    return global_vars, obj_names, obj_paths

_here = os.path.dirname(os.path.abspath(__file__))
GAMECONFIG = os.path.normpath(os.path.join(_here, "..", "Data", "Game", "GameConfig.bin"))
try:
    GLOBAL_VARS, GC_OBJ_NAMES, GC_OBJ_PATHS = load_gameconfig(GAMECONFIG)
except OSError:
    GLOBAL_VARS, GC_OBJ_NAMES, GC_OBJ_PATHS = [], [], []

# Globals the decomp engine registers at runtime (SetGlobalVariableByName) on
# top of GameConfig's list; game.* is the Origins-integration family, the
# ANI_/PLAYER_/MAINMENUMODE_ names are the decomp's playable-character /
# Origins-menu additions. GVar() safely reads 0 for any not present at runtime.
RUNTIME_GLOBALS = [
    "Options.DevMenuFlag", "Options.TouchControls", "Options.OriginalControls",
    "Options.Soundtrack", "Engine.PlatformId", "Engine.DeviceType",
    "Engine.Standalone", "Engine.Fullscreen", "Engine.Borderless", "Engine.VSync",
    "Engine.ScalingMode", "Engine.WindowScale", "Engine.ScreenWidth",
    "Engine.HardwareRenderer", "Config.IsPremiumUser", "Config.NumOfLives",
    "game.callbackParam0", "game.callbackParam1", "game.callbackParam2",
    "game.callbackResult", "game.coinCount", "game.continueFlag", "game.hasPlusDLC",
    "game.playMode", "game.missionCondition", "game.missionFunctionNo",
    "game.missionValue", "game.forceKillPlayer", "game.mainMenuMode",
    "input.pressButton", "HaveLoadAllGDPRValue", "RewardAdCallback",
    "Mini_PlayerFlag", "LampPost.Check",
    "ANI_CLIMBING", "ANI_GLIDING", "ANI_LEDGEPULLUP", "ANI_HAMMER_DASH",
    "ANI_HAMMER_JUMP",
    "PLAYER_SONIC", "PLAYER_TAILS", "PLAYER_KNUCKLES", "PLAYER_AMY",
    "PLAYER_AMY_TAILS", "PLAYER_KNUCKLES_TAILS",
    "MISSION_CONDITION_CLEAR", "BOOT_PLAYMODE_BOSSRUSH",
    "MAINMENUMODE_EXTRAS", "MAINMENUMODE_SETTINGS", "MAINMENUMODE_SOUNDTRACK",
]

# The script compiler's built-in aliases (Script.cpp aliases[]), resolved to
# their numeric values. FX_*, C_*, MAT_* also exist as same-valued C++ enums and
# would pass through by name, but the RETRO_* platform constants include the
# mixed-case RETRO_iOS (would be misread as a function name), and a `case
# RETRO_iOS:` needs a compile-time constant — so map the whole aliases[] table
# to numbers, exactly as the RSDK compiler does.
BUILTIN_NUM_ALIASES = {
    "menu_1": "0", "menu_2": "1",
    "presentation_stage": "0", "regular_stage": "1", "bonus_stage": "2", "special_stage": "3",
    "stage_running": "1", "stage_paused": "2", "reset_game": "2",
    "facing_left": "1", "facing_right": "0",
    "retro_win": "0", "retro_osx": "1", "retro_xbox_360": "2", "retro_ps3": "3",
    "retro_ios": "4", "retro_android": "5", "retro_wp7": "6",
}
GLOBAL_VARS_CI = set(v.lower() for v in GLOBAL_VARS) | set(v.lower() for v in RUNTIME_GLOBALS)

# ---------------------------------------------------------------------------
# Object.* entity fields (indexable). Values are Entity member names.
# ---------------------------------------------------------------------------
ENTITY_FIELD = {
    "Type": "type", "PropertyValue": "propertyValue", "XPos": "XPos", "YPos": "YPos",
    "State": "state", "Rotation": "rotation", "Scale": "scale", "Priority": "priority",
    "DrawOrder": "drawOrder", "Direction": "direction", "InkEffect": "inkEffect",
    "Alpha": "alpha", "Frame": "frame", "Animation": "animation",
    "PrevAnimation": "prevAnimation", "AnimationSpeed": "animationSpeed",
    "AnimationTimer": "animationTimer",
}
for _n in range(8):
    ENTITY_FIELD["Value%d" % _n] = "values[%d]" % _n

# Player.* — VAR_PLAYER* always uses playerList[activePlayer]; the accessors in
# NativeObject.hpp/PlayerFields.hpp mirror the Player-struct/bound-entity split.
PLAYER_ACCESSOR = {
    "State": "pState()", "ControlMode": "pControlMode()", "ControlLock": "pControlLock()",
    "CollisionMode": "pCollisionMode()", "CollisionPlane": "pCollisionPlane()",
    "XPos": "pXPos()", "YPos": "pYPos()", "ScreenXPos": "pScreenXPos()", "ScreenYPos": "pScreenYPos()",
    "Speed": "pSpeed()", "XVelocity": "pXVel()", "YVelocity": "pYVel()", "Gravity": "pGravity()",
    "Angle": "pAngle()", "Skidding": "pSkidding()", "Pushing": "pPushing()", "TrackScroll": "pTrackScroll()",
    "Up": "pUp()", "Down": "pDown()", "Left": "pLeft()", "Right": "pRight()",
    "JumpPress": "pJumpPress()", "JumpHold": "pJumpHold()", "LookPos": "pLookPos()", "Water": "pWater()",
    "FollowPlayer1": "Plr()->followPlayer1", "EntityNo": "Plr()->entityNo", "Flailing": "Plr()->flailing[0]",
    "TopSpeed": "pTopSpeed()", "Acceleration": "pAccel()", "Deceleration": "pDecel()",
    "AirAcceleration": "pAirAccel()", "AirDeceleration": "pAirDecel()",
    "GravityStrength": "pGravityStrength()", "JumpStrength": "pJumpStrength()", "JumpCap": "pJumpCap()",
    "RollingAcceleration": "pRollingAccel()", "RollingDeceleration": "pRollingDecel()",
    "Timer": "pTimer()", "Visible": "pVisible()", "TileCollisions": "pTileCollisions()",
    "ObjectInteraction": "pObjectInteractions()", "Rotation": "pRotation()", "Direction": "pDirection()",
    "Scale": "PlrEntity()->scale", "Priority": "PlrEntity()->priority", "DrawOrder": "PlrEntity()->drawOrder",
    "InkEffect": "PlrEntity()->inkEffect", "Alpha": "PlrEntity()->alpha",
    "Animation": "pAnimation()", "PrevAnimation": "pPrevAnimation()", "Frame": "pFrame()",
    "AnimationSpeed": "pAnimationSpeed()", "AnimationTimer": "pAnimationTimer()",
    "CollisionTop": "pCollisionTop()", "CollisionBottom": "pCollisionBottom()",
    "CollisionLeft": "pCollisionLeft()", "CollisionRight": "pCollisionRight()",
    "OutOfBounds": "PlayerOutOfBounds()",
}
for _n in range(16):
    PLAYER_ACCESSOR["Value%d" % _n] = "PlayerValue(%d)" % _n

# Plain (non-indexed) engine variables — VAR_* get/set switch, Script.cpp.
SPECIAL = {
    "TempValue0": "scriptEng.tempValue[0]", "TempValue1": "scriptEng.tempValue[1]",
    "TempValue2": "scriptEng.tempValue[2]", "TempValue3": "scriptEng.tempValue[3]",
    "TempValue4": "scriptEng.tempValue[4]", "TempValue5": "scriptEng.tempValue[5]",
    "TempValue6": "scriptEng.tempValue[6]", "TempValue7": "scriptEng.tempValue[7]",
    "CheckResult": "CheckResult()",
    "ArrayPos0": "scriptEng.arrayPosition[0]", "ArrayPos1": "scriptEng.arrayPosition[1]",
    "TempObjectPos": "scriptEng.arrayPosition[2]",
    "Object.EntityNo": "objectLoop",
    "Stage.State": "stageMode", "Stage.ActiveList": "activeStageList",
    "Stage.ListPos": "stageListPosition", "Stage.TimeEnabled": "timeEnabled",
    "Stage.MilliSeconds": "stageMilliseconds", "Stage.Seconds": "stageSeconds",
    "Stage.Minutes": "stageMinutes", "Stage.ActNo": "actID",
    "Stage.PauseEnabled": "pauseEnabled", "Stage.ListSize": "stageListCount[activeStageList]",
    "Stage.NewXBoundary1": "newXBoundary1", "Stage.NewXBoundary2": "newXBoundary2",
    "Stage.NewYBoundary1": "newYBoundary1", "Stage.NewYBoundary2": "newYBoundary2",
    "Stage.XBoundary1": "xBoundary1", "Stage.XBoundary2": "xBoundary2",
    "Stage.YBoundary1": "yBoundary1", "Stage.YBoundary2": "yBoundary2",
    "Stage.WaterLevel": "waterLevel", "Stage.MidPoint": "tLayerMidPoint",
    "Stage.PlayerListPos": "playerListPos", "Stage.ActivePlayer": "activePlayer",
    "Stage.DebugMode": "debugMode",
    "Screen.CameraEnabled": "cameraEnabled", "Screen.CameraTarget": "cameraTarget",
    "Screen.CameraStyle": "cameraStyle",
    "Screen.CenterX": "SCREEN_CENTERX", "Screen.CenterY": "SCREEN_CENTERY",
    "Screen.XSize": "SCREEN_XSIZE", "Screen.YSize": "SCREEN_YSIZE",
    "Screen.XOffset": "xScrollOffset", "Screen.YOffset": "yScrollOffset",
    "Screen.ShakeX": "cameraShakeX", "Screen.ShakeY": "cameraShakeY",
    "Screen.AdjustCameraY": "cameraAdjustY",
    "Music.Volume": "masterVolume", "Music.CurrentTrack": "trackID",
    "Menu1.Selection": "gameMenu[0].selection1", "Menu2.Selection": "gameMenu[1].selection1",
    "3DScene.NoVertices": "vertexCount", "3DScene.NoFaces": "faceCount",
    "3DScene.ProjectionX": "projectionX", "3DScene.ProjectionY": "projectionY",
    "Engine.State": "Engine.gameMode", "Engine.Message": "Engine.message",
    "Engine.Language": "Engine.language", "Engine.OnlineActive": "Engine.onlineActive",
    "Engine.FrameSkipTimer": "Engine.frameSkipTimer", "Engine.FrameSkipSetting": "Engine.frameSkipSetting",
    "Engine.SFXVolume": "sfxVolume", "Engine.BGMVolume": "bgmVolume",
    "Engine.PlatformID": "RETRO_GAMEPLATFORMID", "Engine.TrialMode": "Engine.trialMode",
    "Engine.HapticsEnabled": "Engine.hapticsEnabled",  # lvalue (bool field); scripts read+write it
    "KeyPress.AnyStart": "anyPress",
    "Object.OutOfBounds": "GetObjectOutOfBounds(objectLoop)",
    "Object.SpriteSheet": "objectScriptList[objectEntityList[objectLoop].type].spriteSheetID",
    # RetroScript booleans are literally 1/0; keep int comparisons warning-free.
    "true": "1", "false": "0",
}
# KeyDown/KeyPress: single InputData struct — the [0] index in scripts is ignored
# by the interpreter (there is only one local player).
_INPUT_FIELD = {"Up": "up", "Down": "down", "Left": "left", "Right": "right",
                "ButtonA": "A", "ButtonB": "B", "ButtonC": "C", "Start": "start"}
for _f, _e in _INPUT_FIELD.items():
    SPECIAL["KeyDown." + _f] = "keyDown." + _e
    SPECIAL["KeyPress." + _f] = "keyPress." + _e

# Indexed engine arrays — canonical script var -> C++ lvalue with {i}.
ARRAYS = {
    "SaveRAM": "saveRAM[{i}]",
    "Global": "globalVariables[{i}]",
    "Stage.DeformationData0": "bgDeformationData0[{i}]",
    "Stage.DeformationData1": "bgDeformationData1[{i}]",
    "Stage.DeformationData2": "bgDeformationData2[{i}]",
    "Stage.DeformationData3": "bgDeformationData3[{i}]",
    "Stage.ActiveLayer": "activeTileLayers[{i}]",
    "Screen.DrawListSize": "drawListEntries[{i}].listSize",
    "TouchScreen.Down": "touchDown[{i}]",
    "TouchScreen.XPos": "touchX[{i}]",
    "TouchScreen.YPos": "touchY[{i}]",
    "Player.Flailing": "Plr()->flailing[{i}]",
    "Object.SpriteSheet": "objectScriptList[objectEntityList[{i}].type].spriteSheetID",
    "KeyPress.AnyStart": "anyPress",
    "VertexBuffer.x": "vertexBuffer[{i}].x", "VertexBuffer.y": "vertexBuffer[{i}].y",
    "VertexBuffer.z": "vertexBuffer[{i}].z", "VertexBuffer.u": "vertexBuffer[{i}].u",
    "VertexBuffer.v": "vertexBuffer[{i}].v",
    "FaceBuffer.a": "faceBuffer[{i}].a", "FaceBuffer.b": "faceBuffer[{i}].b",
    "FaceBuffer.c": "faceBuffer[{i}].c", "FaceBuffer.d": "faceBuffer[{i}].d",
    "FaceBuffer.Flag": "faceBuffer[{i}].flags", "FaceBuffer.Color": "faceBuffer[{i}].colour",
}
_TILELAYER_FIELD = {"XSize": "xsize", "YSize": "ysize", "Type": "type", "Angle": "angle",
                    "XPos": "XPos", "YPos": "YPos", "ZPos": "ZPos",
                    "ParallaxFactor": "parallaxFactor", "ScrollSpeed": "scrollSpeed",
                    "ScrollPos": "scrollPos", "DeformationOffset": "deformationOffset",
                    "DeformationOffsetW": "deformationOffsetW"}
for _f, _e in _TILELAYER_FIELD.items():
    ARRAYS["TileLayer." + _f] = "stageLayouts[{i}]." + _e
for _f in ("ParallaxFactor", "ScrollSpeed", "ScrollPos"):
    ARRAYS["HParallax." + _f] = "hParallax." + _f[0].lower() + _f[1:] + "[{i}]"
    ARRAYS["VParallax." + _f] = "vParallax." + _f[0].lower() + _f[1:] + "[{i}]"
for _f, _e in _INPUT_FIELD.items():           # KeyPress[0].Up etc — index ignored
    ARRAYS["KeyDown." + _f] = "keyDown." + _e
    ARRAYS["KeyPress." + _f] = "keyPress." + _e

# get/set-asymmetric vars: (rvalue with {i}, set-statement with {i} and {v}).
# The interpreter's store truncates subpixels (XPos = value << 16) — faithful.
ASYM = {
    "Object.iXPos": ("(objectEntityList[{i}].XPos >> 16)", "objectEntityList[{i}].XPos = ({v}) << 16;"),
    "Object.iYPos": ("(objectEntityList[{i}].YPos >> 16)", "objectEntityList[{i}].YPos = ({v}) << 16;"),
    "Player.iXPos": ("(pXPos() >> 16)", "pXPos() = ({v}) << 16;"),
    "Player.iYPos": ("(pYPos() >> 16)", "pYPos() = ({v}) << 16;"),
}

# ---------------------------------------------------------------------------
# Function name -> C++ emitter (lambda over already-translated arg list).
# Semantics mirror the FUNC_* opcode bodies in Script.cpp.
# ---------------------------------------------------------------------------
def _call(name):
    return lambda a: "%s(%s)" % (name, ", ".join(a))

FUNC = {
    # audio
    "PlaySfx": _call("PlaySfx"), "StopSfx": _call("StopSfx"),
    "SetSfxAttributes": _call("SetSfxAttributes"),
    "PlayStageSfx": lambda a: "PlaySfx(globalSFXCount + %s, %s)" % (a[0], a[1]),
    "StopStageSfx": lambda a: "StopSfx(globalSFXCount + %s)" % a[0],
    "PlayMusic": _call("PlayMusic"), "StopMusic": lambda a: "StopMusic()",
    "PauseMusic": lambda a: "PauseSound()", "ResumeMusic": lambda a: "ResumeSound()",
    "SetMusicTrack": _call("SetMusicTrack_Script"),
    # collision
    "PlayerObjectCollision": _call("PlayerObjectCollision"),
    "ObjectTileCollision": _call("ObjectTileCollision_Script"),
    "ObjectTileGrip": _call("ObjectTileGrip_Script"),
    "PlayerTileCollision": lambda a: "PlayerTileCollision_Script()",
    "CheckTouchRect": _call("CheckTouchRect_Script"),
    # entities
    "CreateTempObject": _call("CreateTempObject"),
    "ResetObjectEntity": _call("ResetObjectEntity"),
    "BindPlayerToObject": _call("BindPlayerToObject_Script"),
    "ProcessPlayerControl": lambda a: "::ProcessPlayerControl(Plr())",
    "ProcessAnimation": lambda a: "ProcessAnimation_Script()",
    "DrawObjectAnimation": lambda a: "DrawObjectAnimation_Script()",
    "DrawPlayerAnimation": lambda a: "DrawPlayerAnimation_Script()",
    # drawing
    "LoadSpriteSheet": _call("LoadSpriteSheet"),
    "RemoveSpriteSheet": lambda a: "RemoveGraphicsFile(%s, -1)" % a[0],
    "SpriteFrame": _call("AddSpriteFrame"), "EditFrame": _call("EditFrame_Script"),
    "LoadAnimation": _call("LoadAnimation_Script"),
    "GetAnimationByName": lambda a: "%s = GetAnimationByName(%s)" % (a[0], a[1]),
    "DrawSprite": lambda a: "DrawSprite_Frame(%s)" % a[0],
    "DrawSpriteXY": _call("DrawSprite_FrameXY"),
    "DrawSpriteScreenXY": _call("DrawSprite_ScreenXY"),
    "DrawSpriteFX": _call("DrawSpriteFX_Script"),
    "DrawSpriteScreenFX": _call("DrawSpriteScreenFX_Script"),
    "DrawNumbers": _call("DrawNumbers_Script"),
    "DrawActName": _call("DrawActName_Script"),
    "DrawRect": _call("DrawRectangle"), "DrawTintRect": _call("DrawTintRectangle"),
    "ClearScreen": _call("ClearScreen"),
    # palette / fade
    "LoadPalette": _call("LoadPalette"), "RotatePalette": _call("RotatePalette"),
    "SetScreenFade": _call("SetFade"), "SetActivePalette": _call("SetActivePalette"),
    "SetPaletteFade": _call("SetLimitedFade"), "CopyPalette": _call("CopyPalette"),
    # stage / layers / tiles
    "LoadStage": lambda a: "stageMode = STAGEMODE_LOAD",
    "SetLayerDeformation": _call("SetLayerDeformation"),
    "GetTileLayerEntry": lambda a: "%s = stageLayouts[%s].tiles[%s + 0x100 * %s]" % (a[0], a[1], a[2], a[3]),
    "SetTileLayerEntry": lambda a: "stageLayouts[%s].tiles[%s + 0x100 * %s] = %s" % (a[1], a[2], a[3], a[0]),
    "Get16x16TileInfo": lambda a: "%s = Get16x16TileInfo_Script(%s, %s, %s)" % (a[0], a[1], a[2], a[3]),
    "Set16x16TileInfo": _call("Set16x16TileInfo_Script"),
    "Copy16x16Tile": _call("Copy16x16Tile"),
    # draw lists
    "ClearDrawList": lambda a: "drawListEntries[%s].listSize = 0" % a[0],
    "AddDrawListEntityRef": lambda a: "drawListEntries[%s].entityRefs[drawListEntries[%s].listSize++] = %s" % (a[0], a[0], a[1]),
    "GetDrawListEntityRef": lambda a: "%s = drawListEntries[%s].entityRefs[%s]" % (a[0], a[1], a[2]),
    "SetDrawListEntityRef": lambda a: "drawListEntries[%s].entityRefs[%s] = %s" % (a[1], a[2], a[0]),
    # math
    "Rand": lambda a: "%s = rand() %% %s" % (a[0], a[1]),
    "Sin": lambda a: "%s = Sin512(%s)" % (a[0], a[1]), "Cos": lambda a: "%s = Cos512(%s)" % (a[0], a[1]),
    "Sin256": lambda a: "%s = Sin256(%s)" % (a[0], a[1]), "Cos256": lambda a: "%s = Cos256(%s)" % (a[0], a[1]),
    "SinChange": lambda a: "%s = %s + (Sin512(%s) >> %s) - %s" % (a[0], a[3], a[1], a[2], a[4]),
    "CosChange": lambda a: "%s = %s + (Cos512(%s) >> %s) - %s" % (a[0], a[3], a[1], a[2], a[4]),
    "ATan2": lambda a: "%s = ArcTanLookup(%s, %s)" % (a[0], a[1], a[2]),
    "Interpolate": lambda a: "%s = (%s * (0x100 - %s) + %s * %s) >> 8" % (a[0], a[2], a[3], a[3], a[1]),
    "InterpolateXY": lambda a: ["%s = (%s * (0x100 - %s) >> 8) + ((%s * %s) >> 8);" % (a[0], a[3], a[6], a[6], a[2]),
                                "%s = (%s * (0x100 - %s) >> 8) + (%s * %s >> 8);" % (a[1], a[5], a[6], a[6], a[4])],
    "FlipSign": lambda a: "%s = -%s" % (a[0], a[0]),
    "Not": lambda a: "%s = ~%s" % (a[0], a[0]),
    "GetBit": lambda a: "%s = ((%s >> %s) & 1)" % (a[0], a[1], a[2]),
    "SetBit": lambda a: "%s = (%s) ? (%s | (1 << %s)) : (%s & ~(1 << %s))" % (a[0], a[2], a[0], a[1], a[0], a[1]),
    "CheckEqual": lambda a: "CheckResult() = (%s == %s)" % (a[0], a[1]),
    "CheckNotEqual": lambda a: "CheckResult() = (%s != %s)" % (a[0], a[1]),
    "CheckGreater": lambda a: "CheckResult() = (%s > %s)" % (a[0], a[1]),
    "CheckLower": lambda a: "CheckResult() = (%s < %s)" % (a[0], a[1]),
    # 3D
    "Draw3DScene": lambda a: "Draw3DScene_Script()",
    "SetIdentityMatrix": _call("SetIdentityMatrixM"),
    "MatrixMultiply": _call("MatrixMultiplyM"),
    "MatrixTranslateXYZ": _call("MatrixTranslateXYZM"),
    "MatrixScaleXYZ": _call("MatrixScaleXYZM"),
    "MatrixRotateX": _call("MatrixRotateXM"), "MatrixRotateY": _call("MatrixRotateYM"),
    "MatrixRotateZ": _call("MatrixRotateZM"), "MatrixRotateXYZ": _call("MatrixRotateXYZM"),
    "TransformVertices": _call("TransformVerticesM"),
    # menus / text
    "SetupMenu": _call("SetupMenu_Script"), "AddMenuEntry": _call("AddMenuEntry_Script"),
    "EditMenuEntry": _call("EditMenuEntry_Script"), "DrawMenu": _call("DrawMenu_Script"),
    "LoadTextFont": lambda a: "LoadFontFile(%s)" % a[0],
    "LoadTextFile": _call("LoadTextFile_Script"),
    "DrawText": _call("DrawText_Script"),
    "GetTextInfo": lambda a: "%s = GetTextInfo_Script(%s, %s, %s, %s)" % (a[0], a[1], a[2], a[3], a[4]),
    "GetVersionNumber": _call("GetVersionNumber_Script"),
    # system
    "SetAchievement": _call("SetAchievement"), "SetLeaderboard": _call("SetLeaderboard"),
    "LoadOnlineMenu": _call("LoadOnlineMenu_Script"),
    "EngineCallback": lambda a: "Engine.Callback(%s)" % a[0],
    "HapticEffect": _call("HapticEffect_Script"),
    "ReadSaveRAM": lambda a: "CheckResult() = ReadSaveRAMData()",
    "WriteSaveRAM": lambda a: "CheckResult() = WriteSaveRAMData()",
    "LoadVideo": _call("LoadVideo_Script"),
    "NextVideoFrame": lambda a: "UpdateVideoFrame()",
}

# case-insensitive views (engine StrComp folds case)
SPECIAL_CI = {k.lower(): v for k, v in SPECIAL.items()}
ENTITY_FIELD_CI = {k.lower(): v for k, v in ENTITY_FIELD.items()}
PLAYER_ACCESSOR_CI = {k.lower(): v for k, v in PLAYER_ACCESSOR.items()}
ARRAYS_CI = {k.lower(): v for k, v in ARRAYS.items()}
ASYM_CI = {k.lower(): v for k, v in ASYM.items()}
FUNC_CI = {k.lower(): v for k, v in FUNC.items()}

CMP_RE = re.compile(r"\s*(==|!=|>=|<=|>|<)\s*")
ASSIGN_RE = re.compile(r"^(.+?)\s*(<<=|>>=|\+=|-=|\*=|/=|&=|\|=|\^=|%=|(?<![=!<>+\-*/&|^%])=(?!=))\s*(.+)$")
NUM_RE = re.compile(r"[-+]?(0x[0-9A-Fa-f]+|\d+)$")

def cpp_ident(name):
    return name.replace(".", "_")

class Transpiler:
    def __init__(self):
        self.num_alias = dict(BUILTIN_NUM_ALIASES)  # lower NAME -> number constant
        self.var_alias = {}   # lower NAME -> canonical script var (original case)
        self.declared = {}    # lower name -> original: #function declarations
        self.defined = {}     # lower name -> original: function blocks in this file
        self.warnings = []

    # ---- preprocessing --------------------------------------------------
    def preprocess(self, text):
        out, keep = [], True
        stack = []
        for raw in text.splitlines():
            line = self._strip_comment(raw).rstrip()
            # normalize tabs outside string literals (scripts tab-align '=')
            parts = line.split('"')
            for k in range(0, len(parts), 2):
                parts[k] = parts[k].replace("\t", " ")
            line = '"'.join(parts)
            s = line.strip()
            low = s.lower()
            if low.startswith("#platform:"):
                stack.append(keep)
                keep = keep and any(tok in low for tok in PLATFORM_KEEP)
                continue
            if low.startswith("#endplatform"):
                keep = stack.pop() if stack else True
                continue
            if not keep:
                continue
            if low.startswith("#alias"):
                m = re.match(r"#alias\s+(.+?)\s*:\s*(\S+)", s)
                if m:
                    val, name = m.group(1).strip(), m.group(2).strip()
                    if NUM_RE.fullmatch(val):
                        self.num_alias[name.lower()] = val
                    else:
                        self.var_alias[name.lower()] = val
                continue
            if low.startswith("#function"):
                fn = s.split()[1]
                self.declared[fn.lower()] = fn
                continue
            if s.startswith("#"):
                continue
            out.append(line)
        # pre-scan function definitions (needed to route CallFunction correctly)
        for line in out:
            m = re.match(r"(?:sub|function)\s+(\w+)", line.strip(), re.I)
            if m and line.strip().lower().startswith("function"):
                self.defined[m.group(1).lower()] = m.group(1)
        return out

    @staticmethod
    def _strip_comment(line):
        # strip // comments, but not inside string literals
        in_str = False
        for k in range(len(line) - 1):
            c = line[k]
            if c == '"':
                in_str = not in_str
            elif not in_str and c == "/" and line[k + 1] == "/":
                return line[:k]
        return line

    def warn(self, w):
        if w not in self.warnings:
            self.warnings.append(w)

    # ---- index resolution -----------------------------------------------
    def entity_index(self, idxtok):
        """Object[...] index: an explicit leading +/- is relative to objectLoop
        (VARARR_ENTNOPLUS1 / VARARR_ENTNOMINUS1); otherwise absolute."""
        idxtok = idxtok.strip()
        if idxtok and idxtok[0] in "+-":
            rest = idxtok[1:].strip()
            return "objectLoop %s %s" % (idxtok[0], self.expr(rest))
        return self.expr(idxtok)

    # ---- variable resolution ---------------------------------------------
    def resolve_lvalue(self, tok, depth=0):
        """-> (rvalue_expr, set_fmt or None). set_fmt has {v} for the value."""
        tok = tok.strip()
        if depth > 8:
            return None, None
        # full-token alias (may point at an indexed entity field)
        base = self.var_alias.get(tok.lower())
        if base is not None and base.lower() != tok.lower():
            return self.resolve_lvalue(base, depth + 1)

        # Base[idx].Field
        m = re.fullmatch(r"([A-Za-z_0-9][\w.]*)\[(.+)\]\.(\w+)", tok)
        if m:
            name, idx, field = m.group(1), m.group(2), m.group(3)
            canon = self.var_alias.get((name + "." + field).lower(), name + "." + field)
            lcanon = canon.lower()
            if lcanon in ARRAYS_CI:
                return ARRAYS_CI[lcanon].format(i=self.expr(idx)), None
            # alias may map Label.Field -> Object.ValueN (keep Label's index!)
            cfield = canon.split(".", 1)[1] if lcanon.startswith("object.") else None
            if cfield is None and name.lower() != "object":
                # label array with a plain entity field (Face[i].XPos)
                cfield = field
            if cfield is not None:
                i = self.entity_index(idx)
                lf = cfield.lower()
                if lf == "entityno":     # VAR_OBJECTENTITYNO: value IS the index
                    return "(%s)" % i, None
                if lf in ENTITY_FIELD_CI:
                    return "objectEntityList[%s].%s" % (i, ENTITY_FIELD_CI[lf]), None
                if ("object." + lf) in ASYM_CI:
                    g, s = ASYM_CI["object." + lf]
                    return g.format(i=i), s.replace("{i}", i)
                self.warn("array field %s[].%s" % (name, cfield))
                return "objectEntityList[%s].values[0] /*TODO field %s*/" % (i, cfield), None
            if lcanon.startswith("player."):
                a = PLAYER_ACCESSOR_CI.get(lcanon[7:])
                if a:
                    return a, None
            self.warn("array var %s[].%s" % (name, field))
            return "0 /*TODO %s*/" % tok, None

        # Base[idx]  (SaveRAM[x], Stage.ActiveLayer[0], Player.Flailing[1])
        m = re.fullmatch(r"([A-Za-z_0-9][\w.]*)\[(.+)\]", tok)
        if m:
            name, idx = m.group(1), m.group(2)
            canon = self.var_alias.get(name.lower(), name)
            lcanon = canon.lower()
            if lcanon in ARRAYS_CI:
                return ARRAYS_CI[lcanon].format(i=self.expr(idx)), None
            self.warn("array '%s'" % tok)
            return "0 /*TODO %s*/" % tok, None

        # plain names
        low = tok.lower()
        if low in SPECIAL_CI:
            return SPECIAL_CI[low], None
        if low in ASYM_CI:
            g, s = ASYM_CI[low]
            return g.format(i="objectLoop"), s.replace("{i}", "objectLoop")
        if low.startswith("object."):
            f = ENTITY_FIELD_CI.get(low[7:])
            if f:
                return "self->" + f, None
        if low.startswith("player."):
            a = PLAYER_ACCESSOR_CI.get(low[7:])
            if a:
                return a, None
        return None, None

    # ---- expression translation ----------------------------------------
    def expr(self, tok):
        tok = tok.strip()
        if tok == "":
            return ""
        if tok.startswith('"') and tok.endswith('"'):
            return tok
        # player state function referenced by name (cross-file state constant)
        if re.fullmatch(r"(?i)player_state_\w+", tok):
            return 'PlayerStateID("%s")' % tok
        # TypeName[Some Name]
        m = re.fullmatch(r"(?i)typename\[(.+?)\]", tok)
        if m:
            return 'TypeNameID("%s")' % m.group(1).strip()
        # numeric alias / literal (incl. -0x20000 / +1)
        if tok.lower() in self.num_alias:
            return self.num_alias[tok.lower()]
        if NUM_RE.fullmatch(tok):
            return tok
        got, _ = self.resolve_lvalue(tok)
        if got is not None:
            return got
        base = self.var_alias.get(tok.lower(), tok)
        # verified global variable (GameConfig + decomp runtime registrations)
        if base.lower() in GLOBAL_VARS_CI or base.lower().startswith("game."):
            return 'GVar("%s")' % base
        # ALL-CAPS identifier -> engine enum / common-alias constant that exists
        # as a C++ define/enum with the same value (ANI_*, C_BOX, FX_FLIP, INK_*,
        # FLIP_*, TILEINFO_*, RETRO_WP7, ...). Passed through by name.
        if re.fullmatch(r"[A-Z_][A-Z0-9_]*", base):
            return base
        # A mixed-case bare identifier used as a value is a SCRIPT FUNCTION name.
        # RSDK compiles a function name to its runtime function-ID (scripts stash
        # IDs in Value/Rotation fields, then CallFunction(thatValue) later). We
        # resolve the ID at runtime by name; -1 if the function isn't loaded.
        if re.fullmatch(r"[A-Za-z_]\w*", base):
            return 'ScriptFuncID("%s")' % base
        self.warn("expr '%s'" % tok)
        return "/*TODO expr: %s*/ 0" % tok

    def split_args(self, s):
        args, depth, cur, in_str = [], 0, "", False
        for c in s:
            if c == '"':
                in_str = not in_str
            if not in_str:
                if c in "[(":
                    depth += 1
                elif c in "])":
                    depth -= 1
                elif c == "," and depth == 0:
                    args.append(cur); cur = ""
                    continue
            cur += c
        if cur.strip():
            args.append(cur)
        return [a.strip() for a in args]

    # ---- statement translation -----------------------------------------
    def statement(self, line):
        s = line.strip()
        # increment / decrement
        m = re.fullmatch(r"(.+?)\s*\+\+", s)
        if m:
            return self._incdec(m.group(1), "+")
        m = re.fullmatch(r"(.+?)\s*--", s)
        if m:
            return self._incdec(m.group(1), "-")
        # assignment
        m = ASSIGN_RE.match(s)
        if m:
            lhs, op, rhs = m.group(1).strip(), m.group(2), m.group(3).strip()
            get, set_fmt = self.resolve_lvalue(lhs)
            r = self.expr(rhs)
            if set_fmt is None:
                if get is None:
                    get = self.expr(lhs)  # may warn
                return "%s %s %s;" % (get, op, r)
            if op == "=":
                return set_fmt.replace("{v}", r)
            return set_fmt.replace("{v}", "%s %s (%s)" % (get, op[:-1], r))
        # function call
        m = re.fullmatch(r"(\w+)\((.*)\)", s)
        if m:
            name, argstr = m.group(1), m.group(2)
            low = name.lower()
            rawargs = self.split_args(argstr)
            if low == "callfunction":
                return self._callfunction(rawargs[0])
            args = [self.expr(a) for a in rawargs]
            if low in FUNC_CI:
                r = FUNC_CI[low](args)
                return [x if x.endswith(";") else x + ";" for x in r] if isinstance(r, list) else r + ";"
            if low in self.defined or low in self.declared:
                return self._callfunction(name)
            self.warn("func %s" % name)
            return "/*TODO func: %s*/ %s(%s);" % (name, name, ", ".join(args))
        self.warn("stmt '%s'" % s)
        return "/*TODO stmt: %s*/" % s

    def _callfunction(self, fn):
        low = fn.lower()
        # defined in this file -> direct native call
        if low in self.defined:
            return "%s();" % cpp_ident(self.defined[low])
        # a variable holding a function ID -> dynamic dispatch
        got, _ = self.resolve_lvalue(fn)
        if got is None and low in self.num_alias:
            got = self.num_alias[low]
        if got is not None:
            return "CallScriptFunction(%s, scriptSub);" % got
        # cross-file script function (with or without a #function declaration —
        # the text compiler resolves undeclared names against functions that
        # earlier-parsed scripts registered): route through the hybrid
        # dispatcher — native if that object is already converted, interpreter
        # otherwise.
        if low in self.declared:
            return 'CallScriptFunctionNamed("%s", scriptSub);' % self.declared[low]
        if re.fullmatch(r"[A-Za-z_]\w*", fn):
            return 'CallScriptFunctionNamed("%s", scriptSub);' % fn
        self.warn("func-ref %s" % fn)
        return "/*TODO CallFunction: %s*/" % fn

    def _incdec(self, lhs, sign):
        get, set_fmt = self.resolve_lvalue(lhs)
        if set_fmt is None:
            if get is None:
                get = self.expr(lhs)
            return "%s%s%s;" % (get, sign, sign)
        return set_fmt.replace("{v}", "%s %s 1" % (get, sign))

    def cond(self, s):
        m = CMP_RE.search(s)
        if m:
            return "%s %s %s" % (self.expr(s[:m.start()]), m.group(1), self.expr(s[m.end():]))
        return "(%s) != 0" % self.expr(s)  # bare truthy (rare)

    # ---- block translation ----------------------------------------------
    def block(self, lines):
        out, i = [], 0
        while i < len(lines):
            s = lines[i].strip()
            if s == "":
                i += 1; continue
            low = s.lower()
            if low.startswith("if "):
                out.append("if (%s) {" % self.cond(s[3:]))
            elif low == "else":
                out.append("} else {")
            elif low in ("end if", "endif"):
                out.append("}")
            elif low.startswith("while "):
                out.append("while (%s) {" % self.cond(s[6:]))
            elif low == "loop":
                out.append("}")
            elif low.startswith("switch "):
                out.append("switch (%s) {" % self.expr(s[7:]))
            elif low.startswith("case "):
                out.append("case %s:" % self.expr(s[5:]))
            elif low == "default":
                out.append("default:")
            elif low == "break":
                out.append("break;")
            elif low in ("end switch", "endswitch"):
                out.append("}")
            elif low in ("end sub", "end function", "endfunction"):
                pass
            else:
                st = self.statement(s)
                if isinstance(st, list):
                    out.extend(st)
                else:
                    out.append(st)
            i += 1
        return out

# ---- top-level file conversion ------------------------------------------
def convert(path, objname):
    t = Transpiler()
    lines = t.preprocess(open(path, encoding="utf-8", errors="replace").read())
    # split into subs / functions
    blocks, cur, curname, kind = {}, [], None, None
    for line in lines:
        s = line.strip()
        m = re.match(r"(sub|function)\s+(\w+)", s, re.I)
        if m:
            if curname:
                blocks[curname] = (kind, cur)
            kind, curname, cur = m.group(1).lower(), m.group(2), []
        elif curname is not None:
            cur.append(line)
    if curname:
        blocks[curname] = (kind, cur)

    body = []
    order = ["ObjectStartup", "ObjectMain", "ObjectPlayerInteraction", "ObjectDraw"]
    names = [n for n in order if n in blocks] + [n for n in blocks if n not in order and not n.startswith("RSDK")]
    for name in names:
        kind, blk = blocks[name]
        code = fix_empty_labels(t.block(blk))
        code = indent(code)
        joined = "\n".join(code)
        pre = []
        if "self->" in joined:
            pre.append("Entity *self = Self();")
        fn = cpp_ident(name)
        body.append("void %s::%s()\n{" % (objname, fn))
        body += ["    " + p for p in pre]
        if pre:
            body.append("")
        body += code
        body.append("}\n")
    return t, body, names

def fix_empty_labels(lines):
    """A `case X:` / `default:` immediately followed by `}` (empty trailing case,
    e.g. a script `case N` right before `endswitch`) is ill-formed pre-C++23
    (C5299: label at end of compound statement). Give it an empty statement."""
    out = []
    for i, ln in enumerate(lines):
        out.append(ln)
        s = ln.strip()
        if s.startswith("case ") or s == "default:":
            # find next non-blank line
            j = i + 1
            while j < len(lines) and lines[j].strip() == "":
                j += 1
            if j >= len(lines) or lines[j].strip().startswith("}"):
                out.append(";")
    return out


def indent(lines):
    """Re-indent brace-delimited C++ lines for readability."""
    out, depth = [], 1
    for ln in lines:
        s = ln.strip()
        opens = s.count("{") - s.count("}")
        if s.startswith("}") or s.startswith("case ") or s.startswith("default:") or s.startswith("break"):
            d = depth - 1
        else:
            d = depth
        if s.startswith("case ") or s.startswith("default:") or s.startswith("break"):
            d = depth  # cases sit one in from switch body
        out.append("    " * max(d, 1) + s)
        depth += opens
        if depth < 1:
            depth = 1
    return out

SUB2HOOK = {"ObjectMain": "subMain", "ObjectPlayerInteraction": "subPlayerInteraction",
            "ObjectDraw": "subDraw", "ObjectStartup": "subSetup"}

def write_files(src, obj, outdir):
    t, body, names = convert(src, obj)
    guard = obj.upper() + "_H"
    pub = [n for n in names if n not in SUB2HOOK]
    hdr = ["#ifndef " + guard, "#define " + guard, "",
           '#include "RetroEngine.hpp"', "#if RETRO_USE_NATIVE_OBJECTS",
           '#include "NativeScriptOps.hpp"', "",
           "namespace %s {" % obj]
    for n in names:
        hdr.append("void %s();" % cpp_ident(n))
    if pub:
        hdr.append("extern const Native::NativeFunctionDef funcs[%d];" % len(pub))
    hdr += ["}", "", "#endif", "#endif // " + guard, ""]
    cpp = ['#include "RetroEngine.hpp"', "#if RETRO_USE_NATIVE_OBJECTS", "",
           '#include "%s.hpp"' % obj, '#include "GameConstants.hpp"',
           '#include "PlayerConstants.hpp"', '#include "PlayerFields.hpp"',
           '#include "NativeScriptOps.hpp"', "",
           "using namespace Native;", "",
           "// AUTO-GENERATED from %s by retroscript2cpp.py. Faithful transliteration;" % os.path.basename(src),
           "// review, then move to hand-maintained once verified.", ""]
    cpp += body
    # public function table — collected per stage by InitNativeObjects so
    # cross-object CallScriptFunctionNamed routes natively
    if pub:
        cpp += ["const Native::NativeFunctionDef %s::funcs[%d] = {" % (obj, len(pub))]
        for n in pub:
            cpp.append('    { "%s", %s::%s },' % (n, obj, cpp_ident(n)))
        cpp += ["};", ""]
    cpp += ["#endif // RETRO_USE_NATIVE_OBJECTS", ""]
    _write_if_changed(os.path.join(outdir, obj + ".hpp"), "\n".join(hdr))
    _write_if_changed(os.path.join(outdir, obj + ".cpp"), "\n".join(cpp))
    # registry line: name, main, playerInteraction, draw, setup
    slot = {"subMain": "nullptr", "subPlayerInteraction": "nullptr", "subDraw": "nullptr", "subSetup": "nullptr"}
    for n in names:
        if n in SUB2HOOK:
            slot[SUB2HOOK[n]] = "%s::%s" % (obj, cpp_ident(n))
    reg = '{ "%s", %s, %s, %s, %s },' % (objdisplayname(src), slot["subMain"],
          slot["subPlayerInteraction"], slot["subDraw"], slot["subSetup"])
    return t, names, reg

def objdisplayname(src):
    return os.path.splitext(os.path.basename(src))[0]

def _write_if_changed(path, content):
    """Skip the write when content is unchanged so timestamps stay put and
    incremental builds only recompile objects that actually changed."""
    try:
        if open(path, encoding="utf-8").read() == content:
            return
    except OSError:
        pass
    open(path, "w", encoding="utf-8").write(content)

if __name__ == "__main__":
    src, obj = sys.argv[1], sys.argv[2]
    if len(sys.argv) > 3:
        t, names, reg = write_files(src, obj, sys.argv[3])
        sys.stderr.write("wrote %s.hpp/.cpp  subs=%s  warnings=%d\n" % (obj, names, len(t.warnings)))
        sys.stderr.write("REGISTRY: " + reg + "\n")
        if t.warnings:
            sys.stderr.write("UNMAPPED:\n  " + "\n  ".join(t.warnings) + "\n")
    else:
        t, body, names = convert(src, obj)
        print("// AUTO-GENERATED from %s by retroscript2cpp.py — review before use." % os.path.basename(src))
        print("\n".join(body))
        if t.warnings:
            sys.stderr.write("UNMAPPED (%d):\n  " % len(t.warnings) + "\n  ".join(t.warnings) + "\n")

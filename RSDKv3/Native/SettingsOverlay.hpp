#ifndef SETTINGS_OVERLAY_H
#define SETTINGS_OVERLAY_H

// =============================================================================
//  Settings Overlay  (SonicCD-Native)
// -----------------------------------------------------------------------------
//  A self-contained in-game Display Settings panel, openable anywhere with F8.
//  It draws directly into the engine framebuffer (so it needs no game assets or
//  script-menu plumbing) and applies Resolution / Window Scale, Fullscreen,
//  VSync and the Scaling filter LIVE, persisting them to settings.ini on close.
//
//  Hooks (all guarded so the engine builds unchanged if this is removed):
//    * ProcessEvents  (RetroEngine.cpp) -> HandleKeyDown  on every SDL keydown
//    * after ProcessInput (RetroEngine.cpp) -> FreezeGameInput while open
//    * top of FlipScreen (Drawing.cpp)  -> Draw           over the finished frame
// =============================================================================

#if RETRO_USE_NATIVE_OBJECTS

namespace SettingsOverlay
{
bool IsOpen();
// Returns true if the key was consumed by the overlay (so the caller skips its
// own handling for that key).
bool HandleKeyDown(int keysym, int mod);
// While open, neutralise this frame's game input so navigation doesn't leak
// into gameplay.
void FreezeGameInput();
// Draw the panel into the engine framebuffer (no-op when closed).
void Draw();
}

#endif // RETRO_USE_NATIVE_OBJECTS
#endif // !SETTINGS_OVERLAY_H

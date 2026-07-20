#include "RetroEngine.hpp"

#if RETRO_USE_NATIVE_OBJECTS

#include "SettingsOverlay.hpp"
#include "Input.hpp"

// =============================================================================
//  Self-contained Display Settings overlay. No game assets, no script menus —
//  it renders with an embedded 5x7 font straight into the RGB565 framebuffer.
// =============================================================================

namespace SettingsOverlay
{
// ---- embedded 5x7 font ------------------------------------------------------
// Each glyph is 7 rows; the low 5 bits of each row are pixels, bit4 = leftmost.
// Hand-designed so the exact bit patterns are verifiable at a glance.
struct Glyph {
    char c;
    unsigned char rows[7];
};

static const Glyph FONT[] = {
    { 'A', { 0b01110, 0b10001, 0b10001, 0b11111, 0b10001, 0b10001, 0b10001 } },
    { 'B', { 0b11110, 0b10001, 0b10001, 0b11110, 0b10001, 0b10001, 0b11110 } },
    { 'C', { 0b01110, 0b10001, 0b10000, 0b10000, 0b10000, 0b10001, 0b01110 } },
    { 'D', { 0b11110, 0b10001, 0b10001, 0b10001, 0b10001, 0b10001, 0b11110 } },
    { 'E', { 0b11111, 0b10000, 0b10000, 0b11110, 0b10000, 0b10000, 0b11111 } },
    { 'F', { 0b11111, 0b10000, 0b10000, 0b11110, 0b10000, 0b10000, 0b10000 } },
    { 'G', { 0b01110, 0b10001, 0b10000, 0b10111, 0b10001, 0b10001, 0b01111 } },
    { 'H', { 0b10001, 0b10001, 0b10001, 0b11111, 0b10001, 0b10001, 0b10001 } },
    { 'I', { 0b01110, 0b00100, 0b00100, 0b00100, 0b00100, 0b00100, 0b01110 } },
    { 'J', { 0b00111, 0b00010, 0b00010, 0b00010, 0b00010, 0b10010, 0b01100 } },
    { 'K', { 0b10001, 0b10010, 0b10100, 0b11000, 0b10100, 0b10010, 0b10001 } },
    { 'L', { 0b10000, 0b10000, 0b10000, 0b10000, 0b10000, 0b10000, 0b11111 } },
    { 'M', { 0b10001, 0b11011, 0b10101, 0b10101, 0b10001, 0b10001, 0b10001 } },
    { 'N', { 0b10001, 0b10001, 0b11001, 0b10101, 0b10011, 0b10001, 0b10001 } },
    { 'O', { 0b01110, 0b10001, 0b10001, 0b10001, 0b10001, 0b10001, 0b01110 } },
    { 'P', { 0b11110, 0b10001, 0b10001, 0b11110, 0b10000, 0b10000, 0b10000 } },
    { 'Q', { 0b01110, 0b10001, 0b10001, 0b10001, 0b10101, 0b10010, 0b01101 } },
    { 'R', { 0b11110, 0b10001, 0b10001, 0b11110, 0b10100, 0b10010, 0b10001 } },
    { 'S', { 0b01111, 0b10000, 0b10000, 0b01110, 0b00001, 0b00001, 0b11110 } },
    { 'T', { 0b11111, 0b00100, 0b00100, 0b00100, 0b00100, 0b00100, 0b00100 } },
    { 'U', { 0b10001, 0b10001, 0b10001, 0b10001, 0b10001, 0b10001, 0b01110 } },
    { 'V', { 0b10001, 0b10001, 0b10001, 0b10001, 0b10001, 0b01010, 0b00100 } },
    { 'W', { 0b10001, 0b10001, 0b10001, 0b10101, 0b10101, 0b11011, 0b10001 } },
    { 'X', { 0b10001, 0b10001, 0b01010, 0b00100, 0b01010, 0b10001, 0b10001 } },
    { 'Y', { 0b10001, 0b10001, 0b01010, 0b00100, 0b00100, 0b00100, 0b00100 } },
    { 'Z', { 0b11111, 0b00001, 0b00010, 0b00100, 0b01000, 0b10000, 0b11111 } },
    { '0', { 0b01110, 0b10001, 0b10011, 0b10101, 0b11001, 0b10001, 0b01110 } },
    { '1', { 0b00100, 0b01100, 0b00100, 0b00100, 0b00100, 0b00100, 0b01110 } },
    { '2', { 0b01110, 0b10001, 0b00001, 0b00110, 0b01000, 0b10000, 0b11111 } },
    { '3', { 0b11111, 0b00010, 0b00100, 0b00010, 0b00001, 0b10001, 0b01110 } },
    { '4', { 0b00010, 0b00110, 0b01010, 0b10010, 0b11111, 0b00010, 0b00010 } },
    { '5', { 0b11111, 0b10000, 0b11110, 0b00001, 0b00001, 0b10001, 0b01110 } },
    { '6', { 0b00110, 0b01000, 0b10000, 0b11110, 0b10001, 0b10001, 0b01110 } },
    { '7', { 0b11111, 0b00001, 0b00010, 0b00100, 0b01000, 0b01000, 0b01000 } },
    { '8', { 0b01110, 0b10001, 0b10001, 0b01110, 0b10001, 0b10001, 0b01110 } },
    { '9', { 0b01110, 0b10001, 0b10001, 0b01111, 0b00001, 0b00010, 0b01100 } },
    { ':', { 0b00000, 0b01100, 0b01100, 0b00000, 0b01100, 0b01100, 0b00000 } },
    { '.', { 0b00000, 0b00000, 0b00000, 0b00000, 0b00000, 0b01100, 0b01100 } },
    { '-', { 0b00000, 0b00000, 0b00000, 0b11111, 0b00000, 0b00000, 0b00000 } },
    { '/', { 0b00001, 0b00010, 0b00010, 0b00100, 0b01000, 0b01000, 0b10000 } },
    { '<', { 0b00010, 0b00100, 0b01000, 0b10000, 0b01000, 0b00100, 0b00010 } },
    { '>', { 0b01000, 0b00100, 0b00010, 0b00001, 0b00010, 0b00100, 0b01000 } },
    { '(', { 0b00010, 0b00100, 0b01000, 0b01000, 0b01000, 0b00100, 0b00010 } },
    { ')', { 0b01000, 0b00100, 0b00010, 0b00010, 0b00010, 0b00100, 0b01000 } },
    { '+', { 0b00000, 0b00100, 0b00100, 0b11111, 0b00100, 0b00100, 0b00000 } },
    { '!', { 0b00100, 0b00100, 0b00100, 0b00100, 0b00100, 0b00000, 0b00100 } },
    { '%', { 0b11001, 0b11010, 0b00010, 0b00100, 0b01000, 0b01011, 0b10011 } },
};
static const int FONT_COUNT = sizeof(FONT) / sizeof(FONT[0]);

static const unsigned char *glyphRows(char c)
{
    if (c >= 'a' && c <= 'z')
        c -= 32; // fold to uppercase
    for (int i = 0; i < FONT_COUNT; ++i) {
        if (FONT[i].c == c)
            return FONT[i].rows;
    }
    return nullptr; // space / unknown -> blank
}

// ---- framebuffer drawing ----------------------------------------------------
static inline ushort rgb565(int r, int g, int b)
{
    return (ushort)(((r >> 3) << 11) | ((g >> 2) << 5) | (b >> 3));
}

static inline void putPixel(int x, int y, ushort col)
{
    if (x < 0 || y < 0 || x >= SCREEN_XSIZE || y >= SCREEN_YSIZE)
        return;
    Engine.frameBuffer[x + y * GFX_LINESIZE] = col;
}

static void fillRect(int x, int y, int w, int h, ushort col)
{
    for (int j = 0; j < h; ++j)
        for (int i = 0; i < w; ++i) putPixel(x + i, y + j, col);
}

// 50% checkerboard darkening of a rect (cheap translucency without alpha math).
static void dimRect(int x, int y, int w, int h)
{
    for (int j = 0; j < h; ++j) {
        for (int i = 0; i < w; ++i) {
            if ((i + j) & 1)
                putPixel(x + i, y + j, 0);
        }
    }
}

static int textWidth(const char *s, int scale) { return (int)strlen(s) * 6 * scale; }

static void drawText(int x, int y, const char *s, ushort col, int scale)
{
    for (; *s; ++s) {
        const unsigned char *g = glyphRows(*s);
        if (g) {
            for (int ry = 0; ry < 7; ++ry) {
                for (int rx = 0; rx < 5; ++rx) {
                    if (g[ry] & (0x10 >> rx))
                        fillRect(x + rx * scale, y + ry * scale, scale, scale, col);
                }
            }
        }
        x += 6 * scale;
    }
}

static void drawTextR(int right, int y, const char *s, ushort col, int scale) { drawText(right - textWidth(s, scale), y, s, col, scale); }

// ---- options model ----------------------------------------------------------
enum Option { OPT_SCALE, OPT_FULLSCREEN, OPT_VSYNC, OPT_FILTER, OPT_COUNT };

static bool s_open      = false;
static int s_selected   = 0;

static const char *filterName(int mode)
{
    switch (mode) {
        case 0: return "NEAREST";
        case 1: return "INTEGER";
        case 2: return "SHARP";
        case 3: return "BILINEAR";
        default: return "NEAREST";
    }
}

static const char *optionLabel(int opt)
{
    switch (opt) {
        case OPT_SCALE: return "WINDOW SCALE";
        case OPT_FULLSCREEN: return "FULLSCREEN";
        case OPT_VSYNC: return "VSYNC";
        case OPT_FILTER: return "SCALING FILTER";
        default: return "";
    }
}

static void optionValue(int opt, char *out)
{
    switch (opt) {
        case OPT_SCALE: sprintf(out, "%dX", Engine.windowScale); break;
        case OPT_FULLSCREEN: strcpy(out, Engine.isFullScreen ? "ON" : "OFF"); break;
        case OPT_VSYNC: strcpy(out, Engine.vsync ? "ON" : "OFF"); break;
        case OPT_FILTER: strcpy(out, filterName(Engine.scalingMode)); break;
        default: out[0] = 0; break;
    }
}

// ---- live apply -------------------------------------------------------------
static void applyWindowScale()
{
#if RETRO_USING_SDL2
    if (!Engine.isFullScreen && Engine.window) {
        SDL_SetWindowSize(Engine.window, SCREEN_XSIZE_CONFIG * Engine.windowScale, SCREEN_YSIZE * Engine.windowScale);
        SDL_SetWindowPosition(Engine.window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
    }
#endif
}

static void applyFullscreen()
{
    SetFullScreen(Engine.isFullScreen);
}

static void applyVSync()
{
#if RETRO_USING_SDL2 && !RETRO_USING_OPENGL && SDL_VERSION_ATLEAST(2, 0, 18)
    if (Engine.renderer)
        SDL_RenderSetVSync(Engine.renderer, Engine.vsync ? 1 : 0);
#endif
    // Engine.vsync also gates the frame limiter in RetroEngine::Run, so toggling
    // the field is enough for the timing side.
}

static void adjust(int opt, int dir)
{
    switch (opt) {
        case OPT_SCALE: {
            int s = Engine.windowScale + dir;
            if (s < 1) s = 1;
            if (s > 6) s = 6;
            Engine.windowScale = s;
            applyWindowScale();
            break;
        }
        case OPT_FULLSCREEN:
            Engine.isFullScreen = !Engine.isFullScreen;
            applyFullscreen();
            break;
        case OPT_VSYNC:
            Engine.vsync = !Engine.vsync;
            applyVSync();
            break;
        case OPT_FILTER:
            Engine.scalingMode = (Engine.scalingMode + dir + 4) % 4; // live: read each frame in FlipScreen
            break;
        default: break;
    }
}

static void saveAndClose()
{
    // WriteSettings persists Engine.startFullScreen for [Window] FullScreen, so
    // mirror the live fullscreen state before writing.
    Engine.startFullScreen = Engine.isFullScreen;
    WriteSettings();
    s_open = false;
}

// ---- public API -------------------------------------------------------------
bool IsOpen() { return s_open; }

bool HandleKeyDown(int keysym, int mod)
{
    (void)mod;
#if RETRO_USING_SDL2
    if (!s_open) {
        if (keysym == SDLK_F8) {
            s_open     = true;
            s_selected = 0;
            return true;
        }
        return false;
    }

    switch (keysym) {
        case SDLK_F8:
        case SDLK_ESCAPE: saveAndClose(); return true;
        case SDLK_UP: s_selected = (s_selected + OPT_COUNT - 1) % OPT_COUNT; return true;
        case SDLK_DOWN: s_selected = (s_selected + 1) % OPT_COUNT; return true;
        case SDLK_LEFT: adjust(s_selected, -1); return true;
        case SDLK_RIGHT: adjust(s_selected, +1); return true;
        case SDLK_RETURN:
        case SDLK_SPACE: adjust(s_selected, +1); return true;
        default: return true; // swallow everything else while open
    }
#else
    return false;
#endif
}

void FreezeGameInput()
{
    if (!s_open)
        return;
    keyDown  = InputData();
    keyPress = InputData();
    anyPress = false;
}

void Draw()
{
    if (!s_open)
        return;

    const int scale = 2;
    const int panelW = (SCREEN_XSIZE - 48 < 360) ? SCREEN_XSIZE - 48 : 360;
    const int panelH = 176;
    const int px     = (SCREEN_XSIZE - panelW) / 2;
    const int py     = (SCREEN_YSIZE - panelH) / 2;

    // dim the whole screen, then a solid bordered panel
    dimRect(0, 0, SCREEN_XSIZE, SCREEN_YSIZE);
    fillRect(px, py, panelW, panelH, rgb565(14, 18, 46));
    fillRect(px, py, panelW, 3, rgb565(84, 132, 236));
    fillRect(px, py + panelH - 3, panelW, 3, rgb565(84, 132, 236));
    fillRect(px, py, 3, panelH, rgb565(84, 132, 236));
    fillRect(px + panelW - 3, py, 3, panelH, rgb565(84, 132, 236));

    // title
    const char *title = "DISPLAY SETTINGS";
    drawText(px + (panelW - textWidth(title, scale)) / 2, py + 12, title, rgb565(255, 214, 0), scale);
    fillRect(px + 16, py + 34, panelW - 32, 1, rgb565(60, 76, 150));

    // option rows
    const int rowY0 = py + 46;
    const int rowH  = 26;
    for (int i = 0; i < OPT_COUNT; ++i) {
        int ry = rowY0 + i * rowH;
        bool sel = (i == s_selected);
        if (sel)
            fillRect(px + 8, ry - 4, panelW - 16, rowH - 4, rgb565(38, 54, 128));

        ushort labelCol = sel ? rgb565(255, 255, 255) : rgb565(206, 214, 230);
        ushort valCol   = sel ? rgb565(150, 230, 255) : rgb565(110, 190, 240);

        if (sel)
            drawText(px + 14, ry, ">", rgb565(255, 214, 0), scale);
        drawText(px + 30, ry, optionLabel(i), labelCol, scale);

        char val[32];
        optionValue(i, val);
        // show arrows around adjustable values on the selected row
        if (sel) {
            drawTextR(px + panelW - 18, ry, ">", rgb565(255, 214, 0), scale);
            drawTextR(px + panelW - 30, ry, val, valCol, scale);
            drawTextR(px + panelW - 30 - textWidth(val, scale) - 6, ry, "<", rgb565(255, 214, 0), scale);
        }
        else {
            drawTextR(px + panelW - 18, ry, val, valCol, scale);
        }
    }

    // footer hint
    const char *hint = "ARROWS - ADJUST    F8 - SAVE + CLOSE";
    drawText(px + (panelW - textWidth(hint, 1)) / 2, py + panelH - 16, hint, rgb565(150, 156, 180), 1);
}
} // namespace SettingsOverlay

#endif // RETRO_USE_NATIVE_OBJECTS

# Sonic-CD-2026-Remaster

A source port and remaster of Sonic CD built on the RSDKv3 engine.

This repository contains the engine source, remastered native menu/UI code, data assets, and platform build files for Linux, Windows, and Android. It is designed to build a playable Sonic CD remaster with modern engine improvements, native object support, and enhanced menu overlays.

## Features

- RSDKv3-based Sonic CD engine source
- Native object layer and remastered menu overlays
- SDL2 (default) and SDL1 support
- Optional hardware rendering via OpenGL/GLEW
- Custom settings overlay, remastered main menu, pause menu, and soundtrack selector
- Build support for Linux, Windows, and Android

## Repository layout

- `CMakeLists.txt` - top-level build script and engine source list
- `platforms/` - platform-specific CMake configuration for Linux, Windows, and Android
- `RSDKv3/` - engine source files and native remaster implementation
- `Data/` - game data assets used by the engine
- `dependencies/` - bundled third-party libraries and dependency build support
- `tools/` - build/transpile helper scripts
- `build.bat` - Windows build script for Visual Studio + vcpkg

## Prerequisites

### Linux

- `cmake` (>= 3.10)
- `pkg-config`
- SDL2 development libraries (or SDL1 if building with `-DRETRO_SDL_VERSION=1`)
- `libogg`, `libvorbis`, and `libtheora` development libraries
- Optional: `glew` if `RETRO_USE_HW_RENDER` is enabled

### Windows

- Visual Studio 2022 / 2026 (or compatible MSVC toolchain)
- `vcpkg` configured if using `build.bat`
- SDL2 development libraries, plus libogg, libvorbis, libtheora, and optionally GLEW

### Android

- Android NDK and appropriate CMake/Gradle tooling
- SDL2 and required Android system libraries

## Building

### Linux

From the repository root:

```bash
mkdir -p build && cd build
cmake .. -DRETRO_SDL_VERSION=2 -DRETRO_USE_HW_RENDER=ON
cmake --build . --parallel
```

If pkg-config does not find the libraries automatically, install the matching development packages for your distribution or provide custom paths.

To build with SDL1 instead:

```bash
cmake .. -DRETRO_SDL_VERSION=1
cmake --build . --parallel
```

### Windows

Use the provided `build.bat` with Visual Studio and vcpkg:

```batch
build.bat
```

The script expects `VCPKG_ROOT` to point to a valid vcpkg installation and will configure a Visual Studio solution for x64.

### Android

The Android platform file is configured in `platforms/Android.cmake`.
A standard Android NDK/CMake build may use the `Android` platform and set the toolchain accordingly.

## Running the game

- On Windows and Linux, execute the generated `RetroEngine` (or `RSDKv3.exe` when built via the Windows batch script).
- Ensure the `Data/` folder is present next to the executable, or provide `Data.rsdk` if desired.

The engine will load assets from the local `Data/` directory by default.

## Important CMake options

- `-DRETRO_FORCE_CASE_INSENSITIVE=ON` : force case-insensitive file handling
- `-DRETRO_MOD_LOADER=ON|OFF` : enable or disable mod loader support
- `-DRETRO_USE_HW_RENDER=ON|OFF` : enable hardware rendering support
- `-DRETRO_DISABLE_PLUS=ON|OFF` : disable Plus/dev extras for public builds
- `-DRETRO_ORIGINAL_CODE=ON|OFF` : preserve original code behavior (not playable in this repo)
- `-DRETRO_SDL_VERSION=2|1` : select SDL2 (default) or SDL1
- `-DRETRO_OUTPUT_NAME=<name>` : change output executable name

## Notes

- `build.bat` stages the built executable and required DLLs next to the project root and expects the `Data/` folder to remain in place.
- `platforms/Linux.cmake` uses pkg-config to detect SDL2, Ogg, Theora, Vorbis, and optionally GLEW.
- `platforms/Windows.cmake` is intended for use with vcpkg-managed packages when available.
- `Data.rsdk` is the packaged data file used by the engine, but the repo is configured to load loose assets from `Data/` when present.

## License

No repository license file is included in this repository. Review the code and assets before reuse.

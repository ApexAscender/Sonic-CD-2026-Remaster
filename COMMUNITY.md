# Community Guide

Welcome to the Sonic-CD-2026-Remaster community resources. This file provides guidance for contributors, bug reporters, and anyone interested in building or improving the project.

## Getting Help

If you need help with the project, the best approach is:

- Open an issue describing the problem, including:
  - your operating system and build environment
  - the exact command(s) you used
  - any error output or failed build logs
- Include whether you built using `cmake` / `build.bat` / Android tooling
- If the issue is runtime-related, include the engine output and whether `Data/` is present next to the executable

## Reporting Bugs

Please submit bug reports through GitHub Issues.

A good bug report should include:

- Problem summary and expected behavior
- Steps to reproduce
- Build platform and configuration
- Error messages or logs

## Contributing

Contributions are welcome, including:

- Fixes for build issues on Linux, Windows, or Android
- Improvements to the native remastered menu and UI
- Cleanup and organization of `RSDKv3/` source and platform files
- Documentation improvements, including build and usage guides

### How to contribute

1. Fork the repository.
2. Create a feature branch.
3. Make your changes.
4. Test your build on your target platform.
5. Open a pull request with a clear description and summary of changes.

## Preferred Workflow

- Use `cmake` to configure and build on Linux.
- Use `build.bat` with Visual Studio + `vcpkg` for Windows builds.
- For Android, adapt the Android NDK toolchain and verify the `platforms/Android.cmake` settings.

## Community Guidelines

- Be respectful and constructive.
- Keep discussions focused on the project.
- Share enough context to make your issue or pull request actionable.

## Notes

- There is no license file included in this repository. Before using or redistributing code or assets, verify the license status separately.
- The project currently targets the RSDKv3 engine with a custom remastered menu and native object layer.

## Files of interest

- `README.md` — project overview and build instructions
- `CMakeLists.txt` — top-level build settings and engine source list
- `platforms/` — platform-specific build configurations
- `RSDKv3/` — engine source, native object code, and remaster implementation
- `Data/` — game assets used by the engine

@echo off
REM ============================================================================
REM  SonicCD-Native build script (MSVC + vcpkg)
REM  Produces the native C++ Sonic CD remaster (RSDKv3 engine + Native object layer).
REM ============================================================================
setlocal
set VCPKG_ROOT=C:\vcpkg
set SRC=%~dp0
REM %~dp0 ends with a backslash; inside quotes that \" escapes the quote and
REM corrupts every cmake argument after it. Strip it.
set SRC=%SRC:~0,-1%
set BUILD=%SRC%\build

echo [1/3] Configuring (Visual Studio 18 2026, x64, vcpkg)...
cmake -S "%SRC%" -B "%BUILD%" ^
  -G "Visual Studio 18 2026" -A x64 ^
  -DCMAKE_TOOLCHAIN_FILE=%VCPKG_ROOT%\scripts\buildsystems\vcpkg.cmake ^
  -DVCPKG_TARGET_TRIPLET=x64-windows ^
  -DCMAKE_CXX_STANDARD=17 ^
  -DRETRO_MOD_LOADER=ON ^
  -DRETRO_USE_HW_RENDER=OFF
if errorlevel 1 goto :fail

echo [2/3] Building (Release)...
cmake --build "%BUILD%" --config Release --parallel
if errorlevel 1 goto :fail

echo [3/3] Staging exe + DLLs next to the loose Data\ folder (assets, NOT Data.rsdk)...
REM The engine uses Data.rsdk only if it sits next to the exe; with none present it
REM reads the loose Data\ folder. We keep the runnable game in the project root so
REM it picks up SonicCD-Native\Data\. Never copy Data.rsdk here.
copy /y "%BUILD%\Release\RSDKv3.exe" "%SRC%\RSDKv3.exe" >nul
copy /y "%BUILD%\Release\*.dll" "%SRC%\" >nul 2>nul
echo.
echo BUILD OK.  Run: "%SRC%\RSDKv3.exe"  (loads .\Data\)
goto :eof

:fail
echo.
echo BUILD FAILED (see output above).
exit /b 1

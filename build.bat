@echo off
:: build.bat -- Copyright @ Amélie Heinrich 2024

set rootDir=%cd%

if not exist run_tree (
    mkdir run_tree
)

set source=%rootDir%/src/*.cpp
set output=-FeTemplate.exe
set includeDirs=-I%rootDir%/ext/include -I%rootDir%/include
set linkDirs=/LIBPATH:%rootDir%/ext/lib
set links=sfml-system.lib sfml-window.lib sfml-graphics.lib user32.lib opengl32.lib freetype.lib winmm.lib gdi32.lib
set flags=-EHsc /std:c++17 -Zi -w /MP -FC -nologo

pushd run_tree
cl %includeDirs% %output% %flags% %source% /link /incremental /DEBUG:FULL %linkDirs% %links%
popd run_tree

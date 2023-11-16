@ECHO OFF
cls
del *.obj *.pdb .*exe *.ilk

@ECHO COMPILER
cl /nologo /Zi /GR- /EHs /W4 /MDd /std:c++latest -I ..\include -I ..\deps\sdl2\include /c ..\src\main.cpp
cl /nologo /Zi /GR- /EHs /W4 /MDd /std:c++latest -I ..\include -I ..\deps\sdl2\include /c ..\src\Application.cpp
cl /nologo /Zi /GR- /EHs /W4 /MDd /std:c++latest -I ..\include -I ..\deps\sdl2\include /c ..\src\Renderer.cpp
cl /nologo /Zi /GR- /EHs /W4 /MDd /std:c++latest -I ..\include -I ..\deps\sdl2\include /c ..\src\Grid.cpp
cl /nologo /Zi /GR- /EHs /W4 /MDd /std:c++latest -I ..\include -I ..\deps\sdl2\include /c ..\src\Agent.cpp
cl /nologo /Zi /GR- /EHs /W4 /MDd /std:c++latest -I ..\include -I ..\deps\sdl2\include /c ..\src\Node.cpp

@ECHO LINKER
cl /nologo /Zi /GR- /EHs /W4 /MDd /Fe:../bin/main.exe *.obj /link /SUBSYSTEM:CONSOLE ..\deps\sdl2\lib\x64\SDL2.lib ..\deps\sdl2\lib\x64\SDL2main.lib opengl32.lib user32.lib gdi32.lib shell32.lib ole32.lib


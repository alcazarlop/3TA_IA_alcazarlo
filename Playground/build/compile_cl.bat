@ECHO OFF
cls
del *.obj *.pdb

cl /nologo /Zi /GR- /EHs /W4 /MDd -I ..\include -I ..\deps\esat\include /c ..\src\*.cpp
cl /nologo /Zi /GR- /EHs /W4 /MDd /Fe:../bin/main.exe *.obj ..\deps\esat\bin\ESAT_d.lib opengl32.lib user32.lib gdi32.lib shell32.lib


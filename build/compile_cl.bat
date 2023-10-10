@ECHO OFF

REM DELETE TEMP FILES
del *.obj *.pdb *.ilk *.exe

REM DEBUG CONFIGURATION

REM COMPILE SOURCE CODE
cl /nologo /Zi /GR- /EHs /W3 /MDd -I ..\include -I ..\deps\esat\include /c ..\src\*.cc

REM LINK PROGRAM
//cl /nologo /Zi /GR- /EHs /W3 /MDd /Fe:arkanoid_d.exe *.obj ..\deps\esat\bin\ESAT_d.lib opengl32.lib user32.lib gdi32.lib shell32.lib /link /IGNORE:4099

REM COPY FILES
xcopy arkanoid_d.exe ..\bin\ /L /Y


REM RELEASE CONFIGURATION

REM COMPILE SOURCE CODE
REM cl /nologo /O2 /GR- /EHs /W3 /MD -I ..\include -I ..\deps\esat\include /c ..\src\*.cc
REM LINK PROGRAM
REM cl /nologo /O2 /GR- /EHs /W3 /MD /Fe:test.exe *.obj ..\deps\esat\bin\ESAT.lib opengl32.lib user32.lib gdi32.lib shell32.lib /link /IGNORE:4099
REM COPY FILES
REM xcopy test.exe ..\bin\ /L /Y


@ECHO OFF

REM DELETE TEMP FILES
del *.obj *.pdb *.ilk *.exe
del "..\bin\*.pdb" "..\bin\*.exe" "..\bin\*.ilk"

REM DEBUG CONFIGURATION

REM COMPILE MATH LIB
cl /nologo /O2 /GR- /EHs /W3 /MD /D_CRT_SECURE_NO_WARNINGS -I ..\include -I ..\deps\esat\include -I ..\deps\math_library\include /c ..\deps\math_library\src\*.cc

REM COMPILE SOURCE CODE
cl /nologo /O2 /GR- /EHs /W3 /MD /D_CRT_SECURE_NO_WARNINGS -I ..\include -I ..\deps\esat\include -I ..\deps\math_library\include /c ..\src\*.cc

REM LINK PROGRAM
cl /nologo /O2 /GR- /EHs /W3 /MD /Fe:../bin/demo.exe *.obj ..\deps\esat\bin\ESAT.lib opengl32.lib user32.lib gdi32.lib shell32.lib /link /IGNORE:4099

if exist "../bin/demo_d.exe" (
  rem En caso de que la compilacion se haya realizado correctamente
  @echo ---------------------------------------------------
  @echo  Compilacion completa.
  @echo ---------------------------------------------------
) else (
  rem En caso de que la compilacion falle y tire errores en el codigo
  @echo ---------------------------------------------------
  @echo  Compilacion fallida.
  @echo ---------------------------------------------------
)
REM COPY FILES
@REM @xcopy arkanoid_d.exe ..\bin\ /L /Y


REM RELEASE CONFIGURATION

REM COMPILE SOURCE CODE
REM cl /nologo /O2 /GR- /EHs /W3 /MD -I ..\include -I ..\deps\esat\include /c ..\src\*.cc
REM LINK PROGRAM
REM cl /nologo /O2 /GR- /EHs /W3 /MD /Fe:arkanoid.exe *.obj ..\deps\esat\bin\ESAT.lib opengl32.lib user32.lib gdi32.lib shell32.lib /link /IGNORE:4099
REM COPY FILES
REM xcopy arkanoid.exe ..\bin\ /L /Y

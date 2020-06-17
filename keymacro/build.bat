gcc main.c keyboard.c keymouse.c fileio.c libstring.c -o keymacro.exe
SET MYPATH=D:\mypath
DEL %MYPATH%\keymacro.exe
COPY keymacro.exe %MYPATH%\keymacro.exe
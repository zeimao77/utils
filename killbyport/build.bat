gcc main.c set.c winlib.c -o killbyport.exe
SET MYPATH=D:\mypath
DEL %MYPATH%\killbyport.exe
COPY killbyport.exe %MYPATH%\killbyport.exe
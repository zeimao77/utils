gcc main.c systemutil.c -o generatePassword.exe
SET MYPATH=D:\mypath
DEL %MYPATH%\generatePassword.exe
COPY generatePassword.exe %MYPATH%\generatePassword.exe
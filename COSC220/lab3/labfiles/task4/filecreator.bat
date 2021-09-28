@echo off
title File Creator
:a
set /p name=Enter the name of your file: 
set /p ext=Enter the extension of your file (Don't include the .): 
echo. > %name%.%ext%
set /p choice=Type 1 to quit. Type 2 to make another file.
if %choice% == 1 goto b
if %choice% == 2 goto a
:b
pause
exit
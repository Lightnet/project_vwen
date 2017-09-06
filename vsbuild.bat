@echo off
call "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Auxiliary\Build\vcvars32.bat"
cd ../../../projects/project_vwen
call scons tool=window
REM pause
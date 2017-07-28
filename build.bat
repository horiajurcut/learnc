@echo off

rd /q /s "build" 2>nul

mkdir build
pushd build
cl -Zi ..\main.c ..\chapters\*.c
popd
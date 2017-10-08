@echo off
call "c:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\vcvarsall.bat"
mkdir ..\..\build
pushd ..\..\build
cl -Zi ..\handmade\code\win32_handmade.cpp user32.lib Gdi32.lib
popd

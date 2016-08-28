set CMAKE_BIN_PATH="C:\Program Files (x86)\CMake\bin"
call %CMAKE_BIN_PATH%\cmake.exe -G "Visual Studio 12 Win64" ..\
call "C:\Program Files (x86)\Microsoft Visual Studio 12.0\Common7\Tools\vsvars32.bat"
devenv Coding.sln
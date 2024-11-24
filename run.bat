@echo off
rem Create the build directory and configure the build
cmake -B build

rem Build the project
cmake --build build

rem Run the executable and save the output to a file
build\Debug\rtiow.exe > image.ppm
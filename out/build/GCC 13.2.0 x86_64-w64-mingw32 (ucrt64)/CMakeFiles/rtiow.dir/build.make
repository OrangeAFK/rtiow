# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.30

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\onepl\OneDrive\Desktop\cpp\rtiow

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\onepl\OneDrive\Desktop\cpp\rtiow\out\build\GCC 13.2.0 x86_64-w64-mingw32 (ucrt64)"

# Include any dependencies generated for this target.
include CMakeFiles/rtiow.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/rtiow.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/rtiow.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/rtiow.dir/flags.make

CMakeFiles/rtiow.dir/main.cpp.obj: CMakeFiles/rtiow.dir/flags.make
CMakeFiles/rtiow.dir/main.cpp.obj: C:/Users/onepl/OneDrive/Desktop/cpp/rtiow/main.cpp
CMakeFiles/rtiow.dir/main.cpp.obj: CMakeFiles/rtiow.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="C:\Users\onepl\OneDrive\Desktop\cpp\rtiow\out\build\GCC 13.2.0 x86_64-w64-mingw32 (ucrt64)\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/rtiow.dir/main.cpp.obj"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/rtiow.dir/main.cpp.obj -MF CMakeFiles\rtiow.dir\main.cpp.obj.d -o CMakeFiles\rtiow.dir\main.cpp.obj -c C:\Users\onepl\OneDrive\Desktop\cpp\rtiow\main.cpp

CMakeFiles/rtiow.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/rtiow.dir/main.cpp.i"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\onepl\OneDrive\Desktop\cpp\rtiow\main.cpp > CMakeFiles\rtiow.dir\main.cpp.i

CMakeFiles/rtiow.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/rtiow.dir/main.cpp.s"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\onepl\OneDrive\Desktop\cpp\rtiow\main.cpp -o CMakeFiles\rtiow.dir\main.cpp.s

# Object files for target rtiow
rtiow_OBJECTS = \
"CMakeFiles/rtiow.dir/main.cpp.obj"

# External object files for target rtiow
rtiow_EXTERNAL_OBJECTS =

rtiow.exe: CMakeFiles/rtiow.dir/main.cpp.obj
rtiow.exe: CMakeFiles/rtiow.dir/build.make
rtiow.exe: CMakeFiles/rtiow.dir/linkLibs.rsp
rtiow.exe: CMakeFiles/rtiow.dir/objects1.rsp
rtiow.exe: CMakeFiles/rtiow.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="C:\Users\onepl\OneDrive\Desktop\cpp\rtiow\out\build\GCC 13.2.0 x86_64-w64-mingw32 (ucrt64)\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable rtiow.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\rtiow.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/rtiow.dir/build: rtiow.exe
.PHONY : CMakeFiles/rtiow.dir/build

CMakeFiles/rtiow.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\rtiow.dir\cmake_clean.cmake
.PHONY : CMakeFiles/rtiow.dir/clean

CMakeFiles/rtiow.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\onepl\OneDrive\Desktop\cpp\rtiow C:\Users\onepl\OneDrive\Desktop\cpp\rtiow "C:\Users\onepl\OneDrive\Desktop\cpp\rtiow\out\build\GCC 13.2.0 x86_64-w64-mingw32 (ucrt64)" "C:\Users\onepl\OneDrive\Desktop\cpp\rtiow\out\build\GCC 13.2.0 x86_64-w64-mingw32 (ucrt64)" "C:\Users\onepl\OneDrive\Desktop\cpp\rtiow\out\build\GCC 13.2.0 x86_64-w64-mingw32 (ucrt64)\CMakeFiles\rtiow.dir\DependInfo.cmake" "--color=$(COLOR)"
.PHONY : CMakeFiles/rtiow.dir/depend

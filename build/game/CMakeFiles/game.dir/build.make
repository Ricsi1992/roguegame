# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.28

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
CMAKE_SOURCE_DIR = C:\CzRProg\Ricsi_programozas\C++\workspace\roguegame

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\CzRProg\Ricsi_programozas\C++\workspace\roguegame\build

# Include any dependencies generated for this target.
include game/CMakeFiles/game.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include game/CMakeFiles/game.dir/compiler_depend.make

# Include the progress variables for this target.
include game/CMakeFiles/game.dir/progress.make

# Include the compile flags for this target's objects.
include game/CMakeFiles/game.dir/flags.make

game/CMakeFiles/game.dir/src/ASCIIRenderEngine.cpp.obj: game/CMakeFiles/game.dir/flags.make
game/CMakeFiles/game.dir/src/ASCIIRenderEngine.cpp.obj: game/CMakeFiles/game.dir/includes_CXX.rsp
game/CMakeFiles/game.dir/src/ASCIIRenderEngine.cpp.obj: C:/CzRProg/Ricsi_programozas/C++/workspace/roguegame/game/src/ASCIIRenderEngine.cpp
game/CMakeFiles/game.dir/src/ASCIIRenderEngine.cpp.obj: game/CMakeFiles/game.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\CzRProg\Ricsi_programozas\C++\workspace\roguegame\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object game/CMakeFiles/game.dir/src/ASCIIRenderEngine.cpp.obj"
	cd /d C:\CzRProg\Ricsi_programozas\C++\workspace\roguegame\build\game && C:\MinGW\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT game/CMakeFiles/game.dir/src/ASCIIRenderEngine.cpp.obj -MF CMakeFiles\game.dir\src\ASCIIRenderEngine.cpp.obj.d -o CMakeFiles\game.dir\src\ASCIIRenderEngine.cpp.obj -c C:\CzRProg\Ricsi_programozas\C++\workspace\roguegame\game\src\ASCIIRenderEngine.cpp

game/CMakeFiles/game.dir/src/ASCIIRenderEngine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/game.dir/src/ASCIIRenderEngine.cpp.i"
	cd /d C:\CzRProg\Ricsi_programozas\C++\workspace\roguegame\build\game && C:\MinGW\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\CzRProg\Ricsi_programozas\C++\workspace\roguegame\game\src\ASCIIRenderEngine.cpp > CMakeFiles\game.dir\src\ASCIIRenderEngine.cpp.i

game/CMakeFiles/game.dir/src/ASCIIRenderEngine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/game.dir/src/ASCIIRenderEngine.cpp.s"
	cd /d C:\CzRProg\Ricsi_programozas\C++\workspace\roguegame\build\game && C:\MinGW\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\CzRProg\Ricsi_programozas\C++\workspace\roguegame\game\src\ASCIIRenderEngine.cpp -o CMakeFiles\game.dir\src\ASCIIRenderEngine.cpp.s

game/CMakeFiles/game.dir/src/GameEngine.cpp.obj: game/CMakeFiles/game.dir/flags.make
game/CMakeFiles/game.dir/src/GameEngine.cpp.obj: game/CMakeFiles/game.dir/includes_CXX.rsp
game/CMakeFiles/game.dir/src/GameEngine.cpp.obj: C:/CzRProg/Ricsi_programozas/C++/workspace/roguegame/game/src/GameEngine.cpp
game/CMakeFiles/game.dir/src/GameEngine.cpp.obj: game/CMakeFiles/game.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\CzRProg\Ricsi_programozas\C++\workspace\roguegame\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object game/CMakeFiles/game.dir/src/GameEngine.cpp.obj"
	cd /d C:\CzRProg\Ricsi_programozas\C++\workspace\roguegame\build\game && C:\MinGW\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT game/CMakeFiles/game.dir/src/GameEngine.cpp.obj -MF CMakeFiles\game.dir\src\GameEngine.cpp.obj.d -o CMakeFiles\game.dir\src\GameEngine.cpp.obj -c C:\CzRProg\Ricsi_programozas\C++\workspace\roguegame\game\src\GameEngine.cpp

game/CMakeFiles/game.dir/src/GameEngine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/game.dir/src/GameEngine.cpp.i"
	cd /d C:\CzRProg\Ricsi_programozas\C++\workspace\roguegame\build\game && C:\MinGW\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\CzRProg\Ricsi_programozas\C++\workspace\roguegame\game\src\GameEngine.cpp > CMakeFiles\game.dir\src\GameEngine.cpp.i

game/CMakeFiles/game.dir/src/GameEngine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/game.dir/src/GameEngine.cpp.s"
	cd /d C:\CzRProg\Ricsi_programozas\C++\workspace\roguegame\build\game && C:\MinGW\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\CzRProg\Ricsi_programozas\C++\workspace\roguegame\game\src\GameEngine.cpp -o CMakeFiles\game.dir\src\GameEngine.cpp.s

game/CMakeFiles/game.dir/src/GameStateHandler.cpp.obj: game/CMakeFiles/game.dir/flags.make
game/CMakeFiles/game.dir/src/GameStateHandler.cpp.obj: game/CMakeFiles/game.dir/includes_CXX.rsp
game/CMakeFiles/game.dir/src/GameStateHandler.cpp.obj: C:/CzRProg/Ricsi_programozas/C++/workspace/roguegame/game/src/GameStateHandler.cpp
game/CMakeFiles/game.dir/src/GameStateHandler.cpp.obj: game/CMakeFiles/game.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\CzRProg\Ricsi_programozas\C++\workspace\roguegame\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object game/CMakeFiles/game.dir/src/GameStateHandler.cpp.obj"
	cd /d C:\CzRProg\Ricsi_programozas\C++\workspace\roguegame\build\game && C:\MinGW\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT game/CMakeFiles/game.dir/src/GameStateHandler.cpp.obj -MF CMakeFiles\game.dir\src\GameStateHandler.cpp.obj.d -o CMakeFiles\game.dir\src\GameStateHandler.cpp.obj -c C:\CzRProg\Ricsi_programozas\C++\workspace\roguegame\game\src\GameStateHandler.cpp

game/CMakeFiles/game.dir/src/GameStateHandler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/game.dir/src/GameStateHandler.cpp.i"
	cd /d C:\CzRProg\Ricsi_programozas\C++\workspace\roguegame\build\game && C:\MinGW\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\CzRProg\Ricsi_programozas\C++\workspace\roguegame\game\src\GameStateHandler.cpp > CMakeFiles\game.dir\src\GameStateHandler.cpp.i

game/CMakeFiles/game.dir/src/GameStateHandler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/game.dir/src/GameStateHandler.cpp.s"
	cd /d C:\CzRProg\Ricsi_programozas\C++\workspace\roguegame\build\game && C:\MinGW\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\CzRProg\Ricsi_programozas\C++\workspace\roguegame\game\src\GameStateHandler.cpp -o CMakeFiles\game.dir\src\GameStateHandler.cpp.s

game/CMakeFiles/game.dir/src/main.cpp.obj: game/CMakeFiles/game.dir/flags.make
game/CMakeFiles/game.dir/src/main.cpp.obj: game/CMakeFiles/game.dir/includes_CXX.rsp
game/CMakeFiles/game.dir/src/main.cpp.obj: C:/CzRProg/Ricsi_programozas/C++/workspace/roguegame/game/src/main.cpp
game/CMakeFiles/game.dir/src/main.cpp.obj: game/CMakeFiles/game.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\CzRProg\Ricsi_programozas\C++\workspace\roguegame\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object game/CMakeFiles/game.dir/src/main.cpp.obj"
	cd /d C:\CzRProg\Ricsi_programozas\C++\workspace\roguegame\build\game && C:\MinGW\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT game/CMakeFiles/game.dir/src/main.cpp.obj -MF CMakeFiles\game.dir\src\main.cpp.obj.d -o CMakeFiles\game.dir\src\main.cpp.obj -c C:\CzRProg\Ricsi_programozas\C++\workspace\roguegame\game\src\main.cpp

game/CMakeFiles/game.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/game.dir/src/main.cpp.i"
	cd /d C:\CzRProg\Ricsi_programozas\C++\workspace\roguegame\build\game && C:\MinGW\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\CzRProg\Ricsi_programozas\C++\workspace\roguegame\game\src\main.cpp > CMakeFiles\game.dir\src\main.cpp.i

game/CMakeFiles/game.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/game.dir/src/main.cpp.s"
	cd /d C:\CzRProg\Ricsi_programozas\C++\workspace\roguegame\build\game && C:\MinGW\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\CzRProg\Ricsi_programozas\C++\workspace\roguegame\game\src\main.cpp -o CMakeFiles\game.dir\src\main.cpp.s

# Object files for target game
game_OBJECTS = \
"CMakeFiles/game.dir/src/ASCIIRenderEngine.cpp.obj" \
"CMakeFiles/game.dir/src/GameEngine.cpp.obj" \
"CMakeFiles/game.dir/src/GameStateHandler.cpp.obj" \
"CMakeFiles/game.dir/src/main.cpp.obj"

# External object files for target game
game_EXTERNAL_OBJECTS =

bin/game.exe: game/CMakeFiles/game.dir/src/ASCIIRenderEngine.cpp.obj
bin/game.exe: game/CMakeFiles/game.dir/src/GameEngine.cpp.obj
bin/game.exe: game/CMakeFiles/game.dir/src/GameStateHandler.cpp.obj
bin/game.exe: game/CMakeFiles/game.dir/src/main.cpp.obj
bin/game.exe: game/CMakeFiles/game.dir/build.make
bin/game.exe: game/CMakeFiles/game.dir/linkLibs.rsp
bin/game.exe: game/CMakeFiles/game.dir/objects1.rsp
bin/game.exe: game/CMakeFiles/game.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\CzRProg\Ricsi_programozas\C++\workspace\roguegame\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable ..\bin\game.exe"
	cd /d C:\CzRProg\Ricsi_programozas\C++\workspace\roguegame\build\game && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\game.dir\link.txt --verbose=$(VERBOSE)
	cd /d C:\CzRProg\Ricsi_programozas\C++\workspace\roguegame\build\game && "C:\Program Files\CMake\bin\cmake.exe" -E copy_if_different C:/CzRProg/Ricsi_programozas/C++/workspace/roguegame/libs/windows/pdcurses/pdcurses.dll C:/CzRProg/Ricsi_programozas/C++/workspace/roguegame/build/bin

# Rule to build all files generated by this target.
game/CMakeFiles/game.dir/build: bin/game.exe
.PHONY : game/CMakeFiles/game.dir/build

game/CMakeFiles/game.dir/clean:
	cd /d C:\CzRProg\Ricsi_programozas\C++\workspace\roguegame\build\game && $(CMAKE_COMMAND) -P CMakeFiles\game.dir\cmake_clean.cmake
.PHONY : game/CMakeFiles/game.dir/clean

game/CMakeFiles/game.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\CzRProg\Ricsi_programozas\C++\workspace\roguegame C:\CzRProg\Ricsi_programozas\C++\workspace\roguegame\game C:\CzRProg\Ricsi_programozas\C++\workspace\roguegame\build C:\CzRProg\Ricsi_programozas\C++\workspace\roguegame\build\game C:\CzRProg\Ricsi_programozas\C++\workspace\roguegame\build\game\CMakeFiles\game.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : game/CMakeFiles/game.dir/depend


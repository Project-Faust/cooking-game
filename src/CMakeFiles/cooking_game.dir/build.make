# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/c/Users/pente/Documents/development-projects/cooking-game

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/pente/Documents/development-projects/cooking-game/src

# Include any dependencies generated for this target.
include CMakeFiles/cooking_game.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/cooking_game.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/cooking_game.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cooking_game.dir/flags.make

CMakeFiles/cooking_game.dir/main.cpp.o: CMakeFiles/cooking_game.dir/flags.make
CMakeFiles/cooking_game.dir/main.cpp.o: main.cpp
CMakeFiles/cooking_game.dir/main.cpp.o: CMakeFiles/cooking_game.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/pente/Documents/development-projects/cooking-game/src/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/cooking_game.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/cooking_game.dir/main.cpp.o -MF CMakeFiles/cooking_game.dir/main.cpp.o.d -o CMakeFiles/cooking_game.dir/main.cpp.o -c /mnt/c/Users/pente/Documents/development-projects/cooking-game/src/main.cpp

CMakeFiles/cooking_game.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cooking_game.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/pente/Documents/development-projects/cooking-game/src/main.cpp > CMakeFiles/cooking_game.dir/main.cpp.i

CMakeFiles/cooking_game.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cooking_game.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/pente/Documents/development-projects/cooking-game/src/main.cpp -o CMakeFiles/cooking_game.dir/main.cpp.s

CMakeFiles/cooking_game.dir/Game.cpp.o: CMakeFiles/cooking_game.dir/flags.make
CMakeFiles/cooking_game.dir/Game.cpp.o: Game.cpp
CMakeFiles/cooking_game.dir/Game.cpp.o: CMakeFiles/cooking_game.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/pente/Documents/development-projects/cooking-game/src/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/cooking_game.dir/Game.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/cooking_game.dir/Game.cpp.o -MF CMakeFiles/cooking_game.dir/Game.cpp.o.d -o CMakeFiles/cooking_game.dir/Game.cpp.o -c /mnt/c/Users/pente/Documents/development-projects/cooking-game/src/Game.cpp

CMakeFiles/cooking_game.dir/Game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cooking_game.dir/Game.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/pente/Documents/development-projects/cooking-game/src/Game.cpp > CMakeFiles/cooking_game.dir/Game.cpp.i

CMakeFiles/cooking_game.dir/Game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cooking_game.dir/Game.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/pente/Documents/development-projects/cooking-game/src/Game.cpp -o CMakeFiles/cooking_game.dir/Game.cpp.s

# Object files for target cooking_game
cooking_game_OBJECTS = \
"CMakeFiles/cooking_game.dir/main.cpp.o" \
"CMakeFiles/cooking_game.dir/Game.cpp.o"

# External object files for target cooking_game
cooking_game_EXTERNAL_OBJECTS =

cooking_game: CMakeFiles/cooking_game.dir/main.cpp.o
cooking_game: CMakeFiles/cooking_game.dir/Game.cpp.o
cooking_game: CMakeFiles/cooking_game.dir/build.make
cooking_game: CMakeFiles/cooking_game.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/Users/pente/Documents/development-projects/cooking-game/src/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable cooking_game"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cooking_game.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cooking_game.dir/build: cooking_game
.PHONY : CMakeFiles/cooking_game.dir/build

CMakeFiles/cooking_game.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cooking_game.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cooking_game.dir/clean

CMakeFiles/cooking_game.dir/depend:
	cd /mnt/c/Users/pente/Documents/development-projects/cooking-game/src && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/pente/Documents/development-projects/cooking-game /mnt/c/Users/pente/Documents/development-projects/cooking-game /mnt/c/Users/pente/Documents/development-projects/cooking-game/src /mnt/c/Users/pente/Documents/development-projects/cooking-game/src /mnt/c/Users/pente/Documents/development-projects/cooking-game/src/CMakeFiles/cooking_game.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cooking_game.dir/depend


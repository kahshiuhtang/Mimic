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
CMAKE_SOURCE_DIR = /home/kahshiuh/Desktop/kahshiuh/Mimic/Poker

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kahshiuh/Desktop/kahshiuh/Mimic/Poker/bin

# Include any dependencies generated for this target.
include libs/Poker/CMakeFiles/Poker.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include libs/Poker/CMakeFiles/Poker.dir/compiler_depend.make

# Include the progress variables for this target.
include libs/Poker/CMakeFiles/Poker.dir/progress.make

# Include the compile flags for this target's objects.
include libs/Poker/CMakeFiles/Poker.dir/flags.make

libs/Poker/CMakeFiles/Poker.dir/src/Card.cpp.o: libs/Poker/CMakeFiles/Poker.dir/flags.make
libs/Poker/CMakeFiles/Poker.dir/src/Card.cpp.o: ../libs/Poker/src/Card.cpp
libs/Poker/CMakeFiles/Poker.dir/src/Card.cpp.o: libs/Poker/CMakeFiles/Poker.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kahshiuh/Desktop/kahshiuh/Mimic/Poker/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object libs/Poker/CMakeFiles/Poker.dir/src/Card.cpp.o"
	cd /home/kahshiuh/Desktop/kahshiuh/Mimic/Poker/bin/libs/Poker && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT libs/Poker/CMakeFiles/Poker.dir/src/Card.cpp.o -MF CMakeFiles/Poker.dir/src/Card.cpp.o.d -o CMakeFiles/Poker.dir/src/Card.cpp.o -c /home/kahshiuh/Desktop/kahshiuh/Mimic/Poker/libs/Poker/src/Card.cpp

libs/Poker/CMakeFiles/Poker.dir/src/Card.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Poker.dir/src/Card.cpp.i"
	cd /home/kahshiuh/Desktop/kahshiuh/Mimic/Poker/bin/libs/Poker && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kahshiuh/Desktop/kahshiuh/Mimic/Poker/libs/Poker/src/Card.cpp > CMakeFiles/Poker.dir/src/Card.cpp.i

libs/Poker/CMakeFiles/Poker.dir/src/Card.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Poker.dir/src/Card.cpp.s"
	cd /home/kahshiuh/Desktop/kahshiuh/Mimic/Poker/bin/libs/Poker && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kahshiuh/Desktop/kahshiuh/Mimic/Poker/libs/Poker/src/Card.cpp -o CMakeFiles/Poker.dir/src/Card.cpp.s

libs/Poker/CMakeFiles/Poker.dir/src/Dealer.cpp.o: libs/Poker/CMakeFiles/Poker.dir/flags.make
libs/Poker/CMakeFiles/Poker.dir/src/Dealer.cpp.o: ../libs/Poker/src/Dealer.cpp
libs/Poker/CMakeFiles/Poker.dir/src/Dealer.cpp.o: libs/Poker/CMakeFiles/Poker.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kahshiuh/Desktop/kahshiuh/Mimic/Poker/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object libs/Poker/CMakeFiles/Poker.dir/src/Dealer.cpp.o"
	cd /home/kahshiuh/Desktop/kahshiuh/Mimic/Poker/bin/libs/Poker && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT libs/Poker/CMakeFiles/Poker.dir/src/Dealer.cpp.o -MF CMakeFiles/Poker.dir/src/Dealer.cpp.o.d -o CMakeFiles/Poker.dir/src/Dealer.cpp.o -c /home/kahshiuh/Desktop/kahshiuh/Mimic/Poker/libs/Poker/src/Dealer.cpp

libs/Poker/CMakeFiles/Poker.dir/src/Dealer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Poker.dir/src/Dealer.cpp.i"
	cd /home/kahshiuh/Desktop/kahshiuh/Mimic/Poker/bin/libs/Poker && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kahshiuh/Desktop/kahshiuh/Mimic/Poker/libs/Poker/src/Dealer.cpp > CMakeFiles/Poker.dir/src/Dealer.cpp.i

libs/Poker/CMakeFiles/Poker.dir/src/Dealer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Poker.dir/src/Dealer.cpp.s"
	cd /home/kahshiuh/Desktop/kahshiuh/Mimic/Poker/bin/libs/Poker && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kahshiuh/Desktop/kahshiuh/Mimic/Poker/libs/Poker/src/Dealer.cpp -o CMakeFiles/Poker.dir/src/Dealer.cpp.s

libs/Poker/CMakeFiles/Poker.dir/src/Deck.cpp.o: libs/Poker/CMakeFiles/Poker.dir/flags.make
libs/Poker/CMakeFiles/Poker.dir/src/Deck.cpp.o: ../libs/Poker/src/Deck.cpp
libs/Poker/CMakeFiles/Poker.dir/src/Deck.cpp.o: libs/Poker/CMakeFiles/Poker.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kahshiuh/Desktop/kahshiuh/Mimic/Poker/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object libs/Poker/CMakeFiles/Poker.dir/src/Deck.cpp.o"
	cd /home/kahshiuh/Desktop/kahshiuh/Mimic/Poker/bin/libs/Poker && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT libs/Poker/CMakeFiles/Poker.dir/src/Deck.cpp.o -MF CMakeFiles/Poker.dir/src/Deck.cpp.o.d -o CMakeFiles/Poker.dir/src/Deck.cpp.o -c /home/kahshiuh/Desktop/kahshiuh/Mimic/Poker/libs/Poker/src/Deck.cpp

libs/Poker/CMakeFiles/Poker.dir/src/Deck.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Poker.dir/src/Deck.cpp.i"
	cd /home/kahshiuh/Desktop/kahshiuh/Mimic/Poker/bin/libs/Poker && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kahshiuh/Desktop/kahshiuh/Mimic/Poker/libs/Poker/src/Deck.cpp > CMakeFiles/Poker.dir/src/Deck.cpp.i

libs/Poker/CMakeFiles/Poker.dir/src/Deck.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Poker.dir/src/Deck.cpp.s"
	cd /home/kahshiuh/Desktop/kahshiuh/Mimic/Poker/bin/libs/Poker && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kahshiuh/Desktop/kahshiuh/Mimic/Poker/libs/Poker/src/Deck.cpp -o CMakeFiles/Poker.dir/src/Deck.cpp.s

libs/Poker/CMakeFiles/Poker.dir/src/Game.cpp.o: libs/Poker/CMakeFiles/Poker.dir/flags.make
libs/Poker/CMakeFiles/Poker.dir/src/Game.cpp.o: ../libs/Poker/src/Game.cpp
libs/Poker/CMakeFiles/Poker.dir/src/Game.cpp.o: libs/Poker/CMakeFiles/Poker.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kahshiuh/Desktop/kahshiuh/Mimic/Poker/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object libs/Poker/CMakeFiles/Poker.dir/src/Game.cpp.o"
	cd /home/kahshiuh/Desktop/kahshiuh/Mimic/Poker/bin/libs/Poker && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT libs/Poker/CMakeFiles/Poker.dir/src/Game.cpp.o -MF CMakeFiles/Poker.dir/src/Game.cpp.o.d -o CMakeFiles/Poker.dir/src/Game.cpp.o -c /home/kahshiuh/Desktop/kahshiuh/Mimic/Poker/libs/Poker/src/Game.cpp

libs/Poker/CMakeFiles/Poker.dir/src/Game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Poker.dir/src/Game.cpp.i"
	cd /home/kahshiuh/Desktop/kahshiuh/Mimic/Poker/bin/libs/Poker && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kahshiuh/Desktop/kahshiuh/Mimic/Poker/libs/Poker/src/Game.cpp > CMakeFiles/Poker.dir/src/Game.cpp.i

libs/Poker/CMakeFiles/Poker.dir/src/Game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Poker.dir/src/Game.cpp.s"
	cd /home/kahshiuh/Desktop/kahshiuh/Mimic/Poker/bin/libs/Poker && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kahshiuh/Desktop/kahshiuh/Mimic/Poker/libs/Poker/src/Game.cpp -o CMakeFiles/Poker.dir/src/Game.cpp.s

libs/Poker/CMakeFiles/Poker.dir/src/Player.cpp.o: libs/Poker/CMakeFiles/Poker.dir/flags.make
libs/Poker/CMakeFiles/Poker.dir/src/Player.cpp.o: ../libs/Poker/src/Player.cpp
libs/Poker/CMakeFiles/Poker.dir/src/Player.cpp.o: libs/Poker/CMakeFiles/Poker.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kahshiuh/Desktop/kahshiuh/Mimic/Poker/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object libs/Poker/CMakeFiles/Poker.dir/src/Player.cpp.o"
	cd /home/kahshiuh/Desktop/kahshiuh/Mimic/Poker/bin/libs/Poker && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT libs/Poker/CMakeFiles/Poker.dir/src/Player.cpp.o -MF CMakeFiles/Poker.dir/src/Player.cpp.o.d -o CMakeFiles/Poker.dir/src/Player.cpp.o -c /home/kahshiuh/Desktop/kahshiuh/Mimic/Poker/libs/Poker/src/Player.cpp

libs/Poker/CMakeFiles/Poker.dir/src/Player.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Poker.dir/src/Player.cpp.i"
	cd /home/kahshiuh/Desktop/kahshiuh/Mimic/Poker/bin/libs/Poker && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kahshiuh/Desktop/kahshiuh/Mimic/Poker/libs/Poker/src/Player.cpp > CMakeFiles/Poker.dir/src/Player.cpp.i

libs/Poker/CMakeFiles/Poker.dir/src/Player.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Poker.dir/src/Player.cpp.s"
	cd /home/kahshiuh/Desktop/kahshiuh/Mimic/Poker/bin/libs/Poker && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kahshiuh/Desktop/kahshiuh/Mimic/Poker/libs/Poker/src/Player.cpp -o CMakeFiles/Poker.dir/src/Player.cpp.s

# Object files for target Poker
Poker_OBJECTS = \
"CMakeFiles/Poker.dir/src/Card.cpp.o" \
"CMakeFiles/Poker.dir/src/Dealer.cpp.o" \
"CMakeFiles/Poker.dir/src/Deck.cpp.o" \
"CMakeFiles/Poker.dir/src/Game.cpp.o" \
"CMakeFiles/Poker.dir/src/Player.cpp.o"

# External object files for target Poker
Poker_EXTERNAL_OBJECTS =

libs/Poker/libPoker.a: libs/Poker/CMakeFiles/Poker.dir/src/Card.cpp.o
libs/Poker/libPoker.a: libs/Poker/CMakeFiles/Poker.dir/src/Dealer.cpp.o
libs/Poker/libPoker.a: libs/Poker/CMakeFiles/Poker.dir/src/Deck.cpp.o
libs/Poker/libPoker.a: libs/Poker/CMakeFiles/Poker.dir/src/Game.cpp.o
libs/Poker/libPoker.a: libs/Poker/CMakeFiles/Poker.dir/src/Player.cpp.o
libs/Poker/libPoker.a: libs/Poker/CMakeFiles/Poker.dir/build.make
libs/Poker/libPoker.a: libs/Poker/CMakeFiles/Poker.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kahshiuh/Desktop/kahshiuh/Mimic/Poker/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX static library libPoker.a"
	cd /home/kahshiuh/Desktop/kahshiuh/Mimic/Poker/bin/libs/Poker && $(CMAKE_COMMAND) -P CMakeFiles/Poker.dir/cmake_clean_target.cmake
	cd /home/kahshiuh/Desktop/kahshiuh/Mimic/Poker/bin/libs/Poker && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Poker.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
libs/Poker/CMakeFiles/Poker.dir/build: libs/Poker/libPoker.a
.PHONY : libs/Poker/CMakeFiles/Poker.dir/build

libs/Poker/CMakeFiles/Poker.dir/clean:
	cd /home/kahshiuh/Desktop/kahshiuh/Mimic/Poker/bin/libs/Poker && $(CMAKE_COMMAND) -P CMakeFiles/Poker.dir/cmake_clean.cmake
.PHONY : libs/Poker/CMakeFiles/Poker.dir/clean

libs/Poker/CMakeFiles/Poker.dir/depend:
	cd /home/kahshiuh/Desktop/kahshiuh/Mimic/Poker/bin && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kahshiuh/Desktop/kahshiuh/Mimic/Poker /home/kahshiuh/Desktop/kahshiuh/Mimic/Poker/libs/Poker /home/kahshiuh/Desktop/kahshiuh/Mimic/Poker/bin /home/kahshiuh/Desktop/kahshiuh/Mimic/Poker/bin/libs/Poker /home/kahshiuh/Desktop/kahshiuh/Mimic/Poker/bin/libs/Poker/CMakeFiles/Poker.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : libs/Poker/CMakeFiles/Poker.dir/depend


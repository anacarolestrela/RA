# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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
CMAKE_SOURCE_DIR = /home/marco/NetBeansProjects/bahiart2023

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/marco/NetBeansProjects/bahiart2023

# Include any dependencies generated for this target.
include src/network/CMakeFiles/sockets.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/network/CMakeFiles/sockets.dir/compiler_depend.make

# Include the progress variables for this target.
include src/network/CMakeFiles/sockets.dir/progress.make

# Include the compile flags for this target's objects.
include src/network/CMakeFiles/sockets.dir/flags.make

src/network/CMakeFiles/sockets.dir/socket.cpp.o: src/network/CMakeFiles/sockets.dir/flags.make
src/network/CMakeFiles/sockets.dir/socket.cpp.o: src/network/socket.cpp
src/network/CMakeFiles/sockets.dir/socket.cpp.o: src/network/CMakeFiles/sockets.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marco/NetBeansProjects/bahiart2023/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/network/CMakeFiles/sockets.dir/socket.cpp.o"
	cd /home/marco/NetBeansProjects/bahiart2023/src/network && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/network/CMakeFiles/sockets.dir/socket.cpp.o -MF CMakeFiles/sockets.dir/socket.cpp.o.d -o CMakeFiles/sockets.dir/socket.cpp.o -c /home/marco/NetBeansProjects/bahiart2023/src/network/socket.cpp

src/network/CMakeFiles/sockets.dir/socket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sockets.dir/socket.cpp.i"
	cd /home/marco/NetBeansProjects/bahiart2023/src/network && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marco/NetBeansProjects/bahiart2023/src/network/socket.cpp > CMakeFiles/sockets.dir/socket.cpp.i

src/network/CMakeFiles/sockets.dir/socket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sockets.dir/socket.cpp.s"
	cd /home/marco/NetBeansProjects/bahiart2023/src/network && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marco/NetBeansProjects/bahiart2023/src/network/socket.cpp -o CMakeFiles/sockets.dir/socket.cpp.s

# Object files for target sockets
sockets_OBJECTS = \
"CMakeFiles/sockets.dir/socket.cpp.o"

# External object files for target sockets
sockets_EXTERNAL_OBJECTS =

src/network/libsockets.a: src/network/CMakeFiles/sockets.dir/socket.cpp.o
src/network/libsockets.a: src/network/CMakeFiles/sockets.dir/build.make
src/network/libsockets.a: src/network/CMakeFiles/sockets.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/marco/NetBeansProjects/bahiart2023/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libsockets.a"
	cd /home/marco/NetBeansProjects/bahiart2023/src/network && $(CMAKE_COMMAND) -P CMakeFiles/sockets.dir/cmake_clean_target.cmake
	cd /home/marco/NetBeansProjects/bahiart2023/src/network && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sockets.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/network/CMakeFiles/sockets.dir/build: src/network/libsockets.a
.PHONY : src/network/CMakeFiles/sockets.dir/build

src/network/CMakeFiles/sockets.dir/clean:
	cd /home/marco/NetBeansProjects/bahiart2023/src/network && $(CMAKE_COMMAND) -P CMakeFiles/sockets.dir/cmake_clean.cmake
.PHONY : src/network/CMakeFiles/sockets.dir/clean

src/network/CMakeFiles/sockets.dir/depend:
	cd /home/marco/NetBeansProjects/bahiart2023 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/marco/NetBeansProjects/bahiart2023 /home/marco/NetBeansProjects/bahiart2023/src/network /home/marco/NetBeansProjects/bahiart2023 /home/marco/NetBeansProjects/bahiart2023/src/network /home/marco/NetBeansProjects/bahiart2023/src/network/CMakeFiles/sockets.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/network/CMakeFiles/sockets.dir/depend


# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
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
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/anacarol/bahiart2023

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/anacarol/bahiart2023/build

# Include any dependencies generated for this target.
include src/network/CMakeFiles/udpsocket.dir/depend.make

# Include the progress variables for this target.
include src/network/CMakeFiles/udpsocket.dir/progress.make

# Include the compile flags for this target's objects.
include src/network/CMakeFiles/udpsocket.dir/flags.make

src/network/CMakeFiles/udpsocket.dir/udpsocket.cpp.o: src/network/CMakeFiles/udpsocket.dir/flags.make
src/network/CMakeFiles/udpsocket.dir/udpsocket.cpp.o: ../src/network/udpsocket.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/anacarol/bahiart2023/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/network/CMakeFiles/udpsocket.dir/udpsocket.cpp.o"
	cd /home/anacarol/bahiart2023/build/src/network && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/udpsocket.dir/udpsocket.cpp.o -c /home/anacarol/bahiart2023/src/network/udpsocket.cpp

src/network/CMakeFiles/udpsocket.dir/udpsocket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/udpsocket.dir/udpsocket.cpp.i"
	cd /home/anacarol/bahiart2023/build/src/network && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/anacarol/bahiart2023/src/network/udpsocket.cpp > CMakeFiles/udpsocket.dir/udpsocket.cpp.i

src/network/CMakeFiles/udpsocket.dir/udpsocket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/udpsocket.dir/udpsocket.cpp.s"
	cd /home/anacarol/bahiart2023/build/src/network && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/anacarol/bahiart2023/src/network/udpsocket.cpp -o CMakeFiles/udpsocket.dir/udpsocket.cpp.s

# Object files for target udpsocket
udpsocket_OBJECTS = \
"CMakeFiles/udpsocket.dir/udpsocket.cpp.o"

# External object files for target udpsocket
udpsocket_EXTERNAL_OBJECTS =

src/network/libudpsocket.a: src/network/CMakeFiles/udpsocket.dir/udpsocket.cpp.o
src/network/libudpsocket.a: src/network/CMakeFiles/udpsocket.dir/build.make
src/network/libudpsocket.a: src/network/CMakeFiles/udpsocket.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/anacarol/bahiart2023/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libudpsocket.a"
	cd /home/anacarol/bahiart2023/build/src/network && $(CMAKE_COMMAND) -P CMakeFiles/udpsocket.dir/cmake_clean_target.cmake
	cd /home/anacarol/bahiart2023/build/src/network && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/udpsocket.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/network/CMakeFiles/udpsocket.dir/build: src/network/libudpsocket.a

.PHONY : src/network/CMakeFiles/udpsocket.dir/build

src/network/CMakeFiles/udpsocket.dir/clean:
	cd /home/anacarol/bahiart2023/build/src/network && $(CMAKE_COMMAND) -P CMakeFiles/udpsocket.dir/cmake_clean.cmake
.PHONY : src/network/CMakeFiles/udpsocket.dir/clean

src/network/CMakeFiles/udpsocket.dir/depend:
	cd /home/anacarol/bahiart2023/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/anacarol/bahiart2023 /home/anacarol/bahiart2023/src/network /home/anacarol/bahiart2023/build /home/anacarol/bahiart2023/build/src/network /home/anacarol/bahiart2023/build/src/network/CMakeFiles/udpsocket.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/network/CMakeFiles/udpsocket.dir/depend


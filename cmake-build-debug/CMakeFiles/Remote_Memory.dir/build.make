# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = /home/luis/Documents/CLion/clion-2017.2/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/luis/Documents/CLion/clion-2017.2/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/luis/CLionProjects/Remote_Memory

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/luis/CLionProjects/Remote_Memory/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Remote_Memory.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Remote_Memory.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Remote_Memory.dir/flags.make

CMakeFiles/Remote_Memory.dir/main.cpp.o: CMakeFiles/Remote_Memory.dir/flags.make
CMakeFiles/Remote_Memory.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/luis/CLionProjects/Remote_Memory/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Remote_Memory.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Remote_Memory.dir/main.cpp.o -c /home/luis/CLionProjects/Remote_Memory/main.cpp

CMakeFiles/Remote_Memory.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Remote_Memory.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/luis/CLionProjects/Remote_Memory/main.cpp > CMakeFiles/Remote_Memory.dir/main.cpp.i

CMakeFiles/Remote_Memory.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Remote_Memory.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/luis/CLionProjects/Remote_Memory/main.cpp -o CMakeFiles/Remote_Memory.dir/main.cpp.s

CMakeFiles/Remote_Memory.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/Remote_Memory.dir/main.cpp.o.requires

CMakeFiles/Remote_Memory.dir/main.cpp.o.provides: CMakeFiles/Remote_Memory.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/Remote_Memory.dir/build.make CMakeFiles/Remote_Memory.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/Remote_Memory.dir/main.cpp.o.provides

CMakeFiles/Remote_Memory.dir/main.cpp.o.provides.build: CMakeFiles/Remote_Memory.dir/main.cpp.o


# Object files for target Remote_Memory
Remote_Memory_OBJECTS = \
"CMakeFiles/Remote_Memory.dir/main.cpp.o"

# External object files for target Remote_Memory
Remote_Memory_EXTERNAL_OBJECTS =

Remote_Memory: CMakeFiles/Remote_Memory.dir/main.cpp.o
Remote_Memory: CMakeFiles/Remote_Memory.dir/build.make
Remote_Memory: CMakeFiles/Remote_Memory.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/luis/CLionProjects/Remote_Memory/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Remote_Memory"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Remote_Memory.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Remote_Memory.dir/build: Remote_Memory

.PHONY : CMakeFiles/Remote_Memory.dir/build

CMakeFiles/Remote_Memory.dir/requires: CMakeFiles/Remote_Memory.dir/main.cpp.o.requires

.PHONY : CMakeFiles/Remote_Memory.dir/requires

CMakeFiles/Remote_Memory.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Remote_Memory.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Remote_Memory.dir/clean

CMakeFiles/Remote_Memory.dir/depend:
	cd /home/luis/CLionProjects/Remote_Memory/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/luis/CLionProjects/Remote_Memory /home/luis/CLionProjects/Remote_Memory /home/luis/CLionProjects/Remote_Memory/cmake-build-debug /home/luis/CLionProjects/Remote_Memory/cmake-build-debug /home/luis/CLionProjects/Remote_Memory/cmake-build-debug/CMakeFiles/Remote_Memory.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Remote_Memory.dir/depend


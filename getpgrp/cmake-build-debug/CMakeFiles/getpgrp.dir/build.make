# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /home/cai/Desktop/clion-2021.2/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/cai/Desktop/clion-2021.2/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/cai/Desktop/Program/getpgrp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/cai/Desktop/Program/getpgrp/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/getpgrp.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/getpgrp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/getpgrp.dir/flags.make

CMakeFiles/getpgrp.dir/main.c.o: CMakeFiles/getpgrp.dir/flags.make
CMakeFiles/getpgrp.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cai/Desktop/Program/getpgrp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/getpgrp.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/getpgrp.dir/main.c.o -c /home/cai/Desktop/Program/getpgrp/main.c

CMakeFiles/getpgrp.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/getpgrp.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/cai/Desktop/Program/getpgrp/main.c > CMakeFiles/getpgrp.dir/main.c.i

CMakeFiles/getpgrp.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/getpgrp.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/cai/Desktop/Program/getpgrp/main.c -o CMakeFiles/getpgrp.dir/main.c.s

# Object files for target getpgrp
getpgrp_OBJECTS = \
"CMakeFiles/getpgrp.dir/main.c.o"

# External object files for target getpgrp
getpgrp_EXTERNAL_OBJECTS =

getpgrp: CMakeFiles/getpgrp.dir/main.c.o
getpgrp: CMakeFiles/getpgrp.dir/build.make
getpgrp: CMakeFiles/getpgrp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/cai/Desktop/Program/getpgrp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable getpgrp"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/getpgrp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/getpgrp.dir/build: getpgrp
.PHONY : CMakeFiles/getpgrp.dir/build

CMakeFiles/getpgrp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/getpgrp.dir/cmake_clean.cmake
.PHONY : CMakeFiles/getpgrp.dir/clean

CMakeFiles/getpgrp.dir/depend:
	cd /home/cai/Desktop/Program/getpgrp/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/cai/Desktop/Program/getpgrp /home/cai/Desktop/Program/getpgrp /home/cai/Desktop/Program/getpgrp/cmake-build-debug /home/cai/Desktop/Program/getpgrp/cmake-build-debug /home/cai/Desktop/Program/getpgrp/cmake-build-debug/CMakeFiles/getpgrp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/getpgrp.dir/depend


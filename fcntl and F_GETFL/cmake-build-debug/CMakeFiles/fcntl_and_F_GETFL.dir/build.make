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
CMAKE_COMMAND = /home/cai/sdb1/clion-2021.2/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/cai/sdb1/clion-2021.2/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/cai/sdb1/new/fcntl and F_GETFL"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/cai/sdb1/new/fcntl and F_GETFL/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/fcntl_and_F_GETFL.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/fcntl_and_F_GETFL.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/fcntl_and_F_GETFL.dir/flags.make

CMakeFiles/fcntl_and_F_GETFL.dir/main.c.o: CMakeFiles/fcntl_and_F_GETFL.dir/flags.make
CMakeFiles/fcntl_and_F_GETFL.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/cai/sdb1/new/fcntl and F_GETFL/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/fcntl_and_F_GETFL.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/fcntl_and_F_GETFL.dir/main.c.o -c "/home/cai/sdb1/new/fcntl and F_GETFL/main.c"

CMakeFiles/fcntl_and_F_GETFL.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/fcntl_and_F_GETFL.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/cai/sdb1/new/fcntl and F_GETFL/main.c" > CMakeFiles/fcntl_and_F_GETFL.dir/main.c.i

CMakeFiles/fcntl_and_F_GETFL.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/fcntl_and_F_GETFL.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/cai/sdb1/new/fcntl and F_GETFL/main.c" -o CMakeFiles/fcntl_and_F_GETFL.dir/main.c.s

# Object files for target fcntl_and_F_GETFL
fcntl_and_F_GETFL_OBJECTS = \
"CMakeFiles/fcntl_and_F_GETFL.dir/main.c.o"

# External object files for target fcntl_and_F_GETFL
fcntl_and_F_GETFL_EXTERNAL_OBJECTS =

fcntl_and_F_GETFL: CMakeFiles/fcntl_and_F_GETFL.dir/main.c.o
fcntl_and_F_GETFL: CMakeFiles/fcntl_and_F_GETFL.dir/build.make
fcntl_and_F_GETFL: CMakeFiles/fcntl_and_F_GETFL.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/cai/sdb1/new/fcntl and F_GETFL/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable fcntl_and_F_GETFL"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/fcntl_and_F_GETFL.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/fcntl_and_F_GETFL.dir/build: fcntl_and_F_GETFL
.PHONY : CMakeFiles/fcntl_and_F_GETFL.dir/build

CMakeFiles/fcntl_and_F_GETFL.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/fcntl_and_F_GETFL.dir/cmake_clean.cmake
.PHONY : CMakeFiles/fcntl_and_F_GETFL.dir/clean

CMakeFiles/fcntl_and_F_GETFL.dir/depend:
	cd "/home/cai/sdb1/new/fcntl and F_GETFL/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/cai/sdb1/new/fcntl and F_GETFL" "/home/cai/sdb1/new/fcntl and F_GETFL" "/home/cai/sdb1/new/fcntl and F_GETFL/cmake-build-debug" "/home/cai/sdb1/new/fcntl and F_GETFL/cmake-build-debug" "/home/cai/sdb1/new/fcntl and F_GETFL/cmake-build-debug/CMakeFiles/fcntl_and_F_GETFL.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/fcntl_and_F_GETFL.dir/depend


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
CMAKE_SOURCE_DIR = "/home/cai/sdb1/new/rio_readlineb and rio_writen"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/cai/sdb1/new/rio_readlineb and rio_writen/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/rio_readlineb_and_rio_writen.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/rio_readlineb_and_rio_writen.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/rio_readlineb_and_rio_writen.dir/flags.make

CMakeFiles/rio_readlineb_and_rio_writen.dir/main.c.o: CMakeFiles/rio_readlineb_and_rio_writen.dir/flags.make
CMakeFiles/rio_readlineb_and_rio_writen.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/cai/sdb1/new/rio_readlineb and rio_writen/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/rio_readlineb_and_rio_writen.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/rio_readlineb_and_rio_writen.dir/main.c.o -c "/home/cai/sdb1/new/rio_readlineb and rio_writen/main.c"

CMakeFiles/rio_readlineb_and_rio_writen.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/rio_readlineb_and_rio_writen.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/cai/sdb1/new/rio_readlineb and rio_writen/main.c" > CMakeFiles/rio_readlineb_and_rio_writen.dir/main.c.i

CMakeFiles/rio_readlineb_and_rio_writen.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/rio_readlineb_and_rio_writen.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/cai/sdb1/new/rio_readlineb and rio_writen/main.c" -o CMakeFiles/rio_readlineb_and_rio_writen.dir/main.c.s

# Object files for target rio_readlineb_and_rio_writen
rio_readlineb_and_rio_writen_OBJECTS = \
"CMakeFiles/rio_readlineb_and_rio_writen.dir/main.c.o"

# External object files for target rio_readlineb_and_rio_writen
rio_readlineb_and_rio_writen_EXTERNAL_OBJECTS =

rio_readlineb_and_rio_writen: CMakeFiles/rio_readlineb_and_rio_writen.dir/main.c.o
rio_readlineb_and_rio_writen: CMakeFiles/rio_readlineb_and_rio_writen.dir/build.make
rio_readlineb_and_rio_writen: CMakeFiles/rio_readlineb_and_rio_writen.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/cai/sdb1/new/rio_readlineb and rio_writen/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable rio_readlineb_and_rio_writen"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/rio_readlineb_and_rio_writen.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/rio_readlineb_and_rio_writen.dir/build: rio_readlineb_and_rio_writen
.PHONY : CMakeFiles/rio_readlineb_and_rio_writen.dir/build

CMakeFiles/rio_readlineb_and_rio_writen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/rio_readlineb_and_rio_writen.dir/cmake_clean.cmake
.PHONY : CMakeFiles/rio_readlineb_and_rio_writen.dir/clean

CMakeFiles/rio_readlineb_and_rio_writen.dir/depend:
	cd "/home/cai/sdb1/new/rio_readlineb and rio_writen/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/cai/sdb1/new/rio_readlineb and rio_writen" "/home/cai/sdb1/new/rio_readlineb and rio_writen" "/home/cai/sdb1/new/rio_readlineb and rio_writen/cmake-build-debug" "/home/cai/sdb1/new/rio_readlineb and rio_writen/cmake-build-debug" "/home/cai/sdb1/new/rio_readlineb and rio_writen/cmake-build-debug/CMakeFiles/rio_readlineb_and_rio_writen.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/rio_readlineb_and_rio_writen.dir/depend


# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = "D:\CLion 2021.1.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\CLion 2021.1.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "E:\programe\GitHub project warehouse manager\C-skill\fork"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "E:\programe\GitHub project warehouse manager\C-skill\fork\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/fork.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/fork.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/fork.dir/flags.make

CMakeFiles/fork.dir/main.c.obj: CMakeFiles/fork.dir/flags.make
CMakeFiles/fork.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="E:\programe\GitHub project warehouse manager\C-skill\fork\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/fork.dir/main.c.obj"
	D:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\fork.dir\main.c.obj -c "E:\programe\GitHub project warehouse manager\C-skill\fork\main.c"

CMakeFiles/fork.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/fork.dir/main.c.i"
	D:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "E:\programe\GitHub project warehouse manager\C-skill\fork\main.c" > CMakeFiles\fork.dir\main.c.i

CMakeFiles/fork.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/fork.dir/main.c.s"
	D:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "E:\programe\GitHub project warehouse manager\C-skill\fork\main.c" -o CMakeFiles\fork.dir\main.c.s

# Object files for target fork
fork_OBJECTS = \
"CMakeFiles/fork.dir/main.c.obj"

# External object files for target fork
fork_EXTERNAL_OBJECTS =

fork.exe: CMakeFiles/fork.dir/main.c.obj
fork.exe: CMakeFiles/fork.dir/build.make
fork.exe: CMakeFiles/fork.dir/linklibs.rsp
fork.exe: CMakeFiles/fork.dir/objects1.rsp
fork.exe: CMakeFiles/fork.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="E:\programe\GitHub project warehouse manager\C-skill\fork\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable fork.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\fork.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/fork.dir/build: fork.exe

.PHONY : CMakeFiles/fork.dir/build

CMakeFiles/fork.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\fork.dir\cmake_clean.cmake
.PHONY : CMakeFiles/fork.dir/clean

CMakeFiles/fork.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "E:\programe\GitHub project warehouse manager\C-skill\fork" "E:\programe\GitHub project warehouse manager\C-skill\fork" "E:\programe\GitHub project warehouse manager\C-skill\fork\cmake-build-debug" "E:\programe\GitHub project warehouse manager\C-skill\fork\cmake-build-debug" "E:\programe\GitHub project warehouse manager\C-skill\fork\cmake-build-debug\CMakeFiles\fork.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/fork.dir/depend


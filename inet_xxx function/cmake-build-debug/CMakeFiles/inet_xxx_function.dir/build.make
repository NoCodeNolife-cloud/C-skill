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
CMAKE_COMMAND = /home/jax/taskfiles/software/clion-2021.2.2/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/jax/taskfiles/software/clion-2021.2.2/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/jax/taskfiles/program/inet_xxx function"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/jax/taskfiles/program/inet_xxx function/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/inet_xxx_function.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/inet_xxx_function.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/inet_xxx_function.dir/flags.make

CMakeFiles/inet_xxx_function.dir/main.cpp.o: CMakeFiles/inet_xxx_function.dir/flags.make
CMakeFiles/inet_xxx_function.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/jax/taskfiles/program/inet_xxx function/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/inet_xxx_function.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/inet_xxx_function.dir/main.cpp.o -c "/home/jax/taskfiles/program/inet_xxx function/main.cpp"

CMakeFiles/inet_xxx_function.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/inet_xxx_function.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/jax/taskfiles/program/inet_xxx function/main.cpp" > CMakeFiles/inet_xxx_function.dir/main.cpp.i

CMakeFiles/inet_xxx_function.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/inet_xxx_function.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/jax/taskfiles/program/inet_xxx function/main.cpp" -o CMakeFiles/inet_xxx_function.dir/main.cpp.s

# Object files for target inet_xxx_function
inet_xxx_function_OBJECTS = \
"CMakeFiles/inet_xxx_function.dir/main.cpp.o"

# External object files for target inet_xxx_function
inet_xxx_function_EXTERNAL_OBJECTS =

inet_xxx_function: CMakeFiles/inet_xxx_function.dir/main.cpp.o
inet_xxx_function: CMakeFiles/inet_xxx_function.dir/build.make
inet_xxx_function: CMakeFiles/inet_xxx_function.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/jax/taskfiles/program/inet_xxx function/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable inet_xxx_function"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/inet_xxx_function.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/inet_xxx_function.dir/build: inet_xxx_function
.PHONY : CMakeFiles/inet_xxx_function.dir/build

CMakeFiles/inet_xxx_function.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/inet_xxx_function.dir/cmake_clean.cmake
.PHONY : CMakeFiles/inet_xxx_function.dir/clean

CMakeFiles/inet_xxx_function.dir/depend:
	cd "/home/jax/taskfiles/program/inet_xxx function/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/jax/taskfiles/program/inet_xxx function" "/home/jax/taskfiles/program/inet_xxx function" "/home/jax/taskfiles/program/inet_xxx function/cmake-build-debug" "/home/jax/taskfiles/program/inet_xxx function/cmake-build-debug" "/home/jax/taskfiles/program/inet_xxx function/cmake-build-debug/CMakeFiles/inet_xxx_function.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/inet_xxx_function.dir/depend

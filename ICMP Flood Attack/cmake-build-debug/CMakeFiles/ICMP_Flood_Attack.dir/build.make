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
CMAKE_SOURCE_DIR = "/home/jax/taskfiles/new program/ICMP Flood Attack"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/jax/taskfiles/new program/ICMP Flood Attack/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/ICMP_Flood_Attack.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/ICMP_Flood_Attack.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ICMP_Flood_Attack.dir/flags.make

CMakeFiles/ICMP_Flood_Attack.dir/main.cpp.o: CMakeFiles/ICMP_Flood_Attack.dir/flags.make
CMakeFiles/ICMP_Flood_Attack.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/jax/taskfiles/new program/ICMP Flood Attack/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ICMP_Flood_Attack.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ICMP_Flood_Attack.dir/main.cpp.o -c "/home/jax/taskfiles/new program/ICMP Flood Attack/main.cpp"

CMakeFiles/ICMP_Flood_Attack.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ICMP_Flood_Attack.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/jax/taskfiles/new program/ICMP Flood Attack/main.cpp" > CMakeFiles/ICMP_Flood_Attack.dir/main.cpp.i

CMakeFiles/ICMP_Flood_Attack.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ICMP_Flood_Attack.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/jax/taskfiles/new program/ICMP Flood Attack/main.cpp" -o CMakeFiles/ICMP_Flood_Attack.dir/main.cpp.s

# Object files for target ICMP_Flood_Attack
ICMP_Flood_Attack_OBJECTS = \
"CMakeFiles/ICMP_Flood_Attack.dir/main.cpp.o"

# External object files for target ICMP_Flood_Attack
ICMP_Flood_Attack_EXTERNAL_OBJECTS =

ICMP_Flood_Attack: CMakeFiles/ICMP_Flood_Attack.dir/main.cpp.o
ICMP_Flood_Attack: CMakeFiles/ICMP_Flood_Attack.dir/build.make
ICMP_Flood_Attack: CMakeFiles/ICMP_Flood_Attack.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/jax/taskfiles/new program/ICMP Flood Attack/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ICMP_Flood_Attack"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ICMP_Flood_Attack.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ICMP_Flood_Attack.dir/build: ICMP_Flood_Attack
.PHONY : CMakeFiles/ICMP_Flood_Attack.dir/build

CMakeFiles/ICMP_Flood_Attack.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ICMP_Flood_Attack.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ICMP_Flood_Attack.dir/clean

CMakeFiles/ICMP_Flood_Attack.dir/depend:
	cd "/home/jax/taskfiles/new program/ICMP Flood Attack/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/jax/taskfiles/new program/ICMP Flood Attack" "/home/jax/taskfiles/new program/ICMP Flood Attack" "/home/jax/taskfiles/new program/ICMP Flood Attack/cmake-build-debug" "/home/jax/taskfiles/new program/ICMP Flood Attack/cmake-build-debug" "/home/jax/taskfiles/new program/ICMP Flood Attack/cmake-build-debug/CMakeFiles/ICMP_Flood_Attack.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/ICMP_Flood_Attack.dir/depend


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
CMAKE_SOURCE_DIR = "/home/jax/taskfiles/program/Byte order detection"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/jax/taskfiles/program/Byte order detection/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Byte_order_detection.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/Byte_order_detection.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Byte_order_detection.dir/flags.make

CMakeFiles/Byte_order_detection.dir/main.cpp.o: CMakeFiles/Byte_order_detection.dir/flags.make
CMakeFiles/Byte_order_detection.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/jax/taskfiles/program/Byte order detection/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Byte_order_detection.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Byte_order_detection.dir/main.cpp.o -c "/home/jax/taskfiles/program/Byte order detection/main.cpp"

CMakeFiles/Byte_order_detection.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Byte_order_detection.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/jax/taskfiles/program/Byte order detection/main.cpp" > CMakeFiles/Byte_order_detection.dir/main.cpp.i

CMakeFiles/Byte_order_detection.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Byte_order_detection.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/jax/taskfiles/program/Byte order detection/main.cpp" -o CMakeFiles/Byte_order_detection.dir/main.cpp.s

# Object files for target Byte_order_detection
Byte_order_detection_OBJECTS = \
"CMakeFiles/Byte_order_detection.dir/main.cpp.o"

# External object files for target Byte_order_detection
Byte_order_detection_EXTERNAL_OBJECTS =

Byte_order_detection: CMakeFiles/Byte_order_detection.dir/main.cpp.o
Byte_order_detection: CMakeFiles/Byte_order_detection.dir/build.make
Byte_order_detection: CMakeFiles/Byte_order_detection.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/jax/taskfiles/program/Byte order detection/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Byte_order_detection"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Byte_order_detection.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Byte_order_detection.dir/build: Byte_order_detection
.PHONY : CMakeFiles/Byte_order_detection.dir/build

CMakeFiles/Byte_order_detection.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Byte_order_detection.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Byte_order_detection.dir/clean

CMakeFiles/Byte_order_detection.dir/depend:
	cd "/home/jax/taskfiles/program/Byte order detection/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/jax/taskfiles/program/Byte order detection" "/home/jax/taskfiles/program/Byte order detection" "/home/jax/taskfiles/program/Byte order detection/cmake-build-debug" "/home/jax/taskfiles/program/Byte order detection/cmake-build-debug" "/home/jax/taskfiles/program/Byte order detection/cmake-build-debug/CMakeFiles/Byte_order_detection.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Byte_order_detection.dir/depend

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
CMAKE_SOURCE_DIR = /nfs/homes/rverona-/metavery/CPP/raytracer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /nfs/homes/rverona-/metavery/CPP/raytracer/build

# Include any dependencies generated for this target.
include CMakeFiles/raytracer.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/raytracer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/raytracer.dir/flags.make

CMakeFiles/raytracer.dir/sources/main.cpp.o: CMakeFiles/raytracer.dir/flags.make
CMakeFiles/raytracer.dir/sources/main.cpp.o: ../sources/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/homes/rverona-/metavery/CPP/raytracer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/raytracer.dir/sources/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/raytracer.dir/sources/main.cpp.o -c /nfs/homes/rverona-/metavery/CPP/raytracer/sources/main.cpp

CMakeFiles/raytracer.dir/sources/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/raytracer.dir/sources/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /nfs/homes/rverona-/metavery/CPP/raytracer/sources/main.cpp > CMakeFiles/raytracer.dir/sources/main.cpp.i

CMakeFiles/raytracer.dir/sources/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/raytracer.dir/sources/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /nfs/homes/rverona-/metavery/CPP/raytracer/sources/main.cpp -o CMakeFiles/raytracer.dir/sources/main.cpp.s

CMakeFiles/raytracer.dir/sources/Tuple.cpp.o: CMakeFiles/raytracer.dir/flags.make
CMakeFiles/raytracer.dir/sources/Tuple.cpp.o: ../sources/Tuple.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/homes/rverona-/metavery/CPP/raytracer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/raytracer.dir/sources/Tuple.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/raytracer.dir/sources/Tuple.cpp.o -c /nfs/homes/rverona-/metavery/CPP/raytracer/sources/Tuple.cpp

CMakeFiles/raytracer.dir/sources/Tuple.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/raytracer.dir/sources/Tuple.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /nfs/homes/rverona-/metavery/CPP/raytracer/sources/Tuple.cpp > CMakeFiles/raytracer.dir/sources/Tuple.cpp.i

CMakeFiles/raytracer.dir/sources/Tuple.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/raytracer.dir/sources/Tuple.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /nfs/homes/rverona-/metavery/CPP/raytracer/sources/Tuple.cpp -o CMakeFiles/raytracer.dir/sources/Tuple.cpp.s

CMakeFiles/raytracer.dir/sources/Utils.cpp.o: CMakeFiles/raytracer.dir/flags.make
CMakeFiles/raytracer.dir/sources/Utils.cpp.o: ../sources/Utils.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/homes/rverona-/metavery/CPP/raytracer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/raytracer.dir/sources/Utils.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/raytracer.dir/sources/Utils.cpp.o -c /nfs/homes/rverona-/metavery/CPP/raytracer/sources/Utils.cpp

CMakeFiles/raytracer.dir/sources/Utils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/raytracer.dir/sources/Utils.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /nfs/homes/rverona-/metavery/CPP/raytracer/sources/Utils.cpp > CMakeFiles/raytracer.dir/sources/Utils.cpp.i

CMakeFiles/raytracer.dir/sources/Utils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/raytracer.dir/sources/Utils.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /nfs/homes/rverona-/metavery/CPP/raytracer/sources/Utils.cpp -o CMakeFiles/raytracer.dir/sources/Utils.cpp.s

# Object files for target raytracer
raytracer_OBJECTS = \
"CMakeFiles/raytracer.dir/sources/main.cpp.o" \
"CMakeFiles/raytracer.dir/sources/Tuple.cpp.o" \
"CMakeFiles/raytracer.dir/sources/Utils.cpp.o"

# External object files for target raytracer
raytracer_EXTERNAL_OBJECTS =

raytracer: CMakeFiles/raytracer.dir/sources/main.cpp.o
raytracer: CMakeFiles/raytracer.dir/sources/Tuple.cpp.o
raytracer: CMakeFiles/raytracer.dir/sources/Utils.cpp.o
raytracer: CMakeFiles/raytracer.dir/build.make
raytracer: /usr/lib/x86_64-linux-gnu/libglfw.so.3.3
raytracer: CMakeFiles/raytracer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/nfs/homes/rverona-/metavery/CPP/raytracer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable raytracer"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/raytracer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/raytracer.dir/build: raytracer

.PHONY : CMakeFiles/raytracer.dir/build

CMakeFiles/raytracer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/raytracer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/raytracer.dir/clean

CMakeFiles/raytracer.dir/depend:
	cd /nfs/homes/rverona-/metavery/CPP/raytracer/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /nfs/homes/rverona-/metavery/CPP/raytracer /nfs/homes/rverona-/metavery/CPP/raytracer /nfs/homes/rverona-/metavery/CPP/raytracer/build /nfs/homes/rverona-/metavery/CPP/raytracer/build /nfs/homes/rverona-/metavery/CPP/raytracer/build/CMakeFiles/raytracer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/raytracer.dir/depend

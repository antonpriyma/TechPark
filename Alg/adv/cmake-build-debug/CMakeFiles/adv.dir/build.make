# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /home/anton/.local/share/umake/ide/clion/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/anton/.local/share/umake/ide/clion/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/anton/CLionProjects/TechPark/Alg/adv

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/anton/CLionProjects/TechPark/Alg/adv/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/adv.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/adv.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/adv.dir/flags.make

CMakeFiles/adv.dir/main.cpp.o: CMakeFiles/adv.dir/flags.make
CMakeFiles/adv.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/anton/CLionProjects/TechPark/Alg/adv/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/adv.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/adv.dir/main.cpp.o -c /home/anton/CLionProjects/TechPark/Alg/adv/main.cpp

CMakeFiles/adv.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/adv.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/anton/CLionProjects/TechPark/Alg/adv/main.cpp > CMakeFiles/adv.dir/main.cpp.i

CMakeFiles/adv.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/adv.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/anton/CLionProjects/TechPark/Alg/adv/main.cpp -o CMakeFiles/adv.dir/main.cpp.s

CMakeFiles/adv.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/adv.dir/main.cpp.o.requires

CMakeFiles/adv.dir/main.cpp.o.provides: CMakeFiles/adv.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/adv.dir/build.make CMakeFiles/adv.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/adv.dir/main.cpp.o.provides

CMakeFiles/adv.dir/main.cpp.o.provides.build: CMakeFiles/adv.dir/main.cpp.o


# Object files for target adv
adv_OBJECTS = \
"CMakeFiles/adv.dir/main.cpp.o"

# External object files for target adv
adv_EXTERNAL_OBJECTS =

adv: CMakeFiles/adv.dir/main.cpp.o
adv: CMakeFiles/adv.dir/build.make
adv: CMakeFiles/adv.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/anton/CLionProjects/TechPark/Alg/adv/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable adv"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/adv.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/adv.dir/build: adv

.PHONY : CMakeFiles/adv.dir/build

CMakeFiles/adv.dir/requires: CMakeFiles/adv.dir/main.cpp.o.requires

.PHONY : CMakeFiles/adv.dir/requires

CMakeFiles/adv.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/adv.dir/cmake_clean.cmake
.PHONY : CMakeFiles/adv.dir/clean

CMakeFiles/adv.dir/depend:
	cd /home/anton/CLionProjects/TechPark/Alg/adv/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/anton/CLionProjects/TechPark/Alg/adv /home/anton/CLionProjects/TechPark/Alg/adv /home/anton/CLionProjects/TechPark/Alg/adv/cmake-build-debug /home/anton/CLionProjects/TechPark/Alg/adv/cmake-build-debug /home/anton/CLionProjects/TechPark/Alg/adv/cmake-build-debug/CMakeFiles/adv.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/adv.dir/depend

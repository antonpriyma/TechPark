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
CMAKE_SOURCE_DIR = /home/anton/CLionProjects/TechPark/Alg/quene

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/anton/CLionProjects/TechPark/Alg/quene/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/quene.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/quene.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/quene.dir/flags.make

CMakeFiles/quene.dir/main.cpp.o: CMakeFiles/quene.dir/flags.make
CMakeFiles/quene.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/anton/CLionProjects/TechPark/Alg/quene/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/quene.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/quene.dir/main.cpp.o -c /home/anton/CLionProjects/TechPark/Alg/quene/main.cpp

CMakeFiles/quene.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/quene.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/anton/CLionProjects/TechPark/Alg/quene/main.cpp > CMakeFiles/quene.dir/main.cpp.i

CMakeFiles/quene.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/quene.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/anton/CLionProjects/TechPark/Alg/quene/main.cpp -o CMakeFiles/quene.dir/main.cpp.s

CMakeFiles/quene.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/quene.dir/main.cpp.o.requires

CMakeFiles/quene.dir/main.cpp.o.provides: CMakeFiles/quene.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/quene.dir/build.make CMakeFiles/quene.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/quene.dir/main.cpp.o.provides

CMakeFiles/quene.dir/main.cpp.o.provides.build: CMakeFiles/quene.dir/main.cpp.o


# Object files for target quene
quene_OBJECTS = \
"CMakeFiles/quene.dir/main.cpp.o"

# External object files for target quene
quene_EXTERNAL_OBJECTS =

quene: CMakeFiles/quene.dir/main.cpp.o
quene: CMakeFiles/quene.dir/build.make
quene: CMakeFiles/quene.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/anton/CLionProjects/TechPark/Alg/quene/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable quene"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/quene.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/quene.dir/build: quene

.PHONY : CMakeFiles/quene.dir/build

CMakeFiles/quene.dir/requires: CMakeFiles/quene.dir/main.cpp.o.requires

.PHONY : CMakeFiles/quene.dir/requires

CMakeFiles/quene.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/quene.dir/cmake_clean.cmake
.PHONY : CMakeFiles/quene.dir/clean

CMakeFiles/quene.dir/depend:
	cd /home/anton/CLionProjects/TechPark/Alg/quene/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/anton/CLionProjects/TechPark/Alg/quene /home/anton/CLionProjects/TechPark/Alg/quene /home/anton/CLionProjects/TechPark/Alg/quene/cmake-build-debug /home/anton/CLionProjects/TechPark/Alg/quene/cmake-build-debug /home/anton/CLionProjects/TechPark/Alg/quene/cmake-build-debug/CMakeFiles/quene.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/quene.dir/depend


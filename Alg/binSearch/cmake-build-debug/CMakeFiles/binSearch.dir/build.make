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
CMAKE_SOURCE_DIR = /home/anton/CLionProjects/TechPark/Alg/binSearch

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/anton/CLionProjects/TechPark/Alg/binSearch/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/binSearch.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/binSearch.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/binSearch.dir/flags.make

CMakeFiles/binSearch.dir/main.cpp.o: CMakeFiles/binSearch.dir/flags.make
CMakeFiles/binSearch.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/anton/CLionProjects/TechPark/Alg/binSearch/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/binSearch.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/binSearch.dir/main.cpp.o -c /home/anton/CLionProjects/TechPark/Alg/binSearch/main.cpp

CMakeFiles/binSearch.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/binSearch.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/anton/CLionProjects/TechPark/Alg/binSearch/main.cpp > CMakeFiles/binSearch.dir/main.cpp.i

CMakeFiles/binSearch.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/binSearch.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/anton/CLionProjects/TechPark/Alg/binSearch/main.cpp -o CMakeFiles/binSearch.dir/main.cpp.s

CMakeFiles/binSearch.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/binSearch.dir/main.cpp.o.requires

CMakeFiles/binSearch.dir/main.cpp.o.provides: CMakeFiles/binSearch.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/binSearch.dir/build.make CMakeFiles/binSearch.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/binSearch.dir/main.cpp.o.provides

CMakeFiles/binSearch.dir/main.cpp.o.provides.build: CMakeFiles/binSearch.dir/main.cpp.o


# Object files for target binSearch
binSearch_OBJECTS = \
"CMakeFiles/binSearch.dir/main.cpp.o"

# External object files for target binSearch
binSearch_EXTERNAL_OBJECTS =

binSearch: CMakeFiles/binSearch.dir/main.cpp.o
binSearch: CMakeFiles/binSearch.dir/build.make
binSearch: CMakeFiles/binSearch.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/anton/CLionProjects/TechPark/Alg/binSearch/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable binSearch"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/binSearch.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/binSearch.dir/build: binSearch

.PHONY : CMakeFiles/binSearch.dir/build

CMakeFiles/binSearch.dir/requires: CMakeFiles/binSearch.dir/main.cpp.o.requires

.PHONY : CMakeFiles/binSearch.dir/requires

CMakeFiles/binSearch.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/binSearch.dir/cmake_clean.cmake
.PHONY : CMakeFiles/binSearch.dir/clean

CMakeFiles/binSearch.dir/depend:
	cd /home/anton/CLionProjects/TechPark/Alg/binSearch/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/anton/CLionProjects/TechPark/Alg/binSearch /home/anton/CLionProjects/TechPark/Alg/binSearch /home/anton/CLionProjects/TechPark/Alg/binSearch/cmake-build-debug /home/anton/CLionProjects/TechPark/Alg/binSearch/cmake-build-debug /home/anton/CLionProjects/TechPark/Alg/binSearch/cmake-build-debug/CMakeFiles/binSearch.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/binSearch.dir/depend

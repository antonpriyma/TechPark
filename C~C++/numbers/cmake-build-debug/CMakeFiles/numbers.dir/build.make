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
CMAKE_SOURCE_DIR = /home/anton/CLionProjects/tech_park/numbers

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/anton/CLionProjects/tech_park/numbers/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/numbers.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/numbers.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/numbers.dir/flags.make

CMakeFiles/numbers.dir/main.c.o: CMakeFiles/numbers.dir/flags.make
CMakeFiles/numbers.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/anton/CLionProjects/tech_park/numbers/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/numbers.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/numbers.dir/main.c.o   -c /home/anton/CLionProjects/tech_park/numbers/main.c

CMakeFiles/numbers.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/numbers.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/anton/CLionProjects/tech_park/numbers/main.c > CMakeFiles/numbers.dir/main.c.i

CMakeFiles/numbers.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/numbers.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/anton/CLionProjects/tech_park/numbers/main.c -o CMakeFiles/numbers.dir/main.c.s

CMakeFiles/numbers.dir/main.c.o.requires:

.PHONY : CMakeFiles/numbers.dir/main.c.o.requires

CMakeFiles/numbers.dir/main.c.o.provides: CMakeFiles/numbers.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/numbers.dir/build.make CMakeFiles/numbers.dir/main.c.o.provides.build
.PHONY : CMakeFiles/numbers.dir/main.c.o.provides

CMakeFiles/numbers.dir/main.c.o.provides.build: CMakeFiles/numbers.dir/main.c.o


# Object files for target numbers
numbers_OBJECTS = \
"CMakeFiles/numbers.dir/main.c.o"

# External object files for target numbers
numbers_EXTERNAL_OBJECTS =

numbers: CMakeFiles/numbers.dir/main.c.o
numbers: CMakeFiles/numbers.dir/build.make
numbers: CMakeFiles/numbers.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/anton/CLionProjects/tech_park/numbers/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable numbers"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/numbers.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/numbers.dir/build: numbers

.PHONY : CMakeFiles/numbers.dir/build

CMakeFiles/numbers.dir/requires: CMakeFiles/numbers.dir/main.c.o.requires

.PHONY : CMakeFiles/numbers.dir/requires

CMakeFiles/numbers.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/numbers.dir/cmake_clean.cmake
.PHONY : CMakeFiles/numbers.dir/clean

CMakeFiles/numbers.dir/depend:
	cd /home/anton/CLionProjects/tech_park/numbers/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/anton/CLionProjects/tech_park/numbers /home/anton/CLionProjects/tech_park/numbers /home/anton/CLionProjects/tech_park/numbers/cmake-build-debug /home/anton/CLionProjects/tech_park/numbers/cmake-build-debug /home/anton/CLionProjects/tech_park/numbers/cmake-build-debug/CMakeFiles/numbers.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/numbers.dir/depend


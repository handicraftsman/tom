# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_SOURCE_DIR = /home/handicraftsman/Projects/tom

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/handicraftsman/Projects/tom/build

# Include any dependencies generated for this target.
include CMakeFiles/tom-demo-greeter.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/tom-demo-greeter.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tom-demo-greeter.dir/flags.make

CMakeFiles/tom-demo-greeter.dir/greeter/greeter.cpp.o: CMakeFiles/tom-demo-greeter.dir/flags.make
CMakeFiles/tom-demo-greeter.dir/greeter/greeter.cpp.o: ../greeter/greeter.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/handicraftsman/Projects/tom/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/tom-demo-greeter.dir/greeter/greeter.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tom-demo-greeter.dir/greeter/greeter.cpp.o -c /home/handicraftsman/Projects/tom/greeter/greeter.cpp

CMakeFiles/tom-demo-greeter.dir/greeter/greeter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tom-demo-greeter.dir/greeter/greeter.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/handicraftsman/Projects/tom/greeter/greeter.cpp > CMakeFiles/tom-demo-greeter.dir/greeter/greeter.cpp.i

CMakeFiles/tom-demo-greeter.dir/greeter/greeter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tom-demo-greeter.dir/greeter/greeter.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/handicraftsman/Projects/tom/greeter/greeter.cpp -o CMakeFiles/tom-demo-greeter.dir/greeter/greeter.cpp.s

# Object files for target tom-demo-greeter
tom__demo__greeter_OBJECTS = \
"CMakeFiles/tom-demo-greeter.dir/greeter/greeter.cpp.o"

# External object files for target tom-demo-greeter
tom__demo__greeter_EXTERNAL_OBJECTS =

libtom-demo-greeter.so: CMakeFiles/tom-demo-greeter.dir/greeter/greeter.cpp.o
libtom-demo-greeter.so: CMakeFiles/tom-demo-greeter.dir/build.make
libtom-demo-greeter.so: libtom.so
libtom-demo-greeter.so: CMakeFiles/tom-demo-greeter.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/handicraftsman/Projects/tom/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library libtom-demo-greeter.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tom-demo-greeter.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tom-demo-greeter.dir/build: libtom-demo-greeter.so

.PHONY : CMakeFiles/tom-demo-greeter.dir/build

CMakeFiles/tom-demo-greeter.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tom-demo-greeter.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tom-demo-greeter.dir/clean

CMakeFiles/tom-demo-greeter.dir/depend:
	cd /home/handicraftsman/Projects/tom/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/handicraftsman/Projects/tom /home/handicraftsman/Projects/tom /home/handicraftsman/Projects/tom/build /home/handicraftsman/Projects/tom/build /home/handicraftsman/Projects/tom/build/CMakeFiles/tom-demo-greeter.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/tom-demo-greeter.dir/depend


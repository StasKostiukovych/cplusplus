# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /opt/clion-2018.3.4/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /opt/clion-2018.3.4/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/stas/CLionProjects/DateTime_Kostiukovych

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/stas/CLionProjects/DateTime_Kostiukovych/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/DateTime_Kostiukovych.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/DateTime_Kostiukovych.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DateTime_Kostiukovych.dir/flags.make

CMakeFiles/DateTime_Kostiukovych.dir/main.cpp.o: CMakeFiles/DateTime_Kostiukovych.dir/flags.make
CMakeFiles/DateTime_Kostiukovych.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/stas/CLionProjects/DateTime_Kostiukovych/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/DateTime_Kostiukovych.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DateTime_Kostiukovych.dir/main.cpp.o -c /home/stas/CLionProjects/DateTime_Kostiukovych/main.cpp

CMakeFiles/DateTime_Kostiukovych.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DateTime_Kostiukovych.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/stas/CLionProjects/DateTime_Kostiukovych/main.cpp > CMakeFiles/DateTime_Kostiukovych.dir/main.cpp.i

CMakeFiles/DateTime_Kostiukovych.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DateTime_Kostiukovych.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/stas/CLionProjects/DateTime_Kostiukovych/main.cpp -o CMakeFiles/DateTime_Kostiukovych.dir/main.cpp.s

CMakeFiles/DateTime_Kostiukovych.dir/src/Date.cpp.o: CMakeFiles/DateTime_Kostiukovych.dir/flags.make
CMakeFiles/DateTime_Kostiukovych.dir/src/Date.cpp.o: ../src/Date.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/stas/CLionProjects/DateTime_Kostiukovych/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/DateTime_Kostiukovych.dir/src/Date.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DateTime_Kostiukovych.dir/src/Date.cpp.o -c /home/stas/CLionProjects/DateTime_Kostiukovych/src/Date.cpp

CMakeFiles/DateTime_Kostiukovych.dir/src/Date.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DateTime_Kostiukovych.dir/src/Date.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/stas/CLionProjects/DateTime_Kostiukovych/src/Date.cpp > CMakeFiles/DateTime_Kostiukovych.dir/src/Date.cpp.i

CMakeFiles/DateTime_Kostiukovych.dir/src/Date.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DateTime_Kostiukovych.dir/src/Date.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/stas/CLionProjects/DateTime_Kostiukovych/src/Date.cpp -o CMakeFiles/DateTime_Kostiukovych.dir/src/Date.cpp.s

CMakeFiles/DateTime_Kostiukovych.dir/src/Time.cpp.o: CMakeFiles/DateTime_Kostiukovych.dir/flags.make
CMakeFiles/DateTime_Kostiukovych.dir/src/Time.cpp.o: ../src/Time.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/stas/CLionProjects/DateTime_Kostiukovych/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/DateTime_Kostiukovych.dir/src/Time.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DateTime_Kostiukovych.dir/src/Time.cpp.o -c /home/stas/CLionProjects/DateTime_Kostiukovych/src/Time.cpp

CMakeFiles/DateTime_Kostiukovych.dir/src/Time.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DateTime_Kostiukovych.dir/src/Time.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/stas/CLionProjects/DateTime_Kostiukovych/src/Time.cpp > CMakeFiles/DateTime_Kostiukovych.dir/src/Time.cpp.i

CMakeFiles/DateTime_Kostiukovych.dir/src/Time.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DateTime_Kostiukovych.dir/src/Time.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/stas/CLionProjects/DateTime_Kostiukovych/src/Time.cpp -o CMakeFiles/DateTime_Kostiukovych.dir/src/Time.cpp.s

# Object files for target DateTime_Kostiukovych
DateTime_Kostiukovych_OBJECTS = \
"CMakeFiles/DateTime_Kostiukovych.dir/main.cpp.o" \
"CMakeFiles/DateTime_Kostiukovych.dir/src/Date.cpp.o" \
"CMakeFiles/DateTime_Kostiukovych.dir/src/Time.cpp.o"

# External object files for target DateTime_Kostiukovych
DateTime_Kostiukovych_EXTERNAL_OBJECTS =

DateTime_Kostiukovych: CMakeFiles/DateTime_Kostiukovych.dir/main.cpp.o
DateTime_Kostiukovych: CMakeFiles/DateTime_Kostiukovych.dir/src/Date.cpp.o
DateTime_Kostiukovych: CMakeFiles/DateTime_Kostiukovych.dir/src/Time.cpp.o
DateTime_Kostiukovych: CMakeFiles/DateTime_Kostiukovych.dir/build.make
DateTime_Kostiukovych: CMakeFiles/DateTime_Kostiukovych.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/stas/CLionProjects/DateTime_Kostiukovych/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable DateTime_Kostiukovych"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/DateTime_Kostiukovych.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DateTime_Kostiukovych.dir/build: DateTime_Kostiukovych

.PHONY : CMakeFiles/DateTime_Kostiukovych.dir/build

CMakeFiles/DateTime_Kostiukovych.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/DateTime_Kostiukovych.dir/cmake_clean.cmake
.PHONY : CMakeFiles/DateTime_Kostiukovych.dir/clean

CMakeFiles/DateTime_Kostiukovych.dir/depend:
	cd /home/stas/CLionProjects/DateTime_Kostiukovych/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/stas/CLionProjects/DateTime_Kostiukovych /home/stas/CLionProjects/DateTime_Kostiukovych /home/stas/CLionProjects/DateTime_Kostiukovych/cmake-build-debug /home/stas/CLionProjects/DateTime_Kostiukovych/cmake-build-debug /home/stas/CLionProjects/DateTime_Kostiukovych/cmake-build-debug/CMakeFiles/DateTime_Kostiukovych.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/DateTime_Kostiukovych.dir/depend


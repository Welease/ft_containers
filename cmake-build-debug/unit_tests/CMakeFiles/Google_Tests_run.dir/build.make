# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/welease/projects/ft_containers

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/welease/projects/ft_containers/cmake-build-debug

# Include any dependencies generated for this target.
include unit_tests/CMakeFiles/Google_Tests_run.dir/depend.make

# Include the progress variables for this target.
include unit_tests/CMakeFiles/Google_Tests_run.dir/progress.make

# Include the compile flags for this target's objects.
include unit_tests/CMakeFiles/Google_Tests_run.dir/flags.make

unit_tests/CMakeFiles/Google_Tests_run.dir/map.cpp.o: unit_tests/CMakeFiles/Google_Tests_run.dir/flags.make
unit_tests/CMakeFiles/Google_Tests_run.dir/map.cpp.o: ../unit_tests/map.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/welease/projects/ft_containers/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object unit_tests/CMakeFiles/Google_Tests_run.dir/map.cpp.o"
	cd /Users/welease/projects/ft_containers/cmake-build-debug/unit_tests && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Google_Tests_run.dir/map.cpp.o -c /Users/welease/projects/ft_containers/unit_tests/map.cpp

unit_tests/CMakeFiles/Google_Tests_run.dir/map.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Google_Tests_run.dir/map.cpp.i"
	cd /Users/welease/projects/ft_containers/cmake-build-debug/unit_tests && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/welease/projects/ft_containers/unit_tests/map.cpp > CMakeFiles/Google_Tests_run.dir/map.cpp.i

unit_tests/CMakeFiles/Google_Tests_run.dir/map.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Google_Tests_run.dir/map.cpp.s"
	cd /Users/welease/projects/ft_containers/cmake-build-debug/unit_tests && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/welease/projects/ft_containers/unit_tests/map.cpp -o CMakeFiles/Google_Tests_run.dir/map.cpp.s

unit_tests/CMakeFiles/Google_Tests_run.dir/list.cpp.o: unit_tests/CMakeFiles/Google_Tests_run.dir/flags.make
unit_tests/CMakeFiles/Google_Tests_run.dir/list.cpp.o: ../unit_tests/list.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/welease/projects/ft_containers/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object unit_tests/CMakeFiles/Google_Tests_run.dir/list.cpp.o"
	cd /Users/welease/projects/ft_containers/cmake-build-debug/unit_tests && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Google_Tests_run.dir/list.cpp.o -c /Users/welease/projects/ft_containers/unit_tests/list.cpp

unit_tests/CMakeFiles/Google_Tests_run.dir/list.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Google_Tests_run.dir/list.cpp.i"
	cd /Users/welease/projects/ft_containers/cmake-build-debug/unit_tests && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/welease/projects/ft_containers/unit_tests/list.cpp > CMakeFiles/Google_Tests_run.dir/list.cpp.i

unit_tests/CMakeFiles/Google_Tests_run.dir/list.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Google_Tests_run.dir/list.cpp.s"
	cd /Users/welease/projects/ft_containers/cmake-build-debug/unit_tests && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/welease/projects/ft_containers/unit_tests/list.cpp -o CMakeFiles/Google_Tests_run.dir/list.cpp.s

unit_tests/CMakeFiles/Google_Tests_run.dir/queue.cpp.o: unit_tests/CMakeFiles/Google_Tests_run.dir/flags.make
unit_tests/CMakeFiles/Google_Tests_run.dir/queue.cpp.o: ../unit_tests/queue.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/welease/projects/ft_containers/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object unit_tests/CMakeFiles/Google_Tests_run.dir/queue.cpp.o"
	cd /Users/welease/projects/ft_containers/cmake-build-debug/unit_tests && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Google_Tests_run.dir/queue.cpp.o -c /Users/welease/projects/ft_containers/unit_tests/queue.cpp

unit_tests/CMakeFiles/Google_Tests_run.dir/queue.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Google_Tests_run.dir/queue.cpp.i"
	cd /Users/welease/projects/ft_containers/cmake-build-debug/unit_tests && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/welease/projects/ft_containers/unit_tests/queue.cpp > CMakeFiles/Google_Tests_run.dir/queue.cpp.i

unit_tests/CMakeFiles/Google_Tests_run.dir/queue.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Google_Tests_run.dir/queue.cpp.s"
	cd /Users/welease/projects/ft_containers/cmake-build-debug/unit_tests && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/welease/projects/ft_containers/unit_tests/queue.cpp -o CMakeFiles/Google_Tests_run.dir/queue.cpp.s

unit_tests/CMakeFiles/Google_Tests_run.dir/stack.cpp.o: unit_tests/CMakeFiles/Google_Tests_run.dir/flags.make
unit_tests/CMakeFiles/Google_Tests_run.dir/stack.cpp.o: ../unit_tests/stack.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/welease/projects/ft_containers/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object unit_tests/CMakeFiles/Google_Tests_run.dir/stack.cpp.o"
	cd /Users/welease/projects/ft_containers/cmake-build-debug/unit_tests && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Google_Tests_run.dir/stack.cpp.o -c /Users/welease/projects/ft_containers/unit_tests/stack.cpp

unit_tests/CMakeFiles/Google_Tests_run.dir/stack.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Google_Tests_run.dir/stack.cpp.i"
	cd /Users/welease/projects/ft_containers/cmake-build-debug/unit_tests && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/welease/projects/ft_containers/unit_tests/stack.cpp > CMakeFiles/Google_Tests_run.dir/stack.cpp.i

unit_tests/CMakeFiles/Google_Tests_run.dir/stack.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Google_Tests_run.dir/stack.cpp.s"
	cd /Users/welease/projects/ft_containers/cmake-build-debug/unit_tests && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/welease/projects/ft_containers/unit_tests/stack.cpp -o CMakeFiles/Google_Tests_run.dir/stack.cpp.s

unit_tests/CMakeFiles/Google_Tests_run.dir/test.cpp.o: unit_tests/CMakeFiles/Google_Tests_run.dir/flags.make
unit_tests/CMakeFiles/Google_Tests_run.dir/test.cpp.o: ../unit_tests/test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/welease/projects/ft_containers/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object unit_tests/CMakeFiles/Google_Tests_run.dir/test.cpp.o"
	cd /Users/welease/projects/ft_containers/cmake-build-debug/unit_tests && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Google_Tests_run.dir/test.cpp.o -c /Users/welease/projects/ft_containers/unit_tests/test.cpp

unit_tests/CMakeFiles/Google_Tests_run.dir/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Google_Tests_run.dir/test.cpp.i"
	cd /Users/welease/projects/ft_containers/cmake-build-debug/unit_tests && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/welease/projects/ft_containers/unit_tests/test.cpp > CMakeFiles/Google_Tests_run.dir/test.cpp.i

unit_tests/CMakeFiles/Google_Tests_run.dir/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Google_Tests_run.dir/test.cpp.s"
	cd /Users/welease/projects/ft_containers/cmake-build-debug/unit_tests && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/welease/projects/ft_containers/unit_tests/test.cpp -o CMakeFiles/Google_Tests_run.dir/test.cpp.s

unit_tests/CMakeFiles/Google_Tests_run.dir/vector.cpp.o: unit_tests/CMakeFiles/Google_Tests_run.dir/flags.make
unit_tests/CMakeFiles/Google_Tests_run.dir/vector.cpp.o: ../unit_tests/vector.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/welease/projects/ft_containers/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object unit_tests/CMakeFiles/Google_Tests_run.dir/vector.cpp.o"
	cd /Users/welease/projects/ft_containers/cmake-build-debug/unit_tests && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Google_Tests_run.dir/vector.cpp.o -c /Users/welease/projects/ft_containers/unit_tests/vector.cpp

unit_tests/CMakeFiles/Google_Tests_run.dir/vector.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Google_Tests_run.dir/vector.cpp.i"
	cd /Users/welease/projects/ft_containers/cmake-build-debug/unit_tests && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/welease/projects/ft_containers/unit_tests/vector.cpp > CMakeFiles/Google_Tests_run.dir/vector.cpp.i

unit_tests/CMakeFiles/Google_Tests_run.dir/vector.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Google_Tests_run.dir/vector.cpp.s"
	cd /Users/welease/projects/ft_containers/cmake-build-debug/unit_tests && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/welease/projects/ft_containers/unit_tests/vector.cpp -o CMakeFiles/Google_Tests_run.dir/vector.cpp.s

# Object files for target Google_Tests_run
Google_Tests_run_OBJECTS = \
"CMakeFiles/Google_Tests_run.dir/map.cpp.o" \
"CMakeFiles/Google_Tests_run.dir/list.cpp.o" \
"CMakeFiles/Google_Tests_run.dir/queue.cpp.o" \
"CMakeFiles/Google_Tests_run.dir/stack.cpp.o" \
"CMakeFiles/Google_Tests_run.dir/test.cpp.o" \
"CMakeFiles/Google_Tests_run.dir/vector.cpp.o"

# External object files for target Google_Tests_run
Google_Tests_run_EXTERNAL_OBJECTS =

unit_tests/Google_Tests_run: unit_tests/CMakeFiles/Google_Tests_run.dir/map.cpp.o
unit_tests/Google_Tests_run: unit_tests/CMakeFiles/Google_Tests_run.dir/list.cpp.o
unit_tests/Google_Tests_run: unit_tests/CMakeFiles/Google_Tests_run.dir/queue.cpp.o
unit_tests/Google_Tests_run: unit_tests/CMakeFiles/Google_Tests_run.dir/stack.cpp.o
unit_tests/Google_Tests_run: unit_tests/CMakeFiles/Google_Tests_run.dir/test.cpp.o
unit_tests/Google_Tests_run: unit_tests/CMakeFiles/Google_Tests_run.dir/vector.cpp.o
unit_tests/Google_Tests_run: unit_tests/CMakeFiles/Google_Tests_run.dir/build.make
unit_tests/Google_Tests_run: lib/libgtestd.a
unit_tests/Google_Tests_run: lib/libgtest_maind.a
unit_tests/Google_Tests_run: lib/libgtestd.a
unit_tests/Google_Tests_run: unit_tests/CMakeFiles/Google_Tests_run.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/welease/projects/ft_containers/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable Google_Tests_run"
	cd /Users/welease/projects/ft_containers/cmake-build-debug/unit_tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Google_Tests_run.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
unit_tests/CMakeFiles/Google_Tests_run.dir/build: unit_tests/Google_Tests_run

.PHONY : unit_tests/CMakeFiles/Google_Tests_run.dir/build

unit_tests/CMakeFiles/Google_Tests_run.dir/clean:
	cd /Users/welease/projects/ft_containers/cmake-build-debug/unit_tests && $(CMAKE_COMMAND) -P CMakeFiles/Google_Tests_run.dir/cmake_clean.cmake
.PHONY : unit_tests/CMakeFiles/Google_Tests_run.dir/clean

unit_tests/CMakeFiles/Google_Tests_run.dir/depend:
	cd /Users/welease/projects/ft_containers/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/welease/projects/ft_containers /Users/welease/projects/ft_containers/unit_tests /Users/welease/projects/ft_containers/cmake-build-debug /Users/welease/projects/ft_containers/cmake-build-debug/unit_tests /Users/welease/projects/ft_containers/cmake-build-debug/unit_tests/CMakeFiles/Google_Tests_run.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : unit_tests/CMakeFiles/Google_Tests_run.dir/depend


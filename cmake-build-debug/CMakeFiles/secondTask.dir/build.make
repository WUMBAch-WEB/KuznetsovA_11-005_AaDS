# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\WUMBAch\CLionProjects\untitled

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\WUMBAch\CLionProjects\untitled\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/secondTask.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/secondTask.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/secondTask.dir/flags.make

CMakeFiles/secondTask.dir/SecondWeekHW/SecondTask.cpp.obj: CMakeFiles/secondTask.dir/flags.make
CMakeFiles/secondTask.dir/SecondWeekHW/SecondTask.cpp.obj: SecondWeekHW/SecondTask.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\WUMBAch\CLionProjects\untitled\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/secondTask.dir/SecondWeekHW/SecondTask.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-W\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\secondTask.dir\SecondWeekHW\SecondTask.cpp.obj -c C:\Users\WUMBAch\CLionProjects\untitled\cmake-build-debug\SecondWeekHW\SecondTask.cpp

CMakeFiles/secondTask.dir/SecondWeekHW/SecondTask.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/secondTask.dir/SecondWeekHW/SecondTask.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-W\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\WUMBAch\CLionProjects\untitled\cmake-build-debug\SecondWeekHW\SecondTask.cpp > CMakeFiles\secondTask.dir\SecondWeekHW\SecondTask.cpp.i

CMakeFiles/secondTask.dir/SecondWeekHW/SecondTask.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/secondTask.dir/SecondWeekHW/SecondTask.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-W\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\WUMBAch\CLionProjects\untitled\cmake-build-debug\SecondWeekHW\SecondTask.cpp -o CMakeFiles\secondTask.dir\SecondWeekHW\SecondTask.cpp.s

# Object files for target secondTask
secondTask_OBJECTS = \
"CMakeFiles/secondTask.dir/SecondWeekHW/SecondTask.cpp.obj"

# External object files for target secondTask
secondTask_EXTERNAL_OBJECTS =

secondTask.exe: CMakeFiles/secondTask.dir/SecondWeekHW/SecondTask.cpp.obj
secondTask.exe: CMakeFiles/secondTask.dir/build.make
secondTask.exe: CMakeFiles/secondTask.dir/linklibs.rsp
secondTask.exe: CMakeFiles/secondTask.dir/objects1.rsp
secondTask.exe: CMakeFiles/secondTask.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\WUMBAch\CLionProjects\untitled\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable secondTask.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\secondTask.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/secondTask.dir/build: secondTask.exe

.PHONY : CMakeFiles/secondTask.dir/build

CMakeFiles/secondTask.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\secondTask.dir\cmake_clean.cmake
.PHONY : CMakeFiles/secondTask.dir/clean

CMakeFiles/secondTask.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\WUMBAch\CLionProjects\untitled C:\Users\WUMBAch\CLionProjects\untitled C:\Users\WUMBAch\CLionProjects\untitled\cmake-build-debug C:\Users\WUMBAch\CLionProjects\untitled\cmake-build-debug C:\Users\WUMBAch\CLionProjects\untitled\cmake-build-debug\CMakeFiles\secondTask.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/secondTask.dir/depend


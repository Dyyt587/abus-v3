# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.29

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\33368\Documents\GitHub\abus-v3\src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\33368\Documents\GitHub\abus-v3\src\build

# Include any dependencies generated for this target.
include CMakeFiles/abus_v3.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/abus_v3.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/abus_v3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/abus_v3.dir/flags.make

CMakeFiles/abus_v3.dir/abus_acc.c.obj: CMakeFiles/abus_v3.dir/flags.make
CMakeFiles/abus_v3.dir/abus_acc.c.obj: CMakeFiles/abus_v3.dir/includes_C.rsp
CMakeFiles/abus_v3.dir/abus_acc.c.obj: C:/Users/33368/Documents/GitHub/abus-v3/src/abus_acc.c
CMakeFiles/abus_v3.dir/abus_acc.c.obj: CMakeFiles/abus_v3.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\33368\Documents\GitHub\abus-v3\src\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/abus_v3.dir/abus_acc.c.obj"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/abus_v3.dir/abus_acc.c.obj -MF CMakeFiles\abus_v3.dir\abus_acc.c.obj.d -o CMakeFiles\abus_v3.dir\abus_acc.c.obj -c C:\Users\33368\Documents\GitHub\abus-v3\src\abus_acc.c

CMakeFiles/abus_v3.dir/abus_acc.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/abus_v3.dir/abus_acc.c.i"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\33368\Documents\GitHub\abus-v3\src\abus_acc.c > CMakeFiles\abus_v3.dir\abus_acc.c.i

CMakeFiles/abus_v3.dir/abus_acc.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/abus_v3.dir/abus_acc.c.s"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\33368\Documents\GitHub\abus-v3\src\abus_acc.c -o CMakeFiles\abus_v3.dir\abus_acc.c.s

CMakeFiles/abus_v3.dir/abus_hash.c.obj: CMakeFiles/abus_v3.dir/flags.make
CMakeFiles/abus_v3.dir/abus_hash.c.obj: CMakeFiles/abus_v3.dir/includes_C.rsp
CMakeFiles/abus_v3.dir/abus_hash.c.obj: C:/Users/33368/Documents/GitHub/abus-v3/src/abus_hash.c
CMakeFiles/abus_v3.dir/abus_hash.c.obj: CMakeFiles/abus_v3.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\33368\Documents\GitHub\abus-v3\src\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/abus_v3.dir/abus_hash.c.obj"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/abus_v3.dir/abus_hash.c.obj -MF CMakeFiles\abus_v3.dir\abus_hash.c.obj.d -o CMakeFiles\abus_v3.dir\abus_hash.c.obj -c C:\Users\33368\Documents\GitHub\abus-v3\src\abus_hash.c

CMakeFiles/abus_v3.dir/abus_hash.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/abus_v3.dir/abus_hash.c.i"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\33368\Documents\GitHub\abus-v3\src\abus_hash.c > CMakeFiles\abus_v3.dir\abus_hash.c.i

CMakeFiles/abus_v3.dir/abus_hash.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/abus_v3.dir/abus_hash.c.s"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\33368\Documents\GitHub\abus-v3\src\abus_hash.c -o CMakeFiles\abus_v3.dir\abus_hash.c.s

CMakeFiles/abus_v3.dir/abus_topic.c.obj: CMakeFiles/abus_v3.dir/flags.make
CMakeFiles/abus_v3.dir/abus_topic.c.obj: CMakeFiles/abus_v3.dir/includes_C.rsp
CMakeFiles/abus_v3.dir/abus_topic.c.obj: C:/Users/33368/Documents/GitHub/abus-v3/src/abus_topic.c
CMakeFiles/abus_v3.dir/abus_topic.c.obj: CMakeFiles/abus_v3.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\33368\Documents\GitHub\abus-v3\src\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/abus_v3.dir/abus_topic.c.obj"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/abus_v3.dir/abus_topic.c.obj -MF CMakeFiles\abus_v3.dir\abus_topic.c.obj.d -o CMakeFiles\abus_v3.dir\abus_topic.c.obj -c C:\Users\33368\Documents\GitHub\abus-v3\src\abus_topic.c

CMakeFiles/abus_v3.dir/abus_topic.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/abus_v3.dir/abus_topic.c.i"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\33368\Documents\GitHub\abus-v3\src\abus_topic.c > CMakeFiles\abus_v3.dir\abus_topic.c.i

CMakeFiles/abus_v3.dir/abus_topic.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/abus_v3.dir/abus_topic.c.s"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\33368\Documents\GitHub\abus-v3\src\abus_topic.c -o CMakeFiles\abus_v3.dir\abus_topic.c.s

CMakeFiles/abus_v3.dir/abus_v3.cpp.obj: CMakeFiles/abus_v3.dir/flags.make
CMakeFiles/abus_v3.dir/abus_v3.cpp.obj: CMakeFiles/abus_v3.dir/includes_CXX.rsp
CMakeFiles/abus_v3.dir/abus_v3.cpp.obj: C:/Users/33368/Documents/GitHub/abus-v3/src/abus_v3.cpp
CMakeFiles/abus_v3.dir/abus_v3.cpp.obj: CMakeFiles/abus_v3.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\33368\Documents\GitHub\abus-v3\src\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/abus_v3.dir/abus_v3.cpp.obj"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/abus_v3.dir/abus_v3.cpp.obj -MF CMakeFiles\abus_v3.dir\abus_v3.cpp.obj.d -o CMakeFiles\abus_v3.dir\abus_v3.cpp.obj -c C:\Users\33368\Documents\GitHub\abus-v3\src\abus_v3.cpp

CMakeFiles/abus_v3.dir/abus_v3.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/abus_v3.dir/abus_v3.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\33368\Documents\GitHub\abus-v3\src\abus_v3.cpp > CMakeFiles\abus_v3.dir\abus_v3.cpp.i

CMakeFiles/abus_v3.dir/abus_v3.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/abus_v3.dir/abus_v3.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\33368\Documents\GitHub\abus-v3\src\abus_v3.cpp -o CMakeFiles\abus_v3.dir\abus_v3.cpp.s

CMakeFiles/abus_v3.dir/afifo.c.obj: CMakeFiles/abus_v3.dir/flags.make
CMakeFiles/abus_v3.dir/afifo.c.obj: CMakeFiles/abus_v3.dir/includes_C.rsp
CMakeFiles/abus_v3.dir/afifo.c.obj: C:/Users/33368/Documents/GitHub/abus-v3/src/afifo.c
CMakeFiles/abus_v3.dir/afifo.c.obj: CMakeFiles/abus_v3.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\33368\Documents\GitHub\abus-v3\src\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/abus_v3.dir/afifo.c.obj"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/abus_v3.dir/afifo.c.obj -MF CMakeFiles\abus_v3.dir\afifo.c.obj.d -o CMakeFiles\abus_v3.dir\afifo.c.obj -c C:\Users\33368\Documents\GitHub\abus-v3\src\afifo.c

CMakeFiles/abus_v3.dir/afifo.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/abus_v3.dir/afifo.c.i"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\33368\Documents\GitHub\abus-v3\src\afifo.c > CMakeFiles\abus_v3.dir\afifo.c.i

CMakeFiles/abus_v3.dir/afifo.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/abus_v3.dir/afifo.c.s"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\33368\Documents\GitHub\abus-v3\src\afifo.c -o CMakeFiles\abus_v3.dir\afifo.c.s

CMakeFiles/abus_v3.dir/all_check.c.obj: CMakeFiles/abus_v3.dir/flags.make
CMakeFiles/abus_v3.dir/all_check.c.obj: CMakeFiles/abus_v3.dir/includes_C.rsp
CMakeFiles/abus_v3.dir/all_check.c.obj: C:/Users/33368/Documents/GitHub/abus-v3/src/all_check.c
CMakeFiles/abus_v3.dir/all_check.c.obj: CMakeFiles/abus_v3.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\33368\Documents\GitHub\abus-v3\src\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/abus_v3.dir/all_check.c.obj"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/abus_v3.dir/all_check.c.obj -MF CMakeFiles\abus_v3.dir\all_check.c.obj.d -o CMakeFiles\abus_v3.dir\all_check.c.obj -c C:\Users\33368\Documents\GitHub\abus-v3\src\all_check.c

CMakeFiles/abus_v3.dir/all_check.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/abus_v3.dir/all_check.c.i"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\33368\Documents\GitHub\abus-v3\src\all_check.c > CMakeFiles\abus_v3.dir\all_check.c.i

CMakeFiles/abus_v3.dir/all_check.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/abus_v3.dir/all_check.c.s"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\33368\Documents\GitHub\abus-v3\src\all_check.c -o CMakeFiles\abus_v3.dir\all_check.c.s

CMakeFiles/abus_v3.dir/cvector.c.obj: CMakeFiles/abus_v3.dir/flags.make
CMakeFiles/abus_v3.dir/cvector.c.obj: CMakeFiles/abus_v3.dir/includes_C.rsp
CMakeFiles/abus_v3.dir/cvector.c.obj: C:/Users/33368/Documents/GitHub/abus-v3/src/cvector.c
CMakeFiles/abus_v3.dir/cvector.c.obj: CMakeFiles/abus_v3.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\33368\Documents\GitHub\abus-v3\src\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/abus_v3.dir/cvector.c.obj"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/abus_v3.dir/cvector.c.obj -MF CMakeFiles\abus_v3.dir\cvector.c.obj.d -o CMakeFiles\abus_v3.dir\cvector.c.obj -c C:\Users\33368\Documents\GitHub\abus-v3\src\cvector.c

CMakeFiles/abus_v3.dir/cvector.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/abus_v3.dir/cvector.c.i"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\33368\Documents\GitHub\abus-v3\src\cvector.c > CMakeFiles\abus_v3.dir\cvector.c.i

CMakeFiles/abus_v3.dir/cvector.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/abus_v3.dir/cvector.c.s"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\33368\Documents\GitHub\abus-v3\src\cvector.c -o CMakeFiles\abus_v3.dir\cvector.c.s

# Object files for target abus_v3
abus_v3_OBJECTS = \
"CMakeFiles/abus_v3.dir/abus_acc.c.obj" \
"CMakeFiles/abus_v3.dir/abus_hash.c.obj" \
"CMakeFiles/abus_v3.dir/abus_topic.c.obj" \
"CMakeFiles/abus_v3.dir/abus_v3.cpp.obj" \
"CMakeFiles/abus_v3.dir/afifo.c.obj" \
"CMakeFiles/abus_v3.dir/all_check.c.obj" \
"CMakeFiles/abus_v3.dir/cvector.c.obj"

# External object files for target abus_v3
abus_v3_EXTERNAL_OBJECTS =

abus_v3.exe: CMakeFiles/abus_v3.dir/abus_acc.c.obj
abus_v3.exe: CMakeFiles/abus_v3.dir/abus_hash.c.obj
abus_v3.exe: CMakeFiles/abus_v3.dir/abus_topic.c.obj
abus_v3.exe: CMakeFiles/abus_v3.dir/abus_v3.cpp.obj
abus_v3.exe: CMakeFiles/abus_v3.dir/afifo.c.obj
abus_v3.exe: CMakeFiles/abus_v3.dir/all_check.c.obj
abus_v3.exe: CMakeFiles/abus_v3.dir/cvector.c.obj
abus_v3.exe: CMakeFiles/abus_v3.dir/build.make
abus_v3.exe: CMakeFiles/abus_v3.dir/linkLibs.rsp
abus_v3.exe: CMakeFiles/abus_v3.dir/objects1.rsp
abus_v3.exe: CMakeFiles/abus_v3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\33368\Documents\GitHub\abus-v3\src\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable abus_v3.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\abus_v3.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/abus_v3.dir/build: abus_v3.exe
.PHONY : CMakeFiles/abus_v3.dir/build

CMakeFiles/abus_v3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\abus_v3.dir\cmake_clean.cmake
.PHONY : CMakeFiles/abus_v3.dir/clean

CMakeFiles/abus_v3.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\33368\Documents\GitHub\abus-v3\src C:\Users\33368\Documents\GitHub\abus-v3\src C:\Users\33368\Documents\GitHub\abus-v3\src\build C:\Users\33368\Documents\GitHub\abus-v3\src\build C:\Users\33368\Documents\GitHub\abus-v3\src\build\CMakeFiles\abus_v3.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/abus_v3.dir/depend


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
include CMakeFiles/HelloWorld.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/HelloWorld.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/HelloWorld.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/HelloWorld.dir/flags.make

CMakeFiles/HelloWorld.dir/abus_acc.c.obj: CMakeFiles/HelloWorld.dir/flags.make
CMakeFiles/HelloWorld.dir/abus_acc.c.obj: CMakeFiles/HelloWorld.dir/includes_C.rsp
CMakeFiles/HelloWorld.dir/abus_acc.c.obj: C:/Users/33368/Documents/GitHub/abus-v3/src/abus_acc.c
CMakeFiles/HelloWorld.dir/abus_acc.c.obj: CMakeFiles/HelloWorld.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\33368\Documents\GitHub\abus-v3\src\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/HelloWorld.dir/abus_acc.c.obj"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/HelloWorld.dir/abus_acc.c.obj -MF CMakeFiles\HelloWorld.dir\abus_acc.c.obj.d -o CMakeFiles\HelloWorld.dir\abus_acc.c.obj -c C:\Users\33368\Documents\GitHub\abus-v3\src\abus_acc.c

CMakeFiles/HelloWorld.dir/abus_acc.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/HelloWorld.dir/abus_acc.c.i"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\33368\Documents\GitHub\abus-v3\src\abus_acc.c > CMakeFiles\HelloWorld.dir\abus_acc.c.i

CMakeFiles/HelloWorld.dir/abus_acc.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/HelloWorld.dir/abus_acc.c.s"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\33368\Documents\GitHub\abus-v3\src\abus_acc.c -o CMakeFiles\HelloWorld.dir\abus_acc.c.s

CMakeFiles/HelloWorld.dir/abus_hash.c.obj: CMakeFiles/HelloWorld.dir/flags.make
CMakeFiles/HelloWorld.dir/abus_hash.c.obj: CMakeFiles/HelloWorld.dir/includes_C.rsp
CMakeFiles/HelloWorld.dir/abus_hash.c.obj: C:/Users/33368/Documents/GitHub/abus-v3/src/abus_hash.c
CMakeFiles/HelloWorld.dir/abus_hash.c.obj: CMakeFiles/HelloWorld.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\33368\Documents\GitHub\abus-v3\src\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/HelloWorld.dir/abus_hash.c.obj"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/HelloWorld.dir/abus_hash.c.obj -MF CMakeFiles\HelloWorld.dir\abus_hash.c.obj.d -o CMakeFiles\HelloWorld.dir\abus_hash.c.obj -c C:\Users\33368\Documents\GitHub\abus-v3\src\abus_hash.c

CMakeFiles/HelloWorld.dir/abus_hash.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/HelloWorld.dir/abus_hash.c.i"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\33368\Documents\GitHub\abus-v3\src\abus_hash.c > CMakeFiles\HelloWorld.dir\abus_hash.c.i

CMakeFiles/HelloWorld.dir/abus_hash.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/HelloWorld.dir/abus_hash.c.s"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\33368\Documents\GitHub\abus-v3\src\abus_hash.c -o CMakeFiles\HelloWorld.dir\abus_hash.c.s

CMakeFiles/HelloWorld.dir/abus_topic.c.obj: CMakeFiles/HelloWorld.dir/flags.make
CMakeFiles/HelloWorld.dir/abus_topic.c.obj: CMakeFiles/HelloWorld.dir/includes_C.rsp
CMakeFiles/HelloWorld.dir/abus_topic.c.obj: C:/Users/33368/Documents/GitHub/abus-v3/src/abus_topic.c
CMakeFiles/HelloWorld.dir/abus_topic.c.obj: CMakeFiles/HelloWorld.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\33368\Documents\GitHub\abus-v3\src\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/HelloWorld.dir/abus_topic.c.obj"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/HelloWorld.dir/abus_topic.c.obj -MF CMakeFiles\HelloWorld.dir\abus_topic.c.obj.d -o CMakeFiles\HelloWorld.dir\abus_topic.c.obj -c C:\Users\33368\Documents\GitHub\abus-v3\src\abus_topic.c

CMakeFiles/HelloWorld.dir/abus_topic.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/HelloWorld.dir/abus_topic.c.i"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\33368\Documents\GitHub\abus-v3\src\abus_topic.c > CMakeFiles\HelloWorld.dir\abus_topic.c.i

CMakeFiles/HelloWorld.dir/abus_topic.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/HelloWorld.dir/abus_topic.c.s"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\33368\Documents\GitHub\abus-v3\src\abus_topic.c -o CMakeFiles\HelloWorld.dir\abus_topic.c.s

CMakeFiles/HelloWorld.dir/abus_v3.cpp.obj: CMakeFiles/HelloWorld.dir/flags.make
CMakeFiles/HelloWorld.dir/abus_v3.cpp.obj: CMakeFiles/HelloWorld.dir/includes_CXX.rsp
CMakeFiles/HelloWorld.dir/abus_v3.cpp.obj: C:/Users/33368/Documents/GitHub/abus-v3/src/abus_v3.cpp
CMakeFiles/HelloWorld.dir/abus_v3.cpp.obj: CMakeFiles/HelloWorld.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\33368\Documents\GitHub\abus-v3\src\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/HelloWorld.dir/abus_v3.cpp.obj"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/HelloWorld.dir/abus_v3.cpp.obj -MF CMakeFiles\HelloWorld.dir\abus_v3.cpp.obj.d -o CMakeFiles\HelloWorld.dir\abus_v3.cpp.obj -c C:\Users\33368\Documents\GitHub\abus-v3\src\abus_v3.cpp

CMakeFiles/HelloWorld.dir/abus_v3.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/HelloWorld.dir/abus_v3.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\33368\Documents\GitHub\abus-v3\src\abus_v3.cpp > CMakeFiles\HelloWorld.dir\abus_v3.cpp.i

CMakeFiles/HelloWorld.dir/abus_v3.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/HelloWorld.dir/abus_v3.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\33368\Documents\GitHub\abus-v3\src\abus_v3.cpp -o CMakeFiles\HelloWorld.dir\abus_v3.cpp.s

CMakeFiles/HelloWorld.dir/afifo.c.obj: CMakeFiles/HelloWorld.dir/flags.make
CMakeFiles/HelloWorld.dir/afifo.c.obj: CMakeFiles/HelloWorld.dir/includes_C.rsp
CMakeFiles/HelloWorld.dir/afifo.c.obj: C:/Users/33368/Documents/GitHub/abus-v3/src/afifo.c
CMakeFiles/HelloWorld.dir/afifo.c.obj: CMakeFiles/HelloWorld.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\33368\Documents\GitHub\abus-v3\src\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/HelloWorld.dir/afifo.c.obj"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/HelloWorld.dir/afifo.c.obj -MF CMakeFiles\HelloWorld.dir\afifo.c.obj.d -o CMakeFiles\HelloWorld.dir\afifo.c.obj -c C:\Users\33368\Documents\GitHub\abus-v3\src\afifo.c

CMakeFiles/HelloWorld.dir/afifo.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/HelloWorld.dir/afifo.c.i"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\33368\Documents\GitHub\abus-v3\src\afifo.c > CMakeFiles\HelloWorld.dir\afifo.c.i

CMakeFiles/HelloWorld.dir/afifo.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/HelloWorld.dir/afifo.c.s"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\33368\Documents\GitHub\abus-v3\src\afifo.c -o CMakeFiles\HelloWorld.dir\afifo.c.s

CMakeFiles/HelloWorld.dir/all_check.c.obj: CMakeFiles/HelloWorld.dir/flags.make
CMakeFiles/HelloWorld.dir/all_check.c.obj: CMakeFiles/HelloWorld.dir/includes_C.rsp
CMakeFiles/HelloWorld.dir/all_check.c.obj: C:/Users/33368/Documents/GitHub/abus-v3/src/all_check.c
CMakeFiles/HelloWorld.dir/all_check.c.obj: CMakeFiles/HelloWorld.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\33368\Documents\GitHub\abus-v3\src\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/HelloWorld.dir/all_check.c.obj"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/HelloWorld.dir/all_check.c.obj -MF CMakeFiles\HelloWorld.dir\all_check.c.obj.d -o CMakeFiles\HelloWorld.dir\all_check.c.obj -c C:\Users\33368\Documents\GitHub\abus-v3\src\all_check.c

CMakeFiles/HelloWorld.dir/all_check.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/HelloWorld.dir/all_check.c.i"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\33368\Documents\GitHub\abus-v3\src\all_check.c > CMakeFiles\HelloWorld.dir\all_check.c.i

CMakeFiles/HelloWorld.dir/all_check.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/HelloWorld.dir/all_check.c.s"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\33368\Documents\GitHub\abus-v3\src\all_check.c -o CMakeFiles\HelloWorld.dir\all_check.c.s

CMakeFiles/HelloWorld.dir/cvector.c.obj: CMakeFiles/HelloWorld.dir/flags.make
CMakeFiles/HelloWorld.dir/cvector.c.obj: CMakeFiles/HelloWorld.dir/includes_C.rsp
CMakeFiles/HelloWorld.dir/cvector.c.obj: C:/Users/33368/Documents/GitHub/abus-v3/src/cvector.c
CMakeFiles/HelloWorld.dir/cvector.c.obj: CMakeFiles/HelloWorld.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\33368\Documents\GitHub\abus-v3\src\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/HelloWorld.dir/cvector.c.obj"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/HelloWorld.dir/cvector.c.obj -MF CMakeFiles\HelloWorld.dir\cvector.c.obj.d -o CMakeFiles\HelloWorld.dir\cvector.c.obj -c C:\Users\33368\Documents\GitHub\abus-v3\src\cvector.c

CMakeFiles/HelloWorld.dir/cvector.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/HelloWorld.dir/cvector.c.i"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\33368\Documents\GitHub\abus-v3\src\cvector.c > CMakeFiles\HelloWorld.dir\cvector.c.i

CMakeFiles/HelloWorld.dir/cvector.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/HelloWorld.dir/cvector.c.s"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\33368\Documents\GitHub\abus-v3\src\cvector.c -o CMakeFiles\HelloWorld.dir\cvector.c.s

# Object files for target HelloWorld
HelloWorld_OBJECTS = \
"CMakeFiles/HelloWorld.dir/abus_acc.c.obj" \
"CMakeFiles/HelloWorld.dir/abus_hash.c.obj" \
"CMakeFiles/HelloWorld.dir/abus_topic.c.obj" \
"CMakeFiles/HelloWorld.dir/abus_v3.cpp.obj" \
"CMakeFiles/HelloWorld.dir/afifo.c.obj" \
"CMakeFiles/HelloWorld.dir/all_check.c.obj" \
"CMakeFiles/HelloWorld.dir/cvector.c.obj"

# External object files for target HelloWorld
HelloWorld_EXTERNAL_OBJECTS =

HelloWorld.exe: CMakeFiles/HelloWorld.dir/abus_acc.c.obj
HelloWorld.exe: CMakeFiles/HelloWorld.dir/abus_hash.c.obj
HelloWorld.exe: CMakeFiles/HelloWorld.dir/abus_topic.c.obj
HelloWorld.exe: CMakeFiles/HelloWorld.dir/abus_v3.cpp.obj
HelloWorld.exe: CMakeFiles/HelloWorld.dir/afifo.c.obj
HelloWorld.exe: CMakeFiles/HelloWorld.dir/all_check.c.obj
HelloWorld.exe: CMakeFiles/HelloWorld.dir/cvector.c.obj
HelloWorld.exe: CMakeFiles/HelloWorld.dir/build.make
HelloWorld.exe: CMakeFiles/HelloWorld.dir/linkLibs.rsp
HelloWorld.exe: CMakeFiles/HelloWorld.dir/objects1.rsp
HelloWorld.exe: CMakeFiles/HelloWorld.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\33368\Documents\GitHub\abus-v3\src\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable HelloWorld.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\HelloWorld.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/HelloWorld.dir/build: HelloWorld.exe
.PHONY : CMakeFiles/HelloWorld.dir/build

CMakeFiles/HelloWorld.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\HelloWorld.dir\cmake_clean.cmake
.PHONY : CMakeFiles/HelloWorld.dir/clean

CMakeFiles/HelloWorld.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\33368\Documents\GitHub\abus-v3\src C:\Users\33368\Documents\GitHub\abus-v3\src C:\Users\33368\Documents\GitHub\abus-v3\src\build C:\Users\33368\Documents\GitHub\abus-v3\src\build C:\Users\33368\Documents\GitHub\abus-v3\src\build\CMakeFiles\HelloWorld.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/HelloWorld.dir/depend


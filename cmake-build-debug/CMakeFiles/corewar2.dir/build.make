# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /nfs/2016/m/maksenov/CLionProjects/corewar2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /nfs/2016/m/maksenov/CLionProjects/corewar2/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/corewar2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/corewar2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/corewar2.dir/flags.make

CMakeFiles/corewar2.dir/asm_to_binary.c.o: CMakeFiles/corewar2.dir/flags.make
CMakeFiles/corewar2.dir/asm_to_binary.c.o: ../asm_to_binary.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/2016/m/maksenov/CLionProjects/corewar2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/corewar2.dir/asm_to_binary.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/corewar2.dir/asm_to_binary.c.o   -c /nfs/2016/m/maksenov/CLionProjects/corewar2/asm_to_binary.c

CMakeFiles/corewar2.dir/asm_to_binary.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/corewar2.dir/asm_to_binary.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /nfs/2016/m/maksenov/CLionProjects/corewar2/asm_to_binary.c > CMakeFiles/corewar2.dir/asm_to_binary.c.i

CMakeFiles/corewar2.dir/asm_to_binary.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/corewar2.dir/asm_to_binary.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /nfs/2016/m/maksenov/CLionProjects/corewar2/asm_to_binary.c -o CMakeFiles/corewar2.dir/asm_to_binary.c.s

CMakeFiles/corewar2.dir/asm_to_binary.c.o.requires:

.PHONY : CMakeFiles/corewar2.dir/asm_to_binary.c.o.requires

CMakeFiles/corewar2.dir/asm_to_binary.c.o.provides: CMakeFiles/corewar2.dir/asm_to_binary.c.o.requires
	$(MAKE) -f CMakeFiles/corewar2.dir/build.make CMakeFiles/corewar2.dir/asm_to_binary.c.o.provides.build
.PHONY : CMakeFiles/corewar2.dir/asm_to_binary.c.o.provides

CMakeFiles/corewar2.dir/asm_to_binary.c.o.provides.build: CMakeFiles/corewar2.dir/asm_to_binary.c.o


CMakeFiles/corewar2.dir/sub.c.o: CMakeFiles/corewar2.dir/flags.make
CMakeFiles/corewar2.dir/sub.c.o: ../sub.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/2016/m/maksenov/CLionProjects/corewar2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/corewar2.dir/sub.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/corewar2.dir/sub.c.o   -c /nfs/2016/m/maksenov/CLionProjects/corewar2/sub.c

CMakeFiles/corewar2.dir/sub.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/corewar2.dir/sub.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /nfs/2016/m/maksenov/CLionProjects/corewar2/sub.c > CMakeFiles/corewar2.dir/sub.c.i

CMakeFiles/corewar2.dir/sub.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/corewar2.dir/sub.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /nfs/2016/m/maksenov/CLionProjects/corewar2/sub.c -o CMakeFiles/corewar2.dir/sub.c.s

CMakeFiles/corewar2.dir/sub.c.o.requires:

.PHONY : CMakeFiles/corewar2.dir/sub.c.o.requires

CMakeFiles/corewar2.dir/sub.c.o.provides: CMakeFiles/corewar2.dir/sub.c.o.requires
	$(MAKE) -f CMakeFiles/corewar2.dir/build.make CMakeFiles/corewar2.dir/sub.c.o.provides.build
.PHONY : CMakeFiles/corewar2.dir/sub.c.o.provides

CMakeFiles/corewar2.dir/sub.c.o.provides.build: CMakeFiles/corewar2.dir/sub.c.o


CMakeFiles/corewar2.dir/ft_strsplit_v2.c.o: CMakeFiles/corewar2.dir/flags.make
CMakeFiles/corewar2.dir/ft_strsplit_v2.c.o: ../ft_strsplit_v2.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/2016/m/maksenov/CLionProjects/corewar2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/corewar2.dir/ft_strsplit_v2.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/corewar2.dir/ft_strsplit_v2.c.o   -c /nfs/2016/m/maksenov/CLionProjects/corewar2/ft_strsplit_v2.c

CMakeFiles/corewar2.dir/ft_strsplit_v2.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/corewar2.dir/ft_strsplit_v2.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /nfs/2016/m/maksenov/CLionProjects/corewar2/ft_strsplit_v2.c > CMakeFiles/corewar2.dir/ft_strsplit_v2.c.i

CMakeFiles/corewar2.dir/ft_strsplit_v2.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/corewar2.dir/ft_strsplit_v2.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /nfs/2016/m/maksenov/CLionProjects/corewar2/ft_strsplit_v2.c -o CMakeFiles/corewar2.dir/ft_strsplit_v2.c.s

CMakeFiles/corewar2.dir/ft_strsplit_v2.c.o.requires:

.PHONY : CMakeFiles/corewar2.dir/ft_strsplit_v2.c.o.requires

CMakeFiles/corewar2.dir/ft_strsplit_v2.c.o.provides: CMakeFiles/corewar2.dir/ft_strsplit_v2.c.o.requires
	$(MAKE) -f CMakeFiles/corewar2.dir/build.make CMakeFiles/corewar2.dir/ft_strsplit_v2.c.o.provides.build
.PHONY : CMakeFiles/corewar2.dir/ft_strsplit_v2.c.o.provides

CMakeFiles/corewar2.dir/ft_strsplit_v2.c.o.provides.build: CMakeFiles/corewar2.dir/ft_strsplit_v2.c.o


CMakeFiles/corewar2.dir/ft_command.c.o: CMakeFiles/corewar2.dir/flags.make
CMakeFiles/corewar2.dir/ft_command.c.o: ../ft_command.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/2016/m/maksenov/CLionProjects/corewar2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/corewar2.dir/ft_command.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/corewar2.dir/ft_command.c.o   -c /nfs/2016/m/maksenov/CLionProjects/corewar2/ft_command.c

CMakeFiles/corewar2.dir/ft_command.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/corewar2.dir/ft_command.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /nfs/2016/m/maksenov/CLionProjects/corewar2/ft_command.c > CMakeFiles/corewar2.dir/ft_command.c.i

CMakeFiles/corewar2.dir/ft_command.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/corewar2.dir/ft_command.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /nfs/2016/m/maksenov/CLionProjects/corewar2/ft_command.c -o CMakeFiles/corewar2.dir/ft_command.c.s

CMakeFiles/corewar2.dir/ft_command.c.o.requires:

.PHONY : CMakeFiles/corewar2.dir/ft_command.c.o.requires

CMakeFiles/corewar2.dir/ft_command.c.o.provides: CMakeFiles/corewar2.dir/ft_command.c.o.requires
	$(MAKE) -f CMakeFiles/corewar2.dir/build.make CMakeFiles/corewar2.dir/ft_command.c.o.provides.build
.PHONY : CMakeFiles/corewar2.dir/ft_command.c.o.provides

CMakeFiles/corewar2.dir/ft_command.c.o.provides.build: CMakeFiles/corewar2.dir/ft_command.c.o


CMakeFiles/corewar2.dir/ft_name_comment.c.o: CMakeFiles/corewar2.dir/flags.make
CMakeFiles/corewar2.dir/ft_name_comment.c.o: ../ft_name_comment.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/2016/m/maksenov/CLionProjects/corewar2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/corewar2.dir/ft_name_comment.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/corewar2.dir/ft_name_comment.c.o   -c /nfs/2016/m/maksenov/CLionProjects/corewar2/ft_name_comment.c

CMakeFiles/corewar2.dir/ft_name_comment.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/corewar2.dir/ft_name_comment.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /nfs/2016/m/maksenov/CLionProjects/corewar2/ft_name_comment.c > CMakeFiles/corewar2.dir/ft_name_comment.c.i

CMakeFiles/corewar2.dir/ft_name_comment.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/corewar2.dir/ft_name_comment.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /nfs/2016/m/maksenov/CLionProjects/corewar2/ft_name_comment.c -o CMakeFiles/corewar2.dir/ft_name_comment.c.s

CMakeFiles/corewar2.dir/ft_name_comment.c.o.requires:

.PHONY : CMakeFiles/corewar2.dir/ft_name_comment.c.o.requires

CMakeFiles/corewar2.dir/ft_name_comment.c.o.provides: CMakeFiles/corewar2.dir/ft_name_comment.c.o.requires
	$(MAKE) -f CMakeFiles/corewar2.dir/build.make CMakeFiles/corewar2.dir/ft_name_comment.c.o.provides.build
.PHONY : CMakeFiles/corewar2.dir/ft_name_comment.c.o.provides

CMakeFiles/corewar2.dir/ft_name_comment.c.o.provides.build: CMakeFiles/corewar2.dir/ft_name_comment.c.o


CMakeFiles/corewar2.dir/ft_valid_command.c.o: CMakeFiles/corewar2.dir/flags.make
CMakeFiles/corewar2.dir/ft_valid_command.c.o: ../ft_valid_command.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/2016/m/maksenov/CLionProjects/corewar2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/corewar2.dir/ft_valid_command.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/corewar2.dir/ft_valid_command.c.o   -c /nfs/2016/m/maksenov/CLionProjects/corewar2/ft_valid_command.c

CMakeFiles/corewar2.dir/ft_valid_command.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/corewar2.dir/ft_valid_command.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /nfs/2016/m/maksenov/CLionProjects/corewar2/ft_valid_command.c > CMakeFiles/corewar2.dir/ft_valid_command.c.i

CMakeFiles/corewar2.dir/ft_valid_command.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/corewar2.dir/ft_valid_command.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /nfs/2016/m/maksenov/CLionProjects/corewar2/ft_valid_command.c -o CMakeFiles/corewar2.dir/ft_valid_command.c.s

CMakeFiles/corewar2.dir/ft_valid_command.c.o.requires:

.PHONY : CMakeFiles/corewar2.dir/ft_valid_command.c.o.requires

CMakeFiles/corewar2.dir/ft_valid_command.c.o.provides: CMakeFiles/corewar2.dir/ft_valid_command.c.o.requires
	$(MAKE) -f CMakeFiles/corewar2.dir/build.make CMakeFiles/corewar2.dir/ft_valid_command.c.o.provides.build
.PHONY : CMakeFiles/corewar2.dir/ft_valid_command.c.o.provides

CMakeFiles/corewar2.dir/ft_valid_command.c.o.provides.build: CMakeFiles/corewar2.dir/ft_valid_command.c.o


CMakeFiles/corewar2.dir/get_sizes.c.o: CMakeFiles/corewar2.dir/flags.make
CMakeFiles/corewar2.dir/get_sizes.c.o: ../get_sizes.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/2016/m/maksenov/CLionProjects/corewar2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/corewar2.dir/get_sizes.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/corewar2.dir/get_sizes.c.o   -c /nfs/2016/m/maksenov/CLionProjects/corewar2/get_sizes.c

CMakeFiles/corewar2.dir/get_sizes.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/corewar2.dir/get_sizes.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /nfs/2016/m/maksenov/CLionProjects/corewar2/get_sizes.c > CMakeFiles/corewar2.dir/get_sizes.c.i

CMakeFiles/corewar2.dir/get_sizes.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/corewar2.dir/get_sizes.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /nfs/2016/m/maksenov/CLionProjects/corewar2/get_sizes.c -o CMakeFiles/corewar2.dir/get_sizes.c.s

CMakeFiles/corewar2.dir/get_sizes.c.o.requires:

.PHONY : CMakeFiles/corewar2.dir/get_sizes.c.o.requires

CMakeFiles/corewar2.dir/get_sizes.c.o.provides: CMakeFiles/corewar2.dir/get_sizes.c.o.requires
	$(MAKE) -f CMakeFiles/corewar2.dir/build.make CMakeFiles/corewar2.dir/get_sizes.c.o.provides.build
.PHONY : CMakeFiles/corewar2.dir/get_sizes.c.o.provides

CMakeFiles/corewar2.dir/get_sizes.c.o.provides.build: CMakeFiles/corewar2.dir/get_sizes.c.o


CMakeFiles/corewar2.dir/hash.c.o: CMakeFiles/corewar2.dir/flags.make
CMakeFiles/corewar2.dir/hash.c.o: ../hash.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/2016/m/maksenov/CLionProjects/corewar2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/corewar2.dir/hash.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/corewar2.dir/hash.c.o   -c /nfs/2016/m/maksenov/CLionProjects/corewar2/hash.c

CMakeFiles/corewar2.dir/hash.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/corewar2.dir/hash.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /nfs/2016/m/maksenov/CLionProjects/corewar2/hash.c > CMakeFiles/corewar2.dir/hash.c.i

CMakeFiles/corewar2.dir/hash.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/corewar2.dir/hash.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /nfs/2016/m/maksenov/CLionProjects/corewar2/hash.c -o CMakeFiles/corewar2.dir/hash.c.s

CMakeFiles/corewar2.dir/hash.c.o.requires:

.PHONY : CMakeFiles/corewar2.dir/hash.c.o.requires

CMakeFiles/corewar2.dir/hash.c.o.provides: CMakeFiles/corewar2.dir/hash.c.o.requires
	$(MAKE) -f CMakeFiles/corewar2.dir/build.make CMakeFiles/corewar2.dir/hash.c.o.provides.build
.PHONY : CMakeFiles/corewar2.dir/hash.c.o.provides

CMakeFiles/corewar2.dir/hash.c.o.provides.build: CMakeFiles/corewar2.dir/hash.c.o


CMakeFiles/corewar2.dir/main.c.o: CMakeFiles/corewar2.dir/flags.make
CMakeFiles/corewar2.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/2016/m/maksenov/CLionProjects/corewar2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/corewar2.dir/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/corewar2.dir/main.c.o   -c /nfs/2016/m/maksenov/CLionProjects/corewar2/main.c

CMakeFiles/corewar2.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/corewar2.dir/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /nfs/2016/m/maksenov/CLionProjects/corewar2/main.c > CMakeFiles/corewar2.dir/main.c.i

CMakeFiles/corewar2.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/corewar2.dir/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /nfs/2016/m/maksenov/CLionProjects/corewar2/main.c -o CMakeFiles/corewar2.dir/main.c.s

CMakeFiles/corewar2.dir/main.c.o.requires:

.PHONY : CMakeFiles/corewar2.dir/main.c.o.requires

CMakeFiles/corewar2.dir/main.c.o.provides: CMakeFiles/corewar2.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/corewar2.dir/build.make CMakeFiles/corewar2.dir/main.c.o.provides.build
.PHONY : CMakeFiles/corewar2.dir/main.c.o.provides

CMakeFiles/corewar2.dir/main.c.o.provides.build: CMakeFiles/corewar2.dir/main.c.o


CMakeFiles/corewar2.dir/op.c.o: CMakeFiles/corewar2.dir/flags.make
CMakeFiles/corewar2.dir/op.c.o: ../op.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/2016/m/maksenov/CLionProjects/corewar2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object CMakeFiles/corewar2.dir/op.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/corewar2.dir/op.c.o   -c /nfs/2016/m/maksenov/CLionProjects/corewar2/op.c

CMakeFiles/corewar2.dir/op.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/corewar2.dir/op.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /nfs/2016/m/maksenov/CLionProjects/corewar2/op.c > CMakeFiles/corewar2.dir/op.c.i

CMakeFiles/corewar2.dir/op.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/corewar2.dir/op.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /nfs/2016/m/maksenov/CLionProjects/corewar2/op.c -o CMakeFiles/corewar2.dir/op.c.s

CMakeFiles/corewar2.dir/op.c.o.requires:

.PHONY : CMakeFiles/corewar2.dir/op.c.o.requires

CMakeFiles/corewar2.dir/op.c.o.provides: CMakeFiles/corewar2.dir/op.c.o.requires
	$(MAKE) -f CMakeFiles/corewar2.dir/build.make CMakeFiles/corewar2.dir/op.c.o.provides.build
.PHONY : CMakeFiles/corewar2.dir/op.c.o.provides

CMakeFiles/corewar2.dir/op.c.o.provides.build: CMakeFiles/corewar2.dir/op.c.o


CMakeFiles/corewar2.dir/usage.c.o: CMakeFiles/corewar2.dir/flags.make
CMakeFiles/corewar2.dir/usage.c.o: ../usage.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/2016/m/maksenov/CLionProjects/corewar2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building C object CMakeFiles/corewar2.dir/usage.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/corewar2.dir/usage.c.o   -c /nfs/2016/m/maksenov/CLionProjects/corewar2/usage.c

CMakeFiles/corewar2.dir/usage.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/corewar2.dir/usage.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /nfs/2016/m/maksenov/CLionProjects/corewar2/usage.c > CMakeFiles/corewar2.dir/usage.c.i

CMakeFiles/corewar2.dir/usage.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/corewar2.dir/usage.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /nfs/2016/m/maksenov/CLionProjects/corewar2/usage.c -o CMakeFiles/corewar2.dir/usage.c.s

CMakeFiles/corewar2.dir/usage.c.o.requires:

.PHONY : CMakeFiles/corewar2.dir/usage.c.o.requires

CMakeFiles/corewar2.dir/usage.c.o.provides: CMakeFiles/corewar2.dir/usage.c.o.requires
	$(MAKE) -f CMakeFiles/corewar2.dir/build.make CMakeFiles/corewar2.dir/usage.c.o.provides.build
.PHONY : CMakeFiles/corewar2.dir/usage.c.o.provides

CMakeFiles/corewar2.dir/usage.c.o.provides.build: CMakeFiles/corewar2.dir/usage.c.o


CMakeFiles/corewar2.dir/ft_method.c.o: CMakeFiles/corewar2.dir/flags.make
CMakeFiles/corewar2.dir/ft_method.c.o: ../ft_method.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/2016/m/maksenov/CLionProjects/corewar2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building C object CMakeFiles/corewar2.dir/ft_method.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/corewar2.dir/ft_method.c.o   -c /nfs/2016/m/maksenov/CLionProjects/corewar2/ft_method.c

CMakeFiles/corewar2.dir/ft_method.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/corewar2.dir/ft_method.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /nfs/2016/m/maksenov/CLionProjects/corewar2/ft_method.c > CMakeFiles/corewar2.dir/ft_method.c.i

CMakeFiles/corewar2.dir/ft_method.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/corewar2.dir/ft_method.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /nfs/2016/m/maksenov/CLionProjects/corewar2/ft_method.c -o CMakeFiles/corewar2.dir/ft_method.c.s

CMakeFiles/corewar2.dir/ft_method.c.o.requires:

.PHONY : CMakeFiles/corewar2.dir/ft_method.c.o.requires

CMakeFiles/corewar2.dir/ft_method.c.o.provides: CMakeFiles/corewar2.dir/ft_method.c.o.requires
	$(MAKE) -f CMakeFiles/corewar2.dir/build.make CMakeFiles/corewar2.dir/ft_method.c.o.provides.build
.PHONY : CMakeFiles/corewar2.dir/ft_method.c.o.provides

CMakeFiles/corewar2.dir/ft_method.c.o.provides.build: CMakeFiles/corewar2.dir/ft_method.c.o


CMakeFiles/corewar2.dir/ft_add_command_corewar.c.o: CMakeFiles/corewar2.dir/flags.make
CMakeFiles/corewar2.dir/ft_add_command_corewar.c.o: ../ft_add_command_corewar.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/2016/m/maksenov/CLionProjects/corewar2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building C object CMakeFiles/corewar2.dir/ft_add_command_corewar.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/corewar2.dir/ft_add_command_corewar.c.o   -c /nfs/2016/m/maksenov/CLionProjects/corewar2/ft_add_command_corewar.c

CMakeFiles/corewar2.dir/ft_add_command_corewar.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/corewar2.dir/ft_add_command_corewar.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /nfs/2016/m/maksenov/CLionProjects/corewar2/ft_add_command_corewar.c > CMakeFiles/corewar2.dir/ft_add_command_corewar.c.i

CMakeFiles/corewar2.dir/ft_add_command_corewar.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/corewar2.dir/ft_add_command_corewar.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /nfs/2016/m/maksenov/CLionProjects/corewar2/ft_add_command_corewar.c -o CMakeFiles/corewar2.dir/ft_add_command_corewar.c.s

CMakeFiles/corewar2.dir/ft_add_command_corewar.c.o.requires:

.PHONY : CMakeFiles/corewar2.dir/ft_add_command_corewar.c.o.requires

CMakeFiles/corewar2.dir/ft_add_command_corewar.c.o.provides: CMakeFiles/corewar2.dir/ft_add_command_corewar.c.o.requires
	$(MAKE) -f CMakeFiles/corewar2.dir/build.make CMakeFiles/corewar2.dir/ft_add_command_corewar.c.o.provides.build
.PHONY : CMakeFiles/corewar2.dir/ft_add_command_corewar.c.o.provides

CMakeFiles/corewar2.dir/ft_add_command_corewar.c.o.provides.build: CMakeFiles/corewar2.dir/ft_add_command_corewar.c.o


CMakeFiles/corewar2.dir/ft_valid_all.c.o: CMakeFiles/corewar2.dir/flags.make
CMakeFiles/corewar2.dir/ft_valid_all.c.o: ../ft_valid_all.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/2016/m/maksenov/CLionProjects/corewar2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building C object CMakeFiles/corewar2.dir/ft_valid_all.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/corewar2.dir/ft_valid_all.c.o   -c /nfs/2016/m/maksenov/CLionProjects/corewar2/ft_valid_all.c

CMakeFiles/corewar2.dir/ft_valid_all.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/corewar2.dir/ft_valid_all.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /nfs/2016/m/maksenov/CLionProjects/corewar2/ft_valid_all.c > CMakeFiles/corewar2.dir/ft_valid_all.c.i

CMakeFiles/corewar2.dir/ft_valid_all.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/corewar2.dir/ft_valid_all.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /nfs/2016/m/maksenov/CLionProjects/corewar2/ft_valid_all.c -o CMakeFiles/corewar2.dir/ft_valid_all.c.s

CMakeFiles/corewar2.dir/ft_valid_all.c.o.requires:

.PHONY : CMakeFiles/corewar2.dir/ft_valid_all.c.o.requires

CMakeFiles/corewar2.dir/ft_valid_all.c.o.provides: CMakeFiles/corewar2.dir/ft_valid_all.c.o.requires
	$(MAKE) -f CMakeFiles/corewar2.dir/build.make CMakeFiles/corewar2.dir/ft_valid_all.c.o.provides.build
.PHONY : CMakeFiles/corewar2.dir/ft_valid_all.c.o.provides

CMakeFiles/corewar2.dir/ft_valid_all.c.o.provides.build: CMakeFiles/corewar2.dir/ft_valid_all.c.o


# Object files for target corewar2
corewar2_OBJECTS = \
"CMakeFiles/corewar2.dir/asm_to_binary.c.o" \
"CMakeFiles/corewar2.dir/sub.c.o" \
"CMakeFiles/corewar2.dir/ft_strsplit_v2.c.o" \
"CMakeFiles/corewar2.dir/ft_command.c.o" \
"CMakeFiles/corewar2.dir/ft_name_comment.c.o" \
"CMakeFiles/corewar2.dir/ft_valid_command.c.o" \
"CMakeFiles/corewar2.dir/get_sizes.c.o" \
"CMakeFiles/corewar2.dir/hash.c.o" \
"CMakeFiles/corewar2.dir/main.c.o" \
"CMakeFiles/corewar2.dir/op.c.o" \
"CMakeFiles/corewar2.dir/usage.c.o" \
"CMakeFiles/corewar2.dir/ft_method.c.o" \
"CMakeFiles/corewar2.dir/ft_add_command_corewar.c.o" \
"CMakeFiles/corewar2.dir/ft_valid_all.c.o"

# External object files for target corewar2
corewar2_EXTERNAL_OBJECTS =

corewar2: CMakeFiles/corewar2.dir/asm_to_binary.c.o
corewar2: CMakeFiles/corewar2.dir/sub.c.o
corewar2: CMakeFiles/corewar2.dir/ft_strsplit_v2.c.o
corewar2: CMakeFiles/corewar2.dir/ft_command.c.o
corewar2: CMakeFiles/corewar2.dir/ft_name_comment.c.o
corewar2: CMakeFiles/corewar2.dir/ft_valid_command.c.o
corewar2: CMakeFiles/corewar2.dir/get_sizes.c.o
corewar2: CMakeFiles/corewar2.dir/hash.c.o
corewar2: CMakeFiles/corewar2.dir/main.c.o
corewar2: CMakeFiles/corewar2.dir/op.c.o
corewar2: CMakeFiles/corewar2.dir/usage.c.o
corewar2: CMakeFiles/corewar2.dir/ft_method.c.o
corewar2: CMakeFiles/corewar2.dir/ft_add_command_corewar.c.o
corewar2: CMakeFiles/corewar2.dir/ft_valid_all.c.o
corewar2: CMakeFiles/corewar2.dir/build.make
corewar2: ../libft/libft.a
corewar2: CMakeFiles/corewar2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/nfs/2016/m/maksenov/CLionProjects/corewar2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Linking C executable corewar2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/corewar2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/corewar2.dir/build: corewar2

.PHONY : CMakeFiles/corewar2.dir/build

CMakeFiles/corewar2.dir/requires: CMakeFiles/corewar2.dir/asm_to_binary.c.o.requires
CMakeFiles/corewar2.dir/requires: CMakeFiles/corewar2.dir/sub.c.o.requires
CMakeFiles/corewar2.dir/requires: CMakeFiles/corewar2.dir/ft_strsplit_v2.c.o.requires
CMakeFiles/corewar2.dir/requires: CMakeFiles/corewar2.dir/ft_command.c.o.requires
CMakeFiles/corewar2.dir/requires: CMakeFiles/corewar2.dir/ft_name_comment.c.o.requires
CMakeFiles/corewar2.dir/requires: CMakeFiles/corewar2.dir/ft_valid_command.c.o.requires
CMakeFiles/corewar2.dir/requires: CMakeFiles/corewar2.dir/get_sizes.c.o.requires
CMakeFiles/corewar2.dir/requires: CMakeFiles/corewar2.dir/hash.c.o.requires
CMakeFiles/corewar2.dir/requires: CMakeFiles/corewar2.dir/main.c.o.requires
CMakeFiles/corewar2.dir/requires: CMakeFiles/corewar2.dir/op.c.o.requires
CMakeFiles/corewar2.dir/requires: CMakeFiles/corewar2.dir/usage.c.o.requires
CMakeFiles/corewar2.dir/requires: CMakeFiles/corewar2.dir/ft_method.c.o.requires
CMakeFiles/corewar2.dir/requires: CMakeFiles/corewar2.dir/ft_add_command_corewar.c.o.requires
CMakeFiles/corewar2.dir/requires: CMakeFiles/corewar2.dir/ft_valid_all.c.o.requires

.PHONY : CMakeFiles/corewar2.dir/requires

CMakeFiles/corewar2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/corewar2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/corewar2.dir/clean

CMakeFiles/corewar2.dir/depend:
	cd /nfs/2016/m/maksenov/CLionProjects/corewar2/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /nfs/2016/m/maksenov/CLionProjects/corewar2 /nfs/2016/m/maksenov/CLionProjects/corewar2 /nfs/2016/m/maksenov/CLionProjects/corewar2/cmake-build-debug /nfs/2016/m/maksenov/CLionProjects/corewar2/cmake-build-debug /nfs/2016/m/maksenov/CLionProjects/corewar2/cmake-build-debug/CMakeFiles/corewar2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/corewar2.dir/depend


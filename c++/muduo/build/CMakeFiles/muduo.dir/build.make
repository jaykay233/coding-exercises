# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.23

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.23.2/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.23.2/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/zhiyuan.xu/Downloads/项目/coding-exercises/c++/muduo

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/zhiyuan.xu/Downloads/项目/coding-exercises/c++/muduo/build

# Include any dependencies generated for this target.
include CMakeFiles/muduo.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/muduo.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/muduo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/muduo.dir/flags.make

CMakeFiles/muduo.dir/Channel.o: CMakeFiles/muduo.dir/flags.make
CMakeFiles/muduo.dir/Channel.o: ../Channel.cc
CMakeFiles/muduo.dir/Channel.o: CMakeFiles/muduo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zhiyuan.xu/Downloads/项目/coding-exercises/c++/muduo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/muduo.dir/Channel.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/muduo.dir/Channel.o -MF CMakeFiles/muduo.dir/Channel.o.d -o CMakeFiles/muduo.dir/Channel.o -c /Users/zhiyuan.xu/Downloads/项目/coding-exercises/c++/muduo/Channel.cc

CMakeFiles/muduo.dir/Channel.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/muduo.dir/Channel.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zhiyuan.xu/Downloads/项目/coding-exercises/c++/muduo/Channel.cc > CMakeFiles/muduo.dir/Channel.i

CMakeFiles/muduo.dir/Channel.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/muduo.dir/Channel.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zhiyuan.xu/Downloads/项目/coding-exercises/c++/muduo/Channel.cc -o CMakeFiles/muduo.dir/Channel.s

CMakeFiles/muduo.dir/EventLoop.o: CMakeFiles/muduo.dir/flags.make
CMakeFiles/muduo.dir/EventLoop.o: ../EventLoop.cc
CMakeFiles/muduo.dir/EventLoop.o: CMakeFiles/muduo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zhiyuan.xu/Downloads/项目/coding-exercises/c++/muduo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/muduo.dir/EventLoop.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/muduo.dir/EventLoop.o -MF CMakeFiles/muduo.dir/EventLoop.o.d -o CMakeFiles/muduo.dir/EventLoop.o -c /Users/zhiyuan.xu/Downloads/项目/coding-exercises/c++/muduo/EventLoop.cc

CMakeFiles/muduo.dir/EventLoop.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/muduo.dir/EventLoop.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zhiyuan.xu/Downloads/项目/coding-exercises/c++/muduo/EventLoop.cc > CMakeFiles/muduo.dir/EventLoop.i

CMakeFiles/muduo.dir/EventLoop.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/muduo.dir/EventLoop.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zhiyuan.xu/Downloads/项目/coding-exercises/c++/muduo/EventLoop.cc -o CMakeFiles/muduo.dir/EventLoop.s

CMakeFiles/muduo.dir/InetAddress.o: CMakeFiles/muduo.dir/flags.make
CMakeFiles/muduo.dir/InetAddress.o: ../InetAddress.cc
CMakeFiles/muduo.dir/InetAddress.o: CMakeFiles/muduo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zhiyuan.xu/Downloads/项目/coding-exercises/c++/muduo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/muduo.dir/InetAddress.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/muduo.dir/InetAddress.o -MF CMakeFiles/muduo.dir/InetAddress.o.d -o CMakeFiles/muduo.dir/InetAddress.o -c /Users/zhiyuan.xu/Downloads/项目/coding-exercises/c++/muduo/InetAddress.cc

CMakeFiles/muduo.dir/InetAddress.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/muduo.dir/InetAddress.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zhiyuan.xu/Downloads/项目/coding-exercises/c++/muduo/InetAddress.cc > CMakeFiles/muduo.dir/InetAddress.i

CMakeFiles/muduo.dir/InetAddress.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/muduo.dir/InetAddress.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zhiyuan.xu/Downloads/项目/coding-exercises/c++/muduo/InetAddress.cc -o CMakeFiles/muduo.dir/InetAddress.s

CMakeFiles/muduo.dir/Logger.o: CMakeFiles/muduo.dir/flags.make
CMakeFiles/muduo.dir/Logger.o: ../Logger.cc
CMakeFiles/muduo.dir/Logger.o: CMakeFiles/muduo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zhiyuan.xu/Downloads/项目/coding-exercises/c++/muduo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/muduo.dir/Logger.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/muduo.dir/Logger.o -MF CMakeFiles/muduo.dir/Logger.o.d -o CMakeFiles/muduo.dir/Logger.o -c /Users/zhiyuan.xu/Downloads/项目/coding-exercises/c++/muduo/Logger.cc

CMakeFiles/muduo.dir/Logger.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/muduo.dir/Logger.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zhiyuan.xu/Downloads/项目/coding-exercises/c++/muduo/Logger.cc > CMakeFiles/muduo.dir/Logger.i

CMakeFiles/muduo.dir/Logger.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/muduo.dir/Logger.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zhiyuan.xu/Downloads/项目/coding-exercises/c++/muduo/Logger.cc -o CMakeFiles/muduo.dir/Logger.s

CMakeFiles/muduo.dir/TcpServer.o: CMakeFiles/muduo.dir/flags.make
CMakeFiles/muduo.dir/TcpServer.o: ../TcpServer.cc
CMakeFiles/muduo.dir/TcpServer.o: CMakeFiles/muduo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zhiyuan.xu/Downloads/项目/coding-exercises/c++/muduo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/muduo.dir/TcpServer.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/muduo.dir/TcpServer.o -MF CMakeFiles/muduo.dir/TcpServer.o.d -o CMakeFiles/muduo.dir/TcpServer.o -c /Users/zhiyuan.xu/Downloads/项目/coding-exercises/c++/muduo/TcpServer.cc

CMakeFiles/muduo.dir/TcpServer.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/muduo.dir/TcpServer.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zhiyuan.xu/Downloads/项目/coding-exercises/c++/muduo/TcpServer.cc > CMakeFiles/muduo.dir/TcpServer.i

CMakeFiles/muduo.dir/TcpServer.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/muduo.dir/TcpServer.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zhiyuan.xu/Downloads/项目/coding-exercises/c++/muduo/TcpServer.cc -o CMakeFiles/muduo.dir/TcpServer.s

CMakeFiles/muduo.dir/Timestamp.o: CMakeFiles/muduo.dir/flags.make
CMakeFiles/muduo.dir/Timestamp.o: ../Timestamp.cc
CMakeFiles/muduo.dir/Timestamp.o: CMakeFiles/muduo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zhiyuan.xu/Downloads/项目/coding-exercises/c++/muduo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/muduo.dir/Timestamp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/muduo.dir/Timestamp.o -MF CMakeFiles/muduo.dir/Timestamp.o.d -o CMakeFiles/muduo.dir/Timestamp.o -c /Users/zhiyuan.xu/Downloads/项目/coding-exercises/c++/muduo/Timestamp.cc

CMakeFiles/muduo.dir/Timestamp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/muduo.dir/Timestamp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zhiyuan.xu/Downloads/项目/coding-exercises/c++/muduo/Timestamp.cc > CMakeFiles/muduo.dir/Timestamp.i

CMakeFiles/muduo.dir/Timestamp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/muduo.dir/Timestamp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zhiyuan.xu/Downloads/项目/coding-exercises/c++/muduo/Timestamp.cc -o CMakeFiles/muduo.dir/Timestamp.s

# Object files for target muduo
muduo_OBJECTS = \
"CMakeFiles/muduo.dir/Channel.o" \
"CMakeFiles/muduo.dir/EventLoop.o" \
"CMakeFiles/muduo.dir/InetAddress.o" \
"CMakeFiles/muduo.dir/Logger.o" \
"CMakeFiles/muduo.dir/TcpServer.o" \
"CMakeFiles/muduo.dir/Timestamp.o"

# External object files for target muduo
muduo_EXTERNAL_OBJECTS =

../lib/libmuduo.dylib: CMakeFiles/muduo.dir/Channel.o
../lib/libmuduo.dylib: CMakeFiles/muduo.dir/EventLoop.o
../lib/libmuduo.dylib: CMakeFiles/muduo.dir/InetAddress.o
../lib/libmuduo.dylib: CMakeFiles/muduo.dir/Logger.o
../lib/libmuduo.dylib: CMakeFiles/muduo.dir/TcpServer.o
../lib/libmuduo.dylib: CMakeFiles/muduo.dir/Timestamp.o
../lib/libmuduo.dylib: CMakeFiles/muduo.dir/build.make
../lib/libmuduo.dylib: CMakeFiles/muduo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/zhiyuan.xu/Downloads/项目/coding-exercises/c++/muduo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX shared library ../lib/libmuduo.dylib"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/muduo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/muduo.dir/build: ../lib/libmuduo.dylib
.PHONY : CMakeFiles/muduo.dir/build

CMakeFiles/muduo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/muduo.dir/cmake_clean.cmake
.PHONY : CMakeFiles/muduo.dir/clean

CMakeFiles/muduo.dir/depend:
	cd /Users/zhiyuan.xu/Downloads/项目/coding-exercises/c++/muduo/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/zhiyuan.xu/Downloads/项目/coding-exercises/c++/muduo /Users/zhiyuan.xu/Downloads/项目/coding-exercises/c++/muduo /Users/zhiyuan.xu/Downloads/项目/coding-exercises/c++/muduo/build /Users/zhiyuan.xu/Downloads/项目/coding-exercises/c++/muduo/build /Users/zhiyuan.xu/Downloads/项目/coding-exercises/c++/muduo/build/CMakeFiles/muduo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/muduo.dir/depend


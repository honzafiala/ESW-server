# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /home/honza/ESW/server

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/honza/ESW/server

# Include any dependencies generated for this target.
include CMakeFiles/epoll_server.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/epoll_server.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/epoll_server.dir/flags.make

CMakeFiles/epoll_server.dir/epollconn.cpp.o: CMakeFiles/epoll_server.dir/flags.make
CMakeFiles/epoll_server.dir/epollconn.cpp.o: epollconn.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/honza/ESW/server/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/epoll_server.dir/epollconn.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/epoll_server.dir/epollconn.cpp.o -c /home/honza/ESW/server/epollconn.cpp

CMakeFiles/epoll_server.dir/epollconn.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/epoll_server.dir/epollconn.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/honza/ESW/server/epollconn.cpp > CMakeFiles/epoll_server.dir/epollconn.cpp.i

CMakeFiles/epoll_server.dir/epollconn.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/epoll_server.dir/epollconn.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/honza/ESW/server/epollconn.cpp -o CMakeFiles/epoll_server.dir/epollconn.cpp.s

CMakeFiles/epoll_server.dir/epollfd.cpp.o: CMakeFiles/epoll_server.dir/flags.make
CMakeFiles/epoll_server.dir/epollfd.cpp.o: epollfd.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/honza/ESW/server/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/epoll_server.dir/epollfd.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/epoll_server.dir/epollfd.cpp.o -c /home/honza/ESW/server/epollfd.cpp

CMakeFiles/epoll_server.dir/epollfd.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/epoll_server.dir/epollfd.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/honza/ESW/server/epollfd.cpp > CMakeFiles/epoll_server.dir/epollfd.cpp.i

CMakeFiles/epoll_server.dir/epollfd.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/epoll_server.dir/epollfd.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/honza/ESW/server/epollfd.cpp -o CMakeFiles/epoll_server.dir/epollfd.cpp.s

CMakeFiles/epoll_server.dir/epollinstance.cpp.o: CMakeFiles/epoll_server.dir/flags.make
CMakeFiles/epoll_server.dir/epollinstance.cpp.o: epollinstance.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/honza/ESW/server/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/epoll_server.dir/epollinstance.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/epoll_server.dir/epollinstance.cpp.o -c /home/honza/ESW/server/epollinstance.cpp

CMakeFiles/epoll_server.dir/epollinstance.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/epoll_server.dir/epollinstance.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/honza/ESW/server/epollinstance.cpp > CMakeFiles/epoll_server.dir/epollinstance.cpp.i

CMakeFiles/epoll_server.dir/epollinstance.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/epoll_server.dir/epollinstance.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/honza/ESW/server/epollinstance.cpp -o CMakeFiles/epoll_server.dir/epollinstance.cpp.s

CMakeFiles/epoll_server.dir/epollsocket.cpp.o: CMakeFiles/epoll_server.dir/flags.make
CMakeFiles/epoll_server.dir/epollsocket.cpp.o: epollsocket.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/honza/ESW/server/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/epoll_server.dir/epollsocket.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/epoll_server.dir/epollsocket.cpp.o -c /home/honza/ESW/server/epollsocket.cpp

CMakeFiles/epoll_server.dir/epollsocket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/epoll_server.dir/epollsocket.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/honza/ESW/server/epollsocket.cpp > CMakeFiles/epoll_server.dir/epollsocket.cpp.i

CMakeFiles/epoll_server.dir/epollsocket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/epoll_server.dir/epollsocket.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/honza/ESW/server/epollsocket.cpp -o CMakeFiles/epoll_server.dir/epollsocket.cpp.s

CMakeFiles/epoll_server.dir/main.cpp.o: CMakeFiles/epoll_server.dir/flags.make
CMakeFiles/epoll_server.dir/main.cpp.o: main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/honza/ESW/server/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/epoll_server.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/epoll_server.dir/main.cpp.o -c /home/honza/ESW/server/main.cpp

CMakeFiles/epoll_server.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/epoll_server.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/honza/ESW/server/main.cpp > CMakeFiles/epoll_server.dir/main.cpp.i

CMakeFiles/epoll_server.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/epoll_server.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/honza/ESW/server/main.cpp -o CMakeFiles/epoll_server.dir/main.cpp.s

# Object files for target epoll_server
epoll_server_OBJECTS = \
"CMakeFiles/epoll_server.dir/epollconn.cpp.o" \
"CMakeFiles/epoll_server.dir/epollfd.cpp.o" \
"CMakeFiles/epoll_server.dir/epollinstance.cpp.o" \
"CMakeFiles/epoll_server.dir/epollsocket.cpp.o" \
"CMakeFiles/epoll_server.dir/main.cpp.o"

# External object files for target epoll_server
epoll_server_EXTERNAL_OBJECTS =

epoll_server: CMakeFiles/epoll_server.dir/epollconn.cpp.o
epoll_server: CMakeFiles/epoll_server.dir/epollfd.cpp.o
epoll_server: CMakeFiles/epoll_server.dir/epollinstance.cpp.o
epoll_server: CMakeFiles/epoll_server.dir/epollsocket.cpp.o
epoll_server: CMakeFiles/epoll_server.dir/main.cpp.o
epoll_server: CMakeFiles/epoll_server.dir/build.make
epoll_server: CMakeFiles/epoll_server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/honza/ESW/server/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable epoll_server"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/epoll_server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/epoll_server.dir/build: epoll_server

.PHONY : CMakeFiles/epoll_server.dir/build

CMakeFiles/epoll_server.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/epoll_server.dir/cmake_clean.cmake
.PHONY : CMakeFiles/epoll_server.dir/clean

CMakeFiles/epoll_server.dir/depend:
	cd /home/honza/ESW/server && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/honza/ESW/server /home/honza/ESW/server /home/honza/ESW/server /home/honza/ESW/server /home/honza/ESW/server/CMakeFiles/epoll_server.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/epoll_server.dir/depend


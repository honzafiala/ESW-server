# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/bin/cmake-gui -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/honza/ESW/server/CMakeFiles /home/honza/ESW/server/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/honza/ESW/server/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named epoll_server

# Build rule for target.
epoll_server: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 epoll_server
.PHONY : epoll_server

# fast build rule for target.
epoll_server/fast:
	$(MAKE) -f CMakeFiles/epoll_server.dir/build.make CMakeFiles/epoll_server.dir/build
.PHONY : epoll_server/fast

epollconn.o: epollconn.cpp.o

.PHONY : epollconn.o

# target to build an object file
epollconn.cpp.o:
	$(MAKE) -f CMakeFiles/epoll_server.dir/build.make CMakeFiles/epoll_server.dir/epollconn.cpp.o
.PHONY : epollconn.cpp.o

epollconn.i: epollconn.cpp.i

.PHONY : epollconn.i

# target to preprocess a source file
epollconn.cpp.i:
	$(MAKE) -f CMakeFiles/epoll_server.dir/build.make CMakeFiles/epoll_server.dir/epollconn.cpp.i
.PHONY : epollconn.cpp.i

epollconn.s: epollconn.cpp.s

.PHONY : epollconn.s

# target to generate assembly for a file
epollconn.cpp.s:
	$(MAKE) -f CMakeFiles/epoll_server.dir/build.make CMakeFiles/epoll_server.dir/epollconn.cpp.s
.PHONY : epollconn.cpp.s

epollfd.o: epollfd.cpp.o

.PHONY : epollfd.o

# target to build an object file
epollfd.cpp.o:
	$(MAKE) -f CMakeFiles/epoll_server.dir/build.make CMakeFiles/epoll_server.dir/epollfd.cpp.o
.PHONY : epollfd.cpp.o

epollfd.i: epollfd.cpp.i

.PHONY : epollfd.i

# target to preprocess a source file
epollfd.cpp.i:
	$(MAKE) -f CMakeFiles/epoll_server.dir/build.make CMakeFiles/epoll_server.dir/epollfd.cpp.i
.PHONY : epollfd.cpp.i

epollfd.s: epollfd.cpp.s

.PHONY : epollfd.s

# target to generate assembly for a file
epollfd.cpp.s:
	$(MAKE) -f CMakeFiles/epoll_server.dir/build.make CMakeFiles/epoll_server.dir/epollfd.cpp.s
.PHONY : epollfd.cpp.s

epollinstance.o: epollinstance.cpp.o

.PHONY : epollinstance.o

# target to build an object file
epollinstance.cpp.o:
	$(MAKE) -f CMakeFiles/epoll_server.dir/build.make CMakeFiles/epoll_server.dir/epollinstance.cpp.o
.PHONY : epollinstance.cpp.o

epollinstance.i: epollinstance.cpp.i

.PHONY : epollinstance.i

# target to preprocess a source file
epollinstance.cpp.i:
	$(MAKE) -f CMakeFiles/epoll_server.dir/build.make CMakeFiles/epoll_server.dir/epollinstance.cpp.i
.PHONY : epollinstance.cpp.i

epollinstance.s: epollinstance.cpp.s

.PHONY : epollinstance.s

# target to generate assembly for a file
epollinstance.cpp.s:
	$(MAKE) -f CMakeFiles/epoll_server.dir/build.make CMakeFiles/epoll_server.dir/epollinstance.cpp.s
.PHONY : epollinstance.cpp.s

epollsocket.o: epollsocket.cpp.o

.PHONY : epollsocket.o

# target to build an object file
epollsocket.cpp.o:
	$(MAKE) -f CMakeFiles/epoll_server.dir/build.make CMakeFiles/epoll_server.dir/epollsocket.cpp.o
.PHONY : epollsocket.cpp.o

epollsocket.i: epollsocket.cpp.i

.PHONY : epollsocket.i

# target to preprocess a source file
epollsocket.cpp.i:
	$(MAKE) -f CMakeFiles/epoll_server.dir/build.make CMakeFiles/epoll_server.dir/epollsocket.cpp.i
.PHONY : epollsocket.cpp.i

epollsocket.s: epollsocket.cpp.s

.PHONY : epollsocket.s

# target to generate assembly for a file
epollsocket.cpp.s:
	$(MAKE) -f CMakeFiles/epoll_server.dir/build.make CMakeFiles/epoll_server.dir/epollsocket.cpp.s
.PHONY : epollsocket.cpp.s

main.o: main.cpp.o

.PHONY : main.o

# target to build an object file
main.cpp.o:
	$(MAKE) -f CMakeFiles/epoll_server.dir/build.make CMakeFiles/epoll_server.dir/main.cpp.o
.PHONY : main.cpp.o

main.i: main.cpp.i

.PHONY : main.i

# target to preprocess a source file
main.cpp.i:
	$(MAKE) -f CMakeFiles/epoll_server.dir/build.make CMakeFiles/epoll_server.dir/main.cpp.i
.PHONY : main.cpp.i

main.s: main.cpp.s

.PHONY : main.s

# target to generate assembly for a file
main.cpp.s:
	$(MAKE) -f CMakeFiles/epoll_server.dir/build.make CMakeFiles/epoll_server.dir/main.cpp.s
.PHONY : main.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... edit_cache"
	@echo "... epoll_server"
	@echo "... epollconn.o"
	@echo "... epollconn.i"
	@echo "... epollconn.s"
	@echo "... epollfd.o"
	@echo "... epollfd.i"
	@echo "... epollfd.s"
	@echo "... epollinstance.o"
	@echo "... epollinstance.i"
	@echo "... epollinstance.s"
	@echo "... epollsocket.o"
	@echo "... epollsocket.i"
	@echo "... epollsocket.s"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system


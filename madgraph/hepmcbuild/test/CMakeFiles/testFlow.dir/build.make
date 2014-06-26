# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.6

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canoncical targets will work.
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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/local1/project/Dark-Photons/madgraph/hepmc

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/local1/project/Dark-Photons/madgraph/hepmcbuild

# Include any dependencies generated for this target.
include test/CMakeFiles/testFlow.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/testFlow.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/testFlow.dir/flags.make

test/CMakeFiles/testFlow.dir/testFlow.cc.o: test/CMakeFiles/testFlow.dir/flags.make
test/CMakeFiles/testFlow.dir/testFlow.cc.o: /home/local1/project/Dark-Photons/madgraph/hepmc/test/testFlow.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /home/local1/project/Dark-Photons/madgraph/hepmcbuild/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object test/CMakeFiles/testFlow.dir/testFlow.cc.o"
	cd /home/local1/project/Dark-Photons/madgraph/hepmcbuild/test && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/testFlow.dir/testFlow.cc.o -c /home/local1/project/Dark-Photons/madgraph/hepmc/test/testFlow.cc

test/CMakeFiles/testFlow.dir/testFlow.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testFlow.dir/testFlow.cc.i"
	cd /home/local1/project/Dark-Photons/madgraph/hepmcbuild/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/local1/project/Dark-Photons/madgraph/hepmc/test/testFlow.cc > CMakeFiles/testFlow.dir/testFlow.cc.i

test/CMakeFiles/testFlow.dir/testFlow.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testFlow.dir/testFlow.cc.s"
	cd /home/local1/project/Dark-Photons/madgraph/hepmcbuild/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/local1/project/Dark-Photons/madgraph/hepmc/test/testFlow.cc -o CMakeFiles/testFlow.dir/testFlow.cc.s

test/CMakeFiles/testFlow.dir/testFlow.cc.o.requires:
.PHONY : test/CMakeFiles/testFlow.dir/testFlow.cc.o.requires

test/CMakeFiles/testFlow.dir/testFlow.cc.o.provides: test/CMakeFiles/testFlow.dir/testFlow.cc.o.requires
	$(MAKE) -f test/CMakeFiles/testFlow.dir/build.make test/CMakeFiles/testFlow.dir/testFlow.cc.o.provides.build
.PHONY : test/CMakeFiles/testFlow.dir/testFlow.cc.o.provides

test/CMakeFiles/testFlow.dir/testFlow.cc.o.provides.build: test/CMakeFiles/testFlow.dir/testFlow.cc.o
.PHONY : test/CMakeFiles/testFlow.dir/testFlow.cc.o.provides.build

# Object files for target testFlow
testFlow_OBJECTS = \
"CMakeFiles/testFlow.dir/testFlow.cc.o"

# External object files for target testFlow
testFlow_EXTERNAL_OBJECTS =

test/testFlow: test/CMakeFiles/testFlow.dir/testFlow.cc.o
test/testFlow: lib/libHepMC.so.4.0.0
test/testFlow: test/CMakeFiles/testFlow.dir/build.make
test/testFlow: test/CMakeFiles/testFlow.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable testFlow"
	cd /home/local1/project/Dark-Photons/madgraph/hepmcbuild/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/testFlow.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/testFlow.dir/build: test/testFlow
.PHONY : test/CMakeFiles/testFlow.dir/build

test/CMakeFiles/testFlow.dir/requires: test/CMakeFiles/testFlow.dir/testFlow.cc.o.requires
.PHONY : test/CMakeFiles/testFlow.dir/requires

test/CMakeFiles/testFlow.dir/clean:
	cd /home/local1/project/Dark-Photons/madgraph/hepmcbuild/test && $(CMAKE_COMMAND) -P CMakeFiles/testFlow.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/testFlow.dir/clean

test/CMakeFiles/testFlow.dir/depend:
	cd /home/local1/project/Dark-Photons/madgraph/hepmcbuild && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/local1/project/Dark-Photons/madgraph/hepmc /home/local1/project/Dark-Photons/madgraph/hepmc/test /home/local1/project/Dark-Photons/madgraph/hepmcbuild /home/local1/project/Dark-Photons/madgraph/hepmcbuild/test /home/local1/project/Dark-Photons/madgraph/hepmcbuild/test/CMakeFiles/testFlow.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/testFlow.dir/depend


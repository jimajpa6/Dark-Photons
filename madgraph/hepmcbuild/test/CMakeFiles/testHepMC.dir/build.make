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
include test/CMakeFiles/testHepMC.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/testHepMC.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/testHepMC.dir/flags.make

test/CMakeFiles/testHepMC.dir/testHepMC.cc.o: test/CMakeFiles/testHepMC.dir/flags.make
test/CMakeFiles/testHepMC.dir/testHepMC.cc.o: test/testHepMC.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /home/local1/project/Dark-Photons/madgraph/hepmcbuild/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object test/CMakeFiles/testHepMC.dir/testHepMC.cc.o"
	cd /home/local1/project/Dark-Photons/madgraph/hepmcbuild/test && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/testHepMC.dir/testHepMC.cc.o -c /home/local1/project/Dark-Photons/madgraph/hepmcbuild/test/testHepMC.cc

test/CMakeFiles/testHepMC.dir/testHepMC.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testHepMC.dir/testHepMC.cc.i"
	cd /home/local1/project/Dark-Photons/madgraph/hepmcbuild/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/local1/project/Dark-Photons/madgraph/hepmcbuild/test/testHepMC.cc > CMakeFiles/testHepMC.dir/testHepMC.cc.i

test/CMakeFiles/testHepMC.dir/testHepMC.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testHepMC.dir/testHepMC.cc.s"
	cd /home/local1/project/Dark-Photons/madgraph/hepmcbuild/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/local1/project/Dark-Photons/madgraph/hepmcbuild/test/testHepMC.cc -o CMakeFiles/testHepMC.dir/testHepMC.cc.s

test/CMakeFiles/testHepMC.dir/testHepMC.cc.o.requires:
.PHONY : test/CMakeFiles/testHepMC.dir/testHepMC.cc.o.requires

test/CMakeFiles/testHepMC.dir/testHepMC.cc.o.provides: test/CMakeFiles/testHepMC.dir/testHepMC.cc.o.requires
	$(MAKE) -f test/CMakeFiles/testHepMC.dir/build.make test/CMakeFiles/testHepMC.dir/testHepMC.cc.o.provides.build
.PHONY : test/CMakeFiles/testHepMC.dir/testHepMC.cc.o.provides

test/CMakeFiles/testHepMC.dir/testHepMC.cc.o.provides.build: test/CMakeFiles/testHepMC.dir/testHepMC.cc.o
.PHONY : test/CMakeFiles/testHepMC.dir/testHepMC.cc.o.provides.build

test/CMakeFiles/testHepMC.dir/testHepMCMethods.cc.o: test/CMakeFiles/testHepMC.dir/flags.make
test/CMakeFiles/testHepMC.dir/testHepMCMethods.cc.o: /home/local1/project/Dark-Photons/madgraph/hepmc/test/testHepMCMethods.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /home/local1/project/Dark-Photons/madgraph/hepmcbuild/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object test/CMakeFiles/testHepMC.dir/testHepMCMethods.cc.o"
	cd /home/local1/project/Dark-Photons/madgraph/hepmcbuild/test && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/testHepMC.dir/testHepMCMethods.cc.o -c /home/local1/project/Dark-Photons/madgraph/hepmc/test/testHepMCMethods.cc

test/CMakeFiles/testHepMC.dir/testHepMCMethods.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testHepMC.dir/testHepMCMethods.cc.i"
	cd /home/local1/project/Dark-Photons/madgraph/hepmcbuild/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/local1/project/Dark-Photons/madgraph/hepmc/test/testHepMCMethods.cc > CMakeFiles/testHepMC.dir/testHepMCMethods.cc.i

test/CMakeFiles/testHepMC.dir/testHepMCMethods.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testHepMC.dir/testHepMCMethods.cc.s"
	cd /home/local1/project/Dark-Photons/madgraph/hepmcbuild/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/local1/project/Dark-Photons/madgraph/hepmc/test/testHepMCMethods.cc -o CMakeFiles/testHepMC.dir/testHepMCMethods.cc.s

test/CMakeFiles/testHepMC.dir/testHepMCMethods.cc.o.requires:
.PHONY : test/CMakeFiles/testHepMC.dir/testHepMCMethods.cc.o.requires

test/CMakeFiles/testHepMC.dir/testHepMCMethods.cc.o.provides: test/CMakeFiles/testHepMC.dir/testHepMCMethods.cc.o.requires
	$(MAKE) -f test/CMakeFiles/testHepMC.dir/build.make test/CMakeFiles/testHepMC.dir/testHepMCMethods.cc.o.provides.build
.PHONY : test/CMakeFiles/testHepMC.dir/testHepMCMethods.cc.o.provides

test/CMakeFiles/testHepMC.dir/testHepMCMethods.cc.o.provides.build: test/CMakeFiles/testHepMC.dir/testHepMCMethods.cc.o
.PHONY : test/CMakeFiles/testHepMC.dir/testHepMCMethods.cc.o.provides.build

# Object files for target testHepMC
testHepMC_OBJECTS = \
"CMakeFiles/testHepMC.dir/testHepMC.cc.o" \
"CMakeFiles/testHepMC.dir/testHepMCMethods.cc.o"

# External object files for target testHepMC
testHepMC_EXTERNAL_OBJECTS =

test/testHepMC: test/CMakeFiles/testHepMC.dir/testHepMC.cc.o
test/testHepMC: test/CMakeFiles/testHepMC.dir/testHepMCMethods.cc.o
test/testHepMC: lib/libHepMC.so.4.0.0
test/testHepMC: test/CMakeFiles/testHepMC.dir/build.make
test/testHepMC: test/CMakeFiles/testHepMC.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable testHepMC"
	cd /home/local1/project/Dark-Photons/madgraph/hepmcbuild/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/testHepMC.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/testHepMC.dir/build: test/testHepMC
.PHONY : test/CMakeFiles/testHepMC.dir/build

test/CMakeFiles/testHepMC.dir/requires: test/CMakeFiles/testHepMC.dir/testHepMC.cc.o.requires
test/CMakeFiles/testHepMC.dir/requires: test/CMakeFiles/testHepMC.dir/testHepMCMethods.cc.o.requires
.PHONY : test/CMakeFiles/testHepMC.dir/requires

test/CMakeFiles/testHepMC.dir/clean:
	cd /home/local1/project/Dark-Photons/madgraph/hepmcbuild/test && $(CMAKE_COMMAND) -P CMakeFiles/testHepMC.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/testHepMC.dir/clean

test/CMakeFiles/testHepMC.dir/depend:
	cd /home/local1/project/Dark-Photons/madgraph/hepmcbuild && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/local1/project/Dark-Photons/madgraph/hepmc /home/local1/project/Dark-Photons/madgraph/hepmc/test /home/local1/project/Dark-Photons/madgraph/hepmcbuild /home/local1/project/Dark-Photons/madgraph/hepmcbuild/test /home/local1/project/Dark-Photons/madgraph/hepmcbuild/test/CMakeFiles/testHepMC.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/testHepMC.dir/depend


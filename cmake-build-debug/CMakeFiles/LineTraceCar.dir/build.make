# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /Users/gotoudaisuke/Desktop/Developed_Applications/arudino/LineTraceCar

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/gotoudaisuke/Desktop/Developed_Applications/arudino/LineTraceCar/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/LineTraceCar.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/LineTraceCar.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/LineTraceCar.dir/flags.make

LineTraceCar_LineTraceCar.ino.cpp: ../LineTraceCar.ino
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/gotoudaisuke/Desktop/Developed_Applications/arudino/LineTraceCar/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Regnerating LineTraceCar.ino Sketch"
	/Applications/CLion.app/Contents/bin/cmake/bin/cmake /Users/gotoudaisuke/Desktop/Developed_Applications/arudino/LineTraceCar

CMakeFiles/LineTraceCar.dir/LineTraceCar_LineTraceCar.ino.cpp.obj: CMakeFiles/LineTraceCar.dir/flags.make
CMakeFiles/LineTraceCar.dir/LineTraceCar_LineTraceCar.ino.cpp.obj: LineTraceCar_LineTraceCar.ino.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/gotoudaisuke/Desktop/Developed_Applications/arudino/LineTraceCar/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/LineTraceCar.dir/LineTraceCar_LineTraceCar.ino.cpp.obj"
	/Applications/Arduino.app/Contents/Java/hardware/tools/avr/bin/avr-g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LineTraceCar.dir/LineTraceCar_LineTraceCar.ino.cpp.obj -c /Users/gotoudaisuke/Desktop/Developed_Applications/arudino/LineTraceCar/cmake-build-debug/LineTraceCar_LineTraceCar.ino.cpp

CMakeFiles/LineTraceCar.dir/LineTraceCar_LineTraceCar.ino.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LineTraceCar.dir/LineTraceCar_LineTraceCar.ino.cpp.i"
	/Applications/Arduino.app/Contents/Java/hardware/tools/avr/bin/avr-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/gotoudaisuke/Desktop/Developed_Applications/arudino/LineTraceCar/cmake-build-debug/LineTraceCar_LineTraceCar.ino.cpp > CMakeFiles/LineTraceCar.dir/LineTraceCar_LineTraceCar.ino.cpp.i

CMakeFiles/LineTraceCar.dir/LineTraceCar_LineTraceCar.ino.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LineTraceCar.dir/LineTraceCar_LineTraceCar.ino.cpp.s"
	/Applications/Arduino.app/Contents/Java/hardware/tools/avr/bin/avr-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/gotoudaisuke/Desktop/Developed_Applications/arudino/LineTraceCar/cmake-build-debug/LineTraceCar_LineTraceCar.ino.cpp -o CMakeFiles/LineTraceCar.dir/LineTraceCar_LineTraceCar.ino.cpp.s

CMakeFiles/LineTraceCar.dir/LineTraceCar_LineTraceCar.ino.cpp.obj.requires:

.PHONY : CMakeFiles/LineTraceCar.dir/LineTraceCar_LineTraceCar.ino.cpp.obj.requires

CMakeFiles/LineTraceCar.dir/LineTraceCar_LineTraceCar.ino.cpp.obj.provides: CMakeFiles/LineTraceCar.dir/LineTraceCar_LineTraceCar.ino.cpp.obj.requires
	$(MAKE) -f CMakeFiles/LineTraceCar.dir/build.make CMakeFiles/LineTraceCar.dir/LineTraceCar_LineTraceCar.ino.cpp.obj.provides.build
.PHONY : CMakeFiles/LineTraceCar.dir/LineTraceCar_LineTraceCar.ino.cpp.obj.provides

CMakeFiles/LineTraceCar.dir/LineTraceCar_LineTraceCar.ino.cpp.obj.provides.build: CMakeFiles/LineTraceCar.dir/LineTraceCar_LineTraceCar.ino.cpp.obj


# Object files for target LineTraceCar
LineTraceCar_OBJECTS = \
"CMakeFiles/LineTraceCar.dir/LineTraceCar_LineTraceCar.ino.cpp.obj"

# External object files for target LineTraceCar
LineTraceCar_EXTERNAL_OBJECTS =

LineTraceCar.elf: CMakeFiles/LineTraceCar.dir/LineTraceCar_LineTraceCar.ino.cpp.obj
LineTraceCar.elf: CMakeFiles/LineTraceCar.dir/build.make
LineTraceCar.elf: libuno_CORE.a
LineTraceCar.elf: CMakeFiles/LineTraceCar.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/gotoudaisuke/Desktop/Developed_Applications/arudino/LineTraceCar/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable LineTraceCar.elf"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/LineTraceCar.dir/link.txt --verbose=$(VERBOSE)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating EEP image"
	/Applications/Arduino.app/Contents/Java/hardware/tools/avr/bin/avr-objcopy -O ihex -j .eeprom --set-section-flags=.eeprom=alloc,load --no-change-warnings --change-section-lma .eeprom=0 /Users/gotoudaisuke/Desktop/Developed_Applications/arudino/LineTraceCar/cmake-build-debug/LineTraceCar.elf /Users/gotoudaisuke/Desktop/Developed_Applications/arudino/LineTraceCar/cmake-build-debug/LineTraceCar.eep
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating HEX image"
	/Applications/Arduino.app/Contents/Java/hardware/tools/avr/bin/avr-objcopy -O ihex -R .eeprom /Users/gotoudaisuke/Desktop/Developed_Applications/arudino/LineTraceCar/cmake-build-debug/LineTraceCar.elf /Users/gotoudaisuke/Desktop/Developed_Applications/arudino/LineTraceCar/cmake-build-debug/LineTraceCar.hex
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Calculating image size"
	/Applications/CLion.app/Contents/bin/cmake/bin/cmake -DFIRMWARE_IMAGE=/Users/gotoudaisuke/Desktop/Developed_Applications/arudino/LineTraceCar/cmake-build-debug/LineTraceCar.elf -DMCU=atmega328p -DEEPROM_IMAGE=/Users/gotoudaisuke/Desktop/Developed_Applications/arudino/LineTraceCar/cmake-build-debug/LineTraceCar.eep -P /Users/gotoudaisuke/Desktop/Developed_Applications/arudino/LineTraceCar/cmake-build-debug/CMakeFiles/FirmwareSize.cmake

# Rule to build all files generated by this target.
CMakeFiles/LineTraceCar.dir/build: LineTraceCar.elf

.PHONY : CMakeFiles/LineTraceCar.dir/build

CMakeFiles/LineTraceCar.dir/requires: CMakeFiles/LineTraceCar.dir/LineTraceCar_LineTraceCar.ino.cpp.obj.requires

.PHONY : CMakeFiles/LineTraceCar.dir/requires

CMakeFiles/LineTraceCar.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/LineTraceCar.dir/cmake_clean.cmake
.PHONY : CMakeFiles/LineTraceCar.dir/clean

CMakeFiles/LineTraceCar.dir/depend: LineTraceCar_LineTraceCar.ino.cpp
	cd /Users/gotoudaisuke/Desktop/Developed_Applications/arudino/LineTraceCar/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/gotoudaisuke/Desktop/Developed_Applications/arudino/LineTraceCar /Users/gotoudaisuke/Desktop/Developed_Applications/arudino/LineTraceCar /Users/gotoudaisuke/Desktop/Developed_Applications/arudino/LineTraceCar/cmake-build-debug /Users/gotoudaisuke/Desktop/Developed_Applications/arudino/LineTraceCar/cmake-build-debug /Users/gotoudaisuke/Desktop/Developed_Applications/arudino/LineTraceCar/cmake-build-debug/CMakeFiles/LineTraceCar.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/LineTraceCar.dir/depend


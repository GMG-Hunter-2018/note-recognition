cmake_minimum_required(VERSION 3.12)
project(note-recognition CXX)

# C++ Version
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENTIONS False)

# Qt Settings
set(CMAKE_INCLUDE_CURRENT_DIR ON)
find_package(Qt5 COMPONENTS Core Widgets REQUIRED)

# PortAudio Settings
add_subdirectory(${CMAKE_SOURCE_DIR}/external/portaudio/ EXCLUDE_FROM_ALL)

# Linting/Formatting
set(CMAKE_EXPORT_COMPILE_COMMANDS True CACHE BOOL "Export Compile Commands for Linting" FORCE)
configure_file(tools/lint-clang.bash.in tools/lint-clang.bash @ONLY)
configure_file(tools/format.bash.in tools/format.bash @ONLY)

# Binary Locations
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Warnings
include(${CMAKE_SOURCE_DIR}/cmake/CheckAndAddFlag.cmake)

option(GMG_WERROR "Promote complier warnings to errors." OFF)
if (("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU") OR (CMAKE_CXX_COMPILER_ID MATCHES "Clang"))
	Check_And_Add_Flag(-fdiagnostics-color=always)
	Check_And_Add_Flag(-Wall)
	Check_And_Add_Flag(-Wextra)
	Check_And_Add_Flag(-Wpedantic)
	Check_And_Add_Flag(-Wconversion)
	Check_And_Add_Flag(-Wsign-conversion)
	Check_And_Add_Flag(-Wcast-align)
	Check_And_Add_Flag(-Wcast-qual)
	Check_And_Add_Flag(-Wctor-dtor-privacy)
	Check_And_Add_Flag(-Wdisabled-optimization)
	Check_And_Add_Flag(-Wdouble-promotion)
	Check_And_Add_Flag(-Wduplicated-branches)
	Check_And_Add_Flag(-Wduplicated-cond)
	Check_And_Add_Flag(-Wformat=2)
	Check_And_Add_Flag(-Wlogical-op)
	Check_And_Add_Flag(-Wmissing-include-dirs)
	Check_And_Add_Flag(-Wnoexcept)
	Check_And_Add_Flag(-Wnull-dereference)
	Check_And_Add_Flag(-Wold-style-cast)
	Check_And_Add_Flag(-Woverloaded-virtual)
	Check_And_Add_Flag(-Wshadow)
	Check_And_Add_Flag(-Wstrict-aliasing=1)
	Check_And_Add_Flag(-Wstrict-null-sentinel)
	Check_And_Add_Flag(-Wstrict-overflow=2)
	Check_And_Add_Flag(-Wswitch-default)
	Check_And_Add_Flag(-Wundef)
	Check_And_Add_Flag(-Wuseless-cast)
	Check_And_Add_Flag(-Wno-unknown-pragmas)
	Check_And_Add_Flag(-Wno-aligned-new)
	if(("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU") AND (CMAKE_CXX_COMPILER_VERSION VERSION_LESS 5.0))
		# Useless flag that hits a bunch of valid code
		Check_And_Add_Flag(-Wno-missing-field-initializers)
	endif()
	if(FTL_WERROR)
		Check_And_Add_Flag(-Werror)
	endif()
else()
	Check_And_Add_Flag(/W4)
	Check_And_Add_Flag(/wd4324)
	if(FTL_WERROR)
		Check_And_Add_Flag(/WX)
	endif()
endif()

# Libraries
add_subdirectory(lib)

# Executable Source
add_subdirectory(src)

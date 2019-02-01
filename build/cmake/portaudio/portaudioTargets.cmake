# Generated by CMake

if("${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION}" LESS 2.5)
   message(FATAL_ERROR "CMake >= 2.6.0 required")
endif()
cmake_policy(PUSH)
cmake_policy(VERSION 2.6)
#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Protect against multiple inclusion, which would fail when already imported targets are added once more.
set(_targetsDefined)
set(_targetsNotDefined)
set(_expectedTargets)
foreach(_expectedTarget portaudio portaudio_static)
  list(APPEND _expectedTargets ${_expectedTarget})
  if(NOT TARGET ${_expectedTarget})
    list(APPEND _targetsNotDefined ${_expectedTarget})
  endif()
  if(TARGET ${_expectedTarget})
    list(APPEND _targetsDefined ${_expectedTarget})
  endif()
endforeach()
if("${_targetsDefined}" STREQUAL "${_expectedTargets}")
  unset(_targetsDefined)
  unset(_targetsNotDefined)
  unset(_expectedTargets)
  set(CMAKE_IMPORT_FILE_VERSION)
  cmake_policy(POP)
  return()
endif()
if(NOT "${_targetsDefined}" STREQUAL "")
  message(FATAL_ERROR "Some (but not all) targets in this export set were already defined.\nTargets Defined: ${_targetsDefined}\nTargets not yet defined: ${_targetsNotDefined}\n")
endif()
unset(_targetsDefined)
unset(_targetsNotDefined)
unset(_expectedTargets)


# Create imported target portaudio
add_library(portaudio SHARED IMPORTED)

set_target_properties(portaudio PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "/home/eve/Sync/Non-school-programs/GoogleNotes/note-recognition/external/portaudio/include"
)

# Create imported target portaudio_static
add_library(portaudio_static STATIC IMPORTED)

set_target_properties(portaudio_static PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "/home/eve/Sync/Non-school-programs/GoogleNotes/note-recognition/external/portaudio/include"
)

# Import target "portaudio" for configuration "Debug"
set_property(TARGET portaudio APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(portaudio PROPERTIES
  IMPORTED_LINK_INTERFACE_LIBRARIES_DEBUG "m;pthread"
  IMPORTED_LOCATION_DEBUG "/home/eve/Sync/Non-school-programs/GoogleNotes/note-recognition/build/external/portaudio/libportaudio.so"
  IMPORTED_SONAME_DEBUG "libportaudio.so"
  )

# Import target "portaudio_static" for configuration "Debug"
set_property(TARGET portaudio_static APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(portaudio_static PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "C"
  IMPORTED_LINK_INTERFACE_LIBRARIES_DEBUG "m;pthread"
  IMPORTED_LOCATION_DEBUG "/home/eve/Sync/Non-school-programs/GoogleNotes/note-recognition/build/external/portaudio/libportaudio.a"
  )

# This file does not depend on other imported targets which have
# been exported from the same project but in a separate export set.

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
cmake_policy(POP)

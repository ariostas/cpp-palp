cmake_minimum_required(VERSION 3.14...3.27)

# Project name and settings

project(
  CPP-PALP
  VERSION 0.0.0
  DESCRIPTION "CPP-PALP: a C++ Package for Analyzing Lattice Polytopes"
  LANGUAGES CXX
)

# If this is the main project we set some settings
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)

  set(CMAKE_CXX_EXTENSIONS OFF)
  set_property(GLOBAL PROPERTY USE_FOLDERS ON)

  # Enable testing
  include(CTest)

  # Enable docs if available
  find_package(Doxygen)
  if(Doxygen_FOUND)
    add_subdirectory(docs)
  else()
    message(STATUS "Doxygen not found. Docs will not be built.")
  endif()

endif()

# Use FetchContent to download external libraries
include(FetchContent)

# Formatting library
FetchContent_Declare(
  fmtlib
  GIT_REPOSITORY https://github.com/fmtlib/fmt.git
  GIT_TAG 5.3.0)
FetchContent_MakeAvailable(fmtlib)

# Compiled library code
add_subdirectory(src)

# Standalone apps
add_subdirectory(apps)

# Add tests directory when this is the main project or when explicitly specified
if((CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME OR CPP-PALP_BUILD_TESTING) AND BUILD_TESTING)
  add_subdirectory(tests)
endif()

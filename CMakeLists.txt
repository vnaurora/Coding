cmake_minimum_required (VERSION 2.6)

project (Coding)
# The version number.
set (StringExercises_VERSION_MAJOR 1)
set (StringExercises_VERSION_MINOR 0)

# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
  "${PROJECT_SOURCE_DIR}/StringExercises.h.in"
  "${PROJECT_BINARY_DIR}/StringExercises.h"
  )

# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
include_directories("${PROJECT_BINARY_DIR}")

include_directories ("${PROJECT_SOURCE_DIR}/MathFunctions")
add_subdirectory (MathFunctions) 
set (EXTRA_LIBS ${EXTRA_LIBS} MathFunctions)

add_executable(StringExercises StringExercises.cpp)
target_link_libraries (Coding MathFunctions)


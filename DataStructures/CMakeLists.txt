cmake_minimum_required (VERSION 2.8)

project (StringExercises)
# The version number.
set (StringExercises_VERSION_MAJOR 1)
set (StringExercises_VERSION_MINOR 0)

# configure a header file to pass some of the CMake settings
# to the source code
# configure_file (
  # "${PROJECT_SOURCE_DIR}/StringExercises.h.in"
  # "${PROJECT_SOURCE_BIN}/StringExercises_version.txt"
  # )

# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
include_directories(${PROJECT_SOURCE_DIR})

# Create the list of source files
set (STRING_EXECISES_SRC
    ${CMAKE_CURRENT_LIST_DIR}/StringExercises.cpp
    )

# Create the list of header files
foreach(src_file IN LISTS STRING_EXECISES_SRC)
  string(REGEX REPLACE .cpp .h hdr_file ${src_file})
  list(APPEND STRING_EXECISES_HDR ${hdr_file})
endforeach(src_file IN LISTS STRING_EXECISES_SRC)

# add_executable(StringExercises ${STRING_EXECISES_HDR} 
                               # ${STRING_EXECISES_SRC}
							   # ${CMAKE_CURRENT_LIST_DIR}/StringExercises_main.cpp)

add_library(StringExercises STATIC ${STRING_EXECISES_HDR} ${STRING_EXECISES_SRC})
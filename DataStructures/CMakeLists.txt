cmake_minimum_required (VERSION 2.8)

project (DataStructures)
# The version number.
set (DataStructures_VERSION_MAJOR 1)
set (DataStructures_VERSION_MINOR 0)

# configure a header file to pass some of the CMake settings
# to the source code
# configure_file (
  # "${PROJECT_SOURCE_DIR}/DataStructures.h.in"
  # "${PROJECT_SOURCE_BIN}/DataStructures_version.txt"
  # )

# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
include_directories(${PROJECT_SOURCE_DIR})

# Create the list of source files
set (DATA_STRUCTURES_SRC
    ${CMAKE_CURRENT_LIST_DIR}/StringExercises.cpp
	${CMAKE_CURRENT_LIST_DIR}/ArrayExercises.cpp
	${CMAKE_CURRENT_LIST_DIR}/LinkedListExercises.cpp
    )

# Create the list of header files
foreach(src_file IN LISTS DATA_STRUCTURES_SRC)
  string(REGEX REPLACE .cpp .h hdr_file ${src_file})
  list(APPEND DATA_STRUCTURES_HDR ${hdr_file})
endforeach(src_file IN LISTS DATA_STRUCTURES_SRC)

# add_executable(DataStructures ${DATA_STRUCTURES_HDR} 
                               # ${DATA_STRUCTURES_SRC}
							   # ${CMAKE_CURRENT_LIST_DIR}/DataStructures_main.cpp)

add_library(DataStructures STATIC ${DATA_STRUCTURES_HDR} ${DATA_STRUCTURES_SRC})
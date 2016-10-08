cmake_minimum_required (VERSION 2.8)

project (Algorithms)
set(ALGORITHMS_FOLDER_NAME "Algorithms")
include_directories(${PROJECT_SOURCE_DIR})

# Create the list of source files
set (ALGORITHMS_SRC
    ${CMAKE_CURRENT_LIST_DIR}/AlgoEx01.cpp
    )

# Create the list of header files
foreach(src_file IN LISTS ALGORITHMS_SRC)
  string(REGEX REPLACE .cpp .h hdr_file ${src_file})
  list(APPEND ALGORITHMS_HDR ${hdr_file})
endforeach(src_file IN LISTS ALGORITHMS_SRC)

set(ALGORITHMS_HDR
    ${ALGORITHMS_HDR}
	${CMAKE_CURRENT_LIST_DIR}/AlgorithmExercises.h
	)

# add_executable(Algorithms ${ALGORITHMS_HDR} 
                               # ${ALGORITHMS_SRC}
							   # ${CMAKE_CURRENT_LIST_DIR}/Algorithms_main.cpp)

add_library(Algorithms STATIC ${ALGORITHMS_HDR} ${ALGORITHMS_SRC})
set_property(TARGET Algorithms PROPERTY FOLDER ${ALGORITHMS_FOLDER_NAME})

add_executable(Permutation ${CMAKE_CURRENT_LIST_DIR}/Permutation.cpp)
set_property(TARGET Permutation PROPERTY FOLDER ${ALGORITHMS_FOLDER_NAME})
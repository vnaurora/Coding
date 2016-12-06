cmake_minimum_required (VERSION 2.8)

project (Algorithms)
set(ALGORITHMS_FOLDER_NAME "Algorithms")
include_directories(${PROJECT_SOURCE_DIR})

# Create the list of source files
set(COMMON_HDR
	${CMAKE_CURRENT_LIST_DIR}/HelperFunctions.h)

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

add_executable(Trie ${CMAKE_CURRENT_LIST_DIR}/Trie.cpp)
set_property(TARGET Trie PROPERTY FOLDER ${ALGORITHMS_FOLDER_NAME})

add_executable(FindCommonInTwoArrays ${CMAKE_CURRENT_LIST_DIR}/FindCommonInTwoArrays.cpp)
set_property(TARGET FindCommonInTwoArrays PROPERTY FOLDER ${ALGORITHMS_FOLDER_NAME})

add_executable(BinaryTree ${COMMON_HDR} 
                          ${CMAKE_CURRENT_LIST_DIR}/BinaryTree.h
						  ${CMAKE_CURRENT_LIST_DIR}/BinaryTree_main.cpp)
set_property(TARGET BinaryTree PROPERTY FOLDER ${ALGORITHMS_FOLDER_NAME})

add_executable(BST ${COMMON_HDR} 
                          ${CMAKE_CURRENT_LIST_DIR}/BST.h
						  ${CMAKE_CURRENT_LIST_DIR}/BST_main.cpp)
set_property(TARGET BST PROPERTY FOLDER ${ALGORITHMS_FOLDER_NAME})

############ BASIC PROBLEMS ###################
# SEARCH
add_executable(BinarySearch ${COMMON_HDR} 
						  ${CMAKE_CURRENT_LIST_DIR}/Basic/BinarySearch.cpp)
set_property(TARGET BinarySearch PROPERTY FOLDER ${ALGORITHMS_FOLDER_NAME}/Basic/Search)

#SORT:
add_executable(BubbleSort ${COMMON_HDR} 
						  ${CMAKE_CURRENT_LIST_DIR}/Basic/BubbleSort.cpp)
set_property(TARGET BubbleSort PROPERTY FOLDER ${ALGORITHMS_FOLDER_NAME}/Basic/Sort)
add_executable(QuickSort ${COMMON_HDR} 
						  ${CMAKE_CURRENT_LIST_DIR}/Basic/QuickSort.cpp)
set_property(TARGET QuickSort PROPERTY FOLDER ${ALGORITHMS_FOLDER_NAME}/Basic/Sort)

#GRAPH:
add_executable(Graph_BFS ${COMMON_HDR} 
						  ${CMAKE_CURRENT_LIST_DIR}/Basic/Graph_BFS.cpp)
set_property(TARGET Graph_BFS PROPERTY FOLDER ${ALGORITHMS_FOLDER_NAME}/Basic/Graph)

############ EASY PROBLEMS ###################

add_executable(StringToInt ${COMMON_HDR} 
						  ${CMAKE_CURRENT_LIST_DIR}/Easy/StringToInt.cpp)
set_property(TARGET StringToInt PROPERTY FOLDER ${ALGORITHMS_FOLDER_NAME}/Easy)

add_executable(ReverseWords ${COMMON_HDR} 
						  ${CMAKE_CURRENT_LIST_DIR}/Easy/ReverseWords.cpp)
set_property(TARGET ReverseWords PROPERTY FOLDER ${ALGORITHMS_FOLDER_NAME}/Easy)

add_executable(Sorting ${COMMON_HDR} 
						  ${CMAKE_CURRENT_LIST_DIR}/Easy/Sorting.cpp)
set_property(TARGET Sorting PROPERTY FOLDER ${ALGORITHMS_FOLDER_NAME}/Easy)

add_executable(Sort3ColorBalls ${COMMON_HDR} 
						  ${CMAKE_CURRENT_LIST_DIR}/Easy/Sort3ColorBalls.cpp)
set_property(TARGET Sort3ColorBalls PROPERTY FOLDER ${ALGORITHMS_FOLDER_NAME}/Easy)

add_executable(ReverseInteger ${COMMON_HDR} 
						  ${CMAKE_CURRENT_LIST_DIR}/Easy/ReverseInteger.cpp)
set_property(TARGET ReverseInteger PROPERTY FOLDER ${ALGORITHMS_FOLDER_NAME}/Easy)

add_executable(CountAndSay ${COMMON_HDR} 
						  ${CMAKE_CURRENT_LIST_DIR}/Easy/CountAndSay.cpp)
set_property(TARGET CountAndSay PROPERTY FOLDER ${ALGORITHMS_FOLDER_NAME}/Easy)

############ MEDIUM PROBLEMS ###################
add_executable(LongestStringWithoutDuplicates ${COMMON_HDR} 
						  ${CMAKE_CURRENT_LIST_DIR}/Medium/LongestStringWithoutDuplicates.cpp)
set_property(TARGET LongestStringWithoutDuplicates PROPERTY FOLDER ${ALGORITHMS_FOLDER_NAME}/Medium)

add_executable(SearchRange ${COMMON_HDR} 
						  ${CMAKE_CURRENT_LIST_DIR}/Medium/SearchRange.cpp)
set_property(TARGET SearchRange PROPERTY FOLDER ${ALGORITHMS_FOLDER_NAME}/Medium)
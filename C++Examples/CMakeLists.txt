cmake_minimum_required (VERSION 2.8)

project (C++Examples)
set(ALGORITHMS_FOLDER_NAME "C++Examples")
include_directories(${PROJECT_SOURCE_DIR})

############ REGEX ###################
add_executable(RegexCheckInteger ${COMMON_HDR} 
						  ${CMAKE_CURRENT_LIST_DIR}/Regex/RegexCheckInteger.cpp)
set_property(TARGET RegexCheckInteger PROPERTY FOLDER ${ALGORITHMS_FOLDER_NAME}/Regex)

add_executable(RegexCheckEmailAddress ${COMMON_HDR} 
						  ${CMAKE_CURRENT_LIST_DIR}/Regex/RegexCheckEmailAddress.cpp)
set_property(TARGET RegexCheckEmailAddress PROPERTY FOLDER ${ALGORITHMS_FOLDER_NAME}/Regex)

add_executable(RegexReadTime ${COMMON_HDR} 
						  ${CMAKE_CURRENT_LIST_DIR}/Regex/RegexReadTime.cpp)
set_property(TARGET RegexReadTime PROPERTY FOLDER ${ALGORITHMS_FOLDER_NAME}/Regex)

############ Thread local storage ###################
add_executable(thread_local_storage ${COMMON_HDR} 
                          ${CMAKE_CURRENT_LIST_DIR}/thread_local_storage/per_thread_singleton.h
						  ${CMAKE_CURRENT_LIST_DIR}/thread_local_storage/main.cpp)
set_property(TARGET thread_local_storage PROPERTY FOLDER ${ALGORITHMS_FOLDER_NAME}/thread_local_storage)
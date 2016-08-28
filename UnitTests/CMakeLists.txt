###############################
#UnitTests CMakeLists
#By: NHQ
#Copyright (c) 2016
###############################

cmake_minimum_required (VERSION 2.8)

project (UnitTests CXX)

################################
# GTest
################################
enable_testing()
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

############
# Test objects

include_directories(${CMAKE_CURRENT_LIST_DIR}/../DataStructures)

################################
# Unit Tests
################################
# Add cpp files
set (UNIT_TESTS_SRC
    ${CMAKE_CURRENT_LIST_DIR}/gtest_StringExercises.cpp
	${CMAKE_CURRENT_LIST_DIR}/gtest_ArrayExercises.cpp
	${CMAKE_CURRENT_LIST_DIR}/main.cpp
    )
	
add_executable(UnitTests ${UNIT_TESTS_SRC})
target_link_libraries(UnitTests
					  StringExercises
                      gtest
                      gtest_main)
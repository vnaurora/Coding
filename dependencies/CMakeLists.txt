###############################
#Dependencies CMakeLists
#By: NHQ
#Copyright (c) 2016
###############################

cmake_minimum_required (VERSION 2.8)

set(DEPENDENCIES_FOLDER_NAME "Dependencies")
# Add Google Test
#Group into folder.
add_subdirectory(googletest)
set_property(TARGET gtest PROPERTY FOLDER "${DEPENDENCIES_FOLDER_NAME}/gtest")
set_property(TARGET gmock PROPERTY FOLDER "${DEPENDENCIES_FOLDER_NAME}/gtest")
set_property(TARGET gtest_main PROPERTY FOLDER "${DEPENDENCIES_FOLDER_NAME}/gtest")
set_property(TARGET gmock_main PROPERTY FOLDER "${DEPENDENCIES_FOLDER_NAME}/gtest")

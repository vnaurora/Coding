###############################
#Root CMakeLists
#By: NHQ
#Copyright (c) 2016
###############################

cmake_minimum_required (VERSION 2.8)

#Override rules to set compiler flags.
#NOTE: this must be put before any project() is called.
if (NOT CMAKE_TOOLCHAIN_FILE)
set(CMAKE_USER_MAKE_RULES_OVERRIDE c_flags_overrides.cmake)
set(CMAKE_USER_MAKE_RULES_OVERRIDE_CXX cxx_flags_overrides.cmake)
endif()

include(platform_settings.cmake)

#Create root solution:
project(Coding)

#Add projects inside:
#Dependencies
add_subdirectory(Dependencies)
#Data Structures code
add_subdirectory(DataStructures)
#Algorithms code
add_subdirectory(Algorithms)
#Unit Tests code
add_subdirectory(UnitTests)

###############################
#Common platform settings
#By: NHQ
#Copyright (c) 2016
###############################

# Activate the folders in a solution
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# set output directories
# http://stackoverflow.com/questions/7747857/in-cmake-how-do-i-work-around-the-debug-and-release-directories-visual-studio-2
# First for the generic no-config case (e.g. with mingw)
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE}/bin )
set( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE}/lib )
set( CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE}/lib )
# Second, for multi-config builds (e.g. msvc)
foreach( OUTPUTCONFIG ${CMAKE_CONFIGURATION_TYPES} )
    string( TOUPPER ${OUTPUTCONFIG} CONFIGUPPER )
    set( CMAKE_RUNTIME_OUTPUT_DIRECTORY_${CONFIGUPPER} ${CMAKE_BINARY_DIR}/${OUTPUTCONFIG}/bin )
    set( CMAKE_LIBRARY_OUTPUT_DIRECTORY_${CONFIGUPPER} ${CMAKE_BINARY_DIR}/${OUTPUTCONFIG}/lib )
    set( CMAKE_ARCHIVE_OUTPUT_DIRECTORY_${CONFIGUPPER} ${CMAKE_BINARY_DIR}/${OUTPUTCONFIG}/lib )
endforeach( OUTPUTCONFIG CMAKE_CONFIGURATION_TYPES )

if (APPLE)

  SET(CMAKE_MACOSX_RPATH ON) 
  SET(CMAKE_XCODE_ATTRIBUTE_CLANG_CXX_LANGUAGE_STANDARD "c++11")
  SET(CMAKE_XCODE_ATTRIBUTE_CLANG_CXX_LIBRARY "libc++")
  
elseif(LINUX)
  if(NOT ANDROID)
    SET(CMAKE_SKIP_RPATH FALSE)
    SET(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
    SET(CMAKE_INSTALL_RPATH "\$ORIGIN:\$ORIGIN/../lib")
    set(CMAKE_STRIP "strip" CACHE PATH "strip")
    set(CMAKE_OBJCOPY "objcopy" CACHE PATH "objcopy")
  endif()
  # add_definitions(-D_PSY_LINUX_)
  add_definitions(-D_LINUX)

elseif(MSVC)  
  # add_definitions(-DFREEGLUT_STATIC)
  # Even for builds with debug symbols, we want to eliminate unreferenced
  # functions during linking
  SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /OPT:REF,ICF")
  SET(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} /OPT:REF,ICF")
  SET(CMAKE_MODULE_LINKER_FLAGS "${CMAKE_MODULE_LINKER_FLAGS} /OPT:REF,ICF")

  # Ref: http://blogs.msdn.com/b/vcblog/archive/2011/09/12/10209291.aspx
  # Needed for gtest
  add_definitions(-D_VARIADIC_MAX=10)

  add_definitions(
    -D_UNICODE
    -DUNICODE
    -D_CRT_SECURE_NO_WARNINGS
    -DNOMINMAX
  )

endif()


cmake_minimum_required (VERSION 2.8)

project (OODesign)
set(OODESIGN_FOLDER_NAME "OODesign")
include_directories(${PROJECT_SOURCE_DIR})

# Create the list of source files
set (OODESIGN_SRC
    ${CMAKE_CURRENT_LIST_DIR}/CallCenter.cpp
    )

# Create the list of header files
set(OODESIGN_HDR
    ${CMAKE_CURRENT_LIST_DIR}/OODesign.h
	${CMAKE_CURRENT_LIST_DIR}/CallCenter.h
	${CMAKE_CURRENT_LIST_DIR}/ChessGame.h
	)

# add_executable(Algorithms ${OODESIGN_HDR} 
                               # ${OODESIGN_SRC}
							   # ${CMAKE_CURRENT_LIST_DIR}/OODesign_main.cpp)

add_executable(ChessGame ${CMAKE_CURRENT_LIST_DIR}/ChessGame.h 
                         ${CMAKE_CURRENT_LIST_DIR}/ChessGame_main.cpp)
set_property(TARGET ChessGame PROPERTY FOLDER ${OODESIGN_FOLDER_NAME})
			   
add_library(OODesign STATIC ${OODESIGN_HDR} ${OODESIGN_SRC})
set_property(TARGET OODesign PROPERTY FOLDER ${OODESIGN_FOLDER_NAME})
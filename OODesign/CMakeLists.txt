cmake_minimum_required (VERSION 2.8)

project (OODesign)

include_directories(${PROJECT_SOURCE_DIR})

# Create the list of source files
set (OODESIGN_SRC
    ${CMAKE_CURRENT_LIST_DIR}/CallCenter.cpp
    )

# Create the list of header files
foreach(src_file IN LISTS OODESIGN_SRC)
  string(REGEX REPLACE .cpp .h hdr_file ${src_file})
  list(APPEND OODESIGN_HDR ${hdr_file})
endforeach(src_file IN LISTS OODESIGN_SRC)

set(OODESIGN_HDR
    ${OODESIGN_HDR}
	${CMAKE_CURRENT_LIST_DIR}/OODesign.h
	)

# add_executable(Algorithms ${OODESIGN_HDR} 
                               # ${OODESIGN_SRC}
							   # ${CMAKE_CURRENT_LIST_DIR}/OODesign_main.cpp)

add_library(OODesign STATIC ${OODESIGN_HDR} ${OODESIGN_SRC})
#cxx_flag_overrides.cmake
if (CMAKE_COMPILER_IS_GNUCC)
    message(STATUS "Gnu-Compiler detected, setting custom flags")
    set(CXX_COMMON_FLAGS
        "-fPIC -std=c++11 -fvisibility=hidden -msse -msse2 -msse3 -mssse3 -mmmx -Wall -Wno-unknown-pragmas")
    set(CMAKE_CXX_FLAGS_DEBUG
        "-g -D_DEBUG ${CXX_COMMON_FLAGS}"
        CACHE STRING "Debug options." FORCE
       )
    set(CMAKE_CXX_FLAGS_RELEASE
        "-O2 -fomit-frame-pointer -DNDEBUG  ${CXX_COMMON_FLAGS}"
        CACHE STRING "Release options." FORCE
       )
    set(CMAKE_CXX_FLAGS_RELWITHDEBINFO
        "${CMAKE_CXX_FLAGS_RELEASE} -g" CACHE STRING "Release with debug info options." FORCE
       )

elseif(APPLE)
    message(STATUS "Use clang on Apple, setting custom flags")
    set(CXX_COMMON_FLAGS
        "-std=c++11 -Wall -Wno-unknown-pragmas -Wno-attributes -fvisibility=hidden")
    set(CMAKE_CXX_FLAGS_DEBUG
        "-g -stdlib=libc++ -D_DEBUG ${CXX_COMMON_FLAGS}"
        CACHE STRING "Debug options." FORCE
       )
    set(CMAKE_CXX_FLAGS_RELEASE
        "-O2 -stdlib=libc++ -DNDEBUG ${CXX_COMMON_FLAGS}"
        CACHE STRING "Release options." FORCE
       )
    set(CMAKE_CXX_FLAGS_RELWITHDEBINFO
        "${CMAKE_CXX_FLAGS_RELEASE} -g" CACHE STRING "Release with debug info options." FORCE
       )

elseif(MSVC)
	message(STATUS "Set runtime library for MSVC")
    set(CXX_FLAGS_DEBUG "/D_DEBUG /MTd /Zi /Ob0 /Od /RTC1 /FS")

    set(CXX_FLAGS_RELEASE "/MT /O2 /Ob2 /Oi /Ot /D NDEBUG /FS")
    if(NOT CMAKE_CL_64)
        set(CXX_FLAGS_RELEASE "${CXX_FLAGS_RELEASE} /arch:SSE2")
    endif(NOT CMAKE_CL_64)

    set(CXX_FLAGS_RELWITHDEBINFO "/Zi ${CXX_FLAGS_RELEASE}")

    set(CMAKE_CXX_FLAGS_DEBUG_INIT "${CXX_FLAGS_DEBUG}")
    set(CMAKE_CXX_FLAGS_RELEASE_INIT "${CXX_FLAGS_RELEASE}")
    set(CMAKE_CXX_FLAGS_RELWITHDEBINFO_INIT "${CXX_FLAGS_RELWITHDEBINFO}")
    
    # Removed uuid.lib from the list of defaults
    # Ref: https://code.google.com/p/webrtc/issues/detail?id=3996
    set(CMAKE_CXX_STANDARD_LIBRARIES_INIT "kernel32.lib;user32.lib;gdi32.lib;winspool.lib;shell32.lib;ole32.lib;oleaut32.lib;comdlg32.lib;advapi32.lib")
endif()

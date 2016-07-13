#c_flag_overrides.cmake
if (CMAKE_COMPILER_IS_GNUCC)
        message(STATUS "Gnu-Compiler detected, setting custom flags")
        set(CMAKE_C_FLAGS_DEBUG
            "-g -D_DEBUG" CACHE STRING "Debug options." FORCE
           )
        set(CMAKE_C_FLAGS_RELEASE
            "-O2 -fomit-frame-pointer -fvisibility=hidden -DNDEBUG" CACHE STRING "Release options." FORCE
           )
        set(CMAKE_C_FLAGS_RELWITHDEBINFO
            "${CMAKE_C_FLAGS_RELEASE} -g" CACHE STRING "Release with debug info options." FORCE
           )
elseif(MSVC)


elseif(APPLE)

    set(CMAKE_C_FLAGS_DEBUG
        "-g -D_DEBUG" CACHE STRING "Debug options." FORCE
       )
    set(CMAKE_C_FLAGS_RELEASE
        "-O2 -DNDEBUG" CACHE STRING "Release options." FORCE
       )
    set(CMAKE_C_FLAGS_RELWITHDEBINFO
        "${CMAKE_C_FLAGS_RELEASE} -g" CACHE STRING "Release with debug info options." FORCE
       )

    add_definitions(-Wall)
    add_definitions(-Wno-unknown-pragmas)
    add_definitions(-Wno-attributes)
    add_definitions(-fvisibility=hidden)

endif()

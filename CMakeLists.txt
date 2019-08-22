cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
set(CMAKE_LEGACY_CYGWIN_WIN32 0)

set (pname figures)

project(${pname} CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(headers
    src/Circle.hpp
    src/CompositeFigure.hpp
    src/Figure.hpp
    src/Polygon.hpp
    src/Position.hpp
)

set(sources
    src/Circle.cpp
    src/CompositeFigure.cpp
    src/Figure.cpp
    src/main.cpp
    src/Position.cpp
)

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR
    "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    set(warnings "-Wall -Wextra -Werror")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    set(warnings "/W4 /WX /EHsc")
endif()

if (NOT CONFIGURED_ONCE)
    set(CMAKE_CXX_FLAGS "${warnings}"
        CACHE STRING "Flags used by the compiler during all build types." FORCE)
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set(ename ${pname}.out)
add_executable(${ename} ${sources})

set(CONFIGURED_ONCE TRUE CACHE INTERNAL
    "A flag showing that CMake has configured at least once.")

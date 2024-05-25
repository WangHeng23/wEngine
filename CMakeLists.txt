cmake_minimum_required(VERSION 3.20)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)

project(
    wEngine
    LANGUAGES CXX C
)

add_subdirectory(3rdlibs)
add_subdirectory(engine)

option(WEN_BUILD_SANDBOX "build sandbox" ON)
if (WEN_BUILD_SANDBOX)
    add_subdirectory(sandbox)
endif()
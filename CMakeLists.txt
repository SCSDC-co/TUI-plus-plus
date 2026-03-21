cmake_minimum_required(VERSION 3.28)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(
    tui-plusplus
    LANGUAGES CXX
    VERSION 0.0.1
    DESCRIPTION
        "A header-only simple TUI library heavily \
        inspired by rich and Spectre.Console"
)

add_subdirectory(include/tuipp/)

option(TUI_BUILD_TESTS "Build tests" OFF)

if(TUI_BUILD_TESTS)
    add_executable(tuipp test/main.cpp)

    target_include_directories(tuipp PUBLIC ${CMAKE_SOURCE_DIR}/include)
    target_link_libraries(tuipp PUBLIC tuipp_console)
    set_target_properties(tuipp PROPERTIES CXX_EXTENSIONS OFF)
endif()

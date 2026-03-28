add_library(tuipp_console print.cpp Console.cpp)

target_include_directories(tuipp_console PUBLIC ${CMAKE_SOURCE_DIR}/include)

add_library(tuipp_console)

target_sources(tuipp_console PUBLIC FILE_SET CXX_MODULES FILES print.cpp)

target_include_directories(tuipp_console PUBLIC ${CMAKE_SOURCE_DIR}/vendor)

target_compile_features(tuipp_console PUBLIC cxx_std_20)

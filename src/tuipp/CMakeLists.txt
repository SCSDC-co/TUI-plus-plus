add_library(
    tuipp_src
    ./console_info.cpp
    ./widgets/markup_text/MarkupText.cpp
    ./widgets/Text.cpp
)

target_include_directories(tuipp_src PUBLIC ${CMAKE_SOURCE_DIR}/include)

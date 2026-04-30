#pragma once

#include <cstddef>
#include <cstdlib>

#include "../tuipp/private/macros.hpp"

namespace tuipp {

/// Some useful methods and types for getting the console information
namespace console_info {

struct TerminalSize
{
    std::size_t width{};
    std::size_t height{};
};

enum ColorSystem
{
    /// no color support, it disables every color
    NO_COLORS,

    /// 16 colors palette
    EIGHT_BIT,

    /// full 16 million color support
    TRUE_COLOR
};

TUIPP_NODISCARD TerminalSize
get_terminal_size();

TUIPP_NODISCARD bool
get_support_ansi();

/// adapted from:
/// https://github.com/spectreconsole/spectre.console/blob/main/src/Spectre.Console.Ansi/ColorSystemDetector.cs
/// thanks guys ❤  love you all
TUIPP_NODISCARD ColorSystem
get_color_support();

} // namespace console_info

} // namespace tuipp

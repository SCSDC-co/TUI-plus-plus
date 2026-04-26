/**
 * @file console_info.hpp
 *
 * @brief A header that contains useful methods and types for getting the console informations
 *
 * @author Giuliano De Amicis
 */

#pragma once

#include <cstddef>
#include <cstdlib>

#include "private/macros.hpp"

namespace tuipp {

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

/**
 * @file print.hpp
 *
 * @brief A utility to print text with markup support.
 *
 * @details Example:
 *
 * @code{.cpp}
 * tuipp::println("[bold red]Hello, World![/]");
 *
 * tuipp::print("[bold green]Hello, World![/]");
 * @endcode
 *
 * @author Giuliano De Amicis
 */

#pragma once

#include <string>

namespace tuipp {

/**
 * @brief Print a string with a new line at the end (supports markup). test
 *
 * ## Example:
 *
 * @code{.cpp}
 * tuipp::println("[bold red]Hello, World![/]");
 * @endcode
 *
 * ## Styles:
 *
 * - Foreground colors: `red`, `green`, `grey`, `blue`, `magenta`, `yellow`, `white`, `bright_red`,
 *   `bright_green`, `bright_grey`, `bright_blue`, `bright_magenta`, `bright_yellow`, `bright_cyan`,
 *   `bright_white`
 *
 * - Background colors: `bg_red`, `bg_green`, `bg_grey`, `bg_blue`, `bg_magenta`, `bg_yellow`,
 *   `bg_cyan`, `bg_white`
 *
 * - Effects: `bold`, `underline`, `blink`, `italic`
 *
 * - Reset: `/`
 *
 * ---
 *
 * You can also escape markup brackets using a backslash:
 *
 * @code{.cpp}
 * tuipp::println("\[bold red]Hello, World!\[/]");
 * @endcode
 *
 * @param string The string to be printed, it can be empty.
 */
void
println(const std::string& string = "");

/**
 * @brief Print a string without a new line at the end (supports markup).
 *
 * ## Example:
 *
 * @code{.cpp}
 * tuipp::print("[bold green]Hello, World![/]");
 * @endcode
 *
 * ## Styles:
 *
 * - Foreground colors: `red`, `green`, `grey`, `blue`, `magenta`, `yellow`, `white`, `bright_red`,
 *   `bright_green`, `bright_grey`, `bright_blue`, `bright_magenta`, `bright_yellow`, `bright_cyan`,
 *   `bright_white`
 *
 * - Background colors: `bg_red`, `bg_green`, `bg_grey`, `bg_blue`, `bg_magenta`, `bg_yellow`,
 *   `bg_cyan`, `bg_white`
 *
 * - Effects: `bold`, `underline`, `blink`, `italic`
 *
 * - Reset: `/`
 *
 * ---
 *
 * You can also escape markup brackets using a backslash:
 *
 * @code{.cpp}
 * tuipp::println("\[bold red]Hello, World!\[/]");
 * @endcode
 *
 * @param string The string to be printed, it can be empty.
 */
void
print(const std::string& string = "");

} // namespace tuipp

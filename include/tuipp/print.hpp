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

#include <iostream>
#include <ostream>
#include <sstream>

#include "vendor/termcolor.hpp"

namespace tuipp {

enum class State
{
    TEXT,
    TAG
};

template<typename CharT>
std::basic_ostream<CharT>&
handle_styles(std::basic_ostream<CharT>& stream, const std::string& buffer)
{
    std::istringstream iss(buffer);
    std::string token;

    while (iss >> token) {
        if (token == "red") {
            stream << termcolor::red;
        } else if (token == "green") {
            stream << termcolor::green;
        } else if (token == "grey") {
            stream << termcolor::grey;
        } else if (token == "blue") {
            stream << termcolor::blue;
        } else if (token == "magenta") {
            stream << termcolor::magenta;
        } else if (token == "yellow") {
            stream << termcolor::yellow;
        } else if (token == "cyan") {
            stream << termcolor::cyan;
        } else if (token == "white") {
            stream << termcolor::white;
        } else if (token == "bg_red") {
            stream << termcolor::on_red;
        } else if (token == "bg_green") {
            stream << termcolor::on_green;
        } else if (token == "bg_grey") {
            stream << termcolor::on_grey;
        } else if (token == "bg_blue") {
            stream << termcolor::on_blue;
        } else if (token == "bg_magenta") {
            stream << termcolor::on_magenta;
        } else if (token == "bg_yellow") {
            stream << termcolor::on_yellow;
        } else if (token == "bg_cyan") {
            stream << termcolor::on_cyan;
        } else if (token == "bg_white") {
            stream << termcolor::on_white;
        } else if (token == "bright_red") {
            stream << termcolor::bright_red;
        } else if (token == "bright_green") {
            stream << termcolor::bright_green;
        } else if (token == "bright_grey") {
            stream << termcolor::bright_grey;
        } else if (token == "bright_blue") {
            stream << termcolor::bright_blue;
        } else if (token == "bright_magenta") {
            stream << termcolor::bright_magenta;
        } else if (token == "bright_yellow") {
            stream << termcolor::bright_yellow;
        } else if (token == "bright_cyan") {
            stream << termcolor::bright_cyan;
        } else if (token == "bright_white") {
            stream << termcolor::bright_white;
        } else if (token == "bold") {
            stream << termcolor::bold;
        } else if (token == "underline") {
            stream << termcolor::underline;
        } else if (token == "blink") {
            stream << termcolor::blink;
        } else if (token == "italic") {
            stream << termcolor::italic;
        } else if (token == "/") {
            stream << termcolor::reset;
        }
    }

    return stream;
}

template<typename CharT>
std::basic_ostream<CharT>&
parse_string(std::basic_ostream<CharT>& stream, const std::string& string)
{
    State state = State::TEXT;

    std::string buffer;

    char prev_char{};

    for (const char& c : string) {
        switch (state) {
            case State::TEXT: {
                if (c == '[' && prev_char != '\\') {
                    state = State::TAG;
                    buffer.clear();
                } else {
                    stream << c;
                }
            }
            case State::TAG: {
                if (c == ']') {
                    state = State::TEXT;

                    handle_styles(stream, buffer.erase(0, 1));
                } else {
                    buffer += c;
                }
            }
        }

        prev_char = c;
    }

    return stream;
}

/**
 * @brief Print a string with a new line at the end.
 *
 * @details Example:
 *
 * @code{.cpp}
 * tuipp::println("[bold red]Hello, World![/]");
 * @endcode
 *
 * @param string The string to be printed, it can be empty.
 */
inline void
println(const std::string& string = "")
{
    parse_string(std::cout, string) << '\n';
}

/**
 * @brief Print a string without a new line at the end.
 *
 * @details Example:
 *
 * @code{.cpp}
 * tuipp::print("[bold green]Hello, World![/]");
 * @endcode
 *
 * @param string The string to be printed, it can be empty.
 */
inline void
print(const std::string& string = "")
{
    parse_string(std::cout, string);
}

} // namespace tuipp

#pragma once

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

#include "vendor/termcolor.hpp"

namespace tuipp {

enum class Style
{
    RED,
    GREEN,
    GREY,
    BLUE,
    MAGENTA,
    YELLOW,
    CYAN,
    WHITE,
    BG_RED,
    BG_GREEN,
    BG_GREY,
    BG_BLUE,
    BG_MAGENTA,
    BG_YELLOW,
    BG_CYAN,
    BG_WHITE,
    BRIGHT_RED,
    BRIGHT_GREEN,
    BRIGHT_GREY,
    BRIGHT_BLUE,
    BRIGHT_MAGENTA,
    BRIGHT_YELLOW,
    BRIGHT_CYAN,
    BRIGHT_WHITE,
    BOLD,
    UNDERLINE,
    BLINK,
    ITALIC,
    RESET,
};

struct Styles
{
    std::vector<Style> styles{};

    template<typename CharT>
    std::basic_ostream<CharT>& apply_styles(std::basic_ostream<CharT>& stream)
    {
        for (const Style style : styles) {
            apply_style(stream, style);
        }

        return stream;
    }
};

inline const std::unordered_map<std::string, Style> token_to_style{
    { "red", Style::RED },
    { "green", Style::GREEN },
    { "grey", Style::GREY },
    { "gray", Style::GREY },
    { "blue", Style::BLUE },
    { "magenta", Style::MAGENTA },
    { "yellow", Style::YELLOW },
    { "cyan", Style::CYAN },
    { "white", Style::WHITE },
    { "on red", Style::BG_RED },
    { "on green", Style::BG_GREEN },
    { "on grey", Style::BG_GREY },
    { "on gray", Style::BG_GREY },
    { "on blue", Style::BG_BLUE },
    { "on magenta", Style::BG_MAGENTA },
    { "on yellow", Style::BG_YELLOW },
    { "on cyan", Style::BG_CYAN },
    { "on white", Style::BG_WHITE },
    { "bright red", Style::BRIGHT_RED },
    { "bright green", Style::BRIGHT_GREEN },
    { "bright grey", Style::BRIGHT_GREY },
    { "bright gray", Style::BRIGHT_GREY },
    { "bright blue", Style::BRIGHT_BLUE },
    { "bright magenta", Style::BRIGHT_MAGENTA },
    { "bright yellow", Style::BRIGHT_YELLOW },
    { "bright cyan", Style::BRIGHT_CYAN },
    { "bright white", Style::BRIGHT_WHITE },
    { "bold", Style::BOLD },
    { "underline", Style::UNDERLINE },
    { "blink", Style::BLINK },
    { "italic", Style::ITALIC },
    { "/", Style::RESET },
};

template<typename CharT>
std::basic_ostream<CharT>&
apply_style(std::basic_ostream<CharT>& stream, const Style style)
{
    switch (style) {
        case Style::RED:
            stream << termcolor::red;
            break;
        case Style::GREEN:
            stream << termcolor::green;
            break;
        case Style::GREY:
            stream << termcolor::grey;
            break;
        case Style::BLUE:
            stream << termcolor::blue;
            break;
        case Style::MAGENTA:
            stream << termcolor::magenta;
            break;
        case Style::YELLOW:
            stream << termcolor::yellow;
            break;
        case Style::CYAN:
            stream << termcolor::cyan;
            break;
        case Style::WHITE:
            stream << termcolor::white;
            break;
        case Style::BG_RED:
            stream << termcolor::on_red;
            break;
        case Style::BG_GREEN:
            stream << termcolor::on_green;
            break;
        case Style::BG_GREY:
            stream << termcolor::on_grey;
            break;
        case Style::BG_BLUE:
            stream << termcolor::on_blue;
            break;
        case Style::BG_MAGENTA:
            stream << termcolor::on_magenta;
            break;
        case Style::BG_YELLOW:
            stream << termcolor::on_yellow;
            break;
        case Style::BG_CYAN:
            stream << termcolor::on_cyan;
            break;
        case Style::BG_WHITE:
            stream << termcolor::on_white;
            break;
        case Style::BRIGHT_RED:
            stream << termcolor::bright_red;
            break;
        case Style::BRIGHT_GREEN:
            stream << termcolor::bright_green;
            break;
        case Style::BRIGHT_GREY:
            stream << termcolor::bright_grey;
            break;
        case Style::BRIGHT_BLUE:
            stream << termcolor::bright_blue;
            break;
        case Style::BRIGHT_MAGENTA:
            stream << termcolor::bright_magenta;
            break;
        case Style::BRIGHT_YELLOW:
            stream << termcolor::bright_yellow;
            break;
        case Style::BRIGHT_CYAN:
            stream << termcolor::bright_cyan;
            break;
        case Style::BRIGHT_WHITE:
            stream << termcolor::bright_white;
            break;
        case Style::BOLD:
            stream << termcolor::bold;
            break;
        case Style::UNDERLINE:
            stream << termcolor::underline;
            break;
        case Style::BLINK:
            stream << termcolor::blink;
            break;
        case Style::ITALIC:
            stream << termcolor::italic;
            break;
    }

    return stream;
}

template<typename CharT>
std::basic_ostream<CharT>&
handle_styles(std::basic_ostream<CharT>& stream,
              const std::string& buffer,
              std::vector<Styles>& styles)
{
    std::istringstream iss(buffer);

    std::string token{};

    std::vector<std::string> token_vec{};

    std::vector<Style> style_vec{};

    while (iss >> token) {
        token_vec.push_back(token);
    }

    for (int i = 0; i < token_vec.size(); ++i) {
        std::string buffer{ token_vec[i] };

        if (buffer == "on") {
            buffer = buffer + ' ' + token_vec[i + 1];

            ++i;
        } else if (buffer == "bright") {
            buffer = buffer + ' ' + token_vec[i + 1];

            ++i;
        }

        if (token_to_style.find(buffer) == token_to_style.end()) {
            std::cerr << '\n'
                      << termcolor::reset << '\"' << buffer << '\"' << " is not a valid style!"
                      << std::endl;

            std::exit(1);
        } else {
            Style style = token_to_style.at(buffer);

            if (style == Style::RESET) {
                styles.pop_back();

                stream << termcolor::reset;

                for (int i = 0; i < styles.size(); ++i) {
                    styles[i].apply_styles(stream);
                }
            } else {
                style_vec.push_back(style);
            }
        }
    }

    styles.emplace_back(style_vec);

    for (int i = 0; i < styles.size(); ++i) {
        styles[i].apply_styles(stream);
    }

    return stream;
}

} // namespace tuipp

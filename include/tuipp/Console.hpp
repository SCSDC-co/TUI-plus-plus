/**
 * @file Console.hpp
 *
 * @brief A class that represent a console and some other console utility
 *
 * @author Giuliano De Amicis
 */

#pragma once

#include <cstddef>

#include "private/macros.hpp"
#include "tuipp/print.hpp"

namespace tuipp {

/**
 * @brief This is the class that represent a console.
 *
 * ## Properties
 *
 * - TerminalSize: a struct that represent the dimensions of the console (width and height)
 *
 * - ColorSystem: an enum to represent the color system supported by the console
 *
 * ## Examples
 *
 * @code{.cpp}
 * tuipp::Console console{}; // creates the console
 *
 * console << "[green]Print to the screen using[/] << [green]operator overload![/]" << std::endl;
 * console << "you can" << "chain them!" << std::endl;
 *
 * console.print_info(true); // print the console properties in a nice format!
 * @endcode
 */
class Console
{
  public:
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

    TUIPP_NODISCARD TerminalSize get_terminal_size() const;
    TUIPP_NODISCARD ColorSystem get_color_support() const;

    /// @return the color support as a string
    TUIPP_NODISCARD std::string get_color_support_string() const;

    TUIPP_NODISCARD bool get_support_ansi() const;

    /// A utility to print the console info in a nice format
    void print_info(const bool& color) const;

    Console()
      : terminal_size(set_terminal_size())
      , color_support(set_color_support())
      , support_ansi(set_color_support()) {};

    /// A << operator overload made for printing things in the `std::cout` style
    template<typename T>
    Console& operator<<(const T& value)
    {
        print(value);

        return *this;
    }

    // wth is this
    /// A << operator overload made for printing stream manipulators like `std::endl`
    Console& operator<<(
      std::ostream& (*f)(std::ostream&) // some C shenanigans for accepting stream manipulators
    )
    {
        std::cout << f;

        return *this;
    }

  private:
    TerminalSize terminal_size{};
    ColorSystem color_support{};

    bool support_ansi{};

    TUIPP_NODISCARD TerminalSize set_terminal_size();
    TUIPP_NODISCARD ColorSystem set_color_support();
    TUIPP_NODISCARD bool set_support_ansi();
};

} // namespace tuipp

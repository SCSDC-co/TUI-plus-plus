/**
 * @file Console.hpp
 *
 * @brief A class that represent a console
 *
 * @author Giuliano De Amicis
 */

#pragma once

#include <cstddef>

#include "private/macros.hpp"

namespace tuipp {

class Console
{
  public:
    struct TerminalSize
    {
        std::size_t width{};
        std::size_t height{};
    };

    TUIPP_NODISCARD TerminalSize get_terminal_size();

    Console()
      : terminal_size(get_terminal_size()) {};

  private:
    TerminalSize terminal_size{};
};

} // namespace tuipp

/**
 * @file print.hpp
 *
 * @brief A utility for printing output to the screen.
 *
 * @author Giuliano De Amicis
 */

#pragma once

#include <string>

namespace tuipp {

/**
 * @brief Print a string with a new line at the end.
 *
 * @param string The string to be printed, it can be empty.
 */
void
println(const std::string& string = "");

/**
 * @brief Print a string without a new line at the end.
 *
 * @param string The string to be printed, it can be empty.
 */
void
print(const std::string& string = "");

} // namespace tuipp

#pragma once

#include <string>

namespace tuipp {

namespace console {

/**
 * Print a string with a new line at the end.
 *
 * @param string The string to be printed, it can be empty.
 */
void
println(const std::string& string = "");

/**
 * Print a string without a new line at the end.
 *
 * @param string The string to be printed, it can be empty.
 */
void
print(const std::string& string = "");

} // namespace console

} // namespace tuipp

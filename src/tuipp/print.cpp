#include "tuipp/print.hpp"

#include <iostream>

#include "./parse_string.hpp"

namespace tuipp {

void
println(const std::string& string)
{
    parse_string(std::cout, string) << '\n';
}

void
print(const std::string& string)
{
    parse_string(std::cout, string);
}

} // namespace tuipp

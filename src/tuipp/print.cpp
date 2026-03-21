#include "tuipp/print.hpp"

#include <iostream>
#include <string>

namespace tuipp {

void
println(const std::string& string)
{
    std::cout << string << '\n';
}

void
print(const std::string& string)
{
    std::cout << string;
}

} // namespace tuipp

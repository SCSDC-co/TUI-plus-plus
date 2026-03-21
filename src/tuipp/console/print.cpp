#include "tuipp/console/print.hpp"

#include <iostream>
#include <string>

namespace tuipp {

namespace console {

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

} // namespace console

} // namespace tuipp

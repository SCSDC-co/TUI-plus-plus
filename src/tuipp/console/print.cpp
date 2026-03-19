module;

#include <iostream>
#include <string>

export module tuipp.console;

export namespace tuipp {

namespace console {

void
println(const std::string& string = "")
{
    std::cout << string << '\n';
}

void
print(const std::string& string = "")
{
    std::cout << string;
}

} // namespace console

} // namespace tuipp

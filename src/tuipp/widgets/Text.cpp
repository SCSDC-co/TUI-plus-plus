#include "tuipp/widgets/Text.hpp"

#include <iostream>

namespace tuipp {

namespace widgets {

void
Text::render()
{
    std::cout << this->content;
}

} // namespace widgets

} // namespace tuipp

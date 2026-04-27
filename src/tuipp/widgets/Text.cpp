#include "tuipp/widgets/Text.hpp"

#include <iostream>

namespace tuipp {

namespace widgets {

void
Text::render() const
{
    std::cout << this->content;
}

} // namespace widgets

} // namespace tuipp

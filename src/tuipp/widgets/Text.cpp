#include "tuipp/widgets/Text.hpp"

#include <iostream>
#include <string>

#include "../src/vendor/termcolor.hpp"

namespace tuipp {

namespace widgets {

void
Text::render(const int& width) const
{
    std::ostream& output = std::cout;

    int padding{};

    switch (this->style.get_justification()) {
        case styles::Justification::LEFT:
            padding = 0;
            break;
        case styles::Justification::CENTER:
            padding = (width / 2) - (this->content.length() / 2);
            break;
        case styles::Justification::RIGHT:
            padding = (width - this->content.length());
            break;
    }

    output << std::string(padding, ' ');

    this->style.apply_background(output);
    this->style.apply_foreground(output);
    this->style.apply_effect(output);

    output << this->content;

    output << termcolor::reset;
}

int
Text::get_length(const int& width) const
{
    return this->content.length();
}

} // namespace widgets

} // namespace tuipp

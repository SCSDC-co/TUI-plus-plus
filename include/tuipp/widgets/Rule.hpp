#pragma once

#include <string>

#include "tuipp/styles/Border.hpp"
#include "tuipp/styles/Styles.hpp"
#include "tuipp/widgets/IRenderable.hpp"

namespace tuipp {

namespace widgets {

class Rule : public tuipp::widgets::IRenderable
{
  public:
    std::string fill_char{};

    styles::Style style;

    Rule(std::string content               = "",
         styles::border::BorderType border = styles::border::BorderType::SQUARE,
         styles::Style style               = styles::Style(styles::Foreground::NONE,
                                                           styles::Background::NONE,
                                                           { styles::Effects::NONE },
                                                           styles::Justification::LEFT))
      : content(content)
      , fill_char(
          styles::border::get_part_from_border_type(border, styles::border::BorderParts::TOP))
      , style(style)
    {
    }

    Rule(std::string content = "",
         styles::Style style = styles::Style(styles::Foreground::NONE,
                                             styles::Background::NONE,
                                             { styles::Effects::NONE },
                                             styles::Justification::LEFT))
      : content(content)
      , fill_char(styles::border::get_part_from_border_type(styles::border::BorderType::SQUARE,
                                                            styles::border::BorderParts::TOP))
      , style(style)
    {
    }

    Rule(styles::Style style = styles::Style(styles::Foreground::NONE,
                                             styles::Background::NONE,
                                             { styles::Effects::NONE },
                                             styles::Justification::LEFT))
      : content("")
      , fill_char(styles::border::get_part_from_border_type(styles::border::BorderType::SQUARE,
                                                            styles::border::BorderParts::TOP))
      , style(style)
    {
    }

    virtual void render(const int& width) const override;
    virtual int get_length(const int& width = 0) const override;

  private:
    std::string content{};
};

} // namespace widgets

} // namespace tuipp

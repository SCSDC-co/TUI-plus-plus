#pragma once

#include <string>

#include "tuipp/styles/Styles.hpp"
#include "tuipp/widgets/IRenderable.hpp"

namespace tuipp {

namespace widgets {

/**
 * @brief Just normal text!
 *
 * ## Examples of use
 *
 * @code{.cpp}
 * // Create the widget:
 * auto text = tuipp::widgets::Text("Text widget!");
 *
 * // 3 ways of rendering it:
 * tuipp::Console console;
 * console << text;
 *
 * tuipp::Console::println(text);
 *
 * text.render();
 * @endcode
 *
 * It also support styles:
 *
 * @code{.cpp}
 * auto colored_text =
 *   tuipp::widgets::Text("Colored text!",
 *                        tuipp::styles::Foreground::GREEN,
 *                        tuipp::styles::Background::GREY,
 *                        { tuipp::styles::Effects::BOLD });
 * @endcode
 */
class Text : public tuipp::widgets::IRenderable
{
  public:
    styles::Style style;

    Text(std::string content,
         styles::Style style = styles::Style(styles::Foreground::NONE,
                                             styles::Background::NONE,
                                             { styles::Effects::NONE },
                                             styles::Justification::LEFT))
      : content(content)
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

#pragma once

#include <string>
#include <vector>

#include "../../../src/tuipp/widgets/IRenderable.hpp"
#include "tuipp/widgets/styles/Background.hpp"
#include "tuipp/widgets/styles/Effects.hpp"
#include "tuipp/widgets/styles/Foreground.hpp"
#include "tuipp/widgets/styles/Justification.hpp"

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
 *                        tuipp::widgets::styles::Foreground::GREEN,
 *                        tuipp::widgets::styles::Background::GREY,
 *                        { tuipp::widgets::styles::Effects::BOLD });
 * @endcode
 */
class Text : public tuipp::widgets::IRenderable
{
  public:
    styles::Foreground foreground{};
    styles::Background background{};
    std::vector<styles::Effects> effects{};

    styles::Justification justification{};

    Text(std::string content,
         styles::Justification justification  = styles::Justification::LEFT,
         styles::Foreground foreground        = styles::Foreground::NONE,
         styles::Background background        = styles::Background::NONE,
         std::vector<styles::Effects> effects = { styles::Effects::NONE })
      : content(content)
      , justification(justification)
      , foreground(foreground)
      , background(background)
      , effects(effects)
    {
    }

    virtual void render() const;

  private:
    std::string content{};
};

} // namespace widgets

} // namespace tuipp

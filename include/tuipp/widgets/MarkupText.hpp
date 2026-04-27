#pragma once

#include <string>

#include "../../../src/tuipp/widgets/IRenderable.hpp"

namespace tuipp {

namespace widgets {

class MarkupText : tuipp::widgets::IRenderable
{
  public:
    MarkupText(std::string content)
      : content(content)
    {
    }

    virtual void render();

  private:
    std::string content{};
};

} // namespace widgets

} // namespace tuipp

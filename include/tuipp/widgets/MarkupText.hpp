#pragma once

#include <string>

#include "../../../src/tuipp/widgets/IRenderable.hpp"

namespace tuipp {

namespace widgets {

class MarkupText : public tuipp::widgets::IRenderable
{
  public:
    MarkupText(std::string content)
      : content(content)
    {
    }

    virtual void render() const;

  private:
    std::string content{};
};

} // namespace widgets

} // namespace tuipp

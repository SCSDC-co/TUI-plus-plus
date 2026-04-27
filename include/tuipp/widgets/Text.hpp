#pragma once

#include <string>

#include "../../../src/tuipp/widgets/IRenderable.hpp"

namespace tuipp {

namespace widgets {

class Text : public tuipp::widgets::IRenderable
{
  public:
    Text(std::string content)
      : content(content)
    {
    }

    virtual void render() const;

  private:
    std::string content{};
};

} // namespace widgets

} // namespace tuipp

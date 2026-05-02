#pragma once

#include <vector>

#include "tuipp/styles/Border.hpp"
#include "tuipp/styles/Styles.hpp"
#include "tuipp/widgets/IRenderable.hpp"

namespace tuipp {

namespace widgets {

class Panel : public IRenderable
{
  public:
    styles::border::BorderType border{};

    styles::Foreground border_color{};

    Panel(std::string header,
          styles::border::BorderType border = styles::border::BorderType::SQUARE,
          styles::Foreground border_color   = styles::Foreground::NONE)
      : header(header)
      , border(border)
      , border_color(border_color)
    {
    }

    void add_element(IRenderable& item);

    virtual void render(const int& width) const override;
    virtual int get_length(const int& width = 0) const override;

  private:
    std::string header{};
    std::vector<IRenderable*> childrens{};
};

} // namespace widgets

} // namespace tuipp

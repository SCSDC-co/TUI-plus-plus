#pragma once

namespace tuipp {

// this is a namespace just for the source code of TUI++, it shouldn't be exposed
namespace widgets {

// This is the interface where all the widgets should derive from
class IRenderable
{
  public:
    virtual void render() = 0;
};

} // namespace widgets

} // namespace tuipp

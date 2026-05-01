#pragma once

namespace tuipp {

namespace widgets {

/// The base class for every widgets, exposed so you can create your own!
class IRenderable
{
  public:
    virtual void render(const int& width) const = 0;

    // i know this may look silly, but it's for getting the right length for the rule widget
    virtual int get_length(const int& width = 0) const = 0;

    virtual ~IRenderable() = default;
};

} // namespace widgets

} // namespace tuipp

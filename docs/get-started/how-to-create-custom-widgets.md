# How to create custom widgets

TUI++ exposes `IRenderable`, an interface that you can use for creating widgets.

```cpp:line-numbers
#include <tuipp/widgets/IRenderable.hpp>
#include <tuipp/Console.hpp>
#include <tuipp/colors.hpp>

class MyWidget : public tuipp::widgets::IRenderable
{
  public:
    std::string content{};

    MyWidget(std::string content) : content(content) {}

    // you need to provide an implementation for render
    virtual void render() const {
      std::cout << tuipp::colors::red << content
                << tuipp::colors::reset << std::endl;
    }
};

int main() {
  auto widget = MyWidget("hello!");

  // Console::println automatically calls render()
  tuipp::Console::println(widget);

  return 0;
}
```

Output: <code style="color: red">hello!</code>

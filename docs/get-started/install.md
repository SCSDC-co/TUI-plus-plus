# Install the library

Since the library is still WIP you can install it in your project using `CMake` `FetchContent`:

```cmake:line-numbers
include(FetchContent)

FetchContent_Declare(
    tuipp
    GIT_REPOSITORY https://github.com/SCSDC-co/tuipp.git
    GIT_TAG main
)

FetchContent_MakeAvailable(tuipp)

target_link_libraries(MyTarget PUBLIC tuipp)
```

Then you can use it:

```cpp:line-numbers
#include <tuipp/Console.hpp>

int main() {
  tuipp::Console::println("[green]It's working![/]");

  return 0;
}
```

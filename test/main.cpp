#include <vector>

#include "tuipp/Console.hpp"
#include "tuipp/widgets/MarkupText.hpp"
#include "tuipp/widgets/Text.hpp"
#include "tuipp/widgets/styles/Background.hpp"
#include "tuipp/widgets/styles/Effects.hpp"
#include "tuipp/widgets/styles/Foreground.hpp"
#include "tuipp/widgets/styles/Justification.hpp"

int
main()
{
    std::vector<int> vector{ { 1, 2, 3, 4, 5, 6 } };

    tuipp::widgets::Text text = tuipp::widgets::Text("Text widget!");
    tuipp::widgets::MarkupText markup_text =
      tuipp::widgets::MarkupText("[bold][green]Markup[/] [blue]text[/][red]![/][/]");

    auto styled_text = tuipp::widgets::Text("Styled text widget!",
                                            tuipp::widgets::styles::Justification::LEFT,
                                            tuipp::widgets::styles::Foreground::GREEN,
                                            tuipp::widgets::styles::Background::GREY,
                                            { tuipp::widgets::styles::Effects::BOLD });

    tuipp::Console::println(styled_text);

    styled_text.justification = tuipp::widgets::styles::Justification::CENTER;

    tuipp::Console::println(styled_text);

    styled_text.justification = tuipp::widgets::styles::Justification::RIGHT;

    tuipp::Console::println(styled_text);

    tuipp::Console::println("Print function:");
    tuipp::Console::println("  [green on grey]Colors![/]");
    tuipp::Console::println("  [underline bold]Styles![/]");
    tuipp::Console::println("  Normal text!");
    tuipp::Console::println("  [[You can escape the markup!]]");
    tuipp::Console::println("  [green]Can print anything: [/]", vector);

    tuipp::Console::println();

    tuipp::Console::println("Widgets:");
    tuipp::Console::println("  ", text);
    tuipp::Console::println("  ", markup_text);

    return 0;
}

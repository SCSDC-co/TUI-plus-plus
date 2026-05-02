#include "tuipp/Console.hpp"
#include "tuipp/styles/Border.hpp"
#include "tuipp/styles/Styles.hpp"
#include "tuipp/widgets/MarkupText.hpp"
#include "tuipp/widgets/Panel.hpp"
#include "tuipp/widgets/Rule.hpp"
#include "tuipp/widgets/Text.hpp"

int
main()
{
    auto panel = tuipp::widgets::Panel(" [green]Panel[/] ",
                                       tuipp::styles::border::BorderType::ROUNDED,
                                       tuipp::styles::Foreground::GREEN);

    auto text         = tuipp::widgets::Text("Text!");
    auto colored_text = tuipp::widgets::Text(
      "Colored text!",
      tuipp::styles::Style(tuipp::styles::Foreground::GREEN, tuipp::styles::Background::GREY));
    auto markup_text = tuipp::widgets::MarkupText("[green]Markup Text![/]");
    auto long_text   = tuipp::widgets::Text("The quick brown fox jumps over the lazy dog.");
    auto long_text_2 = tuipp::widgets::Text(
      "\"Success is not final, failure is not fatal: it is the courage to continue that counts.\"");
    auto long_text_3      = tuipp::widgets::Text("\"If you are going through hell, keep going.\"");
    auto wiston_churchill = tuipp::widgets::Text(" - Wiston Churchill");

    auto rule = tuipp::widgets::Rule(tuipp::styles::Style(tuipp::styles::Foreground::GREEN));

    panel.add_element(text);
    panel.add_element(markup_text);
    panel.add_element(long_text);
    panel.add_element(rule);
    panel.add_element(long_text_2);
    panel.add_element(long_text_3);
    panel.add_element(wiston_churchill);
    panel.add_element(rule);
    panel.add_element(colored_text);

    tuipp::Console::println(panel);

    return 0;
}

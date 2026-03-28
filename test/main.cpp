#include <iostream>
#include <string>

#include "tuipp/Console.hpp"
#include "tuipp/print.hpp"

int
main()
{
    tuipp::println("[red bold]Hello,[/] [green]World![/]");
    tuipp::println("[green bold]Hello,[/] [cyan]World![/]");

    tuipp::println("[green]This is green [bold]this is bold and green[/] this is still green[/]");

    tuipp::println("\\[bold]Hello, World!\\[/]");

    tuipp::Console console{};

    std::cout << console.get_terminal_size().width << "x" << console.get_terminal_size().height
              << std::endl;

    return 0;
}

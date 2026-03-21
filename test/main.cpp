#include "tuipp/print.hpp"

int
main()
{
    tuipp::println("[red bold]Hello,[/] [green]World![/]");
    tuipp::println("[green bold]Hello,[/] [cyan]World![/]");

    tuipp::println("\\[bold]Hello, World!\\[/]");

    return 0;
}

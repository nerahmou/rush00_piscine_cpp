#include "ft_retro.hpp"

bool usage(void)
{
	std::cout << "./ft_retro [name]" << std::endl;
	return (1);
}

int main(int argc, const char *argv[])
{
	(void)argv;
	if (argc != 2)
		return (usage());
	initscr();
	move(LINES - 1, COLS - 1);
	addch('.');
	//refresh();
	getch();
	endwin();
	return 0;
}

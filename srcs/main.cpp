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
	WINDOW *mapWindow;
	WINDOW *statusWindow;

	initscr();
	mapWindow = subwin(stdscr, LINES / 1.2, COLS, 0, 0);
	statusWindow = subwin(stdscr, LINES / 1.2, COLS, LINES / 1.2, 0);

	box(mapWindow, ACS_VLINE, ACS_HLINE);
	box(statusWindow, ACS_VLINE, ACS_HLINE);

	mvwprintw(mapWindow, 1, 1, "Map");
	mvwprintw(statusWindow, 1, 1, "Status");

	wrefresh(mapWindow);
	wrefresh(statusWindow);
	
	getch();
	endwin();

	free(mapWindow);
	free(statusWindow);
	return 0;
}

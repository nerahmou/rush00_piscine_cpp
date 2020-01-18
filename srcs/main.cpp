#include "ft_retro.hpp"

bool usage(void)
{
	std::cout << "./ft_retro [name]" << std::endl;
	return (1);
}

int main(int argc, const char *argv[])
{
	Windows	win;

	(void)argv;
	if (argc != 2)
		return (usage());
	win.printBorder();
	win.setCursor(20, 20);
	win.updateEvent();
	if (win.buttonsPressed(BUTTON_UP))
		
	// getch();
	endwin();
	return 0;
}

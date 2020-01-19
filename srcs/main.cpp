/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 21:12:16 by cpieri            #+#    #+#             */
/*   Updated: 2020/01/19 13:05:17 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_retro.hpp"

bool usage(void)
{
	std::cout << "./ft_retro [name]" << std::endl;
	return (1);
}

int main(int argc, const char *argv[])
{
	std::srand(std::time(NULL));
	Windows	win;
	Player	player("Louise");
	Enemy	enemy;
	Enemy	enemy1;
	Enemy	enemy2;

	(void)argv;
	if (argc != 2)
		return (usage());
	win.printBorder();
	win.setCursor(20, 20);
	win.printGameEntity(player);
	win.printGameEntity(enemy);
	win.printGameEntity(enemy1);
	win.printGameEntity(enemy2);
	win.updateEvent();
	if (win.buttonsPressed(BUTTON_UP))
		std::cout << "lol" << std::endl;
	endwin();
	return 0;
}

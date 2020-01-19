/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 21:12:16 by cpieri            #+#    #+#             */
/*   Updated: 2020/01/19 14:15:02 by cpieri           ###   ########.fr       */
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
	int		ch = 0;
	Player	player("Louise");
	Enemy	enemy;
	Enemy	enemy1;
	Enemy	enemy2;

	(void)argv;
	if (argc != 2)
		return (usage());
	while (ch != 'q') {
		win.refresh();
		win.printBorder();
		win.printGameEntity(player);
		win.printGameEntity(enemy);
		win.printGameEntity(enemy1);
		win.printGameEntity(enemy2);
		enemy.setPosX(enemy.getPosX() - 1);
		enemy1.setPosX(enemy1.getPosX() - 1);
		enemy2.setPosX(enemy2.getPosX() - 1);
		ch = getch();
		if (ch == 'd') {
			player.setPosX(player.getPosX() + 1);
		}
		if (ch == 'a') {
			player.setPosX(player.getPosX() - 1);
		}
		if (ch == 's') {
			player.setPosY(player.getPosY() + 1);
		}
		if (ch == 'w') {
			player.setPosY(player.getPosY() - 1);
		}
		if (ch == ' ') {
			player.setPosY(99);
		}
	}
	endwin();
	return 0;
}

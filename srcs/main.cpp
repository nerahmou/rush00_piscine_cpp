/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 21:12:16 by cpieri            #+#    #+#             */
/*   Updated: 2020/01/19 15:49:20 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_retro.hpp"

bool usage(void)
{
	std::cout << "./ft_retro [name]" << std::endl;
	return (1);
}

// void	checkColision(Player const & player, Enemy * enemies) {
// }

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
		// checkColision(player, nullptr);
		while (win.update());
		win.refresh();
		win.printBorder();
		win.printGameEntity(player);
		win.printGameEntity(enemy);
		win.printGameEntity(enemy1);
		win.printGameEntity(enemy2);
		enemy.setPosX(enemy.getPosX() - 1);
		enemy1.setPosX(enemy1.getPosX() - 1);
		enemy2.setPosX(enemy2.getPosX() - 1);
		win.pressedKey(ch, player);
	}
	endwin();
	return 0;
}

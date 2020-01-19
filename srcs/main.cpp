/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 21:12:16 by cpieri            #+#    #+#             */
/*   Updated: 2020/01/19 18:24:14 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                                            */
/* ************************************************************************** */

#include "ft_retro.hpp"

bool usage(void)
{
	std::cout << "./ft_retro [name]" << std::endl;
	return (1);
}

void	checkColision(Player const & player, Enemy * enemies) {
	(void)player;
	(void)enemies;
}

int main(int argc, const char *argv[])
{
	if (argc != 2)
		return (usage());
	std::srand(std::time(NULL));
	int		ch = 0;
	Windows	win;
	Player	player(argv[1]);
	Missile	*missile = NULL;
	Enemy *enemies = NULL;
	Enemy::push(&enemies);


	while (ch != 'q') {
		checkColision(player, nullptr);
		win.refresh();
		win.printBorder();
		win.printGameEntity(player);
		if (missile)
			win.printMissile(&missile);
		//Il faudrai iterer sur les enemies
		win.printGameEntity(*enemies);
		enemies->setPosX(enemies->getPosX() - 1);
		win.pressedKey(ch, player, &enemies, missile);
		//Ajoute ennemie random a chaque tour
		Enemy::push(&enemies);
		while (win.update());
	}
	endwin();
	return 0;
}

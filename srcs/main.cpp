#include "ft_retro.hpp"
#include <iostream>
#include <fstream>

bool usage(void)
{
	std::cout << "./ft_retro [name]" << std::endl;
	return (1);
}

void	checkColision(Windows & win, Player & player, Enemy * enemies) {
	Enemy * cpyList = enemies;
	uint playerX, playerY, enemyX, enemyY = 0;

	while (cpyList) {
		playerX = win.getWidth() * player.getPosX() / 100;
		playerY = win.getHeight() * player.getPosY() / 100;
		enemyX = win.getWidth() * cpyList->getPosX() / 100;
		enemyY = win.getHeight() * cpyList->getPosY() / 100;
		if (playerY == enemyY && playerX + 1 == enemyX) {
			player.setLife(player.getLife() - 1);
			if (player.getLife() == 0) {
				win.loop = false;
				std::cout << "Game Over " << player.getName() << std::endl;
				return ;
			}
		}
		cpyList = cpyList->next;
	}
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
	while (win.loop != false) {
		//Ajoute ennemie random a chaque tour
		Enemy::push(&enemies);
		checkColision(win, player, enemies);
		win.refresh();
		win.printBorder();
		win.printGameEntity(player);
		win.pressedKey(ch, player, &enemies, &missile);
		if (missile) {
			win.printMissile(missile);
			delete missile;
			missile = nullptr;
		}
		Enemy::moveEnemies(&enemies);
		win.printEnemies(enemies);
		while (win.update());
	}
	endwin();
	Enemy::clear(&enemies);
	std::cout << player.getXp() << std::endl;
	return 0;
}

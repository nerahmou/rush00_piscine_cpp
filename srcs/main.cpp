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
	Enemy::push(&enemies);
	Enemy::push(&enemies);
	Enemy::push(&enemies);
	Enemy::push(&enemies);
	Enemy::push(&enemies);
	Enemy::push(&enemies);
	Enemy::push(&enemies);
	while (ch != 'q') {
		//Ajoute ennemie random a chaque tour
		checkColision(player, nullptr);
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

#include "Player.hpp"
#include <fstream>

Player::Player(std::string name):
	Person(PLAYER_DEFAULT_POS_X, PLAYER_DEFAULT_POS_Y,
			PLAYER_LIMIT_MIN_X, PLAYER_LIMIT_MAX_X,
			COLOR_PLAYER, PLAYER_LIFE, PLAYER_XP, PLAYER_CHAR),
	_name(name)
{}

Player::~Player(void)
{}

void Player::shot(Enemy ** enemies, Missile** missile)
{
	Enemy* ennemy = *enemies;
	Enemy * tmp = NULL;

	*missile = new Missile(this->getPosX() + 1, this->getPosY());
	while (ennemy)
	{
		tmp = ennemy->next;
		if (this->getPosY() == ennemy->getPosY())
		{
			if (ennemy->takeDamage((*missile)->getDamage()))
			{
				this->setXp(this->getXp() + ennemy->getXp());
				Enemy::pop(enemies, ennemy);
			}
		}
		ennemy = tmp;
	}
}

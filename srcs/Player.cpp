#include "Player.hpp"

Player::Player(std::string name):
	Person(PLAYER_DEFAULT_POS_X, PLAYER_DEFAULT_POS_Y,
			PLAYER_LIMIT_MIN_X, PLAYER_LIMIT_MAX_X,
			COLOR_PLAYER, PLAYER_LIFE, PLAYER_XP, PLAYER_CHAR),
	_name(name)
{}

Player::~Player(void)
{}

/*
 * Prend une liste d'énemies en parametre et renvoie la nouvelle liste d'enemies
 * apres avoir enlevé la vie de l'enemi si touché. Si l'ennemi n'a plus de vie, on le pop de la liste
 */
void Player::shot(Enemy ** enemies, Missile* missile)
{
	Enemy* ennemy = *enemies;

	missile = new Missile(this->getPosX() + 1, this->getPosY());
	while (ennemy)
	{
		if (this->getPosX() == ennemy->getPosX())
			if (ennemy->takeDamage(missile->getDamage()))
			{
				this->setXp(this->getXp() + ennemy->getXp());
				Enemy::pop(ennemy);
			}
		ennemy = ennemy->next;
	}
}

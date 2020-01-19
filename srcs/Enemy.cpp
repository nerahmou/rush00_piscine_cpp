#include "Enemy.hpp"

ENEMY_LEVEL enemies_level[NB_LEVEL] = {EASY_ENEMY, MEDIUM_ENEMY, HARD_ENEMY};
unsigned enemies_colors[NB_LEVEL] = {COLOR_GREEN, COLOR_RED, COLOR_BLACK};

Enemy::Enemy(void) : Person()
{
	unsigned randomNumber;
	unsigned positionY;
	unsigned color;
	unsigned life;
	unsigned xp;

	randomNumber = std::rand() % NB_LEVEL;
	life = randomNumber;
	xp = randomNumber * 5;
	positionY = std::rand() % GAME_ENTITY_LIMIT_MAX_Y;
	color = enemies_colors[randomNumber];
	this->setPosX(ENEMY_DEFAULT_POS_X);
	this->setPosY(positionY);
	this->setLimitMinX(ENEMY_LIMIT_MIN_X);
	this->setLimitMaxX(ENEMY_LIMIT_MAX_X);
	this->setColor(color);
	this->setLife(life);
	this->setXp(xp);
}

Enemy::~Enemy(void)
{}


Enemy * Enemy::pop(Enemy *enemy)
{
	Enemy* tmp;

	tmp = enemy;
	enemy = enemy->next;
	enemy->prev = tmp;
	if (tmp->prev)
		tmp->prev->next = enemy;
	delete tmp;
	return enemy;
}

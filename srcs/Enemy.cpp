#include "Enemy.hpp"

ENEMY_LEVEL enemies_level[NB_LEVEL] = {EASY_ENEMY, MEDIUM_ENEMY, HARD_ENEMY};
unsigned enemies_colors[NB_LEVEL] = {COLOR_ENEMY_EASY, COLOR_ENEMY_MED, COLOR_ENEMY_HARD};
char enemies_char[NB_LEVEL] = {'+', '%', '$'};

Enemy::Enemy(unsigned posX, unsigned posY) : Person() {
	unsigned randomNumber;
	unsigned color;
	unsigned life;
	unsigned xp;
	char		c;

	randomNumber = std::rand() % NB_LEVEL;
	life = randomNumber;
	xp = randomNumber * 5;
	color = enemies_colors[randomNumber];
	c = enemies_char[randomNumber];
	this->setLimitMinX(ENEMY_LIMIT_MIN_X);
	this->setLimitMaxX(ENEMY_LIMIT_MAX_X);
	this->setPosX(posX);
	this->setPosY(posY);
	this->setColor(color);
	//this->setLife(life);
	this->setLife(1);
	this->setXp(xp);
	this->setChar(c);
}

Enemy::Enemy(void) : Person()
{
	unsigned randomNumber;
	unsigned positionY;
	unsigned color;
	unsigned life;
	unsigned xp;
	char	c;

	randomNumber = std::rand() % (NB_LEVEL);
	life = randomNumber;
	xp = randomNumber * 5;
	positionY = std::rand() % GAME_ENTITY_LIMIT_MAX_Y;
	color = enemies_colors[randomNumber];
	c = enemies_char[randomNumber];
	this->setLimitMinX(ENEMY_LIMIT_MIN_X);
	this->setLimitMaxX(ENEMY_LIMIT_MAX_X);
	this->setPosX(ENEMY_DEFAULT_POS_X);
	this->setPosY(positionY);
	this->setColor(color);
	this->setLife(life);
	this->setXp(xp);
	this->setChar(c);
}

Enemy::~Enemy(void)
{}

void Enemy::moveEnemies(Enemy ** enemies) {
	Enemy * enemy = *enemies;
	Enemy * tmp = NULL;

	while (enemy)
	{
		enemy->setPosX(enemy->getPosX() - 1);
		tmp = enemy->next;
		if (enemy->getPosX() == 1)
			Enemy::pop(enemies, enemy);
		enemy = tmp;
	}
}

void Enemy::push(Enemy **begin)
{
	Enemy *head = *begin;
	Enemy * newEnemy = new Enemy;

	newEnemy->prev = NULL;
	newEnemy->next = NULL;
	if (*begin == NULL)
		*begin = newEnemy;
	else
	{
		while (head->next)
			head = head->next;
		head->next = newEnemy;
		newEnemy->prev = head;
	}
}

void Enemy::pop(Enemy **begin, Enemy *to_del)
{
	Enemy* next = to_del->next;
	Enemy* prev = to_del->prev;

	if (next)
		next->prev = prev;
	if (prev)
		prev->next = next;
	delete to_del;
	if (to_del == *begin)
		*begin = next;
}

#include "Person.hpp"

Person::Person(unsigned posX, unsigned posY, unsigned limitMinX, unsigned limitMaxX, unsigned color, unsigned life, unsigned xp):
	GameEntity(posX, posY, limitMinX, limitMaxX, color), _limitMinX(limitMinX), _limitMaxX(limitMaxX), _life(life), _xp(xp)
{}


Person::Person(void) : GameEntity()
{}

Person::~Person(void)
{}

unsigned Person::getLife(void) const
{
	return this->_life;
}

unsigned Person::getXp(void) const
{
	return this->_xp;
}

bool Person::setLife(unsigned life)
{
	this->_life = life;
	return 0;
}

bool Person::setXp(unsigned xp)
{
	this->_xp = xp;
	return 0;
}

bool Person::takeDamage(unsigned damage)
{
	if ((int)this->_life - (int)damage < 0)
		this->_life = 0;
	else
			this->_life -= damage;
	return 0;
}

#include "Missile.hpp"

Missile::Missile(unsigned posX, unsigned posY):
	GameEntity(posX, posY, 0, 0, MISSILE_COLOR, MISSILE_CHAR), _damage(MISSILE_DAMAGE), _len(COLS / 2)
{}

Missile::~Missile(void)
{}

unsigned Missile::getDamage(void) const
{
	return this->_damage;
}

unsigned Missile::getLen(void) const
{
	return this->_len;
}

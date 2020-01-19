#include "Missile.hpp"

Missile::Missile(unsigned posX, unsigned posY):
	GameEntity(posX, posY, 0, 0, MISSILE_COLOR, MISSILE_CHAR), _damage(MISSILE_DAMAGE), _len(0)
{}

Missile::~Missile(void)
{}

unsigned Missile::getDamage(void) const
{
	return this->_damage;
}

#include "Missile.hpp"

Missile::Missile(void):
	GameEntity(0, 0, 0, 0, MISSILE_COLOR, MISSILE_CHAR), _damage(MISSILE_DAMAGE), _len(0), _used(0)
{}

Missile::~Missile(void)
{}

unsigned Missile::getDamage(void) const
{
	return this->_damage;
}

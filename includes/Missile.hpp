#ifndef MISSILE_HPP
# define MISSILE_HPP

#include "GameEntity.hpp"

#define MISSILE_COLOR COLOR_MAGENTA
#define MISSILE_CHAR '-'
#define MISSILE_DAMAGE 1

class Missile : public GameEntity
{
	public:
		Missile(unsigned posX, unsigned posY);
		virtual ~Missile(void);
		unsigned getDamage(void)const;
		unsigned getLen(void)const;
	private:
		Missile(void);
		Missile(Missile const &);
		Missile & operator=(Missile const &);
		unsigned _damage;
		unsigned _len;
};
#

#endif

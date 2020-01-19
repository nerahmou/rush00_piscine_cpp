#ifndef MISSILE_HPP
# define MISSILE_HPP

#include "GameEntity.hpp"

#define MISSILE_COLOR COLOR_MAGENTA
#define MISSILE_CHAR '-'
#define MISSILE_DAMAGE 1

class Missile : public GameEntity
{
	public:
		Missile(void);
		Missile(unsigned posX, unsigned posY, unsigned limitMinX, unsigned limitMaxX, unsigned color, unsigned life, unsigned xp, char c);
		virtual ~Missile(void);
		unsigned getDamage(void)const;
	private:
		Missile(Missile const &);
		Missile & operator=(Missile const &);
		unsigned _damage;
		unsigned _len;
		bool _used; //si le missile a ete lancé
};
#

#endif

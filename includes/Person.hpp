#ifndef PERSON_HPP
# define PERSON_HPP

#include "GameEntity.hpp"

class Person : public GameEntity
{
	public:
		Person(void);
		Person(unsigned posX, unsigned posY, unsigned limitMinX, unsigned limitMaxX, unsigned color, unsigned life, unsigned xp);
		virtual ~Person(void);
		unsigned getLife(void) const;
		unsigned getXp(void) const;
		bool setLife(unsigned);
		bool setXp(unsigned);
		bool takeDamage(unsigned);
	private:
		Person(Person const &);
		Person & operator=(Person const &);

		unsigned _limitMinX;
		unsigned _limitMaxX;
		unsigned _life;
		unsigned _xp;
};
#endif

#ifndef ENEMY_HPP
# define ENEMY_HPP

#include "ft_retro.hpp"
#include "Person.hpp"

#define ENEMY_LIMIT_MIN_X 0
#define ENEMY_LIMIT_MAX_X 100
#define ENEMY_DEFAULT_POS_X ENEMY_LIMIT_MAX_X

enum ENEMY_LEVEL
{
	EASY_ENEMY,
	MEDIUM_ENEMY,
	HARD_ENEMY,
	NB_LEVEL
};

class Enemy: public Person
{
	public:
		Enemy(unsigned posX, unsigned posY);
		virtual ~Enemy(void);
	private:
		Enemy(void);
		Enemy(Enemy const &);
		Enemy & operator=(Enemy const &);
};

#endif

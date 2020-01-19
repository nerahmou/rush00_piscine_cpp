#ifndef ENEMY_HPP
# define ENEMY_HPP

//#include "ft_retro.hpp"
#include "Person.hpp"

#define ENEMY_LIMIT_MIN_X 0
#define ENEMY_LIMIT_MAX_X 100
#define ENEMY_DEFAULT_POS_X ENEMY_LIMIT_MAX_X - 1

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
		Enemy(void);
		virtual ~Enemy(void);
		Enemy* prev;
		Enemy* next;
		static void pop(Enemy**, Enemy *);
		static void push(Enemy **begin);
		static void	moveEnemies(Enemy ** enemies);
		static void clear(Enemy **enemies);
	private:
		Enemy(Enemy const &);
		Enemy & operator=(Enemy const &);
};


#endif


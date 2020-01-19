#ifndef DECORE_HPP
# define DECORE_HPP

#include "ft_retro.hpp"
#include "GameEntity.hpp"

#define DECORE_LIMIT_MIN_X 0
#define DECORE_LIMIT_MAX_X 100
#define DECORE_COLOR COLOR_YELLOW
#define DECORE_CHAR '*'

class Decore: public GameEntity
{
	public:
		Decore(unsigned posX, unsigned posY);
		virtual ~Decore(void);
	private:
		Decore(void);
		Decore(Decore const &);
		Decore & operator=(Decore const &);
};

#endif

#ifndef GAME_ENTITY_HPP
# define GAME_ENTITY_HPP

#include "ft_retro.hpp"

#define GAME_ENTITY_SIZE_X 1
#define GAME_ENTITY_SIZE_Y 1
#define GAME_ENTITY_LIMIT_MIN_Y 0
#define GAME_ENTITY_LIMIT_MAX_Y 100


class GameEntity
{
	public:
		GameEntity(void);
		GameEntity(unsigned posX, unsigned posY, unsigned limitMinX, unsigned limitMaxX, unsigned color);
		virtual ~GameEntity(void);

		unsigned getPosX(void) const;
		unsigned getPosY(void) const;
		unsigned getSizeX(void) const;
		unsigned getSizeY(void) const;
		unsigned getLimitMinX(void) const;
		unsigned getLimitMaxX(void) const;
		unsigned getColor(void) const;
		bool setPosX(unsigned);
		bool setPosY(unsigned);
		bool setSizeX(unsigned);
		bool setSizeY(unsigned);
		bool setLimitMinX(unsigned);
		bool setLimitMaxX(unsigned);
		bool setColor(unsigned);
	private:
		GameEntity(GameEntity const &);
		GameEntity & operator=(GameEntity const &);

		unsigned _posX;
		unsigned _posY;
		unsigned _sizeX;
		unsigned _sizeY;
		unsigned _limitMinX;
		unsigned _limitMaxX;
		unsigned _color;
};

#endif

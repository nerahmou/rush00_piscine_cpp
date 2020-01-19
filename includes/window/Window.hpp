#ifndef WINDOW_HPP
# define WINDOW_HPP

# include "../GameEntity.hpp"
# include "../Enemy.hpp"
# include "../Missile.hpp"
# include "../Player.hpp"
# include <iostream>
# include <sstream>
#include <cstdio>
# include <ncurses.h>

class Windows
{
private:
	WINDOW *	_win;
	uint		_width;
	uint		_height;
	uint		_key;
	int			_time;
	int			_timeSavedA;
	int			_timeSavedB;


	Windows(Windows const & src);

public:
	bool	loop;
	// bool	frameEndFlag;
	// size_t	frameCount;

	Windows(void);
	~Windows(void);

	void				refresh(void);
	void				buttonsUpdate(void);
	bool				update(void);
	bool				pressed(uint key);

	/*
	**	Print Functions
	*/
	void				printBorder(void);
	void				printGameEntity(GameEntity const & toPrint);
	void				printMissile(Missile* missile);
	void				printEnemies(Enemy * enemies);

	/*
	**	Get Functions
	*/
	WINDOW *			getWin(void) const;
	uint				getKey(void) const;
	uint				getHeight(void) const;
	uint				getWidth(void) const;

	/*
	**	Set Functions
	*/
	void				setCursor(uint x, uint y);

	bool				pressedKey(int& ch, Player & player, Enemy ** enemies, Missile ** missile);
	Windows const &		operator=(Windows const & rhs);
};


#endif

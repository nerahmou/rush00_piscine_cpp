/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Window.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 14:09:07 by cpieri            #+#    #+#             */
/*   Updated: 2020/01/19 16:03:34 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_HPP
# define WINDOW_HPP

# include "../GameEntity.hpp"
// # include "../Player.hpp"
# include <iostream>
# include <ctime>
# include <ncurses.h>

# define TIMEPERFRAME	40
# define BUTTON_RIGHT	68
# define BUTTON_LEFT	67
# define BUTTON_UP		65
# define BUTTON_DOWN	66

class Windows
{
private:
	WINDOW *	_win;
	uint		_width;
	uint		_height;
	// uint		_key;
	int			_time;


	Windows(Windows const & src);

public:
	bool	frameEndFlag;
	size_t	frameCount;

	Windows(void);
	~Windows(void);

	void				refresh(void);
	bool				update(void);
	/*
	**	Print Functions
	*/
	void				printBorder(void);
	void				printGameEntity(GameEntity const & toPrint);

	/*
	**	Get Functions
	*/
	WINDOW *			getWin(void) const;
	uint				getHeight(void) const;
	uint				getWidth(void) const;

	/*
	**	Set Functions
	*/
	void				setCursor(uint x, uint y);

	bool				pressedKey(int& ch, GameEntity & player);
	Windows const &		operator=(Windows const & rhs);
};


#endif

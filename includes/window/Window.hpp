/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Window.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 14:09:07 by cpieri            #+#    #+#             */
/*   Updated: 2020/01/19 10:38:32 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_HPP
# define WINDOW_HPP

# include "../GameEntity.hpp"
# include <iostream>
# include <ncurses.h>

# define BUTTON_RIGHT	68
# define BUTTON_LEFT	67
# define BUTTON_UP		65
# define BUTTON_DOWN	66
# define PLAYER_PAIR	1

class Windows
{
private:
	WINDOW *	_win;
	uint		_width;
	uint		_height;
	uint		_key;

	Windows(Windows const & src);

public:
	Windows(void);
	~Windows(void);

	bool				updateEvent(void);
	bool				buttonsPressed(uint button);

	/*
	**	Print Functions
	*/
	void				printBorder(void);
	void				printSquare(uint color);
	void				printGameEntity(GameEntity const & toPrint);

	/*
	**	Get Functions
	*/
	WINDOW *			getWin(void) const;

	/*
	**	Set Functions
	*/
	void				setCursor(uint x, uint y);

	Windows const &		operator=(Windows const & rhs);
};


#endif

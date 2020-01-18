/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Window.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 14:19:19 by cpieri            #+#    #+#             */
/*   Updated: 2020/01/18 21:48:49 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window/Window.hpp"

Windows::Windows(void) {
	initscr();
	start_color();
	this->_win = subwin(stdscr, LINES / 2, COLS / 2, 0, 0);
	this->_height = LINES / 2;
	this->_width = COLS / 2;
}

Windows::Windows(Windows const & src) {
	initscr();
	start_color();
	*this = src;
}

Windows::~Windows(void) {}


bool			Windows::updateEvent(void) {
	this->_key = getch();
	printw("key = %d\n", this->_key);
	return (true);
}

bool			Windows::buttonsPressed(uint button) {
	if (this->_key == button)
		return (true);
	return (false);
}

/*
**	Print Functions
*/
void			Windows::printBorder(void) {
	box(this->_win, ACS_VLINE, ACS_HLINE);
	wrefresh(this->_win);
}

void			Windows::printSquare(uint color) {
	(void)color;

	init_pair(PLAYER_PAIR, COLOR_RED, COLOR_MAGENTA);
	attron(COLOR_CYAN);
	wprintw(this->_win, ".");
	attroff(COLOR_CYAN);
	wrefresh(this->_win);
}

void			Windows::printGameEntity(GameEntity const & toPrint) {
	// uint	x0, x1, y0, y1 = 0;

	this->setCursor(this->_width * 0.15, this->_height / 2);
	this->printSquare(toPrint.getColor());
}

/*
**	Get Functions
*/
WINDOW *		Windows::getWin(void) const {
	return (this->_win);
}

/*
**	Set Functions
*/
void			Windows::setCursor(uint x, uint y) {
	if (x > this->_width || y > this->_height)
		return ;
	wmove(this->_win, y, x);
}

Windows const &	Windows::operator=(Windows const & rhs) {
	this->_win = rhs.getWin();
	return (*this);
}
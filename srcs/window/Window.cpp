/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Window.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 14:19:19 by cpieri            #+#    #+#             */
/*   Updated: 2020/01/18 16:33:17 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window/Window.hpp"

Windows::Windows(void) {
	initscr();
	this->_win = subwin(stdscr, LINES / 2, COLS / 2, 0, 0);
	this->_width = LINES / 2;
	this->_height = COLS / 2;
}

Windows::Windows(Windows const & src) {
	initscr();
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
	move(x, y);
}

Windows const &	Windows::operator=(Windows const & rhs) {
	this->_win = rhs.getWin();
	return (*this);
}
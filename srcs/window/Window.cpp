/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Window.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 14:19:19 by cpieri            #+#    #+#             */
/*   Updated: 2020/01/19 14:07:53 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window/Window.hpp"
#include <fstream>

Windows::Windows(void) {
	initscr();
	start_color();
	init_pair(COLOR_DECORE, COLOR_YELLOW, COLOR_BLACK);
	init_pair(COLOR_ENEMY_EASY, COLOR_WHITE, COLOR_GREEN);
	init_pair(COLOR_ENEMY_MED, COLOR_WHITE, COLOR_MAGENTA);
	init_pair(COLOR_ENEMY_HARD, COLOR_WHITE, COLOR_RED);
	init_pair(COLOR_PLAYER, COLOR_BLUE, COLOR_WHITE);
	this->_win = subwin(stdscr, LINES / 2, COLS / 2, 0, 0);
	this->_height = LINES / 2;
	this->_width = COLS / 2;
}

Windows::Windows(Windows const & src) {
	initscr();
	start_color();
	init_pair(COLOR_DECORE, COLOR_YELLOW, COLOR_BLACK);
	init_pair(COLOR_ENEMY_EASY, COLOR_RED, COLOR_GREEN);
	init_pair(COLOR_ENEMY_MED, COLOR_RED, COLOR_MAGENTA);
	init_pair(COLOR_ENEMY_HARD, COLOR_RED, COLOR_RED);
	init_pair(COLOR_PLAYER, COLOR_BLUE, COLOR_WHITE);
	*this = src;
}

Windows::~Windows(void) {}

void			Windows::refresh(void) {
	clear();
	wclear(this->_win);
}

/*
**	Print Functions
*/
void			Windows::printBorder(void) {
	box(this->_win, ACS_VLINE, ACS_HLINE);
	wrefresh(this->_win);
}

void			Windows::printGameEntity(GameEntity const & toPrint) {
	uint	x, y = 0;

	x = this->_width * toPrint.getPosX() / 100;
	y = this->_height * toPrint.getPosY() / 100;
	this->setCursor(x, y);
	wattron(this->_win, COLOR_PAIR(toPrint.getColor()));
	waddch(this->_win, toPrint.getChar());
	wattroff(this->_win, COLOR_PAIR(toPrint.getColor()));
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
	wmove(this->_win, y, x);
}

Windows const &	Windows::operator=(Windows const & rhs) {
	this->_win = rhs.getWin();
	return (*this);
}
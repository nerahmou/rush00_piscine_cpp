/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Window.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 14:19:19 by cpieri            #+#    #+#             */
/*   Updated: 2020/01/19 16:56:03 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                                            */
/* ************************************************************************** */

#include "window/Window.hpp"
#include <fstream>

Windows::Windows(void) {
	initscr();
	keypad(stdscr, TRUE);
	start_color();
	init_pair(COLOR_DECORE, COLOR_YELLOW, COLOR_BLACK);
	init_pair(COLOR_ENEMY_EASY, COLOR_WHITE, COLOR_GREEN);
	init_pair(COLOR_ENEMY_MED, COLOR_WHITE, COLOR_MAGENTA);
	init_pair(COLOR_ENEMY_HARD, COLOR_WHITE, COLOR_RED);
	init_pair(COLOR_PLAYER, COLOR_BLUE, COLOR_WHITE);
	init_pair(COLOR_MISSILE, COLOR_MAGENTA, COLOR_BLACK);
	this->_win = subwin(stdscr, LINES / 2, COLS / 2, 0, 0);
	nodelay(this->_win, true);
	this->_height = LINES / 2;
	this->_width = COLS / 2;
}

Windows::Windows(Windows const & src) {
	initscr();
	keypad(stdscr, TRUE);
	start_color();
	init_pair(COLOR_DECORE, COLOR_YELLOW, COLOR_BLACK);
	init_pair(COLOR_ENEMY_EASY, COLOR_RED, COLOR_GREEN);
	init_pair(COLOR_ENEMY_MED, COLOR_RED, COLOR_MAGENTA);
	init_pair(COLOR_ENEMY_HARD, COLOR_RED, COLOR_RED);
	init_pair(COLOR_PLAYER, COLOR_BLUE, COLOR_WHITE);
	*this = src;
	nodelay(this->_win, true);
}

Windows::~Windows(void) {}

bool			Windows::update(void) {
	const long double sysTime = std::time(0);
	const long double sysTimeMS = sysTime*1000;
	if (((this->_time - sysTimeMS) > TIMEPERFRAME) && this->frameEndFlag)
	{
		this->frameCount++;
		this->_time = sysTimeMS + TIMEPERFRAME;
		this->frameEndFlag = false;
		return (true);
	}
	if (this->frameEndFlag)
		return (false);
	this->frameEndFlag = true;
	return (false);
}

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

bool		Windows::pressedKey(int& ch, GameEntity & player, Enemy ** enemies, Missile & missile) {
	{
		ch = wgetch(this->_win);

		switch (ch) {
			case KEY_UP:
				player.setPosY(player.getPosY() + 4);
				return (true);
			case KEY_DOWN:
				player.setPosY(player.getPosY() - 4);
				return (true);
			case KEY_RIGHT:
				player.setPosX(player.getPosX() + 1);
				return (true);
			case KEY_LEFT:
				player.setPosX(player.getPosX() - 1);
				return (true);
			case ERR:
				return (false);
		}
	}
	return (false);
}

uint			Windows::getHeight(void) const {
	return (this->_height);
}

uint			Windows::getWidth(void) const {
	return (this->_width);
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

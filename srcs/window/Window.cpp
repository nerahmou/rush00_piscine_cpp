#include "Missile.hpp"
#include "window/Window.hpp"
#include <fstream>

Windows::Windows(void) : loop(true) {
	initscr();
	noecho();
	cbreak();
	nodelay(stdscr, true);
	keypad(stdscr, TRUE);
	start_color();
	init_pair(COLOR_DECORE, COLOR_YELLOW, COLOR_BLACK);
	init_pair(COLOR_ENEMY_EASY, COLOR_WHITE, COLOR_GREEN);
	init_pair(COLOR_ENEMY_MED, COLOR_WHITE, COLOR_MAGENTA);
	init_pair(COLOR_ENEMY_HARD, COLOR_WHITE, COLOR_RED);
	init_pair(COLOR_PLAYER, COLOR_BLUE, COLOR_WHITE);
	init_pair(COLOR_MISSILE, COLOR_MAGENTA, COLOR_BLACK);
	this->_win = subwin(stdscr, LINES / 2, COLS / 2, 0, 0);
	this->_height = LINES / 2;
	this->_width = COLS / 2;
	this->_timeSavedA = this->_timeSavedB = this->_time = std::clock() /  (CLOCKS_PER_SEC / 2);;
}

Windows::Windows(Windows const & src) {
	initscr();
	noecho();
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
	this->_time = std::clock();
	if ((this->_time / 50000) - (this->_timeSavedA / 50000) > 0) {
		 this->_timeSavedA = this->_time;
		return (false);
	}
	return (true);
}

void			Windows::buttonsUpdate(void) {
	this->_key = wgetch(this->_win);
}

void			Windows::refresh(void) {
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

void			Windows::printEnemies(Enemy * enemies) {
	Enemy *		list = enemies;
	while (list) {
		this->printGameEntity(*list);
		list = list->next;
	}
}

void			Windows::printMissile(Missile* missile) {
	uint	x, y = 0;

	x = this->_width * missile->getPosX() / 100;
	y = this->_height * missile->getPosY() / 100;
	this->setCursor(x, y);
	wattron(this->_win, COLOR_PAIR(missile->getColor()));
	waddch(this->_win, missile->getChar());
	std::string str;
	for(unsigned i = x; i < this->_width - 2; i++) {
		str += missile->getChar();
	}
	wprintw(this->_win, str.c_str());
	wattroff(this->_win, COLOR_PAIR(missile->getColor()));
	wrefresh(this->_win);
}
/*
 **	Get Functions
 */
WINDOW *		Windows::getWin(void) const {
	return (this->_win);
}

bool		Windows::pressedKey(int& ch, Player & player,
								Enemy ** enemies, Missile ** missile) {
	{
		ch = getch();
		switch (ch) {
			case KEY_DOWN:
				player.setPosY(player.getPosY() + 4);
				return (true);
			case KEY_UP:
				player.setPosY(player.getPosY() - 4);
				return (true);
			case KEY_RIGHT:
				player.setPosX(player.getPosX() + 1);
				return (true);
			case KEY_LEFT:
				player.setPosX(player.getPosX() - 1);
				return (true);
			case ' ':
				player.shot(enemies, missile);
				return (true);
			case 'q':
				this->loop = false;
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

uint			Windows::getKey(void) const {
	return (this->_key);
}

bool			Windows::pressed(uint key)
{
	if (key == this->_key)
		return (true);
	return (false);
}

/*
 **	Set Functions
 */
void			Windows::setCursor(uint x, uint y) {
	if (x > this->_width || y >this->_height)
		return ;
	wmove(this->_win, y, x);
}

Windows const &	Windows::operator=(Windows const & rhs) {
	this->_win = rhs.getWin();
	return (*this);
}

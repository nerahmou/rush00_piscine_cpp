#include "Player.hpp"

Player::Player(std::string name):
	Person(PLAYER_DEFAULT_POS_X, PLAYER_DEFAULT_POS_Y,
			PLAYER_LIMIT_MIN_X, PLAYER_LIMIT_MAX_X,
			COLOR_PLAYER, PLAYER_LIFE, PLAYER_XP, PLAYER_CHAR),
	_name(name)
{}

Player::~Player(void)
{}

bool Player::shot(void)
{
	//TODO
	return 0;
}

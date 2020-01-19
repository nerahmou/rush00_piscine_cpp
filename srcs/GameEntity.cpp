#include "GameEntity.hpp"

GameEntity::GameEntity(unsigned posX, unsigned posY, unsigned limitMinX, unsigned limitMaxX, unsigned color, char c):
	_posX(posX),
	_posY(posY),
	_sizeX(GAME_ENTITY_SIZE_X),
	_sizeY(GAME_ENTITY_SIZE_Y),
	_limitMinX(limitMinX),
	_limitMaxX(limitMaxX),
	_color(color),
	_cToPrint(c)
{}

GameEntity::GameEntity(void)
{}

GameEntity::~GameEntity(void)
{}

unsigned GameEntity::getPosX(void) const
{
	return this->_posX;
}

unsigned GameEntity::getPosY(void) const
{
	return this->_posY;
}

unsigned GameEntity::getSizeX(void) const
{
	return this->_sizeX;
}

unsigned GameEntity::getSizeY(void) const
{
	return this->_sizeY;
}

unsigned GameEntity::getColor(void) const
{
	return this->_color;
}

char GameEntity::getChar(void) const
{
	return this->_cToPrint;
}

bool GameEntity::setPosX(unsigned posX)
{
	this->_posX = posX;
	return 0;
}

bool GameEntity::setPosY(unsigned posY)
{
	this->_posY = posY;
	return 0;
}

bool GameEntity::setSizeX(unsigned sizeX)
{
	this->_sizeX = sizeX;
	return 0;
}

bool GameEntity::setSizeY(unsigned sizeY)
{
	this->_sizeY = sizeY;
	return 0;
}

bool GameEntity::setLimitMinX(unsigned limitMinX)
{
	this->_limitMinX = limitMinX;
	return 0;
}

bool GameEntity::setLimitMaxX(unsigned limitMaxX)
{
	this->_limitMaxX = limitMaxX;
	return 0;
}

bool GameEntity::setColor(unsigned color)
{
	this->_color = color;
	return 0;
}

bool GameEntity::setChar(char c)
{
	this->_cToPrint = c;
	return 0;
}

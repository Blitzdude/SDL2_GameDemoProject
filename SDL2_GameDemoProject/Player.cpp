#include "Player.h"

Player::Player(int x, int y) 
{
	xPosition = x;
	yPosition = y;
	
}

Player::~Player()
{
}

void Player::moveRight()
{
	xPosition++;
}

void Player::moveLeft()
{
	xPosition--;
}

#include "Player.h"

Player::Player(int x, int y) 
{
	xPosition = x;
	yPosition = y;
	playerTexture = loadFromFile(imagePath);

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

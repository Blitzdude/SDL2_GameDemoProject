#include "Player.h"

Player::Player(int x, int y) 
{
	xPosition = x;
	yPosition = y;
	texture = loadFromFile(imagePath);
	if (texture == NULL) 
	{
		printf("Couldn't load player texture!\n");
	}
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

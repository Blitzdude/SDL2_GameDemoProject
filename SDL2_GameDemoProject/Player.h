#pragma once
#include "LTexture.h"

class Player : public LTexture
{
public:

	int xPosition = 0;
	int yPosition = 0;
	std::string imagePath = "resources/player.png";
	
	Player(int x, int y);
	~Player();

	void moveRight();
	void moveLeft();
};


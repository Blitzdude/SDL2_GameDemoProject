#pragma once
#include "Global.h"

class Player
{
public:

	int xPosition = 0;
	int yPosition = 0;
	std::string spritePath = "resources/player.bmp";

	Player();
	Player(int x, int y);
	~Player();

	void moveRight();
	void moveLeft();
		

	
};


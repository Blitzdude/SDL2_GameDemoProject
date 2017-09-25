#pragma once
#include "LTexture.h"

class Player : protected LTexture
{
public:

	int xPosition = 0;
	int yPosition = 0;
	std::string imagePath = "resources/player.png";
	LTexture playerTexture;
	
	
	Player(int x, int y);
	~Player();

	void moveRight();
	void moveLeft();
		

	
};


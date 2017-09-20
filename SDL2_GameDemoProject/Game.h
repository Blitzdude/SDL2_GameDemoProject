#pragma once
#include "Global.h"
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>

class Game
{
public:
	//The window we'll be rendering to
	SDL_Window* window = NULL;

	//The surface contained by the window
	SDL_Surface* screenSurface = NULL;

	SDL_Surface* image = NULL;

	Game();
	~Game();
	
	bool init();
	bool loadMedia();
	bool createWindow();
	void updateWindow();
	void closeGame();
};


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

	//PNG image surface
	SDL_Surface* backgroundSurface = NULL;

	
	

	//Event handler
	SDL_Event eventHandler;

	//Scene texture
	LTexture backgroundTexture;

	Game(); // Constructor
	~Game(); // destructor
	
	// Method
	bool init();
	bool loadMedia();
	SDL_Surface* loadFromFile(std::string path);
	bool createWindow();
	
	void updateWindow();
	void closeGame();
};


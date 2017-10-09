#pragma once

#include "Global.h"
#include "LTexture.h"
#include "Player.h"

class Game 
{
public:
	//The window we'll be rendering to
	SDL_Window* window = NULL;

	//The surface contained by the window
	SDL_Surface* screenSurface = NULL;

	//PNG image surface
	SDL_Surface* backgroundSurface = NULL;

	//Scene texture
	LTexture backgroundTexture;
	LTexture playerTexture;
	
	//Renderer
	SDL_Renderer* renderer;

	Game(); // constructor
	~Game(); // destructor
	
	// Method
	bool init();
	bool loadMedia();
	bool loadMedia(std::string path);
	bool createWindow();
	void processInput();
	
	void updateWindow(Player &p);
	void closeGame();
};


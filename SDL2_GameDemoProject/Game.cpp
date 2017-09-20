#include "Game.h"



Game::Game()
{
}


Game::~Game()
{
}


bool Game::init()
{
	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		return false;
	}
	return true;
}

bool Game::loadMedia()
{
	//Loading success flag
	bool success = true;

	//Load splash image
	image = SDL_LoadBMP("02_getting_an_image_on_the_screen/hello_world.bmp");
	if (image == NULL)
	{
		printf("Unable to load image %s! SDL Error: %s\n", "02_getting_an_image_on_the_screen/hello_world.bmp", SDL_GetError());
		success = false;
	}

	return success;
}



bool Game::createWindow()
{
	//Create window
	window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (window == NULL)
	{
		printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		return false;
	}	
}

void Game::updateWindow()
{
	//Get window surface
	screenSurface = SDL_GetWindowSurface(window);

	//Fill the surface white
	SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format,
		0xFF, 0xFF, 0xFF));

	//Update the surface
	SDL_UpdateWindowSurface(window);
}

void Game::closeGame()
{
	//Destroy window
	SDL_DestroyWindow(window);

	//Quit SDL subsystems
	SDL_Quit();
	
}

#include "Game.h"



Game::Game()
{
}


Game::~Game()
{
}


bool Game::init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf("Warning: Linear texture filtering not enabled!");
		}

		//Create window
		window = SDL_CreateWindow(
			"SDL Tutorial", 
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			SCREEN_WIDTH, SCREEN_HEIGHT, 
			SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Create renderer for window
			renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
			if (renderer == NULL)
			{
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
					success = false;
				}
			}
		}
	}

	return success;
}

bool Game::loadMedia()
{
	//Loading success flag
	bool success = true;

	//Load background texture
	if (!backgroundTexture.loadFromFile("resources/background.png", renderer))
	{
		printf("Failed to load background texture image!\n");
		success = false;
	}
	// load player texture
	if (!playerTexture.loadFromFile("resources/player.png", renderer))
	{
		printf("Failed to load player texture image!\n");
		success = false;
	}

	return success;
}

bool Game::loadMedia(std::string path)
{
	//Loading success flag
	bool success = true;

	//Load background texture
	if (!backgroundTexture.loadFromFile("resources/background.png", renderer))
	{
		printf("Failed to load background texture image!\n");
		success = false;
	}

	return success;
}


bool Game::createWindow()
{
	bool success = true;
	//Create window
	window = SDL_CreateWindow("SDL Tutorial",
								SDL_WINDOWPOS_UNDEFINED, 
								SDL_WINDOWPOS_UNDEFINED, 
								SCREEN_WIDTH, SCREEN_HEIGHT, 
								SDL_WINDOW_SHOWN);
	if (window == NULL)
	{
		printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		success = false;
	}	
	return success;
}

void Game::processInput()
{
	SDL_Event evnt;
	while (SDL_PollEvent &evnt) {

	}
}



void Game::updateWindow(Player &p)
{
	//Get window surface
	screenSurface = SDL_GetWindowSurface(window);

	
	//Clear screen
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(renderer);

	//Render background texture to screen
	backgroundTexture.render(0, 0, renderer);

	//Render Foo' to the screen
	playerTexture.render(p.xPosition, p.yPosition, renderer);

	//Update screen
	SDL_RenderPresent(renderer);
}

void Game::closeGame()
{
	//Free loaded images
	playerTexture.free();
	backgroundTexture.free();

	//Destroy window	
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	window = NULL;
	renderer = NULL;


	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
	
}

//Using SDL and standard IO
#include "Game.h"


int main(int argc, char* args[])
{
	Game gm;

	if (!gm.init()) {
		gm.createWindow();

		//Get window surface
		gm.screenSurface = SDL_GetWindowSurface(gm.window);

		//Fill the surface white
		SDL_FillRect(gm.screenSurface, NULL, SDL_MapRGB(gm.screenSurface->format,
														0xFF, 0xFF, 0xFF));

		//Update the surface
		SDL_UpdateWindowSurface(gm.window);

		//Wait two seconds
		SDL_Delay(2000);
		return true;

		gm.closeGame();
	}

	

	return 0;
}
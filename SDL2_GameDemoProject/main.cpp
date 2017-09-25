//Using SDL and standard IO
#include "Game.h"
#include "Player.h"

SDL_Event e;

int main(int argc, char* args[])
{
	// Create game manager 
	Game gm;

	//create player
	Player player1(0,0);

	// initialize and create window
	if (!gm.init()) 
	{
		printf("Unable to initialize!\n");
	}
	else
	{
		// load media
		if (!gm.loadMedia()) 
		{
			printf("Unable to load media!\n");
		}
		else {
			// running flag
			bool running = true;

			//Create event handler
			SDL_Event e;

			//Main game loop
			while (running) 
			{

				// handle events
				while (SDL_PollEvent(&e) != 0) 
				{

					//user quits
					if (e.type == SDL_QUIT) 
					{
						running = false;
					}	
				}

				//Update the window
				gm.updateWindow(player1);

			} // Game loop end
		}
	}


	// QUIT SDL
	gm.closeGame(&player1);
	return 0;
}
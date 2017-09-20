//Using SDL and standard IO
#include "Game.h"


int main(int argc, char* args[])
{
	Game gm;

	if (!gm.init()) {
		printf("Failed to initialize");
	}
	else {

		gm.createWindow();

		
		//Update the surface
		gm.updateWindow();

		//Wait two seconds
		SDL_Delay(3000);
		
		gm.closeGame();
	}

	

	return 0;
}
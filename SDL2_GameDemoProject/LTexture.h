#pragma once
#include "Global.h"
class LTexture
{

public:
	//Initializes variables
	LTexture();

	//Deallocates memory
	~LTexture();

	//Loads image at specified path
	SDL_Texture* loadFromFile(std::string path, SDL_Renderer* renderer);

	//Deallocates texture
	void free();

	//Renders texture at given point
	void render(int x, int y, SDL_Renderer* renderer);

	//Gets image dimensions
	int getWidth();
	int getHeight();

protected:
	//The actual hardware texture
	SDL_Texture* texture;

	//Image dimensions
	int width;
	int height;
};


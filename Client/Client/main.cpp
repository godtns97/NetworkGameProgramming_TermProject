#include "global.h"
#include "client.h"
using namespace std;

SDL_Window* gWindow = NULL;
SDL_Surface* gScreenSurface = NULL;			//The surface contained by the window

bool init()
{
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}

	//Create window
	gWindow = SDL_CreateWindow("TANK", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (gWindow == NULL)
	{
		printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Get window surface
		gScreenSurface = SDL_GetWindowSurface(gWindow);
	}

	return success;
}

void close()
{
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	SDL_Quit();
}

int main(int argc, char* args[])
{
	//Start up SDL and create window
	if (!init()) cout << "Failed to load media!\n";
	else
	{
		bool quit = false;			//Main loop flag
		SDL_Event e;

		//While application is running
		while (!quit)
		{
			//Handle events on queue
			while (SDL_PollEvent(&e) != 0)
			{
				//User requests quit
				if (e.type == SDL_QUIT)
				{
					quit = true;
				}
				else if (e.type == SDL_KEYDOWN)
				{
					switch (e.key.keysym.sym)
					{
					case SDLK_UP:
						break;

					case SDLK_DOWN:
						break;

					case SDLK_RIGHT:
						break;

					case SDLK_LEFT:
						break;
					case SDLK_SPACE:
						break;
					}
				}
			}

			////Apply the image
			//SDL_BlitSurface(gXOut, NULL, gScreenSurface, NULL);
			
			////Update the surface
			//SDL_UpdateWindowSurface(gWindow);
		}
	}

	close();
	return 0;
}
#include "global.h"
#include "surface.h"
#include "tank.h"
#include "timer.h"

list<Tank> tanks;

Surface& surface = Surface::getInstance();

//Starts up SDL and creates window
bool init()
{
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << endl;
		success = false;
	}
	else
	{
		//Create window
		gWindow = SDL_CreateWindow("TANK!", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

		if (gWindow == NULL)
		{
			cout << "Window could not be created! SDL_Error: " << SDL_GetError() << endl;
			success = true;
		}
		else
		{
			//Get window surface
			gScreenSurface = SDL_GetWindowSurface(gWindow);
		}

		surface.loadImage();
	}

	return success;
}

//Frees media and shuts down SDL
void close()
{
	surface.closeSurface();

	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	SDL_Quit();
}

void draw(const bool &quit)
{
	Timer timer;
	Timer fps;
	unsigned frame = 0;

	fps.start();
	while (!quit)
	{
		timer.start();
		surface.drawSurface(tanks);
		++frame;

	}
}

int main(int argc, char* args[])
{
	if (!init()) cout << "Failed to initalize!\n";
	else
	{

		bool quit = false;
		SDL_Event e;

		while (!quit)
		{
			while (SDL_PollEvent(&e) != 0)
			{
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

					case SDLK_LEFT:
						break;

					case SDLK_RIGHT:
						break;

					case SDLK_SPACE:
						break;

					default:
						continue;
					}
				}
			}
		}
	}

	close();

	return 0;
}
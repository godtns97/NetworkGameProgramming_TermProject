#include "global.h"
#include "bullet.h"
#include "object.h"
#include "surface.h"
#include "tank.h"
#include "timer.h"
using namespace std;

Surface& surface = Surface::getInstance();
list<Tank> tanks;
list<Bullet> bullets;

int keypress;

int main(int argc, char* args[])
{
	//Start up SDL and create window
	if (!surface.init()) return -1;
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
						keypress = 1;
						break;

					case SDLK_DOWN:
						keypress = 2;
						break;

					case SDLK_RIGHT:
						keypress = 3;
						break;

					case SDLK_LEFT:
						keypress = 4;
						break;
					case SDLK_SPACE:
						keypress = 0;
						break;
					}
				}
			}
		}
	}

	surface.close();
	return 0;
}